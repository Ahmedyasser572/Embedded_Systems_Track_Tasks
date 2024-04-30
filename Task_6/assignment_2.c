#include <stdio.h>

int main() {
    int hours, minutes, seconds;
    printf("Enter time in format [hh:mm:ss] input the hours then press enter the same you \
will do with the others\n");
    scanf("%d%d%d", &hours, &minutes, &seconds);

    // Input validation
    if(hours < 0 || hours > 23 || minutes < 0 || minutes > 59 || seconds < 0 || seconds > 59) {
        printf("Invalid time input.\n");
        return 1;
    }

    // Conversion to integer and save it in one integer 
    int total_seconds = hours * 3600 + minutes * 60 + seconds;

    printf("Total time in seconds: %d\n", total_seconds);

    // Conversion back to [hh:mm:ss] format to hours and seconds again
    hours = total_seconds / 3600;
    total_seconds %= 3600;
    minutes = total_seconds / 60;
    seconds = total_seconds % 60;

    printf("Time in [hh:mm:ss] format: %02d:%02d:%02d\n", hours, minutes, seconds);

    return 0;
}