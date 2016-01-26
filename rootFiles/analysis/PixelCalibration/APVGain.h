//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Apr  8 14:34:30 2014 by ROOT version 5.32/00
// from TTree APVGain/APVGain
// found on file: Gains_Tree_08_04_LARGE.root
//////////////////////////////////////////////////////////

#ifndef APVGain_h
#define APVGain_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <iostream>
#include "../../plotStyleThesis.h"

// Header file for the classes stored in the TTree if any.

// Fixed size dimensions of array or collections stored in the TTree if any.

const TString step = "AB_CL0";
const bool saveOutput = true;

class APVGain {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   UInt_t          Index;
   UInt_t          Bin;
   UInt_t          DetId;
   UChar_t         APVId;
   UChar_t         SubDet;
   Float_t         x;
   Float_t         y;
   Float_t         z;
   Float_t         Eta;
   Float_t         R;
   Float_t         Phi;
   Float_t         Thickness;
   Float_t         FitMPV;
   Float_t         FitMPVErr;
   Float_t         FitWidth;
   Float_t         FitWidthErr;
   Float_t         FitChi2NDF;
   Double_t        Gain;
   Double_t        PrevGain;
   Double_t        NEntries;
   Bool_t          isMasked;

   // List of branches
   TBranch        *b_Index;   //!
   TBranch        *b_Bin;   //!
   TBranch        *b_DetId;   //!
   TBranch        *b_APVId;   //!
   TBranch        *b_SubDet;   //!
   TBranch        *b_x;   //!
   TBranch        *b_y;   //!
   TBranch        *b_z;   //!
   TBranch        *b_Eta;   //!
   TBranch        *b_R;   //!
   TBranch        *b_Phi;   //!
   TBranch        *b_Thickness;   //!
   TBranch        *b_FitMPV;   //!
   TBranch        *b_FitMPVErr;   //!
   TBranch        *b_FitWidth;   //!
   TBranch        *b_FitWidthErr;   //!
   TBranch        *b_FitChi2NDF;   //!
   TBranch        *b_Gain;   //!
   TBranch        *b_PrevGain;   //!
   TBranch        *b_NEntries;   //!
   TBranch        *b_isMasked;   //!

   APVGain(TTree *tree=0);
   virtual ~APVGain();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef APVGain_cxx
APVGain::APVGain(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
     cout<<step<<endl;
     //TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("~/PixelCalibration/input/Gains_Tree_" + step + ".root");
     TFile *f = TFile::Open("/afs/desy.de/user/t/tlenz/PixelCalibration/input/Gains_Tree_" + step + ".root");
      if (!f || !f->IsOpen()) {
         f = new TFile("~/PixelCalibration/input/Gains_Tree_" + step + ".root");
      }
      //TDirectory * dir = (TDirectory*)f->Get("~/PixelCalibration/input/Gains_Tree_" + step + ".root:/alcaSiStripGainsHarvester");
      f->GetObject("alcaSiStripGainsHarvester/APVGain",tree);

   }
   Init(tree);
}

APVGain::~APVGain()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t APVGain::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t APVGain::LoadTree(Long64_t entry)
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

void APVGain::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("Index", &Index, &b_Index);
   fChain->SetBranchAddress("Bin", &Bin, &b_Bin);
   fChain->SetBranchAddress("DetId", &DetId, &b_DetId);
   fChain->SetBranchAddress("APVId", &APVId, &b_APVId);
   fChain->SetBranchAddress("SubDet", &SubDet, &b_SubDet);
   fChain->SetBranchAddress("x", &x, &b_x);
   fChain->SetBranchAddress("y", &y, &b_y);
   fChain->SetBranchAddress("z", &z, &b_z);
   fChain->SetBranchAddress("Eta", &Eta, &b_Eta);
   fChain->SetBranchAddress("R", &R, &b_R);
   fChain->SetBranchAddress("Phi", &Phi, &b_Phi);
   fChain->SetBranchAddress("Thickness", &Thickness, &b_Thickness);
   fChain->SetBranchAddress("FitMPV", &FitMPV, &b_FitMPV);
   fChain->SetBranchAddress("FitMPVErr", &FitMPVErr, &b_FitMPVErr);
   fChain->SetBranchAddress("FitWidth", &FitWidth, &b_FitWidth);
   fChain->SetBranchAddress("FitWidthErr", &FitWidthErr, &b_FitWidthErr);
   fChain->SetBranchAddress("FitChi2NDF", &FitChi2NDF, &b_FitChi2NDF);
   fChain->SetBranchAddress("Gain", &Gain, &b_Gain);
   fChain->SetBranchAddress("PrevGain", &PrevGain, &b_PrevGain);
   fChain->SetBranchAddress("NEntries", &NEntries, &b_NEntries);
   fChain->SetBranchAddress("isMasked", &isMasked, &b_isMasked);
   Notify();
}

Bool_t APVGain::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void APVGain::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t APVGain::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef APVGain_cxx
