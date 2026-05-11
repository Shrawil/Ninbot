#include "commands.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int execute(char str[], char args[]) {
	if(strcmp(str, "hello") == 0 || strcmp(str, "hi") == 0 || strcmp(str, "hellow") == 0 || strcmp(str, "helo") == 0 || strcmp(str, "howdy") == 0) {
		return 2;
	}
	if(strcmp(str, "how") == 0 && strcmp(args, "are you") == 0 || strcmp(str, "how") == 0 && strcmp(args, "r you") == 0 || strcmp(str, "how") == 0 && strcmp(args, "are u") == 0 || strcmp(str, "how") == 0 && strcmp(args, "r u") == 0) {
		return 3;
	}
	if(strcmp(str, "exit") == 0) {
		printf("Thanks for using me.\n");
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
		return 3;
	}
	if(strcmp(str, "todo") == 0) {
		manageTodo(args);
		return 1;
	}
	if(strcmp(str, "open") == 0) {
		return openApp(args);
	}
	return 0;
}