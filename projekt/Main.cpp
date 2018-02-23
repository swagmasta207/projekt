#include <iostream>
#include <fstream>
#include <cstring>
#include <string.h>
#include <stdlib.h>
#include <sstream>

using namespace std;
/*

*/

typedef struct
{
    char* dat;
}Cell;

Cell cell[256][256];

string to_string(double x)
{
  ostringstream ss;
  ss << x;
  return ss.str();
}

double sumr(Cell cell[256][256], int bufx, int bufy, int lens) /// =sum(r##,xxx,yyy,jr)
{
    double S = 0.0;
    double N = 0.0;
    int i;
    for(i=0;i<lens;i++)
    {
         N = atof(cell[bufx+i][bufy].dat);
         S = S + N;
    }
    return S;
}



int main(void)
{
    ostringstream strs;
    string line;
    char *cstr = new char[line.length() + 1];
    int bufx = 0;
    int bufy = 0;
    int lens;
    int nofunc = 1;
    int x = 0;
    int jrk = 0;
    int amount = 0;
    int i[256];
    int j[256];
    double S[256];
    char* tok;
    fstream txt ;
    txt.open("tabel.txt", ios::in);
    do
    {
        bufy = 0;
        getline (txt,line);
        strcpy(cstr, line.c_str());
        tok = strtok (cstr,"|");
        while(tok != NULL)
        {
            lens = strlen(tok);
            cell[bufx][bufy].dat = (char*)malloc(lens*sizeof(char*));
            strcpy(cell[bufx][bufy].dat,tok);
            if(*(cell[bufx][bufy].dat + 0) == '=')
            {
                i[x] = bufx;
                j[x] = bufy;
                x++;
                amount++;
            }
            tok = strtok (NULL,"|");
            bufy++;
        }
        bufx++;
    }while(txt.good());
    txt.close();
    x=0;
    jrk = 0;
    if (amount <=0)
    {
        return 1;
    }
    do{
        if(*(cell[i[x]][j[x]].dat + 0) == '=')
            {
            if((10*(*(cell[i[x]][j[x]].dat + 17) - '0') + (*(cell[i[x]][j[x]].dat + 18) - '0')) == jrk)
            {
                jrk++;
                if(*(cell[i[x]][j[x]].dat + 1) == 's')
                {
                    if(*(cell[i[x]][j[x]].dat + 2) == 'u')
                    {
                        lens = 10*(*(cell[i[x]][j[x]].dat + 6) - '0') + (*(cell[i[x]][j[x]].dat + 7) - '0');
                        if(*(cell[i[x]][j[x]].dat + 5) == 'r')
                        {
                            bufx = 100*(*(cell[i[x]][j[x]].dat + 9) - '0') + 10*(*(cell[i[x]][j[x]].dat + 10) - '0') + (*(cell[i[x]][j[x]].dat + 11) - '0');
                            bufy = 100*(*(cell[i[x]][j[x]].dat + 13) - '0') + 10*(*(cell[i[x]][j[x]].dat + 14) - '0') + (*(cell[i[x]][j[x]].dat + 15) - '0');
                            snprintf(cell[i[x]][j[x]].dat, 256, "%f", sumr(cell, bufx, bufy, lens));
                            nofunc = 0;
                            x=-1;
                        }
                    }
                }
            }
        }
        x++;
    }while(x >= 0 && jrk < amount);

    if(nofunc == 0){
        bufx = 0;
        bufy = 0;
        txt.open("tabel.txt", ios::out);
        do{
            do{
                if(cell[bufx][bufy].dat != NULL)
                {
                    txt << cell[bufx][bufy].dat << "|";
                } else {
                    txt << " |";
                }
                bufy++;
            }while (cell[bufx][bufy].dat != NULL);
            txt << "\n";
            bufy = 0;
            bufx++;
        }while(cell[bufx][bufy].dat != NULL);
        txt.close();
    }
    return 0;
}

