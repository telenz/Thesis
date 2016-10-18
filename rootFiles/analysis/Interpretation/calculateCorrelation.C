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
#include "TAxis.h"
#include "TGaxis.h"
#include "TStyle.h"
#include "TLine.h"
#include "TTree.h"
#include "TChain.h"
#include "TRandom3.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include "../../plotStyleThesis.h"


class sample{

public:

  vector<unsigned int> eventList;

  TFile *file;
  TTree *tree;

  TH1D* histoInner;
  TH1D* histoMiddle;

  double statistics;
  double purity;

  vector<double> *trackEta;
  vector<double> *trackPt;
  vector<double> *trackP;
  vector<double> *trackGenPt;
  vector<double> *trackASmi;
  vector<double> *trackHarm2;
  vector<double> *trackCaloIso;
  vector<double> *trackMass;
  vector<double> *trackIsolation;
  vector<double> *trackGenE;
  vector<double> *trackGenEt;
  vector<double> *trackEndVertexRho ;
  vector<double> *trackChi2;
  vector<double> *trackNdof;
  vector<int>    *trackNLostOuter;
  vector<int>    *trackNLostMiddle;
  vector<int>    *trackNLostInner;
  vector<int>    *trackNValid;
  vector<int>    *trackPdgId;
  double weight;
  double weight_xsec_lumi;
  double met;
  double leadingJetPt;
  unsigned int event;

  sample(){

    tree=0;
    file=0;
    statistics=0;
    purity=0;

    trackEta        = 0;
    trackEta        = 0;
    trackPt         = 0;
    trackP          = 0;
    trackGenPt      = 0;
    trackASmi       = 0;
    trackHarm2      = 0;
    trackCaloIso    = 0;
    trackMass       = 0;
    trackIsolation  = 0;
    trackGenE       = 0;
    trackGenEt      = 0;
    trackEndVertexRho = 0;
    trackChi2 = 0;
    trackNdof = 0;
    trackNLostOuter = 0;
    trackNLostMiddle = 0;
    trackNLostInner = 0;
    trackNValid     = 0;
    trackPdgId      = 0;
  };

  void getTreeVariables(){
    tree->SetBranchAddress("trackEta",&trackEta);
    tree->SetBranchAddress("trackPt",&trackPt);
    tree->SetBranchAddress("trackP",&trackP);
    tree->SetBranchAddress("trackGenPt",&trackGenPt);
    tree->SetBranchAddress("trackDeDxASmi",&trackASmi);
    tree->SetBranchAddress("trackDeDxHarm2",&trackHarm2);
    tree->SetBranchAddress("trackCaloIsolation",&trackCaloIso);
    tree->SetBranchAddress("trackMass",&trackMass);
    tree->SetBranchAddress("trackIsolation",&trackIsolation);
    tree->SetBranchAddress("trackGenE",&trackGenE);
    tree->SetBranchAddress("trackGenEt",&trackGenEt);
    tree->SetBranchAddress("trackEndVertexRho",&trackEndVertexRho);
    tree->SetBranchAddress("trackChi2",&trackChi2);
    tree->SetBranchAddress("trackNdof",&trackNdof);
    tree->SetBranchAddress("trackNLostOuter",&trackNLostOuter);
    tree->SetBranchAddress("trackNLostInner",&trackNLostInner);
    tree->SetBranchAddress("trackNLostMiddle",&trackNLostMiddle);
    tree->SetBranchAddress("trackNValid",&trackNValid);
    tree->SetBranchAddress("trackPdgId",&trackPdgId);
    tree->SetBranchAddress("MET",&met);
    tree->SetBranchAddress("LeadingJetPt",&leadingJetPt);
    tree->SetBranchAddress("weight",&weight);
    tree->SetBranchAddress("weight_xsec_lumi",&weight_xsec_lumi);
    tree->SetBranchAddress("event",&event);
  };


  void Selection(bool select, double ptMin, double ptMax, double iasMin, double iasMax){

    cout<<"Tree entries = "<<tree->GetEntries()<<endl;
    
    for(int n=0; n<tree->GetEntries(); n++){

      tree->GetEntry(n);
      weight=1;
      weight_xsec_lumi=1;

      if(select){
	for(unsigned int i = 0; i<trackASmi->size(); i++ ){
	  
	  if(trackPt->at(i)  < ptMin)   continue;
	  if(trackPt->at(i)  > ptMax)   continue;
	  if(trackASmi->at(i) < iasMin) continue;
	  if(trackASmi->at(i) > iasMax) continue;
	  eventList.push_back(event);
	}
      }
      else{ eventList.push_back(event);}
    }
    
  };


};


