#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include "nbsupport.h"

void cleanInput(char str[]) {

    int i, j = 0;
    char cleaned[256];

    for(i = 0; str[i] != '\0'; i++) {

        char ch = tolower(str[i]);

        if((ch >= 'a' && ch <= 'z') || ch == ' ') {
            cleaned[j++] = ch;
        }
    }

    cleaned[j] = '\0';

    strcpy(str, cleaned);
}

void setupAutostart() {

    char *home = getenv("HOME");

    if(home == NULL) {
        printf("Failed to get HOME directory.\n");
        return;
    }

    char desktopPath[512];

    snprintf(desktopPath,
             sizeof(desktopPath),
             "%s/.config/autostart/Ninbot.desktop",
             home);

    // Check if already exists
    FILE *check = fopen(desktopPath, "r");

    if(check != NULL) {
        fclose(check);
        return;
    }

    // Get executable path
    char exePath[512];

    ssize_t len = readlink("/proc/self/exe",
                           exePath,
                           sizeof(exePath) - 1);

    if(len == -1) {
        printf("Failed to detect executable path.\n");
        return;
    }

    exePath[len] = '\0';

    // Create desktop file
    FILE *fp = fopen(desktopPath, "w");

    if(fp == NULL) {
        printf("Failed to create autostart file.\n");
        return;
    }

    fprintf(fp,
        "[Desktop Entry]\n"
        "Type=Application\n"
        "Name=Ninbot\n"
        "Exec=%s\n"
        "Terminal=true\n",
        exePath
    );

    fclose(fp);

    printf("Autostart enabled. [Press Enter]\n");
}

char *getName() {
	FILE *fp = fopen("data.txt", "r");
	static char name[20];
	if(fp == NULL) return NULL;
	if(fgets(name, sizeof(name), fp) == NULL) return NULL;
	fclose(fp);
	name[strcspn(name, "\n")] = '\0';
	return name;
}

void init() {
	FILE *fp = fopen("data.txt", "r");
	if(fp == NULL || getName() == NULL) {
		// No record found.
		setUpUser();
		return;
	}
	fclose(fp);
}

void setUpUser() {
	char name[20];
	int age;

	printf("Welcome to Ninbot, this is a one time setup!\n");
	printf("Enter your name : ");
	fgets(name, sizeof(name), stdin);
	name[strcspn(name, "\n")] = '\0';

	printf("Enter you age : ");
	scanf("%d", &age);

	FILE *fp = fopen("data.txt", "w");
	fprintf(fp, "%s\n", name);
	fprintf(fp, "%d\n", age);
	fclose(fp);
	char choice;
	printf("Do you want to enable autostart [y/n] : ");
	scanf(" %c", &choice);
	if(choice == 'y' || choice == 'Y') setupAutostart();
	else return;
	printf("All set up! [Press Enter]\n");
	getchar();
}

void separate(char str[], char args[]) {
	int i, j;
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
} 