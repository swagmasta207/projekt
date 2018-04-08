#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

double SOTSMAKS = 0.33;
double TKINDLUSTUS = 0.016;
double KINDLUSTUS = 0.008;

int main(void)
{
    ifstream palkfail ("palk.txt");

    string line;
    int palk;
    int spalk;
    getline(palkfail, line);
    palkfail.close();
    if ( ! (istringstream(line) >> palk) ) palk = 0;
    if (palk < 470){spalk = 470;}
    else {spalk = palk;}
    ofstream sotsfail ("maksud.txt", ios::trunc);
    sotsfail << spalk*SOTSMAKS;
    sotsfail << endl;
    sotsfail << palk*TKINDLUSTUS;
    sotsfail << endl;
    sotsfail << palk*KINDLUSTUS;
    sotsfail.close();
    return 0;
}
