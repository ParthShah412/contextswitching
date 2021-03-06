#include"load.h"
#include"replaceVar.h"
#include<time.h>
void pri(void *ins, unsigned long processID){

	char *instruction = (char *)ins;
	int i=0;
	while(instruction[i]!='\n') {
		i++;
	}
	instruction[i]='\0';
	int size=strlen(instruction);

	int j,var1 =0,var2 =0,var3;
	float var4=0.0;
	i=0;
	while(instruction[i]!=32) {
		i++;
	}
	FILE *fptr;
	time_t t;
	int insCode=load("instructions.txt",&instruction[0],i);

	switch(insCode) {

		case 1:
		i++;
		j=i;
		while(instruction[i]!=' ') {
			i++;
		}
		var1 = load("resource.txt",&instruction[j],i-j);
		i++;
		j=i;
		while(instruction[i]!=32) {
			i++;
		}
		var2 = load("resource.txt",&instruction[j],i-j);
		i++;
		j=i;
		while(instruction[i]!=32 && i<strlen(instruction)) {
			i++;
		}
		var3 = var1+var2;
		fptr=fopen("fcfs_log.txt","a+");
		if(fptr==NULL) {
			printf("Error");
			exit(1);
		}
		else {
			//time(&t);
			fprintf(fptr,"%s %lu i + j = %d\n",ctime(&t),processID,var3);
		}
		fclose(fptr);
		//here we need to write value of var3 inplace of "k" in resource.txt
		replaceVal(&instruction[j],var3);

		break;
		case 2:
		i++;
		j=i;
		while(instruction[i]!=' ') {
			i++;
		}
		var1 = load("resource.txt",&instruction[j],i-j);
		i++;
		j=i;
		while(instruction[i]!=32 ) {
			i++;
		}
		var2 = load("resource.txt",&instruction[j],i-j);
		i++;
		j=i;
		while(instruction[i]!=32 && i<strlen(instruction)) {
			i++;
		}
		var3 = var1-var2;
		fptr=fopen("fcfs_log.txt","a+");
		if(fptr==NULL) {
			printf("Error");
			exit(1);
		}
		else {
			fprintf(fptr,"%s %lu a - b = %d\n",ctime(&t),processID,var3);
		}
		fclose(fptr);
		replaceVal(&instruction[j],var3);

		break;
		case 3:
		i++;
		j=i;
		while(instruction[i]!=' ') {
			i++;
		}
		var1 = load("resource.txt",&instruction[j],i-j);
		i++;
		while(instruction[i]!=32 ) {
			i++;
			j=i;
		}
		var2 = load("resource.txt",&instruction[j],i-j);
		i++;
		j=i;
		while(instruction[i]!=32 && i<strlen(instruction)) {
			i++;
		}
		var3 = var1*var2;
		fptr=fopen("fcfs_log.txt","a+");
		if(fptr==NULL) {
			printf("Error");
			exit(1);
		}
		else {
			fprintf(fptr,"%s %lu c * d = %d\n",ctime(&t),processID,var3);
		}
		fclose(fptr);
		replaceVal(&instruction[j],var3);

		break;
		case 4:
		i++;
		j=i;
		while(instruction[i]!=' ') {
			i++;
		}
		var1 = load("resource.txt",&instruction[j],i-j);
		i++;
		j=i;
		while(instruction[i]!=32 ) {
			i++;
		}
		var2 = load("resource.txt",&instruction[j],i-j);
		i++;
		j=i;
		while(instruction[i]!=32 && i<strlen(instruction)) {
			i++;
		}
		var4 = (float)var1/var2;
		fptr=fopen("fcfs_log.txt","a+");
		if(fptr==NULL) {
			printf("Error");
			exit(1);
		}
		else {
			fprintf(fptr,"%s %lu x / y = %f\n",ctime(&t),processID,var4);
		}
		fclose(fptr);
		replaceVal(&instruction[j],var3);

		break;
	}
}
