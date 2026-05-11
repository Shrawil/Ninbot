#include <stdio.h>
#include <string.h>
#include "nbsupport.h"

char *getName() {
	FILE *fp = fopen("data.txt", "r");
	char *name;
	fgets(name, sizeof(name), fp);
	return name;
}

void init() {
	FILE *fp = fopen("data.txt", "r");
	if(fp == NULL) {
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