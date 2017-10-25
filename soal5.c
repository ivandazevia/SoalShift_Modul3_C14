#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_t tid1;
pthread_t tid2;

void* fina(void *arg){
    FILE *fileinput;
    fileinput = fopen("/home/zevi/SoalShift_Modul3_C14/Novel.txt","r");
    char tmp[6000];
    int jumlahfina=0;
    fgets(tmp, sizeof(tmp),fileinput);
    if(strstr(tmp,"Fina")){
        jumlahfina++;
    }
    fclose(fileinput);
    printf("Fina = %d\n",jumlahfina);
}

void* ifah(void *arg){
    FILE *fileinput;
    fileinput = fopen("/home/zevi/SoalShift_Modul3_C14/Novel.txt","r");
    char tmp[6000];
    int jumlahifah=0;
    fgets(tmp, sizeof(tmp),fileinput);
    if(strstr(tmp,"Ifah")){
        jumlahifah++;
    }
    fclose(fileinput);
    printf("Ifah = %d\n",jumlahifah);
}

int main(){
    pthread_create(&(tid1),NULL,&fina,NULL);
    pthread_create(&(tid2),NULL,&ifah,NULL);
    
    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);
}

