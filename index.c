#include <stdio.h>
#include <windows.h>
#include <conio.h>
#define outputHandle GetStdHandle(STD_OUTPUT_HANDLE)

int text_color = FOREGROUND_INTENSITY;
int background_color = 0;

void header(int mana);
void regristaz(int m);
void regristaztmp(int a, int w1, int w2);
void klikMenu(int y);

void posisi(int x, int y)
{
    COORD position = {x, y};
    SetConsoleCursorPosition(outputHandle, position);
}
void warna_text(int color)
{
    SetConsoleTextAttribute(outputHandle, color | (background_color << 4));
    text_color = color;
}
void warna_bg(int color)
{
    SetConsoleTextAttribute(outputHandle, text_color | (color << 4));
    background_color = color;
}

void booking(char jalur[30],char nama[30],char asal[30],int day,int month,int year){
//Menyimpan Ke Notepad
    FILE*data;
    data=fopen("regris.txt","a");

    fputs(jalur,data);
    fputs("\n",data);
    fputs(nama,data);
    fputs("\n",data);
    fputs(asal,data);
    fputs("\n",data);
    fprintf(data,"%d/%d/%d\n",day,month,year);

    fclose (data);
}

void registai(char user[30],char pass[30]){
//Menyimpan Ke Notepad
    FILE*data;
    data=fopen("login.txt","a");

    fputs(user,data);
    fputs("\n",data);
    fputs(pass,data);
    fputs("\n",data);

    fclose (data);
}

char login(char user2[30], char pass2[30]){
    char user[30][30];
    char pass[30][30];
    int a=0;


    FILE *data;
	data = fopen("login.txt","r");

// Mencari baris yang username-nya cocok
    while(!feof(data) && strcmp(user[a],user2) != 0){
          fscanf(data,"%s",&user[a]);
          fscanf(data,"%s",&pass[a]);
          a++;
        }
        
        a--;
	
// Mencocokkan password pada baris itu
    for(int b=0;b<=a;b++){
    	if(strcmp(user[b],user2)== 0 && strcmp(pass[b],pass2)== 0){
            return '0';
        } 
    }  
}

char cekndaftar(char user2[30]){
    char user[30][30];
    char pass[30][30];
    int a=0;


    FILE *data;
	data = fopen("login.txt","r");

// Mencari baris yang username-nya cocok
    while(!feof(data) && strcmp(user[a],user2) != 0){
          fscanf(data,"%s",&user[a]);
          fscanf(data,"%s",&pass[a]);
          a++;
        }  
        a--;
    for(int b=0;b<=a;b++){
    	if(strcmp(user[b],user2)== 0){
            return '0';
        } 
    } 
}

void bcg(int x,int y,int c){
posisi(x,y);
warna_bg(c);  
    for(int a=y;a<=29;a++){
        for(int b=x;b<=119;b++){
            if(a==1 || a==30 || b==1 || b==119){
                warna_text(c);
                printf("%c", 219);
            }
            else {
                printf(" ");
            }
        }
    }
}

