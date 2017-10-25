#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_t tid1;
pthread_t tid2;
int status;
int jumlahfina=0;
int jumlahifah=0;

void* fina(void *arg){
    status = 0;
    FILE *fileinput;
    fileinput = fopen("/home/zevi/SoalShift_Modul3_C14/Novel.txt","r");
    char tmp[400];
    
    while(fileinput!=NULL && fgets(tmp, sizeof(tmp), fileinput)!=NULL){
        //fgets(tmp, sizeof(tmp),fileinput);
        if(strstr(tmp,"Fina")){
            //printf("Fina\n");
            jumlahfina++;
        }
    }
    fclose(fileinput);
    printf("Fina = %d\n",jumlahfina);
    status =1;
}

void* ifah(void *arg){
    while(status!=1){}
    FILE *fileinput;
    fileinput = fopen("/home/zevi/SoalShift_Modul3_C14/Novel.txt","r");
    char tmp[400];
    
    while(fileinput!=NULL && fgets(tmp, sizeof(tmp), fileinput)!=NULL){
        if(strstr(tmp,"Ifah")){
            //printf("Ifah\n");
            jumlahifah++;
        }
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

