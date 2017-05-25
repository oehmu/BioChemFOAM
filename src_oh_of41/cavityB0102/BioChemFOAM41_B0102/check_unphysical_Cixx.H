//OEHMU
//int i0_check_unphysical_Cixx = 0;
if (j == 3) {
	forAll (mesh.C(),celli)
	{
		//-----------------------------------------------------------------------------------
		//##Section to ensure possitive solutions for al scalar fields Cixx 01/08/2014
		if (Ci[celli] < 0.00001) {Ci[celli] = 0.00001;i0_check_unphysical_Cixx=1;}
		if (Ci2[celli] < 0.00001) {Ci2[celli] = 0.00001;i0_check_unphysical_Cixx=1;}
		if (Ci3[celli] < 0.00001) {Ci3[celli] = 0.00001;i0_check_unphysical_Cixx=1;}
		if (Ci4[celli] < 0.00001) {Ci4[celli] = 0.00001;i0_check_unphysical_Cixx=1;}
		if (Ci5[celli] < 0.00001) {Ci5[celli] = 0.00001;i0_check_unphysical_Cixx=1;}
		if (Ci6[celli] < 0.00001) {Ci6[celli] = 0.00001;i0_check_unphysical_Cixx=1;}
		if (Ci7[celli] < 0.00001) {Ci7[celli] = 0.00001;i0_check_unphysical_Cixx=1;}
		if (Ci8[celli] < 0.00001) {Ci8[celli] = 0.00001;i0_check_unphysical_Cixx=1;}
		if (Ci9[celli] < 0.00001) {Ci9[celli] = 0.00001;i0_check_unphysical_Cixx=1;}
		if (Ci10[celli] < 0.00001) {Ci10[celli] = 0.00001;i0_check_unphysical_Cixx=1;}
		if (Ci11[celli] < 0.00001) {Ci11[celli] = 0.00001;i0_check_unphysical_Cixx=1;}

		//-----------------------------------------------------------------------------------
		//##Section to ensure a superior limit for scalar fields Cixx 01/08/2014
			/*if (Ci[celli] > 15) {Ci7[celli] = 1;i0_check_unphysical_Cixx=1;}

			//values for Ci5 and Ci6 from file "NO3_dataToSampleOF_compareWITHMeasured.xlsx" if using mean values or
			//paper james2008a.pdf mean values for July
			if (Ci5[celli] > 5) {Ci5[celli] = 0.01;i0_check_unphysical_Cixx=1;}
			if (Ci6[celli] > 5) {Ci6[celli] = 2;i0_check_unphysical_Cixx=1;}
			if (Ci7[celli] > 15) {Ci7[celli] = 11;i0_check_unphysical_Cixx=1;}*/
		//-----------------------------------------------------------------------------------
		/*i0_check_unphysical_Cixx = 0;// not run next portion of code
		if (i0_check_unphysical_Cixx == 1)
		{
			if (i1_check_unphysical_Cixx < 1)
			{
				Info<< "....->Attemt to fix cells, help solver " << endl;
				#include "CixxEqn.H"
				i0_check_unphysical_Cixx=0;
				i1_check_unphysical_Cixx++;
			}
			else
			{
				i1_check_unphysical_Cixx = 0;
			}
		}*/

	}
	if (i0_check_unphysical_Cixx == 1)
	{
		Info<< "....->Attemt to fix cells with NEGATIVES < 0.00001" << endl;
	}

}

if (j == 1) {
	forAll (mesh.C(),celli)
	{
		//-----------------------------------------------------------------------------------
		//##Section to ensure possitive solutions for al scalar fields Cixx 01/08/2014
		if (Ci[celli] < 0.00001) {i0_check_unphysical_Cixx=1;}
		if (Ci2[celli] < 0.00001) {i0_check_unphysical_Cixx=1;}
		if (Ci3[celli] < 0.00001) {i0_check_unphysical_Cixx=1;}
		if (Ci4[celli] < 0.00001) {i0_check_unphysical_Cixx=1;}
		if (Ci5[celli] < 0.00001) {i0_check_unphysical_Cixx=1;}
		if (Ci6[celli] < 0.00001) {i0_check_unphysical_Cixx=1;}
		if (Ci7[celli] < 0.00001) {i0_check_unphysical_Cixx=1;}
		if (Ci8[celli] < 0.00001) {i0_check_unphysical_Cixx=1;}
		if (Ci9[celli] < 0.00001) {i0_check_unphysical_Cixx=1;}
		if (Ci10[celli] < 0.00001) {i0_check_unphysical_Cixx=1;}
		if (Ci11[celli] < 0.00001) {i0_check_unphysical_Cixx=1;}
	}
	if (i0_check_unphysical_Cixx == 1)
	{
		Info<< "....->OJO there are some negatives STILL when Attemting to fix cells with NEGATIVES < 0.00001" << endl;
	}

}

