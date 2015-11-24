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
#include "TChain.h"
#include "TRandom3.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include "TPad.h"
#include "drawRatioPlot.h"


class sample{


public:

  TFile *file;
  TTree *tree;

  TH1D* histo;
  TH1D* histoECalo;
  TH1D* histoASmi;
  TH1D* histoNValid;
  TH1D* histoPt;

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


  vector<int>    *trackMeasSize;

  sample(double iasCut){

    tree=0;
    file=0;
    histo=0;
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

    Double_t xbinsECalo[3]  = {0,10,200};
    //Double_t xbinsASmi[5]   = {0,0.1,0.2,0.5,1};
   
    //Double_t xbinsASmi[5]   = {0,0.05,0.1,0.3,1};
    Double_t xbinsNHits[4]  = {3,5,7,25};
    Double_t xbinsPt[6]     = {20,35,50,75,150,2000};

    histoECalo  = new TH1D("predECalo","predECalo",2,xbinsECalo);

    //Double_t xbinsASmi[5]   = {0,0.05,0.1,0.2,1};
    Double_t xbinsASmi[3]   = {0,0.2,1};
    histoASmi   = new TH1D("predASmi","predASmi",2,xbinsASmi);

    histoNValid = new TH1D("predNValid","predNValid",3,xbinsNHits);
    histoPt     = new TH1D("predPt","predPt",5,xbinsPt);
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


  void Selection(bool doMatching, int pdgId, double ptCut=35., double ecaloCut=5.){

    histo->Sumw2();
    histoECalo->Sumw2();
    histoASmi->Sumw2();
    histoNValid->Sumw2();
    histoPt->Sumw2();

    histo->SetTitle("");

    statistics = 0;
    purity     = 0;

    for(int n=0; n<tree->GetEntries(); n++){

      tree->GetEntry(n);

      //if(met<100)                        continue;
      //if(leadingJetPt<70)               continue;
      

      if(abs(trackEta->at(0))>2.1)                                 continue;
      if(abs(trackEta->at(0))>1.42 && abs(trackEta->at(0))<1.65 )  continue;
      if(trackPt->at(0)<ptCut)                                     continue;

      if(trackCaloIso->at(0)>ecaloCut)                                     continue;

             
      // ****************************************** Particle Id **********************************
      purity+=1;
      if(doMatching){
	if(abs(trackPdgId->at(0))!=pdgId)      continue; 
      }
      statistics +=1;
      // ****************************************** Particle Id **********************************

      histoECalo    -> Fill(trackCaloIso->at(0),weight_xsec_lumi*weight);
      histoASmi     -> Fill(trackASmi->at(0));
      histoNValid   -> Fill(trackNValid->at(0),weight_xsec_lumi*weight);
      histoPt       -> Fill(trackPt->at(0),weight_xsec_lumi*weight);
      histo         -> Fill(trackEta->at(0),weight_xsec_lumi*weight);

    }
    
    purity=statistics/purity;
    cout<<"integral = "<<histoASmi->Integral()<<endl;
    if(histoASmi->Integral() !=0)  histoASmi     -> Scale(1./histoASmi->Integral());
  };

  

};


int makeLeptonIasCRSRplots(int pdgId){

  double ptCut    = 20;
  double ecaloCut = 50000;
  double iasCut   = 0.2;

  sample pred(iasCut);
  sample SR(iasCut);
  sample dataCR(iasCut);



  TString process = "wjets";
  SR.file   = new TFile("/nfs/dust/cms/user/tlenz/ANALYSIS/workdir/analysis_2015_10_11_METGt0_JetPt70_noBlinding/results/analyzer/ntuples/input_weighted/wjets.root","READ");


  TString pathToFile = "";
  TString particleType = "";
  if(pdgId==11){
    pathToFile = "/nfs/dust/cms/user/tlenz/ANALYSIS/workdir/analysis_2015_08_19_METGt0_JetPt70_ElectronCS/results/analyzer/ntuples/input_weighted/";
    particleType = "Electrons";
  }
  else if(pdgId==13){
    pathToFile = "/nfs/dust/cms/user/tlenz/ANALYSIS/workdir/analysis_2015_08_19_METGt0_JetPt70_MuonCS/results/analyzer/ntuples/input_weighted/";
    particleType = "Muons";
  }
  else if(pdgId==211){
    pathToFile = "/nfs/dust/cms/user/tlenz/ANALYSIS/workdir/analysis_2015_08_19_METGt0_JetPt70_TauCS/results/analyzer/ntuples/input_weighted/";
    particleType = "Taus";
  }

  pred.file     = new TFile(pathToFile + process + ".root","READ");
  dataCR.file   = new TFile(pathToFile + "data.root","READ");

  TString selection = "chiTrackspreselectionNoQCDCutsNoTrigger";
  pred.file   -> GetObject(selection + "/Variables",pred.tree);
  SR.file     -> GetObject(selection + "/Variables",SR.tree);
  dataCR.file -> GetObject(selection + "/Variables",dataCR.tree);

  SR.getTreeVariables();
  pred.getTreeVariables();
  dataCR.getTreeVariables();
  
  cout<<"1"<<endl;
  int nbins=20;
  double xmin=-2.4;
  double xmax=2.4;
  SR.histo     = new TH1D("SR","SR",nbins,xmin,xmax);
  pred.histo   = new TH1D("pred","pred",nbins,xmin,xmax);
  dataCR.histo = new TH1D("data","data",nbins,xmin,xmax);



  cout<<"MC signal region = "<<endl;
  SR.Selection(1,pdgId,ptCut,ecaloCut);
  cout<<"MC control region = "<<endl;
  pred.Selection(0,pdgId,ptCut,ecaloCut);
  cout<<"Data signal region = "<<endl;
  dataCR.Selection(0,pdgId,ptCut,ecaloCut);

  cout<<"###########################################################################"<<endl;
  cout<<"Statisitcs:"<<endl;
  cout<<"Signal region  = "<<SR.statistics<<endl;
  cout<<"Control region = "<<pred.statistics<<endl;
  cout<<"Purity: Control region = "<<pred.purity<<endl;
  cout<<"###########################################################################"<<endl;
  
  
  TCanvas *c = drawRatioPlot(pred.histoASmi, SR.histoASmi ,"dE/dx discriminator (I_{as})","N_{CR}/N_{SR}","CR_{MC}^{lep veto inverted}","SR_{MC}",10,0.001);
  c->cd();
  TPad* pad = (TPad*) gPad->GetPrimitive("pad1");
  pad->cd();
  TLatex*  info1   = new TLatex();
  info1-> SetNDC();
  info1->SetTextSize(0.06);
  info1->DrawLatex(0.45,0.65,particleType);
  c->SaveAs("plots/hASmi_SRbinning_" + particleType + "_MCCR_MCSR.pdf");


  TCanvas *c1 = drawRatioPlot(pred.histoASmi, dataCR.histoASmi ,"dE/dx discriminator (I_{as})","N_{MC}/N_{Data}","CR_{MC}^{lep veto inverted}","CR_{Data}^{lep veto inverted}",10,0.001);
  c1->cd();
  pad = (TPad*) gPad->GetPrimitive("pad1");
  pad->cd();
  info1   = new TLatex();
  info1-> SetNDC();
  info1->SetTextSize(0.06);
  info1->DrawLatex(0.50,0.65,particleType);
  c1->SaveAs("plots/hASmi_SRbinning_" + particleType + "_MCCR_DataCR.pdf");
 
  return 0;
 
}

//################################################################################################################################
//################################################################################################################################
