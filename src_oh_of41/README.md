BioChemFOAM for OpenFOAM 4.3.1 (OF41)
===================

## *Overview*
<b>BioChemFOAM</b>  applications for OF41.
Store code and examples per case. This is done these way since some 
cases may introduce different parameterization, so source code may change as needed.

[oehmu] [2017-03-25]
<br>
More information can be found in the PhD dissertation <b><sup>[R01]</sup></b> and in the peer review Journal publication <b><sup>[R02]</sup></b>. <br>


---

## Comparison of cases and configuration of BioChemFOAM(Bhhss)

###### B0101 = H01 + S01
[2017-04-03]
H01:= hydrodynamic model 01 using pisoFOAM defined by default in OpenFOAM.
S01:= means BioChemFOAM configured with T=0 (T meaning the time derivate of an species), meaning no species transport over time.
B0101:= is the name of the asssigned to the configuration derived by combining H01 with S01. 
C01:=is the cavity case study defined by default in OpenFOAM which runs pisoFOAM
C01{B0101}:= is the cavity case utilizing the BioChemFOAM configuration described by <b>B0101</b>.


###### B0102 = H01 + S02
S02:= (T=R) simulates one reaction transport equation, similar to having nitrate in all cells of the domain without any spacial interation. Each cell acts as an independent tank.

Files updated:
BioChemFOAM41_B0102.C -> {LN79 -> int CiI_Go_STOP=1;}
CixxEqn04.H -> {Ln13 -> #comment line} + {Ln31 -> #comment line}


---

##Folders and Files - Description
#
##### -->cavity/
Case with examples running pisoFOAM. Original program from OpenFOAM 4.1.
#
##### -->cavityT/
Case utilizing BioChemFOAM configured to run only hydrodynamics, that should give the same results as case="cavity/".



---


## How to compile the code:

To do!!

