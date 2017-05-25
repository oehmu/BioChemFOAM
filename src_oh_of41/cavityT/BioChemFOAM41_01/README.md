BioChemFOAM CODE for OpenFOAM (OF) 4.1 (OF41)
===================

## *Overview*
<b>BioChemFOAM</b> all code files for this example. Includes only one species and shows the general idea presented in References <b>[R01]</b> and <b>[R02]</b>.
<br>

---
<b>BioChemFOAM</b> files structure, see [N01]:
- ->BioChemFOAM41_01.C
- ----> ```#include "createFields.H"```
- ----> ```#include "UEqn.H"```
- ----> ```#include "pEqn.H"```
- ----> ```#include "TEqn.H"```
- ----> ```#include "IEqn.H"```
- ----> ```#include "CixxEqn04_CixxEqn_ODE.H"```
- --------> ```#include "CixxEqn04.H"``` or ```#include "CixxEqn04_sedimentation.H"```
- --------> ```#include "CixxEqn_ODE.H"```
- ------------> ```#include "CixxEqn_ODE_class.H"```

---
## Files and Folders - Description

##### FolderName=Make/
Stores information to compile the code.[2016_12_14] 

##### FileName=BioChemFOAM_NO3_3.C
Main C++ code.[2016_12_14] 

##### FileName=IEqn.H
Solving ligh (photons), equations in OF format.[2016_12_14] 

##### FileName=CixxEqn04_CixxEqn_ODE.H
Solves T+A-D=0 and then solves T=R (here is the splitting operator method). Call two other files {CixxEqn04.H, CixxEqn_ODE.H, CixxEqn_ODE_class.H}.[2016_12_14] 

##### FileName=CixxEqn04.H
Solves T+A-D=0. [2016_12_14] 

##### FileName=CixxEqn_ODE.H
Solves T=R. Calls the file {CixxEqn_ODE_class.H}. [2016_12_14] 

##### FileName=CixxEqn_ODE_class.H
Define the class which solves the ODEs in T=R. [2016_12_14] 


---
## Procedures [Pnn], Notes [Nnn] and References[Rnn]

<b>[R01]</b>:= Hernandez Murcia, Oscar Eduardo. "Development of a highly resolved 3-D computational model for applications in water quality and ecosystems." (2014). http://ir.uiowa.edu/etd/1334/. [2016_12_14]<br>
<b>[R02]</b>:= Murcia, Oscar E Hernandez, Douglas J Schnoebelen, Athanasios N Papanicolaou, and Benjamin Abban. n.d. “Coupling Flow with Nutrient Dynamics via BioChemFOAM in the Mississippi River.” Journal of Applied Water Engineering and Research 0 (0): 1–23. doi:10.1080/23249676.2017.1287020. [2016-03-25]<br>

<br>

<b>[N01]</b>:=[2016-03-25]The software has been tested only in OF41.<br>

