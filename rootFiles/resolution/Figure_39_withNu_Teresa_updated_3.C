{
//=========Macro generated from canvas: c/Uncertainty on Flavor Composition
//=========  (Fri Dec 12 18:33:36 2014) by ROOT version5.32/00
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
   gre->SetTitle("Uncertainty on Flavor Composition");

   Int_t ci;   // for color index setting
   ci = TColor::GetColor("#0000ff");
   gre->SetLineColor(ci);

   ci = TColor::GetColor("#0000ff");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(22);
   gre->SetMarkerSize(1.3);
   gre->SetPoint(0,28.28113,0.1793782);
   gre->SetPointError(0,0.09022492,0.001619306);
   gre->SetPoint(1,40.49079,0.155096);
   gre->SetPointError(1,0.107226,0.0009751919);
   gre->SetPoint(2,56.94111,0.1298829);
   gre->SetPointError(2,0.1368115,0.0007086813);
   gre->SetPoint(3,77.98094,0.1090205);
   gre->SetPointError(3,0.1445857,0.0004564825);
   gre->SetPoint(4,106.1634,0.09394831);
   gre->SetPointError(4,0.1621922,0.0003549416);
   gre->SetPoint(5,134.8058,0.08448567);
   gre->SetPointError(5,0.1821649,0.0003037943);
   gre->SetPoint(6,162.5494,0.07814059);
   gre->SetPointError(6,0.2042267,0.0002743961);
   gre->SetPoint(7,197.5771,0.07173945);
   gre->SetPointError(7,0.191109,0.0002005175);
   gre->SetPoint(8,244.5113,0.06572635);
   gre->SetPointError(8,0.2259577,0.0001855655);
   gre->SetPoint(9,306.882,0.06043024);
   gre->SetPointError(9,0.2207546,0.0001332977);
   gre->SetPoint(10,426.1901,0.05380417);
   gre->SetPointError(10,0.2687139,0.0001043244);
   gre->SetPoint(11,623.5644,0.04782048);
   gre->SetPointError(11,0.4148892,0.0001161903);
   gre->SetPoint(12,852.8606,0.04452741);
   gre->SetPointError(12,0.6863083,0.0001296721);
   
   TH1F *Graph_Graph1 = new TH1F("Graph_Graph1","Uncertainty on Flavor Composition",100,20,1300);
   Graph_Graph1->SetMinimum(0);
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
   f_gluons->SetChisquare(30.48524);
   f_gluons->SetNDF(9);
   f_gluons->GetXaxis()->SetLabelFont(42);
   f_gluons->GetXaxis()->SetTitleSize(0.05);
   f_gluons->GetXaxis()->SetTitleOffset(1.3);
   f_gluons->GetXaxis()->SetTitleFont(42);
   f_gluons->GetYaxis()->SetLabelFont(42);
   f_gluons->GetYaxis()->SetTitleSize(0.05);
   f_gluons->GetYaxis()->SetTitleOffset(1.4);
   f_gluons->GetYaxis()->SetTitleFont(42);
   f_gluons->SetParameter(0,0.1200628);
   f_gluons->SetParError(0,2.355334);
   f_gluons->SetParLimits(0,0,0);
   f_gluons->SetParameter(1,1.092727);
   f_gluons->SetParError(1,0.01671083);
   f_gluons->SetParLimits(1,0,0);
   f_gluons->SetParameter(2,0.03389142);
   f_gluons->SetParError(2,0.0002287452);
   f_gluons->SetParLimits(2,0,100000);
   f_gluons->SetParameter(3,-0.07838966);
   f_gluons->SetParError(3,0.005712617);
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
   gre->SetPoint(0,28.28113,0.1793782);
   gre->SetPointError(0,0.09022492,0.001619306);
   gre->SetPoint(1,40.49079,0.155096);
   gre->SetPointError(1,0.107226,0.0009751919);
   gre->SetPoint(2,56.94111,0.1298829);
   gre->SetPointError(2,0.1368115,0.0007086813);
   gre->SetPoint(3,77.98094,0.1090205);
   gre->SetPointError(3,0.1445857,0.0004564825);
   gre->SetPoint(4,106.1634,0.09394831);
   gre->SetPointError(4,0.1621922,0.0003549416);
   gre->SetPoint(5,134.8058,0.08448567);
   gre->SetPointError(5,0.1821649,0.0003037943);
   gre->SetPoint(6,162.5494,0.07814059);
   gre->SetPointError(6,0.2042267,0.0002743961);
   gre->SetPoint(7,197.5771,0.07173945);
   gre->SetPointError(7,0.191109,0.0002005175);
   gre->SetPoint(8,244.5113,0.06572635);
   gre->SetPointError(8,0.2259577,0.0001855655);
   gre->SetPoint(9,306.882,0.06043024);
   gre->SetPointError(9,0.2207546,0.0001332977);
   gre->SetPoint(10,426.1901,0.05380417);
   gre->SetPointError(10,0.2687139,0.0001043244);
   gre->SetPoint(11,623.5644,0.04782048);
   gre->SetPointError(11,0.4148892,0.0001161903);
   gre->SetPoint(12,852.8606,0.04452741);
   gre->SetPointError(12,0.6863083,0.0001296721);
   
   TH1F *Graph_Graph_Graph12 = new TH1F("Graph_Graph_Graph12","Uncertainty on Flavor Composition",100,20,1300);
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
   f_gluons->SetChisquare(30.48524);
   f_gluons->SetNDF(9);
   f_gluons->GetXaxis()->SetLabelFont(42);
   f_gluons->GetXaxis()->SetTitleSize(0.05);
   f_gluons->GetXaxis()->SetTitleOffset(1.3);
   f_gluons->GetXaxis()->SetTitleFont(42);
   f_gluons->GetYaxis()->SetLabelFont(42);
   f_gluons->GetYaxis()->SetTitleSize(0.05);
   f_gluons->GetYaxis()->SetTitleOffset(1.4);
   f_gluons->GetYaxis()->SetTitleFont(42);
   f_gluons->SetParameter(0,0.1200628);
   f_gluons->SetParError(0,2.355334);
   f_gluons->SetParLimits(0,0,0);
   f_gluons->SetParameter(1,1.092727);
   f_gluons->SetParError(1,0.01671083);
   f_gluons->SetParLimits(1,0,0);
   f_gluons->SetParameter(2,0.03389142);
   f_gluons->SetParError(2,0.0002287452);
   f_gluons->SetParLimits(2,0,100000);
   f_gluons->SetParameter(3,-0.07838966);
   f_gluons->SetParError(3,0.005712617);
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
   gre->SetPoint(0,28.53471,0.1707737);
   gre->SetPointError(0,0.05247147,0.0008998551);
   gre->SetPoint(1,42.75415,0.1448036);
   gre->SetPointError(1,0.0691239,0.0005780696);
   gre->SetPoint(2,60.88349,0.1218669);
   gre->SetPointError(2,0.08286195,0.0004211929);
   gre->SetPoint(3,82.33892,0.1061628);
   gre->SetPointError(3,0.08749376,0.0002845538);
   gre->SetPoint(4,111.2976,0.09351808);
   gre->SetPointError(4,0.098486,0.0002310135);
   gre->SetPoint(5,139.9201,0.08547507);
   gre->SetPointError(5,0.1116181,0.0002035601);
   gre->SetPoint(6,168.3921,0.07936838);
   gre->SetPointError(6,0.1274219,0.0001880118);
   gre->SetPoint(7,203.1809,0.07381012);
   gre->SetPointError(7,0.1236555,0.000141171);
   gre->SetPoint(8,250.5111,0.06845375);
   gre->SetPointError(8,0.1493061,0.0001345996);
   gre->SetPoint(9,312.9861,0.06349516);
   gre->SetPointError(9,0.1510174,9.935757e-05);
   gre->SetPoint(10,431.6017,0.05802609);
   gre->SetPointError(10,0.1887101,8.124702e-05);
   gre->SetPoint(11,626.8937,0.05306613);
   gre->SetPointError(11,0.3084253,9.594357e-05);
   gre->SetPoint(12,850.08,0.04966067);
   gre->SetPointError(12,0.5267048,0.0001102607);
   
   TH1F *Graph_Graph_uds3 = new TH1F("Graph_Graph_uds3","Jet Energy Resolution for  0.0 < |#eta| <  1.3 (intrinsic)",100,25.63401,932.8192);
   Graph_Graph_uds3->SetMinimum(0.0373381);
   Graph_Graph_uds3->SetMaximum(0.1838859);
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
   f_uds->SetChisquare(23.05505);
   f_uds->SetNDF(9);
   f_uds->GetXaxis()->SetLabelFont(42);
   f_uds->GetXaxis()->SetTitleSize(0.05);
   f_uds->GetXaxis()->SetTitleOffset(1.3);
   f_uds->GetXaxis()->SetTitleFont(42);
   f_uds->GetYaxis()->SetLabelFont(42);
   f_uds->GetYaxis()->SetTitleSize(0.05);
   f_uds->GetYaxis()->SetTitleOffset(1.4);
   f_uds->GetYaxis()->SetTitleFont(42);
   f_uds->SetParameter(0,-1.75828);
   f_uds->SetParError(0,0.1027164);
   f_uds->SetParLimits(0,0,0);
   f_uds->SetParameter(1,1.072798);
   f_uds->SetParError(1,0.01214811);
   f_uds->SetParLimits(1,0,0);
   f_uds->SetParameter(2,0.04064899);
   f_uds->SetParError(2,0.000159262);
   f_uds->SetParLimits(2,0,100000);
   f_uds->SetParameter(3,-0.0718852);
   f_uds->SetParError(3,0.004356437);
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
   gre->SetPoint(0,28.94733,0.1801198);
   gre->SetPointError(0,0.08729926,0.001539291);
   gre->SetPoint(1,42.62347,0.1625904);
   gre->SetPointError(1,0.1103711,0.001060472);
   gre->SetPoint(2,59.81982,0.1420111);
   gre->SetPointError(2,0.1489985,0.0008781423);
   gre->SetPoint(3,81.35113,0.1257821);
   gre->SetPointError(3,0.1571181,0.0006260787);
   gre->SetPoint(4,109.675,0.1146015);
   gre->SetPointError(4,0.1945723,0.0005711411);
   gre->SetPoint(5,137.0338,0.1059813);
   gre->SetPointError(5,0.2472175,0.0005474161);
   gre->SetPoint(6,165.0275,0.1010094);
   gre->SetPointError(6,0.2935894,0.0005420073);
   gre->SetPoint(7,199.6768,0.09621599);
   gre->SetPointError(7,0.2991131,0.000437047);
   gre->SetPoint(8,246.2974,0.09077039);
   gre->SetPointError(8,0.383009,0.0004502484);
   gre->SetPoint(9,306.863,0.08589937);
   gre->SetPointError(9,0.409307,0.0003537967);
   gre->SetPoint(10,425.3751,0.07786496);
   gre->SetPointError(10,0.5274387,0.0003062881);
   gre->SetPoint(11,622.6854,0.06881414);
   gre->SetPointError(11,0.8862693,0.0003539433);
   gre->SetPoint(12,854.314,0.06466981);
   gre->SetPointError(12,1.423674,0.0003955568);
   
   TH1F *Graph_Graph_cb4 = new TH1F("Graph_Graph_cb4","Jet Energy Resolution for  0.0 < |#eta| <  1.3 (intrinsic)",100,25.97403,938.4254);
   Graph_Graph_cb4->SetMinimum(0.05253577);
   Graph_Graph_cb4->SetMaximum(0.1933976);
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
   f_cb->SetChisquare(58.79032);
   f_cb->SetNDF(9);
   f_cb->GetXaxis()->SetLabelFont(42);
   f_cb->GetXaxis()->SetTitleSize(0.05);
   f_cb->GetXaxis()->SetTitleOffset(1.3);
   f_cb->GetXaxis()->SetTitleFont(42);
   f_cb->GetYaxis()->SetLabelFont(42);
   f_cb->GetYaxis()->SetTitleSize(0.05);
   f_cb->GetYaxis()->SetTitleOffset(1.4);
   f_cb->GetYaxis()->SetTitleFont(42);
   f_cb->SetParameter(0,2.225824);
   f_cb->SetParError(0,0.2872681);
   f_cb->SetParLimits(0,0,0);
   f_cb->SetParameter(1,0.4617409);
   f_cb->SetParError(1,0.03407382);
   f_cb->SetParLimits(1,0,0);
   f_cb->SetParameter(2,0.02506808);
   f_cb->SetParError(2,0.006900011);
   f_cb->SetParLimits(2,0,100000);
   f_cb->SetParameter(3,0.3913153);
   f_cb->SetParError(3,0.03502451);
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
   tex = new TLatex(0.2,0.18,"including #nu's in particle jet");
   tex->SetNDC();
   tex->SetTextSize(0.045);
   tex->SetLineWidth(2);
   tex->Draw();
   
   
   c->Modified();
   c->cd();
   c->SetSelected(c);

   c->SaveAs("Figure_39_withNu_Teresa_updated_3.pdf");
}
