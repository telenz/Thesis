#include "TGraphAsymmErrors.h"


class sample{


public:

  TFile *file;
  TString filename;
  TTree *tree;

  TH1D*     histo;
  TH1D*     histoNP;

  int    statistics;
  double purity;

  vector<double> *trackEta;
  vector<double> *trackPt;
  vector<double> *trackP;
  vector<double> *trackGenPt;
  vector<double> *trackASmi;
  vector<double> *trackASmiNP;
  vector<double> *trackHarm2;
  vector<double> *trackCaloIso;
  vector<double> *trackMass;
  vector<double> *trackIsolation;
  vector<double> *trackGenE;
  vector<double> *trackGenEt;
  vector<double> *trackEndVertexRho ;
  vector<double> *trackChi2;
  vector<double> *trackNdof;
  vector<double> *trackHCALRp5Isolation;
  vector<double> *trackECALRp5Isolation;
  vector<double> *trackHCALRp4Isolation;
  vector<double> *trackECALRp4Isolation;
  vector<double> *trackHCALRp3Isolation;
  vector<double> *trackECALRp3Isolation;
  vector<int>    *trackNLostOuter;
  vector<int>    *trackNLostMiddle;
  vector<int>    *trackNLostInner;
  vector<int>    *trackNValid;
  vector<int>    *trackPdgId;
  vector<int>    *trackStatus;
  double weight;
  double weightReweighting;
  double weight_xsec_lumi;
  double met;
  double leadingJetPt;

  vector<double> *trackDeDx1;
  vector<double> *trackDeDx2;
  vector<double> *trackDeDx3;
  vector<double> *trackDeDx4;
  vector<double> *trackDx1;
  vector<double> *trackDx2;
  vector<double> *trackDx3;
  vector<double> *trackDx4;

  vector<int>    *trackMeasSize;

  sample(TString _filename){

    filename = _filename;
    tree=0;
    file=0;
    histo=0;
    histoNP=0;
    statistics=0;
    purity=0;

    trackEta        = 0;
    trackEta        = 0;
    trackPt         = 0;
    trackP          = 0;
    trackGenPt      = 0;
    trackASmi       = 0;
    trackASmiNP     = 0;
    trackHarm2      = 0;
    trackCaloIso    = 0;
    trackMass       = 0;
    trackIsolation  = 0;
    trackGenE       = 0;
    trackGenEt      = 0;
    trackEndVertexRho = 0;
    trackChi2 = 0;
    trackNdof = 0;
    trackHCALRp5Isolation = 0;
    trackECALRp5Isolation = 0;
    trackHCALRp4Isolation = 0;
    trackECALRp4Isolation = 0;
    trackHCALRp3Isolation = 0;
    trackECALRp3Isolation = 0;
    trackNLostOuter = 0;
    trackNLostMiddle = 0;
    trackNLostInner = 0;
    trackNValid     = 0;
    trackPdgId      = 0;
    trackStatus     = 0;
    trackDeDx1   = 0;
    trackDeDx2   = 0;
    trackDeDx3   = 0;
    trackDeDx4   = 0;
    trackDx1   = 0;
    trackDx2   = 0;
    trackDx3   = 0;
    trackDx4   = 0;
    trackMeasSize= 0;

    //   Double_t xbinsECalo[3]  = {0,20,200};
    //Double_t xbinsASmi[3]   = {0,0.3,1};
    //Double_t xbinsNHits[4]  = {3,5,7,25};

    //histoECalo  = new TH1D("predASmi","predASmi",2,xbinsECalo);
    //histoASmi   = new TH1D("predASmi","predASmi",2,xbinsASmi);
    //histoNValid = new TH1D("predNValid","predNValid",3,xbinsNHits);
  };

  void getTree(TString idir){
    TFile *f1 = new TFile(idir + "/" + filename + ".root","READ");
    if(!f1){
      cout<<"File not available: "<<filename<<endl<<endl;
    }
    f1->GetObject("chiTracksCandidateTracks/Variables",tree);
  }
  
  void getTreeVariables(){
    tree->SetBranchStatus("*",0);
    //tree->SetBranchStatus("trackEta",1);
    //tree->SetBranchAddress("trackEta",&trackEta);
    tree->SetBranchStatus("trackP",1);
    tree->SetBranchAddress("trackP",&trackP);
    tree->SetBranchStatus("trackDeDxASmi",1);
    tree->SetBranchAddress("trackDeDxASmi",&trackASmi);
    tree->SetBranchStatus("trackDeDxASmiNP",1);
    tree->SetBranchAddress("trackDeDxASmiNP",&trackASmiNP);
    //tree->SetBranchStatus("trackCaloIsolation",1);
    //tree->SetBranchAddress("trackCaloIsolation",&trackCaloIso);
    // tree->SetBranchStatus("trackNLostOuter",1);
    //tree->SetBranchAddress("trackNLostOuter",&trackNLostOuter);

    tree->SetBranchStatus("trackNLostMiddle",1);
    tree->SetBranchAddress("trackNLostMiddle",&trackNLostMiddle);
    tree->SetBranchStatus("trackNLostInner",1);
    tree->SetBranchAddress("trackNLostInner",&trackNLostInner);
    
    tree->SetBranchStatus("trackNValid",1);
    tree->SetBranchAddress("trackNValid",&trackNValid);
    //tree->SetBranchStatus("MET",1);
    //tree->SetBranchAddress("MET",&met);
    //tree->SetBranchStatus("LeadingJetPt",1);
    //tree->SetBranchAddress("LeadingJetPt",&leadingJetPt);
    tree->SetBranchStatus("weight",1);
    tree->SetBranchAddress("weight",&weight);
    tree->SetBranchStatus("weightReweighting",1);
    tree->SetBranchAddress("weightReweighting",&weightReweighting);
    tree->SetBranchStatus("weight_xsec_lumi",1);
    tree->SetBranchAddress("weight_xsec_lumi",&weight_xsec_lumi);
  };


  void Selection(int nHitsCut){

    
    histo   -> SetTitle("");
    histoNP -> SetTitle("");

    statistics = 0;
    purity=0;

    cout<<"Entries = "<<tree->GetEntries()<<endl;


    for(int n=0; n<tree->GetEntries(); n++){

      weightReweighting = 1.;
      tree->GetEntry(n);
     

      for(unsigned int i=0; i<trackASmi->size(); i++){

	//if(trackNValid->at(i)<10)                                     continue; 
	//if(trackP->at(i)<10)                                          continue; 
	if(trackNLostMiddle->at(i)!=0 )                                     continue; 
	if(trackNLostInner->at(i) !=0 )                                     continue; 
	histo         -> Fill(trackASmi   -> at(i),weight*weight_xsec_lumi*weightReweighting);
	histoNP       -> Fill(trackASmiNP -> at(i),weight*weight_xsec_lumi*weightReweighting);
	statistics +=1;
      }
    
    }

    purity=statistics/purity;
  };

};
