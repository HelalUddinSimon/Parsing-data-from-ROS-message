#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int main() {
	vector<string> v;
	vector<string> v2;
	vector<string> v3;

	string str = "header: seq: 7550 stamp: secs: 1654457903 nsecs: 454540014 frame_id: '' name: [panda_joint1, panda_joint2, panda_joint3, panda_joint4, panda_joint5, panda_joint6, panda_joint7, panda_finger_joint1, panda_finger_joint2] position: [0.07121904858184498, -0.4682235257388547, -0.0041496520862388305, -2.7032134914230554, -0.017718688464827007, 2.2235127269870865, 0.8744310802364481, 0.04003729671239853, 0.04003729671239853] velocity: [-0.2460503909875479, -0.2250197070339677, -0.000607773911807103, 0.1676371593019008, -8.404935230919982e-05, -0.35704647571779, -0.24327792670548393, 0.0, 0.0] effort: [-0.2289014458656311, -13.368252754211426, -0.4351654648780823, 22.02277374267578, 0.3128869831562042, 1.843363881111145, -0.389145165681839, 0.0, 0.0]";


// separating joints name from string

string startDEL = "name: ";
// this is really only needed for the first delimiter
string stopDEL =  "]";

unsigned firstLim = str.find(startDEL);
unsigned lastLim = str.find(stopDEL);

string strNew = str.substr (firstLim,lastLim);
strNew.erase (0,7);
//strNew.erase(0, 1);
strNew.erase(strNew.size() - 1);
//cout << strNew;
stringstream ss(strNew);
    while (ss.good()) {
        string substr;
        getline(ss, substr, ',');
        v.push_back(substr);
    }

        for (size_t i = 0; i < v.size(); i++)
        cout << v[i] << endl;
       // cout << endl;


// Panda's arm positions

string PosstartDEL = "position:";
string PosstopDEL =  "]";

unsigned PosfirstLim = str.find(PosstartDEL);
unsigned PoslastLim = str.find(PosstopDEL);

string PosstrNew = str.substr (PosfirstLim,PoslastLim);
PosstrNew.erase (0,11);
PosstrNew.erase(PosstrNew.size() - 1);
//cout << PosstrNew;
stringstream ssp(PosstrNew);
    while (ssp.good()) {
        string substr;
        getline(ssp, substr, ',');
        v2.push_back(substr);
    }

        for (size_t j = 0; j < v2.size(); j++)
      //  cout<<"Arms Position::" << endl;
        cout << v2[j] << endl;
        cout << endl;

// Panda's arm velocity

string VelstartDEL = "velocity:";
string VelstopDEL =  "]";

unsigned VelfirstLim = str.find(VelstartDEL);
unsigned VellastLim = str.find(VelstopDEL);

string VelstrNew = str.substr (VelfirstLim,VellastLim);
VelstrNew.erase (0,11);
//strNew.erase(0, 1);
VelstrNew.erase(VelstrNew.size() - 1);
//cout << VelstrNew;
stringstream ssv(VelstrNew);
    while (ssv.good()) {
        string substr;
        getline(ssv, substr, ',');
        v2.push_back(substr);
    }

        for (size_t k = 0; k < v3.size(); k++)
      //  cout<<"Arms Position::" << endl;
        cout << v3[k] << endl;
       // cout << endl;

	return 0;
}
