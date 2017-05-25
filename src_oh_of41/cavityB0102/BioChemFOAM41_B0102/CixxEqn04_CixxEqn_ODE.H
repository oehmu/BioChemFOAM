//######################################################
//only one step in the operation splitting method
//######################################################

//Ci_2=Ci;
//Ci2_2=Ci2;
//Ci3_2=Ci3;
//Ci4_2=Ci4;
//Ci5_2=Ci5;
Ci6_2=Ci6;
//Ci7_2=Ci7;
//Ci8_2=Ci8;
//Ci9_2=Ci9;
//Ci10_2=Ci10;
//Ci11_2=Ci11;

//solve (temporal term+convection)
//Info      << "...BEGIN tempora+convection STEP" << dyStart<<endl;
Info      << "...BEGIN T+A-D=0 STEP" << endl;
if (ST_model == 1) {
	#include "CixxEqn04.H"
}

if (ST_model == 2) {
	#include "CixxEqn04_sedimentation.H"
}

/*Ci_2=Ci;
Ci2_2=Ci2;
Ci3_2=Ci3;
Ci4_2=Ci4;
Ci5_2=Ci5;
Ci6_2=Ci6;
Ci7_2=Ci7;
Ci8_2=Ci8;
Ci9_2=Ci9;
Ci10_2=Ci10;
Ci11_2=Ci11;*/


Info      << "...END T+A-D=0 STEP" << endl;


Info      << "...BEGIN T=R, PCBP STEP" <<endl;
//solve PCBP
#include "CixxEqn_ODE.H"
Info      << "...END T=R, PCBP STEP" <<endl;


Info      << "...BEGIN correct Boundary for species" <<endl;
//Ci.correctBoundaryConditions();
//Ci2.correctBoundaryConditions();
//Ci3.correctBoundaryConditions();
//Ci4.correctBoundaryConditions();
//Ci5.correctBoundaryConditions();
Ci6.correctBoundaryConditions();
//Ci7.correctBoundaryConditions();
//Ci8.correctBoundaryConditions();
//Ci9.correctBoundaryConditions();
//Ci10.correctBoundaryConditions();
//Ci11.correctBoundaryConditions();
Info      << "...END correct Boundary for species" <<endl;

Info      << "...BEGIN Error calculation" <<endl;
//E1_Ci  = 0.5*( (max(Ci-Ci_2)).value()- (min(Ci-Ci_2)).value());
//E1_Ci2 = 0.5*( (max(Ci2-Ci2_2)).value()- (min(Ci2-Ci2_2)).value());;
//E1_Ci3 = 0.5*( (max(Ci3-Ci3_2)).value()- (min(Ci3-Ci3_2)).value());
//E1_Ci4 = 0.5*( (max(Ci4-Ci4_2)).value()- (min(Ci4-Ci4_2)).value());
//E1_Ci5 = 0.5*( (max(Ci5-Ci5_2)).value()- (min(Ci5-Ci5_2)).value());
E1_Ci6 = 0.5*( (max(Ci6-Ci6_2)).value()- (min(Ci6-Ci6_2)).value());
//E1_Ci7 = 0.5*( (max(Ci7-Ci7_2)).value()- (min(Ci7-Ci7_2)).value());
//E1_Ci8 = 0.5*( (max(Ci8-Ci8_2)).value()- (min(Ci8-Ci8_2)).value());
//E1_Ci9 = 0.5*( (max(Ci9-Ci9_2)).value()- (min(Ci9-Ci9_2)).value());
//E1_Ci10 = 0.5*( (max(Ci10-Ci10_2)).value()- (min(Ci10-Ci10_2)).value());
//E1_Ci11 = 0.5*( (max(Ci11-Ci11_2)).value()- (min(Ci11-Ci11_2)).value());

