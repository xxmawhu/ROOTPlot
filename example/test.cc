#ifndef __CINT__
#include "RooGlobalFunc.h"
#endif
#include "RooRealVar.h"
#include "RooStats/SPlot.h"
#include "RooDataSet.h"
#include "RooRealVar.h"
#include "RooGaussian.h"
#include "RooExponential.h"
#include "RooChebychev.h"
#include "RooAddPdf.h"
#include "RooProdPdf.h"
#include "RooAddition.h"
#include "RooProduct.h"
#include "TCanvas.h"
#include "RooAbsPdf.h"
#include "RooFit.h"
#include "RooFitResult.h"
#include "RooWorkspace.h"
#include "RooConstVar.h"
#include "RooArgList.h"
#include <iostream>
#include <map>
#include <string>

// use this order for safety on library loading
using namespace RooFit ;
using namespace RooStats ;
using std::cout;
using std::endl;
using std::map;
using std::string;
// class RooBEFFPdf;

void usage(std::ostream& out, const TString& progName) {
    out<<"Usage:\n";
    out<<progName<<" gen #events #seed #lambda datfile\n";
    out<<"or\n";
    out<<progName<<" fit #datfile #lambda #fixlambda[1 for fix]"<<std::endl;
}


int main( int argc, char** argv )
{
    cout << "hello" << endl;
    if (argc <2) {
        usage(std::cerr, argv[0]);
        return EXIT_FAILURE;
    }
    TString Datadat = "lambda_1.dat";
    double m_lambda = 0.00;
    bool fix_lambda = false;
    int nevents = 1;
    double seed(1);

    bool m_gen = false;
    m_gen += 1;

    TString command = argv[1];
    command.ToLower();
    if (command == "gen") {
        // gen #events #seed #lambda #outfile
        nevents = atoi(argv[2]); 
        cout << "Simulate " << nevents << " events" << endl;
        seed = atoi(argv[3]);
        m_lambda = stod(string(argv[4]));
        cout << "set lambda at " << m_lambda << endl;
        Datadat = argv[5];
        m_gen = true;
    }
    else if (command == "fit") {
        // fit #datfile #lambda #fixlambda[1 for fix] 
        Datadat = argv[2];
        m_lambda = stod(string(argv[3]));
        fix_lambda = atoi(argv[4]);
        if (fix_lambda) {
            cout << "fix lambda @" << m_lambda << endl;
        }
    }
    
    cout<<"The data sample is : "<<Datadat<<endl;
    seed += 1;
    
    double high = 3.09;
    double low = 0-high;
    RooRealVar v11("v11","v11",low,high);
    RooRealVar v12("v12","v12",low,high);
    RooRealVar v13("v13","v13",low,high);
    RooRealVar v14("v14","v14",low,high);
    RooRealVar v21("v21","v21",low,high);
    RooRealVar v22("v22","v22",low,high);
    RooRealVar v23("v23","v23",low,high);
    RooRealVar v24("v24","v24",low,high);
    RooRealVar v31("v31","v31",low,high);
    RooRealVar v32("v32","v32",low,high);
    RooRealVar v33("v33","v33",low,high);
    RooRealVar v34("v34","v34",low,high);
    RooRealVar v41("v41","v41",low,high);
    RooRealVar v42("v42","v42",low,high);
    RooRealVar v43("v43","v43",low,high);
    RooRealVar v44("v44","v44",low,high);
    RooRealVar v51("v51","v51",low,high);
    RooRealVar v52("v52","v52",low,high);
    RooRealVar v53("v53","v53",low,high);
    RooRealVar v54("v54","v54",low,high);

    RooRealVar alpha("alpha", "", 0.462, 0, 1);
    RooRealVar phi("phi", "", 0.738,  -10, 10);
    RooRealVar alphaL("alphaL", "", 0.75, -10, 10);
    //RooFormulaVar alphaLbar("alphaLbar", "the alphaLbdaBar", "-alphaL", 
    //        RooArgSet(alphaL));
    RooRealVar alphaLbar("alphaLbar", "", -0.75, -1, 1);
    RooRealVar lambda("lambda", "", m_lambda, -1, 1);
    if(fix_lambda){
        lambda.setVal(0);
        lambda.setConstant();
    }
    // phi.setConstant();
    //   R.setConstant();
    //  alphaLbar.setConstant();
    //  alphaL.setConstant();

        return 1;

}
