#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

FILE *file;
int N,P2,P3;

int main(){
	P2=fork();
	if(P2==0){
    	for(int i=0;i<200;i++){
			file = fopen("F.txt","r");
			fscanf(file,"%d",&N);
			printf("N=%d Child 1 Id=%d\n",N,getpid());
			fclose(file);
			N++;
			file = fopen("F.txt","w");
			fprintf(file,"%d",N);
            fclose(file);
    	}
    }
	P3=fork();
	if(P3==0){
    	for(int i=0;i<200;i++){
			file = fopen("F.txt","r");
			fscanf(file,"%d",&N);
			printf("N=%d Child 2 Id=%d\n",N,getpid());
			fclose(file);
			N++;
			file = fopen("F.txt","w");
			fprintf(file,"%d",N);
            fclose(file);
    	}
	}
	else{
    	for(int i=0;i<200;i++){
			file = fopen("F.txt","r");
			fscanf(file,"%d",&N);
			printf("N=%d Parent Id=%d\n",N,getpid());
			fclose(file);
			N++;
			file = fopen("F.txt","w");
			fprintf(file,"%d",N);
            fclose(file);
    	}
	}
	return 0;
}
