#include <stdio.h>
#define N 8
int feld[N][N];
int aufruf = 0;

int springer (int zeile, int spalte, int num) {
    aufruf++;
    if (zeile >= N || spalte >= N || zeile < 0 || spalte < 0 || feld[zeile][spalte] != 0) {
        return 0;
    }
    feld[zeile][spalte] = ++num;
    if (num == N * N) {
        return 1;
    }
    if (springer (zeile + 1, spalte + 2, num)) return 1;
    if (springer (zeile + 2, spalte + 1, num)) return 1;
    if (springer (zeile - 1, spalte + 2, num)) return 1;
    if (springer (zeile - 2, spalte + 1, num)) return 1;
    if (springer (zeile + 1, spalte - 2, num)) return 1;
    if (springer (zeile + 2, spalte - 1, num)) return 1;
    if (springer (zeile - 1, spalte - 2, num)) return 1;
    if (springer (zeile - 2, spalte - 1, num)) return 1;
    feld[zeile][spalte] = 0;
    return 0;
}

int main(void) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            feld[i][j] = 0;
        }
    }
    springer (0, 0, 0);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (feld[i][j] < 10) printf("  %d", feld[i][j]);
            else printf(" %d", feld[i][j]);
        }
        printf("\n");
    }
    printf("\n%d\n", aufruf);
    return 0;
}
