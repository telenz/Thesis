#define APVGain_cxx
#include "APVGain.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include "TH1.h"
#include "TH2.h"
#include <map>
#include <iostream>
#include <algorithm>
#include <vector>
#include <algorithm>
#include "TMath.h"
#include "TPaveStats.h"
#include "../../plotStyleThesis.h"

int num=0;

class histo{

public:
  
  TH1D *allGainsPerModule;
  double rms;
  double mean;    


  histo(){
    TString histoName = Form("DifferenceInCalibration_%i",num);
    allGainsPerModule = new TH1D(histoName,"Differences in Calibration",1000,0,2);
    rms  = 0.;
    mean = 1.;
    num += 1;
  };
 

  void calculateRMS(){

    rms  = allGainsPerModule -> GetRMS();
    mean = allGainsPerModule -> GetMean();

    //allGainsPerModule->Draw();

  };

};

  void APVGain::Loop()
{

  TeresaPlottingStyle::init();

  gStyle -> SetTitleFont(42,"xyz");
  gStyle -> SetLabelFont(42,"xyz");

  gStyle -> SetCanvasDefH(600); //Height of canvas
  gStyle -> SetCanvasDefW(600); //Width of canvas

  gStyle -> SetPadBottomMargin(0.15);
  gStyle -> SetPadLeftMargin(0.15);

  // Pad   
  gStyle -> SetTitleSize(0.05,"X"); 
  gStyle -> SetTitleSize(0.05,"Y"); 
  gStyle -> SetLabelSize(0.04,"X");
  gStyle -> SetLabelSize(0.04,"Y");
   
  gStyle -> SetTitleOffset(1.3,"X");
  gStyle -> SetTitleOffset(1.3,"Y");
  gStyle -> SetHistLineWidth(1);
  gStyle -> SetTextFont(132);
  gStyle -> SetTextSize(0.042);

  gStyle->SetOptStat("emr");

  //   In a ROOT session, you can do:
  //      Root > .L APVGain.C
  //      Root > APVGain t
  //      Root > t.GetEntry(12); // Fill t data members with entry number 12
  //      Root > t.Show();       // Show values of entry 12
  //      Root > t.Show(16);     // Read and show values of entry 16
  //      Root > t.Loop();       // Loop on all entries
  //

  //     This is the loop skeleton where:
  //    jentry is the global entry number in the chain
  //    ientry is the entry number in the current Tree
  //  Note that the argument to GetEntry must be:
  //    jentry for TChain::GetEntry
  //    ientry for TTree::GetEntry and TBranch::GetEntry
  //
  //       To read only selected branches, Insert statements like:
  // METHOD1:
  //    fChain->SetBranchStatus("*",0);  // disable all branches
  //    fChain->SetBranchStatus("branchname",1);  // activate branchname
  // METHOD2: replace line
  //    fChain->GetEntry(jentry);       //read all branches
  //by  b_branchname->GetEntry(ientry); //read only this branch
  if (fChain == 0) return;

  const int min=0;


  TString title = "step " + step + ": Pixel and Strip Gain";
  TH1D *GainPS       = new TH1D("GainPS",title,1000,0.0,2.0);
  title = "step " + step + ": Pixel Gain";
  TH1D *pixelGain        = new TH1D("pixelGain",title,2000,0.,2.);
  pixelGain->GetXaxis()->SetNdivisions(505);
  title = "step " + step + ": Strip Gain";
  TH1D *stripGain        = new TH1D("stripGain",title,2000,0,2.0);
  title = "step " + step + ": Strip Previous Gain";
  TH1D *stripPrevGain    = new TH1D("stripPrevGain",title,100,-2,2);
  cout<<step<<endl;
  cout<<min<<endl;
  title =  "step " + step + ": rel. diff of calib. factors inside a module (NEntries>0)";
  TH1D *relDiffOfROCs    = new TH1D("relDiffOfROCs",title,100,0,1);  
  title = "step " + step + ": #sigma of calib. factors inside a module (NEntries>0)";
  TH1D *rmsOfCalibration = new TH1D("rmsOfCalibration",title,100,0,1); 
  title = "step " + step +  ": Pixel: Masked Modules";
  TH1D *pixelIsMasked    = new TH1D("pixelIsMasked",title,2,0,2);  
  //title = "step " + step + ": Strip: Masked APVs";
  TH1D *stripIsMasked    = new TH1D("stripIsMasked",title,2,0,2);  
  title = "Gain vs. FitChi2NDF";
  TH2D *hGainVsChi2NDF    = new TH2D("GainVsFitChi2NDF",title,1000,0,2,1000,0,1000000);  
  title = "Gain vs. SubDetId";
  TH2D *hGainVsSubDetId   = new TH2D("GainVsSubDetId",title,1000,0,2,2,1,3); 
  //title = "Gain vs. DetId";
  //TH2D *hGainVsDetId   = new TH2D("GainVsDetId",title,1000,0,2,2,1,3); 


  title = "step " + step + ": Pixel NEntries";
  TH1D *pixelNentries       = new TH1D("pixelNentries",title,100,0,10000000);
  title = "step " + step + ": Strip NEntries";
  TH1D *stripNentries       = new TH1D("stripNentries",title,100,0,10000000);
  title = "step " + step + ": Pixel FitWidth";
  TH1D *pixelFitWidth       = new TH1D("pixelFitWidth",title,101,-1,100);
  title = "step " + step + ": Strip FitWidth";
  TH1D *stripFitWidth       = new TH1D("stripFitWidth",title,101,-1,100);
  title = "step " + step + ": Strip FitChi2NDF";
  TH1D *stripFitChi2NDF       = new TH1D("stripFitChi2NDF",title,100000,0,1000000);
  title = "step " + step + ": Pixel FitChi2NDF";
  TH1D *pixelFitChi2NDF       = new TH1D("pixelFitChi2NDF",title,100000,0,1000000);
 

  GainPS->GetXaxis()->SetTitle("#frac{MPV (ADC/mm)}{calibration factor (ADC/mm)}");
  pixelGain->GetXaxis() ->SetTitle("#frac{MPV (ADC/mm)}{300 #upoint 265 (ADC/mm)}");
  stripGain->GetXaxis() ->SetTitle("#frac{MPV (ADC/mm)}{300 (ADC/mm)}");
  rmsOfCalibration->GetXaxis()->SetTitle("#sigma_{Gain within one module}");


  Long64_t nentries = fChain->GetEntriesFast();
  

  std::map<int,double> lowerValue;
  std::map<int,double> nTolowerValue;
  std::map<int,double> upperValue;
  std::map<int,double> nToupperValue;
  std::map<int,histo>  gainInModule;

  std::map<int,int> nOfROCs;

  std::vector<int> pixelModules;
  std::vector<int> stripModules;

  Long64_t nbytes = 0, nb = 0;
  cout<<"nentries = "<<nentries<<endl;

  double firstROC1  = 1.;
  double secondROC1 = 1.;

  double firstROC2  = 1.;
  double secondROC2 = 1.;

  std::map<int,double> modules;
  double MeanGain=0;

  for (Long64_t jentry=0; jentry<nentries;jentry++) {

    //----------------------------------------------
    Long64_t ientry = LoadTree(jentry);
    if (ientry < 0) break;
    nb = fChain->GetEntry(jentry);   nbytes += nb;
    //---------------------------------------------

    if(SubDet==1 || SubDet==2){
     
      
      nOfROCs[DetId] += 1;

      // Fill all Gains to map gainInModule     
      if(NEntries>min){

	if ( gainInModule.find(DetId) == gainInModule.end() ) {
	  histo hist;
	  gainInModule[DetId] = hist;
	  gainInModule[DetId].allGainsPerModule->Fill(Gain);

	}
	else{
	  gainInModule[DetId].allGainsPerModule->Fill(Gain);

	}
      }

      // Make new Entry if this module is not yet in vector "pixelModules"
      //if(std::find(pixelModules.begin(), pixelModules.end(), DetId) != pixelModules.end()){}
      //else { pixelModules.push_back(DetId);}

      if(NEntries>min){
	if(lowerValue[DetId] == 0)       lowerValue[DetId]    = Gain;
	else if(lowerValue[DetId]>Gain){
	  lowerValue[DetId]    = Gain;

	}
	if(upperValue[DetId] == 0)       upperValue[DetId] = Gain;
	else if(upperValue[DetId]<Gain){
	  upperValue[DetId]    = Gain;
	}
      }

    }
    
    //cout<<"DetId = "<<DetId<<endl;
    
    

    if(step.Contains("CL2") || step.Contains("Mean") || step.Contains("Validation")){
      
      if(modules.find(DetId) != modules.end() ){
	// Found!!
	continue;
      }
      else {
	// Not found!! 
	modules[DetId] = Gain;
      }
    }

    GainPS -> Fill(Gain);

    if (SubDet==1 || SubDet==2){
      
      if((int) DetId == 352412168){
	MeanGain+=Gain;
	cout<<"352412168 : "<<endl;
	cout<<"NEntries = "<<NEntries<<endl;    
	cout<<"Gain = "<<Gain<<endl;
	cout<<"FitWidth = "<<FitWidth<<endl;
	
      }


      /*
      if(NEntries>100000  && abs(Gain-1.)>0.3){
      	cout<<endl<<"NEntries = "<<NEntries<<endl;
	cout<<"DetId = "<<DetId<<endl;
      	cout<<"SubDet = "<<(int) SubDet<<endl;
	cout<<"Gain = "<<Gain<<endl<<endl;
	}
      */

      
      hGainVsChi2NDF->Fill(Gain,FitChi2NDF);
      hGainVsSubDetId->Fill(Gain,SubDet);

      pixelGain  -> Fill(Gain);
      pixelNentries -> Fill(NEntries); 
      pixelFitWidth -> Fill(FitWidth); 
      pixelIsMasked->Fill(isMasked);

      pixelFitChi2NDF->Fill(FitChi2NDF);
    }
    else{

	stripGain -> Fill (Gain);
	stripNentries -> Fill(NEntries); 
	stripFitWidth -> Fill(FitWidth); 
	stripPrevGain -> Fill (PrevGain);
	stripIsMasked->Fill(isMasked);
	stripFitChi2NDF->Fill(FitChi2NDF);
    }
  }
  cout<<"loop finished!"<<endl;

  cout<<"MeanGain = "<<MeanGain<<endl;
  cout<<"MeanGain/8 = "<<MeanGain/8.<<endl;

  cout<<"firstROC1/secondROC1 = "<<firstROC1/secondROC1<<endl;
  cout<<"firstROC2/secondROC2 = "<<firstROC2/secondROC2<<endl;
  /*
  TCanvas *c1 = new TCanvas("c1","c1",0,0,500,500);
  c1->cd();
  c1->SetLogy();
  pixelGain->Draw();
  if(saveOutput) c1->SaveAs("output/" + step + "/pixelGain.pdf");


  TCanvas *c1a = new TCanvas("c1a","c1a",0,0,500,500);
  c1a->cd();
  c1a->SetLogy();
  GainPS->Draw();
  if(saveOutput)  c1a->SaveAs("output/" + step + "/pixelAndStripGain.pdf");
  
  TCanvas *c2 = new TCanvas("c2","c2",0,0,500,500);
  c2->cd();
  c2->SetLogy();
  stripGain->Draw();
  if(saveOutput)  c2->SaveAs("output/" + step + "/stripGain.pdf");
  
  TCanvas *c3 = new TCanvas("c3","c3",0,0,500,500);
  c3->cd();
  stripPrevGain->Draw();
  if(saveOutput) c3->SaveAs("output/" + step + "/stripPreviousGain.pdf");

  TCanvas *c4 = new TCanvas("c4","c4",0,0,500,500);
  c4->cd();
  pixelIsMasked->Draw();
  if(saveOutput)  c4->SaveAs("output/" + step + "/pixelIsMasked.pdf");

  TCanvas *c5 = new TCanvas("c5","c5",0,0,500,500);
  c5->cd();
  hGainVsChi2NDF->Draw();
  if(saveOutput)  c5->SaveAs("output/" + step + "/hGainVsChi2NDF.pdf");

  TCanvas *c6 = new TCanvas("c6","c6",0,0,500,500);
  c6->cd();
  hGainVsSubDetId->Draw();
  if(saveOutput)  c6->SaveAs("output/" + step + "/hGainVsSubDetId.pdf");

  TCanvas *c7 = new TCanvas("c7","c7",0,0,500,500);
  c7->cd();
  pixelNentries->Draw();
  if(saveOutput)  c7->SaveAs("output/" + step + "/hPixelNentries.pdf");

  TCanvas *c8 = new TCanvas("c8","c8",0,0,500,500);
  c8->cd();
  stripNentries->Draw();
  if(saveOutput)  c8->SaveAs("output/" + step + "/hStripNentries.pdf");

  TCanvas *c9 = new TCanvas("c9","c9",0,0,500,500);
  c9->cd();
  pixelFitWidth->Draw();
  if(saveOutput)  c9->SaveAs("output/" + step + "/hPixelFitWidth.pdf");

  TCanvas *c10 = new TCanvas("c10","c10",0,0,500,500);
  c10->cd();
  stripFitWidth->Draw();
  if(saveOutput)  c10->SaveAs("output/" + step + "/hStripFitWidth.pdf");

  TCanvas *c11 = new TCanvas("c11","c11",0,0,500,500);
  c11->cd();
  pixelFitChi2NDF->Draw();
  if(saveOutput)  c11->SaveAs("output/" + step + "/pixelFitChi2NDF.pdf");

  TCanvas *c12 = new TCanvas("c12","c12",0,0,500,500);
  c12->cd();
  stripFitChi2NDF->Draw();
  if(saveOutput)  c12->SaveAs("output/" + step + "/stripFitChi2NDF.pdf");

  
  TCanvas *c6666 = new TCanvas("c6666","c6666",0,0,500,500);
  c6666->cd();
  */

  
  

  /*  
      for(iterator = nTolowerValue.begin(); iterator != nTolowerValue.end(); iterator++) {
    
      //cout<<"iterator->second = "<<iterator->second<<endl;     
    
      if(iterator->second<0) iterator->second = 0;
    
      std::map<int, double>::iterator iterator2;
      for(iterator2 = nToupperValue.begin(); iterator2 != nToupperValue.end(); iterator2++) {

      if(iterator->first==iterator2->first){
      double relDiff = 1.- iterator->second/iterator2->second;
      relDiffOfROCs->Fill(relDiff);
      if(relDiff>0.10){
      cout<<"relDiff = "<<relDiff<<endl;
      cout<<"iterator2->second = "<<iterator2->second<<endl;
      cout<<"iterator->second = "<<iterator->second<<endl<<endl;
      }
	
      break;
      }
      }

      }
  */


  //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  // Find out what the maximal relative difference is

  std::map<int, double>::iterator iterator1;
  for(iterator1 = lowerValue.begin(); iterator1 != lowerValue.end(); iterator1++) {

    if(iterator1->second<0) iterator1->second = 0;
    std::map<int, double>::iterator iterator2;
    for(iterator2 = upperValue.begin(); iterator2 != upperValue.end(); iterator2++) {
      if(iterator1->first==iterator2->first){
	double relDiff = TMath::Abs(iterator1->second/iterator2->second - 1.);
	relDiffOfROCs->Fill(relDiff);
	
	
	break;
      }
    }
  }
  //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

  //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  // Find out what the standard deviation of all ROCs within one module is

  std::map<int, histo>::iterator iterator;
  for(iterator = gainInModule.begin(); iterator != gainInModule.end(); iterator++) {
    histo hist = iterator->second;
    hist.calculateRMS();
    rmsOfCalibration->Fill(hist.rms/hist.mean);

    if(hist.rms/hist.mean>1.){
      std::cout<<"hist.getEntries() = "<<hist.allGainsPerModule->GetEntries()<<std::endl;
      std::cout<<"rms/mean = "<<hist.rms/hist.mean<<std::endl;
    }

  }
  //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  
  //TCanvas *c100 = new TCanvas("c100","c100",0,0,500,500);
  //c100->cd();
  //relDiffOfROCs->Draw();
  //if(saveOutput) c100->SaveAs((TString) "output/" + step + "/relDiffOfROCs_N" + (long) min + (TString) ".pdf");
  gStyle->SetStatH(0.4);
  gStyle->SetStatW(0.4);
  gStyle->SetOptStat("emr");
  //gStyle->SetOptFit(001);
  //gStyle->SetOptStat("e");
  gStyle->SetStatFontSize(0.025);


  TCanvas *c101 = new TCanvas();
  c101->cd();
  rmsOfCalibration->GetYaxis()->SetTitle("Number of modules");
  rmsOfCalibration->Draw();
  c101->Update();

  TPaveStats *st = (TPaveStats*)rmsOfCalibration->FindObject("stats");
  cout<<st<<endl;
  st->SetX1NDC(0.60); //new x start position
  st->SetX2NDC(.94); //new x end position
  st->SetY1NDC(0.82); //new x start position
  st->SetY2NDC(.94); //new x end position

  if(saveOutput) c101->SaveAs((TString) "output/rmsOfROCs_N_" + (long) min + "_"+ + step +  (TString) ".pdf");
  
}
