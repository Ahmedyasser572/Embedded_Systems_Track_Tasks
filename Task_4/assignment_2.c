#include <stdio.h>
#include <string.h>

struct Date {
    int day;
    int month;
    int year;
};

struct Date read_date() 
{
    struct Date date;
    int result;

    do {
        printf("Enter year: ");
        result = scanf("%d", &date.year);
        if (result != 1 || date.year < 0) {
            printf("Invalid year. Please enter a positive integer.\n");
            while(getchar() != '\n'); 
            continue;
        }

        printf("Enter month: ");
        result = scanf("%d", &date.month);
        if (result != 1 || date.month < 1 || date.month > 12) {
            printf("Invalid month. Please enter an integer between 1 and 12.\n");
            while(getchar() != '\n');
            continue;
        }

        printf("Enter day: ");
        result = scanf("%d", &date.day);
        if (result != 1 || date.day < 1 || date.day > 31) {
            printf("Invalid day. Please enter an integer between 1 and 31.\n");
            while(getchar() != '\n'); 
            continue;
        }

        break; 
    } while (1);

    return date;
}

int main() {
struct Date date1 = read_date();
struct Date date2 = read_date();

    
if (date1.year == date2.year && date1.month == date2.month && date1.day == date2.day) 
{
        printf("Dates are equal.\n");
} 
else 
{
        printf("Dates are not equal.\n");
}

return 0;
}