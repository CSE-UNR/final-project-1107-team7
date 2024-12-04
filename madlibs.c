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

void parseMadlib(char[MAX_SLOTS][MAX_LENGTH+1], FILE*);
void readMadlib(char[MAX_SLOTS+1][STR_CAP+1], FILE*);
_Bool getUserWord(char[MAX_LENGTH+1], char[MAX_LENGTH+1]);
void displayFinished(char[MAX_SLOTS+1][STR_CAP+1], char[MAX_SLOTS][MAX_LENGTH+1]);
void printInline(char[]);

int main(){
	char inputs[MAX_SLOTS][MAX_LENGTH+1];
	char mad_lib[MAX_SLOTS+1][STR_CAP+1];
	FILE* fp = //put some file magic here :)
	parseMadlib(inputs, fp);
	fclose(fp);
	
	
	return 0;
}
void parseMadlib(char inputs[MAX_SLOTS][MAX_LENGTH+1], FILE* fin){
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
	}
}
_Bool getUserWord(char word_type[MAX_LENGTH+1], char temp_word[MAX_LENGTH+1]){
	if(word_type[0] == 'A' && word_type[2] == '\0'){ //Why is the null char at 2?
		printf("Please enter an adjective: ");
		fgets(temp_word, MAX_LENGTH+1, stdin);
		return 1;
	}
	else if(word_type[0] == 'N' && word_type[2] == '\0'){//Wtf
		printf("Please enter a noun: ");
		fgets(temp_word, MAX_LENGTH+1, stdin);
		return 1;
	}
	else if(word_type[0] == 'V' && word_type[2] == '\0'){//Pls help
		printf("Please enter a verb: ");
		fgets(temp_word, MAX_LENGTH+1, stdin);
		return 1;
	}
	return 0;
}
