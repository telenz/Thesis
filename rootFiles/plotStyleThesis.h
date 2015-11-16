#ifndef Teresa_PLOTTING_STYLE_H
#define Teresa_PLOTTING_STYLE_H

#include "TStyle.h"
#include "TROOT.h"
#include "TAxis.h"
#include "TGaxis.h"
#include "TPad.h"
#include <iostream>


class GeneralSettings {
public:
  static void init() {

    //Legend 
    cout<<"GeneralSettings is activated!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
    
    gROOT  -> SetStyle("Plain");
    
    gStyle -> SetLegendFillColor(0);
    gStyle->SetLegendFont(42);
    //gStyle->SetLegendTextSize(0.05);
    gStyle->SetLegendBorderSize(0);

    gStyle->SetNdivisions(505,"X");
    gStyle->SetNdivisions(509,"Y");

    gStyle -> SetTitleFont(42,"xyz");
    gStyle -> SetLabelFont(42,"xyz");

    gStyle->SetPadTickX(1);
    gStyle->SetPadTickY(1);

    // Canvas
    gStyle -> SetCanvasDefH(500); //Height of canvas
    gStyle -> SetCanvasDefW(500); //Width of canvas

    gStyle -> SetPadBottomMargin(0.17);
    gStyle -> SetPadLeftMargin(0.17);
    gStyle -> SetPadTopMargin(0.06);
    gStyle -> SetPadRightMargin(0.06);

    // Pad   
    gStyle -> SetOptTitle(0);
    gStyle -> SetTitleSize(0.06,"XYZ"); 
    gStyle -> SetLabelSize(0.05,"XYZ");
   
    gStyle -> SetTitleOffset(1.3,"X");
    gStyle -> SetTitleOffset(1.35,"Y");

    gStyle -> SetHistLineWidth(1);
    gStyle -> SetMarkerStyle(20);
    gStyle -> SetMarkerSize(.6);
   
    gStyle->SetOptStat("");


    gStyle -> SetTextFont(42);
    gStyle -> SetTextSize(0.05);
    

    TGaxis::SetMaxDigits(3);
    

   
    //gStyle->SetStatStyle(0);
    //gStyle->SetTitleStyle(0); 
    gStyle -> SetFillColor(0);

    gROOT->ForceStyle(); 
  }
};
//################################################################################################################################################################################################
class TeresaPlottingStyle {
public:
  static void init() {

    GeneralSettings::init();
    //Legend 
    cout<<"TeresaPlottingStyle is activated!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
    

    gROOT->ForceStyle(); 
  }
};
//################################################################################################################################################################################################
class TeresaPlottingStyle2d {
public:
  static void init() {

    //Legend 
    GeneralSettings::init();
    cout<<"TeresaPlottingStyle 2d is activated!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
 
 
    gStyle -> SetPadRightMargin(0.20);
    //gStyle -> SetPadLeftMargin(0.20);
    //gStyle -> SetPadBottomMargin(0.25);
    //gStyle -> SetPadTopMargin(0.1);
    //gStyle -> SetTitleOffset(1.05,"XY");
    gStyle -> SetTitleOffset(1.25,"Z");
    gStyle->SetNdivisions(509,"Z");
    gROOT->ForceStyle(); 
  }
};
//################################################################################################################################################################################################

