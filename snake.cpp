/*
** Chiara Signani
** snake.cpp
** 18/05/2022

risolvi errori in funzioni inizializza bonus/malus
togliere i vettori che memorizzano le posizioni bonus/malus

*/

#include <iostream>
#include <ctime>
#include <windows.h>
#include <conio.h>
#define DIM 10
#define BONUS 5
#define MALUS 5
#define VOID_ELEMENT -1
#define RETURN_ERROR -1
using namespace std;

class snake {
    public:
    int x;
    int y;
    void reset() {
        x = VOID_ELEMENT;
        y = VOID_ELEMENT;
    }
    void setpos(int px, int py) {
        x = px;
        y = py;
    }
    void setOnMatrix(char m[DIM][DIM]) {
        m[x][y] = 'O';
    }
} length[DIM * DIM];

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

bool init_bonus (char m[DIM][DIM]) {
    int x, y;
    for (int i = 0; i < BONUS; i++) {
        x = rand() % (DIM - 1) + 1;
        y = rand() % (DIM - 1) + 1;
        if (m[x][y] != '.') {
            i--;
            continue;
        }
        m[x][y]='+';
    }
    return true;
}

bool init_malus (char m[DIM][DIM]) {
    int x, y;
    for (int i = 0; i < MALUS; i++) {
        x = rand() % (DIM - 1) + 1;
        y = rand() % (DIM - 1) + 1;
        if (m[x][y] != '.') {
        i--;
            continue;
        }
        m[x][y]='x';
    }
    return true;
}

void resetSnake(char m[DIM][DIM]) {
    for (int i=0; i<DIM; i++) {
        for (int j=0; j<DIM; j++) {
            if(m[i][j] == 'O') m[i][j] = '.';
        }
    }
}

int main() {
    srand(time(NULL));
    for(int i = 0; i < DIM * DIM; i++) length[i].reset();
    int length_idx = 1;
    length[0].setpos(0,0);
    char m[DIM][DIM], snake='O', comando, sn;
    int x = 0, y = 0, punti = 0;

    cout << "Istruzioni del gioco: " << endl;
    cout << "1. Utilizza il tasto 'w' per spostarti verso l'alto " << endl;
    cout << "2. Utilizza il tasto 's' per spostarti verso il basso " << endl;
    cout << "3. Utilizza il tasto 'd' per spostarti verso destra " << endl;
    cout << "4. Utilizza il tasto 'a' per spostarti verso sinistra" << endl;
    cout << "5. Utilizza il tasto 'm' per uscire dal gioco " << endl;
    cout << "6. Cerca di prendere tutti i bonus (+) per vincere " << endl;
    cout << "7. Cerca di evitare i malus (x) per non perdere " << endl;
    cout << "Premi un tasto per continuare" << endl;
    getch();

    inizializza_matrice(m,'.');
    init_bonus(m);
    init_malus(m);

    while (true) {
        resetSnake(m);
        for(int i = 0; i < length_idx; i++) length[i].setOnMatrix(m);
        system("cls");
        stampa_matrice(m);
        cout << "Score: " << punti << "/" << BONUS << endl;
        comando = getch();
        switch(comando) {
        case('w'):
            if(m[length[0].x - 1][length[0].y] == '+') {
                punti++;
                length_idx++;
                length[length_idx - 1].setpos(length[0].x,length[0].y);
            }
            length[0].x -= 1;
            break;
        case('a'):
            length[0].y -= 1;
            break;
        case('s'):
            length[0].x += 1;
            break;
        case('d'):
            length[0].y += 1;
            break;
        default:
            break;
        }
    //no
    }
    return 0;
}