void welcome(int x,int y){
warna_bg(13);
warna_text(10);
    posisi(x,y++);printf("   ___      _                 _     ___       _                      ");        
    posisi(x,y++);printf("  / __| ___| |__ _ _ __  __ _| |_  |   \\ __ _| |_ __ _ _ _  __ _     ");
    posisi(x,y++);printf("  \\__ \\/ -_) / _` | '  \\/ _` |  _| | |) / _` |  _/ _` | ' \\/ _` |    ");
    posisi(x,y++);printf("  |___/\\___|_\\__,_|_|_|_\\__,_|\\__| |___/\\__,_|\\__\\__,_|_||_\\__, |    ");
    posisi(x,y++);printf("                                                           |___/     ");
    y++;       
    posisi(x,y++);printf("      .                  .-.    .  _    *   _   .                    ");
    posisi(x,y++);printf("             *          /   \\     ((      _/ \\       *    .          ");
    posisi(x,y++);printf("           _    .   .--'\\/\\_ \\     `     /    \\  *   ___             ");
    posisi(x,y++);printf("       *  / \\_    _/ ^      \\/\\'__      /\\/\\  /\\  __/   \\ *          ");
    posisi(x,y++);printf("        /    \\  /    .'   _/  /  \\  *' /    \\/  \\/ .`'\\_/\\   .       ");
    posisi(x,y++);printf("   .   /\\/\\  /\\/ :' __  ^/  ^/    `--./.'  ^  `-.\\ _    _:\\ _        ");
    posisi(x,y++);printf("      /    \\/  \\  _/  \\-' __/.' ^ _   \\_   .'\\   _/ \\ .  __/ \\       ");
    posisi(x,y++);printf("    /\\  .-   `. \\/     \\ / -.   _/ \\ -. `_/   \\ /    `._/  ^  \\      ");
    posisi(x,y++);printf("   /  `-.__ ^   / .-'.--'    . /    `--./ .-'  `-.  `-. `.  -  `.    ");
    y++;
    posisi(x,y++);printf("  ___  _   ___                                    ___                ");
    posisi(x,y++);printf(" |   \\(_) | _ ) __ _ ___ ___ __ __ _ _ __  _ __  | _ \\_ _ __ _ _  _  ");
    posisi(x,y++);printf(" | |) | | | _ \\/ _` (_-</ -_) _/ _` | '  \\| '_ \\ |  _/ '_/ _` | || | ");   
    posisi(x,y++);printf(" |___/|_| |___/\\__,_/__/\\___\\__\\__,_|_|_|_| .__/ |_| |_| \\__,_|\\_,_| ");
    posisi(x,y++);printf("                                          |_|                        ");
}

