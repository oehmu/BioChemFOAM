
		solve(fvm::ddt(Ci) == - fvm::div(phi, Ci)-fvm::div(phiVs,Ci)+fvm::laplacian(nut,Ci));//Bx*

		solve(fvm::ddt(Ci2) == - fvm::div(phi, Ci2)+fvm::laplacian(nut,Ci2));//DOC 

		solve(fvm::ddt(Ci3)  == - fvm::div(phi, Ci3)+fvm::laplacian(nut,Ci3));//DOP 

		solve(fvm::ddt(Ci4) == - fvm::div(phi, Ci4)+fvm::laplacian(nut,Ci4));//DON

		solve(fvm::ddt(Ci5)  == - fvm::div(phi, Ci5)+fvm::laplacian(nut,Ci5));//NH4

		solve(fvm::ddt(Ci6)  == - fvm::div(phi, Ci6)+fvm::laplacian(nut,Ci6));//NO3

		solve(fvm::ddt(Ci7)  == - fvm::div(phi, Ci7)+fvm::laplacian(nut,Ci7));//DO

		solve(fvm::ddt(Ci8)  == - fvm::div(phi, Ci8)+fvm::laplacian(nut,Ci8));//COD

		solve(fvm::ddt(Ci9) == - fvm::div(phi, Ci9)-fvm::div(phiVs,Ci9)+fvm::laplacian(nut,Ci9));//POC*

		solve(fvm::ddt(Ci10) == - fvm::div(phi, Ci10)-fvm::div(phiVs,Ci10)+fvm::laplacian(nut,Ci10));//POP*

		solve(fvm::ddt(Ci11) == - fvm::div(phi, Ci11)-fvm::div(phiVs,Ci11)+fvm::laplacian(nut,Ci11));//PON*


Ci.correctBoundaryConditions();
Ci2.correctBoundaryConditions();
Ci3.correctBoundaryConditions();
Ci4.correctBoundaryConditions();
Ci5.correctBoundaryConditions();
Ci6.correctBoundaryConditions();
Ci7.correctBoundaryConditions();
Ci8.correctBoundaryConditions();
Ci9.correctBoundaryConditions();
Ci10.correctBoundaryConditions();
Ci11.correctBoundaryConditions();

//S_Ci = - fvc::div(phi, Ci)+fvc::laplacian(nut,Ci);
//Info << "S_Ci="<< S_Ci << endl;
//	}
	/*Ci_2=Ci;
	Ci2_2=Ci2;
	Ci3_2=Ci3;
	solve(fvm::ddt(Ci) + fvm::div(phi, Ci)- fvm::laplacian(Dim, Ci)== -k1*Ci3_2/(k2+Ci3_2)*Ci_2/(k3+Ci_2)*Ci_2);
	solve(fvm::ddt(Ci2) + fvm::div(phi, Ci2)- fvm::laplacian(Dim2, Ci2)== k1*Ci3_2/(k2+Ci3_2)*Ci_2/(k3+Ci_2)*Ci_2-k4/((k5+Ci3_2)*(k6+Ci2_2))*Ci2_2);
	solve(fvm::ddt(Ci3) + fvm::div(phi, Ci3)- fvm::laplacian(Dim3, Ci3)== -k7*Ci_2/((k2+Ci3_2)*(k3+Ci_2))*Ci3_2);*/

//}
//////////////

///////////////
//for (int j1=0;j1<1;j1++){

//	for (int j =0;j<2;j++){
	//#       include "CiEqn.H"
		//light modeling

		//solve(fvm::ddt(Ci) == fvm::Sp(Px -BMx -PRx,Ci));//Bx
	//+kEpsilon::nut()
	
