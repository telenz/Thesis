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
#include "/nfs/dust/cms/user/tlenz/JER_checkoutVersion/JERgammajet/CODE/myDeclarations.h"
#include "../plotStyleThesis.h"
#include "myColors.h"

TH1D* GetTH1D(TString filename, TString objectName);
TH2D* GetTH2D(TString filename, TString objectName);
TGraphErrors* readTGraphErrors(const TString &fileName, const TString &gName, const TString &newGName);


int makeFitPlots(){

  TeresaPlottingStyle::init();
  gStyle->SetHistLineWidth(width);
  gStyle->SetNdivisions(506,"Y");

  TString pathToFile = "/nfs/dust/cms/user/tlenz/JER_checkoutVersion/JERgammajet/plots_2012/PF_L1CHS/";

  const TString JetType = "PFCHS";
  TString Method = "RMS99";
  
  const int nEta =nEtaBins;

  TString etaString, filename;   
  

  TString rootFiles, AuxString;
  int meth = 1;

 
  for(int eta = 0; eta < nEtaBins; eta++){
     //for(int eta = 0; eta < 1; eta++){
    
    // Read the MC and data results 
    rootFiles =  pathToFile + Form("data/root_files/Resolution_for_%i_eta_bin_",eta+1) + JetType +  "_data_" + Method +  ".root";
    TGraphErrors* JERData = readTGraphErrors(rootFiles,"Graph;1","Graph;1");
    rootFiles = pathToFile + Form("mc/root_files/Resolution_for_%i_eta_bin_",eta+1) + JetType +  "_mc_" + Method + ".root";
    TGraphErrors* JERMC = readTGraphErrors(rootFiles,"Graph","Graph");
    
    etaString = Form("JER for %4.1f <|#eta|< %4.1f",etaBins[eta+1],etaBins[eta+2]);

    //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    // 1.) Calculate the ratio w/o systematic Uncertainties  

    int nData    = JERData->GetN();

    double *dataX  = JERData->GetX();
    double *dataY  = JERData->GetY();
    double *dataEX = JERData->GetEX();
    double *dataEY = JERData->GetEY();
    
    double *mcX  = JERMC->GetX();
    double *mcY  = JERMC->GetY();
    double *mcEX = JERMC->GetEX();
    double *mcEY = JERMC->GetEY();
    
    double *ratioX  = new double[nData];
    double *ratioY  = new double[nData];
    double *ratioEX = new double[nData];
    double *ratioEY = new double[nData];

 
    int idxMC = 0;
    for(int i=0; i<nData; i++){


      if(TMath::Abs(dataX[i]/mcX[idxMC] - 1.) > 0.05){
	i -= 1;
	idxMC += 1;
	continue;
      }
     
      ratioX[i]  = 1./2.*(dataX[i] + mcX[idxMC]);
      //cout<<"dataY[i] = "<<dataY[i]<<endl;
      //cout<<"mcY[i]   = "<<mcY[idxMC]<<endl;
      ratioY[i]  = dataY[i]/mcY[idxMC];
      ratioEX[i] = 1./2.*TMath::Sqrt(TMath::Power(dataEX[i],2)+TMath::Power(mcEX[idxMC],2));
      ratioEY[i] = TMath::Sqrt(TMath::Power((1./mcY[idxMC]),2)*TMath::Power(dataEY[i],2)+TMath::Power((dataY[i]/(TMath::Power(mcY[idxMC],2))),2)*TMath::Power(mcEY[idxMC],2));
    }
    
    TGraphErrors *Ratio = new TGraphErrors(nData,ratioX,ratioY,ratioEX,ratioEY);

    Ratio -> GetXaxis() -> SetTitle("p_{T}^{#gamma} [GeV]");
    Ratio -> GetYaxis() -> SetTitle("#sigma^{data}_{JER}/#sigma^{MC}_{JER}");
    Ratio -> GetXaxis() -> SetLimits(0,600);
    TF1* f1 = new TF1("name","pol0",0,600);   
    Ratio   -> Fit("name","QR0");
   
   
    double fitPar      = f1 -> GetParameter(0);
    double fitParStatE = f1 -> GetParError(0);

    // Make another TGraph with the fitted error bands   

    double x[100000] = {0};
    double ex[100000] = {0};
    double y[100000] = {0};
    double ey[100000]= {0};

    for(int i=0; i<100000; i++){

      x[i] = 0. + i*1./999.*600.;
      ex[i] = 0.;
      y[i] = fitPar;
      ey[i] = fitParStatE;
    }


    TGraphErrors *band = new TGraphErrors(100000,x,y,ex,ey);


   
    TCanvas *c11 = new TCanvas();
    c11 -> cd();


    // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%    Style    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    Ratio -> SetMinimum(0.5);
    Ratio -> SetMaximum(2.0);
  
    Ratio  -> DrawClone("AP"); 
    Color_t col = kRed - 10;
    band   -> SetLineColor(col);
    band   -> SetFillColor(col);
    band   -> SetMarkerColor(col);
    f1     -> SetLineColor(kRed);
    band   -> SetMarkerSize(0.00001);
    //band   -> SetMinimum(0.5);
    //band   -> SetMaximum(0.5);
    band   -> Draw("e3 same");
    f1     -> Draw("same");
    Ratio  -> Draw("Pe same"); 

  
    TLatex*  info   = new TLatex();
    info -> SetNDC();
    info -> SetTextSize(0.045);
    info -> DrawLatex(0.22,0.23,Form("#chi^{2}/ndof = %4.2f/%i",f1 -> GetChisquare(),f1 -> GetNDF()));
    info -> SetTextSize(0.05);
    info -> DrawLatex(0.51,0.69,Form("#rho_{res} = %4.3f #pm %4.3f", f1 -> GetParameter(0), f1->GetParError(0)));
    info -> DrawLatex(0.56,0.78,Form("#bf{%4.1f < |#eta^{jet}| < %4.1f}",etaBins[eta],etaBins[eta+1]));
    info -> SetTextSize(0.045);
    info -> DrawLatex(0.21,0.87,"Anti-k_{T} (R=0.5), PF+CHS");

    TString infotext = "";
    infotext = TString::Format("19.7 fb^{-1} (#sqrt{s} = 8 TeV)");
    TLatex *text2 = new TLatex(3.1, 24, infotext);
    text2->SetNDC();
    text2->SetTextSize(0.045);
    text2->SetY(0.952);
    text2->SetX(0.55);

    text2->Draw("same");

    filename = Form("output/Ratio_Resolution_for_%i_eta_bin_",eta+1) + JetType +  "_data_comparison_" + Method +  ".pdf";
    c11 -> SaveAs(filename);
    
  }
  


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

TGraphErrors* readTGraphErrors(const TString &fileName, const TString &gName, const TString &newGName) {
  TFile f(fileName,"READ");
  TGraphErrors *g = 0;
  f.GetObject(gName,g);
  if( g ) {
    if( newGName.Length() ) g->SetName(newGName);
  } else {
    std::cerr << "ERROR in FileOps::readTGraph: TGraphErrors with name '" << gName << "' does not exist in file '" << fileName << "'\n.";
    f.Close();
    exit(-1);
  }
  f.Close();
    
  return g;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
