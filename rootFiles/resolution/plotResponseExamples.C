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
#include "myColors.h"

TH1D* GetTH1D(TString filename, TString objectName);
TH2D* GetTH2D(TString filename, TString objectName);



int plotResponseExamples(){

  TeresaPlottingStyle::init();
  gStyle->SetMarkerSize(0.1);
  gStyle->SetMarkerStyle(1);
  //  gStyle -> SetOptTitle(1);
  gStyle -> SetOptLogy();
  gStyle -> SetHistLineWidth(width);


  TString pathToFile = "/nfs/dust/cms/user/tlenz/JER_checkoutVersion/JERgammajet/plots_2012/PF_L1CHS/mc/root_files/";

  TH1D *histoPhoton1, *histoJet1, *histoPhoton2 , *histoJet2, *histoJet3, *histoTogether1, *histoTogether2;   
  TCanvas* canvas1, *canvas2, *canvas3, *canvas4, *canvas5;
  TString fileName;
  TLatex*  info;
      
  
  const int etaB   = 1;
  const int alphaB = 6;
  const int ptB    = 12;

  double min = 0.0001;
  double max = 9.;

  int rebin = 40;
  
  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  // Full Resolution
  canvas1 = new TCanvas();
  canvas1 ->cd();
  fileName       = Form("response_photon_in_%i_Pt_bin_%i_eta_bin_%i_alpha_bin_PFCHS_mc.root",ptB,etaB,alphaB);
  histoPhoton1   = GetTH1D(pathToFile + fileName,"histo");
  fileName       = Form("response_jet_in_%i_Pt_bin_%i_eta_bin_%i_alpha_bin_PFCHS_mc.root",ptB,etaB,alphaB);
  histoJet1      = GetTH1D(pathToFile + fileName,"histo");
  fileName       = Form("response_jet_in_%i_Pt_bin_%i_eta_bin_%i_alpha_bin_PFCHS_mc.root",ptB,etaB,alphaB);
  histoTogether1 = GetTH1D(pathToFile + fileName,"histo");
  histoTogether1 -> Add(histoPhoton1);
  histoTogether1 -> Scale(1./histoTogether1->Integral());
  histoTogether1 -> Rebin(rebin);
  histoTogether1 -> GetXaxis() -> SetRangeUser(0.,2.);

  histoTogether1 -> GetXaxis()->SetTitle("p_{T}^{reco. jet}/p_{T}^{#gamma}");
  histoTogether1 -> GetYaxis()->SetTitle("a.u.");
  histoTogether1 -> SetMinimum(min);
  histoTogether1 -> SetMaximum(max);

  histoTogether1 -> SetMarkerColor(c_measured);
  histoTogether1 -> SetLineColor(c_measured);


  histoTogether1 -> Draw(); 


  // Draw info boxes
  info   = new TLatex();
  info -> SetNDC();
  info ->SetTextSize(0.05);
  info -> DrawLatex(0.7, 0.95, "Simulation");
  info -> DrawLatex(0.2, 0.87, "Measured Response");
  info ->SetTextSize(0.04);
  if(ptB<12) info->DrawLatex(0.49,0.74, Form("%4.0f GeV < p_{T}^{#gamma} < %4.0f GeV",ptBins[ptB-1],ptBins[ptB]));
  else       info->DrawLatex(0.61,0.74, Form("p_{T}^{#gamma} > %4.0f GeV",ptBins[ptB-1]));
  info->DrawLatex(0.60,0.80, Form("%4.1f < |#eta^{1st jet}| < %4.1f",etaBins[etaB-1],etaBins[etaB]));
  info->DrawLatex(0.20,0.80, Form("%4.3f < #alpha < %4.3f",alphaBins[alphaB-1]/100.,alphaBins[alphaB]/100.));
  
  canvas1->SaveAs(Form("output/fullResponse_%i_alpha_bin.pdf",alphaB));
  //-------------------------------------------------------------------------------------------------------------------------
  //-------------------------------------------------------------------------------------------------------------------------

  histoTogether1 -> SetMarkerColor(kBlack);
  histoTogether1 -> SetLineColor(kBlack);
  histoTogether1 -> Draw(); 
  
  double scaleFactor = histoJet1->Integral() + histoPhoton1->Integral(); 

  histoJet1 -> Scale(1./scaleFactor);
  histoJet1 -> Rebin(rebin);
  histoJet1 -> GetXaxis() -> SetRangeUser(0.,2.);
  Color_t color = kRed;
  histoJet1 -> SetMarkerColor(color);
  histoJet1 -> SetLineColor(color);
  histoJet1 -> Draw("same");

  histoPhoton1 -> Scale(1./scaleFactor);
  histoPhoton1 -> Rebin(rebin);
  color = kBlue+1;
  histoPhoton1 -> SetMarkerColor(color);
  histoPhoton1 -> SetLineColor(color);

  histoPhoton1 -> Draw("same");


  // Draw info boxes
  //info   = new TLatex();
  //info -> SetNDC();
  //if(ptB<12) info->DrawLatex(0.62,0.85, Form("%4.0f GeV< p_{T}^{#gamma} < %4.0f GeV",ptBins[ptB-1],ptBins[ptB]));
  //else       info->DrawLatex(0.62,0.85, Form("%4.0f GeV< p_{T}^{#gamma} ",ptBins[ptB-1]));
  //info->DrawLatex(0.62,0.80, Form(" %4.1f < |#eta^{1st jet}| < %4.1f",etaBins[etaB-1],etaBins[etaB]));
  //info->DrawLatex(0.18,0.85, Form("%4.3f < #alpha < %4.3f",alphaBins[alphaB-1]/100.,alphaBins[alphaB]/100.));


  TLegend *legend1 = new TLegend(0.20,0.75,0.8,0.9);
  legend1 -> SetTextSize(0.045);
  legend1 -> AddEntry(histoJet1   , "2^{nd} jet in leading jet hemisphere");
  legend1 -> AddEntry(histoPhoton1, "2^{nd} jet in photon hemisphere");
  legend1 -> Draw();
  info ->SetTextSize(0.05);
  info -> DrawLatex(0.7, 0.95, "Simulation");
  canvas1->SaveAs(Form("output/fullResponseAndContributions_%i_alpha_bin.pdf",alphaB));

  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  // Imbalance

  canvas2 = new TCanvas();
  canvas2 ->cd();
  
  fileName = Form("response_imbalance_photon_in_%i_Pt_bin_%i_eta_bin_%i_alpha_bin_PFCHS_mc.root",ptB,etaB,alphaB);
  histoPhoton2 = GetTH1D(pathToFile + fileName,"histo");
  fileName = Form("response_imbalance_jet_in_%i_Pt_bin_%i_eta_bin_%i_alpha_bin_PFCHS_mc.root",ptB,etaB,alphaB);
  histoJet2 = GetTH1D(pathToFile + fileName,"histo");
  fileName = Form("response_imbalance_jet_in_%i_Pt_bin_%i_eta_bin_%i_alpha_bin_PFCHS_mc.root",ptB,etaB,alphaB);
  histoTogether2 = GetTH1D(pathToFile + fileName,"histo");

  histoTogether2 -> Add(histoPhoton2);
  histoTogether2 -> Scale(1./histoTogether2->Integral());
  histoTogether2 -> Rebin(rebin);
  histoTogether2 -> GetXaxis() -> SetRangeUser(0.,2.);

  histoTogether2 -> GetXaxis()->SetTitle("p_{T}^{gen. jet}/p_{T}^{#gamma}");
  histoTogether2 -> GetYaxis()->SetTitle("a.u.");
  histoTogether2 -> SetMinimum(min);
  histoTogether2 -> SetMaximum(max);

  histoTogether2 -> SetMarkerColor(c_imbalance);
  histoTogether2 -> SetLineColor(c_imbalance);  
  histoTogether2 -> Draw(); 


  // Draw info boxes
  info   = new TLatex();
  info -> SetNDC();
  info ->SetTextSize(0.05);
  info -> DrawLatex(0.2, 0.87, "Imbalance Response");
  info -> DrawLatex(0.7, 0.95, "Simulation");
  info ->SetTextSize(0.04);
  if(ptB<12) info->DrawLatex(0.49,0.74, Form("%4.0f GeV < p_{T}^{#gamma} < %4.0f GeV",ptBins[ptB-1],ptBins[ptB]));
  else       info->DrawLatex(0.61,0.74, Form("p_{T}^{#gamma} > %4.0f GeV",ptBins[ptB-1]));
  info->DrawLatex(0.60,0.80, Form("%4.1f < |#eta^{1st jet}| < %4.1f",etaBins[etaB-1],etaBins[etaB]));
  info->DrawLatex(0.20,0.80, Form("%4.3f < #alpha < %4.3f",alphaBins[alphaB-1]/100.,alphaBins[alphaB]/100.));
  

  canvas2->SaveAs(Form("output/imbalanceResponse_%i_alpha_bin.pdf",alphaB));
  //-------------------------------------------------------------------------------------------------------------------------
  /*
  canvas5 = new TCanvas("canvas5","canvas",500,600,500,500);
  canvas5 ->cd();

  histoTogether2 -> Draw(); 
  
  scaleFactor = histoJet2->Integral() + histoPhoton2->Integral(); 

  histoJet2 -> Scale(histoTogether2->GetEntries()/scaleFactor);

  histoJet2 -> Rebin(rebin);
  histoJet2 -> GetXaxis() -> SetRangeUser(0.,2.);
  histoJet2 -> SetMarkerColor(8);
  histoJet2 -> SetLineColor(8);
  histoJet2 -> Draw("same");

  histoPhoton2 -> Scale(histoTogether2->GetEntries()/scaleFactor);
  histoPhoton2 -> Rebin(rebin);
  histoPhoton2 -> GetXaxis() -> SetRangeUser(0.,2.);
  histoPhoton2 -> SetMarkerColor(2);
  histoPhoton2 -> SetLineColor(2);
  histoPhoton2 -> Draw("same");


  // Draw info boxes
  info   = new TLatex();
  info -> SetNDC();
  
  //if(ptB<12) info->DrawLatex(0.62,0.85, Form("%4.0f GeV< p_{T}^{#gamma} < %4.0f GeV",ptBins[ptB-1],ptBins[ptB]));
  //else       info->DrawLatex(0.62,0.85, Form("%4.0f GeV< p_{T}^{#gamma} ",ptBins[ptB-1]));
  //info->DrawLatex(0.62,0.80, Form(" %4.1f < |#eta^{1st jet}| < %4.1f",etaBins[etaB-1],etaBins[etaB]));
  //info->DrawLatex(0.18,0.85, Form("%4.3f < #alpha < %4.3f",alphaBins[alphaB-1]/100.,alphaBins[alphaB]/100.));

  TLegend *legend2 = new TLegend(0.25,0.75,0.9,0.9);
  legend2 -> SetTextSize(0.033);
  legend2 -> SetFillColor(0);
  legend2 -> SetLineWidth(2);
  legend2 -> AddEntry(histoJet2, "2nd jet in leading jet hemisphere");
  legend2 -> AddEntry(histoPhoton2, "2nd jet in photon hemisphere");
  legend2 -> Draw("same");
  
  canvas5->SaveAs("output/imbalanceAndContributionsExample.pdf");
  */
  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  // Inrinsic
  canvas3 = new TCanvas();
  canvas3 ->cd();
  
  fileName = Form("response_intrinsic_in_%i_Pt_bin_%i_eta_bin_%i_alpha_bin_PFCHS_mc.root",ptB,etaB,alphaB);
  histoJet3 = GetTH1D(pathToFile + fileName,"histo");

  histoJet3 ->Scale(1./histoJet3->Integral());
  histoJet3 -> Rebin(rebin);
  histoJet3 -> GetXaxis() -> SetRangeUser(0.,2.);

  histoJet3 -> GetXaxis()->SetTitle("p_{T}^{reco. jet}/p_{T}^{gen. jet}");
  histoJet3 -> GetYaxis()->SetTitle("a.u.");
  histoJet3 -> SetMinimum(min);
  histoJet3 -> SetMaximum(max);

  histoJet3 -> SetMarkerColor(c_intrinsic);
  histoJet3 -> SetLineColor(c_intrinsic);
  
  histoJet3 -> Draw(); 


  // Draw info boxes
  info   = new TLatex();
  info -> SetNDC();
  info ->SetTextSize(0.05);
  info -> DrawLatex(0.2, 0.87, "Intrinsic Response");
  info -> DrawLatex(0.7, 0.95, "Simulation");
  info ->SetTextSize(0.04);
  if(ptB<12) info->DrawLatex(0.49,0.74, Form("%4.0f GeV < p_{T}^{#gamma} < %4.0f GeV",ptBins[ptB-1],ptBins[ptB]));
  else       info->DrawLatex(0.61,0.74, Form("p_{T}^{#gamma} > %4.0f GeV",ptBins[ptB-1]));
  info->DrawLatex(0.60,0.80, Form("%4.1f < |#eta^{1st jet}| < %4.1f",etaBins[etaB-1],etaBins[etaB]));
  info->DrawLatex(0.20,0.80, Form("%4.3f < #alpha < %4.3f",alphaBins[alphaB-1]/100.,alphaBins[alphaB]/100.));

  canvas3->SaveAs(Form("output/intrinsicResponse_%i_alpha_bin.pdf",alphaB));
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
