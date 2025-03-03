#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include "accommodation_functions.h"
#include "utility_functions.h"

int accommodation[4][30][12][31]={0}; //room type, room number, month, day
int determineYear(int selectedMonth, int selectedDay);
const char* convertNumToMonth(int month);

Room room1, room2, room3, room4;

//Accommodation variable
int roomType=0;
int roomNumber=0;
int month=0, day=0;
int year;


Room room1 = {488, 18, "1 single bed", 0};  // single
Room room2 = {588, 25, "2 single beds", 0}; // twin
Room room3 = {788, 35, "2 queen beds", 0};  // family
Room room4 = {988, 50, "2 King beds, 1 queen bed, 1 sofa bed", 0}; // deluxe


int booking ()
{
    float bill =0;
    Room selectedRoom;

    while (1)
    {
        printf("\n---------------------\n");
        printf("     Booking Page\n");
        printf("---------------------\n");

        printf("Please select  the room type for booking:\n");
        printf("1. Single room\n2. Twin room\n3. Deluxe\n4. Family room\n5. Exit\n");
        printf(">");
        roomType = inputValidationNum();

        if (roomType==1 || roomType==2 || roomType==3 || roomType==4)
        {
            Room *selectedRoom;
            switch(roomType)
            {
                case 1:
                    selectedRoom= &room1;
                    break;

                case 2:
                    selectedRoom= &room2;
                    break;

                case 3:
                    selectedRoom= &room3;
                    break;

                case 4:
                    selectedRoom= &room4;
                    break;
            }

            while (1)
            {
                printf("\nPlease enter room number (01 to 30)\n> ");
                roomNumber = inputValidationNum();

                if (roomNumber>=1 && roomNumber<=30) break;
                printf("Invalid room number, please re-enter.\n");
            }

            
            while (1)
            {
                printf("Please enter the DATE for booking:\n");

                do
                {
                    printf("Month (01 to 12)\n> ");
                    month = inputValidationNum();

                    if (month>=1 && month<=12) break;
                    printf("\nInvalid month, please re-enter.\n");
                } while (month<1||month>12);

                do
                {
                    printf("Day (01 TO 31)\n> ");
                    day = inputValidationNum();

                    if (day>=1 && day<=31) break;
                    printf("Invalid day, please re-enter.\n");
                } while (day<1||day>31);

                break;
            }

            printf("\n");
            if (accommodation[roomType-1][roomNumber-1][month-1][day-1]==0)
            {
                accommodation[roomType-1][roomNumber-1][month-1][day-1]=1;
                switch (roomType)
                {
                    case 1:
                        printf("Room: Single || Room number: %d\n", roomNumber);
                        break;

                    case 2:
                        printf("Room: Twin || Room number: %d\n", roomNumber);
                        break;

                    case 3:
                        printf("Room: Deluxe || Room number: %d\n", roomNumber);
                        break;

                    case 4:
                        printf("Room: Family || Room number: %d\n", roomNumber);
                        break;
                }

                year = determineYear(month, day);
                printf("Date: %d/%d/%d\n", day, month, year);
                printf("Booked Successfully!\n");
                bill+= selectedRoom->price;
                selectedRoom->numbooked+=1;
            }
            else
            {
                printf("Sorry, the room is unavailable.\n");
            }              
        }
        else if (roomType==5)
        {
            break;
        }
        else
        {
            printf("Invalid selection! Please re-enter 1, 2, 3, 4 or 5 only.\n");
        }
    }
    return bill;
}

void viewRoomInfo ()
{
    printf("\nSINGLE ROOM\n");
    printf("----------------\n");
    printf("Price: RM%.2f\n", room1.price);
    printf("Room Size: %d sq ft\n", room1.size);
    printf("Bed type: %s\n", room1.bedtype);

    printf("\nTWIN ROOM\n");
    printf("----------------\n");
    printf("Price: RM%.2f\n", room2.price);
    printf("Room Size: %d sq ft\n", room2.size);
    printf("Bed type: %s\n", room2.bedtype);

    printf("\nDELUXE ROOM\n");
    printf("----------------\n");
    printf("Price: RM%.2f\n", room3.price);
    printf("Room Size: %d sq ft\n", room3.size);
    printf("Bed type: %s\n", room3.bedtype);

    printf("\nFAMILY ROOM\n");
    printf("----------------\n");
    printf("Price: RM%.2f\n", room4.price);
    printf("Room Size: %d sq ft\n", room4.size);
    printf("Bed type: %s\n", room4.bedtype);
}

