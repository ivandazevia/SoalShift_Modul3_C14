#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

pthread_t tid1;
pthread_t tid2;
int status;
int jumlahfina=0;
int jumlahifah=0;

void* fina(void *arg){
    status = 0;
    pid_t child;
    child = fork();
    if(child == 0) printf("Fina : ");
    else{
        while((wait(&status)) > 0);  
        system("grep -o Fina Novel.txt | wc -l"); 
    } 
    status =1;
}

void* ifah(void *arg){
    while(status!=1){}
    pid_t child;
    child = fork();
    if(child == 0) printf("Ifah : ");
    else{
        while((wait(&status)) > 0);  
        system("grep -o Ifah Novel.txt | wc -l");  
    } 
}

int main(){
    pthread_create(&(tid1),NULL,&fina,NULL);
    pthread_create(&(tid2),NULL,&ifah,NULL);
    
    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);
}

