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
#include "drawRatioPlot.h"

class sample{
public:

  TFile *file;
  TTree *tree;

  TH1D* histo;
  TH1D* histoASmiSR;
  TH1D* histoASmi;
  TH1D* histoNValidSR;
  TH1D* histoECalo;
  TH1D* histoPt;

  int    statistics;
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
  vector<double> *trackHCALRp5Isolation;
  vector<double> *trackECALRp5Isolation;
  vector<double> *trackHCALRp4Isolation;
  vector<double> *trackECALRp4Isolation;
  vector<double> *trackHCALRp3Isolation;
  vector<double> *trackECALRp3Isolation;
  vector<int>    *trackNLostOuter;
  vector<int>    *trackNLostMiddle;
  vector<int>    *trackNLostInner;
  vector<int>    *trackNValid;
  vector<int>    *trackPdgId;
  double weight;
  double weight_xsec_lumi;
  double met;
  double leadingJetPt;

  vector<double> *trackDeDx1;
  vector<double> *trackDeDx2;
  vector<double> *trackDeDx3;
  vector<double> *trackDeDx4;
  vector<double> *trackDx1;
  vector<double> *trackDx2;
  vector<double> *trackDx3;
  vector<double> *trackDx4;

  vector<int>    *trackMeasSize;

  sample(){

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
    trackHCALRp5Isolation = 0;
    trackECALRp5Isolation = 0;
    trackHCALRp4Isolation = 0;
    trackECALRp4Isolation = 0;
    trackHCALRp3Isolation = 0;
    trackECALRp3Isolation = 0;
    trackNLostOuter = 0;
    trackNLostMiddle = 0;
    trackNLostInner = 0;
    trackNValid     = 0;
    trackPdgId      = 0;
    trackDeDx1   = 0;
    trackDeDx2   = 0;
    trackDeDx3   = 0;
    trackDeDx4   = 0;
    trackDx1   = 0;
    trackDx2   = 0;
    trackDx3   = 0;
    trackDx4   = 0;
    trackMeasSize= 0;
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


  void Selection(bool doMatching, double ptCut, double ecaloCut){

    histo->Sumw2();
    histoASmiSR->Sumw2();
    histoASmi->Sumw2();

    histo->SetTitle("");

    statistics = 0;
    purity=0;

    for(int n=0; n<tree->GetEntries(); n++){

      tree->GetEntry(n);

      if(met<0)                        continue;
      //if(leadingJetPt<70)               continue;


      for(unsigned int i=0; i<trackEta->size(); i++){

	if(abs(trackEta->at(i))>2.1)                                 continue;
	if(abs(trackEta->at(i))>1.42 && abs(trackEta->at(i))<1.65 )  continue;
	if(trackASmi->at(i)<0.0)           continue;
    
	if(trackPt->at(i)<ptCut)          continue;
 	if(trackCaloIso->at(i)>ecaloCut)  continue;

	
      
	// ****************************************** Particle Id **********************************
	if(doMatching){
	  purity+=1;
	  if(abs(trackPdgId->at(i))!=0)      continue; 
	  statistics +=1;
	}
	// ****************************************** Particle Id **********************************
	histo         -> Fill(leadingJetPt,weight_xsec_lumi*weight);
	histoASmiSR   -> Fill(trackASmi->at(i),weight_xsec_lumi*weight);
	histoASmi     -> Fill(trackASmi->at(i),weight_xsec_lumi*weight);
      }
    }

    purity=statistics/purity;
  };
};


int makeFakeIasCRSRplots(double ptCut=20){

  double ecaloCut=5;
  double iasCut=0.2;

  sample pred;
  sample SR;
  sample data;

  SR.file   = new TFile("/nfs/dust/cms/user/tlenz/ANALYSIS/workdir/analysis_2015_10_11_METGt0_JetPt70_noBlinding/results/analyzer/ntuples/input_weighted/wjets.root","READ");
  pred.file = new TFile("/nfs/dust/cms/user/tlenz/ANALYSIS/workdir/analysis_2015_08_19_METGt0_JetPt70_FakeCS/results/analyzer/ntuples/input_weighted/wjets.root","READ");

  pred.file   -> GetObject("chiTrackspreselectionNoQCDCutsNoTrigger/Variables",pred.tree);
  SR.file     -> GetObject("chiTrackspreselectionNoQCDCutsNoTrigger/Variables",SR.tree);


  pred.getTreeVariables();
  SR.getTreeVariables();

  int nbins=15;
  double xmin=50;
  double xmax=300;

  pred.histo = new TH1D("CR","CR",nbins,xmin,xmax);
  SR.histo   = new TH1D("SR","SR",nbins,xmin,xmax);

  Double_t xbinsASmiSR[3]  = {0,iasCut,1};
  Double_t xbinsASmi[5]  = {0,0.1,0.2,0.4,1};
  pred.histoASmiSR   = new TH1D("MC_CR","MC CR",2,xbinsASmiSR);
  pred.histoASmi     = new TH1D("MC_CR","MC CR",4,xbinsASmi);
  SR.histoASmiSR     = new TH1D("MC_SR","MC SR",2,xbinsASmiSR);
  SR.histoASmi       = new TH1D("MC_SR","MC SR",4,xbinsASmi);

  pred.Selection(1,ptCut,ecaloCut);
  SR.Selection(1,ptCut,ecaloCut);
  cout<<"###########################################################################"<<endl;
  cout<<"Statisitcs:"<<endl;
  cout<<"Signal region  = "<<SR.statistics<<endl;
  cout<<"Control region = "<<pred.statistics<<endl;
  cout<<"Purity: Signal region  = "<<SR.purity<<endl;
  cout<<"Purity: Control region = "<<pred.purity<<endl;
  cout<<"###########################################################################"<<endl;


  pred.histo      -> Scale(1./pred.histo->Integral());
  pred.histoASmiSR-> Scale(1./pred.histoASmiSR->Integral());
  pred.histoASmi  -> Scale(1./pred.histoASmi->Integral());
  SR.histo        -> Scale(1./SR.histo->Integral());
  SR.histoASmiSR  -> Scale(1./SR.histoASmiSR->Integral());
  SR.histoASmi    -> Scale(1./SR.histoASmi->Integral());

  TString filename = "";
  filename = "hASmi_SRbinning_fakes_";
  filename += Form("ECalaoLe%.0f_",ecaloCut);
  filename += Form("trackPtGt%.0f",ptCut);
  TCanvas *c = drawRatioPlot(pred.histoASmiSR,SR.histoASmiSR,"dE/dx discriminator (I_{as})","N_{SR}/N_{CR}","simulated events from CR_{I_{as}}^{fake}","simulated events from SR");
  c->cd();
  TPad* pad = (TPad*) gPad->GetPrimitive("pad1");

  pad->cd();
  TLatex*  info   = new TLatex();
  info-> SetNDC();
  info->SetTextSize(0.06);
  TString AuxString = Form("Purity of fakes in CR = %4.1f ",pred.purity*100);
  info->DrawLatex(0.43,0.60,AuxString);
  TLatex*  info1   = new TLatex();
  info1-> SetNDC();
  info1->SetTextSize(0.06);
  AuxString.Form("p_{T}>%4.0fGeV",ptCut);
  info1->DrawLatex(0.43,0.50,AuxString);
  c->SaveAs(filename + ".pdf");


  filename = "hASmi_fakes_";
  filename += Form("ECalaoLe%.0f_",ecaloCut);
  filename += Form("trackPtGt%.0f",ptCut);
  TCanvas *c1 = drawRatioPlot(pred.histoASmi,SR.histoASmi,"dE/dx discriminator (I_{as})","N_{CR}/N_{SR}","simulated events from CR_{I_{as}}^{fake}","simulated events from SR");
  c1->cd();
  pad = (TPad*) gPad->GetPrimitive("pad1");

  pad->cd();
  info   = new TLatex();
  info-> SetNDC();
  info->SetTextSize(0.06);
  AuxString = Form("Purity of fakes in CR = %4.1f ",pred.purity*100);
  info->DrawLatex(0.43,0.60,AuxString);
  info1   = new TLatex();
  info1-> SetNDC();
  info1->SetTextSize(0.06);
  AuxString.Form("p_{T}>%4.0fGeV",ptCut);
  info1->DrawLatex(0.43,0.50,AuxString);
  c1->SaveAs(filename + ".pdf");


  /*
  filename = "hASmi_fakes_";
  filename += Form("ECalaoLe%.0f_",ecaloCut);
  filename += Form("trackPtGt%.0f_",ptCut);
  drawRatioPlotWithPurity(pred.histoASmi,SR.histoASmi,"dE/dx discriminator (I_{as})",filename + pred.histoASmi->GetName() + "_"  + SR.histoASmi->GetName() + ".pdf" ,pred.purity,ptCut);
  */
  return 0;
 
}

//################################################################################################################################
//################################################################################################################################
//################################################################################################################################

//################################################################################################################################
