//if ( Up_GO_STOP == 1){
    Info<< "Reading field p\n" << endl;
    volScalarField p
    (
        IOobject
        (
            "p",
            runTime.timeName(),
            mesh,
            IOobject::MUST_READ,
            IOobject::AUTO_WRITE
        ),
        mesh
    );

    Info<< "Reading field U\n" << endl;
    volVectorField U
    (
        IOobject
        (
            "U",
            runTime.timeName(),
            mesh,
            IOobject::MUST_READ,
            IOobject::AUTO_WRITE
        ),
        mesh
    );

    volScalarField nut
    (
        IOobject
        (
            "nut",
            runTime.timeName(),
            mesh,
            IOobject::MUST_READ,
            IOobject::AUTO_WRITE
        ),
        mesh
    );

    #include "createPhi.H"

    label pRefCell = 0;
    scalar pRefValue = 0.0;
    //setRefCell(p, mesh.solutionDict().subDict("PISO"), pRefCell, pRefValue);
    setRefCell(p, piso.dict(), pRefCell, pRefValue);
    mesh.setFluxRequired(p.name());

    singlePhaseTransportModel laminarTransport(U, phi);

    autoPtr<incompressible::turbulenceModel> turbulence
    (
        incompressible::turbulenceModel::New(U, phi, laminarTransport)
    );

    #include "createMRF.H"
//}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Info<< "\nReading lightProperties" << endl;

IOdictionary lightProperties
(
    IOobject
    (
        "lightProperties",
        runTime.constant(),
        mesh,
        IOobject::MUST_READ_IF_MODIFIED,
        IOobject::NO_WRITE
    )
);

const dimensionedVector nI(lightProperties.lookup("nI"));
Info<< "Reading field I(represents Light(radiation), photons) propagation on the mass of water)\n" << endl;
    volScalarField I
    (
        IOobject
        (
            "I",
            runTime.timeName(),
            mesh,
            IOobject::MUST_READ,
            IOobject::AUTO_WRITE
        ),
        mesh
    );
dimensionedScalar ki
(
     lightProperties.lookup("ki")
);
dimensionedScalar D_I
    (
        lightProperties.lookup("D_I")
    );
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


    Info<< "Reading transportProperties\n" << endl;

    IOdictionary transportProperties
    (
        IOobject
        (
            "transportProperties",
            runTime.constant(),
            mesh,
            IOobject::MUST_READ_IF_MODIFIED,
            IOobject::NO_WRITE
        )
    );

    dimensionedScalar nu
    (
        transportProperties.lookup("nu")
    );
/////////for Diffusion fixed value

    dimensionedScalar Dim
    (
        transportProperties.lookup("Dim")
    );
dimensionedScalar Dim2
    (
        transportProperties.lookup("Dim2")
    );
dimensionedScalar Dim3
    (
        transportProperties.lookup("Dim3")
    );
dimensionedScalar Dim4
    (
        transportProperties.lookup("Dim4")
    );
dimensionedScalar Dim5
    (
        transportProperties.lookup("Dim5")
    );
dimensionedScalar Dim6
    (
        transportProperties.lookup("Dim6")
    );
dimensionedScalar Dim7
    (
        transportProperties.lookup("Dim7")
    );
dimensionedScalar Dim8
    (
        transportProperties.lookup("Dim8")
    );
dimensionedScalar Dim9
    (
        transportProperties.lookup("Dim9")
    );
dimensionedScalar Dim10
    (
        transportProperties.lookup("Dim10")
    );
dimensionedScalar Dim11
    (
        transportProperties.lookup("Dim11")
    );


//for Bx
/*dimensionedScalar Px
    (
        transportProperties.lookup("Px")
    );*/

dimensionedScalar PMx//maximum growth rate for algal group x(day-1)
    (
        transportProperties.lookup("PMx")
    );

dimensionedScalar KHNx//nitrogen half saturation constant for algal group x(mass/volume)
    (
        transportProperties.lookup("KHNx")
    );

//------------------------------------------------
/*
dimensionedScalar BMx
    (
        transportProperties.lookup("BMx")
    );*/

dimensionedScalar BMRx
    (
        transportProperties.lookup("BMRx")
    );

dimensionedScalar alphap
    (
        transportProperties.lookup("alphap")
    );
//BxP
dimensionedScalar BxP
    (
        transportProperties.lookup("BxP")
    );

//----------------------------------------------------

dimensionedScalar KTBx
    (
        transportProperties.lookup("KTBx")
    );

/*
dimensionedScalar PRx
    (
        transportProperties.lookup("PRx")
    );
*/
dimensionedScalar PRRx
    (
        transportProperties.lookup("PRRx")
    );

