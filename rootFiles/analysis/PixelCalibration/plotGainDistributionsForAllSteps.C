#include <iostream>
#include  <cstdio>
#include "TFile.h"
#include "TString.h"
#include "TROOT.h"
#include "TTree.h"
#include "TChain.h"
#include "TBranch.h"
#include "TH1D.h"
#include "TCanvas.h"
#include "../../plotStyleThesis.h"


//const Int_t nOfPixelModules = 16588;
//const Int_t nOfPixelModules = 15148;
const Int_t nOfPixelModules = 1440;
const Int_t nOfModules      = 16588;

typedef struct { 

  unsigned int nEntries;
  unsigned int firstRun;
  unsigned int lastRun;
  unsigned int Index[nOfModules];
  UInt_t       DetId[nOfModules];
  UChar_t      SubDet[nOfModules];
  UChar_t      APVId[nOfModules];
  Double_t     Gain[nOfModules]; 
  Double_t     GainWoGlobalScaling[nOfModules];
  Double_t     FitWidth[nOfModules]; 
  
} CalibrationStep_t;


int plotGainDistributionsForAllSteps()
{

  gStyle->SetOptStat(1110);
  gStyle -> SetPadBottomMargin(0.15);

  TeresaPlottingStyle::init();

  TString Cstep[5];
  Cstep[0]="AB";
  Cstep[1]="C1";
  Cstep[2]="C2";
  Cstep[3]="D1";
  Cstep[4]="D2";

  TH1D* calibFactors;


  for(int i=0; i<5; i++){


    calibFactors = new TH1D("calibFactors"+Cstep[i],"Calibration Factors " + Cstep[i],100,0.5,1.50);

    // Read input tree
    TChain* chain = new TChain("PixelGain");
    chain->Add("~/PixelCalibration/PixelGain_" + Cstep[i] + ".root");

    UInt_t   detid[nOfPixelModules];
    UChar_t  subdet[nOfPixelModules];
    Double_t gain[nOfPixelModules];
    Double_t width[nOfPixelModules];

    chain->SetBranchAddress("DetId",detid);
    chain->SetBranchAddress("SubDet",subdet);
    chain->SetBranchAddress("Gain",gain);
    chain->SetBranchAddress("FitWidth",width);

   
    
 
    int nMax = chain->GetEntries();

    int idx=0;
    for(int n=0; n<nMax; n++)
      {
	chain->GetEntry(n);

	for(int j=0; j<1440; j++){
	  
	  calibFactors->Fill(1./gain[j]);
	}
	
      }



    //##################################################################################
    TCanvas *c = new TCanvas("c","c",0,0,500,500);
    calibFactors->GetXaxis()->SetTitle("calibration factors");
    calibFactors->GetYaxis()->SetTitle("Number of modules");
    calibFactors -> Draw("hist");
    calibFactors->SetTitle("");
    c->Update();
  
    c->SaveAs("PixelGain_"+Cstep[i]+"_NEW.pdf");


  
  }
 
  
  return 0;


}
