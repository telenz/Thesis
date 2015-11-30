#include <iostream>
#include <stdlib.h>
#include <cmath>
#include "TF1.h"
#include "TH1.h"
#include "TH2.h"
#include "TFile.h"
#include "TCanvas.h"
#include "TStyle.h"
#include "TLegend.h"
#include "TLatex.h"
#include "../plotStyleThesis.h"

TCanvas* plotTH2D(TH2* histo, TString xTitle, TString yTitle);

void make2dplot(){

  //  gStyle->SetOptFit(1111);
  gStyle->SetOptStat("");

  TeresaPlottingStyle2d::init();
  gROOT->ForceStyle();


  TCanvas *c = new TCanvas("c","c",500,0,500,500);
  c->cd();

  //  TString ana = "analysis_2015_07_24_WithVertexCondition_FinerBinning";
  TString ana = "analysis_2015_11_30_ForThesis";
  
  TFile *fileMC   = new TFile("/nfs/dust/cms/user/tlenz/HighDeDx-DisappTrks-PostProcessing-ExclusiveBins/systematics/signal/11_Ias/ANALYSES/workdir/" + ana + "/results/analyzer/ntuples/mc.root", "READ");
  TFile *fileData = new TFile("/nfs/dust/cms/user/tlenz/HighDeDx-DisappTrks-PostProcessing-ExclusiveBins/systematics/signal/11_Ias/ANALYSES/workdir/" + ana + "/results/analyzer/ntuples/data.root", "READ");
  TH2D* histoIasPMC = 0;
  TH2D* histoIasPData = 0;
  fileMC    -> GetObject("hIasP",histoIasPMC);
  fileData  -> GetObject("hIasP",histoIasPData);

  histoIasPMC->Scale(histoIasPData->Integral()/histoIasPMC->Integral());
  TCanvas* c1 = plotTH2D(histoIasPMC,"p [GeV]","dE/dx discriminator (I_{as})");
  TLatex*  info   = new TLatex();
  info->DrawLatex(1.35,0.91,"Simulation");
  c1->SaveAs("IasP_MC.pdf");



  TCanvas* c2 = plotTH2D(histoIasPData,"p [GeV]","dE/dx discriminator (I_{as})");
  //histoIasPData->Scale(1./histoIasPData->Integral());
  info->DrawLatex(1.35,0.91,"Observed Data");
  c2->SaveAs("IasP_Data.pdf");

}
//####################################################################################################

TCanvas* plotTH2D(TH2* histo, TString xTitle, TString yTitle){


  TCanvas *c = new TCanvas("c","c",500,0,500,500);
  c->cd();

  histo->Draw("COLZ");
  histo->SetTitle("");
  histo->GetXaxis()->SetTitle(xTitle);
  histo->GetYaxis()->SetTitle(yTitle);
  histo->GetXaxis()->SetRangeUser(0.4,2.5);
  histo->GetZaxis()->SetRangeUser(1,100000);

  c->SetLogz();

  
  return c;

}
//####################################################################################################