int viewRoomList ()
{
    int i; //for room number looping 

    while (1)
    {
        printf("\n-----------------------------\n");
        printf("       View Room List\n");
        printf("-----------------------------\n");
        printf("Please select  the ROOM TYPE:\n");
        printf("1. Single room\n2. Twin room\n3. Deluxe\n4. Family room\n5. Exit\n");
        printf(">");
        roomType = inputValidationNum();

        if (roomType==1 || roomType==2 || roomType==3 || roomType==4)
        {
            
            while (1)
            {
                printf("Please enter the DATE\n> ");

                do 
                {
                    printf("Month (01 to 12)\n> ");
                    month = inputValidationNum();

                    if (month>=1 && month<=12) break;
                    printf("\nInvalid month, please re-enter.\n");
                } while (month< 1 || month > 12);

                do
                {
                    printf("Day (01 TO 31)\n> ");
                    day = inputValidationNum();

                    if (day>=1 && day<=31) break;
                    printf("Invalid day, please re-enter.\n");
                } while (day < 1 || day > 31);

                break;
            }

            year = determineYear(month, day);
            const char* monthName = convertNumToMonth(month);

            printf("\nDate: %d %s %d\n", day, monthName, year);
            printf("[] AVAILABLE\n[/] NOT AVAILABLE\n");
            for (i=0; i<10; i++)
            {
                printf("%d: ", i+1); //print room number
                if (accommodation[roomType-1][i][month-1][day-1]==0)
                {
                    printf("[]\t");
                }
                else
                {
                    printf("[/]\t");
                }
            }
            printf("\n");

            for (i=10; i<20; i++)
            {
                printf("%d: ", i+1); //print room number
                if (accommodation[roomType-1][i][month-1][day-1]==0)
                {
                    printf("[]\t");
                }
                else
                {
                    printf("[/]\t");
                }
            }
            printf("\n");

            for (i=20; i<30; i++)
            {
                printf("%d: ", i+1); //print room number
                if (accommodation[roomType-1][i][month-1][day-1]==0)
                {
                    printf("[]\t");
                }
                else
                {
                    printf("[/]\t");
                }
            } 
            printf("\n");               
        }
        else if (roomType==5)
        {
            return 0;
        }
        else
        {
            printf("Invalid selection! Please re-enter 1, 2, 3, 4 or 5 only.\n");
        }
    }
}

void billInfo (float totalBill)
{

     if (room1.numbooked == 0 && room2.numbooked == 0 && room3.numbooked == 0 && room4.numbooked == 0)
    {
        printf("No bookings have been made yet. Please book a room first.\n");
        return;
    }

    printf("\n-----------------------------\n");
    printf("       Billing Details\n");
    printf("-----------------------------\n");
    printf("Room Type\tNumber\t\tPrice\n");
    
    if (room1.numbooked!=0)
    {
        printf("Single Room\t%d\t\t%.2f\n", room1.numbooked, room1.price);
    }
    if (room2.numbooked!=0)
    {
        printf("Twin Room\t%d\t\t%.2f\n", room2.numbooked, room2.price);
    }
    if (room3.numbooked!=0)
    {
        printf("Deluxe\t%d\t\t%.2f\n", room3.numbooked, room3.price);
    }
    if (room4.numbooked!=0)
    {
        printf("Family Room\t%d\t\t%.2f\n", room4.numbooked, room4.price);
    }
    printf("Total price: ");
    printf("RM %.2f\n", totalBill);
}

int determineYear(int selectedMonth, int selectedDay) 
{
    // Get current date
    time_t t = time(NULL);           
    struct tm currentDate = *localtime(&t);

    int currentYear = currentDate.tm_year + 1900;
    int currentMonth = currentDate.tm_mon + 1;  
    int currentDay = currentDate.tm_mday;        

    // Determine the year for the selected date
    if (selectedMonth > currentMonth || 
        (selectedMonth == currentMonth && selectedDay >= currentDay)) {
        return currentYear;
    } else {
        return currentYear + 1;
    }
}

void change_room_price(int choice) {
    float changed_pricing = 0;
    char room_type[30];

    switch (choice) {
        case 1:
            strcpy(room_type, "single room");
            printf("\nCurrent price for %s: RM%.2f\n", room_type, room1.price);
            printf("Enter new price for %s\n> RM", room_type);
            changed_pricing = inputValidationFloat();
            room1.price = changed_pricing;
            break;
        case 2:
            strcpy(room_type, "twin room");
            printf("\nCurrent price for %s: RM%.2f\n", room_type, room2.price);
            printf("Enter new price for %s\n> RM", room_type);
            changed_pricing = inputValidationFloat();
            room2.price = changed_pricing;
            break;
        case 3:
            strcpy(room_type, "deluxe");
            printf("\nCurrent price for %s: RM%.2f\n", room_type, room3.price);
            printf("Enter new price for %s\n> RM", room_type);
            changed_pricing = inputValidationFloat();
            room3.price = changed_pricing;
            break;
        case 4:
            strcpy(room_type, "family room");
            printf("\nCurrent price for %s: RM%.2f\n", room_type, room4.price);
            printf("Enter new price for %s\n> RM", room_type);
            changed_pricing = inputValidationFloat();
            room4.price = changed_pricing;
            break;
        default:
            printf("\nInvalid choice\n");
            return;
    }
    printf("\nNew price for %s updated to RM%.2f\n", room_type, changed_pricing);
}

