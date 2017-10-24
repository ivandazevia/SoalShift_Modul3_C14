#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
    int input;
    int barang[7] = {0,0,0,0,0,0,0,0};
    while(1){
        printf("Siapakah Anda?\n");
        printf("1. Penjual\n");
        printf("2. Pembeli\n");
        scanf("%d",&input);
        if(input==1){
            while(1){
                printf("Pilih Perintah : \n");
                printf("1. Lihat stock barang\n");
                printf("2. Tambah stock barang\n");
                printf("3. End session\n");
                int perintah;
                printf("Masukkan perintah : ");
                scanf("%d",&perintah);
                if(perintah==1){
                    system("clear");
                    for(int i=1;i<=6;i++){
                        if(barang[i]==0) continue;//printf("barang[%d] = kosong\n",i);
                        else{
                            if(i==1) printf("MP4A1 = %d\n",barang[1]);
                            else if(i==2) printf("PM2-V1 = %d\n",barang[2]);
                            else if(i==3) printf("SPR-3 = %d\n",barang[3]);
                            else if(i==4) printf("SS2-V5 = %d\n",barang[4]);
                            else if(i==5) printf("SPG1-V3 = %d\n",barang[5]);
                            else if(i==6) printf("MINE = %d\n",barang[6]);
                        }
                    }
                }
                else if(perintah==2){
                    system("clear");
                    char updatebarang[11];
                    int jumlahbarang;
                    printf("Pilih barang yang akan di tambah stock:\n");
                    printf("Format menambah stock [nama barang] [jumlah barang]\n");
                    printf("MP4A1\n");
                    printf("PM2-V1\n");
                    printf("SPR-3\n");
                    printf("SS2-V5\n");
                    printf("SPG1-V3\n");
                    printf("MINE\n");
                    scanf("%s",updatebarang);
                    getchar();
                   // printf("%s\n",updatebarang);
                    scanf("%d",&jumlahbarang);
                    //printf("%s %d\n",updatebarang,jumlahbarang);

                    if(strcmp(updatebarang, "MP4A1") == 0) barang[1]+=jumlahbarang;
                    else if(strcmp(updatebarang, "PM2-V1") == 0) barang[2]+=jumlahbarang;
                    else if(strcmp(updatebarang, "SPR-3") == 0) barang[3]+=jumlahbarang;
                    else if(strcmp(updatebarang, "SS2-V5") == 0) barang[4]+=jumlahbarang;
                    else if(strcmp(updatebarang, "SPG1-V3") == 0) barang[5]+=jumlahbarang;
                    else if(strcmp(updatebarang, "MINE") == 0) barang[6]+=jumlahbarang;
                }
                else break;
            }
        }
        else{
            while(1){
                printf("Pilih Perintah : \n");
                printf("1. Lihat stock barang\n");
                printf("2. Beli barang\n");
                printf("3. End session\n");
                int perintah;
                printf("Masukkan perintah : ");
                scanf("%d",&perintah);
                if(perintah==1){
                    system("clear");
                    for(int i=1;i<=6;i++){
                        if(i==1) printf("MP4A1 = %d\n",barang[1]);
                        else if(i==2) printf("PM2-V1 = %d\n",barang[2]);
                        else if(i==3) printf("SPR-3 = %d\n",barang[3]);
                        else if(i==4) printf("SS2-V5 = %d\n",barang[4]);
                        else if(i==5) printf("SPG1-V3 = %d\n",barang[5]);
                        else if(i==6) printf("MINE = %d\n",barang[6]);
                    }
                }
                else if(perintah==2){
                    system("clear");
                    char updatebarang[11];
                    int jumlahbarang;
                    printf("Pilih barang yang akan di beli:\n");
                    printf("Format membeli [nama barang] [jumlah barang]\n");
                    printf("MP4A1\n");
                    printf("PM2-V1\n");
                    printf("SPR-3\n");
                    printf("SS2-V5\n");
                    printf("SPG1-V3\n");
                    printf("MINE\n");
                    scanf("%s",updatebarang);
                    getchar();
                   // printf("%s\n",updatebarang);
                    scanf("%d",&jumlahbarang);
                    //printf("%s %d\n",updatebarang,jumlahbarang);

                    if(strcmp(updatebarang, "MP4A1") == 0 && barang[1]>=jumlahbarang) barang[1]-=jumlahbarang;
                    else if(strcmp(updatebarang, "PM2-V1") == 0 && barang[2]>=jumlahbarang) barang[2]-=jumlahbarang;
                    else if(strcmp(updatebarang, "SPR-3") == 0 && barang[3]>=jumlahbarang) barang[3]-=jumlahbarang;
                    else if(strcmp(updatebarang, "SS2-V5") == 0 && barang[4]>=jumlahbarang) barang[4]-=jumlahbarang;
                    else if(strcmp(updatebarang, "SPG1-V3") == 0 && barang[5]>=jumlahbarang) barang[5]-=jumlahbarang;
                    else if(strcmp(updatebarang, "MINE") == 0 && barang[6]>=jumlahbarang) barang[6]-=jumlahbarang;
                    else printf("Stock barang yang anda pilih tidak mencukupi\n");
                }
                else break;
            }
        }
    }
    return 0;
}

