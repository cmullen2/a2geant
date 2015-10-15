#include "A2DetPol.hh"
#include "G4VisAttributes.hh"
#include "G4Colour.hh"
#include "G4SDManager.hh"
#include "G4ThreeVector.hh"
#include "G4RotationMatrix.hh"
#include "G4Tubs.hh"
#include "G4Cons.hh"
#include "G4SubtractionSolid.hh"

A2DetPID::A2DetPol(){
  fregionPol=NULL;
  fregionPol=new G4Region("Pol");//allows seperate cuts to be defined for crystal
  //Polarimeter
  //  G4Tubs* npol=new G4Tubs("NPOL",10/2*mm,60*mm,40/2*mm,0*deg,360*deg);
  G4double  Xoff=0*CLHEP::mm;
  // G4double  Yoff=7.8*mm;
  G4double  Yoff=0*CLHEP::mm;     //original
  //G4double  Yoff=5*mm;        //shift graphite
  // fZ0=0*cm;

}

A2DetPID::~A2DetPol(){
  //delete Rot;
}

G4VPhysicalVolume* A2DetPol::Construct1(G4LogicalVolume* MotherLogical,G4double Z0){
  //Build the Phase 1 polarimeter (2009)

  fMotherLogic=MotherLogical;

  //some parameters
  fPol_Z = 207.5*CLHEP::mm;
  fPol_rin = 69.5*CLHEP::mm;
  fPol_rout = 92.5*CLHEP::mm;

  //Make the polarimeter shape
  MakeTube();
  MakeCap();
  //MakeSupports1();

  fMyPhysi = new G4PVPlacement(0, G4ThreeVector(0,0,0), fMyLogic, "MWPC", fMotherLogic, false, 1);


  return fMyPhysi;
}

G4VPhysicalVolume* A2DetPol::Construct2(G4LogicalVolume* MotherLogical,G4double Z0){
  //Build the phase 2 polarimeter (2015/2016)

  fMotherLogic=MotherLogical;
  //some parameters
  fPol_Z = 207.5*CLHEP::mm;
  fPol_rin = 69.5*CLHEP::mm;
  fPol_rout = 92.5*CLHEP::mm;

  //Make the polarimeter shape
  MakeTube();
  MakeCap();
  // MakeSupports2();

  //  fMyLogic->SetVisAttributes (G4VisAttributes::Invisible);

  return fMyPhysi; // Need to define this, what is it and why does it matter?
}

void A2DetPol::MakeTube(){
  // Make polarimeter tube

  //*************carbon cylinder
  G4double tubez0=-10*CLHEP::mm+fPol_Z/2;
  G4Tubs* npol2=new G4Tubs("NPOL2", fPol_rin, fPol_rout , fPol_Z/2,0*CLHEP::deg,360*CLHEP::deg);     //small gap between cylinder and pipe wall where styrofoam was placed
  G4LogicalVolume* npolLogic2=new G4LogicalVolume(npol2,G4NistManager::Instance()->FindOrBuildMaterial("A2_G348GRAPHITE"),"NPOL2");
  G4VPhysicalVolume* npolPhysi2=new G4PVPlacement(0,G4ThreeVector(Xoff,Yoff,tubez0),npolLogic2,"NPOL2",fWorldLogic,false,998);
}

void A2DetPol::MakeCap(){
  // Make cap for polarimeter

  //********forward cap
  G4Tubs* npol=new G4Tubs("NPOL",40./2*CLHEP::mm,190*CLHEP::mm/2,70./2*CLHEP::mm,0*CLHEP::deg,360*CLHEP::deg);
  G4LogicalVolume* npolLogic=new G4LogicalVolume(npol,G4NistManager::Instance()->FindOrBuildMaterial("A2_G348GRAPHITE"),"NPOL");
  // G4VPhysicalVolume* npolPhysi=new G4PVPlacement(0,G4ThreeVector(0,0,12*cm+40/2*mm),npolLogic,"NPOL",fWorldLogic,false,999);  //this stays commented out
  G4VPhysicalVolume* npolPhysi=new G4PVPlacement(0,G4ThreeVector(Xoff,Yoff,31.5*CLHEP::cm),npolLogic,"NPOL",fWorldLogic,false,999);     //put this one back

}


//void A2DetPol::MakeSupports1(){
  // Make the supporting structure

  //**********orange support tube
  //G4Tubs* nptube=new G4Tubs("NPTUBE",195./2*CLHEP::mm,200*CLHEP::mm/2,280./2*CLHEP::cm,0*CLHEP::deg,360*CLHEP::deg);
  //G4LogicalVolume* nptubeLogic=new G4LogicalVolume(nptube,G4NistManager::Instance()->FindOrBuildMaterial("G4_POLYVINYL_CHLORIDE"),"NPTUBE");
  //G4VPhysicalVolume* nptubePhysi=new G4PVPlacement(0,G4ThreeVector(Xoff,Yoff-0.*CLHEP::mm,-9.4*CLHEP::cm),nptubeLogic,"NPTUBE",fWorldLogic,false,997);

//}

//void A2DetPol::MakeSupports2(){
  // Make the supporting structure

  //**********orange support tube
  //G4Tubs* nptube=new G4Tubs("NPTUBE",195./2*CLHEP::mm,200*CLHEP::mm/2,280./2*CLHEP::cm,0*CLHEP::deg,360*CLHEP::deg);
  //G4LogicalVolume* nptubeLogic=new G4LogicalVolume(nptube,G4NistManager::Instance()->FindOrBuildMaterial("G4_POLYVINYL_CHLORIDE"),"NPTUBE");
  //G4VPhysicalVolume* nptubePhysi=new G4PVPlacement(0,G4ThreeVector(Xoff,Yoff-0.*CLHEP::mm,-9.4*CLHEP::cm),nptubeLogic,"NPTUBE",fWorldLogic,false,997);

//}