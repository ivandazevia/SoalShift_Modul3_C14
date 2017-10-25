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
        sleep(10);
        kepiting-=10; 
        printf("kepiting : %d\n",kepiting);
        if(kepiting<=0){
            printf("Kepiting mati :(\n");
            break;
        }
    }
}
void* lohan_lapar (void *arg){
    while(lohan>0){
        sleep(5);
        lohan-=15;
        printf("lohan : %d\n",lohan);
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
    
}
