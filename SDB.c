#include "SDB.h"

void INIT_SDB(student students[], int size) {
    // Initializing the first 3 students in the struct
    students[0].Student_ID = 2994821;
    students[0].Student_year = 29;
    students[0].Course1_ID = 265;
    students[0].Course1_grade = 88;
    students[0].Course2_ID = 473;
    students[0].Course2_grade = 93;
    students[0].Course3_ID = 589;
    students[0].Course3_grade = 79;

    students[1].Student_ID = 8593423;
    students[1].Student_year = 21;
    students[1].Course1_ID = 266;
    students[1].Course1_grade = 75;
    students[1].Course2_ID = 474;
    students[1].Course2_grade = 95;
    students[1].Course3_ID = 590;
    students[1].Course3_grade = 81;

    students[2].Student_ID = 7638125;
    students[2].Student_year = 30;
    students[2].Course1_ID = 267;
    students[2].Course1_grade = 85;
    students[2].Course2_ID = 475;
    students[2].Course2_grade = 90;
    students[2].Course3_ID = 591;
    students[2].Course3_grade = 78;

    // Loop to initialize the rest of the students to value of 0 (indicating the space is empty)
    for (int i = 3; i < size; i++) {
        students[i].Student_ID = 0;
        students[i].Student_year = 0;
        students[i].Course1_ID = 0;
        students[i].Course1_grade = 0;
        students[i].Course2_ID = 0;
        students[i].Course2_grade = 0;
        students[i].Course3_ID = 0;
        students[i].Course3_grade = 0;
    }
}

void SDB_action(int action, student students[], int size) {
    int usedSize = 0, ID_EXIST = 0, ID_ENTERED = 0, validInput = 0, isDatabaseFull = 0;
    char user_ID_Str[10];

    switch (action) {
    case 1:
        SDB_AddEntry(students, size);
        break;
    case 2:
        usedSize = SDB_GetUsedSize(students, size);
        printf("Total Used spaces are %d\n", usedSize);
        break;
    case 3:
        printAllStudents(students, size);
        break;
    case 4:
        SDB_GetList(students, size);
        break;
    case 5:
        printSpecificStudent(students, size);
        break;
    case 6:
    printf("\nPlease enter the ID to check if it exists or not: ");
    do {
        scanf("%s", user_ID_Str);
        if (strlen(user_ID_Str) == 7) {
            validInput = 1;
            ID_ENTERED = atoi(user_ID_Str); // In case of valid input, convert the string to integer to be passed to the function
        } else {
            printf("\nInvalid input. Please enter a 7-digit student ID: ");
        }
    } while (!validInput);
    ID_EXIST = SDB_IsIdExist(students, size, ID_ENTERED);
    if (ID_EXIST != 0)
        printf("\nThe student ID entered belongs to student number %d", ID_EXIST);
    else
        printf("\nThe student ID entered does not exist.");
    break;

    case 7:
        printf("\nPlease enter the ID of the student to delete his/her data: ");
        do {
        scanf("%s", user_ID_Str);
        if (strlen(user_ID_Str) == 7) {
            validInput = 1;
            ID_ENTERED = atoi(user_ID_Str); // In case of valid input, convert the string to integer to be passed to the function
        } else {
            printf("\nInvalid input. Please enter a 7-digit student ID: ");
        }
    } while (!validInput);
        ID_EXIST = SDB_delete (students, size, ID_ENTERED);
        if (ID_EXIST)
            printf("\nThe student %d was deleted from the database successfully", ID_EXIST);
        else
            printf("\nThe student ID does not exist.");
        break;
    case 8:
        isDatabaseFull = SDB_IsFull(students, size);
        if (isDatabaseFull)
            printf("\nThe database is full\n");
        else
            printf("\nThe database is not full\n");
        break;
    case 9:
        printf("\nExiting Application...\n");
        break;
    default:
        printf("\nInvalid option or an error occurred, please restart.\n");
        break;
    }
}

void printAllStudents(student students[], int size) {
    // Simple loop to print out all the students in the database
    for (int i = 0; i < size; i++) {
        if (students[i].Student_ID != 0) {
            printf("\nStudent %d:\n", i + 1);
            printf("Student ID: %d\n", students[i].Student_ID);
            printf("Student year: %d\n", students[i].Student_year);
            printf("Course 1 ID: %d\n", students[i].Course1_ID);
            printf("Course 1 grade: %d\n", students[i].Course1_grade);
            printf("Course 2 ID: %d\n", students[i].Course2_ID);
            printf("Course 2 grade: %d\n", students[i].Course2_grade);
            printf("Course 3 ID: %d\n", students[i].Course3_ID);
            printf("Course 3 grade: %d\n", students[i].Course3_grade);
        }
    }
}

