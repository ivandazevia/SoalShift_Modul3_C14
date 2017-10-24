#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
//phtread_t tid[7];

int main(){
    int input;
    int barang[8] = {0};
    printf("Siapakah Anda?\n");
    printf("1. Penjual\n");
    printf("2. Pembeli\n");
    scanf("%d",&input);
    if(input==1){
        system("clear");
        printf("Pilih Perintah : \n");
        printf("1. Lihat stock barang\n");
        printf("2. Tambah stock barang\n");
        while(1){
            int perintah;
            scanf("%d",&perintah);
            if(perintah==1){
                //system("clear");
                for(int i=1;i<=8;i++){
                    if(barang[i]==0) continue;
                    else{
                        if(i==1) printf("MP4A1 = %d\n",barang[i]);
                        else if(i==2) printf("PM2-V1 = %d\n",barang[i]);
                        else if(i==3) printf("SPR-3 = %d\n",barang[i]);
                        else if(i==4) printf("SS2-V5 = %d\n",barang[i]);
                        else if(i==5) printf("SPG1-V3 = %d\n",barang[i]);
                        else if(i==6) printf("MINE = %d\n",barang[i]);
                    }
                }
            }
            else{
                //system("clear");
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
                scanf("%s %d",&updatebarang,&jumlahbarang);
                if(updatebarang=='MP4A1') barang[1]+=jumlahbarang;
                else if(updatebarang=='PM2-V1') barang[2]+=jumlahbarang;
                else if(updatebarang=='SPR-3') barang[3]+=jumlahbarang;
                else if(updatebarang=='SS2-V5') barang[4]+=jumlahbarang;
                else if(updatebarang=='SPG1-V3') barang[5]+=jumlahbarang;
                else if(updatebarang=='MINE') barang[6]+=jumlahbarang;
            }
        }
    }
}
