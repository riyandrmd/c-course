#include <stdio.h>
#include <conio.h>
#include "menudll.c"
#include "validasi.c"
#include <stdbool.h>

//colorlist
//15 > 255,255,255
//14 > 197,198,200
//13 > 151,225,226
//12 > 43,122,119
//11 > 23,55,55
//10 > 11,12,16
//6  > 251,216,62
//5  > 178,10,10
//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////PROTOTYPE///////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

void bcg(int x,int y,int c);
void menutama(int a, int w1, int w2);
void klikMenu(int y);
void menu();
void tblMasuk(int a, int w1, int w2);
void Masuk();
void klikAwal();
void menuPilih();
void Daftar();
void loadingBar();
void loadingText(int y);
void logos(int a,int b,int c);
void regristaztmp(int a, int w1, int w2);
void regristaz(int m);
void konfirmasi(char jalur2[30],char nama2[30],char asal2[30],int jumlah2);
void tanggal();
void sewaperkap();
void navsewa();
void cekNama();
void cekDaerah();
void bayardong(int total,int x);

//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////GLOBALCLIMATECHANGE/////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

char usertmp[30];
char jalur[30];
int jumlah;
char jum[30],nama[30],asal[30];
int klikreg=0;
int salah=0;
int m=30,yo=0,y=10,yp=12;
int day2,month2,year2;
int bulan[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int tenda,sb,matras,jaket,daypack,lama;
char tenda2[30],sb2[30],matras2[30],jaket2[30],daypack2[30],lama2[30];
int totalreg,totalsewa;
char jalur5[30][30];
char nama5[30][30];
char asal5[30][30];
char tanggal5[30][30];

//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////PROSEDURE///////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

void main(){
    system("mode con cols=120 lines=30");
    bcg(0,0,11);    
    logos(49,8,6);
    loadingBar();

    getch();
}

void cekpesanan(){
    FILE *data;
	data = fopen("regris.txt","r");
    int a=0;
    char au;
    header(5);
    warna_bg(6); warna_text(11);
    posisi(30,29);printf(" Kembali <Esc> ");
    warna_bg(13); warna_text(10);
    while(!feof(data)){
            fgets(jalur5[a],sizeof(jalur5[a]),data);
            fgets(nama5[a],sizeof(nama5[a]),data);
            fgets(asal5[a],sizeof(asal5[a]),data);
            fgets(tanggal5[a],sizeof(tanggal5[a]),data);
        a++;
    }a--;
    int t=0; 
    for(int a=0;a<=3;a++){
        posisi(27,6+t); printf("%c jalur : %s",254,jalur5[a]);
        posisi(27,7+t); printf("   nama  : %s", nama5[a]);
        posisi(27,8+t); printf("   asal daerah : %s", asal5[a]); 
        posisi(27,9+t); printf("   tanggal : %s", tanggal5[a]);
        t+=4;
    }
    t=0;
    do{
    au = getch();
        if(au==27){ 
            hapus();
            welcome(38,3);
            klikMenu(14);
        }

    }while(au!=27);
}

void konfirmasi(char jalur2[30],char nama2[30],char asal2[30],int jumlah2 ){

    totalreg += jumlah2*15000;
    int klok;
    header(1);
    warna_bg(13); warna_text(10);
    posisi(29,7);printf("%c Jalur pendakian via : %s",254,jalur2);
    posisi(29,9);printf("%c Hari tanggal : %02d / %02d / %04d",254,day2,month2,year2);
    posisi(29,11);printf("%c Penanggung jawab : %s",254,nama2);
    posisi(29,13);printf("%c Asal Daerah (Kota/kabupaten) : %s",254,asal2);
    posisi(29,15);printf("%c Jumlah Pendaki  :  %2d",254,jumlah2);
    posisi(29,17);printf("Biaya Simaksi Rp %d ",totalreg);
    warna_text(11);warna_bg(6);
    posisi(30,29);printf(" Kembali <Esc> ");
    posisi(75,29);printf(" Konfirmasi <ENTER> ");

    do{
        klok = getch();
        if(klok == 27){
            hapus();
            regristaz(m);
        }else if(klok == 13){
            bayardong(totalreg,1);
        }
    }while(klok =! 27 || klok != 13);
}

void menutama(int a, int w1, int w2){

    warna_text(w1);warna_bg(w2);
    if(a==10){
        posisi(1,a); printf(" REGRISTASI PENDAKIAN ");
    }
    else if(a==12){
        posisi(1,a); printf(" SEWA PERKAP ");
    }
    else if(a==14){
        posisi(1,a); printf(" CEK PESANAN ");
    }
    else if(a==16){
        posisi(1,a); printf(" INFO JALUR PENDAKIAN ");
    }
    else if(a==18){
        posisi(1,a); printf(" TENTANG App. ");
    }
    else if(a==20){
        posisi(1,a); printf(" LOGOUT ");
    }
}

void klikMenu(int y){
    int kliknya;
    do{
        menutama(y,15,12);
        kliknya=getch();
            switch(kliknya){
                case 80:
                    menutama(y,15,11);
                    y+=2;
                    if(y>20){
                        y=10;
                }break; 
                case 72 :
                    menutama(y,15,11);
                    y-=2;
                    if(y<10){
                        y=20;
                }break;
            }
    }while(kliknya!=13);
    
    if(y==10 && kliknya==13){
        warna_text(10);warna_bg(6);
        posisi(1,y); printf(" REGRISTASI PENDAKIAN ");
        Sleep(50);
        hapus();
        syarat();
    }
    else if(y==12 && kliknya==13){
        warna_text(10);warna_bg(6);
        posisi(1,y);printf(" SEWA PERKAP ");
        hapus();
        Sleep(50);
        sewaperkap(yp);
       
    }
    else if(y==14 && kliknya==13){
        warna_text(10);warna_bg(6);
        posisi(1,y); printf(" CEK PESANAN ");
        hapus();
        Sleep(50);
        cekpesanan();
    }
    else if(y==16 && kliknya==13){
        warna_text(10);warna_bg(6);
        posisi(1,y); printf(" INFO JALUR PENDAKIAN ");
        Sleep(50);
        hapus();
        infopendakian();
    }
    else if(y==18 && kliknya==13){
        warna_text(10);warna_bg(6);
        posisi(1,y); printf(" TENTANG App. ");
        Sleep(500);
        hapus();
        header(2);
        appinfo();
    }
    else if(y==20 && kliknya==13){
        warna_text(10);warna_bg(6);
        posisi(1,y);printf(" LOGOUT ");
        Sleep(500);
        
        bcg(0,0,11);
        logos(49,8,6);
        menuPilih();
        klikAwal();
    }
}

void cekNama(){
   int h=1;
   int b=0;
   int r=1;
   int y=0;

   strcpy(nama,valBatas(48,14,20,11,13));
   strupr(nama);

    y=strlen(nama);

    if(y<1){
          posisi(48,14);printf("                                 ");
          posisi(48,14);printf("Invalid");
          Sleep(500);
          posisi(48,14);printf("                                  ");
          cekNama();
       }


 for(int x=0;x<y;x++){
    if(nama[x]>64&&nama[x]<91||nama[x]==32||nama[x]==39){
            r=0;}
    else{
            posisi(48,14);printf("                         ");
            posisi(48,14);printf("Invalid");
            Sleep(500);
            posisi(48,14);printf("                         ");
            cekNama();
        }

            if(r==0){
                if(nama[x]==32){
                    b=1;
                }
                if(b==1&&nama[x+1]==32){
                    posisi(48,14);printf("                         ");
                    posisi(48,14);printf("Invalid");
                    Sleep(500);
                    posisi(48,14);printf("                         ");
                    cekNama();
                }
                if(nama[x]>64&&nama[x]<91){
                h=0;
                }
                if(nama[0]==39){
                h=1;
                }
                    if(nama[x-1]!=39&&nama[x]==39){
                h=0;
                }

                if(nama[y-1]==39||nama[x]==39&&nama[x+1]==39){
                    h=1;
                }
                if( nama[0]==32 ||nama[x]==32&&nama[x+1]==32|| nama[y-1]==32){
                    h=1;
                }
            }

        if (h==1){

            posisi(48,14);printf("                                 ");
            posisi(48,14);printf("Invalid");
            Sleep(500);
            posisi(48,14);printf("                                  ");
            cekNama();
        }else{
        posisi(48,14);printf("%s",nama);

        }
    }
}

void cekDaerah(){
   int h=1;
   int b=0;
   int r=1;
   int y=0;

   strcpy(asal,valBatas(60,16,20,11,13));
   strupr(asal);

    y=strlen(asal);

    if(y<1){
          posisi(60,16);printf("                                 ");
          posisi(60,16);printf("Invalid");
          Sleep(500);
          posisi(60,16);printf("                                  ");
          cekDaerah();
       }


 for(int x=0;x<y;x++){
    if(asal[x]> 64 &&asal[x]< 91 ||asal[x]== 32 ||asal[x]== 39 ){
            r=0;
    }
    else{
            posisi(60,16);printf("                         ");
            posisi(60,16);printf("Invalid");
            Sleep(500);
            posisi(60,16);printf("                         ");
            cekDaerah();
        }

            if(r==0){
                if(asal[x]==32){
                    b=1;
                }
                if(b==1&&asal[x+1]==32){
                    posisi(60,16);printf("                         ");
                    posisi(60,16);printf("Invalid");
                    Sleep(500);
                    posisi(60,16);printf("                         ");
                    cekDaerah();
                }
                if(asal[x]>64&&asal[x]<91){
                h=0;
                }
                if(asal[0]==39){
                h=1;
                }
                    if(asal[x-1]!=39&&asal[x]==39){
                h=0;
                }

                if(asal[y-1]== 39||asal[x]==39&&asal[x+1]==39){
                    h=1;
                }
                if( asal[0] == 32 ||asal[x]==32&&asal[x+1]==32|| asal[y-1]==32){
                    h=1;
                }
            }

        if (h==1){

            posisi(60,16);printf("                                 ");
            posisi(60,16);printf("Invalid");
            Sleep(500);
            posisi(60,16);printf("                                  ");
            cekDaerah();
        }else{
        posisi(60,16);printf("%s",asal);

        } 
    }
}

void regristaz(int m){
    header(1);
    warna_bg(13);warna_text(10);
    posisi(27,7);printf("%c Pilih Jalur Pendakian : ",254);
    posisi(30,8);printf(" Patak Banteng "); 
    posisi(50,8);printf("   Dwarawati   ");
    posisi(70,8);printf("     Wates     ");
    posisi(90,8);printf("   Kalilembu   ");
    warna_text(11);warna_bg(6);
    posisi(30,29);printf(" Kembali <Esc> ");

    do{
        regristaztmp(m,15,11);
        klikreg=getch();
            switch(klikreg){
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
                    warna_bg(6);
                    posisi(30,29);printf("               ");
                    hapus();
                    welcome(38,3);
                    klikMenu(y);
                break;
            }
    }while(klikreg!=13);


        if(m==30 && klikreg==13){
            warna_bg(11);warna_text(6);
            posisi(m,8);printf(" Patak Banteng ");
            strcpy(jalur,"Patak Banteng");
            warna_bg(6);
            posisi(30,29);printf("               ");
        }
        else if(m==50 && klikreg==13){
            warna_bg(11);warna_text(6);
            posisi(m,8);printf("   Dwarawati   ");
            strcpy(jalur,"Dwarawati");
            warna_bg(6);
            posisi(30,29);printf("               ");
        }
        else if(m==70 && klikreg==13){
            warna_bg(11);warna_text(6);
            posisi(m,8);printf("     Wates     ");
            strcpy(jalur,"Wates");
            warna_bg(6);
            posisi(30,29);printf("               ");
        }
        else if(m==90 && klikreg==13){
            warna_bg(11);warna_text(6);
            posisi(m,8);printf("   Kalilembu   ");
            strcpy(jalur,"Kalilembu");
            warna_bg(6);
            posisi(30,29);printf("               ");
        }

            warna_bg(13); warna_text(10);
           
            posisi(29,12); printf("DD/MM/YYYY (untuk tahun 2022)");
            posisi(27,11); printf("%c Tgl. Pendakian : ",254);
            tanggal();

            warna_bg(13); warna_text(10);
            posisi(27,14);printf("%c Penanggung Jawab : ",254);
            cekNama();
            
            posisi(27,16);printf("%c Asal Daerah (Kota/kabupaten) : ",254);
            cekDaerah();
            
            do{
            posisi(27,18);printf("%c Jumlah Pendaki : ",254);
            strcpy(jum,angka(45,18,2));
            jumlah=atoi(jum);
            if(jumlah > 15 ){
                    posisi(45,18);printf("Maks. 15 orang");
                    Sleep(500);
                    posisi(45,18);printf("              ");
                }
            }while(jumlah>15);
    hapus();
    konfirmasi(jalur,nama,asal,jumlah);
    }

void menu(){
    for(int a=0;a<=25 ;a++){
        for(int b=0;b<=29;b++){
            warna_bg(11);
            posisi(a,b);printf(" ");
        }
    }
    logos(1,1,6);
    footer(0,29);
    warna_text(10);warna_bg(6); 
    posisi(2,29);printf("%c[%s] online %c",254,usertmp,254 );
    warna_bg(11);warna_text(6);
    posisi(1,8); printf("MENU>>>");
    warna_text(15);
    posisi(1,10); printf(" REGRISTASI PENDAKIAN ");
    posisi(1,12); printf(" SEWA PERKAP ");
    posisi(1,14); printf(" CEK PESANAN ");
    posisi(1,16); printf(" INFO JALUR PENDAKIAN ");
    posisi(1,18); printf(" TENTANG App. ");
    posisi(1,20); printf(" LOGOUT "); 
    
    welcome(38,3);
    klikMenu(y);
}

void tblMasuk(int a, int w1, int w2){

    warna_text(w1);warna_bg(w2);

    if(a==14){
    posisi(52,a);printf("      Masuk       ");
    posisi(52,a+1);printf("                  ");
    }
    else if (a==17){
    posisi(52,a);printf("      Daftar      ");
    posisi(52,a+1);printf("                  ");
    }
    else if (a==20){
    posisi(52,a);printf("      Keluar      ");
    posisi(52,a+1);printf("                  ");
    }
}

void Masuk(){
    char un[30],pw[30];
    warna_bg(6);
        for(int x=45;x<=75;x++){
            for(int y=8;y<=18;y++){
                posisi(x,y);printf(" ");
            }
        }
    warna_text(10);
    posisi(58,9);printf("LOGIN");
    posisi(46,12);printf("username :");
    posisi(46,14);printf("password :");
    warna_text(10);
    warna_bg(15);
    posisi(57,12);printf("                ");
    posisi(57,14);printf("                ");
    
    strcpy(un,valBataslog(57,12,12,0));
    strcpy(pw,valBataslog(57,14,8,1));
    strlwr(un);
    strcpy(usertmp,un);
    
    if(login(un,pw) == '0'){
        warna_text(15);
        warna_bg(12);
        posisi(45,16);printf("         SUKSES LOGIN !        ");
        posisi(45,17);printf("                               ");
        warna_bg(11);
        loadingText(20);

        for(int a=85;a>=35;a--){
            for(int c=8;c<=20;c++){
                warna_bg(11);posisi(a,c);printf(" "); 
            }Sleep(5);
        }
        bcg(0,0,13);
        menu();
    }
    else{
        salah+=1;
        warna_text(15);
        warna_bg(5);
        posisi(45,16);printf(" USERNAME ATAU PASSWORD SALAH! ");
        posisi(45,17);printf("                               ");
        Sleep(300);
        if(salah < 3 ){
            Masuk();
        }else {
            salah=0;
            posisi(45,16);printf("  TIDAK DAPAT LOGIN SEMENTARA  ");
            posisi(45,17);printf("                               ");
            Sleep(900);
            main();
        }
    }   
}

void klikAwal(){
    int klikAwal,y=14;
    do{
        tblMasuk(y,15,12);
        klikAwal=getch();
            switch(klikAwal){
                case 80:
                    tblMasuk(y,15,11);
                    y+=3;
                    if(y>21){
                        y=14;
                }break; 
                case 72 :
                    tblMasuk(y,15,11);
                    y-=3;
                    if(y<14){
                        y=20;
                }break;
            }
    }while(klikAwal!=13);
        if(y==14 && klikAwal==13){
            for(int a=85;a>=35;a--){
                for(int c=8;c<=25;c++){
                    warna_bg(11);posisi(a,c);printf(" "); 
                }
            }
            Sleep(5);
            Masuk();
        }
    else if(y==17 && klikAwal==13){
        for(int a=85;a>=35;a--){
            for(int c=8;c<=25;c++){
                warna_bg(11);posisi(a,c);printf(" "); 
            }
            }Sleep(5);Daftar();
    }
    else if(y==21 && klikAwal==13){ 
        exit(0);
    }
}
    
void menuPilih(){
    garis(49,13);
    garis2(49,12);
    garis(62,23);
    garis2(71,17);
    warna_text(15); warna_bg(11);
    posisi(52,14);printf("      Masuk       ");
    posisi(52,15);printf("                  ");
    posisi(52,17);printf("      Daftar      ");
    posisi(52,18);printf("                  ");
    posisi(52,20);printf("      Keluar      ");
    posisi(52,21);printf("                  ");
}

void Daftar(){
    char pass[30],user[30];
    warna_bg(6);warna_text(10);
        for(int x=45;x<=75;x++){
            for(int y=8;y<=19;y++){
                posisi(x,y);printf(" ");
            }
        }

    posisi(58,9);printf("DAFTAR");
    posisi(48,10);printf("buat username & password");
    posisi(46,12);printf("username :");
    posisi(46,14);printf("password :");
    warna_text(10);
    warna_bg(15);
    posisi(57,12);printf("                ");
    posisi(57,14);printf("                ");
    posisi(57,14);printf("                ");

    strcpy(user,valUserdaftar(57,12,12));
    strcpy(pass,valBataslog(57,14,8,0));
    strlwr(user); strlwr(pass);

        if(cekndaftar(user) == '0'){
            warna_text(15);
    		warna_bg(5);
            posisi(45,16);printf("        AKUN SUDAH ADA         ");
            posisi(45,17);printf("                               ");
            Sleep(500);
            Daftar();
            }

        else {
            warna_text(15);
            warna_bg(12);
            posisi(45,16);printf("         DATA DISIMPAN         ");
            posisi(45,17);printf("                               ");
            registai(user,pass);
            Sleep(500); 
            Masuk();
        }
}

void loadingBar(){
    for(int a=0; a<=50 ; a++){
   	    warna_text(15);
        posisi(35+a,15);printf("%c",219);
    }
	posisi(52,25);printf("Powered by VS Code");
	for(int a=0;a<=100;a++){
		warna_text(12);posisi(35+a/2,15);printf("%c",219);
        warna_text(15);posisi(60,16);printf("%d%%",a);
        Sleep(5);
    }
   
    Sleep(500);
    for(int b=14;b<=16;b++){
        for(int a=35;a<=85;a++){
            posisi(a,b);printf(" ");
        }Sleep(10);
    }
    posisi(52,25);printf("                      ");
    
    menuPilih();
    klikAwal();
}

void bayardong(int total,int x){
    int tamp,bayar,au;
    char bay[30];
    hapus();
    warna_bg(13);warna_text(10);
    header(7);
    posisi(27,7);printf("%c Pilih opsi pembayaran ",254);
    posisi(30,8);printf("      DANA     "); 
    posisi(50,8);printf("      OVO      ");
    posisi(70,8);printf("    LinkAja    ");
    posisi(90,8);printf("     Gopay     ");
    warna_text(11);warna_bg(6);
    posisi(30,29);printf("  Kembali <Esc>  ");
    posisi(75,29);printf("  Bayar <ENTER>  ");
    
    do{
       bayartmp(m,15,11);
        klikreg=getch();
            switch(klikreg){
                case 77:
                   bayartmp(m,10,13);
                    m+=20;
                    if(m>90){
                        m=30;
                }break; 
                case 75 :
                   bayartmp(m,10,13);
                    m-=20;
                    if(m<30){
                        m=90;
                }break;
                case 27 :
                    hapus();
                    welcome(38,3);
                    klikMenu(y);
                break;
            }
    }while(klikreg!=13);

if(m==30 && klikreg==13){
    warna_bg(11);warna_text(6);
    posisi(m,8);printf("      DANA     ");
}
if(m==50 && klikreg==13){
    warna_bg(11);warna_text(6);
    posisi(m,8);printf("      OVO      ");
}
if(m==70 && klikreg==13){
    warna_bg(11);warna_text(6);
    posisi(m,8);printf("    LinkAja    ");
}
if(m==90 && klikreg==13){
    warna_bg(11);warna_text(6);
    posisi(m,8);printf("     Gopay     ");
}

warna_text(10);warna_bg(13);
posisi(27,10);printf(" Biaya Admin : Rp 500 ");
total+=500;
posisi(27,11);printf(" TOTAL TAGIHAN : %d ",total);
    do{
        posisi(27,12);printf(" BAYAR :Rp. ");
        strcpy(bay,angka(38,12,8));
            bayar = atoi(bay);
            if(bayar > total){
                warna_text(10);warna_bg(13);
                posisi(38,12);printf("Nominal Harus Sama !");
                Sleep(500);
                posisi(38,12);printf("                    ");
            }
            else if(bayar==total){
                warna_text(10);warna_bg(13);
                posisi(27,13);printf(" LUNAS ");
                if(x=1){
                    booking(jalur,nama,asal,day2,month2,year2);
                }
                totalsewa=0;
                totalreg=0;
            }else{
                warna_text(10);warna_bg(13);
                posisi(38,12);printf(" Nominal Tidak Cukup ");
                Sleep(500);
                posisi(38,12);printf("                     ");
            }
        }while (bayar!=total);

    do{
    au = getch();
        if(au==27){ 
            hapus();
            welcome(38,3);
            klikMenu(m);
        }

    }while(au!=27);
}

void loadingText(int y){
    warna_text(15);posisi(54,y);printf("Loading...");
    for(int a=0;a<=100;a++){
        posisi(64,y);printf("%d%%",a);
        Sleep(10);
    }
}

void tanggal(){
    char day[5],month[5],year[5];    
    bool doi = false;
    do{

    strcpy(day,valBatas(46,11,2,10,13));
    printf("/");
    strcpy(month,valBatas(49,11,2,10,13));
    printf("/");
    strcpy(year,valBatas(52,11,4,10,13));

            day2 = atoi(day);
            month2 = atoi(month);
            year2 = atoi(year);

            if( year2 == 2022){
                if( year2%4==0 && year2%400==0 || year2%100!=0){
                    bulan[2]==29;
                    if(month2>=1 && month2<=12){
                        if(day2>=1 && day2<=bulan[month2]){
                            doi = 1;
                        }else{
                            posisi(46,11);
                            printf("Tanggal invalid");
                            Sleep(300);
                            posisi(46,11);printf("                 ");
                        }
                    }else{
                        posisi(46,11);
                        printf("Bulan invalid");
                        Sleep(300);
                        posisi(46,11);printf("                 ");
                    }
                }else{
                    posisi(46,11);
                    printf("Invalid input");
                    Sleep(300);
                    posisi(52,11);printf("                 ");
                }
            }else{
                posisi(46,11);
                printf("Invalid Input");
                Sleep(300);
                posisi(46,11);printf("                 ");
            }
    }while(doi == false);
}

void sewaperkap(int yp){
    int slik;  
    warna_bg(13);                          
    header(4);
    bool cek = false;
    for(int a=26;a<=40;a++){
        for(int b=0;b<=28;b++){
            warna_bg(12);
            posisi(a,b);printf("  ");
        }
    }
    warna_text(6);warna_bg(12);
    posisi(28,10);printf("PERKAP>>");
    warna_text(15);
    posisi(30,12);printf(" TENDA ");
    posisi(30,14);printf(" SB ");
    posisi(30,16);printf(" MATRAS ");
    posisi(30,18);printf(" JAKET ");
    posisi(30,20);printf(" DAYPACK ");
    warna_text(11);warna_bg(6);
    posisi(30,29);printf(" Kembali <Esc> ");

    do{
        perkap(yp,6,11);
        slik=getch();
        switch(slik){
            case 80:
                perkap(yp,15,12);
                yp+=2;
                if(yp>20){
                yp=12;
            }break; 
            case 72 :
                perkap(yp,15,12);
                yp-=2;
                if(yp<12){
                yp=20;
            }break;
            case 27 :
                hapus();
                welcome(38,3);
                klikMenu(12);
            break;
        }
    }while(slik!=13);
       
        if(slik==13 && yp==12){
            warna_text(11);warna_bg(13);
            posisi(44,10);printf(" Harga sewa Rp 30.000/hari");
            do{
                warna_text(11);
                fflush(stdin);
                posisi(44,13);printf("%c jumlah tenda : ",254);gets(tenda2);
                posisi(44,14);printf("%c lama sewa (hari) : ",254);gets(lama2);
                tenda=atoi(tenda2);
                lama=atoi(lama2);
                    if(tenda <= 3 && tenda > 0 || lama <= 3 && lama > 0){
                        cek = true;
                        totalsewa+=30000*tenda*lama;
                        posisi(44,16);printf("%c total : Rp %d",254,30000*tenda*lama);    
                    }
                    else if(tenda==0 || lama==0){
                        invalidsewa(1);
                    }else{
                        invalidsewa(2);
                    }
            }while(cek==false);
        }
    
    if(slik==13 && yp==14){
            warna_text(11);warna_bg(13);
            posisi(44,10);printf(" Harga sewa Rp 15.000/hari");
            do{
                warna_text(11);
                fflush(stdin);
                posisi(44,13);printf("%c jumlah SB : ",254);gets(sb2);
                posisi(44,14);printf("%c lama sewa (hari) : ",254);gets(lama2);
                sb=atoi(sb2);
                lama=atoi(lama2);
                    if(sb <= 3 && sb > 0 && lama <= 3 && lama > 0){
                        cek = true;
                        totalsewa+=15000*sb*lama;
                        posisi(44,16);printf("%c total : Rp %d",254,15000*sb*lama);    
                    }
                    else if(sb==0 || lama==0){
                        invalidsewa(1);
                    }else{
                        invalidsewa(2);
                    }
            }while(cek==false);
        }
    if(slik==13 && yp==16){
            warna_text(11);warna_bg(13);
            posisi(44,10);printf(" Harga sewa Rp 5.000/hari");
            do{
                warna_text(11);
                fflush(stdin);
                posisi(44,13);printf("%c jumlah matras : ",254);gets(matras2);
                posisi(44,14);printf("%c lama sewa (hari) : ",254);gets(lama2);
                matras=atoi(matras2);
                lama=atoi(lama2);
                    if(matras <= 3 && matras > 0 && lama <= 3 && lama > 0){
                        cek = true;
                        totalsewa+=5000*matras*lama;
                        posisi(44,16);printf("%c total : Rp %d",254,5000*matras*lama);    
                    }
                    else if(matras ==0 || lama ==0){
                        invalidsewa(1);
                    }else{
                        invalidsewa(2);
                    }
            }while(cek==false);
        }
    if(slik==13 && yp==18){
            warna_text(11);warna_bg(13);
            posisi(44,10);printf(" Harga sewa Rp 15.000/hari");
            do{
                warna_text(11);
                fflush(stdin);
                posisi(44,13);printf("%c jumlah jaket : ",254);gets(jaket2);
                posisi(44,14);printf("%c lama sewa (hari) : ",254);gets(lama2);
                jaket=atoi(jaket2);
                lama=atoi(lama2);
                    if(jaket <= 3 && jaket > 0 && lama <= 3 && lama > 0){
                        cek = true;
                        totalsewa+=15000*jaket*lama;
                        posisi(44,16);printf("%c total : Rp %d",254,15000*jaket*lama);    
                    }
                    else if(jaket == 0 || lama == 0){
                        invalidsewa(1);
                    }else{
                        invalidsewa(2);
                    }
            }while(cek==false);
        }
    if(slik==13 && yp==20){
            warna_text(11);warna_bg(13);
            posisi(44,10);printf(" Harga sewa Rp 25.000/hari");
            do{
                warna_text(11);
                fflush(stdin);
                posisi(44,13);printf("%c jumlah daypack : ",254);gets(daypack2);
                posisi(44,14);printf("%c lama sewa (hari) : ",254);gets(lama2);
                daypack=atoi(daypack2);
                lama=atoi(lama2);
                    if(daypack <= 3 && daypack > 0 && lama <= 3 && lama > 0){
                        cek = true;
                        totalsewa+=25000*daypack*lama;
                        posisi(44,16);printf("%c total : Rp %d",254,25000*daypack*lama); 
                    }
                    else if(daypack == 0 || lama == 0){
                        invalidsewa(1);
                    }else{
                        invalidsewa(2);
                    }
            }while(cek==false);
        }
    posisi(44,18);printf("%c TOTAL TAGIHAN : Rp %d",254,totalsewa);
    navsewa();  
}

void navsewa(){
    int klok;
    char totali[30];
    warna_bg(11);warna_text(6);
    posisi(45,25);printf(" Tambah <Esc>    ");
    posisi(95,25);printf(" Bayar <ENTER>   ");
    do{
        klok = getch();
        if(klok == 27){
            hapus2();
            sewaperkap(yp);

        }else if(klok == 13){
            hapus2();
            bayardong(totalsewa,0);
        }
    }while(klok =! 27|| klok != 13);
}

