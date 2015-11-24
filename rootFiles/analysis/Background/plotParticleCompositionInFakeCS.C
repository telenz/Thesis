#include "TROOT.h"
#include "TFile.h"
#include "TProfile.h"
#include "TH1.h"
#include "TH2.h"
#include "TMath.h"
#include "TGraph.h"
#include "TGraphErrors.h"
#include "TLorentzVector.h"
#include "TString.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TLatex.h"
#include "TROOT.h"
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



TLorentzVector lorentzVector(float pt, float eta, float phi, float energy){
  
  TLorentzVector v4;
  v4.SetPtEtaPhiM(pt,eta,phi,energy);
  
  return v4;
};

class sample{


public:

  TFile *file;
  TTree *tree;

  TH1D* histo;
  TH1D* histoASmiSR;
  TH1D* histoNValidSR;

  int    statistics;
  double purity;

  vector<double> *trackEta;
  vector<double> *trackPt;
  vector<double> *trackPtError;
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
  vector<int>    *trackStatus;
  double weight;
  double weight_xsec_lumi;
  double met;
  double leadingJetPt;
  int nJets;
  double VertexZ;
  int event;


  std::vector<Double_t>  *muonPt;
  std::vector<Double_t>  *muonEt;
  std::vector<Double_t>  *muonPhi;
  std::vector<Double_t>  *muonEta;
  std::vector<Double_t>  *muonChi2;
  std::vector<Double_t>  *muonndof;
  std::vector<Double_t>  *muondB;
  std::vector<Double_t>  *muond0;
  std::vector<Double_t>  *muonVertex_z;
  std::vector<Double_t>  *muonNOfValidMuonHits;
  std::vector<Double_t>  *muonTrackerLayersWithMeas;
  std::vector<Double_t>  *muonNOfValidPixelHits;
  std::vector<Double_t>  *muonNOfMatchedMuonStations;
  std::vector<Double_t>  *muonChargedHadronIso;
  std::vector<Double_t>  *muonNeutralHadronIso;
  std::vector<Double_t>  *muonPhotonIso;
  std::vector<Double_t>  *muonpuChargedHadronIso;
  std::vector<Int_t>  *muonPdgId;
  std::vector<Int_t>  *muonStatus;

  sample(){

    tree=0;
    file=0;
    histo=0;
    statistics=0;
    purity=0;

    trackEta        = 0;
    trackEta        = 0;
    trackPt         = 0;
    trackPtError    = 0;
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
    trackStatus     = 0;
    muonPt = 0;
    muonEt = 0;
    muonPhi = 0;
    muonEta = 0;
    muonChi2 = 0;
    muonndof = 0;
    muondB = 0;
    muond0 = 0;
    muonVertex_z = 0;
    muonNOfValidMuonHits = 0;
    muonTrackerLayersWithMeas = 0;
    muonNOfValidPixelHits = 0;
    muonNOfMatchedMuonStations = 0;
    muonChargedHadronIso = 0;
    muonNeutralHadronIso = 0;
    muonPhotonIso = 0;
    muonpuChargedHadronIso = 0;
    muonPdgId = 0;
    muonStatus = 0;
  };

