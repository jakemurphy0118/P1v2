#include "P1TrackingAction.hh"
#include "G4Track.hh"
#include "G4SystemOfUnits.hh"

P1TrackingAction::P1TrackingAction(){
}

P1TrackingAction::~P1TrackingAction(){
}

void P1TrackingAction::PreUserTrackingAction(const G4Track* aTrack){

	
	//if(aTrack->GetParticleDefinition()->GetParticleName() == "e+"){
	//	G4cout << "New track #" << aTrack->GetTrackID() << " of " 
	//	<< aTrack->GetParticleDefinition()->GetParticleName()
	//	<< " Ekin(MeV)= " << aTrack->GetKineticEnergy()/MeV
	//	<< " parent # " << aTrack->GetParentID()
	//	<< G4endl;

	
	//}
}

void P1TrackingAction::PostUserTrackingAction(const G4Track*){
}

