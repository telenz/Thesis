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
#include "/afs/desy.de/user/t/tlenz/Thesis/rootFiles/plotStyleThesis.h"


TCanvas *drawRatioPlotWithPurity(TH1D *prediction, TH1D *sr, TString xTitle, TString filename, double purity, double ptcut);
void getPoissonIntervalls(double mu1, double mu2);

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
    tree->SetBranchAddress("trackDeDx1",&trackDeDx1);
    tree->SetBranchAddress("trackDeDx2",&trackDeDx2);
    tree->SetBranchAddress("trackDeDx3",&trackDeDx3);
    tree->SetBranchAddress("trackDeDx4",&trackDeDx4);
    tree->SetBranchAddress("trackDx1",&trackDx1);
    tree->SetBranchAddress("trackDx2",&trackDx2);
    tree->SetBranchAddress("trackDx3",&trackDx3);
    tree->SetBranchAddress("trackDx4",&trackDx4);
    tree->SetBranchAddress("trackMeasSize",&trackMeasSize);
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


int makeFakeIasCRSRplots(){

  double ptCut=20;
  double ecaloCut=5;
  double iasCut=0.0;

  sample pred;
  sample SR;
  sample data;

  SR.file   = new TFile("/nfs/dust/cms/user/tlenz/ANALYSIS/workdir/analysis_2015_10_11_METGt0_JetPt70_noBlinding/results/analyzer/ntuples/input_weighted/wjets.root","READ");
  pred.file = new TFile("/nfs/dust/cms/user/tlenz/ANALYSIS/workdir/analysis_2015_08_19_METGt0_JetPt70_FakeCS/results/analyzer/ntuples/input_weighted/wjets.root","READ");

  pred.file   -> GetObject("chiTrackspreselectionNoQCDCutsTrigger/Variables",pred.tree);
  SR.file     -> GetObject("chiTrackspreselectionNoQCDCutsTrigger/Variables",SR.tree);


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


  TeresaPlottingStyle::init();
  gROOT->ForceStyle();

  TString filename = "hASmi_SRbinning_d0Inverted_fakes_";
  filename += Form("ECalaoLe%.0f_",ecaloCut);
  filename += Form("trackPtGt%.0f_",ptCut);

  TCanvas *c2 = drawRatioPlotWithPurity(pred.histoASmi,SR.histoASmi,"dE/dx discriminator (I_{as})",filename + pred.histoASmi->GetName() + "_"  + SR.histoASmi->GetName() + ".pdf" ,pred.purity,ptCut);
 
  return 0;
 
}

//################################################################################################################################
//################################################################################################################################
//################################################################################################################################


//################################################################################################################################
 // Get the 68% confindence interval of mu1/mu2