void logos(int a,int b,int c){
    warna_text(c);
        posisi(a,b);printf("%c%c%c%c%c  B A S E C A M P ",219,219,223,219,221,219);
        b++;posisi(a,b);printf("%c%c%c%c%c %c%c%c%c%c %c%c%c%c%c %c%c %c%c",219,219,220,219,219,219,219,219,219,220,222,219,219,219,221,219,219,219,219,219);   
        b++;posisi(a,b);printf("%c%c%c%c%c %c%c%c%c%c %c%c%c%c%c %c%c %c%c",219,219,223,223,223,219,219,220,219,223,219,219,220,219,219,219);
        b++;posisi(a,b);printf("%c%c    %c%c %c%c %c%c %c%c %c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,223,219,219,219,219,219,219,219);
        b++;posisi(a,b);printf("             2.565 Mdpl");
}

void hapus(){  
    for(int b=0;b<=28;b++){
        for(int a=26;a<=118;a++){
            warna_bg(13);
            posisi(a,b);printf(" ");
        }
    }
}

void syarat(){
    for(int a=29;a<=100;a++){
        for(int b=7;b<=21;b++){
        posisi(a,b);warna_bg(6);printf(" ");
        }
    }
posisi(30,8); printf("%c SYARAT PENDAKIAN G. PRAU :",254);
posisi(33,10); printf("1. Menunjukan surat vaksin");
posisi(33,11); printf("2. Membawa surat keterangan sehat");
posisi(33,12); printf("3. Wajib mengikuti peraturan yang berlaku");
posisi(33,13); printf("4. Wajib membawa perlengkapan pendakian sesuai SOP");
posisi(33,14); printf("5. Wajib membawa Kartu Identitas (KTP,SIM, kartu Pelajar/Mahasiswa)");
posisi(33,15); printf("6. Membayar regristasi pendakian Rp 15.000/orang");
posisi(33,16); printf("7. Pendaki wajib lapor setelah melakukan pendakian");
warna_bg(11);warna_text(6);
posisi(85,20); printf(" Next <ENTER> ");
int j;
    do{
    j = getch();
        if(j == 13){
            hapus();
            regristaz(30);
        }
    }while(j != 13);
}

void appinfo(){
int yo;
header(2);
warna_bg(13);
posisi(30,8); printf(" Aplikasi BASECAMP PRAU merupakan aplikasi untuk para pendaki yang	");
posisi(30,9); printf(" ingin melakukan pendakian di Gunung Prau, dengan menggunakan aplikasi	");
posisi(30,10); printf(" ini pendaki dapat melakukan regristasi pendakian Gunung Prau secara	");
posisi(30,11); printf(" online. ");
posisi(30,13); printf(" Versi		: 0.01.22.001 (beta version)");
posisi(30,14); printf(" Rilis		: 16/01/2022	");
posisi(30,15); printf(" Update		: -	");
posisi(30,16); printf(" Developer	: Ryand Design Studio TM. ");
warna_text(12);
posisi(30,20); printf(" All Right Reserved");
posisi(70,20); printf(" Instagram @rdxrmd ");

warna_text(6); warna_bg(11);
posisi(95,25);printf(" kembali <Esc> ");
do{
    yo = getch();
        if(yo==27){ 
            hapus();
            welcome(38,3);
            klikMenu(18);
        }
    }while(yo!=27);
}

void garis(int x,int y){
    warna_text(6);
    posisi(x,y);printf("%c%c%c%c%c%c%c%c%c%c",223,223,223,223,223,223,223,223,223,223);
}

void garis2(int x,int y){
    warna_text(6);
    for(int a=1;a<=5;a++){
        posisi(x,y+a);printf("%c",219);
    }
}

void footer(int x,int y){
    warna_text(6);
    for(int a=0;a<=119;a++){
        posisi(x+a,y);printf("%c\b",219);
    }
}

void infopendakian(){
header(6);
int klikinfo=0;
int m=30;
warna_bg(13);warna_text(10);
    posisi(27,7);printf("%c Jalur Pendakian : ",254);
    posisi(30,8);printf(" Patak Banteng "); 
    posisi(50,8);printf("   Dwarawati   ");
    posisi(70,8);printf("     Wates     ");
    posisi(90,8);printf("   Kalilembu   ");

            warna_text(10); warna_bg(13);
            posisi(27,10);printf("%c Lokasi : Desa Patak Banteng, Kec. Kejajar, Kab. Wonosobo",254);
            posisi(27,11);printf("%c Durasi Pendakian: 2-3 Jam",254);
            posisi(27,12);printf("%c Jumlah Pos : 3",254);
            posisi(30,14);printf("Basecamp - Pos 1(Sikut Dewo)                : 27 Menit");
            posisi(30,15);printf("Pos 1(Sikut Dewo) - Pos 2(Canggal Wilangan) : 45 Menit");
            posisi(30,16);printf("Pos 2(Canggal Wilangan) - Pos 3(Cacingan)   : 45 Menit");
            posisi(30,17);printf("Pos 3(Cacingan) - Puncak                    : 45 Menit");

            warna_text(6); warna_bg(11);
            posisi(95,25);printf(" Kembali <Esc> ");
    do{
        regristaztmp(m,15,10);

        klikinfo=getch();
            switch(klikinfo){
                case 77:
                    regristaztmp(m,10,13);
                    m+=20;
                    if(m>90){
                        m=30;
                }break; 
                case 75 :
                    regristaztmp(m,10,13);
                    m-=20;
                    if(m<30){
                    m=90;
                }break;
                case 27 :
                    hapus();
                    welcome(38,3);
                    klikMenu(16);
                break;
                default :
                break;
            } 
        
        if(m == 30){
            warna_text(10); warna_bg(13);
            posisi(27,10);printf("%c Lokasi : Desa Patak Banteng, Kec. Kejajar, Kab. Wonosobo",254);
            posisi(27,11);printf("%c Durasi Pendakian: 2-3 Jam",254);
            posisi(27,12);printf("%c Jumlah Pos : 3",254);
            posisi(30,14);printf("Basecamp - Pos 1(Sikut Dewo)                : 27 Menit");
            posisi(30,15);printf("Pos 1(Sikut Dewo) - Pos 2(Canggal Wilangan) : 45 Menit");
            posisi(30,16);printf("Pos 2(Canggal Wilangan) - Pos 3(Cacingan)   : 45 Menit");
            posisi(30,17);printf("Pos 3(Cacingan) - Puncak                    : 45 Menit");
            }
            if(m == 50){
            warna_text(10); warna_bg(13);
            posisi(27,10);printf("%c Lokasi : Desa Dieng Kulon, Kec. Batur Kab. Banjarnegara ",254);
            posisi(27,11);printf("%c Durasi Pendakian: 2-3 Jam",254);
            posisi(27,12);printf("%c Jumlah Pos : 3",254);
            posisi(30,14);printf("Basecamp - Pos 1(Gemekan)                   : 30 Menit");
            posisi(30,15);printf("Pos 1(Gemekan) - Pos 2(Semendung)           : 45 Menit");
            posisi(30,16);printf("Pos 2(Semendung) - Pos 3(Nganjir)           : 45 Menit");
            posisi(30,17);printf("Pos 3(Nganjir) - Puncak                     : 90 Menit");
            posisi(30,18);printf("Puncak - Bukit Teletubis                    : 25 Menit");
            }
            if(m == 70){
            warna_text(10); warna_bg(13);
            posisi(27,10);printf("%c Lokasi : Desa Wates, Kec. Wonoboyo, Kab. Temanggung       ",254);
            posisi(27,11);printf("%c Durasi Pendakian: +-3 Jam",254);
            posisi(27,12);printf("%c Jumlah Pos : 3",254);
            posisi(30,14);printf("Basecamp - Pos 1(Blumbung Kodok)            : 60 Menit");
            posisi(30,15);printf("Pos 1(Blumbung Kodok) - Pos 2(Cemaran)      : 30 Menit");
            posisi(30,16);printf("Pos 2(Cemaran) - Pos 3(Sudung Dewo)         : 30 Menit");
            posisi(30,17);printf("Pos 3(Sudung Dewo) - Camp Area              : 45 Menit");
            posisi(30,18);printf("Camp Area - Puncak                          : 20 Menit");
            }
            if(m == 90){
            warna_text(10); warna_bg(13);
            posisi(27,10);printf("%c Lokasi : Desa Kalilembu, Kec. Kejajar, Kab. Wonosobo      ",254);
            posisi(27,11);printf("%c Durasi Pendakian: 2-3 Jam",254);
            posisi(27,12);printf("%c Jumlah Pos : 3",254);
            posisi(30,14);printf("Basecamp - Pos 1                            : 40 Menit");
            posisi(30,15);printf("Pos 1 - Pos 2(                              : 60 Menit");
            posisi(30,16);printf("Pos 2 - Pos 3                               : 50 Menit");
            posisi(30,17);printf("Pos 3 - Puncak                              : 40 Menit");

        }
    }while(klikinfo!=27);
}

void header(int mana){
    warna_text(10);
    switch(mana){ 
        case 1 :
            posisi(50,1);printf("  ___              _    _           _      ");
            posisi(50,2);printf(" | _ \\___ __ _ _ _(_)__| |_ __ _ __(_)    ");
            posisi(50,3);printf(" |   / -_) _` | '_| (_-<  _/ _` (_-< |     ");
            posisi(50,4);printf(" |_|_\\___\\__, |_| |_/__/\\__\\__,_/__/_| ");
            posisi(50,5);printf("         |___/                             ");
            break;
        case 2 :
            posisi(50,1);printf("    _               ___       __           ");
            posisi(50,2);printf("   /_\\  _ __ _ __  |_ _|_ _  / _|___      ");
            posisi(50,3);printf("  / _ \\| '_ \\ '_ \\  | || ' \\|  _/ _ \\ ");
            posisi(50,4);printf(" /_/ \\_\\ .__/ .__/ |___|_||_|_| \\___/   ");
            posisi(50,5);printf("       |_|  |_|                            ");
            break;
        case 4 :
            posisi(45,1);printf("  ___                    ___         _  ");         
            posisi(45,2);printf(" / __| _____ __ ____ _  | _ \\___ _ _| |____ _ _ __	    ");
            posisi(45,3);printf(" \\__ \\/ -_) V  V / _` | |  _/ -_) '_| / / _` | '_ \\     ");
            posisi(45,4);printf(" |___/\\___|\\_/\\_/\\__,_| |_| \\___|_| |_\\_\\__,_| .__/ ");
            posisi(45,5);printf("                                             |_|  	        ");  
            break;		
        case 5 :
            posisi(45,1);printf("   ___     _     ___                                     ");
            posisi(45,2);printf("  / __|___| |__ | _ \\___ ___ __ _ _ _  __ _ _ _         ");
            posisi(45,3);printf(" | (__/ -_) / / |  _/ -_|_-</ _` | ' \\/ _` | ' \\       ");
            posisi(45,4);printf("  \\___\\___|_\\_\\ |_| \\___/__/\\__,_|_||_\\__,_|_||_| ");
            break;
        case 6 :
            posisi(50,1);printf("  ___    _   _               _     ");
            posisi(50,2);printf(" | __|__| |_(_)_ __  __ _ __(_)    ");
            posisi(50,3);printf(" | _|(_-<  _| | '  \\/ _` (_-< |   ");
            posisi(50,4);printf(" |___/__/\\__|_|_|_|_\\__,_/__/_|   ");
        break;
        case 7 :   
            posisi(50,1);printf("  ___                      ");
            posisi(50,2);printf(" | _ ) __ _ _  _ __ _ _ _  ");
            posisi(50,3);printf(" | _ \\/ _` | || / _` | '_| ");
            posisi(50,4);printf(" |___/\\__,_|\\_, \\__,_|_|   ");
            posisi(50,5);printf("            |__/           ");
        break;
    }
}

void invalidsewa(int w){
    switch(w){
        case 1:
            warna_text(5);
            posisi(43,15);printf(" lu order apaan !? ");
            Sleep(700);
            posisi(44,15);printf("                   ");
            posisi(61,13);printf("                   ");
            posisi(65,14);printf("                   ");  
        break;  
        case 2:
            warna_text(5);
            posisi(43,15);printf(" maks. sewa 3 hari & 3 barang/item");
            Sleep(900);
            posisi(44,15);printf("                                  ");
            posisi(61,13);printf("                   ");
            posisi(65,14);printf("                   "); 
        break;
    } 
}

void perkap(int a, int w1, int w2){

    warna_text(w1);warna_bg(w2);
    if(a==12){
        posisi(30,a); printf(" TENDA    ");
    }                      
    else if(a==14){
        posisi(30,a); printf(" SB       ");
    }
    else if(a==16){
        posisi(30,a); printf(" MATRAS   ");
    }
    else if(a==18){
        posisi(30,a); printf(" JAKET    ");
    }
    else if(a==20){
        posisi(30,a); printf(" DAYPACK  ");
    }
}

void hapus2(){
    for(int a=44;a<=90;a++){
        for(int b=8;b<=20;b++){
            warna_bg(13);
            posisi(a,b);printf(" ");
        }
    }
}
void regristaztmp(int a, int w1, int w2){
    warna_text(w1);warna_bg(w2);
    if(a==30){
        posisi(a,8);printf(" Patak Banteng "); 
    }
    else if(a==50){
        posisi(a,8);printf("   Dwarawati   ");
    }
    else if(a==70){
        posisi(a,8);printf("     Wates     ");
    }
    else if(a==90){
        posisi(a,8);printf("   Kalilembu   ");
    }
}

void bayartmp(int a,int w1,int w2){
    warna_text(w1);warna_bg(w2);
    if(a==30){
        posisi(a,8);printf("      DANA     "); 
    }
    else if(a==50){
        posisi(a,8);printf("      OVO      ");
    }
    else if(a==70){
        posisi(a,8);printf("    LinkAja    ");
    }
    else if(a==90){
        posisi(a,8);printf("     Gopay     ");
    }
}