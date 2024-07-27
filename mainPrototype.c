/*  Student database
     Program made by
   Basel Mohamed Mostafa
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "STD.h"
#include "SDB.h"
#include "SDBAPP.c"
#include "SDB.c"

int main() {
    printf("-------------------------------------------------------------------------------------------\n----------------------------------Student Database Program----------------------------------\n--------------------------------------------------------------------------------------------\n");

    int structSize = 10, userAction = 0;
    student students[structSize];

    // Calling on the initialization function first to initialize all the students in the database
    INIT_SDB(students, structSize);

    // Main program loop
    do {
        userAction = SDB_APP();
        SDB_action(userAction, students, structSize);
    } while (userAction != 9);

    return 0;
}
