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
void example_stack(TString plotname)
{
  //  gROOT->ProcessLine(".L tdrstyle.C"); // use when available
  //  setTDRStyle(); // just to set tdrstyle
  gStyle->SetOptStat(0);
  TString copyname = plotname;
  TCanvas *c1 = new TCanvas("c1","A Simple Graph Example",200,10,700,500);
  TString Initial("base/");
  plotname = Initial + plotname;

  TLegend *leg = new TLegend(0.70,0.50,0.85,0.85,NULL,"brNDC");
  leg->SetFillStyle(0);
  leg->SetBorderSize(0);
  leg->SetFillColor(10);
  leg->SetTextSize(0.03);
  // h1 means signal & h2 ttbar
  
  TFile *ttbar = new TFile("ttbar_selection_.root");
  TFile *wh_m_100 = new TFile("wh_M_100_selection_.root");
  
  TH1F *h1 = (wh_m_100->Get(plotname))->Clone("h1");
  h1->SetLineColor(1);
  h1->SetLineWidth(2);
  h1->Scale(1.0/h1->Integral());
  h1->SetTitle(copyname);
  h1->GetXaxis()->SetTitle("dijet mass");
  h1->GetYaxis()->SetTitle("Normalized to unity/5 GeV");
  
  
  TH1F *h2 = (ttbar->Get(plotname))->Clone("h2");
  h2->SetLineColor(2);
  h2->SetLineWidth(2);
  h2->Scale(1.0/h2->Integral());
  h2->SetTitle(copyname);
  h2->GetXaxis()->SetTitle("dijet mass");
  h2->GetYaxis()->SetTitle("Normalized to unity/5 GeV");
  
  h2->Draw("hist");
  h1->Draw("hist same");
  
  leg->AddEntry(h1,"wh_M_100","l");
  leg->AddEntry(h2,"ttbar","l");
  
  leg->Draw();
  
  
  // TCanvas::Update() draws the frame, after which one can change it
  c1->Update();
  //   c1->GetFrame()->SetFillColor(21);
  c1->GetFrame()->SetBorderSize(12);
  c1->Modified();
  TString outFile("");
  outFile += plotname;
  outFile += ".pdf";
  c1->SaveAs(outFile);
}

void example_stack_all(){
  example_stack("mjj_kfit");
  example_stack("mjj_kfit_Id");
  example_stack("mjj_kfit_Id_drCut1");
  example_stack("mjj_kfit_Id_drCut2");
  example_stack("mjj_kfit_Id_drCut3");
  example_stack("mjj_kfit_Id_drCut4");
}


