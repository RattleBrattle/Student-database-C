#include <stdio.h>
#include <stdlib.h>
#include "SDB.h"

int SDB_APP() {
    int userChoice = 0, correctChoice = 0;

    printf("\nPlease choose one of the following:\n");
    printf("1) Add an Entry\n2) Used size in the database\n3) Read All student data\n4) Get all student IDs\n5) Search Specific student ID\n6) Check if ID exists\n7) Delete student data\n8) Check if database is full\n9) Exit");
    printf("\nYour Input: ");

    while (correctChoice == 0) {
        scanf("%d", &userChoice);

        if (userChoice < 1 || userChoice > 9) {
            printf("\nInvalid Choice, please try again!\n");
            correctChoice = 0;
        } else {
            correctChoice = 1;
        }
    }
    return userChoice;
}
