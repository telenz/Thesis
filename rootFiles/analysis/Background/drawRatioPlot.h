#include "../../plotStyleThesis.h"

TCanvas* drawRatioPlot(TH1D *numerator, TH1D *denominator, TString xTitle, TString yTitleRatio, TString legendNum, TString legendDenom, double max = 5, double min=0.05){

  TeresaPlottingStyleRatio::init();
  gROOT->ForceStyle();


  // Change these settings
  denominator->SetMaximum(max);
  denominator->SetMinimum(min);

  
  TCanvas *c = new TCanvas();
  c->cd();

  float y = 0.28;
  TPad *pad1     = new TPad("pad1", "Control Plots 1", 0.01, y, 0.99, 0.99);
  TPad *padRatio = new TPad("rp1", "Ratio1", 0.01, 0.01, 0.99, y);

  TH1D *ratio = 0;
  ratio = (TH1D*) numerator->Clone();
  ratio -> Divide(denominator);
  ratio -> SetLineColor(kBlack);
  //ratio -> GetYaxis() -> SetRangeUser(0.5,1.5);
  ratio -> GetYaxis() -> SetRangeUser(0.0,2);
  ratio -> GetYaxis() -> CenterTitle();

  double titleSize = gStyle->GetTitleSize()*(1-y)/y;
  ratio -> SetTitleSize(titleSize,"XYZ");
  double labelSize = gStyle->GetLabelSize()*(1-y)/y;
  ratio -> SetLabelSize(labelSize,"XYZ");
  ratio -> GetYaxis()->SetTitleOffset(0.45);
  ratio -> GetYaxis()->SetTitle(yTitleRatio);
  ratio -> SetMarkerStyle(20);

  padRatio->cd();
  ratio->Draw();

  // Draw line at one!
  TLine *line = new TLine(0,1,1,1);
  line->SetLineWidth(2);
  line->Draw("same");
  padRatio->Modified();


  TLegend *leg = new TLegend(0.45,0.68,0.85,0.90);   //Lepton Ias plots
  //TLegend *leg = new TLegend(0.28,0.72,0.85,0.90); //Fake Ias plots
  leg ->SetTextSize(0.06);
  leg->AddEntry(numerator,legendNum,"pel"); 
  leg->AddEntry(denominator,legendDenom,"pel"); 


  pad1->cd();
  pad1->SetLogy();
  numerator   -> SetLineColor(kBlack);
  numerator   -> SetMarkerColor(kBlack);
  numerator   -> SetMarkerStyle(24);
  denominator -> SetLineColor(kRed);
  denominator -> SetMarkerColor(kRed);
  denominator -> SetMarkerSize(1.2);
  denominator -> GetYaxis()->SetTitle("a.u.");
  denominator -> GetXaxis()->SetTitle(xTitle);
  denominator -> Draw("e");
  numerator   -> Draw("e same");
  leg         -> Draw("same");

  // Draw both pads to canvas
  c->cd();
  pad1     -> Draw();
  padRatio -> SetGridy();
  padRatio -> Draw();

  return c;

}
