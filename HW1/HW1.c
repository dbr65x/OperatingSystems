#include <stdio.h>
#include <stdlib.h>
int main(){
	int childID,parentID;
	printf("The parent process is suspended after the wait system call is made. Then it resumes after the child process runs completely\n");
	fork();
	childID=getpid();
	parentID=getppid();
	printf("Fork makes two processes, which is why this statement prints twice.\n");
	wait(NULL);
	printf("ChildID:%d\tParentID:%d\n", childID, parentID);

	exit(-1);
	//This line of code never runs because exit terminates the program before then.
	printf("Exit terminates fork before it duplicates the process.\n");
	return  0;
}