  void getTreeVariables(bool fakeSelection){
    if(fakeSelection){
      tree->SetBranchAddress("trackEta",&trackEta);
      tree->SetBranchAddress("trackPt",&trackPt);
      tree->SetBranchAddress("trackPtError",&trackPtError);
      tree->SetBranchAddress("trackP",&trackP);
      tree->SetBranchAddress("trackGenPt",&trackGenPt);
      tree->SetBranchAddress("trackCaloIsolation",&trackCaloIso);
      tree->SetBranchAddress("trackIsolation",&trackIsolation);
      tree->SetBranchAddress("trackGenE",&trackGenE);
      tree->SetBranchAddress("trackGenEt",&trackGenEt);
      tree->SetBranchAddress("trackChi2",&trackChi2);
      tree->SetBranchAddress("trackNdof",&trackNdof);
      tree->SetBranchAddress("trackNLostOuter",&trackNLostOuter);
      tree->SetBranchAddress("trackNLostInner",&trackNLostInner);
      tree->SetBranchAddress("trackNLostMiddle",&trackNLostMiddle);
      tree->SetBranchAddress("trackNValid",&trackNValid);
      tree->SetBranchAddress("trackStatus",&trackStatus);
      tree->SetBranchAddress("trackPdgId",&trackPdgId);
      tree->SetBranchAddress("muonPt",&muonPt);
      tree->SetBranchAddress("muonEt",&muonEt);
      tree->SetBranchAddress("muonPhi",&muonPhi);
      tree->SetBranchAddress("muonEta",&muonEta);
      tree->SetBranchAddress("muonChi2",&muonChi2);
      tree->SetBranchAddress("muonndof",&muonndof);
      tree->SetBranchAddress("muondB",&muondB);
      tree->SetBranchAddress("muond0",&muond0);
      tree->SetBranchAddress("muonVertex_z",&muonVertex_z);
      tree->SetBranchAddress("muonNOfValidMuonHits",&muonNOfValidMuonHits);
      tree->SetBranchAddress("muonTrackerLayersWithMeas",&muonTrackerLayersWithMeas);
      tree->SetBranchAddress("muonNOfValidPixelHits",&muonNOfValidPixelHits);
      tree->SetBranchAddress("muonNOfMatchedMuonStations",&muonNOfMatchedMuonStations);
      tree->SetBranchAddress("muonChargedHadronIso",&muonChargedHadronIso);
      tree->SetBranchAddress("muonNeutralHadronIso",&muonNeutralHadronIso);
      tree->SetBranchAddress("muonPhotonIso",&muonPhotonIso);
      tree->SetBranchAddress("muonpuChargedHadronIso",&muonpuChargedHadronIso);
      tree->SetBranchAddress("muonPdgId",&muonPdgId);
      tree->SetBranchAddress("muonStatus",&muonStatus);
    }
    tree->SetBranchAddress("MET",&met);
    tree->SetBranchAddress("njets",&nJets);
    tree->SetBranchAddress("event",&event);
    tree->SetBranchAddress("VertexZ",&VertexZ);
    tree->SetBranchAddress("LeadingJetPt",&leadingJetPt);
    tree->SetBranchAddress("weight",&weight);
    tree->SetBranchAddress("weight_xsec_lumi",&weight_xsec_lumi);
    

  };


  void Selection(bool fakeSelection){

    histo->Sumw2();
    histo->SetTitle("");

    statistics = 0;
    purity=0;

    cout<<"Entries = "<<tree->GetEntries()<<endl;


	  histo -> Fill("Fakes",0);
	  histo -> Fill("p",0);
	  histo -> Fill("#sigma^{+}",0);
	  histo -> Fill("K^{+}",0);
	  histo -> Fill("#pi",0);
	  histo -> Fill("#sigma^{-}",0);
	  histo -> Fill("#gamma",0);
	  histo -> Fill("Others",0);
	
	  histo -> LabelsDeflate("X") ;
	  histo -> GetYaxis() -> SetTitle("a.u");
	  cout<<histo -> GetYaxis() -> GetTitleSize()<<endl;
	  histo -> GetXaxis() -> SetLabelSize(0.07);
	  histo -> GetXaxis() -> LabelsOption("v");
	  histo -> GetXaxis() -> SetLabelOffset(0.007);
	  //histo -> GetXaxis() ->SetTitle("matched generator-level particle");

    for(int n=0; n<tree->GetEntries(); n++){

      tree->GetEntry(n);
     

      if(fakeSelection){


	for(unsigned int i=0; i<trackStatus->size();i++){


	  if(abs(trackEta->at(i))>2.1)                                 continue;
	  if(abs(trackEta->at(i))>1.42 && abs(trackEta->at(i))<1.65 )  continue;
	  if(trackPt->at(i)<30)              continue;	
	  if(trackCaloIso->at(i)>5)          continue;   


	  //weight=1;
	  // weight_xsec_lumi=1;

	  if(trackPdgId->at(i)!=0){
	    //cout<< weight<< endl;
	    //cout<<trackStatus->size()<<endl;
	    //cout<<"trackNValid->at(i) = "<<trackNValid->at(i)<<endl;
	  }


	  if(trackPdgId->at(i)==0){
	    histo -> Fill("Fakes",weight_xsec_lumi*weight);
	  }
	  else if(abs(trackPdgId->at(i))==211){
	    histo -> Fill("#pi",weight_xsec_lumi*weight);
	  }
	  else if(abs(trackPdgId->at(i))==2212){
	    histo -> Fill("p",weight_xsec_lumi*weight);
	  }
	  else if(abs(trackPdgId->at(i))==3222){
	    histo -> Fill("#sigma^{+}",weight_xsec_lumi*weight);
	  }
	  else if(abs(trackPdgId->at(i))==321){
	    histo -> Fill("K^{+}",weight_xsec_lumi*weight);
	  }
	  else if(abs(trackPdgId->at(i))==3112){
	    histo -> Fill("#sigma^{-}",weight_xsec_lumi*weight);
	  }
	  else if(abs(trackPdgId->at(i))==22){
	    histo -> Fill("#gamma",weight_xsec_lumi*weight);
	  }
	  else{
	    histo -> Fill("Others",weight_xsec_lumi*weight);
	  }
	  break;
	}
      }
      else histo -> Fill(0.5,weight_xsec_lumi*weight);
  
    }
  };
};


