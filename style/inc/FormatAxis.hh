/* ====================================================
#   Copyright (C)2019 All rights reserved.
#
#   Author        : Xin-Xin Ma
#   Email         : xxmawhu@163.com
#   File Name     : FormatAxis.hh
#   Create Time   : 2019-12-14 17:20
#   Last Modified : 2019-12-14 17:22
#   Describe      :
#
# ====================================================*/
#include <TAxis.h>
#include <iostream>
using namespace std;

void FormatAxis(TAxis* axis) {
    axis->SetLabelFont(42);
    axis->SetLabelSize(0.06);
    axis->SetLabelOffset(0.01);
    axis->SetNdivisions(505);
    axis->SetTitleFont(42);
    axis->SetTitleColor(1);
    axis->SetTitleSize(0.06);
    axis->SetNoExponent(0);
    axis->CenterTitle();
}
