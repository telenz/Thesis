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



int makeValidationPlots_Bias(){

  TeresaPlottingStyle::init();
  gStyle -> SetHistLineWidth(width);
  TGaxis::SetMaxDigits(5);
  gStyle->SetNdivisions(506,"Y");


  TString pathToFile = "/nfs/dust/cms/user/tlenz/JER_checkoutVersion/JERgammajet/plots_2012/PF_L1CHS/mc/root_files/";
  TString method = "RMS99";
   
  TGraphErrors* intr  = 0;
  TGraphErrors* full  = 0;
  TGraphErrors* Ratio = 0;
  TFile *file;
  TString fileName;
  TString etaRegion; 

  TCanvas *canvas = new TCanvas("c","c",0,0,500,500);
  canvas -> cd();
  float fraction  = 0.40;
  TPad *pad1      = new TPad("pad1", "Control Plots 1", 0.01, fraction, 0.99, 0.99);
  TPad *padRatio  = new TPad("rp1", "Ratio1", 0.01, 0.01, 0.99, fraction-0.005);

  padRatio -> SetBottomMargin(0.40);
  padRatio -> SetTopMargin(0.002);
  pad1     -> SetBottomMargin(0.002);
  pad1     -> SetTopMargin(0.07);


  for(int j=0; j<1; j++){

    etaRegion.Form("%4.1f <|#eta^{1st jet}|< %4.1f",etaBins[j], etaBins[j+1]);

    fileName.Form("/Resolution_for_%i_eta_bin_PFCHS_mc_%s.root",j+1,method.Data());
    cout<<fileName<<endl;
    file =  TFile::Open(pathToFile + fileName);
    file -> GetObject("Graph",full);
    delete file;

    fileName.Form("/Resolution_for_%i_eta_bin_intrinsic_PFCHS_mc_%s.root",j+1,method.Data());
    file = TFile::Open(pathToFile + fileName);
    file->GetObject("Graph",intr);
    delete file;

    full -> SetMarkerColor(c_measured);
    full -> SetLineColor(c_measured);
    TF1* f1 =   full -> GetFunction("fResolution");
    f1->SetLineColor(c_measured);
    //    TF1* f1 =   full -> GetFunction("fResolution")->SetLineColor(c_measured);
    //    f1->GetXaxis()->SetRangeUser(50,600);

    intr -> SetMarkerColor(c_intrinsic);
    intr -> SetLineColor(c_intrinsic);
    intr -> GetFunction("fResolution")->SetLineColor(c_intrinsic);

    
    full ->SetMaximum(0.12);
    full ->SetMinimum(0.05);
    full->GetYaxis()->SetTitle("#sigma_{JER}");
    full->GetXaxis()->SetTitle("");

    double titleSize = gStyle -> GetTitleSize("X")*1/(1-fraction); 
    full -> GetXaxis() -> SetTitleSize(titleSize);
    full -> GetYaxis() -> SetTitleSize(titleSize);
    double labelSize = gStyle -> GetLabelSize("X")*1./(1-fraction); 
    full -> GetXaxis() -> SetLabelSize(labelSize);
    full -> GetYaxis() -> SetLabelSize(labelSize);
    full -> GetYaxis() -> SetTitleOffset(0.9);


    pad1 -> cd();

    TLatex*  info   = new TLatex();
    info->SetNDC();
    info->SetTextSize(labelSize -0.01);
    
    cout<<etaRegion<<endl;
    
    full -> Draw("AP same");
    f1->Draw("same");
    intr -> Draw("Psame"); 
    info->DrawLatex(250., 0.085,etaRegion);
    info->SetTextSize(labelSize);
    info -> DrawLatex(0.70, 0.94, "Simulation");

    TLegend *legend  = new TLegend(0.32,0.7,0.9,0.9);
    legend -> SetTextSize(labelSize-0.01);
    legend -> AddEntry(intr,"intrinsic resolution","l");
    legend -> AddEntry(full,"measured resolution (MC)","l");
    legend->Draw("same");

    canvas->cd();
    pad1->Draw();
 
    //------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    const int numEntries = intr ->GetN();
    double *xIntrinsic   = intr -> GetX();
    double *yIntrinsic   = intr -> GetY();
    double *xIntrinsicError = intr -> GetEX();
    double *yIntrinsicError  = intr -> GetEY();
    double *xFull = full -> GetX();
    double *yFull = full -> GetY();
    double *xFullError = full -> GetEX();
    double *yFullError = full -> GetEY();

    double *x = new double[numEntries];
    double *y = new double[numEntries];
    double *xError = new double[numEntries];
    double *yError = new double[numEntries];

    for(int i=0; i<numEntries; i++){
      
      
      y[i] = yFull[i]/yIntrinsic[i];
      x[i] = 1./2.*(xFull[i]+xIntrinsic[i]);
      
      yError[i] =  TMath::Sqrt(TMath::Power((1./yIntrinsic[i]),2)*TMath::Power(yFullError[i],2)+TMath::Power((yFull[i]/(TMath::Power(yIntrinsic[i],2))),2)*TMath::Power(yIntrinsicError[i],2)-2.0*yFull[i]/TMath::Power(yIntrinsic[i],3)*yFullError[i]*yIntrinsicError[i]);
      //cout<<"y["<<i<<"] = "<<y[i]*100<<endl<<endl;
      //cout<<"yError["<<i<<"] = "<<yError[i]*100<<endl<<endl;

      xError[i] = 1./2.*TMath::Sqrt(TMath::Power(xFullError[i],2)+TMath::Power(xIntrinsicError[i],2));
  }

    Ratio = new TGraphErrors(numEntries,x,y,xError,yError);


    titleSize =  gStyle -> GetTitleSize("X")/fraction;
    Ratio -> GetYaxis() -> SetTitleSize(titleSize-0.01);
    Ratio -> GetXaxis() -> SetTitleSize(titleSize);
    Ratio -> GetYaxis() -> CenterTitle();
    labelSize =  gStyle -> GetLabelSize("X")/fraction;
    cout<<labelSize<<endl;
    Ratio -> GetXaxis() -> SetLabelSize(labelSize);
    Ratio -> GetYaxis() -> SetLabelSize(labelSize);
    Ratio -> GetXaxis() -> SetTitleOffset(1.2);
    Ratio -> GetYaxis() -> SetTitleOffset(0.65);

    Ratio -> SetTitle("");
    Ratio -> GetXaxis()->SetTitle("p_{T}^{#gamma} [GeV]");
    Ratio -> GetXaxis()->SetLimits(0,600);
    Ratio -> GetYaxis()->SetTitle("#sigma_{meas.}/#sigma_{intr.}");
    Ratio -> SetMaximum(1.25);
    Ratio -> SetMinimum(0.75);
    padRatio->cd();

    Ratio -> Draw("AP");
    TF1* line = new TF1("line","1.",0,600);
    line->SetLineColor(kBlack);
    line->SetLineWidth(1);
    line->Draw("same");

    
  
    canvas->cd();
    padRatio->Modified();
    padRatio->SetGridy();
    padRatio->Draw("same");
    gPad->RedrawAxis();
    fileName.Form("output/MCClosure_for_%i_eta_bin_%s.pdf",j+1,method.Data());
    canvas   -> SaveAs(fileName);
    //------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 
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


//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
