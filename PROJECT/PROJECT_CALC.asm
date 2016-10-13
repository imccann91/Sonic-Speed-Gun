; WRITTEN BY ANDY BIETRY AND IAN MCCANN.
; "MUX" CODE PROVIDED BY GEORGE FEZEKAS.
; THIS PROGRAM USES ANALOG TO DIGITAL CONVERSION TO PROCESS SIGNALS FROM
; AN ULTRA SONIC SENSOR TO CALCULATE SPEED. IT ALSO DISPLAYS THE SPEED
; ON 4 7-SEGEMENT LED DISPLAYS IN MILES PER HOUR.

#include Reg9s12.h

setvec        equ        $EEA4           ;Debug12 Set Vector() Sub address location
getchar       equ        $EE84           ;Debug12 getchar() sub address location
putchar       equ        $EE86           ;Debug12 putchar() sub address location
DIG0        equ        8                 ; PP3
DIG1        equ        4                 ; PP2
DIG2        equ        2                 ; PP1
DIG3        equ        1                 ; P0
        org     $1000
start
        ldaa        #$FF
        staa        ptp                  ; turn off 7-segment display
        staa        ddrb                 ; program portb for output (LED Segments)
        staa        ddrp                 ; program portp for output (LED Display Enable Lines)

        ldx        #RTISR                ;obtain the address of our ISR
        pshx                             ;save it on the stack
        ldd        #56                   ;obtain Debug12 RAM Table address for RTISR
        ldx        setvec                ;call Debug12 sub to install ISR in RAM Table
        jsr        0,x

        movb        #$37,rtictl          ;program RTInterrupt to occur every
                                         ; 4MHz/1024 = 3906.25/2^2/8 = 122.0703125 Hz

        movb        #122,count           ;init counter for 122 * 8.12 ms
        bset        crgint,$80           ;enable Real Time Clock and RTInterrupts

        movw        #$0000,number        ;initialize counter and number to be displayed
        movw        number,mux_dig       ;copy number to the to the multiplexed display storage
        movb        #$03,mux_sel         ;initialize mux selector (will be cycled from 3-0, then reset to 3)

        cli                              ;clear mask bit in CCR to enable ALL interrupts
        
loop    nop                              ;MAIN LOOP
        bra     loop

RTISR
        pshx
        pshd
        pshy
        bset        crgflg,$80           ;clear interrupt flag
        dec         count                ;wait for 122 intterrupts before doing anything
        bne         mux

SENSOR  NOP
        LDAA        #$80                 ;Set the ADPU bit to 1 (turn on the A to D)
        STAA        atd0ctl2             ;Store in this register

        LDAA        #240/3               ;10 microsecond delay
wait    DBNE        A wait
        LDAA        #$20                 ;Set S4C to 1 (Sets A to D to do a 4 conversions)
        STAA        atd0ctl3             ;Store in this reigster
        MOVB        #$82 atd0ctl5        ;start conversion and sample PAD02
wait2   BRCLR        atd0stat #$80 wait2 ;wait for SCF=1
;*************************************************************;
        LDAA        CFLG                 ;CALCULATIONS
        CMPA        #1
        BNE         $106F                ;BRANCHES TO THE START OF THE STORING PROCESS,
        LDD         NUM1                 ;LOOK AT LINE #74
        SUBD        NUM2
        LBLT        NEGATE               ;NOTE: THIS CALCULATES THE SPEED IN INCHES PER SECOND
        STD         SPEED
        
        

;*************************************************************;
        LDAA        SFLG
        CMPA        #1
        LBEQ        STORE2
        LDD         $90
        STD         NUM1                 ;STORE DISTANCE TO NUM1
        BSET        SFLG,1
;*************************************************************;

        MOVB        #122,count           ;reset interrupt counter
        
mux                                      ;the following code displays the number stored in the interger "number"
                                         ;by treating it as 4 discrete 4-bit nybbles multiplexed between the
                                         ;4 LED display digits at a rate of 122 per second.

        ldab        mux_sel              ;get current mux address (0-3)
        ldaa        mux_dig+1            ;get low order byte
        anda        #$0F                 ;interested in only the low order nybble for display
        ldx        #seg_ptrn             ;lookup the segment pattern for the nybble
        ldaa        a,x
        staa        portb                ;update the correct LED digit for display
        ldy        #mltplx               ;index to jump table
        aslb                             ;multiply index by 2 for word address offset
        ldy        b,y                   ;pickup mux address
        jsr        0,y                   ;jump to and enable the correct display digit

        ldd        mux_dig               ;divide the integer for display by 16 so that
        ldx        #$10                  ;the next nybble for display is in the low order 4 bits
        idiv
        stx        mux_dig
        dec        mux_sel               ;go to the next LED digit
        bpl        quit
        movb        #$03,mux_sel         ;reset the mux selector
        movw        number,mux_dig       ;reset the integer display digit
quit
        puly
        pulx
        puld
        rti



digit0:
        bclr        ptp,DIG0             ; turn on LED Display digit 0
        bset        ptp,DIG1             ; turn off all other digits
        bset        ptp,DIG2
        bset        ptp,DIG3
        rts
digit1
        bset        ptp,DIG0
        bclr        ptp,DIG1             ; turn on LED DISPLAY digit 1
        bset        ptp,DIG2             ; turn off all other digits
        bset        ptp,DIG3
        rts
digit2
        bset        ptp,DIG0
        bset        ptp,DIG1
        bclr        ptp,DIG2             ; turn on LED Display digit 2
        bset        ptp,DIG3             ; turn off all other digits
        rts
digit3
        bset        ptp,DIG0
        bset        ptp,DIG1
        bset        ptp,DIG2
        bclr        ptp,DIG3             ; turn on LED Display digit 3
        rts
;****************************************;
NEGATE                                   ;NEGATES SPEED IF IT'S NEGATIVE
        STD         SPEED
        NEG         SPEED
        RTS


;****************************************;
STORE2                                   ;STORES THE SECOND DISTANCE INTO NUM2 AND RETURNS TO THE MAIN LOOP
        LDD         $90
        STD         NUM2
        BCLR        SFLG,1
        BSET        CFLG,1
        JMP         $106F
;****************************************;
NUM1    RMB          2                   ;STORAGE LOCATION FOR FIRST READING
NUM2    RMB          2                   ;STORAGE LOCATION FOR SECOND READING
SFLG    DB           0                   ;STORAGE LOCATION FLAG
CFLG    DB           0                   ;CALCULATIONS FLAG
NFLG    DB           0                   ;NEGATIVE RESULT FLAG
SPEED   RMB          2                   ;RESULT OF SPEED CALCULATION
;****************************************;

count        rmb        1                ; interrupt counter
number        rmb        2               ; 16 bit integer cout
mux_dig        rmb        2              ; current mux digit being displayed
mux_sel        rmb        1              ; current mux/display digit (0-3)
seg_ptrn                                 ; bit patterns to illuminate correct LED segments
        fcb        $3f,$06,$5b,$4f,$66,$6d,$7d,$07                ; 0-7
;                0,  1,  2,  3,  4,  5,  6,  7
        fcb        $7f,$6f,$77,$7c,$39,$5e,$79,$71                ; 8-$0f
;                8,  9,  A,  b,  C,  d,  E,  F
mltplx                                   ;jump addresses to enable 1 of 4 LED display digits
        dw        digit3,digit2,digit1,digit0
        end