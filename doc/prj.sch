<Qucs Schematic 0.0.19>
<Properties>
  <View=-56,-34,1190,864,1.21,0,52>
  <Grid=10,10,1>
  <DataSet=prj.dat>
  <DataDisplay=prj.dpl>
  <OpenDisplay=0>
  <Script=prj.m>
  <RunScript=0>
  <SimInhibitWindow=0>
  <showFrame=0>
  <FrameText0=Title>
  <FrameText1=Drawn By:>
  <FrameText2=Date:>
  <FrameText3=Revision:>
</Properties>
<Symbol>
  <.ID -20 -16 SUB>
  <Line -20 20 40 0 #000080 2 1>
  <Line 20 20 0 -40 #000080 2 1>
  <Line -20 -20 40 0 #000080 2 1>
  <Line -20 20 0 -40 #000080 2 1>
</Symbol>
<Components>
  <.TR TR1 1 560 550 0 65 0 0 "lin" 1 "0" 1 "1 ms" 1 "11" 0 "Trapezoidal" 0 "2" 0 "1 ns" 0 "1e-16" 0 "150" 0 "0.001" 0 "1 pA" 0 "1 uV" 0 "26.85" 0 "1e-3" 0 "1e-6" 0 "1" 0 "CroutLU" 0 "no" 0 "yes" 0 "0" 0>
  <IProbe Pr1 1 380 380 -41 -26 0 3>
  <GND * 5 380 550 0 0 0 0>
  <R RL 1 380 480 15 -26 0 1 "180" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "european" 0>
  <GND * 1 290 230 0 0 0 0>
  <_BJT BC547BP_1 1 290 190 8 -26 0 0 "npn" 0 "1.8e-14" 0 "0.9955" 0 "1.005" 0 "0.14" 0 "0.03" 0 "80" 0 "12.5" 0 "5e-14" 0 "1.46" 0 "1.72e-13" 0 "1.27" 0 "400" 0 "35.5" 0 "0" 0 "0" 0 "0.25" 0 "0.6" 0 "0.56" 0 "1.3e-11" 0 "0.75" 0 "0.33" 0 "4e-12" 0 "0.54" 0 "0.33" 0 "1" 0 "0" 0 "0.75" 0 "0" 0 "0.5" 0 "6.4e-10" 0 "0" 0 "0" 0 "0" 0 "5.072e-08" 0 "26.85" 0 "0" 0 "1" 0 "1" 0 "0" 0 "1" 0 "1" 0 "0" 0 "0" 0 "3" 0 "1.11" 0 "26.85" 0 "1" 0>
  <R R4 1 220 190 -26 15 0 0 "12k" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "european" 0>
  <Switch T3 1 130 190 -26 11 0 0 "on" 0 ".6ms" 1 "0" 0 "1e12" 0 "26.85" 0 "1e-6" 0 "spline" 0>
  <Vdc V1 1 -10 360 18 -26 0 1 "3.7 V" 1>
  <Switch T1 1 30 190 -26 11 0 0 "off" 0 ".2ms" 1 "0" 0 "1e12" 0 "26.85" 0 "1e-6" 0 "spline" 0>
  <Switch T0 1 30 610 -26 11 0 0 "off" 0 ".1ms" 1 "0" 0 "1e12" 0 "26.85" 0 "1e-6" 0 "spline" 0>
  <Switch T2 1 130 610 -26 11 0 0 "on" 0 ".3ms" 1 "0" 0 "1e12" 0 "26.85" 0 "1e-6" 0 "spline" 0>
  <_BJT Q2N3906_1 1 290 310 -26 -26 1 1 "pnp" 0 "4e-14" 0 "1" 0 "1" 0 "0.02" 0 "0" 0 "50" 0 "0" 0 "7e-15" 0 "1.16" 0 "0" 0 "2" 0 "400" 0 "7.5" 0 "0" 0 "0" 0 "2.4" 0 "0" 0 "0" 0 "6.3e-12" 0 "0.75" 0 "0.33" 0 "5.8e-12" 0 "0.75" 0 "0.33" 0 "1" 0 "0" 0 "0.75" 0 "0" 0 "0.5" 0 "5e-10" 0 "0" 0 "0" 0 "0" 0 "2.3e-08" 0 "26.85" 0 "6e-16" 0 "1" 0 "1" 0 "0" 0 "1" 0 "1" 0 "0" 0 "1.5" 0 "3" 0 "1.11" 0 "26.85" 0 "1" 0>
  <GND * 1 80 510 0 0 0 0>
  <R R3 1 200 430 15 -26 0 1 "10k" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "european" 0>
  <R R2 1 290 490 15 -26 0 1 "18k" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "european" 0>
</Components>
<Wires>
  <160 190 190 190 "" 0 0 0 "">
  <290 520 290 610 "" 0 0 0 "">
  <160 610 200 610 "" 0 0 0 "">
  <200 610 290 610 "" 0 0 0 "">
  <200 460 200 610 "" 0 0 0 "">
  <200 310 200 400 "" 0 0 0 "">
  <200 310 260 310 "" 0 0 0 "">
  <290 340 290 460 "" 0 0 0 "">
  <320 310 380 310 "" 0 0 0 "">
  <380 310 380 350 "" 0 0 0 "">
  <380 410 380 450 "Vav" 400 430 40 "">
  <380 510 380 550 "" 0 0 0 "">
  <250 190 260 190 "" 0 0 0 "">
  <290 220 290 230 "" 0 0 0 "">
  <290 140 290 160 "" 0 0 0 "">
  <290 140 460 140 "" 0 0 0 "">
  <-10 310 200 310 "" 0 0 0 "">
  <60 190 100 190 "" 0 0 0 "">
  <60 610 100 610 "" 0 0 0 "">
  <-10 190 0 190 "" 0 0 0 "">
  <-10 190 -10 310 "" 0 0 0 "">
  <-10 310 -10 330 "" 0 0 0 "">
  <460 140 460 610 "Vm" 500 610 405 "">
  <290 610 460 610 "" 0 0 0 "">
  <-10 610 0 610 "" 0 0 0 "">
  <-10 390 -10 450 "" 0 0 0 "">
  <-10 450 -10 610 "" 0 0 0 "">
  <-10 450 80 450 "" 0 0 0 "">
  <80 450 80 510 "" 0 0 0 "">
</Wires>
<Diagrams>
  <Rect 560 490 484 165 3 #c0c0c0 1 00 0 0 0.0001 0.001 1 -0.00199603 0.01 0.0219563 1 -1 1 1 315 0 225 "time (s)" "Pr1 (A)" "" "">
	<"Pr1.It" #0000ff 0 3 0 0 0>
  </Rect>
  <Tab 560 290 307 242 3 #c0c0c0 1 00 1 0 1 1 1 0 1 1 1 0 1 30 315 0 225 "" "" "" "">
	<"Pr1.It" #0000ff 0 3 1 0 0>
	<"Vav.Vt" #0000ff 0 3 1 0 0>
	<"Vm.Vt" #0000ff 0 3 1 0 0>
  </Tab>
</Diagrams>
<Paintings>
  <Text -10 60 12 #000000 0 "T0,T2 switch on push button\nT1 auto sustain power\nT3 digital shutdown">
</Paintings>
