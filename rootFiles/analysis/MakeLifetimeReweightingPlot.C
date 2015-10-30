#include "TMath.h"
#include "TF1.h"
#include "TFile.h"
#include "TH1.h"
#include "TCanvas.h"
#include "TStyle.h"
#include "TLegend.h"
#include "TLatex.h"
#include <iostream>
#include "/afs/desy.de/user/t/tlenz/Thesis/rootFiles/plotStyleThesis.h"


void MakeLifetimeReweightingPlot(){

  TeresaPlottingStyle::init();

  TFile *file = new TFile("LifetimeReweighting_m100GeV_From50cmTo10cm.root","READ");

  TH1D *histo = 0;

  //####################################################
  gStyle->SetStatH(0.3);
  gStyle->SetStatW(0.5);
  gStyle->SetOptFit(001);
  gStyle->SetOptStat("e");
  gStyle->SetStatFontSize(0.035);
  //gStyle->SetErrorX(0); 
  //####################################################
  TCanvas *c = new TCanvas("c","c",0,0,500,500);
  c->cd();

  file->GetObject("htrackProperLifetimeReweighted",histo);
  //file->GetObject("chiTrackspreselection/hMet",histo);
  cout<<"Integral      = "<<histo->Integral(1,1000)<<endl;
  cout<<"Entries       = "<<histo->GetEntries()<<endl;
  histo->Scale(1./histo->Integral());
  histo->SetTitle("");
  histo->GetXaxis()->SetTitle("d_{lab}/(#beta#upoint#gamma) [cm]");
  histo->GetYaxis()->SetTitle("a.u.");
  

 
  TF1 *f = new TF1("f","expo",0.,370);  //370
  histo->Rebin(50);
  f->SetParameter(1,10);
  f->SetParameter(2,0.3);
  histo->Fit("f","QIR");

  f->SetLineColor(kGreen+1);
  double ctau      = -1./f->GetParameter(1);
  //double ctauError = TMath::Abs(2*f->GetParError(1)/f->GetParameter(1));
  double ctauErrorHigh = abs((-1.0 / (f->GetParameter(1) + f->GetParError(1))) - ctau);
  double ctauErrorLow  = abs((-1.0 / (f->GetParameter(1) - f->GetParError(1))) - ctau);

  cout<<endl;
  cout<<"ctau = "<<ctau<<" + "<<ctauErrorHigh<<" "<<ctauErrorLow<<endl;;
  cout<<endl;
  cout<<"Chi2/Ndof = "<<f->GetChisquare()/f->GetNDF()<<endl;

  cout<<"histo Mean    = "<<histo->GetMean()<<endl;
  cout<<"Integral      = "<<histo->Integral(1,10)<<endl;
  cout<<"bin content 1 = "<<histo->GetBinContent(1)<<endl;

  //histo->SetStats(kTRUE);
  histo->SetMarkerSize(0.8);
  histo->Draw("ep");
  histo->GetYaxis()->SetRangeUser(0.00000001,2);
  histo->GetXaxis()->SetRangeUser(0,500);
  c->SetLogy();
  f->Draw("same");


  TLatex box;
  box.SetNDC();
  box.DrawLatex(0.5,0.6,Form("Fitted c#tau=%4.2f^{+%4.2f}_{-%4.2f}",ctau,ctauErrorHigh,ctauErrorLow));

  //  TLegend *leg = new TLegend(0.2, 0.2, .8, .8);
  //leg->Add()


  c->SaveAs("10cm.pdf");










}
