#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>

using namespace std;
/*

*/

typedef struct
{
    char* dat;
}Cell;

Cell cell[256][256];

double sumr(Cell cell[256][256], int bufx, int bufy, int lens)
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

    string line;
    char *cstr = new char[line.length() + 1];
    int bufx = 0;
    int bufy = 0;
    int lens;
    char* fun ;
    fun = (char*)malloc(sizeof(char));
    *(fun + 0) = '='; // puue
    int i, j;
    double S = 0.0;
    char* tok; //tok = strtok (line,"#");
    ifstream txt ("tabel.txt");
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
            //cout << bufx << "|" << bufy << " - " << cell[bufx][bufy].dat << endl;
            if(*(cell[bufx][bufy].dat + 0) == '=')
            {
                i = bufx;
                j = bufy;
            }
            tok = strtok (NULL,"|");
            bufy++;
        }
        bufx++;
    }while(txt.good());
    /*cout << endl << endl;
    for(i=0;i<256;i++)
    {
        for(j=0;j<256;j++)
        {
            if(cell[i][j].dat != NULL)
            {
                cout << i << "|" << j << " - " << cell[i][j].dat << endl;
            }
        }
    }*/
    if(*(cell[i][j].dat + 1) == 's')
    {
        if(*(cell[i][j].dat + 2) == 'u')
        {
            lens = *(cell[i][j].dat + 6) - '0';
            if(*(cell[i][j].dat + 5) == 'r')
            {
                bufx = 100*(*(cell[i][j].dat + 8) - '0') + 10*(*(cell[i][j].dat + 9) - '0') + (*(cell[i][j].dat + 10) - '0');
                bufy = 100*(*(cell[i][j].dat + 12) - '0') + 10*(*(cell[i][j].dat + 13) - '0') + (*(cell[i][j].dat + 14) - '0');
                S = sumr(cell, bufx, bufy, lens);
            }
        }
    }
    //cout << "Sum: " << S << endl;
    return 0;
}

