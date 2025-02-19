/*
 *  Builder.C
 *  mmdaqToCMS
 *
 *  Created by S. Colafranceschi on 22/9/21.
 *  Creative Commons (CC BY), aka do whatever you please
 *
 */


#include <string>
#include <iostream>
#include <TTree.h>
#include <TFile.h>
#include "ReadConf.h"
#include <fstream>

using namespace std;

bool IsFileExisting(std::string filename);

int main(int argc, char* argv[]) {
//int main(string InputFile) {

   std:string ConfigFile = "ConfigFile.cfg";
   ReadConf myconfiguration;
   myconfiguration.InputFile = ConfigFile;
   myconfiguration.LoadConfiguration();

    if (argc == 3) {
        std::string RawFile(argv[1]);
        std::string ConfigFile(argv[2]);
        if (IsFileExisting(RawFile)) {
            TFile file0(RawFile.c_str());
            TTree* t = dynamic_cast<TTree*>(file0.Get("apv_raw"));
            TTree* tped = dynamic_cast<TTree*>(file0.Get("apv_raw_ped"));
            if (myconfiguration.MaxEvents < 0) {
                t->AddFriend(tped);
                t->Process("apv_raw.C+",RawFile.c_str());
            }
            else {
                t->AddFriend(tped);
                t->Process("apv_raw.C+",RawFile.c_str(),myconfiguration.MaxEvents);
            }
       }
    }
    if (argc == 2) {
        std::string RawFile(argv[1]);

	if (IsFileExisting(RawFile)) {
            TFile file0(RawFile.c_str());
            TTree* t = dynamic_cast<TTree*>(file0.Get("apv_raw"));
            TTree* tped = dynamic_cast<TTree*>(file0.Get("apv_raw_ped"));
            if (myconfiguration.MaxEvents < 0) {
                t->AddFriend(tped);
                t->Process("apv_raw.C+",RawFile.c_str());
            }
            else {
                t->AddFriend(tped);
                t->Process("apv_raw.C+",RawFile.c_str(),myconfiguration.MaxEvents);
            }
       }
    }
    return 0;
}

bool IsFileExisting(std::string filename) {    
    std::ifstream file(filename.c_str());
    bool result;
    if (!(file)) {
        std::cout << "BE CAREFUL " << filename << " does not exist" << std::endl;
        result = false;
    }
    else {
        result = true;
    }
    return result;
}
