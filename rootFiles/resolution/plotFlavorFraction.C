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


int plotFlavorFraction(){

  TeresaPlottingStyle::init();
  gStyle->SetNdivisions(506,"Y");
  gStyle->SetHistLineWidth(width);
  TGaxis::SetMaxDigits(5);

  TString pathToFile = "/nfs/dust/cms/user/tlenz/JER_checkoutVersion/JERgammajet/plots_2012/PF_L1CHS_primary_analysis/mc/root_files/";

  TString definition = "algo";

  TH2D *charm2D, *bottom2D, *gluon2D, *lightQuark2D, *nonDefined2D;
  TH1D *charm[2], *bottom[2], *gluon[2], *lightQuark[2], *together[2], *nonDefined[2], *allQuarks[2], *togetherWoUndefined[2];
  TH1D *charmComp[2], *bottomComp[2], *gluonComp[2], *lightQuarkComp[2], *nonDefinedComp[2], *allQuarksComp[2], *gluonWoUndefinedComp[2];
  TString fileName;  
  TFile *file;
  TCanvas* canvas[2] = {0};  
  TLatex*  info[2]   = {0};
  TLegend* legend[2] = {0};
 
   
  // Read Files
  fileName =  pathToFile + "hPhotonPtJetEtaFlavorBottom_" + definition + "_PFCHS_mc.root";
  file     =  new TFile(fileName);
  bottom2D =  (TH2D*) gDirectory->Get("histo");
  bottom2D -> SetDirectory(0);
  bottom[0]  = (TH1D*) bottom2D->ProjectionX("bottom0",0,bottom2D->GetYaxis()->FindBin(1.3));
  bottom[1]  = (TH1D*) bottom2D->ProjectionX("bottom1",bottom2D->GetYaxis()->FindBin(1.3),-1);
  cout<<"bottom2D->GetYaxis()->FindBin(1.3) = "<<bottom2D->GetYaxis()->FindBin(1.3)<<endl;
  cout<<"bottom2D->GetYaxis()->FindBin(5.0) = "<<bottom2D->GetYaxis()->FindBin(5.0)<<endl;
  for(int i= 0; i<2; i++) bottom[i] -> Rebin(20);
  for(int i= 0; i<2; i++) bottom[i] -> SetDirectory(0);
  delete file;

  fileName =  pathToFile + "hPhotonPtJetEtaFlavorCharm_" + definition + "_PFCHS_mc.root";
  file     =  new TFile(fileName);
  charm2D  =  (TH2D*) gDirectory->Get("histo");
  charm2D  -> SetDirectory(0);
  charm[0] = charm2D->ProjectionX("charm0",0,charm2D->GetYaxis()->FindBin(1.3),"");  
  charm[1] = charm2D->ProjectionX("charm1",charm2D->GetYaxis()->FindBin(1.3),-1,"");
  for(int i= 0; i<2; i++) charm[i]  ->Rebin(20);
  for(int i= 0; i<2; i++) charm[i]  -> SetDirectory(0);
  delete file;

  fileName =  pathToFile + "hPhotonPtJetEtaFlavorGluon_" + definition + "_PFCHS_mc.root";
  file     =  new TFile(fileName);
  gluon2D  =  (TH2D*) gDirectory->Get("histo");
  gluon2D  -> SetDirectory(0);
  gluon[0]    = gluon2D->ProjectionX("gluon0",0,gluon2D->GetYaxis()->FindBin(1.3),"");
  gluon[1]    = gluon2D->ProjectionX("gluon1",gluon2D->GetYaxis()->FindBin(1.3),-1,"");
  for(int i= 0; i<2; i++)  gluon[i]    -> Rebin(20);
  for(int i= 0; i<2; i++)  gluon[i]      -> SetDirectory(0); 
  delete file;
  
  fileName     =  pathToFile + "hPhotonPtJetEtaFlavorLightQuarks_" + definition + "_PFCHS_mc.root";
  file         =  new TFile(fileName);
  lightQuark2D =  (TH2D*) gDirectory->Get("histo");
  lightQuark2D -> SetDirectory(0);
  lightQuark[0] = lightQuark2D->ProjectionX("lightQuark0",0,lightQuark2D->GetYaxis()->FindBin(1.3),"");
  lightQuark[1] = lightQuark2D->ProjectionX("lightQuark1",lightQuark2D->GetYaxis()->FindBin(1.3),-1,"");
  for(int i= 0; i<2; i++)   lightQuark[i] -> Rebin(20);
  for(int i= 0; i<2; i++)   lightQuark[i] -> SetDirectory(0);


  fileName     =  pathToFile + "hPhotonPtJetEtaFlavorNonDefined_" + definition + "_PFCHS_mc.root";
  file         =  new TFile(fileName);
  nonDefined2D =  (TH2D*) gDirectory->Get("histo");
  nonDefined2D -> SetDirectory(0);
  nonDefined[0] = nonDefined2D->ProjectionX("nonDefined0",0,nonDefined2D->GetYaxis()->FindBin(1.3),"");
  nonDefined[1] = nonDefined2D->ProjectionX("nonDefined1",nonDefined2D->GetYaxis()->FindBin(1.3),-1,"");
  for(int i= 0; i<2; i++)  nonDefined[i] -> Rebin(20);
  for(int i= 0; i<2; i++)  nonDefined[i] -> SetDirectory(0);
  delete file;
     
  for(int i= 0; i<1; i++){

    allQuarks[i] = (TH1D*) bottom[i]->Clone(Form("allQuarks%i",i));
    allQuarks[i] -> Add(charm[i]);
    allQuarks[i] -> Add(lightQuark[i]);

    together[i] = (TH1D*) bottom[i]->Clone(Form("together%i",i));
    together[i] -> Add(charm[i]);
    together[i] -> Add(gluon[i]);
    together[i] -> Add(lightQuark[i]);
    together[i] -> Add(nonDefined[i]);

    togetherWoUndefined[i] = (TH1D*) bottom[i]->Clone(Form("together%i",i));
    togetherWoUndefined[i] -> Add(charm[i]);
    togetherWoUndefined[i] -> Add(gluon[i]);
    togetherWoUndefined[i] -> Add(lightQuark[i]);

    togetherWoUndefined[i]->Rebin(togetherWoUndefined[i]->GetNbinsX());
    allQuarks[i]->Rebin(allQuarks[i]->GetNbinsX());

    cout<<"number of bins together = "<<togetherWoUndefined[i]->GetNbinsX()<<endl;
    cout<<"number of bins allQuarks = "<<allQuarks[i]->GetNbinsX()<<endl;
    
    bottomComp[i]     = (TH1D*) bottom[i]->Clone(Form("bottom%i",i+3));
    bottomComp[i]     -> Divide(together[i]);
    charmComp[i]      = (TH1D*) charm[i]->Clone(Form("charm%i",i+3));
    charmComp[i]      -> Divide(together[i]);
    gluonComp[i]      = (TH1D*) gluon[i]->Clone(Form("gluon%i",i+3));
    gluonComp[i]      -> Divide(together[i]);
    lightQuarkComp[i] = (TH1D*) lightQuark[i]->Clone(Form("lightQuark%i",i+3));
    lightQuarkComp[i] -> Divide(together[i]);
    nonDefinedComp[i] = (TH1D*) nonDefined[i]->Clone(Form("nonDefined%i",i+3));  
    nonDefinedComp[i] -> Divide(together[i]);
    allQuarksComp[i]  = (TH1D*) allQuarks[i]->Clone(Form("allQuarks%i",i+3));
    allQuarksComp[i] -> Divide(togetherWoUndefined[i]);
    gluon[i]->Rebin(gluon[i]->GetNbinsX());
    gluonWoUndefinedComp[i] = (TH1D*) gluon[i]->Clone(Form("gluon%i",i+3));
    gluonWoUndefinedComp[i] -> Divide(togetherWoUndefined[i]);

    cout<<endl<<endl<<"Gluon Flavor Fraction for systematics  = "<<gluonWoUndefinedComp[i]->GetBinContent(1)<<endl;
    cout<<"Quark Flavor Fraction for systematics  = "<<allQuarksComp[i]->GetBinContent(1)<<endl;
   
    // Set Marker Style 
    lightQuarkComp[i] -> SetMarkerStyle(20);
    gluonComp[i]      -> SetMarkerStyle(24);
    charmComp[i]      -> SetMarkerStyle(21);
    bottomComp[i]     -> SetMarkerStyle(23);
    nonDefinedComp[i] -> SetMarkerStyle(22);
    lightQuarkComp[i] -> SetMarkerColor(2);
    gluonComp[i]      -> SetMarkerColor(1);
    charmComp[i]      -> SetMarkerColor(3);
    bottomComp[i]     -> SetMarkerColor(4);    
    nonDefinedComp[i] -> SetMarkerColor(kOrange);
    lightQuarkComp[i] -> SetLineColor(2);
    gluonComp[i]      -> SetLineColor(1);
    charmComp[i]      -> SetLineColor(3);
    bottomComp[i]     -> SetLineColor(4);
    nonDefinedComp[i] -> SetLineColor(kOrange);

    canvas[i] = new TCanvas();
    canvas[i] ->cd();
    canvas[i] ->SetLogy();

    // Plot the results
    lightQuarkComp[i] -> SetTitle("Flavor Composition in #gamma + Jet Events");
    lightQuarkComp[i] -> GetXaxis()->SetTitle("p_{T}^{#gamma} [GeV]");
    lightQuarkComp[i] -> GetYaxis()->SetTitle("Flavour Fraction");
    lightQuarkComp[i] -> SetMinimum(0.0001);
    lightQuarkComp[i] -> SetMaximum(999);
    lightQuarkComp[i] -> Draw(); 
    //quarksComp -> Draw(); 
    gluonComp[i]      -> Draw("same");
    charmComp[i]      -> Draw("same");
    bottomComp[i]     -> Draw("same");
    nonDefinedComp[i] -> Draw("same");

    legend[i] = new TLegend(0.52,0.62,0.92,0.92);
    legend[i] -> SetTextSize(0.05);
    
    legend[i] -> AddEntry(lightQuarkComp[i],"u-,d-,s-quarks", "pfl");
    legend[i] -> AddEntry(charmComp[i],"c-quarks", "pfl");
    legend[i] -> AddEntry(bottomComp[i],"b-quarks", "pfl");
    legend[i] -> AddEntry(gluonComp[i],"gluons", "pfl");
    legend[i] -> AddEntry(nonDefinedComp[i],"not defined", "pfl");
    legend[i] -> Draw("same");


    info[i]   = new TLatex();
    info[i] -> SetNDC();
  
    if(i==0)      info[i] -> DrawLatex(0.2,0.75,  "0.0 < |#eta^{jet}| < 1.3");
    else if(i==1) info[i] -> DrawLatex(0.2,0.75,  "1.3 < |#eta^{jet}| < 2.3");
    info[i] -> DrawLatex(0.7, 0.95, "Simulation");

    if(i==0)      canvas[i] -> SaveAs("output/flavorFraction_barrel_" + definition + ".pdf");
    else if(i==1) canvas[i] -> SaveAs("output/flavorFraction_endcap_" + definition + ".pdf");


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
