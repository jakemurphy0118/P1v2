#ifndef P1RunAction_h
#define P1RunAction_h 1

#include "G4UserRunAction.hh"
#include "globals.hh"
#include "G4ThreeVector.hh"
#include "P1Histo.hh"

class G4Run;
class P1Histo;

class P1RunAction : public G4UserRunAction{

public: 
	P1RunAction(P1Histo*);
	virtual ~P1RunAction();

	virtual void BeginOfRunAction(const G4Run*);
	virtual void EndOfRunAction(const G4Run*);

	void IncrementAeroAnnihil(){ nAeroAnnihil++;}
	void IncrementScintAnnihil(){ nScintAnnihil++;}
	void IncrementLeaveAero(){ nLeaveAero++;}
	void IncrementEnterAero(){ nEnterAero++;}


private:
	P1Histo* fHisto;
	G4int nAeroAnnihil;
	G4int nScintAnnihil;
	G4int nLeaveAero;
	G4int nEnterAero;


	
};
#endif
