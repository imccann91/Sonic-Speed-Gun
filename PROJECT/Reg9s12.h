*
*
*  HC12 i/o register locations (9s12dp256)
*
*
porta:          equ 0   ;port a = address lines a8 - a15
portb:          equ 1   ;port b = address lines a0 - a7
ddra:           equ 2   ;port a direction register
ddrb:           equ 3   ;port a direction register

porte:          equ 8   ;port e = mode,irqandcontrolsignals
ddre:           equ 9   ;port e direction register
pear:           equ $a  ;port e assignments
mode:           equ $b  ;mode register
pucr:           equ $c  ;port pull-up control register
rdriv:          equ $d  ;port reduced drive control register
ebictl:		equ $e  ;e stretch control

initrm:         equ $10 ;ram location register
initrg:         equ $11 ;register location register
initee:         equ $12 ;eeprom location register
misc:           equ $13 ;miscellaneous mapping control
mtst0:          equ $14 ; reserved
itcr:           equ $15 ;interrupt test control register
itest:          equ $16 ;interrupt test register
mtst1:          equ $17 ; reserved

partidh:	equ $1a ;part id high
partidl:	equ $1b ;part id low
memsiz0:	equ $1c ;memory size
memsiz1:	equ $1d ;memory size
intcr:          equ $1e ;interrupt control register
hprio:          equ $1f ;high priority reg

bkpct0:         equ $28 ;break control register
bkpct1:         equ $29 ;break control register
bkp0x:          equ $2a ; break 0 index register
bkp0h:          equ $2b ; break 0 pointer high
brp0l:          equ $2c ; break 0 pointer low
bkp1x:          equ $2d ; break 1 index register
bkp1h:          equ $2e ; break 1 pointer high
brp1l:          equ $2f ; break 1 pointer low
ppage:		equ $30 ;program page register

portk:		equ $32 ;port k data
ddrk:		equ $33 ;port k direction
synr:           equ $34 ; synthesizer / multiplier register
refdv:          equ $35 ; reference divider register
ctflg:          equ $36 ; reserved
crgflg:         equ $37 ; pll flags register
crgint:         equ $38 ; pll interrupt register
clksel:         equ $39 ; clock select register
pllctl:         equ $3a ; pll control register
rtictl:         equ $3b ;real time interrupt control
copctl:         equ $3c ;watchdog control
forbyp:         equ $3d ;
ctctl:          equ $3e ;
armcop:         equ $3f ;cop reset register

tios:           equ $40 ;timer input/output select
cforc:          equ $41 ;timer compare force
oc7m:           equ $42 ;timer output compare 7 mask
oc7d:           equ $43 ;timer output compare 7 data
tcnt:           equ $44 ;timer counter register hi
*tcnt:          equ $45 ;timer counter register lo
tscr:           equ $46 ;timer system control register
ttov:           equ $47 ;reserved
tctl1:          equ $48 ;timer control register 1
tctl2:          equ $49 ;timer control register 2
tctl3:          equ $4a ;timer control register 3
tctl4:          equ $4b ;timer control register 4
tmsk1:          equ $4c ;timer interrupt mask 1
tmsk2:          equ $4d ;timer interrupt mask 2
tflg1:          equ $4e ;timer flags 1
tflg2:          equ $4f ;timer flags 2
tc0:            equ $50 ;timer capture/compare register 0
tc1:            equ $52 ;timer capture/compare register 1
tc2:            equ $54 ;timer capture/compare register 2
tc3:            equ $56 ;timer capture/compare register 3
tc4:            equ $58 ;timer capture/compare register 4
tc5:            equ $5a ;timer capture/compare register 5
tc6:            equ $5c ;timer capture/compare register 6
tc7:            equ $5e ;timer capture/compare register 7
pactl:          equ $60 ;pulse accumulator controls
paflg:          equ $61 ;pulse accumulator flags
pacn3:          equ $62 ;pulse accumulator counter 3
pacn2:          equ $63 ;pulse accumulator counter 2
pacn1:          equ $64 ;pulse accumulator counter 1
pacn0:          equ $65 ;pulse accumulator counter 0
mcctl:          equ $66 ;modulus down conunter control
mcflg:          equ $67 ;down counter flags
icpar:          equ $68 ;input pulse accumulator control
dlyct:          equ $69 ;delay count to down counter
icovw:          equ $6a ;input control overwrite register
icsys:          equ $6b ;input control system control

timtst:         equ $6d ;timer test register

pbctl:          equ $70 ; pulse accumulator b control
pbflg:          equ $71 ; pulse accumulator b flags
pa3h:           equ $72 ; pulse accumulator holding register 3
pa2h:           equ $73 ; pulse accumulator holding register 2
pa1h:           equ $74 ; pulse accumulator holding register 1
pa0h:           equ $75 ; pulse accumulator holding register 0
mccnt:          equ $76 ; modulus down counter register
*mccntl:        equ $77 ; low byte
tcoh:           equ $78 ; capture 0 holding register
tc1h:           equ $7a ; capture 1 holding register
tc2h:           equ $7c ; capture 2 holding register
tc3h:           equ $7e ; capture 3 holding register

