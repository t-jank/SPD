#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <cmath>
#include <ctime>

using namespace std;


int main()
{

    int n, r,p,q, w=0, sum=0; // n - liczba zadan, r - czas dostarczenia, p - czas trwania na maszynie, q - czas stygniecia;
    string filename[]={"data_1.txt", "data_2.txt", "data_3.txt", "data_4.txt"};

    srand( time( NULL ) ); // konfiguracja generatora liczb losowych

        // wczytanie danych z pliku
        ifstream infile(filename[3]);
        if(infile.good()==false) {cerr<<"Blad. Nie mozna otworzyc pliku!\n"; return 0;}
        infile >> n;
        int *R = new int[n], *P = new int[n], *Q = new int[n];
        while (infile >> r >> p >> q){
            R[w]=r, P[w]=p, Q[w]=q;
            w++;
        }
        int order[n], rightorder[n], temp[n], temp2[n], cmax=0, t=0, best=1000000, bestx, besty, x=64, tmpr[n], tmpq[n];
   //     int *order = new int[n], *temp = new int[n], *temp2 = new int[n], cmax=0, t=0;


        /*/sortowanie po xr-yq i zapisanie kolejnosci do tablicy
        int X[]={1,3,4,8,11,12,21,23};
        int Y[]={1,3,4,8,11,12,21,23};
        int z = sizeof(X) / sizeof(X[0]);
        for(int x=0; x<z; x++)
        {
                for(int y=0; y<z; y++)
                    {

                    for(int i=0; i<n; i++){
                        temp[i] = X[x]*R[i]-Y[y]*Q[i];
                    }
                    for(int i=0; i<n; i++){
                        temp2[i] = temp[i];
                    }
                    sort(temp2, temp2+n);
                    for(int i=0; i<n; i++){
                        order[i] = distance(temp, find(temp, temp+n, temp2[i])); // uwaga! funkcja zle policzy, gdy sa powtarzajace sie wartosci xr-yq
                    }


                    // policzenie czasu calkowitego cmax
                    for(int i=0; i<n; i++)
                    {
                        if(R[order[i]]>t) t = R[order[i]] + P[order[i]];
                        else t = t + P[order[i]];
                        cmax = max(cmax, t+Q[order[i]]);
                    }

                    if(cmax < best){
                        best = cmax;
                        bestx = X[x];
                        besty = Y[y];
                        for(int e=0; e<n; e++)
                            rightorder[e] = order[e];
                    }
                    cmax=0; t=0;
                }
        }*/


            /*/ sortowanie po rand i zapisanie kolejnosci do tablicy
            for(int j = 0; j < 1; j++)
            {

                int *rnd = new int[n];
            /*    for(int k=0; k<n; k++){
                    rnd[k] = -k-1;
                }

                for(int d=0; d<n; d++) // losowanie kolejnosci
                {
                    x = rand() % n;
                    while((find(rnd, rnd + n, x) != rnd + n) == true)
                        x = rand() % n;

                    rnd[d] = x;
                }* /

                for(int v=0; v < n; v++){
                    rnd[v] = v;
                }
         //       random_shuffle(rnd+5, rnd + n - 5);

                // policzenie czasu calkowitego cmax
                for(int b=0; b<n; b++)
                {
                    if(R[rnd[b]]>t) t = R[rnd[b]] + P[rnd[b]];
                    else t = t + P[rnd[b]];
                    cmax = max(cmax, t+Q[rnd[b]]);
                }
                if(cmax < best){
                    best = cmax;
                    for(int e=0; e<n; e++)
                        rightorder[e] = rnd[e];
                }

                cmax=0, t=0;

                delete [] rnd;
            }*/

      /*      for(int i = 0; i < n; i++)
            {
                rightorder[i] = distance(Q, find(Q, Q+n, tmpq[i]));
            }*/


            int modifiedorder[] = {37, 21, 12, 15, 13, 41, 6, 4, 36, 30, 19, 24, 33, 46, 47, 25, 43, 45, 23, 18, 34, 14, 17, 48,
                                    39, 7, 10, 20, 27, 26, 29, 5, 8, 32, 2, 16, 40, 22, 44, 28, 35, 42, 9, 31, 1, 3, 11, 38};

            for(int i=0; i<n; i++)
            {
                if(R[modifiedorder[i]-1]>t) t = R[modifiedorder[i]-1] + P[modifiedorder[i]-1];
                else t = t + P[modifiedorder[i]-1];
                cmax = max(cmax, t+Q[modifiedorder[i]-1]);
            }



            cout << filename[3] << endl << "Kolejnosc: ";
                    for(int z=0; z<n; z++){
                        cout<<modifiedorder[z]<<" ";
                    }
            cout << endl << endl;


            cout << "Wartosci:\t(Cmax = " << cmax << ")\n";
            cout.width(7); cout << left << "nr";
            cout.width(7); cout << left << "R";
            cout.width(6); cout << left << "P";
            cout.width(6); cout << left << "Q" << endl;
            for(int i = 0; i < n; i++){
                cout.width(7); cout << left;
                cout << modifiedorder[i];
                cout.width(7); cout << left;
                cout << R[modifiedorder[i]-1];
                cout.width(6); cout << left;
                cout << P[modifiedorder[i]-1];
                cout.width(6); cout << left;
                cout << Q[modifiedorder[i]-1] << endl;
            }


       /*     cout << filename[3] << endl << "Kolejnosc: ";
                    for(int z=0; z<n; z++){
                        cout<<rightorder[z]+1<<", ";
                    }
            cout << endl << endl;


            cout << "Wartosci:\t(Cmax = " << best << ")\n";
            cout.width(7); cout << left << "nr";
            cout.width(7); cout << left << "R";
            cout.width(6); cout << left << "P";
            cout.width(6); cout << left << "Q" << endl;
            for(int i = 0; i < n; i++){
                cout.width(7); cout << left;
                cout << rightorder[i]+1;
                cout.width(7); cout << left;
                cout << R[rightorder[i]];
                cout.width(6); cout << left;
                cout << P[rightorder[i]];
                cout.width(6); cout << left;
                cout << Q[rightorder[i]] << endl;
            }*/


    return 0;
}