void change_room_bookednum(int choice) {
    int changed_bookednum = 0, roomNumber = 0, month = 0, day = 0;
    char room_type[30];

    switch (choice) {
        case 1:
            strcpy(room_type, "single room");
            break;
        case 2:
            strcpy(room_type, "twin room");
            break;
        case 3:
            strcpy(room_type, "deluxe");
            break;
        case 4:
            strcpy(room_type, "family room");
            break;
        default:
            printf("\nInvalid room type selection.\n");
            return;
    }

    while (1) {
        printf("\nEnter the room number (01 to 30):\n> ");
        roomNumber = inputValidationNum();
        if (roomNumber >= 1 && roomNumber <= 30) break;
        printf("\nInvalid room number. Please re-enter.\n");
    }

    while (1) {
        printf("\nEnter the booking month (01 to 12):\n> ");
        month = inputValidationNum();
        if (month >= 1 && month <= 12) break;
        printf("\nInvalid month. Please enter a valid month between 01 and 12.\n");
    }

    while (1) {
        printf("\nEnter the booking day (01 to 31):\n> ");
        day = inputValidationNum();
        if (day >= 1 && day <= 31) break;
        printf("\nInvalid day. Please enter a valid day between 01 and 31.\n");
    }

    const char* monthName = convertNumToMonth(month);

    if (accommodation[choice-1][roomNumber-1][month-1][day-1] == 1) {
        printf("\nRoom %d (%s) on %d %s is already booked.\n", roomNumber, room_type, day, monthName);
        printf("Would you like to mark it as available? (1 for Yes, 0 for No):\n> ");
        int confirm = inputValidationNum();
        if (confirm == 1) {
            accommodation[choice-1][roomNumber-1][month-1][day-1] = 0;
            printf("\nBooking for Room %d (%s) on %d %s has been canceled and marked as available.\n", roomNumber, room_type, day, monthName);
        } else {
            printf("\nNo changes were made.\n");
        }
    } else {
        printf("\nRoom %d (%s) on %d %s is currently available.\n", roomNumber, room_type, day, monthName);
        printf("Would you like to mark it as booked? (1 for Yes, 0 for No):\n> ");
        int confirm = inputValidationNum();
        if (confirm == 1) {
            accommodation[choice-1][roomNumber-1][month-1][day-1] = 1;
            printf("\nRoom %d (%s) on %d %s has been marked as booked.\n", roomNumber, room_type, day, monthName);
        } else {
            printf("\nNo changes were made.\n");
        }
    }
}

int editAccommodationInfo() {
    int choice = 0, i = 0;
    
    while (1) {
        printf("\n-----------------------------\n");
        printf("Accommodation Information Menu\n");
        printf("-----------------------------\n");
        printf("1. Change Room Pricing\n2. Change Number of Booked Rooms\n3. Back\n");
        printf("> ");
        choice = inputValidationNum();

        if (choice == 1) {
            while (1) {
                printf("\nChange pricing for:\n");
                printf("1. Single room\n2. Twin room\n3. Deluxe\n4. Family room\n5. Back\n");
                printf("> ");
                i = inputValidationNum();
                if (i == 5) break;
                change_room_price(i);   
            }
        } else if (choice == 2) {
            while (1) {
                printf("\nChange number of booking for:\n");
                printf("1. Single room\n2. Twin room\n3. Deluxe\n4. Family room\n5. Back\n");
                printf("> ");
                i = inputValidationNum();
                if (i == 5) break;
                change_room_bookednum(i);
            }
        } else if (choice == 3) {
            return 1;
        } else {
            printf("\nInvalid choice, try again\n");
        }
    }
}

const char* convertNumToMonth(int month) {
    switch (month) {
        case 1: return "January";
        case 2:  return "February";
        case 3:  return "March";
        case 4:  return "April";
        case 5:  return "May";
        case 6:  return "June";
        case 7:  return "July";
        case 8:  return "August";
        case 9:  return "September";
        case 10: return "October";
        case 11: return "November";
        case 12: return "December";
        default: return "Invalid Month";
    }
}