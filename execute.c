#include "commands.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int execute(char str[], char args[]) {
	if(strcmp(str, "exit") == 0) {
		printf("Thanks for using me.");
		exit(0);
	}
	if(strcmp(str, "youtube") == 0) {
		youtube(args);
		return 1;
	}
	if(strcmp(str, "help") == 0) {
		showHelp();
		return 1;
	}
	if(strcmp(str, "time") == 0) {
		showTime();
		return 1;
	}
	if(strcmp(str, "meow") == 0) {
		return 2;
	}
	return 0;
}