#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#include "TChain.h"
#include "TCanvas.h"
#include "TF1.h"
#include "TFile.h"
#include "TGraph.h"
#include "TMath.h"
#include "TLine.h"
#include "TMultiGraph.h"
#include "TStyle.h"
#include "TGraphAsymmErrors.h"
#include "TGraphErrors.h"
#include "TH1.h"
#include "TH2.h"
#include "TObject.h"
#include "THStack.h"
#include "TString.h"
#include "TLegend.h"
#include "TColor.h"
#include "TPaveText.h"
#include "TAttPad.h"
#include "TColorWheel.h"
#include "TLatex.h"
#include "TROOT.h"
#include "../plotStyleThesis.h"

TH1D* GetTH1D(TString filename, TString objectName);
TH2D* GetTH2D(TString filename, TString objectName);



int plotFits(){

  TeresaPlottingStyle::init();
  gStyle->SetOptStat(0);
  gStyle->SetOptStat("");
  TH1D *histo;
  TCanvas* canvas1;
   
  //histo = GetTH1D("AB/352477456.root","proj1");
  histo = GetTH1D("~/PixelCalibration/fits/AB/352476680.root","proj1");
  histo->SetTitle("");
  histo->GetXaxis()->SetTitle("#Delta E/#Delta x [ADC/mm]");
  histo->GetYaxis()->SetTitle("Number of measurements");

  histo->GetXaxis()->SetNdivisions(804);
  histo->GetYaxis()->SetNdivisions(1005);

  histo->GetXaxis()->SetRangeUser(0,1400);
  histo->GetXaxis()->SetNoExponent(kTRUE);

  
  /*
  histo->GetXaxis()->SetTitleSize(0.07);

  */


  canvas1 = new TCanvas();
  canvas1 ->cd();

  histo ->Draw("E");


  canvas1->SaveAs("output/Landau_Module_352476680.pdf");

  return 0;
		 
}




//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Some Functions


TH1D* GetTH1D(TString filename, TString objectName){

  TH1D* object = 0;

  TFile* file =  TFile::Open(filename);
  if(file != 0) file -> GetObject(objectName,object);
  object -> SetDirectory(0);
  delete file;

  return object;
}

TH2D* GetTH2D(TString filename, TString objectName){

  TH2D* object = 0;

  TFile* file =  TFile::Open(filename);
  if(file != 0) file -> GetObject(objectName,object);
  object -> SetDirectory(0);
  delete file;

  return object;
}


//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
