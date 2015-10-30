#include "P1SteppingAction.hh"
//#include "P1EventAction.hh"
#include "P1DetectorConstruction.hh"
#include "P1RunAction.hh"
#include "G4UserSteppingAction.hh"
#include "G4ThreeVector.hh"

#include "G4Step.hh"
#include "G4StepPoint.hh"
#include "G4SystemOfUnits.hh"
#include "G4VProcess.hh"
P1SteppingAction::P1SteppingAction(P1DetectorConstruction* detector, P1RunAction* RA, P1Histo* histo)
  : G4UserSteppingAction(), fDetector(detector), fRunAction(RA), fHisto(histo)
{}

P1SteppingAction::~P1SteppingAction()
{}

void P1SteppingAction::UserSteppingAction(const G4Step* aStep){
	
	G4StepPoint* point1 = aStep->GetPreStepPoint();
	G4StepPoint* point2 = aStep->GetPostStepPoint();

	G4Track* theTrack = aStep->GetTrack();
	G4ParticleDefinition* particleType = theTrack->GetDefinition();
	G4String particleName = particleType->GetParticleName();
	G4String volumeName = point1->GetPhysicalVolume()->GetLogicalVolume()->GetName();
	G4ThreeVector pos1, pos2;
	G4double pos2x, pos2y, pos2z, pos2zPlus;




//-------------------------------------TRACK POSITRON STEPS--------------------------------
	if(particleName == "e+"){

		if(volumeName == "Scint"){
	
			if(point2->GetProcessDefinedStep()->GetProcessName() == "annihil"){
				
				fRunAction->IncrementScintAnnihil();
				G4cout << "Scint Annihilation" << G4endl;
			}		
		}
		
		if(point1->GetStepStatus() == fGeomBoundary && volumeName == "Aero"){
			
			fRunAction->IncrementEnterAero();
		}
		
		if(volumeName == "Aero"){
			
			if(point2->GetProcessDefinedStep()->GetProcessName() == "annihil"){
				
				fRunAction->IncrementAeroAnnihil();
				G4cout << "Aero Annihilation" << G4endl;
				pos2 = point2->GetPosition();
				pos2x = pos2.x();
				pos2y = pos2.y();
				pos2z = pos2.z();
				
				fHisto->FillNtuple(pos2x/cm, pos2y/cm, pos2z/cm);
				
				if(pos2z < 0.000000){pos2zPlus = -1*pos2z;}
				else {pos2zPlus = pos2z;}
			
				fHisto->FillHisto(pos2x/cm, pos2zPlus/cm, 1);
			}
		
			if(point2->GetStepStatus() == fGeomBoundary){
			
				fRunAction->IncrementLeaveAero();
			}		
		}
	}
}