//for DOC
dimensionedScalar FCDx
    (
        transportProperties.lookup("FCDx")
    );

dimensionedScalar KHRx
    (
        transportProperties.lookup("KHRx")
    );

dimensionedScalar FCDP
    (
        transportProperties.lookup("FCDP")
    );

/*dimensionedScalar KHR
    (
        transportProperties.lookup("KHR")
    );*/

/*dimensionedScalar Denit
    (
        transportProperties.lookup("Denit")
    );*/

dimensionedScalar FPDx
    (
        transportProperties.lookup("FPDx")
    );

dimensionedScalar FPDP
    (
        transportProperties.lookup("FPDP")
    );

dimensionedScalar APC
    (
        transportProperties.lookup("APC")
    );

/*dimensionedScalar KDOP
    (
        transportProperties.lookup("KDOP")
    );*/

dimensionedScalar KDP
    (
        transportProperties.lookup("KDP")
    );

dimensionedScalar KDPalg
    (
        transportProperties.lookup("KDPalg")
    );

dimensionedScalar FNDx
    (
        transportProperties.lookup("FNDx")
    );

dimensionedScalar FNDP
    (
        transportProperties.lookup("FNDP")
    );

dimensionedScalar ANCx
    (
        transportProperties.lookup("ANCx")
    );

/*dimensionedScalar KDON
    (
        transportProperties.lookup("KDON")
    );
*/




dimensionedScalar FNIx
    (
        transportProperties.lookup("FNIx")
    );
dimensionedScalar FNIP
    (
        transportProperties.lookup("FNIP")
    );

dimensionedScalar PNx
    (
        transportProperties.lookup("PNx")
    );



dimensionedScalar Nit
    (
        transportProperties.lookup("Nit")
    );

dimensionedScalar ANDC
    (
        transportProperties.lookup("ANDC")
    );



dimensionedScalar AOCR
    (
        transportProperties.lookup("AOCR")
    );

dimensionedScalar AONT
    (
        transportProperties.lookup("AONT")
    );


dimensionedScalar KHCOD
    (
        transportProperties.lookup("KHCOD")
    );

dimensionedScalar KCOD
    (
        transportProperties.lookup("KCOD")
    );

dimensionedScalar Kr
    (
        transportProperties.lookup("Kr")
    );

dimensionedScalar DOs
    (
        transportProperties.lookup("DOs")
    );

/*UNA vulgaridad!! pero ahora OK!!
dimensionedScalar k1
    (
        transportProperties.lookup("k1")
    );
*/
dimensionedScalar DT
(
     transportProperties.lookup("DT")
);
///////new
dimensionedScalar AANOX
(
     transportProperties.lookup("AANOX")
);


dimensionedScalar KHORDO
(
     transportProperties.lookup("KHORDO")
);

dimensionedScalar KHDNN
(
     transportProperties.lookup("KHDNN")
);

dimensionedScalar KDC
(
     transportProperties.lookup("KDC")
);

dimensionedScalar KDCalg
(
     transportProperties.lookup("KDCalg")
);

dimensionedScalar KTMNL
(
     transportProperties.lookup("KTMNL")
);

dimensionedScalar TRMNL
(
     transportProperties.lookup("TRMNL")
);

dimensionedScalar KHNitDO
(
     transportProperties.lookup("KHNitDO")
);

dimensionedScalar KHNitN
(
     transportProperties.lookup("KHNitN")
);

dimensionedScalar Nitm
(
     transportProperties.lookup("Nitm")
);

dimensionedScalar KNit1
(
     transportProperties.lookup("KNit1")
);

dimensionedScalar TNit
(
     transportProperties.lookup("TNit")
);

dimensionedScalar FCP
(
     transportProperties.lookup("FCP")
);

dimensionedScalar KC
(
     transportProperties.lookup("KC")
);

dimensionedScalar KCalg
(
     transportProperties.lookup("KCalg")
);

dimensionedScalar KTHDR
(
     transportProperties.lookup("KTHDR")
);

dimensionedScalar TRHDR
(
     transportProperties.lookup("TRHDR")
);

dimensionedScalar FPx
(
     transportProperties.lookup("FPx")
);

/*dimensionedScalar APC
(
     transportProperties.lookup("APC")
);*/

dimensionedScalar FPP
(
     transportProperties.lookup("FPP")
);

dimensionedScalar KP
(
     transportProperties.lookup("KP")
);

dimensionedScalar KPalg
(
     transportProperties.lookup("KPalg")
);

