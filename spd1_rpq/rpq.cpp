#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <cmath>
//#include <bits/stdc++.h>

using namespace std;


int main()
{

    int n, r,p,q, i=0, sum=0; // n - liczba zadan, r - czas dostarczenia, p - czas trwania na maszynie, q - czas stygniecia;
    string filename[]={"data_1.txt", "data_2.txt", "data_3.txt", "data_4.txt"};


    for(int fnc = 0; fnc < 4; fnc++)
    {
        // wczytanie danych z pliku
        ifstream infile(filename[fnc]);
        if(infile.good()==false) {cerr<<"Blad. Nie mozna otworzyc pliku!\n"; return 0;}
        infile >> n;
        int R[n], P[n], Q[n];
   //     int *R = new int[n], *P = new int[n], *Q = new int[n];
        while (infile >> r >> p >> q){
            R[i]=r, P[i]=p, Q[i]=q;
            i++;
        }

        int order[n], rightorder[n], temp[n], temp2[n], cmax=0, t=0, best=1000000, bestx, besty;
   //     int *order = new int[n], *temp = new int[n], *temp2 = new int[n], cmax=0, t=0;

        /*/ sortowanie po r i zapisanie kolejnosci do tablicy
        for(i=0; i<n; i++){
            temp[i] = R[i];
        }
        sort(temp, temp+n);
        for(i=0; i<n; i++){
            order[i] = distance(R, find(R, R+n, temp[i])); // uwaga! funkcja zle policzy, gdy sa powtarzajace sie wartosci r
        }*/

        /*/ sortowanie po q i zapisanie kolejnosci do tablicy
        for(i=0; i<n; i++){
            temp[i] = Q[i];
        }
        sort(temp, temp+n, greater<int>());
        for(i=0; i<n; i++){
            order[i] = distance(Q, find(Q, Q+n, temp[i])); // uwaga! funkcja zle policzy, gdy sa powtarzajace sie wartosci q
        }*/

        //sortowanie po xr-yq i zapisanie kolejnosci do tablicy
        int X[]={1,3,4,8,11,12,21,23};
        int Y[]={1,3,4,8,11,12,21,23};
        int z = sizeof(X) / sizeof(X[0]);
        for(int x=0; x<z; x++)
        {
                for(int y=0; y<z; y++)
                    {

                    for(i=0; i<n; i++){
                        temp[i] = X[x]*R[i]-Y[y]*Q[i];
                    }
                    for(i=0; i<n; i++){
                        temp2[i] = temp[i];
                    }
                    sort(temp2, temp2+n);
                    for(i=0; i<n; i++){
                        order[i] = distance(temp, find(temp, temp+n, temp2[i])); // uwaga! funkcja zle policzy, gdy sa powtarzajace sie wartosci xr-yq
                    }


                    // policzenie czasu calkowitego cmax
                    for(i=0; i<n; i++)
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



                    // wypisanie proponowanej kolejnosci oraz policzonego dla niej czasu cmax
            //        cout << filename[fnc] << endl << "Kolejnosc: ";
        //            for(i=0; i<n; i++){
        //                cout<<order[i]+1<<" ";
       //             }
     //               cout << "\nCmax = " << cmax << endl << endl;
            //        cout << "BEST = " << best << endl << endl;
                    cmax = 0, t=0;
                }
        }
        // wyzerowanie odpowiednich zmiennych - przygotowanie petli do nastepnego pliku z danymi
    /*    delete[] R;
        delete[] P;
        delete[] Q;
        delete[] order;
        delete[] temp;
        delete[] temp2;*/
        i=0;
        sum = sum + best; // suma calkowita dla 4 plikow z danymi

        cout << filename[fnc] << endl << "Kolejnosc: ";
                    for(i=0; i<n; i++){
                        cout<<rightorder[i]+1<<" ";
                    }
        cout << "\nCmax = " << best << "\nbestx = " << bestx << " besty = " << besty << endl << endl;
        i=0;
    }

    cout << "Suma = " << sum << endl;


    return 0;
}
