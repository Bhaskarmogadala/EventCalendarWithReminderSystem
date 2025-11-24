#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include "color.h"
#include "event.h"

Event* addEvent(Event *head)
{
    Event *newnode = NULL;
    // Allocate memory for new node
    newnode = calloc(1,sizeof(Event));
    if (newnode == NULL) {
        perror("Memory allocation failed");
        return head;
    }
    printf("Enter the event name:\n");
    getchar(); // clear leftover newline from buffer
    char st[100];
    fgets(st,sizeof(st),stdin);
    st[strcspn(st,"\n")]='\0';
    strcpy(newnode->Title,st);
    printf("Enter the day:\n");
    scanf("%d",&newnode->day);
    printf("Enter the month:\n");
    scanf("%d",&newnode->month);
    printf("Enter the year:\n");
    scanf("%d",&newnode->year);
    getchar(); // clear leftover newline from buffer
    printf("Enter the event description\n");
    char str[100];
    fgets(str,sizeof(str),stdin);
    str[strcspn(str,"\n")]='\0';
    strcpy(newnode->description,str);
    // Add at first
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        newnode->next=head;
        head=newnode;
    }
    return head;
}

Event* deleteEvent(Event *head)
{
    Event *temp=NULL;
    if(head==NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        temp=head;
        head=head->next;
        free(temp);
    }
    return head;
}

void saveEventsToFile(Event *ptr,const char*filename)
{
    int size=sizeof(Event)-sizeof(Event*);
    FILE *fp=fopen(filename,"w");
    if(ptr==NULL)
    {
        printf("No events to save");
    }
    else
    {
        while(ptr)
        {
            fwrite(ptr,size,1,fp);
            ptr=ptr->next;
        }
    }
    printf(GREEN BOLD "Events are Saved succesfully\n");
    fclose(fp);
}

void syncEventsFromFile(Event **head,const char*filename)
{
    int size=sizeof(Event)-sizeof(Event*);
    Event demo,*temp,*node;
    FILE *fp=fopen(filename,"r");
    if(fp==NULL)
    {
        perror("File not open\n");
    }
    else
    {
        while(fread(&demo,size,1,fp))
        {
            node=malloc(sizeof(struct Event));
            strcpy(node->Title,demo.Title);
            node->day=demo.day;
            node->month=demo.month;
            node->year=demo.year;
            strcpy(node->description,demo.description);
            if(*head == NULL)
            {
                *head=node;
            }
            else
            {
                temp=*head;
                while(temp->next)
                {
                    temp=temp->next;
                }
                temp->next=node;
            }
        }
        printf(GREEN BOLD "Events are Retrived succesfully\n");
    }
}

void displaymenu()
{
    printf("\n" HR "\n");
    printf("               EVENT CALENDAR & REMINDER SYSTEM\n");
    printf(HR "\n\n");
    printf("a/A : Add new event\n");
    printf("p/P : Print calendar for a month/year\n");
    printf("v/V : View all saved events\n");
    printf("d/D : Delete an event\n");
    printf("s/S : Save all events to a file\n");
    printf("l/L : sync events from file\n");
    printf("u/U : Upcoming event reminders\n");
    printf("f/F : Find events on a specific date\n");
    printf("q/Q : Quit the application\n");
    printf("\n" HR "\n");
}