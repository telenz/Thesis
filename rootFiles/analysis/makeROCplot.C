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

  unsigned int nStep = 10;

  double *xNP = new double[nStep];
  double *x   = new double[nStep];
  double *yNP = new double[nStep];
  double *y   = new double[nStep];
  
  double bkgFullNP    = 0;
  double bkgFull      = 0;
  double signalFullNP = 0;
  double signalFull   = 0;

  for(int j=0; j<10; j++){

    double cut = j*0.1;

    for(unsigned int i=0; i<samplesSig.size(); i++){

      samplesSig[i].getTree("~/xxl-af-cms/ANALYSIS/workdir/analysis_2015_10_26_NoSelection/results/analyzer/ntuples/input_weighted/");
      samplesSig[i].getTreeVariables();

      samplesSig[i].histo      = new TH1D(samplesSig[i].filename,samplesSig[i].filename,1,-10,1);
      samplesSig[i].histoNP    = new TH1D(samplesSig[i].filename,samplesSig[i].filename,1,-10,1);
      samplesSig[i].histo      -> Sumw2();
      samplesSig[i].histoNP    -> Sumw2();

      samplesSig[i].Selection(cut);


      if(j==0){
	signalFullNP = samplesSig[i].histoNP -> Integral();
	signalFull   = samplesSig[i].histo   -> Integral();
	
      }

      cout<<"samplesSig[i].histoNP->Integral() = "<<samplesSig[i].histoNP->Integral()<<endl;

      yNP[j]  = samplesSig[i].histoNP->Integral()/signalFullNP;
      y[j]    = samplesSig[i].histo->Integral()/signalFull;

      cout<<"yNP["<<j<<"] = "<<yNP[j]<<endl;
      cout<<"y["<<j<<"]   = "<<y[j]<<endl;

      delete samplesSig[i].histo;
      delete samplesSig[i].histoNP;
    }

    for(unsigned int i=0; i<samplesBkg.size(); i++){

      samplesBkg[i].getTree("~/xxl-af-cms/ANALYSIS/workdir/analysis_2015_10_26_NoSelection/results/analyzer/ntuples/input_weighted/");
      samplesBkg[i].getTreeVariables();
      samplesBkg[i].histo      = new TH1D(samplesBkg[i].filename,samplesBkg[i].filename,1,-10,1);
      samplesBkg[i].histoNP    = new TH1D(samplesBkg[i].filename,samplesBkg[i].filename,1,-10,1);
      samplesBkg[i].histo      ->Sumw2();
      samplesBkg[i].histoNP    ->Sumw2();

      samplesBkg[i].Selection(cut);

      if(j==0){
	bkgFullNP      = samplesBkg[i].histoNP->Integral();
	bkgFull        = samplesBkg[i].histo->Integral();
      }

      xNP[j] = samplesBkg[i].histoNP->Integral()/bkgFullNP;
      x[j]   = samplesBkg[i].histo->Integral()/bkgFull;

      cout<<"xNP["<<j<<"] = "<<xNP[j]<<endl;
      cout<<"x["<<j<<"]   = "<<x[j]<<endl;


      delete samplesBkg[i].histo;
      delete samplesBkg[i].histoNP;
  
    }   
    
  }

  // %% STYLE %%%%%%%%%%%%%%%%%%%%%%%%%%%%
  gStyle->SetMarkerSize(1);
  gROOT->ForceStyle();
  // %% STYLE %%%%%%%%%%%%%%%%%%%%%%%%%%%%

  TCanvas *c = new TCanvas();
  c->cd();
  c->SetLogx();

  TGraph *gNP = new TGraph(nStep,xNP,yNP);
  TGraph *g   = new TGraph(nStep,x,y);
  
  g   -> SetMarkerColor(2);
  gNP -> SetMarkerColor(1);

  g->SetTitle("");
  g->GetXaxis()->SetTitle("bkg efficiency (wjets only)");
  g->GetYaxis()->SetTitle("signal efficiency");
  g->Draw("AP");
  gNP->Draw("same P");


  TLegend* leg = new TLegend(0.16,0.8,0.65,0.95);
  leg->SetTextSize(0.05);
  //leg->SetTextFont(42);
  leg->AddEntry(g,"Pixel hits included","p");
  leg->AddEntry(gNP,"Without Pixel hits","p");
  leg->Draw("same");

  TLatex* info = new TLatex();
  info->SetNDC();
  info->DrawLatex(0.20,0.7,"m=" + mass + "GeV");
  info->DrawLatex(0.20,0.65,"c#tau=" + ctau + "cm");


  c->SaveAs("output/rocplot_wjets_mass_" + mass + "GeV_ctau_" + ctau + "cm.pdf");
  
  return 0;
 
}
