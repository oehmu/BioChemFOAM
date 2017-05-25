// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
	//Basic definition for the class, functions, variables , etc....
	#include "CixxEqn_ODE_class.H" 

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

///Define the class to hold the ODEs to be solved    
testODE ode;

///Define the numerical method to use to solve the ODEs
//    autoPtr<ODESolver> odeSolver = ODESolver::New(args[1], ode);
    //autoPtr<ODESolver> odeSolver = ODESolver::New("RK", ode);//RK: no jacobian //does not work in OF4.1
    //autoPtr<ODESolver> odeSolver = ODESolver::New("RKCK45", ode);//RK: no jacobian //does not work in OF4.1
	//BEGIN: for OF4.1
	dictionary dict;
	dict.add("solver", "RKCK45");
    autoPtr<ODESolver> odeSolver = ODESolver::New(ode, dict);//RK: no jacobian
 	//END: for OF4.1

Info<< "..BEGING: Solving ODEs" << endl;
Info<< "...Delta Time is "<< runTime.deltaTValue() << endl;//works to get delta time!!
scalar dT = runTime.deltaTValue();
Info<< "...and actual Time is "<< runTime.value() << endl;//works to get delta time!!
scalar aT = runTime.value();

//BEGIN: loop over all cells and solve in each an ODE
forAll (mesh.C(),celli)
{
	//set initial time
    scalar xStart = aT-dT;//like time

	//Get Temperature from cell and assign it to the corresponding class variable
	//ode.Temperatura = T[celli];

	//Get Radiation from cell and assign it to the corresponding class variable
	//ode.Iradiation = I[celli];

	//ode.IDDO = ID_Reareation[celli];

	//ode.IDNO3 = ID_NO3[celli];

	//Create a scalar field for yStart then define IC
    scalarField yStart(ode.nEqns());
    //yStart[0] = Ci[celli];
    //yStart[1] = Ci2[celli];
    //yStart[2] = Ci3[celli];
    //yStart[3] = Ci4[celli];
    //yStart[4] = Ci5[celli];
    yStart[0] = Ci6[celli];
    //yStart[6] = Ci7[celli];
    //yStart[7] = Ci8[celli];
    //yStart[8] = Ci9[celli];
    //yStart[9] = Ci10[celli];
    //yStart[10] = Ci11[celli];

    //This vector has the derivatives
	//este vector contiene  los valores de las derivadas, se pasa por referencia a la clase "ode"
    scalarField dyStart(ode.nEqns());
	//Info      << "Numerical:   = " << dyStart<<endl;

    //Solve the ODEs
	//aqui se llama la funcion "derivatives" de la clase "ode"
	//con la informacion anterior
    ode.derivatives(xStart, yStart, dyStart);
	
    scalar x = xStart;

	//aqui se define el tiempo final de calculo de las ODEs
    scalar xEnd = aT;

	//aqui se define un scalarField para almacenar los resultados
    scalarField y(yStart);

	//assign temperature and I to class "ode"
	//ode.Temperatura = T[celli];
	//ode.Iradiation = I[celli];
	//Info << "Temperature : " << ode.Temperatura << endl;
	//Info << "I : " << ode.Iradiation << " celli = " << celli << endl;


  	//Info<< "..Solving ODEs\n" << endl;
	//	for(label i=0;i<=1;i++){
		//it is the time step for ODE method, explained in "reportZongyuan.pdf"
		scalar hEst = 0.25;//0.05;//0.005
		//scalar hEst = dT/8;//0.005 dT/2 dT/4

		//aqui se resuelven las ODEs
		//1e-6 es la precision??
		odeSolver->relTol() = 1e-8;
		odeSolver->solve(xStart, xEnd, y, hEst);//1e-6

		//odeSolver->solve(ode, xStart, xEnd, y, 1e-8, hEst);//1e-6 //for OF2.3.1

		//Info << y[0] << endl;//ok it works to get a value from the solution
		//Info<< nl << "Solution at time:  = " << xEnd << endl;
		//Info      << "Numerical:   = " << y << ", hEst = " << hEst << endl;
		//Info      <<  y << endl;
	//		xStart=xEnd;
	//		xEnd=xEnd+0.1;	
	//	}
    //Info<< "\nEnd\n" << endl;


	///put values in mesh
	//forAll (Ci,celli)
	//{
		//aqui se assigna el valor calculado a cada celda deacuerdo a la solucion de las ODEs
		//Ci[celli]=y[0];
		//Ci2[celli]=y[1];
		//Ci3[celli]=y[2];
		//Ci4[celli]=y[3];
		//Ci5[celli]=y[4];
		Ci6[celli]=y[0];
		//Ci7[celli]=y[6];
		//Ci8[celli]=y[7];
		//Ci9[celli]=y[8];
		//Ci10[celli]=y[9];
		//Ci11[celli]=y[10];
}
//END: loop over all cells and solve in each an ODE

Info<< "..End Solving ODEs\n" << endl;

//[oehmu]