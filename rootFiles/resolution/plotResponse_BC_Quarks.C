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
#include "../plotStyleThesis.h"

TH1D* GetTH1D(TString filename, TString objectName);
TH2D* GetTH2D(TString filename, TString objectName);



int plotResponse_BC_Quarks(){

  TeresaPlottingStyle::init();
  gStyle->SetMarkerSize(0.001);
  //gStyle->SetMarkerStyle(1);
  gStyle->SetHistLineWidth(3);

  TH1D *histoBC, *histoALL;
  TCanvas* c =  new TCanvas();

  TString pathToFile = "/nfs/dust/cms/user/tlenz/JER_checkoutVersion/JERgammajet/plots_2012/PF_L1CHS/systematicUncertainties/scripts/root_files_FlavorUncertainty/";
   
  TString ptBin = "11";

  histoBC  = GetTH1D(pathToFile + "cb_algo/response_intrinsic_in_" + ptBin + "_Pt_bin_1_eta_bin_1_alpha_bin_PFCHS_mc.root"       , "histo");
  histoALL = GetTH1D(pathToFile + "together_algo/response_intrinsic_in_" + ptBin + "_Pt_bin_1_eta_bin_1_alpha_bin_PFCHS_mc.root" , "histo");
  histoBC  -> Add( GetTH1D(pathToFile + "cb_algo/response_intrinsic_in_" + ptBin + "_Pt_bin_1_eta_bin_2_alpha_bin_PFCHS_mc.root"       , "histo"));
  histoALL -> Add( GetTH1D(pathToFile + "together_algo/response_intrinsic_in_" + ptBin + "_Pt_bin_1_eta_bin_2_alpha_bin_PFCHS_mc.root" , "histo"));
  histoBC  -> Add( GetTH1D(pathToFile + "cb_algo/response_intrinsic_in_" + ptBin + "_Pt_bin_1_eta_bin_3_alpha_bin_PFCHS_mc.root"       , "histo"));
  histoALL -> Add( GetTH1D(pathToFile + "together_algo/response_intrinsic_in_" + ptBin + "_Pt_bin_1_eta_bin_3_alpha_bin_PFCHS_mc.root" , "histo"));
  histoBC  -> Add( GetTH1D(pathToFile + "cb_algo/response_intrinsic_in_" + ptBin + "_Pt_bin_1_eta_bin_4_alpha_bin_PFCHS_mc.root"       , "histo"));
  histoALL -> Add( GetTH1D(pathToFile + "together_algo/response_intrinsic_in_" + ptBin + "_Pt_bin_1_eta_bin_4_alpha_bin_PFCHS_mc.root" , "histo"));
  histoBC  -> Add( GetTH1D(pathToFile + "cb_algo/response_intrinsic_in_" + ptBin + "_Pt_bin_1_eta_bin_5_alpha_bin_PFCHS_mc.root"       , "histo"));
  histoALL -> Add( GetTH1D(pathToFile + "together_algo/response_intrinsic_in_" + ptBin + "_Pt_bin_1_eta_bin_5_alpha_bin_PFCHS_mc.root" , "histo"));
  histoBC  -> Add( GetTH1D(pathToFile + "cb_algo/response_intrinsic_in_" + ptBin + "_Pt_bin_1_eta_bin_6_alpha_bin_PFCHS_mc.root"       , "histo"));
  histoALL -> Add( GetTH1D(pathToFile + "together_algo/response_intrinsic_in_" + ptBin + "_Pt_bin_1_eta_bin_6_alpha_bin_PFCHS_mc.root" , "histo"));
  ptBin="12";
  histoBC  -> Add( GetTH1D(pathToFile + "cb_algo/response_intrinsic_in_" + ptBin + "_Pt_bin_1_eta_bin_1_alpha_bin_PFCHS_mc.root"       , "histo"));
  histoALL -> Add( GetTH1D(pathToFile + "together_algo/response_intrinsic_in_" + ptBin + "_Pt_bin_1_eta_bin_1_alpha_bin_PFCHS_mc.root" , "histo"));
  histoBC  -> Add( GetTH1D(pathToFile + "cb_algo/response_intrinsic_in_" + ptBin + "_Pt_bin_1_eta_bin_2_alpha_bin_PFCHS_mc.root"       , "histo"));
  histoALL -> Add( GetTH1D(pathToFile + "together_algo/response_intrinsic_in_" + ptBin + "_Pt_bin_1_eta_bin_2_alpha_bin_PFCHS_mc.root" , "histo"));
  histoBC  -> Add( GetTH1D(pathToFile + "cb_algo/response_intrinsic_in_" + ptBin + "_Pt_bin_1_eta_bin_3_alpha_bin_PFCHS_mc.root"       , "histo"));
  histoALL -> Add( GetTH1D(pathToFile + "together_algo/response_intrinsic_in_" + ptBin + "_Pt_bin_1_eta_bin_3_alpha_bin_PFCHS_mc.root" , "histo"));
  histoBC  -> Add( GetTH1D(pathToFile + "cb_algo/response_intrinsic_in_" + ptBin + "_Pt_bin_1_eta_bin_4_alpha_bin_PFCHS_mc.root"       , "histo"));
  histoALL -> Add( GetTH1D(pathToFile + "together_algo/response_intrinsic_in_" + ptBin + "_Pt_bin_1_eta_bin_4_alpha_bin_PFCHS_mc.root" , "histo"));
  histoBC  -> Add( GetTH1D(pathToFile + "cb_algo/response_intrinsic_in_" + ptBin + "_Pt_bin_1_eta_bin_5_alpha_bin_PFCHS_mc.root"       , "histo"));
  histoALL -> Add( GetTH1D(pathToFile + "together_algo/response_intrinsic_in_" + ptBin + "_Pt_bin_1_eta_bin_5_alpha_bin_PFCHS_mc.root" , "histo"));
  histoBC  -> Add( GetTH1D(pathToFile + "cb_algo/response_intrinsic_in_" + ptBin + "_Pt_bin_1_eta_bin_6_alpha_bin_PFCHS_mc.root"       , "histo"));
  histoALL -> Add( GetTH1D(pathToFile + "together_algo/response_intrinsic_in_" + ptBin + "_Pt_bin_1_eta_bin_6_alpha_bin_PFCHS_mc.root" , "histo"));
  /*
  ptBin="10";
  histoBC  -> Add( GetTH1D(pathToFile + "cb_algo/response_intrinsic_in_" + ptBin + "_Pt_bin_1_eta_bin_1_alpha_bin_PFCHS_mc.root"       , "histo"));
  histoALL -> Add( GetTH1D(pathToFile + "together_algo/response_intrinsic_in_" + ptBin + "_Pt_bin_1_eta_bin_1_alpha_bin_PFCHS_mc.root" , "histo"));
  histoBC  -> Add( GetTH1D(pathToFile + "cb_algo/response_intrinsic_in_" + ptBin + "_Pt_bin_1_eta_bin_2_alpha_bin_PFCHS_mc.root"       , "histo"));
  histoALL -> Add( GetTH1D(pathToFile + "together_algo/response_intrinsic_in_" + ptBin + "_Pt_bin_1_eta_bin_2_alpha_bin_PFCHS_mc.root" , "histo"));
  //histoBC  -> Add( GetTH1D(pathToFile + "cb_algo/response_intrinsic_in_" + ptBin + "_Pt_bin_1_eta_bin_3_alpha_bin_PFCHS_mc.root"       , "histo"));
  //histoALL -> Add( GetTH1D(pathToFile + "together_algo/response_intrinsic_in_" + ptBin + "_Pt_bin_1_eta_bin_3_alpha_bin_PFCHS_mc.root" , "histo"));
  histoBC  -> Add( GetTH1D(pathToFile + "cb_algo/response_intrinsic_in_" + ptBin + "_Pt_bin_1_eta_bin_4_alpha_bin_PFCHS_mc.root"       , "histo"));
  histoALL -> Add( GetTH1D(pathToFile + "together_algo/response_intrinsic_in_" + ptBin + "_Pt_bin_1_eta_bin_4_alpha_bin_PFCHS_mc.root" , "histo"));
  //histoBC  -> Add( GetTH1D(pathToFile + "cb_algo/response_intrinsic_in_" + ptBin + "_Pt_bin_1_eta_bin_5_alpha_bin_PFCHS_mc.root"       , "histo"));
  //histoALL -> Add( GetTH1D(pathToFile + "together_algo/response_intrinsic_in_" + ptBin + "_Pt_bin_1_eta_bin_5_alpha_bin_PFCHS_mc.root" , "histo"));
  histoBC  -> Add( GetTH1D(pathToFile + "cb_algo/response_intrinsic_in_" + ptBin + "_Pt_bin_1_eta_bin_6_alpha_bin_PFCHS_mc.root"       , "histo"));
  histoALL -> Add( GetTH1D(pathToFile + "together_algo/response_intrinsic_in_" + ptBin + "_Pt_bin_1_eta_bin_6_alpha_bin_PFCHS_mc.root" , "histo"));
  */
  histoALL -> Sumw2();
  histoBC  -> Sumw2();


  double scaling = 1./histoALL->Integral();
  cout<<scaling<<endl;
  histoALL -> Scale(scaling);
  histoBC  -> Scale(scaling);

  histoALL -> Rebin(40);
  histoBC  -> Rebin(40);
  histoALL -> SetTitle("");
  histoALL -> GetXaxis()->SetTitle("p_{T}^{reco. jet}/p_{T}^{gen. jet}");
  histoALL -> GetYaxis()->SetTitle("a.u.");

  histoALL->GetXaxis()->SetRangeUser(0,2);
  histoALL->SetMaximum(9.);
  histoALL->SetMinimum(0.00001);

  c -> cd();
  c -> SetLogy();

  histoALL -> Draw("E");
  //Color_t color = kBlack;
  //Color_t color = kTeal-1;
  cout<< histoALL -> GetLineColor()<<endl;
  //histoALL -> SetMarkerColor(color);
  //histoALL -> SetLineColor(color);

  Color_t color2 = 867;
  histoBC  -> SetMarkerColor(color2);
  histoBC  -> SetLineColor(color2);

  histoBC  -> Draw("E same");

  TLegend *leg = new TLegend(0.3,0.78,0.9,0.92);
  leg->SetTextSize(0.05);
  leg->AddEntry(histoALL,"all jet flavours","lep"); 
  leg->AddEntry(histoBC,"only b- and c-quark jets","pel"); 
  leg->Draw();


  /*
  TLatex* info = new TLatex();
  info-> SetNDC();
  c->cd();
  TString AuxString = "m_{#chi^{#pm}} = 200 GeV";
  info->DrawLatex(0.4,0.7,AuxString);
  AuxString = "#Delta m(#chi^{#pm}, #chi^{0}) #approx 150 MeV";
  info->DrawLatex(0.4,0.6,AuxString);
  */
  TLatex* info = new TLatex();
  info-> SetNDC();
  info->SetTextSize(0.05);
  info -> DrawLatex(0.7, 0.95, "Simulation");
  c->SaveAs("output/intrinsicExampleContributionofBCQuarks.pdf");

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


//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