atd0ctl0:       equ $80 ;adc control 0 (reserved)
atd0ctl1:       equ $81 ;adc control 1 (reserved)
atd0ctl2:       equ $82 ;adc control 2
atd0ctl3:       equ $83 ;adc control 3
atd0ctl4:       equ $84 ;adc control 4
atd0ctl5:       equ $85 ;adc control 5
atd0stat:       equ $86 ;adc status register hi
*atd0stat       equ $87 ;adc status register lo
atd0test:       equ $88 ;adc test (reserved)
*atd0test       equ $89 ;

atd0dien:	equ $8d ;

portad:         equ $8f ;port adc = input only
adr00h:         equ $90 ;adc result 0 register
adr01h:         equ $92 ;adc result 1 register
adr02h:         equ $94 ;adc result 2 register
adr03h:         equ $96 ;adc result 3 register
adr04h:         equ $98 ;adc result 4 register
adr05h:         equ $9a ;adc result 5 register
adr06h:         equ $9c ;adc result 6 register
adr07h:         equ $9e ;adc result 7 register

pwme:		equ $a0 ;pwm enable
pwmpol:         equ $a1 ;pwm polarity
pwmclk:         equ $a2 ;pwm clock select register
pwmprclk:       equ $a3 ;pwm prescale clock select register
pwmcae:         equ $a4 ;pwm center align select register
pwmctl:         equ $a5 ;pwm control register
pwmtst:         equ $a6 ;reserved
pwmprsc:        equ $a7 ;reserved
pwmscla:        equ $a8 ;pwm scale a
pwmsclb:        equ $a9 ;pwm scale b
pwmscnta:       equ $aa ;reserved
pwmscntb:       equ $ab ;reserved
pwmcnt0:        equ $ac ;pwm channel 0 counter
pwmcnt1:        equ $ad ;pwm channel 1 counter
pwmcnt2:        equ $ae ;pwm channel 2 counter
pwmcnt3:        equ $af ;pwm channel 3 counter
pwmcnt4:        equ $b0 ;pwm channel 4 counter
pwmcnt5:        equ $b1 ;pwm channel 5 counter
pwmcnt6:        equ $b2 ;pwm channel 6 counter
pwmcnt7:        equ $b3 ;pwm channel 7 counter
pwmper0:        equ $b4 ;pwm channel 0 period
pwmper1:        equ $b5 ;pwm channel 1 period
pwmper2:        equ $b6 ;pwm channel 2 period
pwmper3:        equ $b7 ;pwm channel 3 period
pwmper4:        equ $b8 ;pwm channel 4 period
pwmper5:        equ $b9 ;pwm channel 5 period
pwmper6:        equ $ba ;pwm channel 6 period
pwmper7:        equ $bb ;pwm channel 7 period
pwmdty0:        equ $bc ;pwm channel 0 duty cycle
pwmdty1:        equ $bd ;pwm channel 1 duty cycle
pwmdty2:        equ $be ;pwm channel 2 duty cycle
pwmdty3:        equ $bf ;pwm channel 3 duty cycle
pwmdty4:        equ $c0 ;pwm channel 0 duty cycle
pwmdty5:        equ $c1 ;pwm channel 1 duty cycle
pwmdty6:        equ $c2 ;pwm channel 2 duty cycle
pwmdty7:        equ $c3 ;pwm channel 3 duty cycle
pwmsdn:         equ $c4 ;pwm shutdown register

sc0bdh:         equ $c8 ;sci 0 baud reg hi byte
sc0bdl:         equ $c9 ;sci 0 baud reg lo byte
sc0cr1:         equ $ca ;sci 0 control1 reg
sc0cr2:         equ $cb ;sci 0 control2 reg
sc0sr1:         equ $cc ;sci 0 status reg 1
sc0sr2:         equ $cd ;sci 0 status reg 2
sc0drh:         equ $ce ;sci 0 data reg hi
sc0drl:         equ $cf ;sci 0 data reg lo
sc1bdh:         equ $d0 ;sci 1 baud reg hi byte
sc1bdl:         equ $d1 ;sci 1 baud reg lo byte
sc1cr1:         equ $d2 ;sci 1 control1 reg
sc1cr2:         equ $d3 ;sci 1 control2 reg
sc1sr1:         equ $d4 ;sci 1 status reg 1
sc1sr2:         equ $d5 ;sci 1 status reg 2
sc1drh:         equ $d6 ;sci 1 data reg hi
sc1drl:         equ $d7 ;sci 1 data reg lo
spi0cr1:        equ $d8 ;spi 0 control1 reg
spi0cr2:        equ $d9 ;spi 0 control2 reg
spi0br:         equ $da ;spi 0 baud reg
spi0sr:         equ $db ;spi 0 status reg hi

sp0dr:          equ $dd ;spi 0 data reg

ibad:		equ $e0 ;i2c bus address register
ibfd:		equ $e1 ;i2c bus frequency divider
ibcr:		equ $e2 ;i2c bus control register
ibsr:		equ $e3 ;i2c bus status register
ibdr:		equ $e4 ;i2c bus message data register

