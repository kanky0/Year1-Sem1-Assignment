#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "admin_functions.h"

Admin admin = {"admin", "password"}; //default

void update_admin_credentials() {
    char current_password[20];
    char new_username[20];
    char new_password[20];
    char confirm_password[20];

    printf("\nEnter current password to change admin credentials:\n> ");
    fgets(current_password, sizeof(current_password), stdin);
    current_password[strcspn(current_password, "\n")] = 0;

    if (strcmp(current_password, admin.password) != 0) {
        printf("\nIncorrect password. Access denied.\n");
        return;
    }

    printf("\nEnter new username:\n> ");
    fgets(new_username, sizeof(new_username), stdin);
    new_username[strcspn(new_username, "\n")] = 0;
    
    printf("\nEnter new password:\n> ");
    fgets(new_password, sizeof(new_password), stdin);
    new_password[strcspn(new_password, "\n")] = 0;

    printf("\nConfirm new password:\n> ");
    fgets(confirm_password, sizeof(confirm_password), stdin);
    confirm_password[strcspn(confirm_password, "\n")] = 0;

    if (strcmp(new_password, confirm_password) != 0) {
        printf("\nPasswords do not match.\n");
        return;
    }

    if (strcmp(new_username, admin.username) == 0) {
        printf("\nNew username cannot be the same as the old username.\n");
        return;
    }

    if (strcmp(new_password, admin.password) == 0) {
        printf("\nNew password cannot be the same as the old password.\n");
        return;
    }

    strcpy(admin.username, new_username);
    strcpy(admin.password, new_password);
}

int admin_login() {
    char input_username[20], input_password[20];
    int attempts = 3;

    while (attempts > 0) {
        printf("\n-----------------------------\n");
        printf("\tAdmin Login\n");
        printf("-----------------------------\n");
        printf("Username\n> ");
        fgets(input_username, sizeof(input_username), stdin);
        input_username[strcspn(input_username, "\r\n")] = 0;

        printf("Password\n> ");
        fgets(input_password, sizeof(input_password), stdin);
        input_password[strcspn(input_password, "\r\n")] = 0;

        if (strcmp(input_username, admin.username) == 0 && strcmp(input_password, admin.password) == 0) {
            printf("\nLogin successful. Welcome, %s.\n", admin.username);
            return 1;
        } else {
            attempts--;
            if (attempts > 0) {
                if (strcmp(input_username, admin.username) == 0 && strcmp(input_password, admin.password) != 0) {
                    printf("Invalid password. You have %d attempts remaining.\n", attempts);
                } else if (strcmp(input_username, admin.username) != 0 && strcmp(input_password, admin.password) == 0) {
                    printf("Invalid username. You have %d attempts remaining.\n", attempts);
                } else if (strcmp(input_username, admin.username) != 0 && strcmp(input_password, admin.password) != 0) {
                    printf("Invalid username and password. You have %d attempt(s) remaining\n", attempts);
                }
            } else {
                printf("\nYou have been locked out of the admin menu.\n");
                return 0;
            }
        }
    }
    return 0;
}