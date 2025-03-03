#ifndef EMPLOYEE_FUNCTIONS_H
#define EMPLOYEE_FUNCTIONS_H

#define MAX_EMPLOYEE 200

typedef struct {
    char name[30];
    char id[20];
    char position[10];
} Employee;

void register_employee();
int employee_login();
void view_employee_info(int employee_index);

extern Employee employee[MAX_EMPLOYEE];
extern int num_employee;

#endif