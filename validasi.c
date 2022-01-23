#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdbool.h>


char *valUserdaftar(int x, int y, int batas){
    static char user[30];
    int a = 0;

    posisi(x, y);
    user[a] = getch();
    while (user[a] != 13 || a == 0){

        if (user[a] == 8){
            a--;
            if (a < 0)
            {
                a = 0;
            }
            posisi(x + a, y);
            printf(" ");
        }
        else{
            warna_text(11);
            warna_bg(15);
            if (user[a] >= 97 && user[a] <= 122 || user[a] >= 65 && user[a] <= 90 ||
                user[a] >= 48 && user[a] <= 57 || user[a] == '.' || user[a] == '_'){
                posisi(x + a, y);
                printf("%c", user[a]);
                a++;
            }
            else{
                if (user[a] == '\0'){
                    // Sengaja Kosong
                }
                else{
                    posisi(x, y);
                    a = 0;
                    printf("                ");
                    warna_text(15);
                    warna_bg(5);
                    posisi(45,16);
                    printf("        Invalid Input          ");
                    posisi(45, 17);
                    printf("                               ");
                    Sleep(500);

                    warna_bg(6);
                    posisi(45, 16);
                    printf("                               ");
                    posisi(45, 17);
                    printf("                               ");
                }
            }
        }

        if (a >= batas + 1)
        {
            a = 0;
            posisi(x, y);
            printf("                ");
            warna_text(15);
            warna_bg(5);
            posisi(45, 16);
            printf("     Maksimal %2d digit !!      ", batas);
            posisi(45, 17);
            printf("                               ");
            Sleep(500);

            warna_bg(6);
            posisi(45, 16);
            printf("                               ");
            posisi(45, 17);
            printf("                               ");
        }

        posisi(x + a, y);
        user[a] = getch();

        if (user[a] == 13 && a < 5)
        {
            posisi(x, y);
            printf("                ");
            warna_text(15);
            warna_bg(5);
            posisi(45, 16);
            printf("       Minimal 5 digit         ", batas);
            posisi(45, 17);
            printf("                               ");
            Sleep(500);

            warna_bg(6);
            posisi(45, 16);
            printf("                               ");
            posisi(45, 17);
            printf("                               ");
            a = 0;
            user[a] = '\0';
        }

        if (user[a] != '\0')
        {
            posisi(x + a, y);
            printf("%c", user[a]);
        }
    }

    user[a] = '\0';
    return user;
}

char *valBataslog(int x, int y, int batas, int t){
    static char user[500];
    int a = 0;

    posisi(x, y);
    user[a] = getch();
    while (user[a] != 13){

        if (user[a] == 8){
            a--;
            if (a < 0){
                a = 0;
            }
            posisi(x + a, y);
            printf(" ");
        }

        else{
            warna_text(11);
            warna_bg(15);
            if (t == 0){
                printf("%c", user[a]);
            }
            else{
            posisi(x+a,y);printf("%c", user[a]);
            Sleep(90);
            posisi(x+a,y);printf("*");
            }
            a++;
        }
        if (a > batas){
            a = 0;
            warna_bg(15);
            posisi(x, y);
            printf("                ");
            warna_text(15);
            warna_bg(5);
            posisi(45, 16);
            printf("   Inputnya Kebanyakan Boss    ");
            posisi(45, 17);
            printf("                               ");
            Sleep(500);

            warna_bg(6);
            posisi(45, 16);
            printf("                               ");
            posisi(45, 17);
            printf("                               ");
        }
        posisi(x + a, y);
        user[a] = getch();
    }
    user[a] = '\0';
    return user;
}

char *valBatas(int x, int y, int batas, int w1, int w2){
    static char user[500];
    int a = 0;

    posisi(x, y);
    user[a] = getch();
    while (user[a] != 13){

        if (user[a] == 8){
            a--;
            if (a < 0){
                a = 0;
            }posisi(x + a, y);
            printf(" ");
        }

        else{
            warna_text(w1);
            warna_bg(w2);
            printf("%c", user[a]);
            a++;
        }if (a > batas){
            a = 0;
            posisi(x, y);
            printf(" Input Maks 15 orang ");
            Sleep(500);
            posisi(x, y);
            printf("                                   ");
        }
        posisi(x + a, y);
        user[a] = getch();
    }
    user[a] = '\0';
    return user;
}

char* angka(int x,int y,int batas){
static char jumlah[10];
    int a = 0;
    posisi(x, y);
    jumlah[a] = getch();
    while (jumlah[a] != 13 || a == 0){

        if (jumlah[a] == 8){
            a--;
            if (a < 0)
            {
                a = 0;
            }
            posisi(x + a, y);
            printf(" ");
        }
        else{
            warna_text(11);
            warna_bg(13);
            if (jumlah[a] >= '0' && jumlah[a] <= '9'){
                posisi(x + a, y);
                printf("%c", jumlah[a]);
                a++;
            }
            else{
                if (jumlah[a] == '\0'){
                    // Sengaja Kosong
                }
                else{
                    a = 0;
                    warna_text(5);
                    warna_bg(13);
                    posisi(x,y);
                    printf(" Invalid Input ");
                    Sleep(500);
                    posisi(x,y);
                    printf("               ");
                }
            }
        }

        if (a >= batas + 1)
        {
            a = 0;
            warna_text(5);
            warna_bg(13);
            posisi(x,y);
            printf(" Maksimal 15 orang  " );
            Sleep(500);
            posisi(x,y);
            printf("                     ");
        }

        posisi(x + a, y);
        jumlah[a] = getch();

        if (jumlah[a] == 13 && a < 1)
        {
            a = 0;
            warna_text(5);
            warna_bg(13);
            posisi(x,y);
            printf(" Minimal 1 digit ");
            Sleep(500);
            posisi(x,y);
            printf("                 ");
            jumlah[a] = '\0';
        }

        if (jumlah[a] != '\0')
        {   
            warna_text(11);
            posisi(x + a, y);
            printf("%c", jumlah[a]);
        }
    }

    jumlah[a] = '\0';
    return jumlah;
}