dlcbcr1:	equ $e8 ;bdlc control regsiter 1
dlcbsvr:	equ $e9 ;bdlc state vector register
dlcbcr2:	equ $ea ;bdlc control register 2
dlcbdr:		equ $eb ;bdlc data register
dlcbard:	equ $ec ;bdlc analog delay register
dlcbrsr:	equ $ed ;bdlc rate select register
dlcscr:		equ $ee ;bdlc control register
dlcbstat:	equ $ef ;bdlc status register
spi1cr1:        equ $f0 ;spi 1 control1 reg
spi1cr2:        equ $f1 ;spi 1 control2 reg
spi1br:         equ $f2 ;spi 1 baud reg
spi1sr:         equ $f3 ;spi 1 status reg hi

sp1dr:          equ $f5 ;spi 1 data reg

spi2cr1:        equ $f8 ;spi 2 control1 reg
spi2cr2:        equ $f9 ;spi 2 control2 reg
spi2br:         equ $fa ;spi 2 baud reg
spi2sr:         equ $fb ;spi 2 status reg hi

sp2dr:          equ $fd ;spi 2 data reg

fclkdiv:	equ $100 ;flash clock divider
fsec:		equ $101 ;flash security register

fcnfg:		equ $103 ;flash configuration register
fprot:		equ $104 ;flash protection register
fstat:		equ $105 ;flash status register
fcmd:		equ $106 ;flash command register

eclkdiv:	equ $110 ;eeprom clock divider

ecnfg:		equ $113 ;eeprom configuration register
eprot:		equ $114 ;eeprom protection register
estat:		equ $115 ;eeprom status register
ecmd:		equ $116 ;eeprom command register

atd1ctl0:       equ $120 ;adc1 control 0 (reserved)
atd1ctl1:       equ $121 ;adc1 control 1 (reserved)
atd1ctl2:       equ $122 ;adc1 control 2
atd1ctl3:       equ $123 ;adc1 control 3
atd1ctl4:       equ $124 ;adc1 control 4
atd1ctl5:       equ $125 ;adc1 control 5
atd1stat:       equ $126 ;adc1 status register hi
*atd1stat       equ $127 ;adc1 status register lo
atd1test:       equ $128 ;adc1 test (reserved)
*atd1test       equ $129 ;

atddien:	equ $12d ;adc1 input enable register

portad1:        equ $12f ;port adc1 = input only
adr10h:         equ $130 ;adc1 result 0 register
adr11h:         equ $132 ;adc1 result 1 register
adr12h:         equ $134 ;adc1 result 2 register
adr13h:         equ $136 ;adc1 result 3 register
adr14h:         equ $138 ;adc1 result 4 register
adr15h:         equ $13a ;adc1 result 5 register
adr16h:         equ $13c ;adc1 result 6 register
adr17h:         equ $13e ;adc1 result 7 register

ptt:		equ $240 ;portt data register
ptit:		equ $241 ;portt input register
ddrt:		equ $242 ;portt direction register
rdrt:		equ $243 ;portt reduced drive register
pert:		equ $244 ;portt pull device enable
ppst:		equ $245 ;portt pull polarity select

pts:		equ $248 ;ports data register
ptis:		equ $249 ;ports input register
ddrs:		equ $24a ;ports direction register
rdrs:		equ $24b ;ports reduced drive register
pers:		equ $24c ;ports pull device enable
ppss:		equ $24d ;ports pull polarity select
woms:		equ $24e ;ports wired or mode register

ptm:		equ $250 ;portm data register
ptim:		equ $251 ;portm input register
ddrm:		equ $252 ;portm direction register
rdrm:		equ $253 ;portm reduced drive register
perm:		equ $254 ;portm pull device enable
ppsm:		equ $255 ;portm pull polarity select
womm:		equ $256 ;portm wired or mode register
modrr:		equ $257 ;portm module routing register
ptp:		equ $258 ;portp data register
ptip:		equ $259 ;portp input register
ddrp:		equ $25a ;portp direction register
rdrp:		equ $25b ;portp reduced drive register
perp:		equ $25c ;portp pull device enable
ppsp:		equ $25d ;portp pull polarity select
piep:		equ $25e ;portp interrupt enable register
pifp:		equ $25f ;portp interrupt flag register
pth:		equ $260 ;porth data register
ptih:		equ $261 ;porth input register
ddrh:		equ $262 ;porth direction register
rdrh:		equ $263 ;porth reduced drive register
perh:		equ $264 ;porth pull device enable
ppsh:		equ $265 ;porth pull polarity select
pieh:		equ $266 ;porth interrupt enable register
pifh:		equ $267 ;porth interrupt flag register
ptj:		equ $268 ;portp data register
ptij:		equ $269 ;portp input register
ddrj:		equ $26a ;portp direction register
rdrj:		equ $26b ;portp reduced drive register
perj:		equ $26c ;portp pull device enable
ppsj:		equ $26d ;portp pull polarity select
piej:		equ $26e ;portp interrupt enable register
pifj:		equ $26f ;portp interrupt flag register

* end registers
