#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream positivi("positivi.txt");
    ofstream negativi("negativi.txt");
    int n;
    do {
        cout << "Inserisci un numero (0 per uscire): ";
        cin >> n;
        if(n == 0) return 0;
        if(n > 0) positivi << n; else negativi << n;
    } while(n != 0);
    return 0;
}