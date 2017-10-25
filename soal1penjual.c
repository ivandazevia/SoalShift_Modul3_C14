#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

int main(){
    key_t key = 1234;
    int *barang;

    int shmid = shmget(key, sizeof(int), IPC_CREAT | 0666);
    barang = shmat(shmid, NULL, 0);
    
    printf("==MODE PENJUAL==\n\n");
    printf("Pilih Perintah : \n");
    printf("1. Lihat stock barang\n");
    printf("2. Tambah stock barang\n");
    int perintah;
    while(1){
        printf("Masukkan perintah : ");
        scanf("%d",&perintah);
        if(perintah==1){
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
    }
    shmdt(barang);
    shmctl(shmid, IPC_RMID, NULL);
}
