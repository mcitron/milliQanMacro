#define t_cxx
#include "milliTree.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void milliTree::Loop()
{
//   In a ROOT session, you can do:
//      root> .L t.C
//      root> t t
//      root> t.GetEntry(12); // Fill t data members with entry number 12
//      root> t.Show();       // Show values of entry 12
//      root> t.Show(16);     // Read and show values of entry 16
//      root> t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   TH1D * heightHist = new TH1D("height","height",100,0,100);
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
      for (uint ip = 0; ip < height->size(); ip++){ 
	if (chan->at(ip) == 16){
	    heightHist->Fill(height->at(ip));
	}
      }
   }
   TCanvas oC;
   heightHist->Draw();
   oC.SaveAs("height.pdf");
}
int runMilliTree(){
    TString iFile = "inputs/MilliQan_Run507_default_v28.root";
    TFile * inputFile = TFile::Open(iFile,"READ");
    TTree * tree = (TTree *) inputFile->Get("t");
    milliTree t = milliTree(tree);
    t.Loop();
    // delete inputFile;
    // delete outputFile;
    return 0;
}
// int runMilliTree(int argc, char *argv[]){
//     return main(argc,argv);
// }