int calculateCorrelations(double ptMin = 30, double ptMax = 1000, double iasMin = 0.0, double iasMax = 0.99){


  TeresaPlottingStyle2d::init();
  gStyle->SetNdivisions(510,"Z");
  gROOT->ForceStyle();

  TCanvas *c = new TCanvas();
  
  vector<TString> ctau;
  //ctau.push_back("2");
 
  ctau.push_back("5");
  ctau.push_back("10");
  ctau.push_back("50");
  ctau.push_back("100");
  ctau.push_back("500");
  ctau.push_back("1000");


  TH2D* corr = new TH2D("correlation","correlation",6,100,700,1,0,1);
  
  for(int m=1;m<7;m++){
    int mass = 100*m;

    for(unsigned int ct=0; ct<ctau.size(); ct++)
      {
	corr->Fill(1.0*mass,ctau[ct],0.0);
	sample DTAnalysis;
	sample myAnalysis;

	iasMin=0.00;
	iasMax=0.99;

	/*
	if(mass == 100 && (ctau[ct].EqualTo("1") || ctau[ct].EqualTo("5") || ctau[ct].EqualTo("10")) ){
	  iasMin = 0.05;
	  iasMax = 0.30;
	}
	if(mass == 200 && (ctau[ct].EqualTo("1") || ctau[ct].EqualTo("5")) ){
	  iasMin = 0.05;
	  iasMax = 0.30;
	}
	*/
	cout<<iasMin<<endl;

	TString signal     = (TString) "Madgraph_signal_mass_" + (long) mass + (TString) "_ctau_" + (TString) ctau[ct] + (TString) "cm";
	TString selection  = "chiTracksfullSelectionNoQCDCutsNoTrigger";
	TString pathTofile = "/afs/desy.de/user/t/tlenz/xxl-af-cms/ANALYSIS/workdir/analysis_2015_12_08_DTSelection/results/analyzer/ntuples/input_weighted/";
 
	DTAnalysis.file    = new TFile(pathTofile + signal + ".root","READ");
	DTAnalysis.file    -> GetObject("chiTracksDTSelection/Variables",DTAnalysis.tree);
	myAnalysis.file    = new TFile(pathTofile + signal + ".root","READ");
	myAnalysis.file    -> GetObject("chiTracksfullSelectionTrigger/Variables",myAnalysis.tree);
	
	DTAnalysis.getTreeVariables();
	myAnalysis.getTreeVariables();
  
	DTAnalysis.Selection(0,0,100000,0,1);
	myAnalysis.Selection(1,ptMin,ptMax,iasMin,iasMax);

	int nOverlap = 0;

	for(unsigned int i=0; i<DTAnalysis.eventList.size(); i++){
	  for(unsigned int j=0; j<myAnalysis.eventList.size(); j++){
	    if(DTAnalysis.eventList[i] == myAnalysis.eventList[j]){
	      //cout<<myAnalysis.eventList[j]<<endl;;
	      nOverlap += 1;
	    }
	  }
	}
  
	cout<<"nOverlap = "<<nOverlap<<endl;
	cout<<"DTAnalysis.eventList.size() = "<<DTAnalysis.eventList.size()<<endl;
	cout<<"myAnalysis.eventList.size() = "<<myAnalysis.eventList.size()<<endl;
	int nDTOrMy = myAnalysis.eventList.size() + DTAnalysis.eventList.size() - nOverlap;
	cout<<"DT || my                    = "<<nDTOrMy<<endl;
	double rho = sqrt(1.0* nOverlap/nDTOrMy);
	cout<<"correlation coefficient     = "<<rho<<endl;

	int binx= corr->GetXaxis()->FindBin(mass); 
	int biny= corr->GetYaxis()->FindBin(ctau[ct]); 
	corr->SetBinContent(binx,biny,rho*100);
	
      }
  }

  corr -> LabelsDeflate("Y");
  corr -> GetXaxis()->SetTitle("mass_{#Chi^{#pm}} [GeV]");
  corr -> GetYaxis()->SetTitle("c#tau_{#Chi^{#pm}} [cm]");
  corr -> GetYaxis()->SetLabelSize(0.07);
  corr -> GetZaxis()->SetTitle("Event overlap [%]");
  //corr -> GetZaxis()->SetRangeUser(10,60);

  c->cd();
  corr ->Draw("COLZ");
  c->SaveAs("AnalysisOverlap.pdf");
  return 0;
 
}


//  LocalWords:  xmax
