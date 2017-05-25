 fvScalarMatrix IEqn
        (
            fvm::ddt(I)
//            - D_I*exp(-Ci/(0.001+Ci))*fvm::laplacian(I)//doesnt work all the time, no last time
//            - D_I*Ci/(0.0001+Ci)*fvm::laplacian(I)//doesnt work all the time, no last time
//exp(-Ci/(0.001+Ci))
//            - D_I*fvm::laplacian(I)+fvm::Sp(ki*Ci/(0.001+Ci),I) //it works
//            - D_I*fvm::laplacian(I)+fvm::Sp(ki*exp(Ci/(0.001+Ci)),I) //it works
			//- fvm::laplacian(D_I, I)+fvm::Sp(ki*Ci/(0.001+Ci),I)
//-ki*I
//- fvm::laplacian(D_I*Ci/(0.001+Ci), I)
-fvm::laplacian(DD_I,I)
        );
//DD_I is defined in "createFields.H"
IEqn.relax();
IEqn.solve();
