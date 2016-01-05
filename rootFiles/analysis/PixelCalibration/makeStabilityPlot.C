#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include "TFile.h"
#include "TString.h"
#include "TProfile.h"
#include "TDirectory.h"
#include "TSystemDirectory.h"
#include "TObject.h"
#include "TCanvas.h"
#include "TF1.h"
#include "TLatex.h"
#include "../../plotStyleThesis.h"

using std::string;
using std::vector;





int makeStabilityPlot()
{

  
  TeresaPlottingStyle::init();

  gStyle -> SetTitleOffset(0.7,"X");
  gStyle -> SetTitleOffset(1.2,"Y");
  gStyle -> SetTitleSize(0.055,"Y");
  gStyle -> SetMarkerSize(0.5);
  gStyle -> SetMarkerColor(kBlack);
  gStyle -> SetLineColor(kBlack);
  gROOT  -> ForceStyle(); 


  //Make fits at the five steps
  TString runRangeStart[5];
  //runRangeStart[0] = "190645"; 
  //runRangeStart[1] = "198116"; 
  //runRangeStart[2] = "199356";
  //runRangeStart[3] = "203894"; 
  //runRangeStart[4] = "205826"; 
  runRangeStart[0] = "190456"; 
  runRangeStart[1] = "198116"; 
  runRangeStart[2] = "199356";
  runRangeStart[3] = "203894"; 
  runRangeStart[4] = "205826"; 
  TString runRangeEnd[5];
  runRangeEnd[0] = "196531";
  runRangeEnd[1] = "199336";
  runRangeEnd[2] = "203002";
  runRangeEnd[3] = "205781";
  runRangeEnd[4] = "208686";

 

  //   TString directory = "/nfs/dust/cms/user/tlenz/PixelCalibration/allRunsLanGausLastVersionWithStrip";
  //  TString directory = "/nfs/dust/cms/user/tlenz/PixelCalibration/allRunsLanGausLastVersionChange";
  TString directory = "/nfs/dust/cms/user/tlenz/PixelCalibration/testWithResolutionPlots";
  //TString directory = "/nfs/dust/cms/user/tlenz/PixelCalibration/testWithResolutionPlotsWithoutDeDxCutBugFree";

  //TString directory = "/nfs/dust/cms/user/tlenz/PixelCalibration/allRunsLanGausWithNewCut/";
  //TString directory = "/afs/desy.de/user/t/tlenz/PixelCalibration/input/allRunsWithGain";
  
  TSystemDirectory *dir = new TSystemDirectory(directory,directory);
  TList* folders = dir->GetListOfFiles();

  vector< TString > filenames;
  
  TH1D* hAfter  = new TH1D("hAfter","Pixel calibration factors applied",521,1,521);
  TH1D* hBefore = new TH1D("hBefore","Pixel without calibration",521,1,521);
  TH1D* hStrip  = new TH1D("hStrip","Strip dE/dx",521,1,521);


  hAfter->GetYaxis()->SetTitle("<I_{h2}> [MeV/cm]");
  hBefore->GetYaxis()->SetTitle("<I_{h2}> [MeV/cm]");
  hStrip->GetYaxis()->SetTitle("<I_{h2}> [MeV/cm]");
  hAfter->GetXaxis()->SetTitle("Time (year 2012)");
  hBefore->GetXaxis()->SetTitle("Time (year 2012)");
  hStrip->GetXaxis()->SetTitle("Time (year 2012)");

  //hAfter->SetTitle("Calibrated");
  //hBefore->SetTitle("Uncalibrated");

  hAfter->SetTitle("");
  hBefore->SetTitle("");
  hStrip->SetTitle("");

  
  hAfter  -> GetYaxis()->SetRangeUser(2.8,3.8);
  hBefore -> GetYaxis()->SetRangeUser(2.8,3.8);
  hStrip  -> GetYaxis()->SetRangeUser(2.8,3.8);

  
  if(folders)
    {

      TSystemDirectory *auxDir;
      TString fname;
      TIter next(folders);

      while ((auxDir=(TSystemDirectory*)next())) {
	fname = auxDir->GetName();

	if(!(fname.BeginsWith("Run"))) {
	  continue;
	}
	filenames.push_back(fname);
	//cout<<"fname = "<<fname<<endl;
      }
    }
  

  TProfile* auxAfter    = 0;
  TProfile* auxBefore   = 0;
  TProfile* auxStrip    = 0;
  TFile *f              = 0;


  unsigned int bin=1;
  cout<<"filenames.size() = "<<filenames.size()<<endl<<endl;
  for(unsigned int i=0; i<filenames.size(); i++)
    {      
      cout<<"Open : "<<filenames[i]<<endl;
      f = new TFile(directory+"/" + filenames[i] + "/pictures/Histos.root","open");
      if(!f) continue;      
      f->GetObject("HSCPHLTTriggerMuFilterdEdxMSProf", auxStrip);
      f->GetObject("HSCPHLTTriggerMuFiltermyHist"    , auxAfter);
      f->GetObject("HSCPHLTTriggerMuFilterdEdxMPProf", auxBefore);
      if(!auxAfter || !auxBefore || !auxStrip){

	cout<<"no file available for "<<filenames[i]<<" !!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl; 
	continue;

      }
      if(auxBefore->GetNbinsX() != auxAfter->GetNbinsX()){
	cout<<"Number of Bins differ!!!!!!!!!!!!!!!!"<<endl;
	return 1;
      }

      for(int j=1; j<=auxAfter->GetNbinsX();j++)
	{
	  hAfter->GetXaxis()->SetBinLabel(bin,auxAfter->GetXaxis()->GetBinLabel(j));
	  hAfter->GetXaxis()->SetBinLabel(bin,"");
	  hAfter->SetBinContent(bin,auxAfter->GetBinContent(j));
	  hAfter->SetBinError(bin,auxAfter->GetBinError(j));
	 
	  hBefore->GetXaxis()->SetBinLabel(bin,auxBefore->GetXaxis()->GetBinLabel(j));
	  hBefore->GetXaxis()->SetBinLabel(bin,"");
	  hBefore->SetBinContent(bin,auxBefore->GetBinContent(j));
	  hBefore->SetBinError(bin,auxBefore->GetBinError(j));

	  hStrip->GetXaxis()->SetBinLabel(bin,auxStrip->GetXaxis()->GetBinLabel(j));
	  hStrip->GetXaxis()->SetBinLabel(bin,"");
	  hStrip->SetBinContent(bin,auxStrip->GetBinContent(j));
	  hStrip->SetBinError(bin,auxStrip->GetBinError(j));


	  bin +=1;
	}
     
      f->Close();

    }
 
  TF1 *ffit[5];
  TF1 *ffitAll;

  TF1 *ffitBefore[5];
  
  TF1 *ffitStrip[5];
  TF1 *ffitAllStrip;

  ffitAll      = new TF1("fitAll","pol0",hAfter->GetXaxis()->FindBin(runRangeStart[0]),hAfter->GetXaxis()->FindBin(runRangeEnd[4])); 
  ffitAllStrip = new TF1("fitAllStrip","pol0",hStrip->GetXaxis()->FindBin(runRangeStart[0]),hStrip->GetXaxis()->FindBin(runRangeEnd[4])); 
  ffitAll      -> SetLineColor(8);
  ffitAllStrip -> SetLineColor(8);

  //TCanvas *cAfter = new TCanvas("cAfter","cAfter",500,0,1.618*400,400);
  TCanvas *cAfter = new TCanvas();
  cAfter->cd();
  hAfter->Draw("E");
  
  //TCanvas *cStrip = new TCanvas("cStrip","cStrip",1000,0,1.618*400,400);
  TCanvas *cStrip = new TCanvas();
  cStrip->cd();
  hStrip->Draw("E");

  //TCanvas *cBefore = new TCanvas("cBefore","cBefore",0,0,1.618*400,400);
  TCanvas *cBefore = new TCanvas();
  cBefore->cd();
  hBefore->Draw("E");
  

  for(unsigned int i=0; i<5; i++){
    ffit[i]      = new TF1(Form("fit%i",i),"pol0",hAfter->GetXaxis()->FindBin(runRangeStart[i]),hAfter->GetXaxis()->FindBin(runRangeEnd[i])); 
    ffitStrip[i] = new TF1(Form("fit%iStrip",i),"pol0",hStrip->GetXaxis()->FindBin(runRangeStart[i]),hStrip->GetXaxis()->FindBin(runRangeEnd[i])); 
    ffitBefore[i] = new TF1(Form("fit%iBefore",i),"pol0",hBefore->GetXaxis()->FindBin(runRangeStart[i]),hBefore->GetXaxis()->FindBin(runRangeEnd[i])); 
  }
  
  for(unsigned int i=0; i<5; i++){
        
    hAfter->Fit(Form("fit%i",i),"Q0R");
    hStrip->Fit(Form("fit%iStrip",i),"Q0R");
    hBefore->Fit(Form("fit%iBefore",i),"Q0R");
    //cAfter->cd();
    cout<<"ffit["<<i<<"]->GetParameter(0) = "<<ffit[i]->GetParameter(0)<<endl;
    cout<<"ffit["<<i<<"]->GetParError(0)  = "<<ffit[i]->GetParError(0)<<endl;
    //cout<<"ffit["<<i<<"]->GetParameter(1) = "<<ffit[i]->GetParameter(1)<<endl;
    //cout<<"ffit["<<i<<"]->GetParError(1) = "<<ffit[i]->GetParError(1)<<endl;
    //ffit[i]->Draw("same");

    cStrip->cd();
    cout<<"ffitStrip["<<i<<"]->GetParameter(0) = "<<ffitStrip[i]->GetParameter(0)<<endl;
    cout<<"ffitStrip["<<i<<"]->GetParError(0)  = "<<ffitStrip[i]->GetParError(0)<<endl;
    //cout<<"ffit["<<i<<"]->GetParameter(1) = "<<ffit[i]->GetParameter(1)<<endl;
    //cout<<"ffit["<<i<<"]->GetParError(1) = "<<ffit[i]->GetParError(1)<<endl;
    ffitStrip[i]->Draw("same");

    cBefore->cd();
    cout<<"ffitBefore["<<i<<"]->GetParameter(0) = "<<ffitBefore[i]->GetParameter(0)<<endl;
    cout<<"ffitBefore["<<i<<"]->GetParError(0)  = "<<ffitBefore[i]->GetParError(0)<<endl;
    //cout<<"ffit["<<i<<"]->GetParameter(1) = "<<ffit[i]->GetParameter(1)<<endl;
    //cout<<"ffit["<<i<<"]->GetParError(1) = "<<ffit[i]->GetParError(1)<<endl;
    //ffitBefore[i]->Draw("same");

    
  }
  cAfter->cd();
  hAfter->Fit("fitAll","Q0R");
  TF1 *ffitAll2      = new TF1("fitAll","pol0",0,1000000000000); 
  ffitAll2->SetLineColor(8);
  ffitAll2->SetParameter(0,ffitAll->GetParameter(0));
  ffitAll2->Draw("same");
  cout<<"ffitAll->GetParameter(0) = "<<ffitAll->GetParameter(0)<<endl;
  cout<<"ffitAll->GetParError(0)  = "<<ffitAll->GetParError(0)<<endl;
  cAfter->Update();
  //cout<<"ffitAll->GetParameter(1) = "<<ffitAll->GetParameter(1)<<endl;
  //cout<<"ffitAll->GetParError(1)  = "<<ffitAll->GetParError(1)<<endl;



  cStrip->cd();
  hStrip->Fit("fitAllStrip","Q0R");
  TF1 *ffitAllStrip2      = new TF1("fitAllStrip","pol0",0,1000000000000); 
  ffitAllStrip2->SetLineColor(8);
  ffitAllStrip2->SetParameter(0,ffitAllStrip->GetParameter(0));
  ffitAllStrip2->Draw("same");
  cStrip->Update();


  TLatex* info = new TLatex();
  info-> SetNDC();
  cAfter->cd();
  ffitAll->Draw("same");
  info->DrawLatex(0.40, 0.83,Form("<I_{h2}>_{Fit} = %4.3f MeV/cm",ffitAll->GetParameter(0)));
  
  cStrip->cd();
  info->DrawLatex(0.40, 0.83,Form("<I_{h2}>_{Fit} = %4.3f MeV/cm",ffitAllStrip->GetParameter(0)));


  
  /*
  TFile t("/afs/desy.de/user/t/tlenz/PixelCalibration/StabilityPlots_1.root","recreate");
  hAfter->Write();
  hBefore->Write();
  hStrip->Write();
  t.Close();
  cStrip->SaveAs("/afs/desy.de/user/t/tlenz/PixelCalibration/output/StabilityPlot_Strip_1.pdf");  
  
  cBefore->SaveAs("/afs/desy.de/user/t/tlenz/PixelCalibration/output/StabilityPlot_Pixel_beforeCalibration_1.pdf");  
  */
  cBefore->SaveAs("output/StabilityPlot_Pixel_beforeCalibration_withoutStepFits_NEW.pdf");  
  cAfter->SaveAs("output/StabilityPlot_Pixel_afterCalibration_withoutStepFits_NEW.pdf");  
  cStrip->SaveAs("output/StabilityPlot_Strip_afterCalibration_withoutStepFits_NEW.pdf");  
  cout<<"bin = "<<bin<<endl;
  return 0;


}

