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
#include "../plotStyleThesis.h"

using std::string;
using std::vector;





int makeLandauPlot()
{

  
  TeresaPlottingStyle::init();

  TF1* land = new TF1("land", "landau(0)",100,600);
  land->SetParameters(1,200,20); //for example
  land->SetTitle("");
  land->GetHistogram()->SetNdivisions(508, "X");
  land->GetHistogram()->SetNdivisions(507, "Y");
  TCanvas *c = new TCanvas();
  c->cd();
  land->GetXaxis()->SetTitle("#Delta E/ #Delta x");
  land->GetYaxis()->SetTitle("a.u.");
  land->Draw();
  c->SaveAs("output/Landau.pdf");
  return 0;


}

