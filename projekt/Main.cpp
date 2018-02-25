#include <iostream>
#include "functions.cpp"

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
    int k = 0;
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
    } else
    {
        /// katkise funktsiooni kontroll
        for(x=0;x<amount;x++)
        {
            k=-1;
            do{
                k++;
            }while((*(cell[i[x]][j[x]].dat + k) != NULL));
            if(k!=20)
            {
                return 1;
            }
            if(isalpha(*(cell[i[x]][j[x]].dat + 1)) == 0){return 1;}
            if(isalpha(*(cell[i[x]][j[x]].dat + 2)) == 0){return 1;}
            if(isalpha(*(cell[i[x]][j[x]].dat + 3)) == 0){return 1;}
            if((*(cell[i[x]][j[x]].dat + 4)) != '('){return 1;}
            if(isalpha(*(cell[i[x]][j[x]].dat + 5)) == 0){return 1;}
            if(isdigit(*(cell[i[x]][j[x]].dat + 6)) == 0){return 1;}
            if(isdigit(*(cell[i[x]][j[x]].dat + 7)) == 0){return 1;}
            if((*(cell[i[x]][j[x]].dat + 8)) != ','){return 1;}
            if(isdigit(*(cell[i[x]][j[x]].dat + 9)) == 0){return 1;}
            if(isdigit(*(cell[i[x]][j[x]].dat + 10)) == 0){return 1;}
            if(isdigit(*(cell[i[x]][j[x]].dat + 11)) == 0){return 1;}
            if((*(cell[i[x]][j[x]].dat + 12)) != ','){return 1;}
            if(isdigit(*(cell[i[x]][j[x]].dat + 13)) == 0){return 1;}
            if(isdigit(*(cell[i[x]][j[x]].dat + 14)) == 0){return 1;}
            if(isdigit(*(cell[i[x]][j[x]].dat + 15)) == 0){return 1;}
            if((*(cell[i[x]][j[x]].dat + 16)) != ','){return 1;}
            if(isdigit(*(cell[i[x]][j[x]].dat + 17)) == 0){return 1;}
            if(isdigit(*(cell[i[x]][j[x]].dat + 18)) == 0){return 1;}
            if((*(cell[i[x]][j[x]].dat + 19)) != ')'){return 1;}
        }
    }

    x=0;
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
                        } else if(*(cell[i[x]][j[x]].dat + 5) == 'v')
                        {
                            bufx = 100*(*(cell[i[x]][j[x]].dat + 9) - '0') + 10*(*(cell[i[x]][j[x]].dat + 10) - '0') + (*(cell[i[x]][j[x]].dat + 11) - '0');
                            bufy = 100*(*(cell[i[x]][j[x]].dat + 13) - '0') + 10*(*(cell[i[x]][j[x]].dat + 14) - '0') + (*(cell[i[x]][j[x]].dat + 15) - '0');
                            snprintf(cell[i[x]][j[x]].dat, 256, "%f", sumv(cell, bufx, bufy, lens));
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
            txt << endl;
            bufy = 0;
            bufx++;
        }while(cell[bufx][bufy].dat != NULL);
        txt.close();
    }
    return 0;
}

