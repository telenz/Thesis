#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include "TFile.h"
#include "TTree.h"
#include "TH1D.h"



int makeCutflowTable()
{

  TH1D* hCutflow; 

  vector<TH1D*> samples;

  TString pathName="~/xxl-af-cms/ANALYSIS/workdir/analysis_2015_11_12_METGt100_JetPt110/results/analyzer/ntuples/input_weighted";
  TFile *file1 = TFile::Open(pathName + "/wjets.root","READ");
  file1->GetObject("chiTracksfullSelectionTrigger/countsTrackCriteria",hCutflow);
  //samples.push_back(hCutflow);
  TFile *file2 = TFile::Open(pathName + "/ttjets.root","READ");
  file2->GetObject("chiTracksfullSelectionTrigger/countsTrackCriteria",hCutflow);
  //samples.push_back(hCutflow);
  TFile *file3 = TFile::Open(pathName + "/dytoll.root","READ");
  file3->GetObject("chiTracksfullSelectionTrigger/countsTrackCriteria",hCutflow);
  //samples.push_back(hCutflow);
  TFile *file4 = TFile::Open(pathName + "/qcd.root","READ");
  file4->GetObject("chiTracksfullSelectionTrigger/countsTrackCriteria",hCutflow);
  //samples.push_back(hCutflow);
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

  ofstream cutflow;
  cutflow.open("cutflowTable.txt");
  cutflow<<"CUTFLOW:"<<std::endl<<std::endl;
  std::cout<<"CUTFLOW:"<<std::endl<<std::endl; 


  cout<<setprecision(2);  

  for(int i=1; i<samples[0]->GetNbinsX(); i++){

   
    if(i==1)  cout<<left<<setw(90)<<"after skim";
    if(i==2)  cout<<left<<setw(90)<<"trigger";
    if(i==3)  cout<<left<<setw(90)<<"$\\ptfirstjet>100\\gev$";
    if(i==4)  cout<<left<<setw(90)<<"$\\met>100\\gev$";
    if(i==5)  cout<<left<<setw(90)<<"$\\Delta\\phi_{\\text{max}} \\left( \\text{jet}_i, \\text{jet}_j  \\right)<2.7$";
    if(i==6)  cout<<left<<setw(90)<<"$\\Delta\\phi_{\\text{max}} \\left( \\text{jet}_i, \\met  \\right)>0.5$";
    if(i==7)  cout<<left<<setw(90)<<"$\\geq1$ reconstructed trk";
    if(i==8)  cout<<left<<setw(90)<<"$\\geq1$ high-purity trk";
    if(i==9)  cout<<left<<setw(90)<<"$\\geq1$ trk with $N_{\\text{miss}}^{\\text{middle}}=0$";
    if(i==10) cout<<left<<setw(90)<<"$\\geq1$ trk with $N_{\\text{miss}}^{\\text{inner}}=0$";
    if(i==11) cout<<left<<setw(90)<<"$\\geq1$ trk with $|d0|<0.02\\cm$";
    if(i==12) cout<<left<<setw(90)<<"$\\geq1$ trk with $|dz|<0.5\\cm$";
    if(i==13) cout<<left<<setw(90)<<"$\\geq1$ trk with $|\\eta|<2.1$";
    if(i==14) cout<<left<<setw(90)<<"$\\geq1$ trk with $\\pt>10\\gev$";
    if(i==15) cout<<left<<setw(90)<<"$\\geq1$ trk without a $\\mu$ within $\\Delta R<0.15$";
    if(i==16) cout<<left<<setw(90)<<"$\\geq1$ trk without an e within $\\Delta R<0.15$";
    if(i==17) cout<<left<<setw(90)<<"$\\geq1$ trk without a $\\tau$ within $\\Delta R<0.15$";
    if(i==18) cout<<left<<setw(90)<<"$\\geq1$ trk without a jet within $\\Delta R<0.5$";
    if(i==19) cout<<left<<setw(90)<<"\\makecell[l]{$\\geq1$ trk ! within $\\Delta R<0.05$ of \\\\\\hfill a dead/noisy ECAL cell}";
    if(i==20) cout<<left<<setw(90)<<"\\makecell[l]{$\\geq1$ trk ! within an ECAL  intermodule gap}";
    if(i==21) cout<<left<<setw(90)<<"$\\geq1$ trk ! within $1.42<|\\eta|<1.65$";
    if(i==22) cout<<left<<setw(90)<<"$\\geq1$ trk ! within $\\Delta R<0.25$ to a bad CSC";
    if(i==23) cout<<left<<setw(90)<<"$\\geq1$ trk with $\\sum \\limits_{\\Delta R < 0.3} \\pt/p_{\\text{T}}^{\\text{cand}} < 0.1$";
    if(i==24) cout<<left<<setw(90)<<"$\\geq1$ trk with $\\ecalo<5\\gev$";

    
    for(unsigned int s=0; s<samples.size(); s++){
    
      //if(s==0)   cout<<samples[s]->GetXaxis()->GetBinLabel(i); 

      
      int exp     = (int)std::log10((float)samples[s]->GetBinContent(i));
      double base = samples[s]->GetBinContent(i)/pow(10,exp);
     
      if(samples[s]->GetBinContent(i) == 0){
	exp  = 0;
	base = 0;
      }
     
      
      cout<<"& "<<fixed<<setw(5)<<base<<"$\\cdot10^{"<<setw(2)<<exp<<"}$"<<setw(1)<<"";
    }
    cout<<"\\\\"<<endl;
  }
 

  cutflow.close();

  return 0;


}
