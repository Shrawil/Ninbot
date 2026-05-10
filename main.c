#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "commands.h"
#include "execute.h"

int main() {
	srand(time(NULL));
	char str[100], args[100];
	int greet = rand() % 5, i, j;

	printf("\033[H\033[J");

	switch (greet) {
		case 0: printf("Hello sir, Ninbot here.\n"); break;
		case 1: printf("Welcome sir, Ninbot at your service.\n"); break;
		case 2: printf("Wish you a very good day sir.\n"); break;
		case 3: printf("Ninbot at your service, sir.\n"); break;
	}

	while(1) {

		// Taking input 
		printf("What can I do for you : ");
		fgets(str, 100, stdin);

		str[strcspn(str, "\n")] = '\0';

		// Parsing commands
		for(i = 0; str[i] != '\0'; i++) {
			if(str[i] == ' ') {
				str[i] = '\0';
				break;
			}
		}
		i++;
		for(j = 0; str[i] != '\0'; i++) {
			args[j++] = str[i];
		}
		args[j] = '\0';

		// Executing
		int ran = execute(str, args);

		if(ran == 0) printf("Something went wrong. [Press Enter]\n");
		else if(ran == 1) printf("Command executed! [Press Enter]\n");
		else if(ran == 2) printf("Ninbot meowed back! [Press Enter]\n");
		getchar();

		//printf("\033[H\033[J");
	}

	return 0;
}