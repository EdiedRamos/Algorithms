//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

/*
    mayuscula -> blancas, minusculas -> negras
    k - rey
    p - peón
    r - torre
    n - caballo
    b - alfíl
    q - reina
    
    ~ - vacio
    x - casilla atacada
*/

char tablero[8][8];
int mov_x[] = {1, -1, 0, 0, 1, -1, 1, -1}, mov_y[] = {0, 0, 1, -1, 1, -1, -1, 1};

bool Valido(int x, int y) {
    return x >= 0 && y >= 0 && x < 8 && y < 8 && (tablero[x][y] == '~' || tablero[x][y] == 'x');
}

void Ataque(int x, int y) {
    if (Valido(x, y)) {
        tablero[x][y] = 'x';
    }
}

void Arriba(int x, int y) {
    if (!Valido(x, y)) return;
    Ataque(x, y);
    Arriba(x-1,y);
}

void Abajo(int x, int y) {
    if (!Valido(x, y)) return;
    Ataque(x, y);
    Abajo(x+1,y);
}

void Izquierda(int x, int y) {
    if (!Valido(x, y)) return;
    Ataque(x, y);
    Izquierda(x, y-1);
}

void Derecha(int x, int y) {
    if (!Valido(x, y)) return;
    Ataque(x, y);
    Derecha(x, y+1);
}

void DiagonalSI(int x, int y) {
    if (!Valido(x, y)) return;
    Ataque(x, y);
    DiagonalSI(x-1,y-1);
}

void DiagonalSD(int x, int y) {
    if (!Valido(x, y)) return;
    Ataque(x, y);
    DiagonalSD(x-1,y+1);
}

void DiagonalII(int x, int y) {
    if (!Valido(x, y)) return;
    Ataque(x, y);
    DiagonalII(x+1,y-1);
}

void DiagonalID(int x, int y) {
    if (!Valido(x, y)) return;
    Ataque(x, y);
    DiagonalID(x+1,y+1);
}

void Peon(int x, int y, bool w) {
    if (w) {
        Ataque(x-1,y-1);
        Ataque(x-1,y+1);
    } else {
        Ataque(x+1,y-1);
        Ataque(x+1,y+1);
    }
}

void Reina(int x, int y) {
    Arriba(x-1,y);
    Abajo(x+1,y);
    Izquierda(x,y-1);
    Derecha(x,y+1);
    DiagonalSI(x-1,y-1);
    DiagonalSD(x-1,y+1);
    DiagonalII(x+1,y-1);
    DiagonalID(x+1,y+1);
}

void Rey(int x, int y) {
    for (int i = 0; i < 8; i++) {
        Ataque(x + mov_x[i], y + mov_y[i]);
    }
}

void Torre(int x, int y) {
    Arriba(x-1,y);
    Abajo(x+1,y);
    Izquierda(x,y-1);
    Derecha(x,y+1);
}

void Caballo(int x, int y) {
    Ataque(x-1,y-2);
    Ataque(x-2,y-1);
    Ataque(x-1,y+2);
    Ataque(x-2,y+1);
    Ataque(x+1,y-2);
    Ataque(x+2,y-1);
    Ataque(x+1,y+2);
    Ataque(x+2,y+1);
}

void Alfil(int x, int y) {
    DiagonalSI(x-1,y-1);
    DiagonalSD(x-1,y+1);
    DiagonalII(x+1,y-1);
    DiagonalID(x+1,y+1);
}

void Movimiento(int x, int y, char c) {
    if (c == 'p') {
        Peon(x, y, 0);
    } else if (c == 'P') {
        Peon(x, y, 1);
    } else {
        c = tolower(c);
        if (c == 'k') {
            Rey(x, y);
        } else if (c == 'q') {
            Reina(x, y);
        } else if (c == 'b') {
            Alfil(x, y);
        } else if (c == 'r') {
            Torre(x, y);
        } else {
            Caballo(x, y);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string fen;
    int _i, _j, _r;
    while (cin >> fen) {
        _r = 0;
        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
                tablero[i][j] = '~';
        _i = _j = 0;
        for (char c : fen) {
            if (c == '/') {
                _i++, _j = 0;
            } else {
                if (isdigit(c)) {
                    _j += (c-'0');
                } else {
                    tablero[_i][_j] = c;
                    _j++;
                }
            }
        }
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (tablero[i][j] != '~' && tablero[i][j] != 'x') {
                    Movimiento(i, j, tablero[i][j]);
                }
            }
        }
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (tablero[i][j] == '~') {
                    _r++;
                }
            }
        }
        cout << _r << "\n";
    }
    return 0;
}