dimensionedScalar FNx
(
     transportProperties.lookup("FNx")
);



dimensionedScalar FNP
(
     transportProperties.lookup("FNP")
);

dimensionedScalar KN
(
     transportProperties.lookup("KN")
);

dimensionedScalar KHN
(
     transportProperties.lookup("KHN")
);

dimensionedScalar KNalg
(
     transportProperties.lookup("KNalg")
);

dimensionedScalar KHPx
(
     transportProperties.lookup("KHPx")
);

dimensionedScalar KDN
(
     transportProperties.lookup("KDN")
);

/////////
/////////////////
Info<< "Reading field T\n" <<endl;
volScalarField T
(
    IOobject
    (
         "T",
         runTime.timeName(),
         mesh,
         IOobject::MUST_READ,
         IOobject::AUTO_WRITE
     ),
     mesh
);

    Info<< "Reading field Ci(Bx:algal biomass of group x)\n" << endl;
    volScalarField Ci
    (
        IOobject
        (
            "Ci",
            runTime.timeName(),
            mesh,
            IOobject::MUST_READ,
            IOobject::AUTO_WRITE
        ),
        mesh
    );

    Info<< "Reading field Ci2(DOC:Dissolved Organic Carbon)\n" << endl;
    volScalarField Ci2
    (
        IOobject
        (
            "Ci2",
            runTime.timeName(),
            mesh,
            IOobject::MUST_READ,
            IOobject::AUTO_WRITE
        ),
        mesh
    );

    Info<< "Reading field Ci3(DOP:Disolved Organic Phosphorus)\n" << endl;
    volScalarField Ci3
    (
        IOobject
        (
            "Ci3",
            runTime.timeName(),
            mesh,
            IOobject::MUST_READ,
            IOobject::AUTO_WRITE
        ),
        mesh
    );

    Info<< "Reading field Ci4(DON:Disolved Organic Nitrogen)\n" << endl;
    volScalarField Ci4
    (
        IOobject
        (
            "Ci4",
            runTime.timeName(),
            mesh,
            IOobject::MUST_READ,
            IOobject::AUTO_WRITE
        ),
        mesh
    );

    Info<< "Reading field Ci5(NH4:Ammonium Ion)\n" << endl;
    volScalarField Ci5
    (
        IOobject
        (
            "Ci5",
            runTime.timeName(),
            mesh,
            IOobject::MUST_READ,
            IOobject::AUTO_WRITE
        ),
        mesh
    );

    Info<< "Reading field Ci6(NO3:Nitrate Nitrogen)\n" << endl;
    volScalarField Ci6
    (
        IOobject
        (
            "Ci6",
            runTime.timeName(),
            mesh,
            IOobject::MUST_READ,
            IOobject::AUTO_WRITE
        ),
        mesh
    );

    Info<< "Reading field Ci7(DO:Dissolved Oxygen)\n" << endl;
    volScalarField Ci7
    (
        IOobject
        (
            "Ci7",
            runTime.timeName(),
            mesh,
            IOobject::MUST_READ,
            IOobject::AUTO_WRITE
        ),
        mesh
    );

    Info<< "Reading field Ci8(COD:Chemical Oxygen Demand)\n" << endl;
    volScalarField Ci8
    (
        IOobject
        (
            "Ci8",
            runTime.timeName(),
            mesh,
            IOobject::MUST_READ,
            IOobject::AUTO_WRITE
        ),
        mesh
    );

    Info<< "Reading field Ci9(POC:Particulate Organic Carbon)\n" << endl;
    volScalarField Ci9
    (
        IOobject
        (
            "Ci9",
            runTime.timeName(),
            mesh,
            IOobject::MUST_READ,
            IOobject::AUTO_WRITE
        ),
        mesh
    );

    Info<< "Reading field Ci10(POP:Particulate Organic Phosphorus)\n" << endl;
    volScalarField Ci10
    (
        IOobject
        (
            "Ci10",
            runTime.timeName(),
            mesh,
            IOobject::MUST_READ,
            IOobject::AUTO_WRITE
        ),
        mesh
    );

    Info<< "Reading field Ci11(PON:Particulate Organic Nitrogen)\n" << endl;
    volScalarField Ci11
    (
        IOobject
        (
            "Ci11",
            runTime.timeName(),
            mesh,
            IOobject::MUST_READ,
            IOobject::AUTO_WRITE
        ),
        mesh
    );


    Info<< "Reading field ID_DO\n" << endl;
    volScalarField ID_Reareation
    (
        IOobject
        (
            "ID_Reareation",
            runTime.timeName(),
            mesh,
            IOobject::MUST_READ,
            IOobject::AUTO_WRITE
        ),
        mesh
    );

    Info<< "Reading field ID_NO3\n" << endl;
    volScalarField ID_NO3
    (
        IOobject
        (
            "ID_NO3",
            runTime.timeName(),
            mesh,
            IOobject::MUST_READ,
            IOobject::AUTO_WRITE
        ),
        mesh
    );


