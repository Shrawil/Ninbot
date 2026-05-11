#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "commands.h"
#include "execute.h"

void manageTodo(char args[]) {

    char action[100];
    char data[200];
    char line[256];

    separate(args, action);

    // ADD TODO
    if(strcmp(args, "add") == 0) {

        FILE *fa = fopen("todo.txt", "a");

        if(fa == NULL) {
            printf("Failed to open todo file.\n");
            return;
        }

        fprintf(fa, "%s\n", action);

        fclose(fa);

        printf("Todo added.\n");
    }

    // SHOW TODOS
    else if(strcmp(args, "show") == 0) {

        FILE *fr = fopen("todo.txt", "r");

        if(fr == NULL) {
            printf("No todo file found.\n");
            return;
        }

        int count = 1;

        while(fgets(line, sizeof(line), fr) != NULL) {
            printf("%d. %s", count++, line);
        }

        fclose(fr);
    }

    // REMOVE TODO
    else if(strcmp(args, "remove") == 0) {

        FILE *fr = fopen("todo.txt", "r");
        FILE *fw = fopen("temp.txt", "w");

        if(fr == NULL || fw == NULL) {
            printf("File error.\n");
            return;
        }

        int removeLine = atoi(action);
        int currentLine = 1;

        while(fgets(line, sizeof(line), fr) != NULL) {

            if(currentLine != removeLine) {
                fputs(line, fw);
            }

            currentLine++;
        }

        fclose(fr);
        fclose(fw);

        remove("todo.txt");
        rename("temp.txt", "todo.txt");

        printf("Todo removed.\n");
    }

    else {
        printf("Unknown todo command.\n");
    }
}

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