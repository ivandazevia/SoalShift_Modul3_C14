#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_t tid1;
pthread_t tid2;
int status;
int nomor;

void* salin1(void *arg)
{ status=0;
    FILE *fo, *fw;
	char str[1024];
	fo = fopen("baca.txt", "r");
	fw = fopen("salin1.txt", "w");

	while (fgets(str, 1024, fo) != NULL)
	{

	 fprintf(fw, "%s\n", str);

	}
	fclose(fo);
	fclose(fw);
	status=1;
    return NULL;
}


void* salin2(void *arg)
{while(status != 1)
	{
	}
    FILE *fo, *fw;
	char str[1024];
	fo = fopen("salin1.txt", "r");
	fw = fopen("salin2.txt", "w");

	while (fgets(str, 1024, fo) != NULL)
	{

	 fprintf(fw, "%s\n", str);

	}
	fclose(fo);
	fclose(fw);
    return NULL;
}

int main(void)
{

    pthread_create(&(tid1), NULL, &salin1, NULL);
    pthread_create(&(tid2), NULL, &salin2, NULL);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    return 0;
}