//		solve(fvm::ddt(Ci) + fvm::div(phi, Ci) - fvm::laplacian(Dim, Ci)== fvm::Sp((PMx*((Ci5+Ci6)/(KHNx+Ci5+Ci6)) - BMx - PRx),Ci));//Bx
//no funciona		solve(fvm::ddt(Ci) + fvm::div(phi, Ci) - fvm::laplacian(Dim, Ci)== fvm::Sp((PMx*limit((Ci5+Ci6)/(KHNx+Ci5+Ci6),(Ci5+Ci6)/(10)) - BMx - PRx),Ci));//Bx
//solve(fvm::ddt(Ci) + fvm::div(phi, Ci) - fvm::laplacian(Dim, Ci)== fvm::Sp((PMx*exp((Ci5+Ci6)/(KHNx+Ci5+Ci6)) - BMx - PRx),Ci));//Bx OK IT WORKS
//solve(fvm::ddt(Ci) + fvm::div(phi, Ci) - fvm::laplacian(Dim, Ci)== fvm::Sp((PMx*sign(T-15)*((Ci5+Ci6)/(KHNx+Ci5+Ci6)) - BMx - PRx),Ci));//Bx OK IT WORKS
//solve(fvm::ddt(Ci) + fvm::div(phi, Ci) - fvm::laplacian(nut, Ci)== fvm::Sp((PMx*(I/300*exp(1-I/300))*exp(-1.1*(T-15)*(T-15)*(-sign(T-15)+1)/2-1.1*(T-20)*(T-20)*(-sign(T-20)+1)/2)*((Ci5+Ci6)/(KHNx+Ci5+Ci6)) - BMx - PRx),Ci));//Bx OK IT WORKS
//solve(fvm::ddt(Ci) + fvm::div(phi, Ci) - fvm::laplacian(nut, Ci)== fvm::Sp((PMx*(I/300*exp(1-I/300))*exp(-1.1*(T-15)*(T-15)*(-sign(T-15)+1)/2-1.1*(T-20)*(T-20)*(-sign(T-20)+1)/2)*(etaN*(etaN-1)*0.5*(Ci5+Ci6)/(KHNx+Ci5+Ci6)+etaN*(etaN+1)*0.5*(Ci3)/(KHPx+Ci3)) - BMx - PRx),Ci));//Bx OK IT WORKS use minimum function for nutrients
//solve(fvm::ddt(Ci) + fvm::div(phi, Ci) - fvm::laplacian(nut, Ci)== fvm::Sp((PMx*(I/300*exp(1-I/300))*exp(-0.008*(T-15)*(T-15)*(-sign(T-15)+1)/2-0.01*(T-20)*(T-20)*(-sign(T-20)+1)/2)*((Ci5+Ci6)/(KHNx+Ci5+Ci6)*(Ci3)/(KHPx+Ci3)) - BMx - PRx),Ci));//Bx OK IT WORKS. 

/*
		solve(fvm::ddt(Ci3) + fvm::div(phi, Ci3) - fvm::laplacian(nut, Ci3) == 
								(FPDx*BMx+FPDP*PRx)*APC*Ci
							-	fvm::Sp(KDOP,Ci3)
							+	(KP+KPalg*Ci*exp(KTHDR*(T-TRHDR)))*Ci10
			 );//DOP
*/
/*		solve(fvm::ddt(Ci3) + fvm::div(phi, Ci3) - fvm::laplacian(nut, Ci3) == 
								(FPDx*BMx+FPDP*PRx)*APC*Ci
							-	fvm::Sp(KDOP,Ci3)
							+	(KP+KPalg*Ci*exp(KTHDR*(T-TRHDR)))*Ci10
			 );//DOP
*/
/*		solve(fvm::ddt(Ci4) + fvm::div(phi, Ci4) - fvm::laplacian(nut, Ci4) == 
						(FNDx*BMx+FNDP*PRx)*ANCx*Ci
					-	fvm::Sp(KDON,Ci4)
					+	(KN+(KHN)/(KHN+Ci5+Ci6)*KNalg*Ci*exp(KTHDR*(T-TRHDR)))*Ci11
			 );//DON
*/

//		Nit=((Ci7/(KHNitDO+Ci7))*(Ci5/(KHNitN+Ci5))*Nitm*exp(-KNit1*(T-TNit)*(T-Tnit))) IN TERM fvm::Sp(Nit,Ci5))
/*
		solve(fvm::ddt(Ci5) + fvm::div(phi, Ci5) - fvm::laplacian(nut, Ci5) == 
						(FNIx*BMx+FNIP*PRx-PNx*Px)*ANCx*Ci
					+	KDON*Ci3
				-fvm::Sp(((Ci7/(KHNitDO+Ci7))*(1/(KHNitN+Ci5))*Nitm*exp(-KNit1*(T-TNit)*(T-TNit))),Ci5));//NH4

*/		
//PNx_NH4=((Ci6/((KHNx+Ci5)*(KHNx+Ci6))+KHNx/((Ci5+Ci6)*(KHNx+Ci6))))
/*		solve(fvm::ddt(Ci5) + fvm::div(phi, Ci5) - fvm::laplacian(nut, Ci5) == 
				(FNIx*BMx+FNIP*PRx)*ANCx*Ci
			-	fvm::Sp(PNx_NH4*Px*ANCx*Ci,Ci5)
			+	KDON*Ci3
			-	fvm::Sp(((Ci7/(KHNitDO+Ci7))*(1/(KHNitN+Ci5))*Nitm*exp(-KNit1*(T-TNit)*(T-TNit))),Ci5));//NH4
*/
//		Denit=((KHORDO/(KHORDO+Ci7))*(Ci6/(KHDNN+Ci6))*AANOX*(KDC+KDCalg*Ci*exp(KTMNL*(T-TRMNL)))) IN TERM fvm::Sp(ANDC*Denit*Ci2,Ci6)
//		Nit NO CHANGES IN TERM Nit*Ci5 
//		PNx=Ci5*((Ci6/((KHNx+Ci5)*(KHNx+Ci6)))+(KHNx/((Ci5+Ci6)*(KHNx+CiCi6))))
/*
		solve(fvm::ddt(Ci6) + fvm::div(phi, Ci6) - fvm::laplacian(nut, Ci6) == 
						- (1-PNx)*Px*ANCx*Ci
					+	((((Ci7/(KHNitDO+Ci7))*(Ci5/(KHNitN+Ci5))*Nitm*exp(-KNit1*(T-TNit)*(T-TNit)))*Ci5))
					-	fvm::Sp((ANDC*((KHORDO/(KHORDO+Ci7))*(1/(KHDNN+Ci6))*AANOX*(KDC+KDCalg*Ci*exp(KTMNL*(T-TRMNL))))*Ci2),Ci6)
			 );//NO3
*/
/*
		solve(fvm::ddt(Ci6) + fvm::div(phi, Ci6) - fvm::laplacian(nut, Ci6) == 
				- 	Px*ANCx*Ci
				+	fvm::Sp(PNx_NO3_1*Px*ANCx*Ci,Ci6)
				+	PNx_NO3_2*Px*ANCx*Ci
				+	((((Ci7/(KHNitDO+Ci7))*(Ci5/(KHNitN+Ci5))*Nitm*exp(-KNit1*(T-TNit)*(T-TNit)))*Ci5))
				-	fvm::Sp((ANDC*((KHORDO/(KHORDO+Ci7))*(1/(KHDNN+Ci6))*AANOX*(KDC+KDCalg*Ci*exp(KTMNL*(T-TRMNL))))*Ci2),Ci6)
			 );//NO3
*/
//				+	PNx_NO3_2*Px*ANCx*Ci

