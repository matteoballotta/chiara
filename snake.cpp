/*
** Chiara Signani
** snake.cpp
** 18/05/2022
*/

#include <iostream>
#include <ctime>
#include <windows.h>
#include <conio.h>
#define DIM 10
#define BONUS 5
#define MALUS 5
using namespace std;

void inizializza_matrice (char [DIM][DIM], char);
void stampa_matrice (char [DIM][DIM]);
bool init_bonus (char [DIM][DIM], int [BONUS*2]);
bool init_malus (char [DIM][DIM], int [MALUS*2]);
bool bonus (char [DIM][DIM], int [BONUS*2], int, int);
bool malus (char [DIM][DIM], int [MALUS*2], int, int);

int main() {
    srand(time(NULL));
    char m[DIM][DIM], snake='O', comando, sn;
    int x=0, y=0, vb[BONUS*2], vm[MALUS*2], n=0;

    cout << "Istruzioni del gioco: " << endl;
    cout << "1. Utilizza il tasto 'w' per spostarti verso l'alto " << endl;
    cout << "2. Utilizza il tasto 's' per spostarti verso il basso " << endl;
    cout << "3. Utilizza il tasto 'd' per spostarti verso destra " << endl;
    cout << "4. Utilizza il tasto 'a' per spostarti verso sinistra" << endl;
    cout << "5. Utilizza il tasto 'm' per uscire dal gioco " << endl;
    cout << "6. Cerca di prendere tutti i bonus (+) per vincere " << endl;
    cout << "7. Cerca di evitare i malus (x) per non perdere " << endl << endl;
    cout << "Sei pronto a giocare (s/n)? ";
    cin >> sn;
    if (sn=='n') {
        cout << "Buona giornata e a presto! " << endl;
        return 0;
    }

    cout << endl;
    inizializza_matrice(m, '.');
    m[0][0]=snake;
    init_bonus(m, vb); init_malus(m, vm);
    if (!init_bonus || !init_malus) {
        cout << "C'e' stato un errore durante il caricamento del gioco, prova a riavviarlo " << endl;
        return 0;
    }
    /*
    for (int i=0; i<BONUS*2 && i<MALUS*2; i++) {
        if (vb[i]==vm[i]) {
            cout << "C'e' stato un errore durante il caricamento del gioco, prova a riavviarlo " << endl;
            return 0;
        }
    }
    */

    system("cls");
    stampa_matrice(m);
    cout << "Score: " << n << "/" << BONUS << endl;
    while (true) {
        comando = getch();

        if (comando=='w') {m[x][y]='.'; m[x-1][y]='O'; x-=1;}
        if (comando=='s') {m[x][y]='.'; m[x+1][y]='O'; x+=1;}
        if (comando=='d') {m[x][y]='.'; m[x][y+1]='O'; y+=1;}
        if (comando=='a') {m[x][y]='.'; m[x][y-1]='O'; y-=1;}
        /*
        switch(n) {
            case(0):
            if (comando=='w') {m[x][y]='.'; m[x-1][y]='O'; x-=1;}
            if (comando=='s') {m[x][y]='.'; m[x+1][y]='O'; x+=1;}
            if (comando=='d') {m[x][y]='.'; m[x][y+1]='O'; y+=1;}
            if (comando=='a') {m[x][y]='.'; m[x][y-1]='O'; y-=1;}
            break;
            case(1):
            if (comando=='w') {m[x+2][y]='.'; m[x][y]='.O'; m[x-1][y]='O'; x-=1;}
            if (comando=='s') {m[x-2][y]='.'; m[x][y]='O'; m[x+1][y]='O'; x+=1;}
            if (comando=='d') {m[x][y-2]='.'; m[x][y]='O'; m[x][y+1]='O'; y+=1;}
            if (comando=='a') {m[x][y+2]='.'; m[x][y]='O'; m[x][y-1]='O'; y-=1;}
            break;
        }
        */

        /*
        if (n==0) {
            if (comando=='w') {m[x][y]='.'; m[x-1][y]='O'; x-=1;}
            if (comando=='s') {m[x][y]='.'; m[x+1][y]='O'; x+=1;}
            if (comando=='d') {m[x][y]='.'; m[x][y+1]='O'; y+=1;}
            if (comando=='a') {m[x][y]='.'; m[x][y-1]='O'; y-=1;}
        }
        if (n==1) {
            if (comando=='w') {m[x][y]='O'; m[x-1][y]='O'; x-=1;}
            if (comando=='s') {m[x][y]='O'; m[x+1][y]='O'; x+=1;}
            if (comando=='d') {m[x][y]='O'; m[x][y+1]='O'; y+=1;}
            if (comando=='a') {m[x][y]='O'; m[x][y-1]='O'; y-=1;}
        }
        */
        if (comando=='m') {cout << "Il gioco e' finito, grazie per aver giocato! " << endl; return 0;}
        if (x<0 || y<0 || x>=DIM || y>=DIM) {cout << "Hai tentato di uscire dal campo di gioco, prova di nuovo! " << endl; return 0;}
        if (!bonus(m, vb, x, y)) {
            n++;
        }
        if (n==BONUS) {
            system("cls");
            stampa_matrice(m);
            cout << "Bravo, hai vinto! " << endl;
            return 0;
        }
        if (!malus(m, vm, x, y)) {
            system("cls");
            stampa_matrice(m);
            cout << "Hai preso un malus, gioca di nuovo! " << endl;
            return 0;
        }
        system("cls");
        stampa_matrice(m);
        cout << "Score: " << n << "/" << BONUS << endl;
    }
    return 0;
}

void inizializza_matrice (char m[DIM][DIM], char valore) {
    for (int i=0; i<DIM; i++) {
        for (int j=0; j<DIM; j++) {
            m[i][j] = valore;
        }
    }
}

void stampa_matrice (char m[DIM][DIM]) {
    for (int i=0; i<DIM; i++) {
        for (int j=0; j<DIM; j++) {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}

bool init_bonus (char m[DIM][DIM], int v[BONUS*2]) {
    int x, y, j=0;
    for (int i=0; i<BONUS; i++) {
        x=rand()%DIM;
        y=rand()%DIM;
        if (x==0 && y==0) return false;
        else {
            /*
            ** HANDLE console_color;
            ** console_color = GetStdHandle(STD_OUTPUT_HANDLE);
            ** SetConsoleTextAttribute(console_color, 10);
            */
            // FUNZIONA system("Color 2");
            // SetConsoleTextAttribute(hConsole, 10);
            // Console.BackgroundColor = ConsoleColor.Green;
            // Console.ForegroundColor = ConsoleColor.DarkGreen;
            m[x][y]='+';
            v[j]=x;
            v[j+1]=y;
            j+=2;
        }
    }
    return true;
}

bool init_malus (char m[DIM][DIM], int v[MALUS*2]) {
    int x, y, j=0;
    for (int i=0; i<MALUS; i++) {
        x=rand()%DIM;
        y=rand()%DIM;
        if (x==0 && y==0) return false;
        else {
            m[x][y]='x';
            v[j]=x;
            v[j+1]=y;
            j+=2;
        }
    }
    return true;
}

bool bonus (char m[DIM][DIM], int v[BONUS*2], int x, int y) {
    for (int i=0; i<BONUS*2; i+=2) {
        if (x==v[i] && y==v[i+1]) return false;
    }
    return true;
}

bool malus (char m[DIM][DIM], int v[MALUS*2], int x, int y) {
    for (int i=0; i<MALUS*2; i+=2) {
        if (x==v[i] && y==v[i+1]) return false;
    }
    return true;
}
