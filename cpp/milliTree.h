//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Jan 12 11:16:29 2023 by ROOT version 6.18/00
// from TTree t/t
// found on file: MilliQan_Run544_default_v25.root
//////////////////////////////////////////////////////////

#ifndef t_h
#define t_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "vector"
#include "vector"
#include "vector"
#include "vector"
#include "TH1D.h"
#include <iostream>
using namespace std;

class milliTree {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Int_t           event;
   Long64_t        runNumber;
   Long64_t        fileNumber;
   vector<float>   *triggerThreshold;
   vector<bool>    *triggerEnable;
   vector<int>     *triggerMajority;
   vector<int>     *triggerLogic;
   vector<float>   *sidebandMean;
   vector<float>   *sidebandRMS;
   vector<float>   *maxThreeConsec;
   vector<int>     *chan;
   vector<int>     *chanWithinBoard;
   vector<int>     *row;
   vector<int>     *column;
   vector<int>     *layer;
   vector<int>     *type;
   vector<int>     *board;
   vector<float>   *height;
   vector<float>   *area;
   vector<float>   *nPE;
   vector<int>     *ipulse;
   vector<int>     *npulses;
   vector<float>   *time;
   vector<float>   *duration;
   vector<float>   *delay;
   vector<float>   *max;
   vector<Long64_t> *present;
   vector<Long64_t> *event_trigger_time_tag;
   vector<Long64_t> *event_time;
   Double_t        event_time_fromTDC;
   vector<Long64_t> *v_groupTDC_g0;
   vector<Long64_t> *v_groupTDC_g1;
   vector<Long64_t> *v_groupTDC_g2;
   vector<Long64_t> *v_groupTDC_g3;
   vector<Long64_t> *v_groupTDC_g4;
   vector<Long64_t> *v_groupTDC_g5;
   vector<Long64_t> *v_groupTDC_g6;
   vector<Long64_t> *v_groupTDC_g7;
   Float_t         tClockCycles;
   Float_t         tTime;
   Float_t         tStartTime;
   Float_t         tTrigger;
   Float_t         tTimeDiff;
   Float_t         tMatchingTimeCut;
   Int_t           tEvtNum;
   Int_t           tRunNum;

   // List of branches
   TBranch        *b_event;   //!
   TBranch        *b_runNumber;   //!
   TBranch        *b_fileNumber;   //!
   TBranch        *b_triggerThreshold;   //!
   TBranch        *b_triggerEnable;   //!
   TBranch        *b_triggerMajority;   //!
   TBranch        *b_triggerLogic;   //!
   TBranch        *b_sidebandMean;   //!
   TBranch        *b_sidebandRMS;   //!
   TBranch        *b_maxThreeConsec;   //!
   TBranch        *b_chan;   //!
   TBranch        *b_chanWithinBoard;   //!
   TBranch        *b_row;   //!
   TBranch        *b_column;   //!
   TBranch        *b_layer;   //!
   TBranch        *b_type;   //!
   TBranch        *b_board;   //!
   TBranch        *b_height;   //!
   TBranch        *b_area;   //!
   TBranch        *b_nPE;   //!
   TBranch        *b_ipulse;   //!
   TBranch        *b_npulses;   //!
   TBranch        *b_time;   //!
   TBranch        *b_duration;   //!
   TBranch        *b_delay;   //!
   TBranch        *b_max;   //!
   TBranch        *b_present;   //!
   TBranch        *b_event_trigger_time_tag;   //!
   TBranch        *b_event_time;   //!
   TBranch        *b_event_time_fromTDC;   //!
   TBranch        *b_v_groupTDC_g0;   //!
   TBranch        *b_v_groupTDC_g1;   //!
   TBranch        *b_v_groupTDC_g2;   //!
   TBranch        *b_v_groupTDC_g3;   //!
   TBranch        *b_v_groupTDC_g4;   //!
   TBranch        *b_v_groupTDC_g5;   //!
   TBranch        *b_v_groupTDC_g6;   //!
   TBranch        *b_v_groupTDC_g7;   //!
   TBranch        *b_tClockCycles;   //!
   TBranch        *b_tTime;   //!
   TBranch        *b_tStartTime;   //!
   TBranch        *b_tTrigger;   //!
   TBranch        *b_tTimeDiff;   //!
   TBranch        *b_tMatchingTimeCut;   //!
   TBranch        *b_tEvtNum;   //!
   TBranch        *b_tRunNum;   //!

   milliTree(TTree *tree=0);
   virtual ~milliTree();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef t_cxx
milliTree::milliTree(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("MilliQan_Run544_default_v25.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("MilliQan_Run544_default_v25.root");
      }
      f->GetObject("t",tree);

   }
   Init(tree);
}

