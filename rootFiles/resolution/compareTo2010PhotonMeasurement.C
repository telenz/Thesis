{
//=========Macro generated from canvas: cFinal2/cFinal2
//=========  (Mon Nov 24 13:36:31 2014) by ROOT version5.32/00

   gROOT->LoadMacro("tdrstyle_mod14.C");
   setTDRStyle();

   gROOT->LoadMacro("CMS_lumi.C");

   writeExtraText = false;       // if extra text
   extraText  = "";  // default extra text is "Preliminary"
   lumi_8TeV  = ""; // default is "19.7 fb^{-1}"
   lumi_7TeV  = "";  // default is "5.1 fb^{-1}"
   cmsText     = "";

   int iPeriod = 0;    // 1=7TeV, 2=8TeV, 3=7+8TeV, 7=7+8+13TeV 

   // Dijet number 1st occurence - Full uncertainty

   TGraphAsymmErrors *grae = new TGraphAsymmErrors(3);
   grae->SetName("Graph");
   grae->SetTitle("Graph");

   Int_t ci;   // for color index setting
   ci = TColor::GetColor("#cccccc");
   grae->SetFillColor(ci);

   ci = TColor::GetColor("#666666");
   grae->SetLineColor(ci);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(24);
   grae->SetMarkerSize(1.2);
   grae->SetPoint(0,0.55,1.07);
   grae->SetPointError(0,0.55,0.55,0.0385875627,0.0312409987);
   grae->SetPoint(2,1.4,1.10);
   grae->SetPointError(2,0.3,0.3,0.0498196748,0.04384062);
   grae->SetPoint(3,2,1.07);
   grae->SetPointError(3,0.3,0.3,0.06717886572,0.073756355);
   
   TH1F *Graph_GraphD = new TH1F("Graph_Graph1","Graph",100,0,2.3);
   Graph_Graph1->SetMinimum(0.8);
   Graph_Graph1->SetMaximum(1.5);
   Graph_Graph1->SetDirectory(0);
   Graph_Graph1->SetStats(0);
   Graph_Graph1->SetLineStyle(0);
   Graph_Graph1->SetMarkerStyle(20);
   Graph_Graph1->GetXaxis()->SetTitle("|#eta|");
   Graph_Graph1->GetXaxis()->SetNdivisions(505);
   Graph_Graph1->GetXaxis()->SetLabelFont(42);
   Graph_Graph1->GetXaxis()->SetLabelOffset(0.007);
   Graph_Graph1->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph1->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph1->GetXaxis()->SetTitleOffset(0.9);
   Graph_Graph1->GetXaxis()->SetTitleFont(42);
   Graph_Graph1->GetYaxis()->SetTitle("Data/MC ratio");
   Graph_Graph1->GetYaxis()->SetLabelFont(42);
   Graph_Graph1->GetYaxis()->SetLabelOffset(0.007);
   Graph_Graph1->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph1->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph1->GetYaxis()->SetTitleOffset(1.25);
   Graph_Graph1->GetYaxis()->SetTitleFont(42);
   Graph_Graph1->GetZaxis()->SetLabelFont(42);
   Graph_Graph1->GetZaxis()->SetLabelOffset(0.007);
   Graph_Graph1->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph1->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph1->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Graph1);
   
   TCanvas* cNew =tdrCanvas("c1",(TH1D*) Graph_Graph1, 3, 11, 1);
   grae->Draw("a2");
   
   gStyle->SetHatchesLineWidth(1);
   gStyle->SetHatchesSpacing(2.2);   

   // Dijet number 2nd occurence - only statistical ucnertainties
   grae = new TGraphAsymmErrors(3);
   grae->SetName("Res_2011_stat");
   grae->SetTitle("Graph");

   ci = TColor::GetColor("#666666");
   grae->SetFillColor(ci);
  
   ci = TColor::GetColor("#666666");
   grae->SetLineColor(ci);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(24);
   grae->SetMarkerSize(1.1);
   grae->SetPoint(0,0.55,1.07);
   grae->SetPointError(0,0.55,0.55,0.020,0.020);
   grae->SetPoint(2,1.4,1.10);
   grae->SetPointError(2,0.3,0.3,0.031,0.031);
   grae->SetPoint(3,2,1.07);
   grae->SetPointError(3,0.3,0.3,0.048,0.048);
   
   TH1F *Graph_Res_2011_stat2 = new TH1F("Graph_Res_2011_stat2","Graph",100,0,2.3);
   Graph_Res_2011_stat2->SetMinimum(1.0271);
   Graph_Res_2011_stat2->SetMaximum(1.1819);
   Graph_Res_2011_stat2->SetDirectory(0);
   Graph_Res_2011_stat2->SetStats(0);
   Graph_Res_2011_stat2->SetLineStyle(0);
   Graph_Res_2011_stat2->SetMarkerStyle(20);
   Graph_Res_2011_stat2->GetXaxis()->SetTitle("|#eta|");
   Graph_Res_2011_stat2->GetXaxis()->SetNdivisions(505);
   Graph_Res_2011_stat2->GetXaxis()->SetLabelFont(42);
   Graph_Res_2011_stat2->GetXaxis()->SetLabelOffset(0.007);
   Graph_Res_2011_stat2->GetXaxis()->SetLabelSize(0.05);
   Graph_Res_2011_stat2->GetXaxis()->SetTitleSize(0.06);
   Graph_Res_2011_stat2->GetXaxis()->SetTitleOffset(0.9);
   Graph_Res_2011_stat2->GetXaxis()->SetTitleFont(42);
   Graph_Res_2011_stat2->GetYaxis()->SetTitle("Data/MC ratio for JER");
   Graph_Res_2011_stat2->GetYaxis()->SetLabelFont(42);
   Graph_Res_2011_stat2->GetYaxis()->SetLabelOffset(0.007);
   Graph_Res_2011_stat2->GetYaxis()->SetLabelSize(0.05);
   Graph_Res_2011_stat2->GetYaxis()->SetTitleSize(0.06);
   Graph_Res_2011_stat2->GetYaxis()->SetTitleOffset(1.25);
   Graph_Res_2011_stat2->GetYaxis()->SetTitleFont(42);
   Graph_Res_2011_stat2->GetZaxis()->SetLabelFont(42);
   Graph_Res_2011_stat2->GetZaxis()->SetLabelOffset(0.007);
   Graph_Res_2011_stat2->GetZaxis()->SetLabelSize(0.05);
   Graph_Res_2011_stat2->GetZaxis()->SetTitleSize(0.06);
   Graph_Res_2011_stat2->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Res_2011_stat2);
   
   grae->Draw("e");
   
   grae = new TGraphAsymmErrors(4);
   grae->SetName("statPlusSys_2012");
   grae->SetTitle("Graph");

   ci = TColor::GetColor("#cc0066");
   grae->SetFillColor(ci);
   grae->SetFillStyle(3244);

   ci = TColor::GetColor("#cc0066");
   grae->SetLineColor(ci);
   grae->SetLineWidth(2);

   ci = TColor::GetColor("#cc0066");
   grae->SetMarkerColor(ci);
   grae->SetMarkerStyle(20);
   grae->SetMarkerSize(1.2);
   grae->SetPoint(0,0.25,1.066669);
   grae->SetPointError(0,0.25,0.25,0.02761264,0.0278084);
   grae->SetPoint(1,0.8,1.086718);
   grae->SetPointError(1,0.3,0.3,0.04068763,0.04085127);
   grae->SetPoint(2,1.4,1.104164);
   grae->SetPointError(2,0.3,0.3,0.05142933,0.05144749);
   grae->SetPoint(3,2,1.198651);
   grae->SetPointError(3,0.3,0.3,0.08392469,0.08404866);
   
   TH1F *Graph_Graph3 = new TH1F("Graph_Graph3","Graph",100,0,2.53);
   Graph_Graph3->SetMinimum(1.014692);
   Graph_Graph3->SetMaximum(1.307064);
   Graph_Graph3->SetDirectory(0);
   Graph_Graph3->SetStats(0);
   Graph_Graph3->SetLineStyle(0);
   Graph_Graph3->SetMarkerStyle(20);
   Graph_Graph3->GetXaxis()->SetTitle("|#eta|");
   Graph_Graph3->GetXaxis()->SetRange(1,91);
   Graph_Graph3->GetXaxis()->SetLabelFont(42);
   Graph_Graph3->GetXaxis()->SetLabelOffset(0.007);
   Graph_Graph3->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph3->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph3->GetXaxis()->SetTitleOffset(0.9);
   Graph_Graph3->GetXaxis()->SetTitleFont(42);
   Graph_Graph3->GetYaxis()->SetTitle("Data/MC ratio (const fit)");
   Graph_Graph3->GetYaxis()->SetLabelFont(42);
   Graph_Graph3->GetYaxis()->SetLabelOffset(0.007);
   Graph_Graph3->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph3->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph3->GetYaxis()->SetTitleOffset(1.25);
   Graph_Graph3->GetYaxis()->SetTitleFont(42);
   Graph_Graph3->GetZaxis()->SetLabelFont(42);
   Graph_Graph3->GetZaxis()->SetLabelOffset(0.007);
   Graph_Graph3->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph3->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph3->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Graph3);
   
   grae->Draw("2");
   
   // Dijet number 3rd occurence - this is important
   grae = new TGraphAsymmErrors(3);
   grae->SetName("Res_2011_stat");
   grae->SetTitle("Graph");

   ci = TColor::GetColor("#666666");
   grae->SetFillColor(ci);

   ci = TColor::GetColor("#666666");
   grae->SetLineColor(ci);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(24);
   grae->SetMarkerSize(1.1);
   grae->SetPoint(0,0.55,1.07);
   grae->SetPointError(0,0.55,0.55,0.020,0.020);
   grae->SetPoint(2,1.4,1.10);
   grae->SetPointError(2,0.3,0.3,0.031,0.031);
   grae->SetPoint(3,2,1.07);
   grae->SetPointError(3,0.3,0.3,0.048,0.048);
  
   TH1F *Graph_Graph_Res_2011_stat24 = new TH1F("Graph_Graph_Res_2011_stat24","Graph",100,0,2.3);
   Graph_Graph_Res_2011_stat24->SetMinimum(1.0271);
   Graph_Graph_Res_2011_stat24->SetMaximum(1.1819);
   Graph_Graph_Res_2011_stat24->SetDirectory(0);
   Graph_Graph_Res_2011_stat24->SetStats(0);
   Graph_Graph_Res_2011_stat24->SetLineStyle(0);
   Graph_Graph_Res_2011_stat24->SetMarkerStyle(20);
   Graph_Graph_Res_2011_stat24->GetXaxis()->SetTitle("|#eta|");
   Graph_Graph_Res_2011_stat24->GetXaxis()->SetNdivisions(505);
   Graph_Graph_Res_2011_stat24->GetXaxis()->SetLabelFont(42);
   Graph_Graph_Res_2011_stat24->GetXaxis()->SetLabelOffset(0.007);
   Graph_Graph_Res_2011_stat24->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph_Res_2011_stat24->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Res_2011_stat24->GetXaxis()->SetTitleOffset(0.9);
   Graph_Graph_Res_2011_stat24->GetXaxis()->SetTitleFont(42);
   Graph_Graph_Res_2011_stat24->GetYaxis()->SetTitle("Data/MC ratio (const fit)");
   Graph_Graph_Res_2011_stat24->GetYaxis()->SetLabelFont(42);
   Graph_Graph_Res_2011_stat24->GetYaxis()->SetLabelOffset(0.007);
   Graph_Graph_Res_2011_stat24->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Res_2011_stat24->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Res_2011_stat24->GetYaxis()->SetTitleOffset(1.25);
   Graph_Graph_Res_2011_stat24->GetYaxis()->SetTitleFont(42);
   Graph_Graph_Res_2011_stat24->GetZaxis()->SetLabelFont(42);
   Graph_Graph_Res_2011_stat24->GetZaxis()->SetLabelOffset(0.007);
   Graph_Graph_Res_2011_stat24->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Res_2011_stat24->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Res_2011_stat24->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Graph_Res_2011_stat24);
   
   grae->Draw("px");
   
     
   // New thing
   grae = new TGraphAsymmErrors(4);
   grae->SetName("statPlusSys_2012");
   grae->SetTitle("Graph");

   ci = TColor::GetColor("#cc0066");
   grae->SetFillColor(ci);
   grae->SetFillStyle(3244);

   ci = TColor::GetColor("#cc0066");
   grae->SetLineColor(ci);
   grae->SetLineWidth(2);

   ci = TColor::GetColor("#cc0066");
   grae->SetMarkerColor(ci);
   grae->SetMarkerStyle(20);
   grae->SetMarkerSize(1.2);
   grae->SetPoint(0,0.25,1.066669);
   grae->SetPointError(0,0.25,0.25,0.02761264,0.0278084);
   grae->SetPoint(1,0.8,1.086718);
   grae->SetPointError(1,0.3,0.3,0.04068763,0.04085127);
   grae->SetPoint(2,1.4,1.104164);
   grae->SetPointError(2,0.3,0.3,0.05142933,0.05144749);
   grae->SetPoint(3,2,1.198651);
   grae->SetPointError(3,0.3,0.3,0.08392469,0.08404866);
   
   TH1F *Graph_Graph_Graph37 = new TH1F("Graph_Graph_Graph37","Graph",100,0,2.53);
   Graph_Graph_Graph37->SetMinimum(1.014692);
   Graph_Graph_Graph37->SetMaximum(1.307064);
   Graph_Graph_Graph37->SetDirectory(0);
   Graph_Graph_Graph37->SetStats(0);
   Graph_Graph_Graph37->SetLineStyle(0);
   Graph_Graph_Graph37->SetMarkerStyle(20);
   Graph_Graph_Graph37->GetXaxis()->SetTitle("|#eta|");
   Graph_Graph_Graph37->GetXaxis()->SetRange(1,91);
   Graph_Graph_Graph37->GetXaxis()->SetLabelFont(42);
   Graph_Graph_Graph37->GetXaxis()->SetLabelOffset(0.007);
   Graph_Graph_Graph37->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph37->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph37->GetXaxis()->SetTitleOffset(0.9);
   Graph_Graph_Graph37->GetXaxis()->SetTitleFont(42);
   Graph_Graph_Graph37->GetYaxis()->SetTitle("Data/MC ratio for JER");
   Graph_Graph_Graph37->GetYaxis()->SetLabelFont(42);
   Graph_Graph_Graph37->GetYaxis()->SetLabelOffset(0.007);
   Graph_Graph_Graph37->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph37->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph37->GetYaxis()->SetTitleOffset(1.25);
   Graph_Graph_Graph37->GetYaxis()->SetTitleFont(42);
   Graph_Graph_Graph37->GetZaxis()->SetLabelFont(42);
   Graph_Graph_Graph37->GetZaxis()->SetLabelOffset(0.007);
   Graph_Graph_Graph37->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph37->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph37->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Graph_Graph37);
   
   grae->Draw("px");
   
   TGraphErrors *gre = new TGraphErrors(4);
   gre->SetName("Stat_2012");
   gre->SetTitle("Graph");

   ci = TColor::GetColor("#cc0066");
   gre->SetFillColor(ci);
   gre->SetFillStyle(3144);

   ci = TColor::GetColor("#cc0066");
   gre->SetLineColor(ci);
   gre->SetLineWidth(2);

   ci = TColor::GetColor("#cc0066");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(20);
   gre->SetMarkerSize(1.2);
   gre->SetPoint(0,0.25,1.066669);
   gre->SetPointError(0,0.25,0.01292094);
   gre->SetPoint(1,0.8,1.086718);
   gre->SetPointError(1,0.3,0.01287304);
   gre->SetPoint(2,1.4,1.104164);
   gre->SetPointError(2,0.3,0.01671054);
   gre->SetPoint(3,2,1.198651);
   gre->SetPointError(3,0.3,0.03744941);
   
   TH1F *Graph_Graph1 = new TH1F("Graph_Graph1","Graph",100,0,2.53);
   Graph_Graph1->SetMinimum(0.8);
   Graph_Graph1->SetMaximum(1.6);
   Graph_Graph1->SetDirectory(0);
   Graph_Graph1->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1->SetLineColor(ci);
   Graph_Graph1->GetXaxis()->SetTitle("|#eta|");
   Graph_Graph1->GetXaxis()->SetRange(1,91);
   Graph_Graph1->GetXaxis()->SetLabelFont(42);
   Graph_Graph1->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph1->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph1->GetXaxis()->SetTitleFont(42);
   Graph_Graph1->GetYaxis()->SetTitle("Data/MC ratio for JER");
   Graph_Graph1->GetYaxis()->SetLabelFont(42);
   Graph_Graph1->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph1->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph1->GetYaxis()->SetTitleFont(42);
   Graph_Graph1->GetZaxis()->SetLabelFont(42);
   Graph_Graph1->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph1->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph1->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1);
   
   gre->GetYaxis()->SetTitle("Data/MC ratio for JER");
   gre->Draw("e");
   
   TLegend *leg = new TLegend(0.18,0.60,0.55,0.75,NULL,"NDC");
   leg->SetBorderSize(0);
   leg->SetTextSize(0.045);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(0);
   TLegendEntry *entry=leg->AddEntry("Graph","36/pb (7 TeV) #gamma+jet","pfle");

   ci = TColor::GetColor("#cccccc");
   entry->SetFillColor(ci);
   entry->SetFillStyle(1001);

   ci = TColor::GetColor("#666666");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(24);
   entry->SetMarkerSize(1.2);
   entry=leg->AddEntry("statPlusSys_2012","20/fb (8 TeV) #gamma+jet","pfle");

   ci = TColor::GetColor("#cc0066");
   entry->SetFillColor(ci);
   entry->SetFillStyle(3244);

   ci = TColor::GetColor("#cc0066");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);

   ci = TColor::GetColor("#cc0066");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1.2);
   leg->Draw();

   gPad->RedrawAxis();

   CMS_lumi( cNew, iPeriod, 11 );
   cNew->Modified();
   cNew->cd();
   cNew->SetSelected(cNew);

   TLatex*  info   = new TLatex();
   info->SetNDC();
   info->SetTextSize(0.045); 
   info->DrawLatex(0.67,0.83,"Anti-k_{T} R=0.5");
   info->DrawLatex(0.67,0.77,"PF+CHS");
   info->SetTextSize(0.055); 
   //   info->DrawLatex(0.79,0.20,"#gamma+jet");


   cNew->Print("output/ComparisonTo2012_GAMJET.pdf");
}
