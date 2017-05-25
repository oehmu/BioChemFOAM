/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | Copyright (C) 2011 OpenFOAM Foundation
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

Application
    pisoFoam+species aquatic ecosystems(OEHMU)

Description
    Transient solver for incompressible flow.

    Turbulence modelling is generic, i.e. laminar, RAS or LES may be selected.

\*---------------------------------------------------------------------------*/

#include "fvCFD.H"
#include "singlePhaseTransportModel.H"
//#include "turbulenceModel.H" //OF2.3.1
#include "turbulentTransportModel.H"
#include "pisoControl.H"
#include "fvOptions.H"

////////////
#include "argList.H"
#include "IOmanip.H"
//#include "ODE.H" //for OF2.3.1
#include "ODESystem.H"
#include "ODESolver.H"
//#include "RK.H"
#include "RKCK45.H"
///////

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

int main(int argc, char *argv[])
{
    #include "postProcess.H"

    #include "setRootCase.H"
    #include "createTime.H"
    #include "createMesh.H"
    #include "createControl.H"
    
    #include "createFields.H"
    
    #include "createFvOptions.H"
    #include "initContinuityErrs.H"

    // * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

    Info<< "\nStarting time loop\n" << endl;
    //BEGIN: Definition global variables
        int Up_GO_STOP=1;

        int T_GO_STOP=1;
        int k_T_GO_STOP_YesNo =1;//1: yes 0:no
        int k_T_GO_STOP =0;//Number of time steps to calculate T before freezed
        int k1_T_GO_STOP =0;//step variable

        int I_Go_STOP=0;
        int CiI_Go_STOP=1;

        int check_unphysical_Cixx_GO_STOP = 0;
        int i0_check_unphysical_Cixx = 0;
        int i1_check_unphysical_Cixx = 1;//number of corrections
        int Nm = 20;
        scalar EE1=4e-4;//1e-4 1e-3 5e-3
        scalar EE2=1;
        int j = 1;
        int m =1 ;

        int ST_model = 1;//1: without sedimentation 2: with sedimentation
    //END: Definition global variables
    
    turbulence->validate();
    //BEGIN: time loop
    while (runTime.loop())
    {
        Info<< "Time = " << runTime.timeName() << nl << endl;
        Info << "Up_GO_STOP = " << Up_GO_STOP << endl;
        //BEGIN: solve hydrodynamics
            if (Up_GO_STOP==1){
                //#include "readPISOControls.H"
                #include "CourantNo.H"

                //BEGIN: Pressure-velocity PISO corrector
                {
                    // Momentum predictor
                    //BEGIN: #include UEqn.H
                        //#include "UEqn.H"
                    // Solve the Momentum equation
                        MRF.correctBoundaryVelocity(U);

                        fvVectorMatrix UEqn
                        (
                            fvm::ddt(U) + fvm::div(phi, U)
                          + MRF.DDt(U)
                          + turbulence->divDevReff(U)
                         ==
                            fvOptions(U)
                        );

                        UEqn.relax();

                        fvOptions.constrain(UEqn);

                        if (piso.momentumPredictor())
                        {
                            solve(UEqn == -fvc::grad(p));

                            fvOptions.correct(U);
                        }
                    //END: #include UEqn.H

                    //BEGIN: PISO loop
                    // --- PISO loop
                        while (piso.correct()) {
                            //#include "pEqn.H"
                            volScalarField rAU(1.0/UEqn.A());
                            volVectorField HbyA(constrainHbyA(rAU*UEqn.H(), U, p));
                            surfaceScalarField phiHbyA
                            (
                                "phiHbyA",
                                fvc::flux(HbyA)
                              + fvc::interpolate(rAU)*fvc::ddtCorr(U, phi)
                            );

                            MRF.makeRelative(phiHbyA);

                            adjustPhi(phiHbyA, U, p);

                            // Update the pressure BCs to ensure flux consistency
                            constrainPressure(p, U, phiHbyA, rAU, MRF);

                            // Non-orthogonal pressure corrector loop
                            while (piso.correctNonOrthogonal())
                            {
                                // Pressure corrector

                                fvScalarMatrix pEqn
                                (
                                    fvm::laplacian(rAU, p) == fvc::div(phiHbyA)
                                );

                                pEqn.setReference(pRefCell, pRefValue);

                                pEqn.solve(mesh.solver(p.select(piso.finalInnerIter())));

                                if (piso.finalNonOrthogonalIter())
                                {
                                    phi = phiHbyA - pEqn.flux();
                                }
                            }

                            #include "continuityErrs.H"

                            U = HbyA - rAU*fvc::grad(p);
                            U.correctBoundaryConditions();
                            fvOptions.correct(U);
                        }
                    //END : PISO loop
                }
                //END: Pressure-velocity PISO corrector

                laminarTransport.correct();
                turbulence->correct();
                //runTime.write();
            }
        //END: solve hydrodynamics

        //BEGIN: Temperature solution
            if (T_GO_STOP==1){
                //SOLVE Temperature
                       #include "TEqn.H"
                        k1_T_GO_STOP++;
                //if (k_T_GO_STOP_YesNo==1){
                //      if (k1_T_GO_STOP==k_T_GO_STOP && k_T_GO_STOP > 0)
                //      {
                //          T_GO_STOP=0;    
                //      }
                //}
                //END solve temperature
            }
        //END: Temperature solution
        
        //BEGIN: couple systems of PDEs solver T+A-D=0 and T=R
            if (CiI_Go_STOP==1){
                //for (int j1=0;j1<1;j1++){
                    //here I have 2 iterations by default hard coded, see j<2
                    //for (int j =0;j<Nm;j++)
                    while (j < Nm){
                        if (I_Go_STOP == 1) {
                            //SOlVE light (photons) as an adimensional parameter with only a temporal+diffusion terms
                            #include "IEqn.H"
                            //END solve light
                        }
                        //SOLVE Species
                        //              #include "CixxEqn.H"
                        //#include "CixxEqn02.H"
                        //#include "CixxEqn_ODE.H"
                        #include "CixxEqn04_CixxEqn_ODE.H"
                        //END solve species
                        
                        /*if (check_unphysical_Cixx_GO_STOP == 1)
                        {
                            //CHECK for unphysical values 
                            #include "check_unphysical_Cixx.H"
                            //END CHECK for unphysical values 
                        }*/
                    }
                    Info << "...Total Outer Iterations = " << m << endl;
                    Info << "...Final ERROR = " << EE2 <<endl;
                    j = 1; m = 1; EE1 = 4e-4;
                //}
            }
        //END: couple systems of PDEs solver
        
        runTime.write();

        Info<< "ExecutionTime = " << runTime.elapsedCpuTime() << " s"
                << "  ClockTime = " << runTime.elapsedClockTime() << " s"
                << nl << endl;
    }
    //END: time loop

    Info<< "End\n" << endl;

    return 0;
}


// ************************************************************************* //
