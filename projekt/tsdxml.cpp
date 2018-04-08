#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

int ALGUSREAD = 12;
int INREAD = 14;
int L6PPREAD = 5;

typedef struct
{
    string iKood;
    string nimi;
    string valiKood; //Väljamakse liigi kood
    string summa; // Väljamakse summa
    string otM22r; //mis kohaga t66l
    string smvm; //Sotsiaalmaksuga maksustatav väljamakse
    string kuumSuur; //Sotsiaalmaksuga maksustatava summa suurendus seoses sotsiaalmaksu miinimum kohustusega
    string sm; //sots maks
    string tkvm; //Töötuskindlustusmaksega maksustatav väljamakse
    string tk; // t66taja kindlustus
    string ttk; //t66andja kindlustus
    string tm; // tulu maks
    string tuliKood; //Tulumaksu kinnipidamisel maha arvatud maksuvaba tulu liik
    string summa2;
}Isikud;

typedef struct
{
    string aasta;
    string kuu;
    string tm; // tulumaks
    string tmej; // tulumaksu erijuht
    string sm; // min sots maks
    string tk; // kogu kindlustus
    string kp; // kohust. pension
    string kohustKokku; // makse kohustus firmale
    string tagastKokku; // palju kuulub tagastamisele
    string laadimisViis; // Laadimise viis
    string regKood;
}Algus;

typedef struct
{
    string smvm; //Sotsiaalmaksuga maksustatav väljamakse
    string sm; // mis sots maks
    string tk; // t66taja poolses kindlustused
    string ttk; // t66andja poolsed kindlustused
    string tm; // tulumaks
}L6pp;

