#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
main(){
	char *word1,*word2,*word3,*word4,*word5;
	word1="Hello";
	word2="world";
	word3="how";
	word4="are";
	word5="you.";
	execl("HW1testfile",word1,word2,word3,word4,word5,NULL);
	printf("Err");
}