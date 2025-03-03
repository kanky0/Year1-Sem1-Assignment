#include <stdio.h>
#include <string.h>
#include "accommodation_functions.h"
#include "customer_functions.h"
#include "employee_functions.h"
#include "admin_functions.h"
#include "utility_functions.h"
#include "input_output_info.h"

// gcc -o hotel "C:\Code\XMUM Codes\C\Assignment Group\main_file.c" "C:\Code\XMUM Codes\C\Assignment Group\accommodation_functions.c" "C:\Code\XMUM Codes\C\Assignment Group\admin_functions.c" "C:\Code\XMUM Codes\C\Assignment Group\customer_functions.c" "C:\Code\XMUM Codes\C\Assignment Group\employee_functions.c" "C:\Code\XMUM Codes\C\Assignment Group\input_output_info.c" "C:\Code\XMUM Codes\C\Assignment Group\utility_functions.c"

int login_menu();
int register_menu();
int customer_menu();
int employee_menu();
int admin_menu();

int main() {
    load_all_data();

    int choice = 0;
    while (1) {
        printf("\n-----------------------------\n");
        printf("    Welcome to XMUM Hotel\n");
        printf("-----------------------------\n");
        printf("1. Login\n");
        printf("2. Register\n");
        printf("3. Exit\n");
        printf("> ");
        choice = inputValidationNum();

        switch (choice) {
            case 1: 
                login_menu(); 
                break;
            case 2: 
                register_menu(); 
                break;
            case 3:
                save_all_data();
                printf("\nThanks for visiting\n"); 
                return 0;
            default: 
                printf("\nInvalid choice, try again\n"); 
                break;
        }
    }
    return 0;
}

int login_menu() {
    int choice = 0;

    while(1) {
        printf("\n-----------------------------\n");
        printf("\t Login Menu\n");
        printf("-----------------------------\n");
        printf("1. Customer\n2. Employee\n3. Administrator\n4. Back\n");
        printf("> ");
        choice = inputValidationNum();

        switch(choice) {
            case 1:
                customer_menu();
                break;
            case 2:
                employee_menu();
                break;
            case 3:
                admin_menu();
                break;
            case 4:
                return 1;
            default: 
                printf("\nInvalid choice, try again.\n"); 
                break;
        }
    }
    
}

int register_menu() {
    int choice = 0;
    
    while(1) {
        printf("\n-----------------------------\n");
        printf("\tRegister Menu\n");
        printf("-----------------------------\n");
        printf("1. Register Customer\n2. Back\n");
        printf("> ");
        choice = inputValidationNum();

        switch (choice) {
            case 1:
                register_customer();
                break;
            case 2:
                return 1;
            default:
                printf("\nInvalid choice, try again.\n");
                break;
        }      
    }
    return 0;
}

int customer_menu() {
    if (customer_count == 0) {
        printf("\nNo customers registered. Please register a customer first.\n");
        return 1;
    }

    char name[30];
    int found = 0;

    printf("\n-----------------------------\n");
    printf("       Customer Login\n");
    printf("-----------------------------\n");
    printf("Please enter your name to access the customer menu\n> ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;

    for (int i = 0; i < customer_count; i++) {
        if (strcasecmp(customers[i].name, name) == 0) {
            found = 1;
            printf("\nLogin successfully. Welcome, %s.\n", customers[i].name);
            break;
        }
    }

    if (!found) {
        printf("\nCustomer not found. Please try again.\n");
        return 1;
    }

    int choice = 0;
    float total_bill = 0;

    while (1) {
        printf("\n-----------------------------\n");
        printf("       Customer Menu\n");
        printf("-----------------------------\n");
        printf("1. Edit Personal Information\n2. View Accommodation Information\n3. Book Room\n4. Bill Information\n5. Back\n");
        printf("> ");
        choice = inputValidationNum();
        
        switch (choice) {
            case 1:
                edit_customer_info(name);
                break;
            case 2:
                viewRoomInfo();
                break;
            case 3:
                total_bill += booking();
                break;
            case 4:
                billInfo(total_bill);
                break;
            case 5:
                return 1;
            default:
                printf("\nInvalid choice, try again.\n");
                break;
        }
    }
    return 0;
}

int employee_menu() {
    int employee_index = -1;
    int choice = 0;

    if (num_employee == 0) {
        printf("\nNo employees registered. Please register an employee first.\n");
        return 1;
    }
    
    employee_index = employee_login();
    if (employee_index == -1) {
        printf("\nReturning to main menu.\n");
        return 1;
    }

    while (1) {
        printf("\n-----------------------------\n");
        printf("        Employee Menu\n");
        printf("-----------------------------\n");
        printf("1. View Position\n2. View List of Customer\n3. View List of Accommodation\n4 Back\n");
        printf("> ");
        choice = inputValidationNum();

        switch (choice) {
            case 1:
                view_employee_info(employee_index);
                break;
            case 2:
                view_list_of_customer();
                break;
            case 3:
                viewRoomList();
                break;
            case 4:
                employee_index = -1;
                return 1;
            default:
                printf("\nInvalid choice, try again.\n");
                break;
        }
    }
    return 0;
}

int admin_menu() {
    if (!admin_login()) {
        return 0;
    }

    int choice = 0;

    while (1) {
        printf("\n-----------------------------\n");
        printf("\tAdmin Menu\n");
        printf("-----------------------------\n");
        printf("1. Edit Accommodation Informtion\n2. View Customer Information\n3. Register Employee(s)\n4. Update Credentials\n5. Back\n");
        printf("> ");
        choice = inputValidationNum();

        switch (choice) {
            case 1:
                editAccommodationInfo();
                break;
            case 2:
                view_customer_info();
                break;
            case 3:
                register_employee();
                break;
            case 4:
                update_admin_credentials();
                break;
            case 5:
                return 1;
            default:
                printf("Invalid choice, try again.\n");
                break;
        }
    }
    return 0;
}