int main(void)
{
    Algus algus;
    L6pp l6pp;
    Isikud* isik;
    ifstream infofail ("info.txt");
    string line;
    string sInimesi;
    int inimesi;
    int chk;
    for(int i=0;i<ALGUSREAD;i++)
    {
        getline(infofail, line);
        switch(i)
        {
        case 0:
            algus.aasta = line;
            break;
        case 1:
            algus.kuu = line;
            break;
        case 2:
            algus.tm = line;
            break;
        case 3:
            algus.tmej = line;
            break;
        case 4:
            algus.sm = line;
            break;
        case 5:
            algus.tk = line;
            break;
        case 6:
            algus.kp = line;
            break;
        case 7:
            algus.kohustKokku = line;
            break;
        case 8:
            algus.tagastKokku = line;
            break;
        case 9:
            algus.laadimisViis = line;
            break;
        case 10:
            algus.regKood = line;
            break;
        case 11:
            sInimesi = line;
            break;
        }


    }
    if ( ! (istringstream(sInimesi) >> inimesi) ) inimesi = 0;
    isik = new Isikud[inimesi];
    for(int i=0;i<inimesi;i++)
    {

        for(int j=0;j<INREAD;j++)
        {
            getline(infofail, line);
            switch(j)
            {
            case 0:
                isik[i].iKood = line;
                break;
            case 1:
                isik[i].nimi = line;
                break;
            case 2:
                isik[i].valiKood = line;
                break;
            case 3:
                isik[i].summa = line;
                break;
            case 4:
                isik[i].otM22r = line;
                break;
            case 5:
                isik[i].smvm = line;
                break;
            case 6:
                isik[i].kuumSuur = line;
                break;
            case 7:
                isik[i].sm = line;
                break;
            case 8:
                isik[i].tkvm = line;
                break;
            case 9:
                isik[i].tk = line;
                break;
            case 10:
                isik[i].ttk = line;
                break;
            case 11:
                isik[i].tm = line;
                break;
            case 12:
                isik[i].tuliKood = line;
                break;
            case 13:
                isik[i].summa2 = line;
                break;

            }
        }
    }
    for(int i=0;i<L6PPREAD;i++)
    {
        getline(infofail, line);
        switch(i)
        {
        case 0:
            l6pp.smvm = line;
            break;
        case 1:
            l6pp.sm = line;
            break;
        case 2:
            l6pp.tk = line;
            break;
        case 3:
            l6pp.ttk = line;
            break;
        case 4:
            l6pp.tm = line;
            break;
        }
    }
    infofail.close();

    /// faili lugemine l2bi, nyyd xml tegemine
    string failinimi;
    failinimi = "TSD ";
    failinimi.append(algus.aasta);
    failinimi.append(" ");
    failinimi.append(algus.kuu);
    failinimi.append(".xml");
    //ofstream xmlfail ("<<failinimi<<", ios::trunc);
    ofstream xmlfail (failinimi.c_str(), ios::trunc);
    xmlfail << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>";
    xmlfail << endl;
    xmlfail << "<tsd_vorm>";
    xmlfail << endl;

    for(int i = 0;i<ALGUSREAD-1;i++)
    {
        xmlfail << "   ";
        switch(i)
        {
        case 0:
            xmlfail << "<c108_Aasta>";
            xmlfail << algus.aasta;
            xmlfail << "</c108_Aasta>";
            break;
        case 1:
            xmlfail << "<c109_Kuu>";
            xmlfail << algus.kuu;
            xmlfail << "</c109_Kuu>";
            break;
        case 2:
            xmlfail << "<c110_Tm>";
            xmlfail << algus.tm;
            xmlfail << "</c110_Tm>";
            break;
        case 3:
            xmlfail << "<c114_TmEj>";
            xmlfail << algus.tmej;
            xmlfail << "</c114_TmEj>";
            break;
        case 4:
            xmlfail << "<c115_Sm>";
            xmlfail << algus.sm;
            xmlfail << "</c115_Sm>";
            break;
        case 5:
            xmlfail << "<c116_Tk>";
            xmlfail << algus.tk;
            xmlfail << "</c116_Tk>";
            break;
        case 6:
            xmlfail << "<c117_Kp>";
            xmlfail << algus.kp;
            xmlfail << "</c117_Kp>";
            break;
        case 7:
            xmlfail << "<c118_KohustKokku>";
            xmlfail << algus.kohustKokku;
            xmlfail << "</c118_KohustKokku>";
            break;
        case 8:
            xmlfail << "<c119_TagastKokku>";
            xmlfail << algus.tagastKokku;
            xmlfail << "</c119_TagastKokku>";
            break;
        case 9:
            xmlfail << "<laadimisViis>";
            xmlfail << algus.laadimisViis;
            xmlfail << "</laadimisViis>";
            break;
        case 10:
            xmlfail << "<regKood>";
            xmlfail << algus.regKood;
            xmlfail << "</regKood>";
            break;

        }
        xmlfail << endl;
    }
    xmlfail << "   <tsd_L" <<"1"<<"_0>" << endl; /// k6ik on peded
    xmlfail << "      <aIsikList>" << endl;

    for(int i=0;i<inimesi;i++)
    {
        xmlfail << "         <tsd_L"<<i+1 <<"_A_Isik>" << endl;

        chk = 0;
        for(int j=0;j<INREAD;j++)
        {
            xmlfail << "            ";
            if(chk == 0)
            {
                switch(j)
                {
                    case 0:

                        xmlfail << "<c1000_Kood>";
                        xmlfail << isik[i].iKood; /// hujjab
                        xmlfail << "</c1000_Kood>";
                        break;

                    case 1:

                        xmlfail << "<c1010_Nimi>";
                        xmlfail << isik[i].nimi;
                        xmlfail << "</c1010_Nimi>";
                        xmlfail << endl;
                        xmlfail << "            <vmList>";
                        xmlfail << endl;
                        xmlfail << "               <tsd_L"<<i+1<<"_A_Vm>";
                        chk = 1;
                        break;
                    }

            }
            else if(chk == 1)
            {

                xmlfail << "      ";
                switch(j)
                {
                case 2:

                    xmlfail << "<c1020_ValiKood>";
                    xmlfail << isik[i].valiKood;
                    xmlfail << "</c1020_ValiKood>";
                    break;
                case 3:
                    xmlfail << "<c1030_Summa>";
                    xmlfail << isik[i].summa;
                    xmlfail << "</c1030_Summa>";
                    break;
                case 4:
                    xmlfail << "<c1040_OtMaar>";
                    xmlfail << isik[i].otM22r;
                    xmlfail << "</c1040_OtMaar>";
                    break;
                case 5:
                    xmlfail << "<c1060_Smvm>";
                    xmlfail << isik[i].smvm;
                    xmlfail << "</c1060_Smvm>";
                    break;
                case 6:
                    xmlfail << "<c1090_KuumSuur>";
                    xmlfail << isik[i].kuumSuur;
                    xmlfail << "</c1090_KuumSuur>";
                    break;
                case 7:
                    xmlfail << "<c1100_Sm>";
                    xmlfail << isik[i].sm;
                    xmlfail << "</c1100_Sm>";
                    break;
                case 8:
                    xmlfail << "<c1120_Tkvm>";
                    xmlfail << isik[i].tkvm;
                    xmlfail << "</c1120_Tkvm>";
                    break;
                case 9:
                    xmlfail << "<c1130_Tk>";
                    xmlfail << isik[i].tk;
                    xmlfail << "</c1130_Tk>";
                    break;
                case 10:
                    xmlfail << "<c1140_Ttk>";
                    xmlfail << isik[i].ttk;
                    xmlfail << "</c1140_Ttk>";
                    break;
                case 11:
                    xmlfail << "<c1170_Tm>";
                    xmlfail << isik[i].tm;
                    xmlfail << "</c1170_Tm>";
                    xmlfail << endl;
                    xmlfail << "                  <mvtList>";
                    xmlfail << endl;
                    xmlfail << "                     <tsd_L" << "1" << "_A_Mvt>";
                    chk = 2;
                    break;
                }
            }
            else
            {
                xmlfail << "            ";
                switch(j)
                {
                case 12:
                    xmlfail << "<c1150_TuliKood>";
                    xmlfail << isik[i].tuliKood;
                    xmlfail << "</c1150_TuliKood>";
                    break;
                case 13:
                    xmlfail << "<c1160_Summa>";
                    xmlfail << isik[i].summa2;
                    xmlfail << "</c1160_Summa>";
                    break;
                }

            }
            xmlfail << endl;
        }
        xmlfail << "                     </tsd_L"<<"1"<<"_A_Mvt>" << endl;
        xmlfail << "                  </mvtList>" << endl;
        xmlfail << "               </tsd_L" <<"1"<<"_A_Vm>" << endl;
        xmlfail << "            </vmList>" << endl;
        xmlfail << "         </tsd_L"<<i+1<<"_A_Isik>" << endl;
    }


    xmlfail << "      </aIsikList>" << endl;
    for(int i=0;i<L6PPREAD;i++)
    {
        xmlfail << "      ";
        switch(i)
        {
        case 0:
            xmlfail << "<c1200_Smvm>";
            xmlfail << l6pp.smvm;
            xmlfail << "</c1200_Smvm>";
            break;
        case 1:
            xmlfail << "<c1210_Smv>";
            xmlfail << l6pp.sm;
            xmlfail << "</c1210_Smv>";
            break;
        case 2:
            xmlfail << "<c1230_Tk>";
            xmlfail << l6pp.tk;
            xmlfail << "</c1230_Tk>";
            break;
        case 3:
            xmlfail << "<c1240_Ttk>";
            xmlfail << l6pp.ttk;
            xmlfail << "</c1240_Ttk>";
            break;
        case 4:
            xmlfail << "<c1250_Tm>";
            xmlfail << l6pp.tm;
            xmlfail << "<c1250_Tm>";
            break;
        }
        xmlfail << endl;
    }
    xmlfail << "   </tsd_L1_0>" << endl;
    xmlfail << "   <vorm>TSD</vorm>" << endl;
    xmlfail << "</tsd_vorm>" << endl;
    delete[] isik;
    return 0;
}
