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
    Event *temp=head;
    if(temp==NULL)
    {
        return newnode;
    }
    while(temp->next!=NULL)
    {
            temp=temp->next;
    }
    temp->next=newnode;
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

Event *sortNodes(Event *head)
{
        int swapped;
        if(head == NULL || head ->next==NULL)
               return head;
        while(1)
        {
                Event *cur=head;
                Event *prev=NULL;
                swapped=0;
                while(cur->next)
                {
                        Event *run=cur->next;
                        if((cur->year > run->year) ||
                 (cur->year == run->year && cur->month > run->month) ||
                 (cur->year == run->year && cur->month == run->month &&
                  cur->day > run->day) )
                        {
                                cur->next=run->next;
                                run->next=cur;
                                if(prev == NULL)
                                        prev=head;
                                else
                                        prev->next=cur;
                                prev=cur;
                                swapped = 1;
                        }
                        else
                        {
                                prev=cur;
                                cur=cur->next;
                        }
                }
                        if(!swapped)
                                break;
        }
        return head;

}
void saveEventsToFile(Event *ptr,const char*filename)
{
    FILE *fp=fopen(filename,"w");
    if(ptr==NULL)
    {
        printf("No events to save");
    }
    else
    {
        //ptr=sortNodes(ptr);
        while(ptr)
        {
                fwrite(ptr->Title, sizeof(ptr->Title), 1, fp);
                fwrite(&ptr->day, sizeof(int), 1, fp);
                fwrite(&ptr->month, sizeof(int), 1, fp);
                fwrite(&ptr->year, sizeof(int), 1, fp);
                fwrite(ptr->description, sizeof(ptr->description), 1, fp);
                ptr=ptr->next;
        }
    }
    printf(GREEN BOLD "Events are Saved succesfully\n");
    fclose(fp);
}

void syncEventsFromFile(Event **head, const char *filename)
{
    FILE *fp = fopen(filename, "rb");
    if (!fp)
    {
        perror("File not open");
        return;
    }

    *head = NULL;   // 
    Event *temp = NULL;

    while (1)
    {
        Event *node = malloc(sizeof(Event));
        if (!node) break;

        if (fread(node->Title, sizeof(node->Title), 1, fp) != 1) break;
        fread(&node->day, sizeof(int), 1, fp);
        fread(&node->month, sizeof(int), 1, fp);
        fread(&node->year, sizeof(int), 1, fp);
        fread(node->description, sizeof(node->description), 1, fp);

        node->next = NULL;   // 

        if (*head == NULL)
            *head = temp = node;
        else
        {
            temp->next = node;
            temp = node;
        }
    }

    fclose(fp);
    printf(GREEN BOLD "Events are Retrieved successfully\n");
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