void printSpecificStudent(student students[], int size) {
    char userSearchStr[10];
    int userSearch = 0, i = 0, validInput = 0, isFound = 0;

    printf("\nEnter the student ID of 7 digits to search for: ");

    // Loop to detect if the user entered the correct size for the student ID (7 Numbers)
    do {
        scanf("%s", userSearchStr);
        if (strlen(userSearchStr) == 7) {
            validInput = 1;
            userSearch = atoi(userSearchStr); // In case of valid input, convert the string to integer
        } else {
            printf("Invalid input. Please enter a 7-digit student ID: ");
        }
    } while (!validInput);

    // Loop to search for the specific student ID and print the student's data
    for (i = 0; i < size; i++) {
        if (students[i].Student_ID == userSearch) {
            isFound = 1;
            printf("\nStudent %d:\n", i + 1);
            printf("Student ID: %d\n", students[i].Student_ID);
            printf("Student year: %d\n", students[i].Student_year);
            printf("Course 1 ID: %d\n", students[i].Course1_ID);
            printf("Course 1 grade: %d\n", students[i].Course1_grade);
            printf("Course 2 ID: %d\n", students[i].Course2_ID);
            printf("Course 2 grade: %d\n", students[i].Course2_grade);
            printf("Course 3 ID: %d\n", students[i].Course3_ID);
            printf("Course 3 grade: %d\n", students[i].Course3_grade);
        }
    }
    if (isFound) {
        printf("student was Found.\n");
    }
    else {
        printf("Student with ID %d not found.\n", userSearch);
    }
}

void SDB_AddEntry(student students[], int size) {
    int isFull = 1, spaceEmptyCounter = 0;

    for (int i = 0; i < size; i++) {
        if (students[i].Student_ID == 0) {
            printf("There is space empty in %d of the database.\n", i);
            spaceEmptyCounter++;
            isFull = 0;
        }
    }
    printf("Total Empty spaces are %d\n", spaceEmptyCounter);

    if (isFull) {
        printf("\nThe database is full. Cannot add more students.\n");
    } else {
        int index = 0;
        printf("\nChoose one of the vacant places shown above: ");
        scanf("%d", &index);

        if (index < 0 || index >= size || students[index].Student_ID != 0) {
            printf("\nInvalid index chosen.\n");
        } else {
            printf("\nEnter student ID of 7 numbers: ");
            scanf("%d", &students[index].Student_ID);
            printf("Enter student year: ");
            scanf("%d", &students[index].Student_year);
            printf("Enter Course 1 ID: ");
            scanf("%d", &students[index].Course1_ID);
            printf("Enter Course 1 grade: ");
            scanf("%d", &students[index].Course1_grade);
            printf("Enter Course 2 ID: ");
            scanf("%d", &students[index].Course2_ID);
            printf("Enter Course 2 grade: ");
            scanf("%d", &students[index].Course2_grade);
            printf("Enter Course 3 ID: ");
            scanf("%d", &students[index].Course3_ID);
            printf("Enter Course 3 grade: ");
            scanf("%d", &students[index].Course3_grade);
        }
    }
}

int SDB_GetUsedSize(student students[], int size) {
    int spaceFullCounter = 0;
    for (int i = 0; i < size; i++) {
        if (students[i].Student_ID != 0) {
            spaceFullCounter++;
        }
    }
    return spaceFullCounter;
}

void SDB_GetList(student students[], int size) {
    int student_ID_Count = 0;
    for (int i = 0; i < size; i++) {
        if (students[i].Student_ID != 0) {
            printf("Student %d, ID is: %d\n", (i + 1), students[i].Student_ID);
            student_ID_Count++;
        }
    }
    printf("\nThe number of IDs present is %d\n", student_ID_Count);
}

int SDB_IsIdExist(student students[], int size, int id) {
    int i = 0;

    // Loop to check if the Entered ID exists or not
    for (i = 0; i < size; i++) {
        if (students[i].Student_ID == id) {
            return i + 1;  // Return the index (1-based)
        }
    }
    return 0;  // Return 0 if ID does not exist
}

int SDB_delete (student students[], int size, int id) {
    int i = 0, exists = 0;

    // Loop to check if the Entered ID exists or not
    for (i = 0; i < size; i++) {
        if (students[i].Student_ID == id) {
            exists = i;
        }
    }

    if (exists == 0)
        return 0;

    // Deleting chosen student data from the database
    students[exists].Student_ID = 0;
    students[exists].Student_year = 0;
    students[exists].Course1_ID = 0;
    students[exists].Course1_grade = 0;
    students[exists].Course2_ID = 0;
    students[exists].Course2_grade = 0;
    students[exists].Course3_ID = 0;
    students[exists].Course3_grade = 0;

    return exists;
}

int SDB_IsFull(student students[], int size) {
    int isFull = 1, spaceEmptyCounter = 0;

    for (int i = 0; i < size; i++) {
        if (students[i].Student_ID == 0) {
            printf("There is space empty in %d of the database.\n", i);
            spaceEmptyCounter++;
            isFull = 0;
        }
    }
    printf("Total Empty spaces are %d\n", spaceEmptyCounter);

    return isFull;
}
