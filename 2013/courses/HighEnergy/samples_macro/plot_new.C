#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "TH1F.h"
#include "TFile.h"
#include "TStyle.h"
#include "TCanvas.h"
#include "TLegend.h"

using namespace std;
void plot(TString plotname, string axislabel, int bin, double xmin, double xmax)
{

 //  setTDRStyle();
  gStyle->SetOptStat(0);
  TCanvas *c1 = new TCanvas("c1","A Simple Graph Example",200,10,700,500);

  TLegend *leg = new TLegend(0.70,0.50,0.85,0.85,NULL,"brNDC");
  leg->SetFillStyle(0);
  leg->SetBorderSize(0);
  leg->SetFillColor(10);
  leg->SetTextSize(0.03);


//  c1->SetLogx();
  // edit h1 means signal & h2 ttbar

  TFile *f_gamma = new TFile("path/to/file1");

  TFile *f_qcd = new TFile("path/to/file2");

  TFile *f_elec = new TFile("path/to/file3");

  TFile *f_tau = new TFile("path/to/file4");


  TFile *f_diph = new TFile("path/to/file5");

  TFile *f_dielec = new TFile("path/to/file6");

  TFile *f_ditau = new TFile("path/to/file7");

//..........................................
// ..gamma
//..........................................

  f_gamma->cd();

  TH1F *h1 = new TH1F("h1","",bin,xmin,xmax);
  TreeB->Project("h1",plotname);


//------------------------------------------
// qcd
//-----------------------------------------

  f_qcd->cd();

  TH1F *h2 = new TH1F("h2","",bin,xmin,xmax);
  TreeB->Project("h2",plotname);

//------------------------------------------
// ..electron
//-----------------------------------------

  f_elec->cd();

  TH1F *h3 = new TH1F("h3","",bin,xmin,xmax);
  TreeB->Project("h3",plotname);


//------------------------------------------
// ..tau
//-----------------------------------------

  f_tau->cd();

  TH1F *h4 = new TH1F("h4","",bin,xmin,xmax);
  TreeB->Project("h4",plotname);

//------------------------------------------
// ..di-photon
//-----------------------------------------

  f_diph->cd();

  TH1F *h5 = new TH1F("h5","",bin,xmin,xmax);
  TreeB->Project("h5",plotname);

//------------------------------------------
// ..di-electron
//-----------------------------------------

  f_dielec->cd();

  TH1F *h6 = new TH1F("h6","",bin,xmin,xmax);
  TreeB->Project("h6",plotname);

//------------------------------------------
// ..di-tau
//-----------------------------------------

  f_ditau->cd();

  TH1F *h7 = new TH1F("h7","",bin,xmin,xmax);
  TreeB->Project("h7",plotname);

//====================================================================
  h1->SetLineColor(1);
  h1->SetLineWidth(2);
  h1->Scale(1.0/h1->Integral());
  h1->SetTitle("");

//  h1->SetAxisRange(0., 1.0,"Y");
//  h1->SetAxisRange(-3.0, 0.0,"X");

  h1->GetXaxis()->SetTitle(axislabel.c_str());

//  h1->GetYaxis()->SetTitle("Normalized to unity/5 GeV");
  h1->GetYaxis()->SetTitle("Normalized to unity");
 
//--------------------------------------------- 

  h2->SetLineColor(2);
  h2->SetLineWidth(2);
  h2->Scale(1.0/h2->Integral());

//  h2->SetAxisRange(0., 0.06,"Y");

  h2->GetYaxis()->SetTitle("Normalized to unity");

//------------------------------------------
  h3->SetLineColor(3);
  h3->SetLineWidth(2);
  h3->Scale(1.0/h3->Integral());

  h3->GetYaxis()->SetTitle("Normalized to unity");

//------------------------------------------
  h4->SetLineColor(4);
  h4->SetLineWidth(2);
  h4->Scale(1.0/h4->Integral());

  h4->GetYaxis()->SetTitle("Normalized to unity");

//------------------------------------------
  h5->SetLineColor(6);
  h5->SetLineWidth(2);
  h5->Scale(1.0/h5->Integral());

//  h5->GetYaxis()->SetRangeUser(min, max)
//  h5->SetAxisRange(0.,5.0,"Y");
  h5->GetYaxis()->SetTitle("Normalized to unity");

//------------------------------------------
  h6->SetLineColor(7);
  h6->SetLineWidth(2);
  h6->Scale(1.0/h6->Integral());

  h6->GetYaxis()->SetTitle("Normalized to unity");

//------------------------------------------
  h7->SetLineColor(9);
  h7->SetLineWidth(2);
  h7->Scale(1.0/h7->Integral());

  h7->GetYaxis()->SetTitle("Normalized to unity");

//------------------------------------------


//====================================================================
//====================================================================


  c1->cd();  

// maximum in Y axis
  cout << "test1: "<<h1->GetMaximum() << endl;
  cout << "test7: "<<h7->GetMaximum() << endl;
  double max_y = h1->GetMaximum();
  if (max_y < h2->GetMaximum()) max_y = h2->GetMaximum();
  if (max_y < h3->GetMaximum()) max_y = h3->GetMaximum();
  if (max_y < h4->GetMaximum()) max_y = h4->GetMaximum();
  if (max_y < h5->GetMaximum()) max_y = h5->GetMaximum();
  if (max_y < h6->GetMaximum()) max_y = h6->GetMaximum();
  if (max_y < h7->GetMaximum()) max_y = h7->GetMaximum();

  cout << "ymax: "<<max_y << endl;
  h1->SetAxisRange(0.,max_y*1.1,"Y");


  h1->Draw("hist");
  h2->Draw("hist same");
  h3->Draw("hist same");
  h4->Draw("hist same");
  h5->Draw("hist same");
  h6->Draw("hist same");
  h7->Draw("hist same");
  
  leg->AddEntry(h1,"photon","l");
  leg->AddEntry(h2,"qcd","l");
  leg->AddEntry(h3,"electron","l");
  leg->AddEntry(h4,"tau","l");
  leg->AddEntry(h5,"di-photon","l");
  leg->AddEntry(h6,"di-electron","l");
  leg->AddEntry(h7,"di-tau","l");
  
  leg->Draw();
  

  // TCanvas::Update() draws the frame, after which one can change it
  c1->Update();
  //   c1->GetFrame()->SetFillColor(21);
  c1->GetFrame()->SetBorderSize(12);
  c1->Modified();


  c1->SaveAs(plotname+".pdf");
//  c1->SaveAs("delJ_ISRoff.pdf");
}

void plot_all(){
plot("trackno","trackno",20,0,20);
plot("thetaJ","thetaJ",30,-3,0);
plot("tau1","tau1",40,-4,0);
plot("tau21","tau21",50,0,1);
plot("LambdaJ","LambdaJ",30,0,-3);
plot("epsJ","epsJ",40,0,0.4);
plot("rho","rho",20,0,2.0);
/*
plot("ecfr1",20,0,20);
plot("ecfr2",30,0,3);
plot("ecfr3",50,0,0.5);
plot("ecfr4",20,0,0.2);
plot("ecfdr1","ecfdr1",100,0,0.3);
plot("ecfdr2","ecfdr2",100,0,0.3);
plot("ecfdr3","ecfdr3",100,0,0.3);
plot("ecfdr4","ecfdr4",100,0,0.3);
*/
}

