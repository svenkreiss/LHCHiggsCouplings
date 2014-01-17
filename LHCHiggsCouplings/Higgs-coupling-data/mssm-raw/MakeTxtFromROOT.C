// Authors: Andre David and Cristovao Beirao da Cruz e Silva (August 2012)
// Copyright: This work is licensed under a Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License.

#include <iostream>
#include <fstream>
#include <iomanip>

#include "TString.h"
#include "TH1F.h"
#include "TFile.h"

using namespace std;

void MakeTxtFromROOT(TString input1, TString input2, TString output)
{
  TFile* inFile2 = new TFile(input2, "READ");
  TFile* inFile1 = new TFile(input1, "READ");

  ofstream myfile;
  myfile.open(output, ios_base::out);

  myfile.setf(ios::left);
  myfile << setw(8) << "mH_GeV"
		  << setw(20) << "sigma_ggH_pb"
		  << setw(20) << "sigma_tt/sigma_ggH"
		  << setw(20) << "sigma_bb/sigma_ggH"
		  << setw(20) << "sigma_tb/sigma_ggH"
		  << endl;

  const Double_t minMass = 110., maxMass = 140., stepMass = 1.;

  TH1F* h_tt = (TH1F*)inFile1->Get("h_tt");
  TH1F* h_bb = (TH1F*)inFile1->Get("h_bb");
  TH1F* h_tb = (TH1F*)inFile1->Get("h_tb");
  TH1F* h_addtoploop = (TH1F*)inFile2->Get("h_addtoploop");

  for(Double_t i = minMass; i <= maxMass; i += stepMass)
  {
    int k = h_tt->GetXaxis()->FindBin(i);
    Double_t top = h_tt->GetBinContent(k);

    k = h_bb->GetXaxis()->FindBin(i);
    Double_t bottom = h_bb->GetBinContent(k);

    k = h_tb->GetXaxis()->FindBin(i);
    Double_t topBottom = h_tb->GetBinContent(k);

    k = h_addtoploop->GetXaxis()->FindBin(i);
    Double_t topExtra = h_addtoploop->GetBinContent(k);

    Double_t sum = top + topExtra + bottom + topBottom;

    myfile.precision(1);
    myfile << fixed << setw(8) << i;
    myfile.precision(6);
    myfile << scientific
    		<< setw(20) << sum
    		<< setw(20) << (top + topExtra)/sum
    		<< setw(20) << bottom/sum
    		<< setw(20) << topBottom/sum
    		<< endl;
  }

  myfile.close();
}

void MakeTxtFromROOT()
{
	MakeTxtFromROOT("./higlu_7TeV.root", "./gghatnnlo_7TeV.root", "../ggH_7TeV.txt");
	MakeTxtFromROOT("./higlu_8TeV.root", "./gghatnnlo_8TeV.root", "../ggH_8TeV.txt");
}
