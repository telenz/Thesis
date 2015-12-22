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
#include "/nfs/dust/cms/user/tlenz/JER_checkoutVersion/JERgammajet/CODE/myDeclarations.h"
#include "../plotStyleThesis.h"

TH1D* GetTH1D(TString filename, TString objectName);
TH2D* GetTH2D(TString filename, TString objectName);



int plotPhotonPtReweighting(){

  TeresaPlottingStyle::init();
  gStyle->SetMarkerSize(0.1);
  gStyle->SetMarkerStyle(1);
  gStyle -> SetOptLogy();
  gStyle -> SetHistLineWidth(width);
  TGaxis::SetMaxDigits(5);
  gStyle->SetNdivisions(506,"Y");

  TString pathToFile = "/nfs/dust/cms/user/tlenz/JER_checkoutVersion/JERgammajet/plots_2012/PF_L1CHS/mc/root_files/";

  TFile *file;  
  TH1D *histo, *histoReweighted;
  TCanvas* canv = new TCanvas();
  canv->cd();  

  TString filename = "hPhoton1PtwoWeights_PFCHS_mc.root";
  histo = GetTH1D(pathToFile + filename, "histo");
  filename = "hPhoton1Pt_PFCHS_mc.root";
  histoReweighted = GetTH1D(pathToFile + filename, "histo");


  int rebin = 60;
  histo           -> Rebin(rebin);
  histoReweighted -> Rebin(rebin);

  Color_t color = kBlue+1;
  histo           -> SetLineColor(color);
  histo           -> SetMarkerColor(color);
  color = kRed;// kTeal+10;
  histoReweighted -> SetLineColor(color);
  histoReweighted -> SetMarkerColor(color);

  histo -> GetXaxis() -> SetRangeUser(0,2000);
  histo -> SetMinimum(0.0001);
  histo -> SetMaximum(100000000);
  histo -> SetYTitle("frequency");
  histo -> SetXTitle("p_{T}^{#gamma} [GeV]");
  histo -> SetTitle("");

  

  histo->Draw();
  histoReweighted->Draw("same");

  TLegend* leg = new TLegend(0.50, 0.75, 0.90, 0.92);
  leg->SetTextSize(0.05);
  leg->AddEntry(histo, "not reweighted" , "lep");
  leg->AddEntry(histoReweighted, "reweighted", "lep");
  leg->Draw();
 

  //canv = DrawComparison(histo, histoReweighted,"photon Pt","","Photon pt", 0);
  canv->SetLogy();

  TLatex* info = new TLatex();
  info-> SetNDC();
  info->SetTextSize(0.05);
  info -> DrawLatex(0.7, 0.95, "Simulation");


  canv ->Print("output/PhotonPtComparison_reweighted.pdf");
  

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
