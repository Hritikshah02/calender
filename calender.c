#include <stdio.h>

int isLeapYear(int year) {
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

int getDayOfWeek(int year, int month, int day) {
    if (month < 3) {
        month += 12;
        year--;
    }
    return (day + 2 * month + 3 * (month + 1) / 5 + year + year / 4 - year / 100 + year / 400) % 7;
}

int getDaysInMonth(int year, int month) {
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeapYear(year))
        return 29;
    return daysInMonth[month];
}

void displayCalendar(int year, int month) {
    printf("   %s %d\n", (month == 1) ? "January" :
                        (month == 2) ? "February" :
                        (month == 3) ? "March" :
                        (month == 4) ? "April" :
                        (month == 5) ? "May" :
                        (month == 6) ? "June" :
                        (month == 7) ? "July" :
                        (month == 8) ? "August" :
                        (month == 9) ? "September" :
                        (month == 10) ? "October" :
                        (month == 11) ? "November" : "December", year);
    printf("Su Mo Tu We Th Fr Sa\n");

    int daysInMonth = getDaysInMonth(year, month);
    int firstDay = getDayOfWeek(year, month, 1);

    int dayCounter = 1;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {
            if (i == 0 && j < firstDay)
                printf("   ");
            else if (dayCounter <= daysInMonth) {
                printf("%2d ", dayCounter);
                dayCounter++;
            }
        }
        printf("\n");
    }
}

int main() {
    int year, month;
    printf("Enter year: ");
    scanf("%d", &year);
    printf("Enter month (1-12): ");
    scanf("%d", &month);

    if (year <= 0 || month < 1 || month > 12) {
        printf("Invalid input.\n");
        return 1;
    }

    displayCalendar(year, month);

    return 0;
}

