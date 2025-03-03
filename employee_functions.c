#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include "employee_functions.h"
#include "utility_functions.h"

// Array to hold employee records
Employee employee[MAX_EMPLOYEE];
int num_employee = 0; // Keep track of the number of registered employees

int is_duplicate_employee_id(char *id);

//For Admin to Register Employee
void register_employee(){

   int i,num_to_register;
   
   while(1){
    printf("\n-----------------------------\n");
    printf("      Register Employee\n");
    printf("-----------------------------\n");
    printf("Please enter the numbers of employee you want to register  [press 0 to exit]\n> ");
    scanf("%d",&num_to_register);
    printf("\n");

     if(num_to_register == 0){
     break;
     }

     if(num_to_register + num_employee > MAX_EMPLOYEE){
      printf("Employee number too large [max : 200 employee]\n");
     }else{
      for(i = 0; i < num_to_register; i++){
          printf("\n-----------------------------\n");
          printf("     Employee Details %d\n",i+1);
          printf("-----------------------------\n");

          printf("Employee name\n> ");
          scanf(" %[^\n]",employee[i].name);
          capitalize_word(employee[i].name);

          while (1) {
            printf("Employee ID\n> ");
            scanf("%s", employee[num_employee].id);

            if (is_duplicate_employee_id(employee[num_employee].id)) {
              printf("Employee ID '%s' already exists. Please enter a unique ID.\n", employee[num_employee].id);
            } else {
              break;
            }
          }

          printf("Employee Department\n> ");
          scanf("%s",&employee[i].position);
          capitalize_word(employee[i].position);

          printf("\n\n");
          num_employee++;
      }

          printf("%d employee(s) has been registered\n",num_to_register);  

    }

   }

}

//For employee login belongs to login_menu
int employee_login(){

char id[20];
int found = 0, employee_index = -1;

printf("\n-----------------------------\n");
printf("       Employee Login\n");
printf("-----------------------------\n");
printf("Please enter your employee ID\n");
printf("> ");
scanf("%s",&id);
while (getchar() != '\n');

for(int i = 0 ; i<num_employee ; i++){
  if(strcmp(employee[i].id, id) == 0){
    found = 1;
    employee_index = i;
    printf("\nLogin successful. Welcome, %s.\n", employee[i].name);
    break;
  }
}

  if(!found){
    printf("Employee ID not found,please communicate with admin\n");
    return -1;
  }

  return employee_index;
}

//For employee to see their information after login
void view_employee_info(int employee_index){
  if (employee_index == -1) {
    printf("\nNo employee logged in.\n");
    return;
  }
    
  printf("\n-----------------------------\n");
  printf("     Employee Information\n");
  printf("-----------------------------\n");
  printf("Employee name : %s\n", employee[employee_index].name);
  printf("Employee id   : %s\n", employee[employee_index].id);
  printf("Position      : %s\n", employee[employee_index].position);
  printf("\n");

}

// Check if id already exists
int is_duplicate_employee_id(char *id) {
  for (int i = 0; i < num_employee; i++) {
    if (strcmp(employee[i].id, id) == 0) {
      return 1;
    }
  }
  return 0;
}