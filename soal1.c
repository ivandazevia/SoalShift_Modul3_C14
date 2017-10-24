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
            }
        }
    }
}
