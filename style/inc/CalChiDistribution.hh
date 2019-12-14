/* ====================================================
#   Copyright (C)2019 All rights reserved.
#
#   Author        : Xin-Xin Ma
#   Email         : xxmawhu@163.com
#   File Name     : CalChiDistribution.hh
#   Create Time   : 2019-12-03 13:55
#   Last Modified : 2019-12-03 15:46
#   Describe      :
#
# ====================================================*/
#include <iostream>
using namespace std;

TGraphErrors CalChiDistribution(const TH1* hdata, const TH1* hmc) {
    // first histogram must be data, the last histogram is mc distribtuion
    // hdata and hmc must have same number of bins and bin size
    // the chi = (n_data - n_mc)/sigma
    //  where the sigma = sqrt(n_data)
    // return a TGraph
    //
    // check the bins
    if (hdata->GetNbinsX() != hmc->GetNbinsX()) {
        std::cout << "Error: the number of bins between data and MC is not equl"
                  << std::endl;
        return TGraphErrors(0);
    }
    // if one bin has less than 10 events, then merge this bin into next one.
    double xpos, ypos;
    double erry;
    double ndata = 0.0;
    double nmc = 0.0;
    int nbin = hdata->GetNbinsX();
    double xarroy[nbin];
    double yarroy[nbin];
    double errarroy[nbin];
    double errX[nbin];
    int inx = 0;
    for (int i = 1; i <= hdata->GetNbinsX(); ++i) {
        double tmp_xpos = hdata->GetBinCenter(i);
        double tmp_ndata = hdata->GetBinContent(i);
        double tmp_nmc = hmc->GetBinContent(i);
        if (tmp_ndata < 0.1) {
            continue;
        }
        xpos = (tmp_ndata * tmp_xpos + xpos * ndata) / (ndata + tmp_ndata);
        ndata += tmp_ndata;
        nmc += tmp_nmc;
        if (ndata < 10) {
            continue;
        }
        erry = sqrt(ndata);
        ypos = (ndata - nmc) / erry;
        xarroy[inx] = xpos;
        yarroy[inx] = ypos;
        errarroy[inx] = 1.0;
        errX[inx] = 0.0;
        //  cout << "index " << inx << endl;
        //  cout << "x, y, err = " << xpos << ", " << ypos << ", " << erry <<
        //  endl;
        inx += 1;
        ndata = 0.0;
        nmc = 0.0;
        xpos = 0.0;
    }
    TGraphErrors graph(inx, xarroy, yarroy, errX, errarroy);
    cout << "xmax = " << hdata->GetXaxis()->GetXmax() << endl;
    cout << "xmin = " << hdata->GetXaxis()->GetXmin() << endl;
    graph.GetXaxis()->SetRangeUser(hdata->GetXaxis()->GetXmin(),
                                   hdata->GetXaxis()->GetXmax());
    graph.GetXaxis()->SetLimits(hdata->GetXaxis()->GetXmin(),
                                hdata->GetXaxis()->GetXmax());
    graph.GetYaxis()->SetLimits(-5.01, 5.01);
    graph.GetYaxis()->SetRangeUser(-5.01, 5.01);
    graph.GetYaxis()->SetNdivisions(20);
    graph.GetYaxis()->SetLabelFont(42);
    graph.GetYaxis()->SetTicks("-");
    return graph;
}
