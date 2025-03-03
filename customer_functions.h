#ifndef CUSTOMER_FUNCTIONS_H
#define CUSTOMER_FUNCTIONS_H

typedef struct {
    char name[30];
    char gender[10];
    int age;
    char phone_num[20];
    char nationality[20];
    char ic[20];
    char passport[20];
} Customer;

extern Customer customers[150];
extern int customer_count;

void view_customer_info();
void view_list_of_customer();
int register_customer();
void edit_customer_info(char name[]);
int inputValidationNum();
void capitalize_name(char *name);

#endif