milliTree::~milliTree()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t milliTree::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t milliTree::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void milliTree::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   triggerThreshold = 0;
   triggerEnable = 0;
   triggerMajority = 0;
   triggerLogic = 0;
   sidebandMean = 0;
   sidebandRMS = 0;
   maxThreeConsec = 0;
   chan = 0;
   chanWithinBoard = 0;
   row = 0;
   column = 0;
   layer = 0;
   type = 0;
   board = 0;
   height = 0;
   area = 0;
   nPE = 0;
   ipulse = 0;
   npulses = 0;
   time = 0;
   duration = 0;
   delay = 0;
   max = 0;
   present = 0;
   event_trigger_time_tag = 0;
   event_time = 0;
   v_groupTDC_g0 = 0;
   v_groupTDC_g1 = 0;
   v_groupTDC_g2 = 0;
   v_groupTDC_g3 = 0;
   v_groupTDC_g4 = 0;
   v_groupTDC_g5 = 0;
   v_groupTDC_g6 = 0;
   v_groupTDC_g7 = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("event", &event, &b_event);
   fChain->SetBranchAddress("runNumber", &runNumber, &b_runNumber);
   fChain->SetBranchAddress("fileNumber", &fileNumber, &b_fileNumber);
   fChain->SetBranchAddress("triggerThreshold", &triggerThreshold, &b_triggerThreshold);
   fChain->SetBranchAddress("triggerEnable", &triggerEnable, &b_triggerEnable);
   fChain->SetBranchAddress("triggerMajority", &triggerMajority, &b_triggerMajority);
   fChain->SetBranchAddress("triggerLogic", &triggerLogic, &b_triggerLogic);
   fChain->SetBranchAddress("sidebandMean", &sidebandMean, &b_sidebandMean);
   fChain->SetBranchAddress("sidebandRMS", &sidebandRMS, &b_sidebandRMS);
   fChain->SetBranchAddress("maxThreeConsec", &maxThreeConsec, &b_maxThreeConsec);
   fChain->SetBranchAddress("chan", &chan, &b_chan);
   fChain->SetBranchAddress("chanWithinBoard", &chanWithinBoard, &b_chanWithinBoard);
   fChain->SetBranchAddress("row", &row, &b_row);
   fChain->SetBranchAddress("column", &column, &b_column);
   fChain->SetBranchAddress("layer", &layer, &b_layer);
   fChain->SetBranchAddress("type", &type, &b_type);
   fChain->SetBranchAddress("board", &board, &b_board);
   fChain->SetBranchAddress("height", &height, &b_height);
   fChain->SetBranchAddress("area", &area, &b_area);
   fChain->SetBranchAddress("nPE", &nPE, &b_nPE);
   fChain->SetBranchAddress("ipulse", &ipulse, &b_ipulse);
   fChain->SetBranchAddress("npulses", &npulses, &b_npulses);
   fChain->SetBranchAddress("time", &time, &b_time);
   fChain->SetBranchAddress("duration", &duration, &b_duration);
   fChain->SetBranchAddress("delay", &delay, &b_delay);
   fChain->SetBranchAddress("max", &max, &b_max);
   fChain->SetBranchAddress("present", &present, &b_present);
   fChain->SetBranchAddress("event_trigger_time_tag", &event_trigger_time_tag, &b_event_trigger_time_tag);
   fChain->SetBranchAddress("event_time", &event_time, &b_event_time);
   fChain->SetBranchAddress("event_time_fromTDC", &event_time_fromTDC, &b_event_time_fromTDC);
   fChain->SetBranchAddress("v_groupTDC_g0", &v_groupTDC_g0, &b_v_groupTDC_g0);
   fChain->SetBranchAddress("v_groupTDC_g1", &v_groupTDC_g1, &b_v_groupTDC_g1);
   fChain->SetBranchAddress("v_groupTDC_g2", &v_groupTDC_g2, &b_v_groupTDC_g2);
   fChain->SetBranchAddress("v_groupTDC_g3", &v_groupTDC_g3, &b_v_groupTDC_g3);
   fChain->SetBranchAddress("v_groupTDC_g4", &v_groupTDC_g4, &b_v_groupTDC_g4);
   fChain->SetBranchAddress("v_groupTDC_g5", &v_groupTDC_g5, &b_v_groupTDC_g5);
   fChain->SetBranchAddress("v_groupTDC_g6", &v_groupTDC_g6, &b_v_groupTDC_g6);
   fChain->SetBranchAddress("v_groupTDC_g7", &v_groupTDC_g7, &b_v_groupTDC_g7);
   fChain->SetBranchAddress("tClockCycles", &tClockCycles, &b_tClockCycles);
   fChain->SetBranchAddress("tTime", &tTime, &b_tTime);
   fChain->SetBranchAddress("tStartTime", &tStartTime, &b_tStartTime);
   fChain->SetBranchAddress("tTrigger", &tTrigger, &b_tTrigger);
   fChain->SetBranchAddress("tTimeDiff", &tTimeDiff, &b_tTimeDiff);
   fChain->SetBranchAddress("tMatchingTimeCut", &tMatchingTimeCut, &b_tMatchingTimeCut);
   fChain->SetBranchAddress("tEvtNum", &tEvtNum, &b_tEvtNum);
   fChain->SetBranchAddress("tRunNum", &tRunNum, &b_tRunNum);
   Notify();
}

Bool_t milliTree::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void milliTree::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t milliTree::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef t_cxx
