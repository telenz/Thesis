#include <fstream>
#include "TROOT.h"
#include "TInterpreter.h"
#include "TApplication.h"
#include "TDirectory.h"
#include "TCanvas.h"
#include "TFile.h"
#include "TKey.h"
#include "TH1.h"
#include "TH2.h"
#include "TH3.h"
#include "TMath.h"
#include "TStyle.h"
#include "TLine.h"
#include "TText.h"
#include "plotStyleThesis.h"



void plotTH2(TH1* histo, TString xTitle,TString yTitle, TString filename);

void plotTrackReconstructionEfficiency(TString zoom="Zoom"){
  TeresaPlottingStyle2d::init();

  TFile *f = new TFile("~/PlotsForThesis/VBF-LS-tau-tools/drawHist/input_Met100/input_weighted/Madgraph_signal_mass_100_ctau_100cm.root","READ");
  TH2D *allTracks;
  TH2D *foundTracks;

  f->GetObject("chiTracksnoSelection/hAllTracksZRho",allTracks);
  f->GetObject("chiTracksnoSelection/hFoundTracksZRho",foundTracks);


  allTracks   -> RebinX(5);
  //allTracks   -> RebinY(2);
  foundTracks -> RebinX(5);
  //foundTracks -> RebinY(2);



  if(zoom.Contains("Zoom")){

       foundTracks->GetXaxis()->SetRangeUser(0,300);
       foundTracks->GetYaxis()->SetRangeUser(0,120);
       allTracks->GetXaxis()->SetRangeUser(0,300);
       allTracks->GetYaxis()->SetRangeUser(0,120);
     }

  
  //plotTH2(foundTracks, "z [cm]", "rho [cm]", "nFoundTracks"+zoom);
  //plotTH2(allTracks, "z [cm]", "rho [cm]", "nAllTracks" +zoom);
  foundTracks->Divide(allTracks);
  plotTH2(foundTracks, "z [cm]", "#rho [cm]", "RecoEffTracks" +zoom);


  

}


void plotTH1(TH1* histo, TString xTitle, TString filename){

  TCanvas *c = new TCanvas("c"+filename,"c"+filename,0,0,500,500);
  c->cd();
  histo->GetXaxis()->SetTitle(xTitle);
  histo->Draw();
  c->SaveAs(filename + ".pdf");

}

void plotTH2(TH1* histo, TString xTitle,TString yTitle, TString filename){

  TCanvas *c = new TCanvas("c"+filename,"c"+filename,0,0,500,500);
  c->cd();
  histo->GetXaxis()->SetTitle(xTitle);
  histo->GetYaxis()->SetTitle(yTitle);
  histo->GetZaxis()->SetTitle("reconstruction efficiency");
  histo->Draw("COLZ");

  TLine *layer1 = new TLine (0., 4.4, 20., 4.4);
  TLine *layer2 = new TLine (0., 7.3, 20., 7.3);
  TLine *layer3 = new TLine (0., 10.2,20., 10.2);
  layer1->SetLineWidth(3.0);
  layer2->SetLineWidth(3.0);
  layer3->SetLineWidth(3.0);
  layer1->Draw("same");
  layer2->Draw("same");
  layer3->Draw("same");

  TText *text = new TText(.62,.96,"Simulation");
  text -> SetNDC();
  text -> SetTextSize(0.040);
  text -> Draw("same");

  c->SaveAs( filename + ".pdf");
  c->SaveAs( filename + ".png");

}