class TeresaPlottingStyleTalks {
public:
  static void init() {

    //Legend 
    
    gROOT  -> SetStyle("Plain");
    
    gStyle -> SetLegendFillColor(0);

    gStyle -> SetTitleFont(42,"xyz");
    gStyle -> SetLabelFont(42,"xyz");

    // Canvas
    gStyle -> SetCanvasDefH(600); //Height of canvas
    gStyle -> SetCanvasDefW(600); //Width of canvas

    gStyle -> SetPadBottomMargin(0.18);
    gStyle -> SetPadLeftMargin(0.18);

    // Pad   
    gStyle -> SetTitleSize(0.07,"X"); 
    gStyle -> SetTitleSize(0.07,"Y"); 
    gStyle -> SetLabelSize(0.05,"X");
    gStyle -> SetLabelSize(0.05,"Y");
   
    gStyle -> SetTitleOffset(1.1,"X");
    gStyle -> SetTitleOffset(1.1,"Y");
    gStyle -> SetHistLineWidth(1);
    gStyle -> SetMarkerStyle(20);
   
    //gStyle->SetOptStat("");
    //gStyle -> SetMaxDigits(3);
    //gStyle -> SetStripDecimals(true);
    //gROOT->SetNoExponent(kTRUE); 
    // gROOT  -> TGaxis.SetMaxDigits(3);
    gStyle -> SetTextFont(132);
    gStyle -> SetTextSize(0.042);
    

    //gStyle->SetStatStyle(0);
    //gStyle->SetTitleStyle(0); 
    gStyle -> SetFillColor(0);

    gROOT->ForceStyle(); 
    /*
    // Zero horizontal error bars
    gStyle->SetErrorX(0);

    //  For the canvas
    gStyle->SetCanvasBorderMode(0);
    gStyle->SetCanvasColor(kWhite);
    gStyle->SetCanvasDefH(800); //Height of canvas
    gStyle->SetCanvasDefW(800); //Width of canvas
    gStyle->SetCanvasDefX(0);   //Position on screen
    gStyle->SetCanvasDefY(0);
 
    //  For the frame
    gStyle->SetFrameBorderMode(0);
    gStyle->SetFrameBorderSize(1);
    gStyle->SetFrameFillColor(kBlack);
    gStyle->SetFrameFillStyle(0);
    gStyle->SetFrameLineColor(kBlack);
    gStyle->SetFrameLineStyle(0);
    gStyle->SetFrameLineWidth(1);
    
    //  For the Pad
    gStyle->SetPadBorderMode(0);
    gStyle->SetPadColor(kWhite);
    gStyle->SetPadGridX(false);
    gStyle->SetPadGridY(false);
    gStyle->SetGridColor(0);
    gStyle->SetGridStyle(3);
    gStyle->SetGridWidth(1);
 
    //  Margins
    gStyle->SetPadTopMargin(0.08);
    gStyle->SetPadBottomMargin(0.19);
    gStyle->SetPadLeftMargin(0.15);
    gStyle->SetPadRightMargin(0.07);

    //  For the histo:
    gStyle->SetHistLineColor(kBlack);
    gStyle->SetHistLineStyle(0);
    gStyle->SetHistLineWidth(3);
    gStyle->SetMarkerStyle(8);
    gStyle->SetMarkerSize(.8);
    gStyle->SetEndErrorSize(4);
 
    //  For the statistics box:
    gStyle->SetOptStat(0);
 
    //  For the axis
    gStyle->SetAxisColor(1,"XYZ");
    gStyle->SetTickLength(0.03,"XYZ");
    gStyle->SetNdivisions(510,"XYZ");
    gStyle->SetPadTickX(1);
    gStyle->SetPadTickY(1);
    gStyle->SetStripDecimals(kFALSE);
 
    //  For the axis labels and titles
    gStyle->SetTitleColor(1,"XYZ");
    gStyle->SetLabelColor(1,"XYZ");
    gStyle->SetLabelFont(42,"XYZ");
    gStyle->SetLabelOffset(0.007,"XYZ");
    gStyle->SetLabelSize(0.045,"XYZ");
    gStyle->SetTitleFont(42,"XYZ");
    gStyle->SetTitleSize(0.06,"XYZ");
    gStyle->SetTitleXOffset(1.2);
    gStyle->SetTitleYOffset(1.);

    //  For the legend
    gStyle->SetLegendBorderSize(0);
    //int colorList[] = {1,2,4,7,6,8,9,10,11};
    */
  }
};
#endif
