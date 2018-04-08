#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

double KINDLUSTUS = 0.008;

int main(void)
{
    ifstream palkfail ("kindlustus.txt");
    string line;
    int palk;

    getline(palkfail, line);
    palkfail.close();
    if ( ! (istringstream(line) >> palk) ) palk = 0;

    ofstream kindfail ("kindlustus.txt", ios::trunc);
    kindfail << palk*KINDLUSTUS;
    kindfail.close();
    return 0;
}
