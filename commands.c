#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "commands.h"

void youtube(char args[]) {
	if(args[0] == '\0') {
		system("xdg-open https://youtube.com");
		return;
	}
	for(int i = 0; args[i] != '\0'; i++) {
		if(args[i] == ' ') {
			args[i] = '+';
		}
	}
	char cmd[200];
	snprintf(cmd, sizeof(cmd),"xdg-open \"https://youtube.com/results?search_query=%s\" > /dev/null 2>&1",args);

	system(cmd);
}

void showTime() {
	time_t currentTime;
	time(&currentTime);
	printf("Current time : %s", ctime(&currentTime));	
}

void showHelp() {
	printf("\n");
	printf("\nAvailable Commands : ");
	printf("\nyoutube <link/term> - Opens youtube in your default browser. (Providing a search link or term is optional)");
	printf("\nopen filename - Search for the directory with \'filename\'.");
	printf("\ntime - Show's current time & date.");
	printf("\n");
}