#ifndef ADMINISTRATOR_FUNCTIONS_H
#define ADMINISTRATOR_FUNCTIONS_H

// Admin structure
typedef struct {
    char username[20];
    char password[20];
} Admin;

extern Admin admin;

void update_admin_credentials();
int admin_login();

#endif