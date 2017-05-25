BioChemFOAM
===================

<b>BioChemFOAM</b> is a CFD model developed initially in OpenFOAM 2.3.1(OF231) which solves a couple system of partial differential equations (PDE). The methodology allows coupling of hydrodynamic and biochemical processes in aquatic ecosystems. 
<br>
<b>BioChemFOAM</b> utilizes mainly an splitting-operator technique in OF to solve the coupling system of non-linear equations for the biochemical processes (e.g. concentration of nitrate, concentration of phosphorus, concentration of algae, etc). 
<br>
More information can be found in the PhD dissertation <b><sup>[R01]</sup></b> and in the Journal publication <b><sup>[R02]</sup></b>. 
<br>
The code and examples presented here serves as a basis to include different parameterization and to extend its capabilities by utilizing e.g. other hydrodynamic models, turbulence, available in OpenFOAM(OF).<br>


---

### FolderName=src_oh_of41/
Source code and examples for OF 4.1. See [N01] and [N02].

---

### Procedures [Pnn], Notes [Nnn] and References[Rnn]
---
<b>[R01]</b>:= Hernandez Murcia, Oscar Eduardo. "Development of a highly resolved 3-D computational model for applications in water quality and ecosystems." (2014). http://ir.uiowa.edu/etd/1334/. [2016_12_14]<br>
<b>[R02]</b>:= Coupling flow with nutrient dynamics via BioChemFOAM in the Mississippi River
Oscar E. Hernandez Murcia, Douglas J. Schnoebelen, Athanasios N. Papanicolaou &Benjamin Abban
Pages 1-23 | Received 14 Jul 2016, Accepted 13 Dec 2016, Published online: 20 Feb 2017
[Journal of Applied Water Engineering and Research 2016](www.tandfonline.com/doi/full/10.1080/23249676.2017.1287020)  fully accepted and peer reviewed.<br>

<br>

<b>[N01]</b>:=[2017-05-24] The software has been tested only in OF41.<br>


