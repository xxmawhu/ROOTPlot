{
    printf("Welcome to the ROOT!\n");
    gROOT->ProcessLine(".include /path/to/inc");
    gStyle->SetTitleColor(0);
    gStyle->SetStatColor(0);
    gStyle->SetTitleFillColor(0);

    // set the paper & margin sizes
    // gStyle->SetPaperSize(20,26);
    // gStyle->SetPadTopMargin(0.01);
    // gStyle->SetPadRightMargin(0.12);
    // gStyle->SetPadBottomMargin(0.13);
    // gStyle->SetPadBottomMargin(0.04);

    // gStyle->SetPadLeftMargin(0.15);

    // use large Times-Roman fonts
    gStyle->SetTitleFont(132, "xyz");   // set the all 3 axes title font
    gStyle->SetTitleFont(132, " ");     // set the pad title font
    gStyle->SetTitleSize(0.06, "xyz");  // set the 3 axes title size
    gStyle->SetTitleSize(0.06, " ");    // set the pad title size
    gStyle->SetLabelFont(132, "xyz");
    gStyle->SetLabelSize(0.05, "xyz");
    gStyle->SetTextFont(132);
    gStyle->SetTextSize(0.08);
    gStyle->SetStatFont(132);

    // use bold lines and markers
    gStyle->SetMarkerStyle(8);
    gStyle->SetHistLineWidth(2);
    // gStyle->SetLineStyleString(2,"[12 12]"); // postscript dashes

    //..Get rid of X error bars
    gStyle->SetErrorX(0.001);

    // do not display any of the standard histogram decorations
    //		gStyle->SetOptTitle(0);
    //		gStyle->SetOptStat(0);
    //		gStyle->SetOptFit(0);

    // put tick marks on top and RHS of plots
    gStyle->SetPadTickX(0);
    gStyle->SetPadTickY(0);

    gStyle->SetFrameBorderMode(0);
    gStyle->SetCanvasBorderMode(0);
    gStyle->SetPadBorderMode(0);
    gStyle->SetPadColor(0);
    gStyle->SetCanvasColor(0);
    gStyle->SetStatColor(0);
    gStyle->SetTitleFillColor(0);

    // set the paper & margin sizes
    //  gStyle->SetPaperSize(20,26);
    //  gStyle->SetPadTopMargin(0.04);
    //  gStyle->SetPadRightMargin(0.04);
    //  gStyle->SetPadBottomMargin(0.15);
    //  gStyle->SetPadLeftMargin(0.16);

    // use large Times-Roman fonts
    gStyle->SetTitleFont(132, "xyz");   // set the all 3 axes title font
    gStyle->SetTitleFont(132, " ");     // set the pad title font
    gStyle->SetTitleSize(0.06, "xyz");  // set the 3 axes title size
    gStyle->SetTitleSize(0.06, " ");    // set the pad title size
    gStyle->SetLabelFont(132, "xyz");
    gStyle->SetLabelSize(0.05, "xyz");
    gStyle->SetTextFont(132);
    gStyle->SetTextSize(0.08);
    gStyle->SetStatFont(132);

    // use bold lines and markers
    gStyle->SetMarkerStyle(8);
    gStyle->SetHistLineWidth(2);
    gStyle->SetLineStyleString(2, "[12 12]");  // postscript dashes

    //..Get rid of X error bars
    gStyle->SetErrorX(0.001);

    // do not display any of the standard histogram decorations
    //		gStyle->SetOptTitle(0);
    //		gStyle->SetOptStat(0);
    //		gStyle->SetOptFit(0);

    // put tick marks on top and RHS of plots
    gStyle->SetPadTickX(0);
    gStyle->SetPadTickY(0);

    // legend
    gStyle->SetLegendBorderSize(0.0);
}
