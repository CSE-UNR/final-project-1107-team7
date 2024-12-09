/**************************/
/*Final Project - Mad Libs*/
/*By:                     */
/*Alex Contreras          */
/*Trinity Hayes           */
/*Kevin Pettibone         */
/*12/2/2024               */
/**************************/

#include <stdio.h>
#define INFILE "madlib2.txt"
#define MAX_SLOTS 20 //The amount of inputs that can be stored
#define MAX_LENGTH 50 //Max length of words
#define STR_CAP 200 //Cap of madlib line length

_Bool parseMadlib(char[MAX_SLOTS][MAX_LENGTH+1], FILE*);
void readMadlib(char madlib[MAX_SLOTS+2][STR_CAP+1], FILE* fp);
_Bool getUserWord(char[MAX_LENGTH+1], char[MAX_LENGTH+1]);
void displayFinished(char[MAX_SLOTS+2][STR_CAP+1], char[MAX_SLOTS][MAX_LENGTH+1]);
void printInline(char[]);
void stringCopy(char[], char[]);

int main(int argc, char* argv[]){
	char infile[STR_CAP+1];
	if(argc > 1){
		stringCopy(argv[1], infile);
	}
	else{
		stringCopy(INFILE, infile);
	}
	char inputs[MAX_SLOTS][MAX_LENGTH+1];
	char mad_lib[MAX_SLOTS+2][STR_CAP+1]; // Enough to have n+1 slots and a null placeholder row
	for(int i=0;i<MAX_SLOTS+2;i++){
		for(int j=0;j<STR_CAP+1;j++){
			mad_lib[i][j] = '\0'; //Set everything to null - remove junk
		}
	}
	
	FILE* fp = fopen(infile,"r"); 
		if (fp == NULL){
		printf("FILE NOT OPENED\n");
	}
	if(!parseMadlib(inputs, fp)){
		return 0; //Parse error - truncate early
	}
	fclose(fp);
	FILE* fp2 = fopen(infile,"r"); //reopen file stream
		if (fp == NULL){
		printf("FILE NOT OPENED\n");
	}   
	readMadlib(mad_lib, fp);
	
	displayFinished(mad_lib, inputs);
	printf("\n");
	
	fclose(fp2);
	
	
	return 0;
}
_Bool parseMadlib(char inputs[MAX_SLOTS][MAX_LENGTH+1], FILE* fin){
	char word_type[MAX_LENGTH+1];
	char temp_word[MAX_LENGTH+1];
	int counter = 0; //Current index being modified
	for(int i = 0;i < MAX_SLOTS * 2;i++){
		fgets(word_type, MAX_LENGTH, fin);
		if(getUserWord(word_type, temp_word)){
			char temp_char = 'a';
			for(int i = 0; i < MAX_LENGTH + 1 && temp_char != '\0'; i++){ //Stop after null char
				inputs[counter][i] = temp_word[i];
				temp_char = temp_word[i];
			}
			counter++;
		}
		else{
			return 0;
		}
	}
	return 1;
}
_Bool getUserWord(char word_type[MAX_LENGTH+1], char temp_word[MAX_LENGTH+1]){
	if(word_type[0] == 'A' && word_type[2] == '\0'){ 
		printf("Please enter an adjective: ");
		fgets(temp_word, MAX_LENGTH+1, stdin);
		return 1;
	}
	else if(word_type[0] == 'N' && word_type[2] == '\0'){
		printf("Please enter a noun: ");
		fgets(temp_word, MAX_LENGTH+1, stdin);
		return 1;
	}
	else if(word_type[0] == 'V' && word_type[2] == '\0'){
		printf("Please enter a verb: ");
		fgets(temp_word, MAX_LENGTH+1, stdin);
		return 1;
	}
	else{
		printf("Error reading madlib file\n");
		return 0;
	}
	return 0;
}
void readMadlib(char madlib[MAX_SLOTS+2][STR_CAP+1], FILE* fp ){
	char junk[STR_CAP+1]; //For getting rid of the word placholders
	for(int row=0;row<MAX_SLOTS+1;row++){
		fgets(madlib[row],STR_CAP,fp);
		fgets(junk, STR_CAP, fp);
	}
}

void displayFinished(char madlibs[MAX_SLOTS+2][STR_CAP+1], char inputs[MAX_SLOTS][MAX_LENGTH+1]){
	int i=0;
	while(madlibs[i][0] != '\0'){
		printInline(madlibs[i]);
		if(madlibs[i+1][0] != '\0'){
			printf(" ");
			printInline(inputs[i]);
		
		}
		if(madlibs[i+1][0] != '.' && madlibs[i+1][0] != ',' && madlibs[i+1][0] != '!'){
			printf(" "); 
		}
		i++;
	}		
}
	
void printInline(char string[]){
	for(int i=0; i<STR_CAP+1; i++){
		if(string[i] == '\0'){
			break;
		}
		
		if(string[i] != '\n'){
			printf("%c", string[i]);
		}
	}
}
void stringCopy(char source[], char dest[]){
	for(int i = 0; i < STR_CAP + 1; i++){
		dest[i] = source[i];
	}
}
