#!/bin/bash


echo "Which Physics List do you wish to change to? Pol or A2?" 
read line
if [ "${line}" == "Pol" ]; then
	sed -i -e 's/A2PhysicsList/PolPhysicsList/g' ./src/A2.cc
	sed -i -e 's:/A2/physics/Physics QGSP_BIC:/Pol/physics/Physics QGSP_BIC_POL:g' ./macros/doppi0.mac
        sed -i -e 's:/A2/physics/SetRegion:/Pol/physics/SetRegion:g' ./macros/doppi0.mac
        sed -i -e 's:/A2/physics/RegionCut:/Pol/physics/RegionCut:g' ./macros/doppi0.mac
        sed -i -e 's:/A2/physics/Physics QGSP_BIC:/Pol/physics/Physics QGSP_BIC_POL:g' ./macros/doneta.mac
        sed -i -e 's:/A2/physics/Physics QGSP_BIC:/Pol/physics/Physics QGSP_BIC_POL:g' ./macros/DGdoppi0.mac





elif [ "${line}" == "A2" ]; then
	sed -i -e 's/PolPhysicsList/A2PhysicsList/g' ./src/A2.cc
        sed -i -e 's:/Pol/physics/Physics QGSP_BIC_POL:/A2/physics/Physics QGSP_BIC:g' ./macros/doppi0.mac
        sed -i -e 's:/Pol/physics/SetRegion:/A2/physics/SetRegion:g' ./macros/doppi0.mac
        sed -i -e 's:/Pol/physics/RegionCut:/A2/physics/RegionCut:g' ./macros/doppi0.mac
        sed -i -e 's:/Pol/physics/Physics QGSP_BIC_POL:/A2/physics/Physics QGSP_BIC:g' ./macros/doneta.mac
        sed -i -e 's:/Pol/physics/Physics QGSP_BIC_POL:/A2/physics/Physics QGSP_BIC:g' ./macros/DGdoppi0.mac




fi
exit 0 
