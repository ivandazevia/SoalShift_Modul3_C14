#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_t tid1;
pthread_t tid2;
pthread_t tid3;
pthread_t tid4;
int lohan = 100, kepiting = 100;

void* kepiting_lapar (void *arg){
    while(kepiting>0){
        sleep(20);
        kepiting-=10; 
        //printf("kepiting : %d\n",kepiting);
        if(kepiting<=0){
            printf("Kepiting mati :(\n");
            break;
        }
    }
}
void* lohan_lapar (void *arg){
    while(lohan>0){
        sleep(10);
        lohan-=15;
        //printf("lohan : %d\n",lohan);
        if(lohan<=0){
            printf("Lohan mati :(\n");
            break;       
        }
    }
}

void* kepiting_makan (void *arg){
    kepiting+=10;
    if(kepiting>100){
        //printf("kepiting : %d\n",kepiting);
        printf("Kepiting mati kegendutan :(\n");
        exit(0);
    }
}

void* lohan_makan (void *arg){
    lohan+=10;
    if(lohan>100){
        //printf("lohan : %d\n",lohan);
        printf("Lohan mati kegendutan :(\n"); 
        exit(0);
    }
}

int main(){
    int input;
    pthread_create(&(tid1),NULL,&kepiting_lapar,NULL);
    pthread_create(&(tid2),NULL,&lohan_lapar,NULL);
    printf("Apa yang ingin anda lakukan?\n");
    printf("1. Beri Makan Kepiting\n");
    printf("2. Beri Makan Lohan\n");
    while(1){
        printf("Masukkan pilihan anda (1/2): ");
        scanf("%d",&input);
        if(input == 1){
            pthread_create(&(tid3),NULL,&kepiting_makan,NULL); 
            //printf("kepiting : %d\n",kepiting);
        }
        else if(input == 2){ 
            pthread_create(&(tid4),NULL,&lohan_makan,NULL); 
            //printf("lohan : %d\n",lohan);
        }
        printf("Kepiting = %d\nLohan = %d\n",kepiting, lohan);
    }
}
