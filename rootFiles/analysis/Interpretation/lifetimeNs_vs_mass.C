#include "TCanvas.h"
#include "TH1.h"
#include "TStyle.h"
#include "TGraph.h"
#include "TLegend.h"
#include "TLegendEntry.h"
#include "TPaveLabel.h"
#include "TFile.h"

void DTLimit(){
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
   lifetimeNs_vs_mass->SetTicky(1);
   lifetimeNs_vs_mass->SetLeftMargin(0.16);
   lifetimeNs_vs_mass->SetRightMargin(0.06);
   lifetimeNs_vs_mass->SetTopMargin(0.07);
   lifetimeNs_vs_mass->SetBottomMargin(0.16);
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
   /*
   graph->SetPoint(0,99.12051244,0.03335668301);
   graph->SetPoint(1,104.9023378,0.06671336602);
   graph->SetPoint(2,169.368725,0.100070049);
   graph->SetPoint(3,195.3469495,0.133426732);
   graph->SetPoint(4,233.9902021,0.1667834151);
   graph->SetPoint(5,273.3781666,0.2001400981);
   graph->SetPoint(6,290.4609809,0.2334967811);
   graph->SetPoint(7,299.1111142,0.2668534641);
   graph->SetPoint(8,321.3831888,0.3002101471);
   graph->SetPoint(9,348.0699254,0.3335668301);
   graph->SetPoint(10,454.4939423,0.6671336602);
   graph->SetPoint(11,490.2495519,1.00070049);
   graph->SetPoint(12,512.2142844,1.33426732);
   graph->SetPoint(13,535.3899621,1.667834151);
   graph->SetPoint(14,548.2327259,2.001400981);
   graph->SetPoint(15,553.1642774,2.334967811);
   graph->SetPoint(16,562.8494575,2.668534641);
   graph->SetPoint(17,561.5941329,3.002101471);
   graph->SetPoint(18,563.7023694,3.335668301);
   graph->SetPoint(19,561.4264806,6.671336602);
   graph->SetPoint(20,533.2501125,10.0070049);
   graph->SetPoint(21,510.0407014,13.3426732);
   graph->SetPoint(22,492.3116629,16.67834151);
   graph->SetPoint(23,480.758022,20.01400981);
   graph->SetPoint(24,469.2652991,23.34967811);
   graph->SetPoint(25,457.2843364,26.68534641);
   graph->SetPoint(26,439.9268566,30.02101471);
   graph->SetPoint(27,426.7404048,33.35668301);
   graph->SetPoint(28,362.8027602,66.71336602);
   graph->SetPoint(29,298.9317298,100.070049);
   graph->SetPoint(30,288.1853863,133.426732);
   graph->SetPoint(31,271.394774,166.7834151);
   graph->SetPoint(32,252.2097613,200.1400981);
   graph->SetPoint(33,242.3838985,233.4967811);
   graph->SetPoint(34,201.4478662,266.8534641);
   graph->SetPoint(35,199.437787,300.2101471);
   graph->SetPoint(36,196.7931209,333.5668301);
   */
   /*
   graph->SetPoint(37,107.9535573,333.5668301);
   graph->SetPoint(38,139.2958895,300.2101471);
   graph->SetPoint(39,160.7356702,266.8534641);
   graph->SetPoint(40,174.88178,233.4967811);
   graph->SetPoint(41,185.1903282,200.1400981);
   graph->SetPoint(42,192.4729833,166.7834151);
   graph->SetPoint(43,196.8851977,133.426732);
   graph->SetPoint(44,219.7224511,100.070049);
   graph->SetPoint(45,279.0784393,66.71336602);
   graph->SetPoint(46,344.3722899,33.35668301);
   graph->SetPoint(47,355.7149993,30.02101471);
   graph->SetPoint(48,364.8442551,26.68534641);
   graph->SetPoint(49,375.3213654,23.34967811);
   graph->SetPoint(50,383.7189195,20.01400981);
   graph->SetPoint(51,391.8750195,16.67834151);
   graph->SetPoint(52,398.766016,13.3426732);
   graph->SetPoint(53,432.4405037,10.0070049);
   graph->SetPoint(54,462.2288517,6.671336602);
   graph->SetPoint(55,469.6943959,3.335668301);
   graph->SetPoint(56,468.1641999,3.002101471);
   graph->SetPoint(57,468.9355605,2.668534641);
   graph->SetPoint(58,465.8911882,2.334967811);
   graph->SetPoint(59,462.088195,2.001400981);
   graph->SetPoint(60,454.4430167,1.667834151);
   graph->SetPoint(61,441.4563876,1.33426732);
   graph->SetPoint(62,411.1503982,1.00070049);
   graph->SetPoint(63,379.3651017,0.6671336602);
   graph->SetPoint(64,284.278749,0.3335668301);
   graph->SetPoint(65,275.438998,0.3002101471);
   graph->SetPoint(66,262.0841224,0.2668534641);
   graph->SetPoint(67,238.7763834,0.2334967811);
   graph->SetPoint(68,199.8534645,0.2001400981);
   graph->SetPoint(69,193.2513774,0.1667834151);
   graph->SetPoint(70,175.3663084,0.133426732);
   graph->SetPoint(71,128.5311084,0.100070049);
   //graph->SetPoint(72,90.96473593,0.06671336602);
   //graph->SetPoint(73,90.30532969,0.03335668301);
   */
   
   TH1F *Graph_Graph1 = new TH1F("Graph_Graph1","",100,100,600);
   Graph_Graph1->SetMinimum(0.05);
   Graph_Graph1->SetMaximum(300);
   Graph_Graph1->SetDirectory(0);
   /*
   Graph_Graph1->SetStats(0);
   Graph_Graph1->SetLineStyle(0);
   Graph_Graph1->SetMarkerStyle(20);
   Graph_Graph1->GetXaxis()->SetTitle("m_{#tilde{#chi}^{#pm}_{1}} [GeV]");
   Graph_Graph1->GetXaxis()->SetNdivisions(509);
   Graph_Graph1->GetXaxis()->SetLabelFont(42);
   Graph_Graph1->GetXaxis()->SetLabelOffset(0.007);
   Graph_Graph1->GetXaxis()->SetLabelSize(0.045);
   Graph_Graph1->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph1->GetXaxis()->SetTitleOffset(1.1);
   Graph_Graph1->GetXaxis()->SetTitleFont(42);
   Graph_Graph1->GetYaxis()->SetTitle("#tau_{#tilde{#chi}^{#pm}_{1}} [ns]");
   Graph_Graph1->GetYaxis()->SetNdivisions(509);
   Graph_Graph1->GetYaxis()->SetLabelFont(42);
   Graph_Graph1->GetYaxis()->SetLabelOffset(0.007);
   Graph_Graph1->GetYaxis()->SetLabelSize(0.045);
   Graph_Graph1->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph1->GetYaxis()->SetTitleOffset(1.23);
   Graph_Graph1->GetYaxis()->SetTitleFont(42);
   Graph_Graph1->GetZaxis()->SetNdivisions(509);
   Graph_Graph1->GetZaxis()->SetLabelFont(42);
   Graph_Graph1->GetZaxis()->SetLabelOffset(0.007);
   Graph_Graph1->GetZaxis()->SetLabelSize(0.045);
   Graph_Graph1->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph1->GetZaxis()->SetTitleFont(42);
   */
   graph->SetHistogram(Graph_Graph1);
   
   TFile* out = new TFile("DTLimit.root","RECREATE");
   graph->Draw("ap");
   
   //   graph->Draw("l");
   
   graph = new TGraph(37);
   graph->SetName("Graph_ObservedLimit");
   graph->SetTitle("");
   graph->SetLineWidth(5);
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
   
 
   // Observed limit
   graph->Draw("l");

   graph->Write();
   out->Close();
        
 
}
