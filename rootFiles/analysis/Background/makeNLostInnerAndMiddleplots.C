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

  TFile *file;
  TTree *tree;

  TH1D* histo;

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
  };


  void Selection(bool doMatching, int pdgId){

    histo->Sumw2();

    statistics = 0;
    purity     = 0;

    cout<<"Tree entries = "<<tree->GetEntries()<<endl;
    
    for(int n=0; n<tree->GetEntries(); n++){

      tree->GetEntry(n);
      weight=1;
      weight_xsec_lumi=1;
      for(unsigned int i = 0; i<trackASmi->size(); i++ ){
	// ****************************************** Particle Id **********************************
	purity+=1;
	if(doMatching){
	  if(pdgId==-1){
	    if(abs(trackPdgId->at(i))!=211 && abs(trackPdgId->at(i))!=13 &&abs(trackPdgId->at(i))!=11 )      continue; 
	  }
	  else{
	    if(abs(trackPdgId->at(i))!=pdgId)      continue; 
	  }
	}
	statistics +=1;
	// ****************************************** Particle Id **********************************

	if(trackCaloIso->at(i) > 5) continue;
	if(trackPt->at(i) < 20) continue;
	//if(trackASmi->at(i) < 0) continue;
	if(abs(trackEta->at(i))>2.1)                                 continue;
	if(abs(trackEta->at(i))>1.42 && abs(trackEta->at(i))<1.65 )  continue;
	if(trackASmi->at(i)<0.0)           continue;
    

	histo     -> Fill(trackNLostInner->at(i)+trackNLostMiddle->at(i));
      }
      
    }

    histo->GetXaxis()->SetTitle("N_{miss}^{inner} + N_{miss}^{middle}");
    histo->GetYaxis()->SetTitle("a.u.");
    
    purity=statistics/purity;
  };



};