int plotParticleCompositionInFakeCS(){

  TeresaPlottingStyle::init();

  sample muFakeControlRegion;
  sample eleFakeControlRegion;
  sample muControlRegion;

  muFakeControlRegion.file = new TFile("/nfs/dust/cms/user/tlenz/DYTOLLANALYSIS/workdir/analysis_2015_09_18_FilesOnDcache/results/analyzer/ntuples/input_weighted/dytollAODSIM.root","READ");
  muFakeControlRegion.file -> GetObject("chiTrackspreselectionTightMuons/Variables",muFakeControlRegion.tree);
  muFakeControlRegion.file -> GetObject("chiTracksnoSelectionTightMuons/Variables",muControlRegion.tree);

  muFakeControlRegion.file -> GetObject("chiTrackspreselectionTightElectrons/Variables",eleFakeControlRegion.tree);

  muFakeControlRegion.getTreeVariables(1);
  eleFakeControlRegion.getTreeVariables(1);
  muControlRegion.getTreeVariables(0);

  muFakeControlRegion.histo = new TH1D("muFakeControlRegion","muFakeControlRegion",1,0,1);
  eleFakeControlRegion.histo = new TH1D("eleFakeControlRegion","eleFakeControlRegion",1,0,1);
  muControlRegion.histo = new TH1D("muControlRegion","muControlRegion",1,0,1);
  
  muFakeControlRegion.Selection(1);
  eleFakeControlRegion.Selection(1);
  //muControlRegion.Selection(0);

  double fakeFractionMu  = muFakeControlRegion.histo->Integral(1,1)/muFakeControlRegion.histo->Integral(0,100);
  double fakeFractionEle = eleFakeControlRegion.histo->Integral(1,1)/eleFakeControlRegion.histo->Integral(0,100);
  
  cout<<"###########################################################################"<<endl;
  cout<<"fake fraction  Mu           = "<<fakeFractionMu<<endl; 
  cout<<"fake fraction  ele          = "<<fakeFractionEle<<endl; 
  cout<<"###########################################################################"<<endl;

  // ***** Calculate scaling factor  ************************************************************************

  muFakeControlRegion.histo->Scale(1./muFakeControlRegion.histo->Integral());
  eleFakeControlRegion.histo->Scale(1./eleFakeControlRegion.histo->Integral());
  // ***********************************************************************************************************
  TCanvas *c1 = new TCanvas();
  muFakeControlRegion.histo->SetMaximum(1.);
  muFakeControlRegion.histo->Draw("e");
  TLatex*  info   = new TLatex();
  info-> SetNDC();
  TString AuxString = "Z#rightarrow#mu#mu";
  info->DrawLatex(0.65,0.8,AuxString);
  c1->SaveAs("plots/ParticleCompositionInFakeCS_Mu.pdf");

  TCanvas *c2 = new TCanvas();
  c2->cd();
  eleFakeControlRegion.histo->SetMaximum(1.);
  eleFakeControlRegion.histo->Draw("e");
  info->DrawLatex(0.65,0.8,"Z#rightarrowee");
  c2->SaveAs("plots/ParticleCompositionInFakeCS_Ele.pdf");
  
  return 0;
 
}

//################################################################################################################################
