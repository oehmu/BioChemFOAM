 fvScalarMatrix TEqn
        (
            fvm::ddt(T)
            + fvm::div(phi, T)
            - fvm::laplacian(nut, T)
//            - fvm::laplacian(DT, T)
        );
        TEqn.solve();
