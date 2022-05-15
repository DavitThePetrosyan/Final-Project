#include <stdio.h>
#include <stdlib.h>

int checking(char* word){
	
	return(((64 < word[0] && word[0] < 91) || (96 < word[0] && word[0] < 123) || (47 < word[0] && word[0] < 58)) ? 1 : 0);
	
}

int word_size (char* word){
	
	int size = 0;
	do{
		size++;

	}while (word[size] != 0);
		
	return size;
}


char** convert_to_morse (char* word, int size, char** morse){
	
	char** new_word = malloc(size * sizeof(char) * 7);

	for (int i = 0; i < size; i++){
	
		if (64 < word[i] && word[i] < 91){
			
			new_word[i] = morse [word[i] - 65];  
	

		}else if (96 < word[i] && word[i] < 123){

			new_word[i] = morse [word[i] - 97];

		}else{
			
			new_word[i] = morse [word[i] - 22];
		}	
	}
	
	return new_word;
}


int main(){

	char* morse[] =  {".- ", "-... ", "-.-. ", "-.. ", ". ", "..-. ", "--. ", ".... ", ".. ", ".--- ", "-.- ", ".-.. ", 
	               "-- ", "-. ", "--- ", ".--. ", "--.- ", ".-. ", "... ", "- ", "..- ", "...- ", ".-- ", "-..- ", "-.-- ", "--.. ", 
		       "----- ", ".---- ", "..--- ", "...-- ", "....- ", "..... ", "-.... ", "--... ", "---.. ", "----. "};  
	

	char word[100];  
	scanf ("%s", &*word);
	
	int s = word_size(word);

	char** h;
		
	printf ("%d", s);

	if (checking(word) == 1){
		h = convert_to_morse(word, s, morse); 
	
		for (int j = 0; j < s; j++){

			printf("%s\n", h[j]);
		
		}
	
		}else if (checking(word) == 0){
		
			printf("Please, enter a valid word or number\n");
		
		}
}	
