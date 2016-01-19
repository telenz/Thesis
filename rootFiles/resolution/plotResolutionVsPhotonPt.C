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


int plotResolutionVsPhotonPt(){

  TeresaPlottingStyle::init();
  gStyle->SetHistLineWidth(width);
  gStyle->SetNdivisions(507,"Y");

  TString pathToFileMC   = "/nfs/dust/cms/user/tlenz/JER_checkoutVersion/JERgammajet/plots_2012/PF_L1CHS/mc/root_files/";
  TString pathToFileData = "/nfs/dust/cms/user/tlenz/JER_checkoutVersion/JERgammajet/plots_2012/PF_L1CHS/data/root_files/";

  TString sourceData, sourceIntrinsic, sourceMC, sourceImbalance, pdfFile, etaRegion, ptRegion, title, EtaPtRegion; 
    
  TLatex*  info;
  TGraphErrors* intrinsicJER, *imbalanceJER, *dataJER, *mcJER;
  TCanvas *c[nEtaBins], *cImb[nEtaBins];
  for(int j=0; j<nEtaBins; j++){

    sourceIntrinsic.Form("Resolution_for_%i_eta_bin_intrinsic_PFCHS_mc_RMS99.root",j+1);
    sourceImbalance.Form("Resolution_for_%i_eta_bin_imbalance_PFCHS_mc_RMS99.root",j+1);
    sourceMC.Form("Resolution_for_%i_eta_bin_PFCHS_mc_RMS99.root",j+1);
    sourceData.Form("Resolution_for_%i_eta_bin_PFCHS_data_RMS99.root",j+1);
    pdfFile.Form("output/Resolution_for_%i_eta_bin_PFCHS_mc_RMS99.pdf",j+1);


    c[j] = new TCanvas();
    TString name = "imbalance";
    cImb[j] = new TCanvas();
    c[j] -> cd();
    TLegend *legend = new TLegend(0.5,0.75,0.9,0.9);      

    intrinsicJER = GetTGraphErrors(pathToFileMC + sourceIntrinsic,"Graph");  
    imbalanceJER = GetTGraphErrors(pathToFileMC + sourceImbalance,"Graph");
    dataJER      = GetTGraphErrors(pathToFileData + sourceData,"Graph");  
    mcJER        = GetTGraphErrors(pathToFileMC + sourceMC,"Graph");  
    if(intrinsicJER  == 0) continue;
      
    intrinsicJER -> GetFunction("fResolution")-> SetLineColor(46);
    intrinsicJER -> SetMarkerColor(c_intrinsic);
    intrinsicJER -> SetLineColor(c_intrinsic);
    intrinsicJER -> SetLineWidth(width);
    imbalanceJER -> GetFunction("fResolution")-> SetBit(TF1::kNotDraw);
    imbalanceJER -> SetMarkerColor(c_imbalance);
    imbalanceJER -> SetLineColor(c_imbalance);
    imbalanceJER -> SetLineWidth(width);

    mcJER -> GetFunction("fResolution")-> SetLineColor(c_measured);
    mcJER -> SetMarkerColor(c_measured);
    mcJER -> SetLineColor(c_measured);
    dataJER -> GetFunction("fResolution")-> SetLineColor(c_data);
    dataJER -> SetMarkerColor(c_data);
    dataJER -> SetLineColor(c_data);


    intrinsicJER -> GetXaxis() -> SetTitle("p_{T}^{#gamma} [GeV]");   
    imbalanceJER -> GetXaxis() -> SetTitle("p_{T}^{#gamma} [GeV]");
    mcJER        -> GetXaxis() -> SetTitle("p_{T}^{#gamma} [GeV]");   
    dataJER      -> GetXaxis() -> SetTitle("p_{T}^{#gamma} [GeV]");   
    intrinsicJER -> GetYaxis() -> SetTitle("#sigma_{intrinsic}"); 
    imbalanceJER -> GetYaxis() -> SetTitle("#sigma_{imbalance}"); 
    mcJER        -> GetYaxis() -> SetTitle("#sigma_{JER}"); 
    dataJER      -> GetYaxis() -> SetTitle("#sigma_{JER}"); 
                        
    intrinsicJER -> SetMinimum(0.00);
    intrinsicJER -> SetMaximum(0.20);   
    intrinsicJER -> GetXaxis() -> SetRangeUser(0,600);
    imbalanceJER -> SetMinimum(0.00);
    imbalanceJER -> SetMaximum(0.10);   
    imbalanceJER -> GetXaxis() -> SetRangeUser(0,600);

    mcJER -> SetMinimum(0.00);
    mcJER -> SetMaximum(0.20);   
    mcJER -> GetXaxis() -> SetRangeUser(0,600);
      
    //intrinsicJER -> Draw("AP");
    mcJER        -> Draw("AP");
    dataJER      -> Draw("Psame");

    //legend -> SetTextSize(0.033);
    legend -> SetTextSize(0.05);
    legend -> SetLineWidth(2);
    legend -> AddEntry(dataJER, "Data");
    legend -> AddEntry(mcJER, "Simulation");
    legend -> Draw("same");

    // Draw info boxes
    etaRegion.Form("%4.1f < |#eta^{1st jet}| < %4.1f",etaBins[j], etaBins[j+1]);
      
    info   = new TLatex();
  
    info -> SetNDC();    
    info->DrawLatex(0.52,0.65,  etaRegion);
    info->DrawLatex(0.22,0.25, "Anti-k_{T} (R=0.5), PF+CHS");
    c[j] -> SaveAs(pdfFile);

    // Draw imbalance
    cImb[j] -> cd(); 
    imbalanceJER -> Draw("AP");
    delete info;
    info   = new TLatex();
    info -> SetNDC();    
    info->SetTextSize(0.05);
    info -> DrawLatex(0.7, 0.95, "Simulation");
    info->DrawLatex(0.22,0.76,  etaRegion);
    info->DrawLatex(0.22,0.85, "Anti-k_{T} (R=0.5), PF+CHS");

    pdfFile.Form("output/Imbalance_for_%i_eta_bin_PFCHS_mc_RMS99.pdf",j+1);
    cImb[j] -> SaveAs(pdfFile);


    // Draw intrinsic
    cImb[j] -> cd(); 
    intrinsicJER -> Draw("AP");
    delete info;
    info   = new TLatex();
    info -> SetNDC();    
    info->SetTextSize(0.05);
    info -> DrawLatex(0.7, 0.95, "Simulation");
    info->DrawLatex(0.5,0.76,  etaRegion);
    info->DrawLatex(0.35,0.85, "Anti-k_{T} (R=0.5), PF+CHS");

    pdfFile.Form("output/Intrinsic_for_%i_eta_bin_PFCHS_mc_RMS99.pdf",j+1);
    cImb[j] -> SaveAs(pdfFile);
    
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
