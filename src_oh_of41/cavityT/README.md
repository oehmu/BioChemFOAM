BioChemFOAM CODE for OpenFOAM (OF) 4.1 (OF41)
===================

Files description this case.

<br>

<b>Objective:</b>
Test BioChemFOAM when including the same code as pisoFOAM available in OpenFOAM by default. It is intended to be compared with the case called "cavity" which is the standard example available in OF41 (see [N01]) [oehmu] [2017-03-25]

<br>

---
## Files and Folders - Description

##### FolderName=0/
Initial Conditions (IC) and Boundary conditions (BC).
<br>
##### FolderName=0.5/...10/
Result over time from running the code "<b>BioChemFOAM41_01</b>".
<br>
##### FolderName=BioChemFOAM41_01/
Folder with main code utilized in this case. 
Include only the hydrodynamic code (solve U, P and tubrulent parameters) as the solver pisoFOAM available in OF41. The pisFOAM code is included in the <b>BioChemFOAM</b> model and other elements in <b>BioChemFOAM</b> are deactivated.
<br>
##### FolderName=constant/
Definition of parameters and mesh in OpenFOAM case called "cavityT"
<br>
##### FolderName=system/
Configuration of the case in general: solver "<b>BioChemFOAM41_01</b>", time step, other stuff and numericla methods.
<br>
##### FolderName=postPro_oh/
Files from post-processing.
<br>
##### FolderName=prePro_oh/
Files from pre-processing.
<br>
##### FileName=bash_moveFilesOutVirtualMachine.bash
Bash script that moves resulted files from Virtual Machine to this folder in the host machine.
<br>
##### FileName=cavityT.foam
Dummy file to open case in Paraview.
<br>
##### FileName=log.BioChemFOAM41_01
Main input in terminal when running the code "<b>BioChemFOAM41_01</b>".
<br>
##### FileName=log.blockMesh
log file from running "blockMesh" in an environment running OF41.
<br>
##### FileName=log.checkMesh
log file with information from running "checkMesh" in an environment running OF41.
<br>
---
## Notes [Nnn]
[N01]OF41 this version is the OpenFOAM version 4.1 www.OpenFOAM.org




