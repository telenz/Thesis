#include "TROOT.h"
#include "TFile.h"
#include "TProfile.h"
#include "TH1.h"
#include "TH2.h"
#include "TMath.h"
#include "TGraph.h"
#include "TGraphErrors.h"
#include "TString.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TLatex.h"
#include "TROOT.h"
#include "TStyle.h"
#include "TLine.h"
#include "TTree.h"
#include "TProfile.h"
#include "TChain.h"
#include "TRandom3.h"
#include "TGraphAsymmErrors.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include "Classes.h"
#include "/afs/desy.de/user/t/tlenz/Thesis/rootFiles/plotStyleThesis.h"


int makeROCplot(TString mass="500", TString ctau="50" ){

  TeresaPlottingStyle::init();

  vector<sample> samplesSig;
  samplesSig.push_back((TString) "Madgraph_signal_mass_" + mass + "_ctau_" + ctau + "cm");

  vector<sample> samplesBkg;
  samplesBkg.push_back((TString) "wjets");
  //samplesBkg.push_back((TString) "ttjets");

  unsigned int nStep = 20;

  double *xNP = new double[nStep-1];
  double *x   = new double[nStep-1];
  double *yNP = new double[nStep-1];
  double *y   = new double[nStep-1];
  
  for(unsigned int i=0; i<samplesSig.size(); i++){
    samplesSig[i].getTree("~/xxl-af-cms/ANALYSIS/workdir/analysis_2015_10_27_NoSelection/results/analyzer/ntuples/input_weighted/");
    samplesSig[i].getTreeVariables();

    samplesSig[i].histo      = new TH1D(samplesSig[i].filename,samplesSig[i].filename,nStep,0,1);
    samplesSig[i].histoNP    = new TH1D(samplesSig[i].filename,samplesSig[i].filename,nStep,0,1);
    samplesSig[i].histo      -> Sumw2();
    samplesSig[i].histoNP    -> Sumw2();

    samplesSig[i].Selection(10000);
  }

  for(unsigned int i=0; i<samplesBkg.size(); i++){
    samplesBkg[i].getTree("~/xxl-af-cms/ANALYSIS/workdir/analysis_2015_10_27_NoSelection/results/analyzer/ntuples/input_weighted/");
    samplesBkg[i].getTreeVariables();

    samplesBkg[i].getTree("~/xxl-af-cms/ANALYSIS/workdir/analysis_2015_10_27_NoSelection/results/analyzer/ntuples/input_weighted/");
    samplesBkg[i].getTreeVariables();
    samplesBkg[i].histo      = new TH1D(samplesBkg[i].filename,samplesBkg[i].filename,nStep,0,1);
    samplesBkg[i].histoNP    = new TH1D(samplesBkg[i].filename,samplesBkg[i].filename,nStep,0,1);
    samplesBkg[i].histo      ->Sumw2();
    samplesBkg[i].histoNP    ->Sumw2();
    
    samplesBkg[i].Selection(100000);

    samplesBkg[i].histo->Draw();
    samplesBkg[i].histoNP->SetLineColor(2);
    samplesBkg[i].histoNP->Draw("same");
  }

  for(unsigned int j=1; j<nStep; j++){

    yNP[j-1]  = samplesSig[0].histoNP->Integral(j,samplesSig[0].histoNP->GetNbinsX())/samplesSig[0].histoNP->Integral();
    y[j-1]    = samplesSig[0].histo->Integral(j,samplesSig[0].histoNP->GetNbinsX())/samplesSig[0].histo->Integral();
    
    xNP[j-1] = samplesBkg[0].histoNP->Integral(j,samplesBkg[0].histoNP->GetNbinsX()+1)/samplesBkg[0].histoNP->Integral();
    x[j-1]   = samplesBkg[0].histo->Integral(j,samplesBkg[0].histoNP->GetNbinsX()+1)/samplesBkg[0].histo->Integral();

    cout<<"yNP["<<j-1<<"] = "<<yNP[j-1]<<endl;
    cout<<"y["<<j-1<<"]   = "<<y[j-1]<<endl;
    cout<<"xNP["<<j-1<<"] = "<<xNP[j-1]<<endl;
    cout<<"x["<<j-1<<"]   = "<<x[j-1]<<endl<<endl;
   
  }

  // %% STYLE %%%%%%%%%%%%%%%%%%%%%%%%%%%%
  gStyle->SetMarkerSize(1);
  gROOT->ForceStyle();
  // %% STYLE %%%%%%%%%%%%%%%%%%%%%%%%%%%%

  TCanvas *c = new TCanvas();
  c->cd();

  TGraph *gNP = new TGraph(nStep-1,xNP,yNP);
  TGraph *g   = new TGraph(nStep-1,x,y);
  
  g   -> SetMarkerColor(2);
  gNP -> SetMarkerColor(1);

  g->SetTitle("");
  g->GetXaxis()->SetTitle("bkg efficiency");
  g->GetYaxis()->SetTitle("signal efficiency");
  g->Draw("AP");
  gNP->Draw("same P");

  c->SetLogx();
  c->Update();
  TLegend* leg = new TLegend(0.16,0.8,0.70,0.95);
  leg->SetTextSize(0.05);
  //leg->SetTextFont(42);
  leg->AddEntry(g,"Pixel hits included","p");
  leg->AddEntry(gNP,"Without Pixel hits","p");
  leg->Draw("same");

  TLatex* info = new TLatex();
  info->SetNDC();
  info->DrawLatex(0.20,0.7,"m=" + mass + "GeV");
  info->DrawLatex(0.20,0.65,"c#tau=" + ctau + "cm");

  g->GetYaxis()->SetRangeUser(0,1);
  g->GetXaxis()->SetLimits(0.00001,1);
  gNP->GetYaxis()->SetRangeUser(0,1);
  gNP->GetXaxis()->SetLimits(0.00001,1);
  g->GetYaxis()->SetNdivisions(905);
  c->Update();

  c->SaveAs("output/rocplot_wjets_mass_" + mass + "GeV_ctau_" + ctau + "cm.pdf");
  
  return 0;
 
}