/*scalar E1_Ci  = (max(Ci-Ci_2)).value();
scalar E1_Ci2 = (max(Ci2-Ci2_2)).value();
scalar E1_Ci3 = (max(Ci3-Ci3_2)).value();
scalar E1_Ci4 = (max(Ci4-Ci4_2)).value();
scalar E1_Ci5 = (max(Ci5-Ci5_2)).value();
scalar E1_Ci6 = (max(Ci6-Ci6_2)).value();
scalar E1_Ci7 = (max(Ci7-Ci7_2)).value();
scalar E1_Ci8 = (max(Ci8-Ci8_2)).value();
scalar E1_Ci9 = (max(Ci9-Ci9_2)).value();
scalar E1_Ci10 = (max(Ci10-Ci10_2)).value();
scalar E1_Ci11 = (max(Ci11-Ci11_2)).value();*/

//EE2 = E1_Ci + E1_Ci2 + E1_Ci3 + E1_Ci4 + E1_Ci5 + E1_Ci6 + E1_Ci7 + E1_Ci8 + E1_Ci9 + E1_Ci10 + E1_Ci11;
EE2 = E1_Ci6;
//Info << "...Sum Abs Difference (sum(Ci-Ci_2)).value()     = " << E1_Ci << "-max= " << (max(Ci-Ci_2)).value() << "-min = "<< (min(Ci-Ci_2)).value() <<endl;
//Info << "...Sum Abs Difference (sum(Ci2-Ci2_2)).value()   = " << E1_Ci2  << "-max= " << (max(Ci2-Ci2_2)).value() << "-min = "<< (min(Ci2-Ci2_2)).value() << endl;
//Info << "...Sum Abs Difference (sum(Ci3-Ci3_2)).value()   = " << E1_Ci3 << "-max= " << (max(Ci3-Ci3_2)).value() << "-min = "<< (min(Ci3-Ci3_2)).value() << endl;
//Info << "...Sum Abs Difference (sum(Ci4-Ci4_2)).value()   = " << E1_Ci4 << "-max= " << (max(Ci4-Ci4_2)).value() << "-min = "<< (min(Ci4-Ci4_2)).value() <<endl;
//Info << "...Sum Abs Difference (sum(Ci5-Ci5_2)).value()   = " << E1_Ci5 << "-max= " << (max(Ci5-Ci5_2)).value() << "-min = "<< (min(Ci5-Ci5_2)).value() <<endl;
Info << "...Sum Abs Difference (sum(Ci6-Ci6_2)).value()   = " << E1_Ci6 << "-max= " << (max(Ci6-Ci6_2)).value() << "-min = "<< (min(Ci6-Ci6_2)).value()<< endl;
//Info << "...Sum Abs Difference (sum(Ci7-Ci7_2)).value()   = " << E1_Ci7 << "-max= " << (max(Ci7-Ci7_2)).value() << "-min = "<< (min(Ci7-Ci7_2)).value() <<endl;
//Info << "...Sum Abs Difference (sum(Ci8-Ci8_2)).value()   = " << E1_Ci8 << "-max= " << (max(Ci8-Ci8_2)).value() << "-min = "<< (min(Ci8-Ci8_2)).value() <<endl;
//Info << "...Sum Abs Difference (sum(Ci9-Ci9_2)).value()   = " << E1_Ci9 << "-max= " << (max(Ci9-Ci9_2)).value() << "-min = "<< (min(Ci9-Ci9_2)).value() <<endl;
//Info << "...Sum Abs Difference (sum(Ci10-Ci10_2)).value() = " << E1_Ci10 << "-max= " << (max(Ci10-Ci10_2)).value() << "-min = "<< (min(Ci10-Ci10_2)).value() <<endl;
//Info << "...Sum Abs Difference (sum(Ci11-Ci11_2)).value() = " << E1_Ci11 << "-max= " << (max(Ci11-Ci11_2)).value() << "-min = "<< (min(Ci11-Ci11_2)).value() <<endl;
//Info << "...Sum Abs Difference ALL                        = " << EE2 << " ----- " << (EE1) << endl;

