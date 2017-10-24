#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_t tid1;
pthread_t tid2;
pthread_t tid3;
int status;
long long input1, input2, input3;

void* fact1(void *arg){
    status = 0;
    long long result=1;
    int i;
    for (i=1;i<=input1;i++) result*=i;
    
    status=1;
    printf("Hasil %lld! = %lld\n", input1, result);
    return NULL;
}

int main(){
    scanf("%lld %lld %lld",&input1,&input2,&input3);
    pthread_create(&(tid1),NULL,&fact1,NULL);
    pthread_join(tid1,NULL);
}
