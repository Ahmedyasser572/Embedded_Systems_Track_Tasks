#include <stdio.h>
#define MAX_NAME_LENGTH 100

typedef struct StudentInfo
{
    char  name[50];  // Student's name
    int roll_number;             // Student's roll number
    int age;                     // Student's age
    int marks;                   // Student's marks
} studentInfo;

int input(char str[], int n) 
{
    int ch;
    int i;
    for (i = 0; ((ch = getchar()) != '\n') && i < n - 1; i++) {
        
        str[i] = ch;
        
    }

    str[i] = '\0';
    return i; 
}




int main()
{
    studentInfo * students[15];

    studentInfo student_1;
    studentInfo student_2;
    studentInfo student_3;
    studentInfo student_4;
    studentInfo student_5;
    studentInfo student_6;
    studentInfo student_7;
    studentInfo student_8;
    studentInfo student_9;
    studentInfo student_10;
    studentInfo student_11;
    studentInfo student_12;
    studentInfo student_13;
    studentInfo student_14;
    studentInfo student_15;

    students[0] = &student_1;
    students[1] = &student_2;
    students[2] = &student_3;
    students[3] = &student_4;
    students[4] = &student_5;
    students[5] = &student_6;
    students[6] = &student_7;
    students[7] = &student_8;
    students[8] = &student_9;
    students[9] = &student_10;
    students[10] = &student_11;
    students[11] = &student_12;
    students[12] = &student_13;
    students[13] = &student_14;
    students[14] = &student_15;

    // students[0]->name = "mahmoud ali";
    // students[0]->age = 22;
    // students[0]->marks = 19;
    // students[0]->roll_number = 1;

    // students[1]->name = "abdullah hamed";
    // students[1]->age = 22;
    // students[1]->marks = 11;
    // students[1]->roll_number = 2;

    // students[2]->name = "mahmoud hamed";
    // students[2]->age = 23;
    // students[2]->marks = 10;
    // students[2]->roll_number = 3;

    // students[3]->name = "mahmoud hamed";
    // students[3]->age = 23;
    // students[3]->marks = 10;
    // students[3]->roll_number = 4;

    // students[4]->name = "mahmoud askar";
    // students[4]->age = 21;
    // students[4]->marks = 15;
    // students[4]->roll_number = 5;

    // students[5]->name = "mahmoud ahmed";
    // students[5]->age = 23;
    // students[5]->marks = 10;
    // students[5]->roll_number = 6;

    // students[6]->name = "mahmoud askar";
    // students[6]->age = 23;
    // students[6]->marks = 10;
    // students[6]->roll_number = 7;


    // students[7]->name = "yousef yasser";
    // students[7]->age = 22;
    // students[7]->marks = 12;
    // students[7]->roll_number = 9;

    // students[8]->name = "yousef askar";
    // students[8]->age = 22;
    // students[8]->marks = 10;
    // students[8]->roll_number = 9;

    // students[9]->name = "yousef ali";
    // students[9]->age = 22;
    // students[9]->marks = 12;
    // students[9]->roll_number = 10;

    // students[10]->name = "ahmed ali";
    // students[10]->age = 22;
    // students[10]->marks = 11;
    // students[10]->roll_number = 11;

    // students[11]->name = "ahmed ali";
    // students[11]->age = 22;
    // students[11]->marks = 10;
    // students[11]->roll_number = 12;

    // students[12]->name = "rawan ali";
    // students[12]->age = 22;
    // students[12]->marks = 20;
    // students[12]->roll_number = 10;

    // students[13]->name = "ahmed ali";
    // students[13]->age = 22;
    // students[13]->marks = 12;
    // students[13]->roll_number = 10;

    // students[14]->name = "ahmed ali";
    // students[14]->age = 22;
    // students[14]->marks = 12;
    // students[14]->roll_number = 10;


    // for (int j = 0; j < 15; j++)
    // {
    //     printf("enter the name of the sutdent:");
    //     input(students[j]->name,50);
    //     printf("\n");
    //     printf("enter the age of the sutdent:");
    //     scanf("%d",students[j]->age);
    //     printf("\n");
    //     printf("enter the mark of the sutdent:");
    //     scanf("%d",students[j]->marks);
    //     printf("\n");
    //     printf("enter the mark of the sutdent:");
    //     scanf("%d",students[j]->roll_number);
    //     printf("\n");
    // }







    for (int i = 0; i < 15; i++)
    {
        if(students[i]->marks < 15)
        {
        printf("name is %s\n",students[i]->name);
        printf("age: %d\n",students[i]->age);
        printf("roll_number = %d\n",students[i]->roll_number);
        printf("marks = %d\n\n",students[i]->marks);
        }
    }



    return 0;
}