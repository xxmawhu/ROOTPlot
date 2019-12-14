/* ====================================================
#   Copyright (C)2019 All rights reserved.
#
#   Author        : Xin-Xin Ma
#   Email         : xxmawhu@163.com
#   File Name     : FormatYAxis.hh
#   Create Time   : 2019-12-14 17:20
#   Last Modified : 2019-12-14 17:23
#   Describe      :
#
# ====================================================*/
#include <TAxis.h>
#include <iostream>
using namespace std;

void FormatYAxis(TAxis* axis, double offset = 1.2) {
    axis->SetLabelFont(42);
    axis->SetLabelSize(0.06);
    axis->SetLabelOffset(0.01);
    axis->SetNdivisions(505);
    axis->SetTitleFont(42);
    axis->SetTitleColor(1);
    axis->SetTitleSize(0.06);
    axis->SetNoExponent(0);
    axis->CenterTitle();
    axis->SetTitleOffset(offset);
    TGaxis* xaxis = (TGaxis*)axis;
    xaxis->SetMaxDigits(3);
}
