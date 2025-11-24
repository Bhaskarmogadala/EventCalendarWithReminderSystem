#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include "calendar.h"
#include "color.h"

//Function to check leap year
int isLeap(int year)
{
    return ((year % 4 == 0 ) && (year % 100 != 0) ||(year % 400 == 0));
}
// Function to return number of days in a month
int getDaysInMonth(int month, int year)
{
    switch(month) {
        case 1: return 31;
        case 2: return isLeap(year) ? 29 : 28;
        case 3: return 31;
        case 4: return 30;
        case 5: return 31;
        case 6: return 30;
        case 7: return 31;
        case 8: return 31;
        case 9: return 30;
        case 10: return 31;
        case 11: return 30;
        case 12: return 31;
        default: return 0;
    }
}

// Function to calculate day of week for 1st of given month/year
// 0=Sunday, 1=Monday,...6=Saturday
int getFirstDayOfMonth(int month, int year)
{
    int d = 1;
    if (month < 3)
    {
        month += 12;
        year -= 1;
    }
    int f = (d + (13*(month + 1))/5 + year + year/4 - year/100 + year/400) % 7;
    return (f + 6) % 7; // Convert so that 0=Sunday
}
/*
// Function to check if a day has an event
int hasEvent(Event *head, int day, int month, int year)
{
    Event *temp = head;
    while (temp)
    {
        if (temp->day == day && temp->month == month && temp->year == year)
            return 1;
        temp = temp->next;
    }
    return 0;
}
*/
void displayCalender(Event *head,int month,int year)
{
    const char*months[] =
    {
        "","January","February","March","April","May","June",
        "July","August","September","October","November","December"
    };

    printf("\n\n===== %s %d =====\n", months[month], year);
    printf("Su Mo Tu We Th Fr Sa\n");

    int firstDay = getFirstDayOfMonth(month, year);
    int totalDays = getDaysInMonth(month, year);

    // Print initial spaces
    for(int i = 0; i < firstDay; i++)
        printf("   ");

    // Print days
        for (int d = 1; d <= totalDays; d++)
        {
            printf("%2d", d);

        if ((d + firstDay) % 7 == 0)
            printf("\n");
        else
            printf(" ");
        }
        printf("\n\n");


}


// Print all events saved
void viewAllSavedEvents(Event *head)
{
    Event *temp = head;
    int found = 0;
    while (temp)
    {
            found=1;
        printf("\n" HR "\n");
        printf(BOLD CYAN "Title          : " RESET "%s\n", temp->Title);
        printf(BOLD CYAN "Date           : " RESET "%02d/%02d/%04d\n", temp->day, temp->month, temp->year);
        printf(BOLD CYAN "Description    : " RESET "%s\n", temp->description);
        temp = temp->next;
    }
        printf(HR "\n");
        if (!found)
        printf("No events this month.\n");
}


// Print Remaining events saved
void upcomingEvents(Event *head, int day, int month, int year )
{
    int found = 0;
    Event *temp = head;
    while (temp)
    {
        if (temp->day >= day && temp->month >= month && temp->year >= year)
        {
        printf("%02d-%02d-%04d : " GREEN BOLD "%s\n", temp->day, temp->month, temp->year, temp->Title);
        found = 1;
        }
        temp = temp->next;
    }
    if (!found)
        printf("GREEN BOLD No events present in this month.\n");
}


// Print specific date events saved
void specificDateEvents(Event *head, int day, int month, int year )
{
    int found = 0;
    Event *temp = head;
    while (temp)
    {
        if (temp->day == day && temp->month == month && temp->year == year)
        {
        printf("%02d-%02d-%04d : " GREEN BOLD "%s\n", temp->day, temp->month, temp->year, temp->Title);
        found = 1;
        }
        temp = temp->next;
    }
    if (!found)
        printf("No events this month.\n");
}