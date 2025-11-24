EVENT CALENDAR WITH REMINDER SYSTEM IN C
-----------------------------------------------------------

PROJECT OVERVIEW :
-----------------------
This project is a Command-Line Interface (CLI) based
Event Calendar and Reminder Management System.
It allows users to add, view, delete, store, and retrieve
events along with displaying monthly calendars and
showing upcoming reminders.

FEATURES :
-----------------------
1. Add new events
2. Display monthly calendar
3. View all saved events
4. Delete an event by ID
5. Save all events to file
6. Load (sync) events from file
7. Show upcoming event reminders
8. Search events by specific date
9. Persistent storage in binary file (events.dat)


EVENT STRUCTURE :
-----------------------
Each event contains:

• Event Name        (e.g., "Project Submission")
• Date              (DD/MM/YYYY)
• Description       (short notes)
• Pointer to next event (Singly Linked List)


FILES :
-----------------------

• main.c
• event.c
• event.h
• calendar.c
• calendar.h
• Makefile
• README.txt
• events.dat (created automatically after save)

HOW TO COMPILE (USING MAKEFILE) :
-----------------------

Step 1: Open terminal and go to project directory
Example:
    cd C-Miniproject

Step 2: Compile all files(optional)
    $ gcc main.c event.c calendar.c -o a.out

Step 3: Run make
    make

This will generate executable:
    a.out

If you want to clean:
    make clean

HOW TO RUN :
-----------------------
Run the program:
    ./a.out (Along with event.dat file)

SAMPLE INPUT/OUTPUT :
-----------------------

Example: Adding an Event
-----------------------------------
Enter Event Name: Meeting
Enter Date (DD MM YYYY): 25 02 2025
Enter Description: Project discussion

Event added successfully!


Example: View All Events
-----------------------------------

Event Name      : Meeting
Date            : 25/02/2025
Description     : Project discussion
-----------------------------------


Example: Save Events
-----------------------------------
Events saved successfully to events.


Example: Load Events
-----------------------------------
Previous records loaded successfully!


Example: Print Calendar
-----------------------------------
Enter Month: 2
Enter Year : 2025
(February 2025 calendar displayed)

VERSION HISTORY :
-----------------------

• Added binary file persistence
• Linked list save/load
• Upcoming event reminders
• Event search by date

FUTURE ENHANCEMENTS :
-----------------------

• Colorful UI using ANSI escape colors
• Export events to text file
• Add event sorting
• Add alarm system