//		Nit CHANGES IN TERM (AONT*Nit*Ci5) NOW IS fvm::Sp(AONT*Nit*Ci5,Ci7)
//+	(1.3-0.3*PNx)*Px*AOCR*Ci
/*
		solve(fvm::ddt(Ci7) + fvm::div(phi, Ci7) - fvm::laplacian(nut, Ci7) == 
						Px*((1.3-0.3*PNx)*AOCR)*Ci
					-	fvm::Sp(((1-FCDx)*1/(KHRx+Ci7)*BMx)*AOCR*Ci,Ci7)
					-	fvm::Sp((AONT*((1/(KHNitDO+Ci7))*(Ci5/(KHNitN+Ci5))*Nitm*exp(-KNit1*(T-TNit)*(T-TNit)))*Ci5),Ci7)
					-	AOCR*KHR*Ci2
					-	fvm::Sp(1/((KHCOD+Ci7))*KCOD*Ci8,Ci7)

			 );//DO
*/
//Ok next works
/*		solve(fvm::ddt(Ci7) + fvm::div(phi, Ci7) - fvm::laplacian(nut, Ci7) == 
						Px*((1.3-0.3*PNx_DO)*AOCR)*Ci
					-	fvm::Sp(((1-FCDx)*1/(KHRx+Ci7)*BMx)*AOCR*Ci,Ci7)
					-	fvm::Sp((AONT*((1/(KHNitDO+Ci7))*(Ci5/(KHNitN+Ci5))*Nitm*exp(-KNit1*(T-TNit)*(T-TNit)))*Ci5),Ci7)
					-	AOCR*KHR*Ci2
					-	fvm::Sp(1/((KHCOD+Ci7))*KCOD*Ci8,Ci7)
+	Kr*(DOs)
-	fvm::Sp(Kr,Ci7)
			 );//DO*/


//+	Kr*(DOs) //add for best case stored in "solution01_data"
//-	fvm::Sp(Kr,Ci7)
/*		solve(fvm::ddt(Ci8) + fvm::div(phi, Ci8) - fvm::laplacian(nut, Ci8) == -fvm::Sp(Ci7/(KHCOD+Ci7)*KCOD,Ci8));//COD
*/

/*		solve(fvm::ddt(Ci9) + fvm::div(phi, Ci9) - fvm::laplacian(nut, Ci9) == FCP*PRx*Ci-fvm::Sp((KC+KCalg*Ci*exp(KTHDR*(T-TRHDR))),Ci9));//POC
*/
/*		solve(fvm::ddt(Ci10) + fvm::div(phi, Ci10) - fvm::laplacian(nut, Ci10) == FPx*BMx*APC*Ci+FPP*PRx*APC*Ci-fvm::Sp((KP+KPalg*Ci*exp(KTHDR*(T-TRHDR))),Ci10));//POP
*/

/*		solve(fvm::ddt(Ci11) + fvm::div(phi, Ci11) - fvm::laplacian(nut, Ci11) == FNx*BMx*ANCx*Ci+FNP*PRx*ANCx*Ci-fvm::Sp((KN+(KHN)/(KHN+Ci5+Ci6)*KNalg*Ci*exp(KTHDR*(T-TRHDR))),Ci11));//PON
*/
