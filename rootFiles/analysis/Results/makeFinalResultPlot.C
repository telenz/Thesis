#include "TGraphAsymmErrors.h"
#include "TH1.h"
#include "TStyle.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TColor.h"
#include <cmath>
#include <iostream>

int makeFinalResultPlot(){

  gStyle->SetOptStat(0);
  gStyle -> SetPadBottomMargin(0.15);
  gStyle -> SetPadRightMargin(0.05);
  gStyle -> SetLabelSize(0.06,"X");
  gStyle -> SetTitleSize(0.05,"Y");
  gStyle->SetLegendBorderSize(0);
  gStyle->SetPadTickY(1);

  

  double pred[4]       = {19.11 ,24.38, 2.49, 2.57};
  double stat_up[4]    = {3.67  ,4.68 , 0.87, 1.18}; 
  double stat_down[4]  = {2.61  ,3.84 , 0.85, 1.14}; 
  double sys[4]        = {9.35  ,8.93 , 1.98, 1.27}; 
  double measured[4]   = {18,34,0.0001,4};

  double error_y_up[4]   = {0};
  double error_y_down[4] = {0};
  double error_y_sym[4]  = {0};
  double x[4]            = {1,2,3,4};
  double error_x_up[4]   = {0};
  double error_x_down[4] = {0};

  double stat_y_sym[4]  = {0};

  for(int i=0; i<4; i++){

    error_y_up[i]   = sqrt( pow(stat_up[i],2)   + pow(sys[i],2) );
    error_y_down[i] = sqrt( pow(stat_down[i],2) + pow(sys[i],2) );

    error_y_sym[i] = 1/2.*(error_y_up[i]+error_y_down[i]);
    stat_y_sym[i] = 1/2.*(stat_up[i]+stat_down[i]);

    cout<<"error_y_up["<<i<<"] = "<<error_y_up[i]<<endl;
    cout<<"error_y_down["<<i<<"] = "<<error_y_down[i]<<endl;

  }
  
  TCanvas *c1 = new TCanvas("c1","c1",1.618*700,700);

  TH1D* h = new TH1D("result","",1,0,1);
  
  h->Fill("#splitline{30GeV<p_{T}<50GeV}{0.05<I_{as}<0.30}",pred[0]);
  h->Fill("#splitline{p_{T}>50GeV}{0.05<I_{as}<0.30}",pred[1]);
  h->Fill("#splitline{30GeV<p_{T}<50GeV}{0.30<I_{as}<1.00}",pred[2]);
  h->Fill("#splitline{p_{T}>50GeV}{0.30<I_{as}<1.00}",pred[3]);

  h->SetBinError(1,error_y_sym[0]);
  h->SetBinError(2,error_y_sym[1]);
  h->SetBinError(3,error_y_sym[2]);
  h->SetBinError(4,error_y_sym[3]);

  h->GetYaxis()->SetRangeUser(0,40);
  h->GetXaxis()->SetLabelOffset(0.02);
  h->SetLineColor(kWhite);
  TH1D* hPred;
  hPred = (TH1D*) h->Clone(); 
  //  h->SetFillStyle(3001);

  //EColor predColor = kGreen-3;
  EColor predColor = kTeal-1;
  hPred->SetFillColor(predColor);
  hPred->SetLineColor(predColor);
  hPred->GetYaxis()->SetTitle("Number of events");
  hPred->DrawCopy("hist");
  

 
  TH1D* hPredStatUp = (TH1D*) hPred->Clone();
  TH1D* hPredStatDown = (TH1D*) hPred->Clone();
  hPredStatUp->SetBinContent(1,pred[0]+stat_up[0]);
  hPredStatUp->SetBinContent(2,pred[1]+stat_up[1]);
  hPredStatUp->SetBinContent(3,pred[2]+stat_up[2]);
  hPredStatUp->SetBinContent(4,pred[3]+stat_up[3]);
  hPredStatDown->SetBinContent(1,pred[0]-stat_down[0]);
  hPredStatDown->SetBinContent(2,pred[1]-stat_down[1]);
  hPredStatDown->SetBinContent(3,pred[2]-stat_down[2]);
  hPredStatDown->SetBinContent(4,pred[3]-stat_down[3]);

  hPredStatUp->SetFillColor(kGreen);
  hPredStatUp->SetFillStyle(3005);
  hPredStatUp->SetLineColor(kGreen);
  hPredStatDown->SetLineColor(kGreen);
  //hPredStatUp->DrawCopy("hist same");


  
  // hPredStatDown->DrawCopy("hist same");
  h->SetMarkerStyle(20);
  h->SetMarkerSize(0);
  h->SetFillColor(kBlack);
  h->SetFillStyle(3004);
  h->Draw("e2 same");
  /*
  double xErr[4] = {0};
  TGraphAsymmErrors *gStatUnc = new TGraphAsymmErrors(4,x,pred,xErr,xErr,stat_down,stat_up);
  gStatUnc->GetXaxis()->SetBinLabel(1,"#splitline{30GeV<p_{T}<50GeV}{0.05<I_{as}<0.30}");
  gStatUnc->GetXaxis()->SetBinLabel(2,"#splitline{p_{T}>50GeV}{0.05<I_{as}<0.30}");
  gStatUnc->GetXaxis()->SetBinLabel(3,"#splitline{30GeV<p_{T}<50GeV}{0.30<I_{as}<1.00}");
  gStatUnc->GetXaxis()->SetBinLabel(4,"#splitline{p_{T}>50GeV}{0.30<I_{as}<1.00}");
  gStatUnc->SetMarkerStyle(20);
  gStatUnc->SetMarkerSize(1.5);
  gStatUnc->Draw("CP same");
  */

  TH1D* hM = new TH1D("measured","",1,0,1);
  hM->Fill("#splitline{30GeV<p_{T}<50GeV}{0.05<I_{as}<0.30}", measured[0]);
  hM->Fill("#splitline{p_{T}>50GeV}{0.05<I_{as}<0.30}"      , measured[1]);
  hM->Fill("#splitline{30GeV<p_{T}<50GeV}{0.30<I_{as}<1.00}", measured[2]);
  hM->Fill("#splitline{p_{T}>50GeV}{0.30<I_{as}<1.00}"      , measured[3]);

  hM->SetMarkerStyle(20);
  hM->SetMarkerSize(1.5);
  hM->Draw("same p");


  TLegend *leg =  new TLegend(0.52,0.70,0.9,0.9);
  leg->SetFillStyle(0);
  leg->SetTextSize(0.041);
  leg->AddEntry(hPred,"Prediction","f");
  //leg->AddEntry(hPredStatUp,"Statistical uncertainty on prediction","f");
  leg->AddEntry(h,"Total uncertainty on prediction","f");
  leg->AddEntry(hM,"Data","p");

  leg->Draw("same");
  gPad->RedrawAxis();

  c1->SaveAs("FinalResultPlot.pdf");
  //c1->SaveAs("FinalResultPlot.eps");
  //c1->SaveAs("FinalResultPlot.png");


  return 0;
}
