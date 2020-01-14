/* ====================================================
#   Copyright (C)2019 All rights reserved.
#
#   Author        : Xin-Xin MA
#   Email         : xxmawhu@163.com
#   File Name     : Format.h
#   Created Time  : 2019-09-09 21:36
#   Last Modified : 2019-12-11 15:16
#   Describe      :
#
# ====================================================*/
#ifndef PLOT_Format_H
#define PLOT_Format_H
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
using std::string;

// Format for data points
void FormatData(TH1* datahist) {
    datahist->SetMarkerStyle(20);
    datahist->SetMarkerSize(1);
    datahist->SetLineWidth(2);

    FormatAxis(datahist->GetXaxis());
    FormatAxis(datahist->GetYaxis());
}
void FormatYAxis(TAxis* axis, double _min = 0, double _max = 1) {
    axis->SetLabelFont(42);
    axis->SetLabelSize(0.06);
    axis->SetLabelOffset(0.01);
    axis->SetNdivisions(505);
    axis->SetTitleFont(42);
    axis->SetTitleColor(1);
    axis->SetTitleSize(0.06);
    axis->SetNoExponent(0);
    axis->CenterTitle();
    cout << "Inf::range: [" << _min << ", " << _max << "]" << endl;
    double _factor = (_max - _min) / 2;
    double _offset = 1.0;
    if (_factor > 1e1 && _factor < 1e2) _offset = 1.2;
    if (_factor > 1e2 && _factor < 1e3) _offset = 1.1;
    if (_factor > 1e3 && _factor < 1e4) _offset = 1.2;
    if (_factor > 1e4 && _factor < 1e5) _offset = 1.1;
    // axis->SetTitleOffset(_offset);
    cout << "Inf::SetTitleOffset " << _offset << endl;
    TGaxis* xaxis = (TGaxis*)axis;
    xaxis->SetMaxDigits(3);
}
void Format(TH1* datahist, string unit = "MeV") {
    // datahist->SetMaximum(datahist->GetMaximum()/0.7);
    TGaxis* xaxis = (TGaxis*)datahist->GetYaxis();
    xaxis->SetMaxDigits(3);
    FormatAxis(datahist->GetXaxis());
    FormatYAxis(datahist->GetYaxis(), datahist->GetMinimum(),
                datahist->GetMaximum());
    double _binwidth = datahist->GetBinWidth(2);
    TString _unit = unit;
    if (_unit == "MeV") {
        _binwidth = _binwidth * 1e3;
    }
    cout << "Inf:: the bin width is  " << _binwidth << endl;
    char ytitle[200];
    if (_binwidth > 0.1) {
        sprintf(ytitle, "Events/ %.1f %s", _binwidth, unit.c_str());
        cout << "Inf::Y title : " << ytitle << endl;
    } else if (0.01 < _binwidth && _binwidth < 0.1) {
        sprintf(ytitle, "Events/ %0.2f %s", _binwidth, unit.c_str());
        cout << "Inf::Y title : " << ytitle << endl;
    } else if (1e-3 <= _binwidth && _binwidth < 1e-2) {
        sprintf(ytitle, "Events/ %0.3f %s", _binwidth, unit.c_str());
        cout << "Inf::Y title : " << ytitle << endl;
    } else if (1e-4 <= _binwidth && _binwidth < 1e-3) {
        sprintf(ytitle, "Events/ %.4f %s", _binwidth, unit.c_str());
        cout << "Inf::Y title : " << ytitle << endl;
    } else if (_binwidth < 1e-4) {
        sprintf(ytitle, "Events/ %.5f %s", _binwidth, unit.c_str());
        cout << "Inf::Y title : " << ytitle << endl;
    }
    datahist->GetYaxis()->SetTitle(ytitle);
}

void Format(TCanvas* c) {
    c->SetRightMargin(0.01);
    c->SetLeftMargin(0.15);
    c->SetTopMargin(0.05);
    c->SetBottomMargin(0.18);
}
void Format(TPaveText* pt) {
    pt->SetTextFont(132);
    pt->SetTextAlign(12);  // zuo dui qi
    pt->SetBorderSize(0);
    pt->SetFillColor(0);
}

void Format(TLegend* leg) {
    leg->SetTextFont(42);
    leg->SetFillColor(0);
    // leg->SetLineColor(10);
    leg->SetLineStyle(2);
    leg->SetLineWidth(0);
    leg->SetFillColorAlpha(0, 1);
    leg->SetTextSize(0.0);
    leg->SetBorderSize(0.0);
}
void Format(TArrow* arr) {
    arr->SetLineWidth(2);
    arr->SetLineColor(kRed);
}
// Graph Format for second MC or background
// (Blue line)
void FormatMC2(TGraph* mc2hist) {
    mc2hist->SetLineColor(3);
    mc2hist->SetLineWidth(2);
    mc2hist->SetLineStyle(9);
    mc2hist->SetFillColor(3);
    //  mc2hist->SetFillStyle(3001);
}

void Format(RooPlot* frame, string unit = "MeV") {
    frame->SetMinimum(0.01);
    frame->SetMaximum(frame->GetMaximum() / 0.7);
    TGaxis* xaxis = (TGaxis*)frame->GetYaxis();
    xaxis->SetMaxDigits(3);
    FormatAxis(frame->GetXaxis());
    FormatYAxis(frame->GetYaxis(), frame->GetMinimum(), frame->GetMaximum());
    double _binwidth = frame->GetXaxis()->GetBinWidth(2);
    TString _unit = unit;
    if (_unit == "MeV") {
        _binwidth = _binwidth * 1e3;
    }
    cout << "Inf:: the bin width is  " << _binwidth << endl;
    char ytitle[200];
    if (_binwidth > 0.1) {
        sprintf(ytitle, "Events/ %.1f %s", _binwidth, unit.c_str());
        cout << "Inf::Y title : " << ytitle << endl;
    } else if (0.01 < _binwidth && _binwidth < 0.1) {
        sprintf(ytitle, "Events/ %0.2f %s", _binwidth, unit.c_str());
        cout << "Inf::Y title : " << ytitle << endl;
    } else if (1e-3 <= _binwidth && _binwidth < 1e-2) {
        sprintf(ytitle, "Events/ %0.3f %s", _binwidth, unit.c_str());
        cout << "Inf::Y title : " << ytitle << endl;
    } else if (1e-4 <= _binwidth && _binwidth < 1e-3) {
        sprintf(ytitle, "Events/ %.4f %s", _binwidth, unit.c_str());
        cout << "Inf::Y title : " << ytitle << endl;
    } else if (_binwidth < 1e-4) {
        sprintf(ytitle, "Events/ %.5f %s", _binwidth, unit.c_str());
        cout << "Inf::Y title : " << ytitle << endl;
    }
    frame->GetYaxis()->SetTitle(ytitle);
}
void Format(TCanvas& c) {
    c.SetRightMargin(0.10);
    c.SetLeftMargin(0.2);
    c.SetTopMargin(0.05);
    c.SetBottomMargin(0.25);
}

#endif
