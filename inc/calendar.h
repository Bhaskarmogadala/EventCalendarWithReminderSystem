#ifndef CALENDEAR_H
#define CALENDAR_H

#include "event.h"

int isLeap(int year);
int getDaysInMonth(int month, int year);
int getFirstDayOfMonth(int month, int year);
void displayCalender(Event *head,int month,int year);
void viewAllSavedEvents(Event *head);
void upcomingEvents(Event *head, int day, int month, int year );
void specificDateEvents(Event *head, int day, int month, int year );

#endif