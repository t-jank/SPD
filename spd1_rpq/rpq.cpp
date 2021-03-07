#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
//#include <bits/stdc++.h>

using namespace std;


int main()
{

    int n, r,p,q, i=0; // n - liczba zadan, r - czas dostarczenia, p - czas trwania na maszynie, q - czas stygniecia;
    string filename="data_3.txt";
    int order[n], temp[n], cmax=0, t=0;

    // wczytanie danych z pliku
    ifstream infile(filename);
    if(infile.good()==false) {cerr<<"Blad. Nie mozna otworzyc pliku!\n"; return 0;}
    infile >> n;
    int R[n], P[n], Q[n];
    while (infile >> r >> p >> q){
        R[i]=r, P[i]=p, Q[i]=q;
        i++;
    }

    /*/ sortowanie po r i zapisanie kolejnosci do tablicy
    for(i=0; i<n; i++){
        temp[i] = R[i];
    }
    sort(temp, temp+n);
    for(i=0; i<n; i++){
        order[i] = distance(R, find(R, R+n, temp[i])); // uwaga! funkcja zle policzy, gdy sa powtarzajace sie wartosci r
    }*/

    // sortowanie po q i zapisanie kolejnosci do tablicy
    for(i=0; i<n; i++){
        temp[i] = Q[i];
    }
    sort(temp, temp+n, greater<int>());
    for(i=0; i<n; i++){
        order[i] = distance(Q, find(Q, Q+n, temp[i])); // uwaga! funkcja zle policzy, gdy sa powtarzajace sie wartosci q
    }

    // policzenie czasu calkowitego cmax
    for(i=0; i<n; i++)
    {
        if(R[order[i]]>t) t = R[order[i]] + P[order[i]];
        else t = t + P[order[i]];
        cmax = max(cmax, t+Q[order[i]]);
    }


    // wypisanie proponowanej kolejnosci oraz policzonego dla niej czasu cmax
    cout << "Kolejnosc: ";
    for(i=0; i<n; i++){
        cout<<order[i]+1<<" ";
    }
    cout << "\nCmax = " << cmax << endl;


    return 0;
}
