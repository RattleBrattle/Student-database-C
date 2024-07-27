#ifndef SDB_H_INCLUDED
#define SDB_H_INCLUDED

/* The main struct and its objects for the database */
typedef struct {
    int Student_ID;
    int Student_year;
    int Course1_ID;
    int Course1_grade;
    int Course2_ID;
    int Course2_grade;
    int Course3_ID;
    int Course3_grade;
} student;

/* These are the prototypes of the main functions used in this app */

// Function to initialize the 3 main starter students in the struct and the rest to 0 (empty)
void INIT_SDB(student students[], int size);

// Main function that shows the menu
int SDB_APP();

// This is the function that takes action depending on user choice
void SDB_action(int action, student students[], int size);

// Function to print/show all the students data
void printAllStudents(student students[], int size);

// Function to add a student to the struct list
void SDB_AddEntry(student students[], int size);

// Function to get the used size of the students in the database
int SDB_GetUsedSize(student students[], int size);

// Function to print the list of all registered students and the number of IDs present in the struct
void SDB_GetList(student students[], int size);

// Function to search for a specific student ID and then print all the student's data
void printSpecificStudent(student students[], int size);

// Function to check if the user entered ID exists or not
int SDB_IsIdExist (student students[], int size, int id);

// Function to delete student data present (convert all values to zero)
int SDB_delete (student students[], int size, int id);

// Function to check if the database is full or not
int SDB_IsFull(student students[], int size);

#endif
