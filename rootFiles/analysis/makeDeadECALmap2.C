//-----------------------------------------------------------------------------
// File:        analyzer.cc
// Description: Analyzer for ntuples created by TheNtupleMaker
// Created:     Tue Sep 24 14:30:05 2013 by mkanalyzer.py
// Author:      Teresa Lenz
//-----------------------------------------------------------------------------
#include "TLorentzVector.h"
#include "TH2.h"
#include "TCanvas.h"
#include <time.h>
#include <fstream>
#include <iomanip>
#include "../plotStyleThesis.h"
using namespace std;


//-----------------------------------------------------------------------------
int makeDeadECALmap2()
{
  TeresaPlottingStyle::init();
  ifstream inputFile("/afs/desy.de/user/t/tlenz/HighDeDx-DisappTrks-Analyzer/data/DeadEcalChannelsNew.txt");
  
  gStyle->SetMarkerSize(0.8); // This corresponds to dr=0.05

  vector<double> etaCSC, phiCSC, etaEcal, phiEcal;
  int lines;
  int i=0;
  double n,m;

  i=0;
  while(inputFile>>n>>m){
    etaEcal.push_back(n);
    phiEcal.push_back(m);
    i++;
    cout<<n<<endl;
  }
  lines=i;

  TH2D* histo = new TH2D("histo","histo",10000,-3.142,3.142,10000,-3.142,3.142);
  

  for(int j = 0; j<etaEcal.size(); j++){


    histo->Fill(etaEcal[j],phiEcal[j]);
    //histo->Fill(-3.05,-3.142);
    

  }

  TCanvas* c = new TCanvas();


  histo->SetTitle("");
  histo->GetXaxis()->SetTitle("#eta");
  histo->GetYaxis()->SetTitle("#phi");
  histo->Draw();

  c->SaveAs("DeadECALMap.pdf");

  return 0;
}
