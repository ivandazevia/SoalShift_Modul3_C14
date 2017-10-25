#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

char pemain1[15];
char pemain2[15];
int status;
int score1 = 0, score2 = 0;
int jmllubang=0;
int ranjau[3][17];
pthread_t tid1,tid2;

void* pemain1milih(void *arg){
    status = 0;
    int lubang;
    
    printf("Giliran %s untuk bermain\n",pemain1);
    printf("Silahkan masukkan 1-4 ranjau pada lubang 1-16\n");
    for(int i=1;i<=4;i++){
        scanf("%d",&lubang);    
        if(ranjau[1][i]==1) printf("lubang sudah terisi\n");
        else {
            ranjau[1][i] = 1;
            jmllubang++;
        }
    }
    
    printf("Sekarang giliran %s untuk menebak\n",pemain2);
    printf("Silahkan %s untuk menebak 4 lubang yang aman\n",pemain2);
    for(int i=1;i<=4;i++){
        scanf("%d",&lubang);
        if(ranjau[1][i]==1){score1++; printf("score1: %d\n",score1);}
        else{score2++; printf("score2: %d\n",score2);}
    }
    status = 1;
}

void* pemain2milih(void *arg){
    while(status!=1){};
    int lubang,jml;
    printf("Giliran %s untuk bermain\n",pemain2);
    printf("Silahkan masukkan 1-4 ranjau pada lubang 1-16\n");
    for(int i=1;i<=4;i++){
        scanf("%d",&lubang);    
        if(ranjau[2][i]==1) printf("lubang sudah terisi\n");
        else {
            ranjau[2][i] = 1;
            jmllubang++;        
        }
    }

    printf("Sekarang giliran %s untuk menebak\n",pemain1);
    printf("Silahkan %s untuk menebak 4 lubang yang aman\n",pemain1);
    for(int i=1;i<=4;i++){
        scanf("%d",&lubang);
        if(ranjau[2][i]==1) {score2++; printf("score2: %d\n",score2);}
        else {score1++;printf("score1: %d\n",score1);}
    }
}

int main(){
    printf("Masukkan nama : ");
	scanf("%s",pemain1);
    getchar();
    printf("%s anda adalah pemain 1\n\n",pemain1);

	printf("Masukkan nama : ");
	scanf("%s",pemain2);
    getchar();
    printf("%s anda adalah pemain 2\n\n",pemain2);
    for(int i=1;i<=16;i++){
            ranjau[1][i]=0;
            ranjau[2][i]=0;        
    }  
    while(1){

        pthread_create(&(tid1),NULL,&pemain1milih,NULL); 
        pthread_create(&(tid2),NULL,&pemain2milih,NULL);
        
        pthread_join(tid1, NULL);
        pthread_join(tid2, NULL); 


        if(score1==10 || score2 == 10){
            printf("Game berakhir karena salah satu pemain sudah mendapatkan 10 poin\n");
            exit(0);
        }
        else if(score1<10 && jmllubang == 16 || score2<10 && jmllubang == 16){
            printf("Game berakhir, karena lubang terisi penuh dan belum ada pemain yang mendapatkan skor 10\n");
            exit(0);
        }
    }
}
