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
TGraphErrors* readTGraphErrors(const TString &fileName, const TString &gName, const TString &newGName);


int makeQCDUncertaintyPlot(){

  TeresaPlottingStyle::init();
  TGaxis::SetMaxDigits(5);
  gStyle->SetHistLineWidth(width);
  gStyle->SetNdivisions(506,"Y");

  TString pathToFile = "/nfs/dust/cms/user/tlenz/JER_checkoutVersion/JERgammajet/plots_2012/PF_L1CHS/systematicUncertainties/scripts/root_files_QCDUncertainty/";

  const TString method = "RMS99";
  const TString type   = "PFCHS";
  const int eta        = 1;

  const double etaBinsQCD[3] = {0.0,1.3,2.7};

  TString pathName    = pathToFile + "mcWoQCD/";
  TString pathNameQCD = pathToFile + "dataWithQCD/";

  cout<<"root files from following folders:"<<endl<<pathName<<endl<<pathNameQCD<<endl<<endl<<endl;

  TString etaString,tot_filename, AuxString;
  TMultiGraph* mg = new TMultiGraph();

  // ------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  // Calculate Correlation with the help of the control plot hPhoton1Pt_PFCHS_mc.root
  TString rootFile[2]; 
  rootFile[0]  = pathName    +  "Resolution_for_1_eta_bin_PFCHS_mc_RMS99.root";
  rootFile[1]  = pathNameQCD +  "Resolution_for_1_eta_bin_PFCHS_data_RMS99.root";

  etaString = "Uncertainty on QCD contamination";
  mg -> SetTitle(etaString);
    

  TCanvas *c = new TCanvas();
  c -> cd();

  TString fitName;
  double maximum = 0;

  TGraphErrors* graph[2]; 
  for(int i =0; i<2; i++){
    graph[i] = readTGraphErrors(rootFile[i],"Graph","Graph");    
    if(graph[i]->GetYaxis()->GetXmax() > maximum) maximum = graph[i]->GetYaxis()->GetXmax();
  }
  
  graph[0] -> SetMarkerColor(kRed);
  graph[1] -> SetMarkerColor(kBlue+1);
 
  graph[0] -> SetLineColor(kRed);
  graph[1] -> SetLineColor(kBlue+1);

  graph[0] -> GetFunction("fResolution") -> SetLineColor(kRed);
  graph[1] -> GetFunction("fResolution") -> SetLineColor(kBlue+1);

  graph[0] -> GetFunction("fResolution") -> SetLineWidth(width);
  graph[1] -> GetFunction("fResolution") -> SetLineWidth(width);
  
 
  TLegend *legend  = new TLegend(0.5,0.75,0.9,0.9);
  legend->SetTextSize(0.05);
  legend -> AddEntry(graph[0],"without QCD","l");
  legend -> AddEntry(graph[1],"with QCD","l");
  
  mg->Add(graph[0]);  
  mg->Add(graph[1]);  
  
  mg->Draw("AP");
    
  mg -> GetYaxis() -> SetTitle("#sigma_{JER}");
  mg -> SetMinimum(0.04);
  mg -> SetMaximum(0.15);   
  mg -> GetXaxis() -> SetLimits(0,600);

  mg -> GetXaxis() -> SetTitle("p_{T}^{#gamma} [GeV]");
  

  TLatex*  info   = new TLatex();
  info-> SetNDC();
  AuxString = Form("%4.1f < |#eta^{1st jet}| < %4.1f",etaBinsQCD[eta-1],etaBinsQCD[eta]);
  info->DrawLatex(0.5,0.6,AuxString);
  info -> DrawLatex(0.7, 0.95, "Simulation");
  
  legend->Draw("same");
  tot_filename = "output/Resolution_for_1_eta_bin_QCDUncertainty_RMS99.pdf";
  c -> SaveAs(tot_filename);

  //-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

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

TGraphErrors* readTGraphErrors(const TString &fileName, const TString &gName, const TString &newGName) {
  TFile f(fileName,"READ");
  TGraphErrors *g = 0;
  f.GetObject(gName,g);
  if( g ) {
    if( newGName.Length() ) g->SetName(newGName);
  } else {
    std::cerr << "ERROR in FileOps::readTGraph: TGraphErrors with name '" << gName << "' does not exist in file '" << fileName << "'\n.";
    f.Close();
    exit(-1);
  }
  f.Close();
    
  return g;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
