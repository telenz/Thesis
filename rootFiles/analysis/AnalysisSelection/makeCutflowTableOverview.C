#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <vector>
#include "TFile.h"
#include "TTree.h"
#include "TH1D.h"
#include "TMath.h"



int makeCutflowTable()
{

  TH1D* hCutflow; 

  vector<TH1D*> samples;

  TString selection = "chiTracksfullSelectionTrigger";

  //TString pathName="/afs/desy.de/user/t/tlenz//xxl-af-cms/ANALYSIS/workdir/analysis_2015_11_18_METGt100_JetPt110_TrackPtGt20/results/analyzer/ntuples/input_weighted";
  //TString pathName="~/xxl-af-cms/ANALYSIS/workdir/analysis_2015_11_12_METGt100_JetPt110/results/analyzer/ntuples/input_weighted";
  TString pathName="~/xxl-af-cms/ANALYSIS/workdir/analysis_2015_12_02_METGt100_JetPt110_TrackPtGt20/results/analyzer/ntuples/input_weighted";
  TFile *file1 = TFile::Open(pathName + "/wjets.root","READ");
  file1->GetObject(selection + "/countsTrackCriteria",hCutflow);
  samples.push_back(hCutflow);
  TFile *file2 = TFile::Open(pathName + "/ttjets.root","READ");
  file2->GetObject(selection + "/countsTrackCriteria",hCutflow);
  samples.push_back(hCutflow);
  TFile *file3 = TFile::Open(pathName + "/dytoll.root","READ");
  file3->GetObject(selection + "/countsTrackCriteria",hCutflow);
  samples.push_back(hCutflow);
  TFile *file4 = TFile::Open(pathName + "/qcd.root","READ");
  file4->GetObject(selection + "/countsTrackCriteria",hCutflow);
  samples.push_back(hCutflow);
  //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  TFile *file5 = TFile::Open(pathName + "/Madgraph_signal_mass_100_ctau_10cm.root","READ");
  file5->GetObject("chiTracksfullSelectionTrigger/countsTrackCriteria",hCutflow);
  samples.push_back(hCutflow);
  TFile *file6 = TFile::Open(pathName + "/Madgraph_signal_mass_100_ctau_100cm.root","READ");
  file6->GetObject("chiTracksfullSelectionTrigger/countsTrackCriteria",hCutflow);
  samples.push_back(hCutflow);
  TFile *file7 = TFile::Open(pathName + "/Madgraph_signal_mass_500_ctau_10cm.root","READ");
  file7->GetObject("chiTracksfullSelectionTrigger/countsTrackCriteria",hCutflow);
  samples.push_back(hCutflow);
  TFile *file8 = TFile::Open(pathName + "/Madgraph_signal_mass_500_ctau_100cm.root","READ");
  file8->GetObject("chiTracksfullSelectionTrigger/countsTrackCriteria",hCutflow);
  samples.push_back(hCutflow);
  //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  TFile *file9 = TFile::Open(pathName + "/data.root","READ");
  file9->GetObject("chiTracksfullSelectionTrigger/countsTrackCriteria",hCutflow);
  samples.push_back(hCutflow);

  ofstream cutflow;
  cutflow.open("cutflowTable.txt");
  cutflow<<"CUTFLOW:"<<std::endl<<std::endl;
  std::cout<<"CUTFLOW:"<<std::endl<<std::endl; 


  cout<<setprecision(5);  

  for(int i=1; i<=8; i++){

   
    if(i==1)  cout<<left<<setw(90)<<"After skim";
    if(i==2)  cout<<left<<setw(90)<<"Trigger";
    if(i==3)  cout<<left<<setw(90)<<"Trigger selection";
    if(i==4)  cout<<left<<setw(90)<<"QCD suppression";
    if(i==5)  cout<<left<<setw(90)<<"Good quality selection";
    if(i==6)  cout<<left<<setw(90)<<"Kinematic selection";
    if(i==7)  cout<<left<<setw(90)<<"Lepton/jet veto";
    if(i==8)  cout<<left<<setw(90)<<"Isolation selection";
 
    int bin = 0; 

    if(i==1)  bin = 1;
    if(i==2)  bin = 2;
    if(i==3)  bin = 4;
    if(i==4)  bin = 6;
    if(i==5)  bin = 12;
    if(i==6)  bin = 14;
    if(i==7)  bin = 22;
    if(i==8)  bin = 24;

    for(unsigned int s=0; s<samples.size(); s++){
    
 
      //      if(s==0)   cout<<samples[s]->GetXaxis()->GetBinLabel(i); 

      
      int exp     = (int)std::log10((float)samples[s]->GetBinContent(bin));
      double base = samples[s]->GetBinContent(bin)/TMath::Power(10.,exp);
     
      if(samples[s]->GetBinContent(i) == 0){
	exp  = 0;
	base = 0;
      }
     
      cout.precision(2);
      cout<<"& "<<fixed<<setw(5)<<base<<"$\\cdot10^{"<<setw(2)<<exp<<"}$"<<setw(1)<<"";
    }
    cout<<"\\\\"<<endl;

    if(i==4){
      cout<<left<<setw(90)<<"Track-based selection:"<<endl;
      for(unsigned int s=0; s<samples.size(); s++){
	cout<<"& ";
      }
      cout<<"\\\\"<<endl;
    }

    if(i==1){
      cout<<left<<setw(90)<<"Event-based selection:"<<endl;
      for(unsigned int s=0; s<samples.size(); s++){
	cout<<"& ";
      }
      cout<<"\\\\"<<endl;
    }

  }
 
  cutflow.close();

  return 0;


}
