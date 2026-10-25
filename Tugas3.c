#include <stdio.h>
#include <stdlib.h>

char cekPemenang(char p[3][3]) {
    for (int i = 0; i < 3; i++) {
        if (p[i][0] == p[i][1] && p[i][1] == p[i][2] && p[i][0] != ' ')
            return p[i][0]; 
        if (p[0][i] == p[1][i] && p[1][i] == p[2][i] && p[0][i] != ' ')
            return p[0][i];
    }
    if (p[0][0] == p[1][1] && p[1][1] == p[2][2] && p[0][0] != ' ')
        return p[0][0];
    if (p[0][2] == p[1][1] && p[1][1] == p[2][0] && p[0][2] != ' ')
        return p[0][2];

    return ' '; 
}

int main(int argc, char *argv[]) {
    
    char papan[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    int baris, kolom;
    char pemainAktif = 'x';
    int langkah = 0;

    while (langkah < 9) {
        
        printf("\nPapan Permainan:\n");
        for (int baris = 0; baris < 3; baris++) {
            for (int kolom = 0; kolom < 3; kolom++) {
                printf(" %c ", papan[baris][kolom]);
                if (kolom < 2) printf("|");
            }
            printf("\n");
            if (baris < 2) printf("---|---|---\n");
        }

        printf("\nGiliran Pemain '%c'\n", pemainAktif);
        printf("Masukkan baris (0-2): ");
        scanf("%d", &baris);
        printf("Masukkan kolom (0-2): ");
        scanf("%d", &kolom);

        if (baris < 0 || baris > 2 || kolom < 0 || kolom > 2 || papan[baris][kolom] != ' ') {
            printf("\n[!] Posisi tidak valid atau sudah terisi! Silakan coba lagi.\n");
            continue; 
        }

        papan[baris][kolom] = pemainAktif;
        langkah++;

        char pemenang = cekPemenang(papan);
        if (pemenang != ' ') {
            printf("\nPapan Akhir:\n");
            for (int baris = 0; baris < 3; baris++) {
                for (int kolom = 0; kolom < 3; kolom++) {
                    printf(" %c ", papan[baris][kolom]);
                    if (kolom < 2) printf("|");
                }
                printf("\n");
                if (baris < 2) printf("---|---|---\n");
            }
            printf("\nSelamat! Pemain '%c' MENANG!\n", pemenang);
            break; 
        }

        if (langkah == 9) {
            printf("\nPermainan Berakhir SERI!\n");
            break;
        }

        if (pemainAktif == 'x') {
    pemainAktif = 'o'; 
} else {
    pemainAktif = 'x'; 
}
    }

    return 0;
}