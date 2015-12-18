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
TGraphErrors* GetTGraphErrors(TString filename, TString objectName);
TF1* GetTF1(TString filename, TString objectName);


int plotResolutionExamples(){

  TeresaPlottingStyle::init();
  gStyle -> SetHistLineWidth(width);
  gStyle->SetNdivisions(506,"Y");
  gStyle ->SetMarkerSize(1.05);

  TString pathToFileMC   = "/nfs/dust/cms/user/tlenz/JER_checkoutVersion/JERgammajet/plots_2012/PF_L1CHS/mc/root_files/";
  TString pathToFileData = "/nfs/dust/cms/user/tlenz/JER_checkoutVersion/JERgammajet/plots_2012/PF_L1CHS/data/root_files/";


  bool addAll = false;
  bool addMC  = true;

  TString sourceResponseAlpha, sourceIntrinsicAlpha, sourceImbalanceAlpha, sourceTotalAlpha, sourceData, pdfFile, etaRegion, ptRegion, title, EtaPtRegion; 
    
  TLatex*  info;
  TLegend *legend;
  TGraphErrors* Add;
  TF1 *fScaleAlpha;
  TF1 *total;

  TCanvas *c = new TCanvas();
  for(int j=0; j<nEtaBins; j++){
    //for(int j=0; j<1; j++){
    for(int i=0;i<nPtBins;i++){
      //for(int i=11;i<12;i++){


      sourceResponseAlpha.Form("jet_energy_resolution_for_%i_eta_bin_%i_pTGamma_bin_PFCHS_mc_RMS99.root",j+1,i+1);
      sourceIntrinsicAlpha.Form("jet_energy_resolution_for_%i_eta_bin_%i_pTGamma_bin_intrinsic_PFCHS_mc_RMS99.root",j+1,i+1);
      sourceImbalanceAlpha.Form("jet_energy_resolution_for_%i_eta_bin_%i_pTGamma_bin_imbalance_PFCHS_mc_RMS99.root",j+1,i+1);
      sourceTotalAlpha.Form("jet_energy_resolution_for_%i_eta_bin_%i_pTGamma_bin_total_PFCHS_mc_RMS99.root",j+1,i+1);
      sourceData.Form("jet_energy_resolution_for_%i_eta_bin_%i_pTGamma_bin_PFCHS_data_RMS99.root",j+1,i+1);
      
      if(addAll)     pdfFile.Form("output/JER_for_%i_eta_bin_%i_pTGamma_bin_all_contributions_PFCHS_RMS99_mc.pdf",j+1,i+1);
      else if(addMC) pdfFile.Form("output/JER_for_%i_eta_bin_%i_pTGamma_bin_wo_data_PFCHS_RMS99_mc.pdf",j+1,i+1);
      else           pdfFile.Form("output/JER_for_%i_eta_bin_%i_pTGamma_bin_wo_data_mc_PFCHS_RMS99_mc.pdf",j+1,i+1);
      title = "Jet Energy Resolution";
 

      c -> cd();
      
      legend  = new TLegend(0.4,0.65,0.9,0.9);
      legend -> SetTextSize(0.05);
  
      // Intrinsic
      Add = GetTGraphErrors(pathToFileMC + sourceIntrinsicAlpha,"Graph");  
      if(Add == 0) continue;
      Add -> SetMinimum(0.0);
      Add -> SetMaximum(0.4);   
      Add -> GetXaxis()->SetLimits(0,20);
      fScaleAlpha = Add->GetFunction("fResolutionAlpha");
  
      Add -> SetMarkerColor(c_intrinsic);
      Add -> SetLineColor(c_intrinsic);
      fScaleAlpha -> SetLineColor(c_intrinsic);
      fScaleAlpha -> SetLineWidth(width);
      Add -> GetXaxis() -> SetTitle("#alpha [%]");   
      Add -> GetXaxis() -> SetTitle("p_{T}^{2nd jet}/p_{T}^{#gamma} [%]");    
      Add -> GetYaxis() -> SetTitle("#sigma_{JER}"); 
      Add -> SetTitle("");
      legend -> AddEntry(Add,"Intrinsic","lep");
      Add -> Draw("AP");

      // Imbalance
      Add = GetTGraphErrors(pathToFileMC + sourceImbalanceAlpha,"Graph");  
      fScaleAlpha = Add->GetFunction("fResolutionAlpha");
      Add -> SetMarkerColor(c_imbalance);
      Add -> SetLineColor(c_imbalance);
      fScaleAlpha -> SetLineColor(c_imbalance);
      fScaleAlpha -> SetLineWidth(width);
      legend -> AddEntry(Add,"Imbalance","lep");
      Add -> Draw("Psame");

      // Total MC
      total = GetTF1(pathToFileMC + sourceTotalAlpha,"totalResolution");
      total -> SetLineColor(c_total);
      total -> SetLineStyle(2);
      total -> SetLineWidth(width+1);
      legend -> AddEntry(total,"Total","l");
      total -> Draw("same");


      // MC pseudo data
      Add = GetTGraphErrors(pathToFileMC + sourceResponseAlpha,"Graph");  
      fScaleAlpha = Add->GetFunction("fResolutionAlpha");
      Add -> SetMarkerColor(c_measured);
      Add -> SetLineColor(c_measured);
      fScaleAlpha -> SetLineWidth(width);
      fScaleAlpha -> SetLineColor(c_measured);
      Add -> GetXaxis() -> SetTitle("#alpha [%]");   
      Add -> GetXaxis() -> SetTitle("p_{T}^{2nd jet}/p_{T}^{#gamma} #upoint 100");    
      Add -> GetYaxis() -> SetTitle("Resolution"); 
      Add -> SetTitle("");           
      if(addMC){
	//	legend -> AddEntry(Add,"#gamma + Jet (pseudo data)","lep");
	legend -> AddEntry(Add,"#gamma + Jet (simulation)","lep");
	Add    -> Draw("Psame");
	total  -> Draw("same");
      }

      // Data
      Add = GetTGraphErrors(pathToFileData + sourceData,"Graph");  
      if(Add != 0){
	fScaleAlpha = Add->GetFunction("fResolutionAlpha");
	Add -> SetMarkerColor(c_data);
	Add -> SetLineColor(c_data);
	fScaleAlpha -> SetLineColor(c_data);
	fScaleAlpha -> SetLineWidth(width);
	if(addAll){
	  legend -> AddEntry(Add,"Data","lep");
	  Add -> Draw("Psame");
	}
      }

      // Draw info boxes
      if (i==nPtBins-1) ptRegion.Form("p_{T}^{#gamma} > %4.0f GeV",ptBins[i]);
      else       ptRegion.Form("%4.1f GeV < p_{T}^{#gamma} < %4.1f GeV" ,ptBins[i], ptBins[i+1]);
      etaRegion.Form("%4.1f < |#eta^{1st jet}| < %4.1f",etaBins[j], etaBins[j+1]);
      
      EtaPtRegion.Form("#splitline{%s}{%s}",ptRegion.Data(),etaRegion.Data());

      info   = new TLatex();
      info -> SetNDC();    
      info -> SetTextSize(0.04);
      info->DrawLatex(0.23,0.55,  ptRegion);
      info->DrawLatex(0.22,0.48,  etaRegion);
      //      info->DrawLatex(0.55,0.53, "Anti-k_{T} 0.5 PFCHSJets");
      
      
      legend -> Draw("same");
      c -> SaveAs(pdfFile);
    }
  }

 
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


TGraphErrors* GetTGraphErrors(TString filename, TString objectName){

  TGraphErrors* graph = 0;
  TFile* file =  TFile::Open(filename);
  if(file != 0) file -> GetObject(objectName,graph);
  delete file;
  
  return graph;
}

TF1* GetTF1(TString filename, TString objectName){

  TF1* object = 0;

  TFile* file =  TFile::Open(filename);
  if(file != 0) file -> GetObject(objectName,object);
  delete file;

  return object;
}


//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
