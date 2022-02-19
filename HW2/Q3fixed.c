#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/stat.h>
#include <unistd.h>

sem_t *mutex1,*mutex2;
FILE *file;
int N,P2,P3;

int main(){
	mutex1 = sem_open("mutex1", O_CREAT, S_IRUSR | S_IWUSR, 0);
	P2=fork();
	if(P2==0){
        sem_wait(mutex1);//Prevents P2 from running first
    	for(int i=0;i<200;i++){
			file = fopen("F.txt","r");//open file for reading
			fscanf(file,"%d",&N);//check number in file
			printf("N=%d Child 1 Id=%d\n",N,getpid());//print N and the current PID
			fclose(file);
			N++;
			file = fopen("F.txt","w");//open file for writing
			fprintf(file,"%d",N);//write new incremented N to file
            fclose(file);
    	}return 0;
        sem_wait(mutex2);//Prevents code from running until the end again
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
        wait();//allows P3 to run before else statement
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
        sem_post(mutex1);//allows P2 to run
	}
	return 0;
}
