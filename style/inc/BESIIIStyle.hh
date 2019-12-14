/* ====================================================
#   Copyright (C)2019 All rights reserved.
#
#   Author        : Xin-Xin MA
#   Email         : xxmawhu@163.com
#   File Name     : BESIIIStyle.hh
#   Created Time  : 2019-09-09 21:36
#   Last Modified : 2019-12-11 15:21
#   Describe      :
#
# ====================================================*/
#ifndef PLOT_BESIIIStyle_H
#define PLOT_BESIIIStyle_H

#include <TH1.h>
#include <TH1F.h>
#include <TF1.h>
#include <TLatex.h>
#include <TList.h>
#include <TLegend.h>
#include <TCanvas.h>
#include <TAxis.h>
#include <TStyle.h>
#include <TGraph.h>
#include <math.h>
#include <iostream>
#include <string>
using namespace std;

// Write "Preliminary" below BESIII -
// to be used together with WriteBes3()
void WritePreliminary() {
    TLatex* prelim = new TLatex(0.94, 0.86, "Preliminary");
    prelim->SetNDC();
    prelim->SetTextFont(62);
    prelim->SetTextSize(0.055);
    prelim->SetTextAlign(33);
    prelim->Draw();
}

// Set the general style options
void SetStyle() {
    gStyle->SetOptStat(0);
    gStyle->SetOptTitle(0);
    gStyle->SetPadRightMargin(0.04);
    gStyle->SetPadLeftMargin(0.18);
    gStyle->SetPadBottomMargin(0.18);
    gStyle->SetPadTopMargin(0.05);
    gStyle->SetPadTickX(0);
    gStyle->SetPadTickY(0);
    gStyle->SetLegendBorderSize(0.0);
}

// Style options for "final" plots
// (no stat/fit box)
void SetPrelimStyle() {
    gStyle->SetOptDate(0);
    gStyle->SetOptStat(0);
    gStyle->SetOptFit(0);
    gStyle->SetOptTitle(0);
}

// Style options for internal meetings
// (stat/fit box)
void SetMeetingStyle() {
    gStyle->SetOptDate(0);
    gStyle->SetOptTitle(0);
    gStyle->SetOptStat(1111);
    gStyle->SetStatBorderSize(1);
    gStyle->SetStatColor(10);
    gStyle->SetStatFont(42);
    gStyle->SetStatFontSize(0.03);
    gStyle->SetOptFit(1111);
}

#endif
