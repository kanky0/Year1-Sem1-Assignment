#ifndef ACCOMMODATION_FUNCTIONS_H
#define ACCOMMODATION_FUNCTIONS_H

typedef struct {
    float price;
    int size;
    char bedtype[50];
    int numbooked;
} Room;

extern Room room1, room2, room3, room4;
extern int accommodation[4][30][12][31];

void viewRoomInfo();
int viewRoomList();
int booking();
void billInfo(float totalBill);
void change_room_price(int choice);
void change_room_bookednum(int choice);
int editAccommodationInfo();

#endif