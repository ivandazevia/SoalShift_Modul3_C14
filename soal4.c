#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_t tid1;
pthread_t tid2;
pthread_t tid3;
int status;
long long input[4];

void* fact1(void *arg){
    status = 0;
    long long result=1;
    int i;
    for (i=1;i<=input[1];i++) result*=i;
    
    status=1;
    printf("Hasil %lld! = %lld\n", input[1], result);
    return NULL;
}

void* fact2(void *arg){
    while(status!=1){}
    long long result=1;
    int i;
    for (i=1;i<=input[2];i++) result*=i;
    
    status=2;
    printf("Hasil %lld! = %lld\n", input[2], result);
    return NULL;
}

void* fact3(void *arg){
    while(status!=2){}
    long long result=1;
    int i;
    for (i=1;i<=input[3];i++) result*=i;
    
    printf("Hasil %lld! = %lld\n", input[3], result);
    return NULL;
}

int main(){
    
    scanf("%lld %lld %lld",&input[1],&input[2],&input[3]);
    int tmp=0,i=3,j;
    while(i--){
        for(j=1;j<=i;j++){
            if(input[j]>input[j+1]){
            tmp = input[j+1]; 
            input[j+1]=input[j]; 
            input[j]=tmp;
            }
        }
    }

    pthread_create(&(tid1),NULL,&fact1,NULL);
    pthread_create(&(tid2),NULL,&fact2,NULL);
    pthread_create(&(tid3),NULL,&fact3,NULL);

    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);
    pthread_join(tid3,NULL);
}
