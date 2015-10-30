#include "P1RunAction.hh"
#include "G4Run.hh"
#include "G4RunManager.hh"
#include "G4UnitsTable.hh"
#include "P1SteppingAction.hh"

P1RunAction::P1RunAction(P1Histo* histo)
: G4UserRunAction(), fHisto(histo)
{}

P1RunAction::~P1RunAction()
{}

void P1RunAction::BeginOfRunAction(const G4Run* aRun){
	G4cout << "BEGIN RUN \n\n\n\n";
	nAeroAnnihil = 0;
	nScintAnnihil = 0;
	nLeaveAero = 0;
	nEnterAero = 0;
	
	fHisto->book();

}

void P1RunAction::EndOfRunAction(const G4Run* aRun){
	//----------------output the percentage of e+ incident on the aerogel that were stopped-----------
	G4cout << "Number of e+ annihilated in Aerogel: " << nAeroAnnihil << G4endl;
	G4cout << "Number of e+ annihilated in Scintilator: " << nScintAnnihil << G4endl;
	G4cout << "Number of e+ that left Aerogel: " << nLeaveAero << G4endl;	
	G4cout << "Number of e+ that entered Aerogel: " << nEnterAero << G4endl;
	G4cout << "The percentage of e+ stopped incident on aerogel is: " << 100* nAeroAnnihil/(nEnterAero) 
	<< "%" << G4endl; 
	G4cout << "The percentage of e+ that left/backscatterd from the aerogel is: " << 100* nLeaveAero/(nEnterAero)
	<< "%" << G4endl;

	fHisto->save();
}


