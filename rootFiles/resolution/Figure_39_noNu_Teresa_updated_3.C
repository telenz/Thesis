{
//=========Macro generated from canvas: c/Uncertainty on Flavor Composition
//=========  (Fri Dec 12 17:17:46 2014) by ROOT version5.32/00
 gStyle->SetOptStat(0);
 
   gROOT->LoadMacro("tdrstyle_mod14.C");
   setTDRStyle();

   gROOT->LoadMacro("CMS_lumi.C");

   writeExtraText = true;       // if extra text
   extraText  = "Simulation";  // default extra text is "Preliminary"
   lumi_8TeV  = "19.7 fb^{-1}"; // default is "19.7 fb^{-1}"
   lumi_7TeV  = "4.9 fb^{-1}";  // default is "5.1 fb^{-1}"

   int iPeriod = 2;    // 1=7TeV, 2=8TeV, 3=7+8TeV, 7=7+8+13TeV 

   
   TGraphErrors *gre = new TGraphErrors(13);
   gre->SetName("Graph_gluons");
   gre->SetTitle("");

   Int_t ci;   // for color index setting
   ci = TColor::GetColor("#0000ff");
   gre->SetLineColor(ci);

   ci = TColor::GetColor("#0000ff");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(22);
   gre->SetMarkerSize(1.3);
   gre->SetPoint(0,28.27405,0.1784338);
   gre->SetPointError(0,0.08995339,0.001609156);
   gre->SetPoint(1,40.46756,0.1548134);
   gre->SetPointError(1,0.1072888,0.0009734584);
   gre->SetPoint(2,56.9175,0.1295549);
   gre->SetPointError(2,0.1367424,0.0007068475);
   gre->SetPoint(3,77.94772,0.108764);
   gre->SetPointError(3,0.1445774,0.0004553807);
   gre->SetPoint(4,106.131,0.09383455);
   gre->SetPointError(4,0.1622119,0.0003544769);
   gre->SetPoint(5,134.7752,0.08437619);
   gre->SetPointError(5,0.1821467,0.0003034032);
   gre->SetPoint(6,162.511,0.0780185);
   gre->SetPointError(6,0.2042436,0.000273944);
   gre->SetPoint(7,197.5331,0.07166341);
   gre->SetPointError(7,0.1911553,0.0002002895);
   gre->SetPoint(8,244.4692,0.06562423);
   gre->SetPointError(8,0.2259605,0.0001852032);
   gre->SetPoint(9,306.8277,0.06040567);
   gre->SetPointError(9,0.2207522,0.0001332234);
   gre->SetPoint(10,426.1355,0.053764);
   gre->SetPointError(10,0.2687204,0.0001042454);
   gre->SetPoint(11,623.4797,0.04777816);
   gre->SetPointError(11,0.4149198,0.0001160812);
   gre->SetPoint(12,852.7576,0.04447847);
   gre->SetPointError(12,0.6864451,0.0001295259);
   TH1F *Graph_Graph1 = new TH1F("Graph_Graph1","Uncertainty on Flavor Composition",100,20,1300);
   Graph_Graph1->SetMinimum(0.0);
   Graph_Graph1->SetMaximum(0.3);
   Graph_Graph1->SetDirectory(0);
   Graph_Graph1->SetStats(0);
   Graph_Graph1->SetMarkerStyle(20);
   Graph_Graph1->GetXaxis()->SetTitle("p_{T}^{gen. jet} [GeV]");
   Graph_Graph1->GetXaxis()->SetMoreLogLabels();
   Graph_Graph1->GetXaxis()->SetNoExponent();
   Graph_Graph1->GetXaxis()->SetLabelFont(42);
   Graph_Graph1->GetXaxis()->SetTitleSize(0.05);
   Graph_Graph1->GetXaxis()->SetTitleOffset(1.3);
   Graph_Graph1->GetXaxis()->SetTitleFont(42);
   Graph_Graph1->GetYaxis()->SetTitle("#sigma_{JER}");
   Graph_Graph1->GetYaxis()->SetLabelFont(42);
   Graph_Graph1->GetYaxis()->SetTitleSize(0.05);
   Graph_Graph1->GetYaxis()->SetTitleOffset(1.4);
   Graph_Graph1->GetYaxis()->SetTitleFont(42);
   Graph_Graph1->GetZaxis()->SetLabelFont(42);
   Graph_Graph1->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1);
   
   TCanvas* c =tdrCanvas("c",(TH1D*) Graph_Graph1, 2, 11, 1);   
   c->cd();
   c->SetLogx();
   gStyle->SetOptStat(0);
   gStyle->SetOptFit(0);
   
 
   Graph_Graph1->GetYaxis()->SetTitleOffset(1.6);
   Graph_Graph1->GetXaxis()->SetTitleOffset(1.20);
   Graph_Graph1->GetXaxis()->SetNoExponent();
   Graph_Graph1->GetXaxis()->SetMoreLogLabels();
   

   
   TF1 *f_gluons = new TF1("f_gluons","TMath::Sqrt(TMath::Sign(1.,[0])*pow([0]/x,2)+pow([1],2)*pow(x,[3]-1)+pow([2],2))",20,1550);

   ci = TColor::GetColor("#0000ff");
   f_gluons->SetFillColor(ci);
   f_gluons->SetFillStyle(0);

   ci = TColor::GetColor("#0000ff");
   f_gluons->SetLineColor(ci);
   f_gluons->SetLineWidth(2);
   f_gluons->SetChisquare(32.53965);
   f_gluons->SetNDF(9);
   f_gluons->GetXaxis()->SetLabelFont(42);
   f_gluons->GetXaxis()->SetTitleSize(0.05);
   f_gluons->GetXaxis()->SetTitleOffset(1.3);
   f_gluons->GetXaxis()->SetTitleFont(42);
   f_gluons->GetYaxis()->SetLabelFont(42);
   f_gluons->GetYaxis()->SetTitleSize(0.05);
   f_gluons->GetYaxis()->SetTitleOffset(1.4);
   f_gluons->GetYaxis()->SetTitleFont(42);
   f_gluons->SetParameter(0,-0.2626191);
   f_gluons->SetParError(0,1.032378);
   f_gluons->SetParLimits(0,0,0);
   f_gluons->SetParameter(1,1.085549);
   f_gluons->SetParError(1,0.01647671);
   f_gluons->SetParLimits(1,0,0);
   f_gluons->SetParameter(2,0.03380259);
   f_gluons->SetParError(2,0.0002311708);
   f_gluons->SetParLimits(2,0,100000);
   f_gluons->SetParameter(3,-0.07606089);
   f_gluons->SetParError(3,0.005741712);
   f_gluons->SetParLimits(3,-10000,1);
   gre->GetListOfFunctions()->Add(f_gluons);
   gre->Draw("p");
   
   gre = new TGraphErrors(13);
   gre->SetName("Graph_gluons");
   gre->SetTitle("Uncertainty on Flavor Composition");

   ci = TColor::GetColor("#0000ff");
   gre->SetLineColor(ci);

   ci = TColor::GetColor("#0000ff");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(22);
   gre->SetMarkerSize(1.3);
   gre->SetPoint(0,28.27405,0.1784338);
   gre->SetPointError(0,0.08995339,0.001609156);
   gre->SetPoint(1,40.46756,0.1548134);
   gre->SetPointError(1,0.1072888,0.0009734584);
   gre->SetPoint(2,56.9175,0.1295549);
   gre->SetPointError(2,0.1367424,0.0007068475);
   gre->SetPoint(3,77.94772,0.108764);
   gre->SetPointError(3,0.1445774,0.0004553807);
   gre->SetPoint(4,106.131,0.09383455);
   gre->SetPointError(4,0.1622119,0.0003544769);
   gre->SetPoint(5,134.7752,0.08437619);
   gre->SetPointError(5,0.1821467,0.0003034032);
   gre->SetPoint(6,162.511,0.0780185);
   gre->SetPointError(6,0.2042436,0.000273944);
   gre->SetPoint(7,197.5331,0.07166341);
   gre->SetPointError(7,0.1911553,0.0002002895);
   gre->SetPoint(8,244.4692,0.06562423);
   gre->SetPointError(8,0.2259605,0.0001852032);
   gre->SetPoint(9,306.8277,0.06040567);
   gre->SetPointError(9,0.2207522,0.0001332234);
   gre->SetPoint(10,426.1355,0.053764);
   gre->SetPointError(10,0.2687204,0.0001042454);
   gre->SetPoint(11,623.4797,0.04777816);
   gre->SetPointError(11,0.4149198,0.0001160812);
   gre->SetPoint(12,852.7576,0.04447847);
   gre->SetPointError(12,0.6864451,0.0001295259);
   
   TH1F *Graph_Graph_Graph12 = new TH1F("Graph_Graph_Graph12","Uncertainty on Flavor Composition",100,10,1300);
   Graph_Graph_Graph12->SetMinimum(0);
   Graph_Graph_Graph12->SetMaximum(0.5);
   Graph_Graph_Graph12->SetDirectory(0);
   Graph_Graph_Graph12->SetStats(0);
   Graph_Graph_Graph12->SetMarkerStyle(20);
   Graph_Graph_Graph12->GetXaxis()->SetTitle("p_{T}^{ptcl} [GeV]");
   Graph_Graph_Graph12->GetXaxis()->SetMoreLogLabels();
   Graph_Graph_Graph12->GetXaxis()->SetNoExponent();
   Graph_Graph_Graph12->GetXaxis()->SetLabelFont(42);
   Graph_Graph_Graph12->GetXaxis()->SetTitleSize(0.05);
   Graph_Graph_Graph12->GetXaxis()->SetTitleOffset(1.3);
   Graph_Graph_Graph12->GetXaxis()->SetTitleFont(42);
   Graph_Graph_Graph12->GetYaxis()->SetTitle("JER");
   Graph_Graph_Graph12->GetYaxis()->SetLabelFont(42);
   Graph_Graph_Graph12->GetYaxis()->SetTitleSize(0.05);
   Graph_Graph_Graph12->GetYaxis()->SetTitleOffset(1.4);
   Graph_Graph_Graph12->GetYaxis()->SetTitleFont(42);
   Graph_Graph_Graph12->GetZaxis()->SetLabelFont(42);
   Graph_Graph_Graph12->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph_Graph12);
   
   
   TF1 *f_gluons = new TF1("f_gluons","TMath::Sqrt(TMath::Sign(1.,[0])*pow([0]/x,2)+pow([1],2)*pow(x,[3]-1)+pow([2],2))",20,1550);

   ci = TColor::GetColor("#0000ff");
   f_gluons->SetFillColor(ci);
   f_gluons->SetFillStyle(0);

   ci = TColor::GetColor("#0000ff");
   f_gluons->SetLineColor(ci);
   f_gluons->SetLineWidth(2);
   f_gluons->SetChisquare(32.53965);
   f_gluons->SetNDF(9);
   f_gluons->GetXaxis()->SetLabelFont(42);
   f_gluons->GetXaxis()->SetTitleSize(0.05);
   f_gluons->GetXaxis()->SetTitleOffset(1.3);
   f_gluons->GetXaxis()->SetTitleFont(42);
   f_gluons->GetYaxis()->SetLabelFont(42);
   f_gluons->GetYaxis()->SetTitleSize(0.05);
   f_gluons->GetYaxis()->SetTitleOffset(1.4);
   f_gluons->GetYaxis()->SetTitleFont(42);
   f_gluons->SetParameter(0,-0.2626191);
   f_gluons->SetParError(0,1.032378);
   f_gluons->SetParLimits(0,0,0);
   f_gluons->SetParameter(1,1.085549);
   f_gluons->SetParError(1,0.01647671);
   f_gluons->SetParLimits(1,0,0);
   f_gluons->SetParameter(2,0.03380259);
   f_gluons->SetParError(2,0.0002311708);
   f_gluons->SetParLimits(2,0,100000);
   f_gluons->SetParameter(3,-0.07606089);
   f_gluons->SetParError(3,0.005741712);
   f_gluons->SetParLimits(3,-10000,1);
   gre->GetListOfFunctions()->Add(f_gluons);
   gre->Draw(" p");
   
   gre = new TGraphErrors(13);
   gre->SetName("Graph_uds");
   gre->SetTitle("Jet Energy Resolution for  0.0 < |#eta| <  1.3 (intrinsic)");

   ci = TColor::GetColor("#ffcc00");
   gre->SetLineColor(ci);

   ci = TColor::GetColor("#ffcc00");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(33);
   gre->SetMarkerSize(1.5);
   gre->SetPoint(0,28.53312,0.1707895);
   gre->SetPointError(0,0.05246512,0.0008999526);
   gre->SetPoint(1,42.74964,0.1447633);
   gre->SetPointError(1,0.06912354,0.0005778942);
   gre->SetPoint(2,60.87825,0.1217984);
   gre->SetPointError(2,0.08285691,0.0004209531);
   gre->SetPoint(3,82.33052,0.1061306);
   gre->SetPointError(3,0.08750033,0.0002844578);
   gre->SetPoint(4,111.2858,0.09346524);
   gre->SetPointError(4,0.09849883,0.0002308785);
   gre->SetPoint(5,139.9052,0.0854464);
   gre->SetPointError(5,0.1116255,0.0002034923);
   gre->SetPoint(6,168.3773,0.07935002);
   gre->SetPointError(6,0.1274282,0.0001879673);
   gre->SetPoint(7,203.1618,0.07378431);
   gre->SetPointError(7,0.1236651,0.0001411194);
   gre->SetPoint(8,250.4918,0.06842524);
   gre->SetPointError(8,0.1493114,0.000134542);
   gre->SetPoint(9,312.9611,0.06347217);
   gre->SetPointError(9,0.1510145,9.932056e-05);
   gre->SetPoint(10,431.5699,0.05799548);
   gre->SetPointError(10,0.1887101,8.12029e-05);
   gre->SetPoint(11,626.8416,0.05303528);
   gre->SetPointError(11,0.3084764,9.588768e-05);
   gre->SetPoint(12,850.0226,0.0496334);
   gre->SetPointError(12,0.526718,0.0001101981);
   
   TH1F *Graph_Graph_uds3 = new TH1F("Graph_Graph_uds3","Jet Energy Resolution for  0.0 < |#eta| <  1.3 (intrinsic)",100,25.63259,932.7562);
   Graph_Graph_uds3->SetMinimum(0.03730658);
   Graph_Graph_uds3->SetMaximum(0.183906);
   Graph_Graph_uds3->SetDirectory(0);
   Graph_Graph_uds3->SetStats(0);
   Graph_Graph_uds3->SetMarkerStyle(20);
   Graph_Graph_uds3->GetXaxis()->SetTitle("p_{T}^{gen Jet}");
   Graph_Graph_uds3->GetXaxis()->SetLabelFont(42);
   Graph_Graph_uds3->GetXaxis()->SetTitleSize(0.05);
   Graph_Graph_uds3->GetXaxis()->SetTitleOffset(1.3);
   Graph_Graph_uds3->GetXaxis()->SetTitleFont(42);
   Graph_Graph_uds3->GetYaxis()->SetTitle("JER (truth)");
   Graph_Graph_uds3->GetYaxis()->SetLabelFont(42);
   Graph_Graph_uds3->GetYaxis()->SetTitleSize(0.05);
   Graph_Graph_uds3->GetYaxis()->SetTitleOffset(1.4);
   Graph_Graph_uds3->GetYaxis()->SetTitleFont(42);
   Graph_Graph_uds3->GetZaxis()->SetLabelFont(42);
   Graph_Graph_uds3->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph_uds3);
   
   
   TF1 *f_uds = new TF1("f_uds","TMath::Sqrt(TMath::Sign(1.,[0])*pow([0]/x,2)+pow([1],2)*pow(x,[3]-1)+pow([2],2))",20,1550);

   ci = TColor::GetColor("#ffcc00");
   f_uds->SetFillColor(ci);
   f_uds->SetFillStyle(0);

   ci = TColor::GetColor("#ffcc00");
   f_uds->SetLineColor(ci);
   f_uds->SetLineWidth(2);
   f_uds->SetChisquare(22.84103);
   f_uds->SetNDF(9);
   f_uds->GetXaxis()->SetLabelFont(42);
   f_uds->GetXaxis()->SetTitleSize(0.05);
   f_uds->GetXaxis()->SetTitleOffset(1.3);
   f_uds->GetXaxis()->SetTitleFont(42);
   f_uds->GetYaxis()->SetLabelFont(42);
   f_uds->GetYaxis()->SetTitleSize(0.05);
   f_uds->GetYaxis()->SetTitleOffset(1.4);
   f_uds->GetYaxis()->SetTitleFont(42);
   f_uds->SetParameter(0,-1.730786);
   f_uds->SetParError(0,0.1040815);
   f_uds->SetParLimits(0,0,0);
   f_uds->SetParameter(1,1.068038);
   f_uds->SetParError(1,0.01208862);
   f_uds->SetParLimits(1,0,0);
   f_uds->SetParameter(2,0.04058859);
   f_uds->SetParError(2,0.0001596266);
   f_uds->SetParLimits(2,0,100000);
   f_uds->SetParameter(3,-0.0703035);
   f_uds->SetParError(3,0.004355812);
   f_uds->SetParLimits(3,-10000,1);
   gre->GetListOfFunctions()->Add(f_uds);
   gre->Draw(" p");
   
   gre = new TGraphErrors(13);
   gre->SetName("Graph_cb");
   gre->SetTitle("Jet Energy Resolution for  0.0 < |#eta| <  1.3 (intrinsic)");

   ci = TColor::GetColor("#ff0000");
   gre->SetLineColor(ci);

   ci = TColor::GetColor("#ff0000");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(21);
   gre->SetPoint(0,28.64537,0.1699044);
   gre->SetPointError(0,0.08667797,0.001463332);
   gre->SetPoint(1,41.5496,0.1466297);
   gre->SetPointError(1,0.1098157,0.0009508129);
   gre->SetPoint(2,58.13965,0.1235894);
   gre->SetPointError(2,0.1494275,0.0007607449);
   gre->SetPoint(3,79.00253,0.1051427);
   gre->SetPointError(3,0.1588301,0.0005206352);
   gre->SetPoint(4,106.6126,0.09354506);
   gre->SetPointError(4,0.1977871,0.000464038);
   gre->SetPoint(5,133.251,0.08448987);
   gre->SetPointError(5,0.2518061,0.000434482);
   gre->SetPoint(6,160.5031,0.07939456);
   gre->SetPointError(6,0.3011148,0.0004240929);
   gre->SetPoint(7,194.4228,0.07316496);
   gre->SetPointError(7,0.306483,0.0003309268);
   gre->SetPoint(8,239.9141,0.06865638);
   gre->SetPointError(8,0.392908,0.0003396319);
   gre->SetPoint(9,299.097,0.06302993);
   gre->SetPointError(9,0.4186235,0.0002586432);
   gre->SetPoint(10,415.5692,0.05678926);
   gre->SetPointError(10,0.5379964,0.0002226581);
   gre->SetPoint(11,609.9077,0.05037394);
   gre->SetPointError(11,0.9053189,0.0002584891);
   gre->SetPoint(12,838.497,0.04706308);
   gre->SetPointError(12,1.453636,0.0002872281);
   
   TH1F *Graph_Graph_cb4 = new TH1F("Graph_Graph_cb4","Jet Energy Resolution for  0.0 < |#eta| <  1.3 (intrinsic)",100,25.70282,921.0898);
   Graph_Graph_cb4->SetMinimum(0.03431666);
   Graph_Graph_cb4->SetMaximum(0.1838269);
   Graph_Graph_cb4->SetDirectory(0);
   Graph_Graph_cb4->SetStats(0);
   Graph_Graph_cb4->SetMarkerStyle(20);
   Graph_Graph_cb4->GetXaxis()->SetTitle("p_{T}^{gen Jet}");
   Graph_Graph_cb4->GetXaxis()->SetLabelFont(42);
   Graph_Graph_cb4->GetXaxis()->SetTitleSize(0.05);
   Graph_Graph_cb4->GetXaxis()->SetTitleOffset(1.3);
   Graph_Graph_cb4->GetXaxis()->SetTitleFont(42);
   Graph_Graph_cb4->GetYaxis()->SetTitle("JER (truth)");
   Graph_Graph_cb4->GetYaxis()->SetLabelFont(42);
   Graph_Graph_cb4->GetYaxis()->SetTitleSize(0.05);
   Graph_Graph_cb4->GetYaxis()->SetTitleOffset(1.4);
   Graph_Graph_cb4->GetYaxis()->SetTitleFont(42);
   Graph_Graph_cb4->GetZaxis()->SetLabelFont(42);
   Graph_Graph_cb4->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph_cb4);
   
   
   TF1 *f_cb = new TF1("f_cb","TMath::Sqrt(TMath::Sign(1.,[0])*pow([0]/x,2)+pow([1],2)*pow(x,[3]-1)+pow([2],2))",20,1550);

   ci = TColor::GetColor("#ff0000");
   f_cb->SetFillColor(ci);
   f_cb->SetFillStyle(0);

   ci = TColor::GetColor("#ff0000");
   f_cb->SetLineColor(ci);
   f_cb->SetLineWidth(2);
   f_cb->SetChisquare(33.87155);
   f_cb->SetNDF(9);
   f_cb->GetXaxis()->SetLabelFont(42);
   f_cb->GetXaxis()->SetTitleSize(0.05);
   f_cb->GetXaxis()->SetTitleOffset(1.3);
   f_cb->GetXaxis()->SetTitleFont(42);
   f_cb->GetYaxis()->SetLabelFont(42);
   f_cb->GetYaxis()->SetTitleSize(0.05);
   f_cb->GetYaxis()->SetTitleOffset(1.4);
   f_cb->GetYaxis()->SetTitleFont(42);
   f_cb->SetParameter(0,1.796919);
   f_cb->SetParError(0,0.1592058);
   f_cb->SetParLimits(0,0,0);
   f_cb->SetParameter(1,0.7533203);
   f_cb->SetParError(1,0.01758797);
   f_cb->SetParLimits(1,0,0);
   f_cb->SetParameter(2,0.03354797);
   f_cb->SetParError(2,0.0005420358);
   f_cb->SetParLimits(2,0,100000);
   f_cb->SetParameter(3,0.0684522);
   f_cb->SetParError(3,0.009504999);
   f_cb->SetParLimits(3,-10000,1);
   gre->GetListOfFunctions()->Add(f_cb);
   gre->Draw(" p");
   
   TLegend *leg = new TLegend(0.55,0.60,0.9,0.75,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextSize(0.045);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("Graph_gluons","gluons","pl");

   ci = TColor::GetColor("#0000ff");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#0000ff");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(22);
   entry->SetMarkerSize(1.3);
   entry=leg->AddEntry("Graph_uds","uds quarks","pl");

   ci = TColor::GetColor("#ffcc00");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#ffcc00");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(33);
   entry->SetMarkerSize(1.5);
   entry=leg->AddEntry("Graph_cb","cb quarks","pl");

   ci = TColor::GetColor("#ff0000");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#ff0000");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   leg->Draw();
   TLatex *   tex = new TLatex(0.76,0.8,"|#eta| < 1.3");
   tex->SetNDC();
   tex->SetTextSize(0.045);
   tex->SetLineWidth(2);
   tex->Draw();
   tex = new TLatex(0.45,0.86,"Anti-k_{T}, R=0.5 (PF+CHS)");
   tex->SetNDC();
   tex->SetTextSize(0.045);
   tex->SetLineWidth(2);
   tex->Draw();
   tex = new TLatex(0.2,0.18,"excluding #nu's in particle jet");
   tex->SetNDC();
   tex->SetTextSize(0.045);
   tex->SetLineWidth(2);
   tex->Draw();
   
   
   c->Modified();
   c->cd();
   c->SetSelected(c);

   c->SaveAs("Figure_39_noNu_Teresa_updated_3.pdf");


}