void getPoissonIntervalls(double mu1, double mu2){

  double result = mu1/mu2;
  TH1D *expHist = new TH1D("mu1/mu2","mu1/mu2",1000,0,1);
  TRandom3 rand1(0);
  TRandom3 rand2(0);

  cout<<"mu1 = "<<mu1<<endl;
  cout<<"mu2 = "<<mu2<<endl;
  cout<<"ratio = "<<result<<endl;

  for(int i=0; i<10000000; i++){

    expHist->Fill(1.*rand1.Poisson(mu1)/rand2.Poisson(mu2));
  }

  // Get now the 68% upper and lower interval
  double errUp  = 0;
  double errLow = 0;
  for(int i=1; i<=expHist->GetNbinsX();i++){

    double upperIntegral = expHist->Integral(i,expHist->GetNbinsX());
    double lowerIntegral = expHist->Integral(1,i);

    if(abs(upperIntegral/expHist->Integral()-0.32)<0.02){
      cout<<"upper bound = "<<expHist->GetBinCenter(i)<<endl;
      errUp = expHist->GetBinCenter(i)-result;
    }
    if(abs(lowerIntegral/expHist->Integral()-0.32)<0.02){
      cout<<"lower bound = "<<expHist->GetBinCenter(i)<<endl;
      errLow = result - expHist->GetBinCenter(i);
    }
  }


  cout<<"error Up = "<<errUp<<endl;
  cout<<"error Low = "<<errLow<<endl;

  TCanvas *c = new TCanvas("cExp","cExp",0,0,500,500);
  expHist->Draw();
}    
//################################################################################################################################
TCanvas *drawRatioPlotWithPurity(TH1D *prediction, TH1D *sr, TString xTitle, TString filename, double purity, double ptcut){
  
  TeresaPlottingStyle::init();

  gStyle->SetMarkerSize(1.0);
  gStyle->SetNdivisions(502,"X");
  gStyle->SetNdivisions(509,"Y");

  TCanvas *c = new TCanvas();

  float y = 0.32;

  TPad *pad1     = new TPad("pad1", "Control Plots 1", 0.01, y, 0.99, 0.99);
  TPad *padRatio = new TPad("rp1", "Ratio1", 0.01, 0.01, 0.99, y-0.02);

  TH1D *ratio = 0;

  ratio = (TH1D*) sr->Clone();
  ratio->Divide(prediction);
  ratio->GetYaxis()->SetTitle((TString) sr->GetTitle() + "/" + (TString) prediction->GetTitle());
  ratio->SetLineColor(kBlack);
  ratio->SetMarkerColor(kBlack);


  padRatio->cd();
  ratio->GetYaxis()->SetRangeUser(0.5,1.5);
  ratio->SetTitleSize(0.15,"XYZ");
  ratio->SetLabelSize(0.13,"XYZ");
  ratio->GetYaxis()->SetTitleOffset(0.5);
  ratio->GetYaxis()->SetTitle("N_{SR}/N_{CR}");
  ratio->GetYaxis()->CenterTitle();
  ratio->GetYaxis()->SetNdivisions(505);
  ratio->Draw();

  // Draw line at one!
  TLine *line = new TLine(0,1,1,1);
  line->SetLineWidth(2);
  line->Draw("same");
  padRatio->Modified();


  TLegend *leg = new TLegend(0.30,0.75,0.85,0.9);
  leg->SetTextSize(0.06);
  leg->AddEntry(sr,"simulated events from SR","pel"); 
  leg->AddEntry(prediction,"simulated events from CR_{I_{as}}^{fake}","pel"); 
  pad1->cd();
  pad1->SetLogy();

  ratio      -> GetXaxis()->SetNdivisions(505);
  prediction -> GetXaxis()->SetNdivisions(505);

  sr->SetLineColor(kRed);
  sr->SetMarkerColor(kRed);
  sr->SetMarkerStyle(20);
  prediction->SetLineColor(kBlack);
  prediction->SetMarkerColor(kBlack);
  prediction->SetMarkerStyle(20);


  prediction->GetYaxis()->SetTitleOffset(0.7);
  prediction->GetXaxis()->SetTitleOffset(0.95);
  prediction->SetTitleSize(0.08,"XYZ");
  prediction->SetLabelSize(0.06,"XYZ");
  prediction->GetYaxis()->SetTitle("a.u.");
  prediction->GetXaxis()->SetTitle("dE/dx discriminator (I_{as})");
  prediction->Draw("e");
  sr->Draw("e same");


  prediction->SetMaximum(1);
  prediction->SetMinimum(0.05);
  leg->Draw("same");


  //***********************
  TLatex*  info   = new TLatex();
  info-> SetNDC();
  info->SetTextSize(0.06);
  TString AuxString = Form("Purity of fakes in CR = %4.1f ",purity*100);
  info->DrawLatex(0.43,0.60,AuxString);

  TLatex*  info1   = new TLatex();
  info1-> SetNDC();
  info1->SetTextSize(0.06);
  AuxString.Form("p_{T}>%4.0fGeV",ptcut);
  info1->DrawLatex(0.43,0.50,AuxString);
  //***********************

  // Draw both pads to canvas
  c->cd();
  pad1->Draw();
  padRatio->SetGridy();
  c -> SetBottomMargin(0.55);
  //c->Modified();
  padRatio->Draw();

  c->SaveAs(filename);

  return c;

}
