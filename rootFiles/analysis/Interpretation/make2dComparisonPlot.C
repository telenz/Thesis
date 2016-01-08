#include "TCanvas.h"
#include "TH1.h"
#include "TStyle.h"
#include "TGraph.h"
#include "TLatex.h"
#include "TLegend.h"
#include "TLegendEntry.h"
#include "TPaveLabel.h"
#include "TFile.h"
#include "../../plotStyleThesis.h"
#include "TMath.h"

void DTLimit(){

  TeresaPlottingStyle::init();
  gStyle -> SetPadTopMargin(0.10);
  gStyle -> SetPadBottomMargin(0.17);

  gStyle -> SetPadRightMargin(0.17);
  gStyle -> SetPadLeftMargin(0.15);

  //gStyle->SetLineWidth(3);

  TFile *in = new TFile("ObservedLimit.root","READ");
  //TFile *in = new TFile("ObservedLimit_HybridNew.root","READ");
  TGraph *myLimit = 0;
  in -> GetObject("Graph",myLimit);
  //in -> GetObject("Limit_ns",myLimit);
  myLimit ->SetLineColor(kRed);
  myLimit ->SetLineWidth(2);
    
  //=========Macro generated from canvas: lifetimeNs_vs_mass/
  //=========  (Mon Oct 13 04:10:45 2014) by ROOT version5.34/03
   TCanvas *lifetimeNs_vs_mass = new TCanvas("lifetimeNs_vs_mass", "",0,0,600,600);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);

   

   lifetimeNs_vs_mass->SetHighLightColor(2);
   lifetimeNs_vs_mass->Range(-2.564096,-2.0861,638.4615,2.82059);
   lifetimeNs_vs_mass->SetFillColor(0);
   lifetimeNs_vs_mass->SetBorderMode(0);
   lifetimeNs_vs_mass->SetBorderSize(2);
   lifetimeNs_vs_mass->SetLogy();
   lifetimeNs_vs_mass->SetLogz();
   lifetimeNs_vs_mass->SetTickx(1);
   lifetimeNs_vs_mass->SetTicky(0);
   //   lifetimeNs_vs_mass->SetLeftMargin(0.16);
   //lifetimeNs_vs_mass->SetRightMargin(0.06);
   //lifetimeNs_vs_mass->SetTopMargin(0.07);
   //lifetimeNs_vs_mass->SetBottomMargin(0.16);
   lifetimeNs_vs_mass->SetFrameFillStyle(0);
   lifetimeNs_vs_mass->SetFrameBorderMode(0);
   lifetimeNs_vs_mass->SetFrameFillStyle(0);
   lifetimeNs_vs_mass->SetFrameBorderMode(0);
   
   TGraph *graph = new TGraph(74);
   graph->SetName("Graph");
   graph->SetTitle("");
   graph->SetFillColor(88);
   graph->SetLineColor(88);
   graph->SetMarkerColor(88);
   graph->SetMarkerStyle(20);
   
   TH1F *Graph_Graph1 = new TH1F("Graph_Graph1","",100,100,600);
   Graph_Graph1->SetMinimum(0.06);
   Graph_Graph1->SetDirectory(0);

   Graph_Graph1->SetStats(0);
   Graph_Graph1->SetLineStyle(0);
   Graph_Graph1->SetMarkerStyle(20);
   Graph_Graph1->GetXaxis()->SetTitle("m_{#tilde{#chi}^{#pm}_{1}} [GeV]");
   Graph_Graph1->GetXaxis()->SetNdivisions(509);
   Graph_Graph1->GetXaxis()->SetLabelFont(42);
   //Graph_Graph1->GetXaxis()->SetLabelOffset(0.007);
   Graph_Graph1->GetXaxis()->SetLabelSize(0.045);
   Graph_Graph1->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph1->GetXaxis()->SetTitleOffset(1.2);
   Graph_Graph1->GetXaxis()->SetTitleFont(42);
   Graph_Graph1->GetYaxis()->SetTitle("#tau_{#tilde{#chi}^{#pm}_{1}} [ns]");
   Graph_Graph1->GetYaxis()->SetNdivisions(509);
   Graph_Graph1->GetYaxis()->SetLabelFont(42);
   //Graph_Graph1->GetYaxis()->SetLabelOffset(0.007);
   Graph_Graph1->GetYaxis()->SetLabelSize(0.045);
   Graph_Graph1->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph1->GetYaxis()->SetTitleOffset(1.3);
   Graph_Graph1->GetYaxis()->SetTitleFont(42);
   //Graph_Graph1->GetZaxis()->SetNdivisions(509);
   Graph_Graph1->GetZaxis()->SetLabelFont(42);
   Graph_Graph1->GetZaxis()->SetLabelOffset(0.007);
   Graph_Graph1->GetZaxis()->SetLabelSize(0.045);
   Graph_Graph1->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph1->GetZaxis()->SetTitleFont(42);

   graph->SetHistogram(Graph_Graph1);
   
   TFile* out = new TFile("DTLimit.root","RECREATE");
   graph->Draw("ap Y+");
   myLimit ->Draw("same");
   
   //   graph->Draw("l");
   
   graph = new TGraph(37);
   graph->SetName("Graph_ObservedLimit");
   graph->SetTitle("");
   graph->SetLineWidth(2);
   graph->SetMarkerStyle(21);
   graph->SetPoint(0,97.98190467,0.03335668301);
   graph->SetPoint(1,95.80600521,0.06671336602);
   graph->SetPoint(2,151.6632363,0.100070049);
   graph->SetPoint(3,188.1097136,0.133426732);
   graph->SetPoint(4,198.9608054,0.1667834151);
   graph->SetPoint(5,245.0833713,0.2001400981);
   graph->SetPoint(6,272.3907102,0.2334967811);
   graph->SetPoint(7,286.2279769,0.2668534641);
   graph->SetPoint(8,294.9334707,0.3002101471);
   graph->SetPoint(9,303.567882,0.3335668301);
   graph->SetPoint(10,413.7995947,0.6671336602);
   graph->SetPoint(11,462.7530035,1.00070049);
   graph->SetPoint(12,481.5137483,1.33426732);
   graph->SetPoint(13,490.4243497,1.667834151);
   graph->SetPoint(14,495.0681694,2.001400981);
   graph->SetPoint(15,497.6776717,2.334967811);
   graph->SetPoint(16,499.1994661,2.668534641);
   graph->SetPoint(17,499.5345362,3.002101471);
   graph->SetPoint(18,499.7965717,3.335668301);
   graph->SetPoint(19,506.8345723,6.671336602);
   graph->SetPoint(20,487.8096143,10.0070049);
   graph->SetPoint(21,471.8810836,13.3426732);
   graph->SetPoint(22,454.2030397,16.67834151);
   graph->SetPoint(23,433.9178988,20.01400981);
   graph->SetPoint(24,405.175573,23.34967811);
   graph->SetPoint(25,396.507939,26.68534641);
   graph->SetPoint(26,391.5211121,30.02101471);
   graph->SetPoint(27,386.1804603,33.35668301);
   graph->SetPoint(28,306.5420211,66.71336602);
   graph->SetPoint(29,281.9794682,100.070049);
   graph->SetPoint(30,254.6885719,133.426732);
   graph->SetPoint(31,208.1656357,166.7834151);
   graph->SetPoint(32,197.9963849,200.1400981);
   graph->SetPoint(33,195.4301693,233.4967811);
   graph->SetPoint(34,193.2212611,266.8534641);
   graph->SetPoint(35,189.7269789,300.2101471);
   graph->SetPoint(36,186.2748171,333.5668301);


   //Graph_Graph1->SetMaximum(300);
   Graph_Graph1->SetMaximum(1);
   //TLegend* leg = new TLegend(0.17,0.46,0.72,0.6);
   // Full range

   /*
   TLegend* leg = new TLegend(0.17,0.42,0.50,0.62);
   leg->SetTextSize(0.035);
   leg->AddEntry(myLimit,"#splitline{Observed limit, #font[12]{This search}}{                      #scale[0.7]{(19.7 fb^{-1})}}","l");
   leg->AddEntry(graph,"#splitline{Observed limit, #font[12]{Search for }}{#font[12]{disappearing tracks} #scale[0.7]{(19.5 fb^{-1})}}","l");
   leg->Draw();
   */


   // Small range
   TLegend* leg = new TLegend(0.31,0.18,0.7,0.37);
   leg->SetTextSize(0.035);
   leg->AddEntry(myLimit,"#splitline{Observed limit, #font[12]{This search}}{                      #scale[0.7]{(19.7 fb^{-1})}}","l");
   leg->AddEntry(graph,"#splitline{Observed limit, #font[12]{Search for }}{#font[12]{disappearing tracks} #scale[0.7]{(19.5 fb^{-1})}}","l");
   //  leg->AddEntry(myLimit,"Observed limit, #font[12]{This search} #scale[0.7]{(19.7 fb^{-1})}","l");
   //leg->AddEntry(graph,"#splitline{Observed limit, #font[12]{Search for }}{#font[12]{disappearing tracks} #scale[0.7]{(19.5 fb^{-1})}}","l");
   leg->Draw();


   TLatex*  info   = new TLatex();
   info -> SetNDC();
   info->SetTextSize(0.045);
   info->DrawLatex(0.70,0.91,"(8 TeV)");


   // Observed limit
   graph->Draw("l");
   graph->Write();
   out->Close();


   // Draw other axis
   double max = Graph_Graph1->GetMaximum();
   cout<<"max in ns = "<<max<<endl;
   double min = Graph_Graph1->GetMinimum();
   cout<<"min in ns = "<<min<<endl;
   

   double lowEdge  = min*pow(10,-9)*TMath::C()*100;
   double highEdge = max*pow(10,-9)*TMath::C()*100;


   TGaxis *axis = new TGaxis(100, min, 100, max, lowEdge, highEdge,505,"-RG");
   axis->SetTitle("c#tau_{#chi^{#pm}}_{1} [cm]");
   axis->SetTitleOffset(1.17);
   //axis->SetLabelOffset(0.07);
   axis->SetTitleSize(0.06);
   axis->SetTitleFont(42);
   axis->SetLabelSize(0.05);
   axis->SetLabelFont(42);
   axis->Draw("same");




   lifetimeNs_vs_mass->SaveAs("Comparison2dLimits_SmallRange.pdf");
        
 
}
