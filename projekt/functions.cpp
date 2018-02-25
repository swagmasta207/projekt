#include <fstream>
#include <cstring>
#include <string.h>
#include <stdlib.h>
#include <sstream>
#include <ctype.h>

using namespace std;

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


double sumv(Cell cell[256][256], int bufx, int bufy, int lens) /// =sum(v##,xxx,yyy,jr)
{
    double S = 0.0;
    double N = 0.0;
    int i;
    for(i=0;i<lens;i++)
    {
         N = atof(cell[bufx][bufy+i].dat);
         S = S + N;
    }
    return S;
}