volScalarField DD_I
(
    IOobject
    (
        "DD_I",
        runTime.timeName(),
        mesh
    ),
    D_I*exp(-Ci/(0.001+Ci))
);


Info<< "Creating field etaN for ALGAE NUTRIENTS selection Minimum value Nitrogen and Phosphorus components\n" << endl;
volScalarField etaN
(
    IOobject
    (
        "etaN",
        runTime.timeName(),
        mesh
    ),
    (sign((Ci5+Ci6)/(KHNx+Ci5+Ci6) - (Ci3)/(KHPx+Ci3)))
);


volScalarField Ci_2("Ci_2", Ci);
volScalarField Ci2_2("Ci2_2", Ci2);
volScalarField Ci3_2("Ci3_2", Ci3);
volScalarField Ci4_2("Ci4_2", Ci4);
volScalarField Ci5_2("Ci5_2", Ci5);
volScalarField Ci6_2("Ci6_2", Ci6);
volScalarField Ci7_2("Ci7_2", Ci7);
volScalarField Ci8_2("Ci8_2", Ci8);
volScalarField Ci9_2("Ci9_2", Ci9);
volScalarField Ci10_2("Ci10_2", Ci10);
volScalarField Ci11_2("Ci11_2", Ci11);

scalar E1_Ci  = 1;
scalar E1_Ci2 = 1;
scalar E1_Ci3 = 1;
scalar E1_Ci4 = 1;
scalar E1_Ci5 = 1;
scalar E1_Ci6 = 1;
scalar E1_Ci7 = 1;
scalar E1_Ci8 = 1;
scalar E1_Ci9 = 1;
scalar E1_Ci10 = 1;
scalar E1_Ci11 = 1;

//volScalarField Ci9_3("Ci9_3", Ci9);

volScalarField Ci9_3
    (
        IOobject
        (
            "Ci9_3",
            runTime.timeName(),
            mesh,
            IOobject::NO_READ,
            IOobject::AUTO_WRITE
        ),
        Ci9
    );

volScalarField S_Ci
(
    IOobject
    (
        "S_Ci",
        runTime.timeName(),
        mesh
    ),
    - fvc::div(phi, Ci)+fvc::laplacian(nut,Ci)
);    


/////////sedimentation of particulate organic part and algae///////////////////////////////
IOdictionary sedimentProperties
(
    IOobject
    (
        "sedimentProperties",
        runTime.constant(),
        mesh,
        IOobject::MUST_READ_IF_MODIFIED,
        IOobject::NO_WRITE
    )
);
const dimensionedVector Vs(sedimentProperties.lookup("Vs"));

surfaceScalarField phiVs
(
    IOobject
    (
        "phiVs",
        runTime.timeName(),
        mesh,
        IOobject::READ_IF_PRESENT,
        IOobject::AUTO_WRITE
    ),
    Vs & mesh.Sf()
);
////////////////////////////////////////////////////

/*
volScalarField S_Ci2("S_Ci2", Ci2);
volScalarField S_Ci3_2("S_Ci3", Ci3);
volScalarField S_Ci4_2("S_Ci4", Ci4);
volScalarField S_Ci5_2("S_Ci5", Ci5);
volScalarField S_Ci6_2("S_Ci6", Ci6);
volScalarField S_Ci7_2("S_Ci7", Ci7);
volScalarField S_Ci8_2("S_Ci8", Ci8);
volScalarField S_Ci9_2("S_Ci9", Ci9);
volScalarField S_Ci10_2("S_Ci10", Ci10);
volScalarField S_Ci11_2("S_Ci11", Ci11);
*/
/*
Info<< "Reading field Ci0(I/I0:growing limiting function)\n" << endl;
    volScalarField Ci0
    (
        IOobject
        (
            "Ci0",
            runTime.timeName(),
            mesh,
            IOobject::MUST_READ,
            IOobject::AUTO_WRITE
        ),
        mesh
    );
*/
//const dimensionedVector g(gravitationalProperties.lookup("Ke"));
/*volScalarField Ci_2("Ci_2", Ci);
volScalarField Ci2_2("Ci2_2", Ci2);
volScalarField Ci3_2("Ci3_2", Ci3);
*/
////////////////

