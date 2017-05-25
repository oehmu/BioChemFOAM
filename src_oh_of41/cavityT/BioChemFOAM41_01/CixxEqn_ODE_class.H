class testODE
:
    //public ODE //fro OF2.3.1
    public ODESystem
{

public:
	//BEGIN: defining some variables
		scalar Temperatura;
		scalar Iradiation;
		scalar IDDO;
		scalar IDNO3;
	//END : defining some variables
    testODE()
    {}

	//BEGIN: define number of equations to solve
	    label nEqns() const
	    {
	        return 1;//this is the number of ODEs to be solved
	    }
	//END: define number of equations to solve

	//BEGIN: define derivatives to solve, meaning ODEs
    void derivatives
    (
        const scalar x,
        const scalarField& y,
        scalarField& dydx
    ) const
    {
		//Begin: NO3 -----------------------------------------------------------------------
			//PNx
			//Px
			//ANCx
			//Nit
			scalar ANDC=0.933;
			scalar kno3 =4.03624e-6;//4.03624e-5;
			scalar NO3s =1e-3;
			//Denit
			//IDN03 is introduced to apply this condiiton only in 
			//      given regions of the domain under study. e.g. close to a boundary
	        //dydx[0] =  IDNO3*kno3*NO3s - IDNO3*kno3*y[0];//NO3
	        //Next line solve this equaiton in all cells of the domain
	        dydx[0] =  kno3*NO3s - kno3*y[0];//NO3
		//End: NO3   ----------------------------OEHMU---------------------------------------

    }
	//END: define derivatives to solve, meaning ODEs

	//BEGIN: define jacobian for the ODEs
    void jacobian
    (
        const scalar x,
        const scalarField& y,
        scalarField& dfdx,
        scalarSquareMatrix& dfdy
    ) const
    {
		/*        dfdx[0] = -0.25;
		        dfdx[1] = (1.0/sqr(x))*y[1];
		        dfdx[2] = (2.0/sqr(x))*y[2];
		        dfdx[3] = (3.0/sqr(x))*y[3];
		*/
    }
	//END: define jacobian for the ODEs
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