if (m <= Nm)
{
				if ((EE2 < EE1) && (EE2 > - EE1) ) 
				{
					j = Nm +1;
				}
				else
				{
					m = m+1;
				}
}
else
{
	j = Nm +1;
}

if (m == 5)
{
	EE1=4e-3;
}
if (m == 10)
{
	EE1=4e-2;
}


Info      << "...END Error calculation" <<endl;

/*
Info      << "...BEGIN 2nd T+A-D=0 STEP" << endl;
#include "CixxEqn04.H"
Info      << "...END 2nd T+A-D=0 STEP" << endl;


Info      << "...BEGIN Error calculation" <<endl;
//scalar E1_Ci  = (sum(Ci-Ci_2)).value();
//scalar E1_Ci2 = (sum(Ci2-Ci2_2)).value();
//scalar E1_Ci3 = (sum(Ci3-Ci3_2)).value();
//scalar E1_Ci4 = (sum(Ci4-Ci4_2)).value();
//scalar E1_Ci5 = (sum(Ci5-Ci5_2)).value();
//scalar E1_Ci6 = (sum(Ci6-Ci6_2)).value();
//scalar E1_Ci7 = (sum(Ci7-Ci7_2)).value();
//scalar E1_Ci8 = (sum(Ci8-Ci8_2)).value();
//scalar E1_Ci9 = (sum(Ci9-Ci9_2)).value();
//scalar E1_Ci10 = (sum(Ci10-Ci10_2)).value();
//scalar E1_Ci11 = (sum(Ci11-Ci11_2)).value();

E1_Ci  = (sum(Ci-Ci_2)).value();
E1_Ci2 = (sum(Ci2-Ci2_2)).value();
E1_Ci3 = (sum(Ci3-Ci3_2)).value();
E1_Ci4 = (sum(Ci4-Ci4_2)).value();
E1_Ci5 = (sum(Ci5-Ci5_2)).value();
E1_Ci6 = (sum(Ci6-Ci6_2)).value();
E1_Ci7 = (sum(Ci7-Ci7_2)).value();
E1_Ci8 = (sum(Ci8-Ci8_2)).value();
E1_Ci9 = (sum(Ci9-Ci9_2)).value();
E1_Ci10 = (sum(Ci10-Ci10_2)).value();
E1_Ci11 = (sum(Ci11-Ci11_2)).value();
//EE2 = E1_Ci*sign(E1_Ci) + E1_Ci2*sign(E1_Ci2) + E1_Ci3*sign(E1_Ci3) + E1_Ci4*sign(E1_Ci4) + E1_Ci5*sign(E1_Ci5) + E1_Ci6*sign(E1_Ci6) + E1_Ci7*sign(E1_Ci7) + E1_Ci8*sign(E1_Ci8) + E1_Ci9*sign(E1_Ci9) + E1_Ci10*sign(E1_Ci10) + E1_Ci11*sign(E1_Ci11);
EE2 = E1_Ci + E1_Ci2 + E1_Ci3 + E1_Ci4 + E1_Ci5 + E1_Ci6 + E1_Ci7 + E1_Ci8 + E1_Ci9 + E1_Ci10 + E1_Ci11;
//Info << "...Sum Abs Difference " << sum(Ci-Ci_2) << endl;
Info << "...Sum Abs Difference (sum(Ci-Ci_2)).value()     = " << E1_Ci << "-max= " << (max(Ci-Ci_2)).value() << "-min = "<< (min(Ci-Ci_2)).value() <<endl;
//Info << "...Sum Abs Difference " << sum(Ci2-Ci2_2) << endl;
Info << "...Sum Abs Difference (sum(Ci2-Ci2_2)).value()   = " << E1_Ci2  << "-max= " << (max(Ci2-Ci2_2)).value() << "-min = "<< (min(Ci2-Ci2_2)).value() << endl;
//Info << "...Sum Abs Difference " << sum(Ci3-Ci3_2) << endl;
Info << "...Sum Abs Difference (sum(Ci3-Ci3_2)).value()   = " << E1_Ci3 << "-max= " << (max(Ci3-Ci3_2)).value() << "-min = "<< (min(Ci3-Ci3_2)).value() << endl;
//Info << "...Sum Abs Difference " << sum(Ci4-Ci4_2) << endl;
Info << "...Sum Abs Difference (sum(Ci4-Ci4_2)).value()   = " << E1_Ci4 << "-max= " << (max(Ci4-Ci4_2)).value() << "-min = "<< (min(Ci4-Ci4_2)).value() <<endl;
//Info << "...Sum Abs Difference " << sum(Ci5-Ci5_2) << endl;
Info << "...Sum Abs Difference (sum(Ci5-Ci5_2)).value()   = " << E1_Ci5 << "-max= " << (max(Ci5-Ci5_2)).value() << "-min = "<< (min(Ci5-Ci5_2)).value() <<endl;
//Info << "...Sum Abs Difference " << sum(Ci6-Ci6_2) << endl;
Info << "...Sum Abs Difference (sum(Ci6-Ci6_2)).value()   = " << E1_Ci6 << "-max= " << (max(Ci6-Ci6_2)).value() << "-min = "<< (min(Ci6-Ci6_2)).value()<< endl;
//Info << "...Sum Abs Difference " << sum(Ci7-Ci7_2) << endl;
Info << "...Sum Abs Difference (sum(Ci7-Ci7_2)).value()   = " << E1_Ci7 << "-max= " << (max(Ci7-Ci7_2)).value() << "-min = "<< (min(Ci7-Ci7_2)).value() <<endl;
//Info << "...Sum Abs Difference " << sum(Ci8-Ci8_2) << endl;
Info << "...Sum Abs Difference (sum(Ci8-Ci8_2)).value()   = " << E1_Ci8 << "-max= " << (max(Ci8-Ci8_2)).value() << "-min = "<< (min(Ci8-Ci8_2)).value() <<endl;
//Info << "...Sum Abs Difference " << sum(Ci9-Ci9_2) << endl;
Info << "...Sum Abs Difference (sum(Ci9-Ci9_2)).value()   = " << E1_Ci9 << "-max= " << (max(Ci9-Ci9_2)).value() << "-min = "<< (min(Ci9-Ci9_2)).value() <<endl;
//Info << "...Sum Abs Difference " << sum(Ci10-Ci10_2) << endl;
Info << "...Sum Abs Difference (sum(Ci10-Ci10_2)).value() = " << E1_Ci10 << "-max= " << (max(Ci10-Ci10_2)).value() << "-min = "<< (min(Ci10-Ci10_2)).value() <<endl;
//Info << "...Sum Abs Difference " << sum(Ci11-Ci11_2) << endl;
Info << "...Sum Abs Difference (sum(Ci11-Ci11_2)).value() = " << E1_Ci11 << "-max= " << (max(Ci11-Ci11_2)).value() << "-min = "<< (min(Ci11-Ci11_2)).value() <<endl;
Info << "...Sum Abs Difference ALL                        = " << EE2 << endl;
	Info << "EE2---EE1 = " << (EE2) <<" ----- " << (EE1) << endl;
//first if to account for a maximum number of outer iterations even EE1 wasnt reached so continue
//second if is to test if the EE1 error was achieved.
//m containts at the end the number of outter iterations
if (m <= Nm)
{
				if ((EE2 < EE1) && (EE2 > - EE1) ) 
				{
					j = Nm +1;
				}
				else
				{
					m = m+1;
				}
}
else
{
	j = Nm +1;
}		
Info      << "...END Error calculation" <<endl;
*/

