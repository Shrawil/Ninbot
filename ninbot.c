#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#include "nbsupport.h"
#include "execute.h"

#define INPUT_SIZE 256
#define NAME_SIZE  50

int main() {

    srand(time(NULL));

    char str[INPUT_SIZE];
    char args[INPUT_SIZE];

    int greet = rand() % 4;

    // Initial setup
    init();

    // Fetch username
    char name[NAME_SIZE];

    strncpy(name, getName(), sizeof(name) - 1);
    name[sizeof(name) - 1] = '\0';

    // Clear terminal
    printf("\033[H\033[J");

    // Greeting
    switch(greet) {

        case 0:
            printf("Hello %s, Ninbot here.\n", name);
            break;

        case 1:
            printf("Welcome %s, Ninbot at your service.\n", name);
            break;

        case 2:
            printf("Wish you a very good day %s.\n", name);
            break;

        case 3:
            printf("Ninbot at your service, %s.\n", name);
            break;
    }

    // Main loop
    while(1) {

        // Reset buffers
        str[0] = '\0';
        args[0] = '\0';

        // Prompt
        printf("\nWhat can I do for you : ");

        // Input
        if(fgets(str, sizeof(str), stdin) == NULL) {
            printf("Input error.\n");
            continue;
        }

        // Remove newline
        str[strcspn(str, "\n")] = '\0';

        // Convert to lowercase
        for(int i = 0; str[i] != '\0'; i++) {
            str[i] = tolower(str[i]);
        }

        cleanInput(str);

        // Parse command + arguments
        separate(str, args);

        // Execute command
        int result = execute(str, args);

        // Result messages
        switch(result) {

            case 0:
                printf("\nUnknown command.\n");
                break;

            case 1:
                printf("\nCommand executed successfully.\n");
                break;

            case 2: 
                printf("\nHello %s!\n", name);
                break;
            case 3:
                printf("Thanks for asking! I'm doing great %s!\n", name);
                break;
            case 4:
                printf("\nNinbot meowed back.\n");
                break;

            case -1:
                printf("\nFatal error occurred.\n");
                break;
        }

        // Pause
        printf("[Press Enter]");
        getchar();

        // Clear screen
        printf("\033[H\033[J");
    }

    return 0;
}