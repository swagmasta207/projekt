#include <iostream>

#include <fstream>

using namespace std;

double SOTSMAKS = 0.33;

int main(void)
{
    ifstream palkfail ("sotsinovsky.txt");
    //ofstream sotsfail;
    string line;
    int palk;

    getline(palkfail, line);
    palkfail.close();
    if ( ! (istringstream(line) >> palk) ) palk = 0;
    if (palk < 470){palk = 470;}
    ofstream sotsfail ("sotsinovsky.txt", ios::trunc);
    sotsfail << palk*SOTSMAKS;
    sotsfail.close();
    return 0;
}
