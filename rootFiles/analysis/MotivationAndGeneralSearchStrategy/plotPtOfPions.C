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
#include "TText.h"
#include "../../plotStyleThesis.h"

TH1D* GetTH1D(TString filename, TString objectName);
TH2D* GetTH2D(TString filename, TString objectName);



int plotPtOfPions(){

  TeresaPlottingStyle::init();

  TH1D *histo;
  TCanvas* c =  new TCanvas();
   
  histo = GetTH1D("analyzerGenSim_histograms_200.root","ptOfPions");
  histo->Sumw2();
  histo->SetTitle("");
  histo->GetXaxis()->SetTitle("p_{T} [GeV]");
  histo->GetYaxis()->SetTitle("a.u.");

  histo->GetXaxis()->SetRangeUser(0,1);

  histo->Scale(1./histo->Integral());


  c = new TCanvas();
  c ->cd();

  histo ->Draw("E");


  TLatex* info = new TLatex();
  info-> SetNDC();
  c->cd();
  TString AuxString = "m_{#chi^{#pm}} = 200 GeV";
  info->DrawLatex(0.4,0.7,AuxString);
  AuxString = "#Delta m(#chi^{#pm}, #chi^{0}) #approx 150 MeV";
  info->DrawLatex(0.4,0.6,AuxString);

  TText *text = new TText(.62,.96,"Simulation");
  text -> SetNDC();
  text -> SetTextSize(0.040);
  text -> Draw("same");



  c->SaveAs("output/PtOfPions.pdf");

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
