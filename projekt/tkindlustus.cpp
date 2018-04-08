#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

double KINDLUSTUS = 0.016;

int main(void)
{
    ifstream palkfail ("tkindlustus.txt");
    string line;
    int palk;

    getline(palkfail, line);
    palkfail.close();
    if ( ! (istringstream(line) >> palk) ) palk = 0;

    ofstream kindfail ("tkindlustus.txt", ios::trunc);
    kindfail << palk*KINDLUSTUS;
    kindfail.close();
    return 0;
}