int makeNLostInnerAndMiddleplots(){

  TeresaPlottingStyle::init();
  gROOT->ForceStyle();

  sample pions;
  sample muons;
  sample elecs;
  sample fakes;
  sample leptons;
  
  //TString selection = "chiTracksQCDsupressionTrigger";
  TString selection = "chiTracksfullSelectionNoQCDCutsNoTrigger";
  //selection = "chiTracksfullSelectionNoQCDCuts";

  //  TString pathTofile = "../input_Met100";
  TString pathTofile = "/afs/desy.de/user/t/tlenz//xxl-af-cms/ANALYSIS/workdir/analysis_2015_11_17_METGt100_JetPt110_NoCutOnMissMiddleAndInner/results/analyzer/ntuples/";
  // pathTofile = "/nfs/dust/cms/user/tlenz/ANALYSIS/workdir/analysis_2015_08_19_METGt0_JetPt70_FakeCS/results/analyzer/ntuples/";
 

  pions.file    = new TFile(pathTofile + "/input_weighted/wjets.root","READ");
  pions.file     -> GetObject(selection + "/Variables",pions.tree);
  muons.file    = new TFile(pathTofile + "/input_weighted/wjets.root","READ");
  muons.file     -> GetObject(selection + "/Variables",muons.tree);
  elecs.file    = new TFile(pathTofile + "/input_weighted/wjets.root","READ");
  elecs.file     -> GetObject(selection + "/Variables",elecs.tree);
  fakes.file    = new TFile(pathTofile + "/input_weighted/wjets.root","READ");
  fakes.file     -> GetObject(selection + "/Variables",fakes.tree);
  leptons.file  = new TFile(pathTofile + "/input_weighted/wjets.root","READ");
  leptons.file   -> GetObject(selection + "/Variables",leptons.tree);

  pions.getTreeVariables();
  muons.getTreeVariables();
  elecs.getTreeVariables();
  fakes.getTreeVariables();
  leptons.getTreeVariables();

  int    nbins = 5;
  double xmin  = 0 ;
  double xmax  = 5 ;


  Double_t xbinsNHits[4]  = {3,5,7,25};
  
  pions.histo     = new TH1D("pions","pions",nbins,xmin,xmax);
  muons.histo     = new TH1D("muons","muons",nbins,xmin,xmax);
  elecs.histo     = new TH1D("elecs","elecs",nbins,xmin,xmax);
  fakes.histo     = new TH1D("fakes","fakes",nbins,xmin,xmax);
  leptons.histo     = new TH1D("fakes","fakes",nbins,xmin,xmax);
  
  
  pions.Selection(1,211);
  muons.Selection(1,13);
  elecs.Selection(1,11);
  fakes.Selection(1,0);
  leptons.Selection(1,-1);

  pions.histo   -> Scale(1./pions.histo->Integral());
  muons.histo   -> Scale(1./muons.histo->Integral());
  elecs.histo   -> Scale(1./elecs.histo->Integral());
  fakes.histo   -> Scale(1./fakes.histo->Integral());
  leptons.histo -> Scale(1./leptons.histo->Integral());

  TCanvas* c = new TCanvas();
  c->cd();
  //c->SetLogy();

  pions.histo   -> SetLineColor(kPink-3);
  muons.histo   -> SetLineColor(kGreen-6);
  elecs.histo   -> SetLineColor(867);
  fakes.histo   -> SetLineColor(kBlack);
  leptons.histo -> SetLineColor(kViolet-4);
  
  pions.histo   -> SetMarkerColor(kPink-3);
  muons.histo   -> SetMarkerColor(kGreen -6);
  elecs.histo   -> SetMarkerColor(867);
  fakes.histo   -> SetMarkerColor(kBlack);
  leptons.histo -> SetMarkerColor(kViolet-4);

  muons.histo->SetMarkerStyle(21);
  fakes.histo->SetMarkerStyle(24);
  elecs.histo->SetMarkerStyle(25);
  // muons.histo->SetMarkerSize(1.3);

  double min = 0.001;
  double max = 1;
  pions.histo->SetMinimum(min);
  pions.histo->SetMaximum(max);    
  muons.histo->SetMinimum(min);
  muons.histo->SetMaximum(max);    
  elecs.histo->SetMinimum(min);
  elecs.histo->SetMaximum(max);    
  fakes.histo->SetMinimum(min);
  fakes.histo->SetMaximum(max);    
  

  
  //pions.histo->SetMaximum(10000);
  //pions.histo->Draw();
  //muons.histo->Draw("same");
  //elecs.histo->Draw("same");
  fakes.histo->Draw("");
  //pions.histo->Draw("same");
  leptons.histo->Draw("same");
  
  TLegend *legend =  new TLegend(0.60,0.65,0.9,0.93);
  legend->SetTextSize(0.05);
  //legend ->AddEntry(pions.histo,"Pions","lep");
  //legend ->AddEntry(muons.histo,"Muons","lep");
  //legend ->AddEntry(elecs.histo,"Electrons","lep");
  legend ->AddEntry(fakes.histo,"Fakes","lep");
  legend ->AddEntry(leptons.histo,"Leptons","lep");

  legend->Draw("same");


  TString name = "NLostInnerPlusMiddle";

  c->SaveAs(name + "ForAllBkg_" + selection + ".pdf");
  /*
  delete legend;
  legend =  new TLegend(0.60,0.87,0.9,0.9);
  legend->SetTextSize(0.05);
  legend ->AddEntry(pions.histo,"Pions","lep");
  pions.histo->Draw();
  legend->Draw("same");
  c->SaveAs(name + "ForPions_" + selection + ".pdf");

  delete legend;
  legend =  new TLegend(0.60,0.87,0.9,0.9);
  legend->SetTextSize(0.05);
  legend ->AddEntry(muons.histo,"Muons","lep");
  muons.histo->Draw();
  legend->Draw("same");
  c->SaveAs(name + "ForMuons_" + selection + ".pdf");

  delete legend;
  legend =  new TLegend(0.60,0.87,0.9,0.9);
  legend->SetTextSize(0.05);
  legend ->AddEntry(elecs.histo,"Electrons","lep");
  elecs.histo->Draw();
  legend->Draw("same");
  c->SaveAs(name + "ForElecs_" + selection + ".pdf");

  delete legend;
  legend =  new TLegend(0.60,0.87,0.9,0.9);
  legend->SetTextSize(0.05);
  legend ->AddEntry(fakes.histo,"Fakes","lep");
  fakes.histo->Draw();
  legend->Draw("same");
  c->SaveAs(name + "ForFakes_" + selection + ".pdf");
  */
  //********************************************************************************

  return 0;
 
}

