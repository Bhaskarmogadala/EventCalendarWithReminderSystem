#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include "event.h"
#include "calendar.h"

int day, month, year;
int main(int argc,char *argv[])
{
    char ch;
    Event *head = NULL;
    while(1)
    {
        displaymenu();
        printf("Enter the choice:");
        scanf(" %c",&ch);
        switch(ch)
        {
            case 'a' :
            case 'A' :
                        head=addEvent(head);
                        break;
            case 'p' :
            case 'P' :
                        printf("Enter month and year to view calendar (MM YYYY): \n");
                        scanf("%d %d", &month, &year);
                        displayCalender(head,month, year);
                        break;
            case 'v' :
            case 'V' :
                        viewAllSavedEvents(head);
                        break;
            case 'd' :
            case 'D' :
                        head=deleteEvent(head);
                        break;
           case 's' :
            case 'S' :
                        saveEventsToFile(head,argv[1]);
                        break;
            case 'l' :
            case 'L' :
                        syncEventsFromFile(&head,argv[1]);
                        break;
             case 'u' :
            case 'U' :
                        printf("Enter day,month and year to view calendar (MM YYYY): \n");
                        scanf("%d %d %d",&day, &month, &year);
                        upcomingEvents(head,day,month,year);
                        break;
            case 'f' :
            case 'F' :
                        printf("Enter day,month and year to view calendar (MM YYYY): \n");
                        scanf("%d %d %d",&day, &month, &year);
                        specificDateEvents(head,day,month,year);
                        break;
            case 'q' :
            case 'Q' :
                        exit(0);
        }
    }
    return 0;
}