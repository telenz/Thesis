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
#include "TH3.h"
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
TH3* GetTH3(TString filename, TString objectName);


int plotDiscrimTemplates(TString file="data"){

  TeresaPlottingStyle2d::init();
  gStyle->SetOptStat(0);
  gStyle->SetOptStat("");
  TH3F *h;

  if(file=="data"){   
    h = (TH3F*) GetTH3("Discrim_template_pixel_data_2012.root","Charge_Vs_Path");
  }
  else{
    h = (TH3F*) GetTH3("Discrim_template_pixel_mc_2012.root","Charge_Vs_Path");
  }

  h->GetXaxis()->SetTitle("pt");
  h->GetYaxis()->SetTitle("dx");
  h->GetZaxis()->SetTitle("dE");
   
  cout<<"nbins x = "<<h->GetNbinsX()<<endl;
  cout<<"nbins y = "<<h->GetNbinsY()<<endl;
  cout<<"nbins z = "<<h->GetNbinsZ()<<endl;

  TH2F* histo;
  histo = (TH2F*) h->Project3D("zy");

  histo->GetXaxis()->SetTitle("pathlength [mm]");
  histo->GetYaxis()->SetTitle("#Delta E/#Delta x [ADC/mm]");
  histo->SetTitle("");
  histo->GetYaxis()->SetRangeUser(0,1000);



  //histo->Scale(1./histo->Integral());
  histo->ComputeIntegral();
  Double_t *integral = histo->GetIntegral();
  histo->SetContent(integral);


  //histo->GetXaxis()->SetNdivisions(804);
  //histo->GetYaxis()->SetNdivisions(1005);

  //histo->GetXaxis()->SetNoExponent(kTRUE);

  
  TCanvas *canvas1 = new TCanvas("c","c",500,0,500,500);
  canvas1 ->cd();

  histo ->Draw("COLZ");

  if(file=="data"){   
    canvas1->SaveAs("Discriminator_template_data_pixel_2012.pdf");
    canvas1->SaveAs("Discriminator_template_data_pixel_2012.png");
  }
  else{
    canvas1->SaveAs("Discriminator_template_mc_pixel_2012.pdf");
    canvas1->SaveAs("Discriminator_template_mc_pixel_2012.png");
  }

  return 0;
		 
}

int plotIasDistribution(){

  TeresaPlottingStyle2d::init();
  gStyle->SetOptStat(0);
  gStyle->SetOptStat("");
  TH3F *hData;
  TH3F *hMC;

  hData = (TH3F*) GetTH3("Discrim_template_pixel_data_2012.root","Charge_Vs_Path");
  hMC   = (TH3F*) GetTH3("Discrim_template_pixel_mc_2012.root","Charge_Vs_Path");

 
  TH2F* histoData;
  TH2F* histoMC;
  histoData = (TH2F*) hData->Project3D("zy");
  histoMC   = (TH2F*) hMC->Project3D("zy");

  TH1F* histoData1d;
  TH1F* histoMC1d;

  histoData1d = (TH1F*) histoData->ProjectionY("bla");

  histoData1d->Draw();
  /*
  histo->GetXaxis()->SetTitle("pathlength [mm]");
  histo->GetYaxis()->SetTitle("#Delta E/#Delta x [ADC/mm]");
  histo->SetTitle("");
  histo->GetYaxis()->SetRangeUser(0,1000);



  //histo->Scale(1./histo->Integral());
  histo->ComputeIntegral();
  Double_t *integral = histo->GetIntegral();
  histo->SetContent(integral);


  //histo->GetXaxis()->SetNdivisions(804);
  //histo->GetYaxis()->SetNdivisions(1005);

  //histo->GetXaxis()->SetNoExponent(kTRUE);

  
  TCanvas *canvas1 = new TCanvas("c","c",500,0,500,500);
  canvas1 ->cd();

  histo ->Draw("COLZ");

  if(file=="data"){   
    canvas1->SaveAs("Discriminator_template_data_pixel_2012.pdf");
    canvas1->SaveAs("Discriminator_template_data_pixel_2012.png");
  }
  else{
    canvas1->SaveAs("Discriminator_template_mc_pixel_2012.pdf");
    canvas1->SaveAs("Discriminator_template_mc_pixel_2012.png");
  }
  */
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

TH3* GetTH3(TString filename, TString objectName){

  TH3* object = 0;

  TFile* file =  TFile::Open(filename);
  if(file != 0) file -> GetObject(objectName,object);
  object -> SetDirectory(0);
  delete file;

  return object;
}


//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
