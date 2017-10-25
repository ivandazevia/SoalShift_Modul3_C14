#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_t tid1;
pthread_t tid2;
pthread_t tid3;
pthread_t tid4;
int status;
int lohan = 100, kepiting = 100;

void* kepiting_lapar (void *arg){
    while(1){
        sleep(20);
        kepiting-=10; 
        if(kepiting<=0) printf("Kepiting mati :(\n");
    }
}

int main(){
    
}
