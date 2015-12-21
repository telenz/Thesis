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



int makeValidationPlots_Ratio(){

  TeresaPlottingStyle::init();
  gStyle -> SetHistLineWidth(2);
  TGaxis::SetMaxDigits(5);
  gStyle->SetNdivisions(506,"Y");

  TString pathToFile = "/nfs/dust/cms/user/tlenz/JER_checkoutVersion/JERgammajet/plots_2012/PF_L1CHS/mc/root_files/";

   double eta_bins[5] = {0., 0.5, 1.1, 1.7, 2.3};
   
   TH1F *Res_INPUT = new TH1F("INPUT","", 4, eta_bins);
   TH1F *Res_Gaus  = new TH1F("MCsmeared_MC_ratio_Gaus", "", 4, eta_bins);
   TH1F *Res_RMS99 = new TH1F("MCsmeared_MC_ratio_RMS99", "", 4, eta_bins);
   TH1F *Res_RMS95 = new TH1F("MCsmeared_MC_ratio_RMS95", "", 4, eta_bins);

   // Input Parameters
   Res_INPUT->SetBinContent(1, 1.1);
   Res_INPUT->SetBinContent(2, 1.1);
   Res_INPUT->SetBinContent(3, 1.1);
   Res_INPUT->SetBinContent(4, 1.1);

   Res_INPUT->SetBinError(1, 0);
   Res_INPUT->SetBinError(2, 0);
   Res_INPUT->SetBinError(3, 0);
   Res_INPUT->SetBinError(4, 0);
   
   // 2sigma Gauss CHS
   Res_Gaus->SetBinContent(1, 1.089);
   Res_Gaus->SetBinContent(2, 1.089);
   Res_Gaus->SetBinContent(3, 1.092);
   Res_Gaus->SetBinContent(4, 1.100);
   
   Res_Gaus->SetBinError(1, 0.007);
   Res_Gaus->SetBinError(2, 0.007);
   Res_Gaus->SetBinError(3, 0.010);
   Res_Gaus->SetBinError(4, 0.024);

   // RMS 99
   Res_RMS99->SetBinContent(1, 1.096);
   Res_RMS99->SetBinContent(2, 1.096);
   Res_RMS99->SetBinContent(3, 1.096);
   Res_RMS99->SetBinContent(4, 1.090);
   
   Res_RMS99->SetBinError(1, 0.004);
   Res_RMS99->SetBinError(2, 0.004);
   Res_RMS99->SetBinError(3, 0.006);
   Res_RMS99->SetBinError(4, 0.013);

   // RMS 95   
   Res_RMS95->SetBinContent(1, 1.095);
   Res_RMS95->SetBinContent(2, 1.095);
   Res_RMS95->SetBinContent(3, 1.093);
   Res_RMS95->SetBinContent(4, 1.091);
   
   Res_RMS95->SetBinError(1, 0.004);
   Res_RMS95->SetBinError(2, 0.004);
   Res_RMS95->SetBinError(3, 0.006);
   Res_RMS95->SetBinError(4, 0.014);
   

   ///////////////////////////////////////////////////////////////
  
   TCanvas *c = new TCanvas();

   TF1* line = new TF1("line","1.1",0,2.3);
   line -> GetYaxis()->SetRangeUser(1.0, 1.3);
   line -> GetYaxis()->SetTitle("#rho_{res} = #sigma_{MC}^{smeared}/ #sigma_{MC}^{non-smeared}");
   line -> GetXaxis()->SetTitle("|#eta^{1st jet}|");
   line -> SetLineColor(kBlack);
   line -> SetLineStyle(7);
   line -> SetLineWidth(3);
   line->Draw("");


   Res_INPUT->SetXTitle("|#eta^{1st jet}|");
   Res_INPUT->GetXaxis()->SetRangeUser(0., 5.);
   Res_INPUT->SetYTitle("MC_{smeared}/MC");
   //   Res_INPUT->GetYaxis()->SetRangeUser(1.04, 1.14);
   Res_INPUT->GetYaxis()->SetRangeUser(0.8, 1.6);
   Res_INPUT->SetMarkerStyle(20);
   Res_INPUT->SetLineColor(kBlack);
   Res_INPUT->SetMarkerColor(kBlack);
   //Res_INPUT->Draw("e1p");

   
   //Res_INPUT->Draw("e1psame");

   Res_RMS99->SetMarkerStyle(21);
   Res_RMS99->SetLineColor(kPink-8);
   Res_RMS99->SetMarkerColor(kPink-8);
   Res_RMS99->GetYaxis()->SetRangeUser(1.0, 1.3);
   Res_RMS99->Draw("e1p same");

   Res_RMS95->SetMarkerStyle(24);
   Res_RMS95->SetLineColor(kGreen+2);
   Res_RMS95->SetMarkerColor(kGreen+2);
   //Res_RMS95->Draw("e1psame");
   //Res_RMS95->Draw("e1psame");

   Res_Gaus->SetMarkerStyle(23);
   Res_Gaus->SetLineColor(kBlue-4);
   Res_Gaus->SetMarkerColor(kBlue-4);
   //Res_Gaus->Draw("e1psame");

   //cmsPrel();

   TLegend *leg = new TLegend(0.20, 0.70, 0.60, 0.90);
   leg->SetTextSize(0.05);
   leg->AddEntry(line,"Input: #rho^{input}_{res}=1.1", "l");
   //leg->AddEntry(Res_Gaus, "Gaus fit 2 #sigma interval", "pfl");
   leg->AddEntry(Res_RMS99,"Measured ratio: #rho^{measured}_{res}", "pfle");
   //leg->AddEntry(Res_RMS95,"St. dev. 95%", "pfl");


   leg->Draw("same");

   TLatex* info   = new TLatex();
   info -> SetNDC();
   info->SetTextSize(0.05);
   info -> DrawLatex(0.7, 0.95, "Simulation");

   c->Print("output/MCClosureRatio.pdf");   
   //c->Print("MCClosure.pdf");   
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
