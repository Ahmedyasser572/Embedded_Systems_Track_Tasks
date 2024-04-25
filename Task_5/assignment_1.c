#include <stdio.h>
typedef     unsigned            char        u8;
typedef     signed              char        s8;

typedef     unsigned    short   int         u16;
typedef     signed      short   int         s16;
typedef     unsigned    long    int         u32;
typedef     signed      long    int         s32;

typedef     unsigned    long    long        u64;
typedef     signed      long    long        s64;

typedef                         float       f32;

typedef                         double      f64;
typedef                 long    double      f96;

typedef struct StudentInfo
{   
    unsigned int marks:3; // Student's marks 
    unsigned int roll_number:4;             // Student's roll number
    unsigned int age:8;                     // Student's age
    char * name;  // Student's name                  
    char *address;
} studentInfo;

struct bitCard {
unsigned face : 4;
unsigned suit : 2;
unsigned color : 1;
}bitCard;

typedef struct complex {
    int real;
    int imaginary;
}complex;

complex  add_complex(complex x, complex y);

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

    

    students[0]->name = "mahmoud ali";
    students[0]->age = 22;
    students[0]->marks = 7;
    students[0]->roll_number = 1;
    students[0]->address = "18-11-fourth building";

    students[1]->name = "abdullah hamed";
    students[1]->age = 22;
    students[1]->marks = 6;
    students[1]->roll_number = 2;

    students[2]->name = "mahmoud hamed";
    students[2]->age = 23;
    students[2]->marks = 6;
    students[2]->roll_number = 3;

    students[3]->name = "mahmoud hamed";
    students[3]->age = 23;
    students[3]->marks = 5;
    students[3]->roll_number = 4;

    students[4]->name = "mahmoud askar";
    students[4]->age = 21;
    students[4]->marks = 2;
    students[4]->roll_number = 5;

    students[5]->name = "mahmoud ahmed";
    students[5]->age = 23;
    students[5]->marks = 3;
    students[5]->roll_number = 6;

    students[6]->name = "mahmoud askar";
    students[6]->age = 23;
    students[6]->marks = 7;
    students[6]->roll_number = 7;


    students[7]->name = "yousef yasser";
    students[7]->age = 22;
    students[7]->marks = 3;
    students[7]->roll_number = 9;

    students[8]->name = "yousef askar";
    students[8]->age = 22;
    students[8]->marks = 2;
    students[8]->roll_number = 9;

    students[9]->name = "yousef ali";
    students[9]->age = 22;
    students[9]->marks = 7;
    students[9]->roll_number = 10;

    students[10]->name = "ahmed ali";
    students[10]->age = 22;
    students[10]->marks = 6;
    students[10]->roll_number = 3;

    students[11]->name = "ahmed ali";
    students[11]->age = 22;
    students[11]->marks = 6;
    students[11]->roll_number = 3;

    students[12]->name = "rawan ali";
    students[12]->age = 22;
    students[12]->marks = 7;
    students[12]->roll_number = 10;

    students[13]->name = "ahmed ali";
    students[13]->age = 22;
    students[13]->marks = 2;
    students[13]->roll_number = 10;

    students[14]->name = "ahmed ali";
    students[14]->age = 22;
    students[14]->marks = 1;
    students[14]->roll_number = 10;

    

    printf("%ld", sizeof(student_1));


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


    complex x;
    x.real = 4;
    x.imaginary = 6;

    complex y;
    x.real = 5;
    x.imaginary = 12;


    complex z  =  add_complex(x,y);

    printf("%d +%d j",z.real,z.imaginary);



}

complex  add_complex(complex x, complex y)
{   
    complex z ; 

    z.real= x.real + y.real;
    z.imaginary = x.imaginary+y.imaginary;

    return z;

}