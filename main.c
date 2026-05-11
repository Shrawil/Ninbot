#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "nbsupport.h"
#include "execute.h"

int main() {
	srand(time(NULL));
	char str[100], args[100];
	int greet = rand() % 5, i, j;

	init();

	char name[20];
	strcpy(name, getName());

	printf("\033[H\033[J");

	switch (greet) {
		case 0: printf("Hello %s, Ninbot here.\n", name); break;
		case 1: printf("Welcome %s, Ninbot at your service.\n", name); break;
		case 2: printf("Wish you a very good day %s.\n", name); break;
		case 3: printf("Ninbot at your service, %s.\n", name); break;
	}

	while(1) {

		// Taking input 
		printf("What can I do for you : ");
		fgets(str, 100, stdin);

		str[strcspn(str, "\n")] = '\0';

		// Parsing commands
		separate(str, args);

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