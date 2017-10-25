#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

char pemain1[15];
char pemain2[15];
int status;
int score1 = 0, score2 = 0;
int ranjau[3][17];
pthread_t tid1,tid2;

void* pemain1milih(void *arg){
    status = 0;
    int lubang,jml;
    printf("Giliran %s untuk bermain\n",pemain1);
    printf("Ada berapa banyak ranjau yang ingin anda letakkan?\n");
    scanf("%d",&jml);
    printf("Silahkan masukkan 1-%d ranjau pada lubang 1-16\n",jml);
    for(int i=1;i<=jml;i++){
        scanf("%d",&lubang);    
        if(ranjau[1][i]!=0) printf("lubang sudah terisi\n");
        else ranjau[1][i] = 1;
    }
    
    printf("Sekarang giliran %s untuk menebak\n",pemain2);
    printf("Silahkan %s untuk menebak 4 lubang yang aman\n");
    for(int i=1;i<=4;i++){
        scanf("%d",&lubang);
        if(ranjau[1][i]==1) score1++;
        else score2++;
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
}
