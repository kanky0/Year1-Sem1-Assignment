#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "customer_functions.h"
#include "utility_functions.h"

Customer customers[150]; // Can store up to 150 customer's information
int customer_count = 0; // To track the current number of registered customer

// View Customer's Info
void view_customer_info() {
    char search_name[30];
    int found = 0;

    if (customer_count == 0) {
        printf("\nNo customers registered.\n");
        return;
    }

    printf("\nPlease Enter Customer Full Name to Search: ");
    fgets(search_name, sizeof(search_name), stdin);
    search_name[strcspn(search_name, "\n")] = 0; // To remove the newline character

    for (int i = 0; i < customer_count; i++) {
        if (strcasecmp(customers[i].name, search_name) == 0) { // Customer's name might be entered in different case
            printf("\n-----------------------------\n");
            printf("    Customer Information\n");
            printf("-----------------------------\n");
            printf("Name\t     : %s\n", customers[i].name);
            printf("Gender\t     : %s\n", customers[i].gender);
            printf("Age\t     : %d\n", customers[i].age);
            printf("Phone Number : %s\n", customers[i].phone_num);
            printf("Nationality  : %s\n", customers[i].nationality);
            printf("IC\t     : %s\n", customers[i].ic);
            printf("Passport     : %s\n", customers[i].passport);
            found = 1;
            break;
        }
    }

    // Customer name not found or unregistered customer name
    if (!found) {
        printf("\nCustomer Not Found, Please Try Again.\n");
    }
}


// View List of Customer 
void view_list_of_customer() {

    // No registered customer 
    if (customer_count == 0) {
        printf("\nPlease register at least one customer.\n");
        return; 
    }

    // At least one customer registered
    printf("\n-----------------------------\n");
    printf("\tCustomer List\n");
    printf("-----------------------------\n");
    for (int i = 0; i < customer_count; i++) {
        printf("Customer %d\t:\n", i + 1); // To ensure the numbering start from 1 instead of 0
        printf("Name\t\t: %s\n", customers[i].name);
        printf("Gender\t\t: %s\n", customers[i].gender);
        printf("Age\t\t: %d\n", customers[i].age);
        printf("Phone Number\t: %s\n", customers[i].phone_num);
        printf("Nationality\t: %s\n", customers[i].nationality);
        printf("IC\t\t: %s\n", customers[i].ic);
        printf("Passport\t: %s\n", customers[i].passport);
        printf("\n");
    }
}

// Complete customer's information
int register_customer() {
    if (customer_count >= 150) {
        printf("\nCustomer list is full.\n"); // Customer's information storage is full
        return -1;
    }

    printf("\nEnter Customer Information.\n");

    printf("Name\t\t: ");
    fgets(customers[customer_count].name, sizeof(customers[customer_count].name), stdin);
    customers[customer_count].name[strcspn(customers[customer_count].name, "\n")] = 0;
    capitalize_word(customers[customer_count].name);

    // To ensure customer's gender is valid
    do {
        printf("Gender (M/F)\t: ");
        fgets(customers[customer_count].gender, sizeof(customers[customer_count].gender), stdin);
        customers[customer_count].gender[strcspn(customers[customer_count].gender, "\n")] = 0;

        // Take the first character of input and converts to lowercase
        char first_char = tolower(customers[customer_count].gender[0]);

        if (first_char == 'm') {
            strcpy(customers[customer_count].gender, "male");
            capitalize_word(customers[customer_count].gender);
            break;
        } else if (first_char == 'f') {
            strcpy(customers[customer_count].gender, "female");
            capitalize_word(customers[customer_count].gender);
            break;
        } else {
            printf("\nInvalid gender. Please enter 'M' for Male or 'F' for Female.\n\n");
        }
    } while (1);

    do {
        printf("Age\t\t: ");
        customers[customer_count].age = inputValidationNum();
        if (customers[customer_count].age < 1 || customers[customer_count].age > 120) {
            printf("\nInvalid age. Please enter a number between 1 and 120.\n\n");
        }
    } while (customers[customer_count].age < 1 || customers[customer_count].age > 120);

    do {
        printf("Phone Number\t: ");
        fgets(customers[customer_count].phone_num, sizeof(customers[customer_count].phone_num), stdin);
        customers[customer_count].phone_num[strcspn(customers[customer_count].phone_num, "\n")] = 0;

        int length = strlen(customers[customer_count].phone_num);

        int is_numeric = 1;
        for (int i = 0; i < length; i++) {
            if (!isdigit(customers[customer_count].phone_num[i])) {
                is_numeric = 0;
                break;
            }
        }

        if (is_numeric && (length == 10 || length == 11)) {
            break;
        } else {
            printf("\nInvalid phone number. Please enter a 10 or 11-digit phone number.\n\n");
        }
    } while (1);
    
    do {
        printf("Nationality\t: ");
        fgets(customers[customer_count].nationality, sizeof(customers[customer_count].nationality), stdin);
        customers[customer_count].nationality[strcspn(customers[customer_count].nationality, "\n")] = 0;
        
        int length = strlen(customers[customer_count].nationality);

        int is_alphabetic = 1;
        for (int i = 0; i < length; i++) {
            if (!isalpha(customers[customer_count].nationality[i])) {
                is_alphabetic = 0;
                break;
            }
        }

        if (is_alphabetic && (length >= 2 && length <= 30)) {
            capitalize_word(customers[customer_count].nationality);
            break;
        } else {
            printf("\nInvalid nationality. Please enter a valid name.\n\n");
        }
    } while (1);

    if (strcasecmp(customers[customer_count].nationality, "Malaysian") == 0) {
        do {
            printf("IC\t\t: ");
            fgets(customers[customer_count].ic, sizeof(customers[customer_count].ic), stdin);
            customers[customer_count].ic[strcspn(customers[customer_count].ic, "\n")] = 0; // Remove newline

            // Check if the length is exactly 12
            int length = strlen(customers[customer_count].ic);
            if (length != 12) {
            printf("\nInvalid IC length. Please enter exactly 12 digits.\n\n");
            continue;
            }

            // Check if all characters are numeric
            int is_numeric = 1;
            for (int i = 0; i < length; i++) {
                if (!isdigit(customers[customer_count].ic[i])) {
                    is_numeric = 0;
                    break;
                }
            }
            if (!is_numeric) {
                printf("\nInvalid IC. Please enter numeric values only.\n\n");
                continue;
            }

            // Extract and validate the date
            char temp[3];
            
            // Extract first two characters for year
            memcpy(temp, customers[customer_count].ic, 2);
            temp[2] = '\0';
            int year = atoi(temp);
            // Extract next two characters for month
            memcpy(temp, customers[customer_count].ic + 2, 2);
            temp[2] = '\0';
            int month = atoi(temp);
            // Extract next two characters for day
            memcpy(temp, customers[customer_count].ic + 4, 2);
            temp[2] = '\0';
            int day = atoi(temp);

            if (month < 1 || month > 12) {
                printf("\nInvalid month in IC. Must be between 01 and 12.\n\n");
                continue;
            }

            int max_days = 31;
            if (month == 4 || month == 6 || month == 9 || month == 11) {
                max_days = 30;
            } else if (month == 2) {
                // Handle February (leap year logic)
                if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
                    max_days = 29;
                } else {
                    max_days = 28;
                }
            }

            if (day < 1 || day > max_days) {
                printf("\nInvalid day in IC. The day must be between 01 and %d for month %02d.\n\n", max_days, month);
                continue;
            }

            // Check State Code
            memcpy(temp, customers[customer_count].ic + 6, 2);
            temp[2] = '\0';
            int state_code = atoi(temp);
            if (state_code < 1 || state_code > 9) {
                printf("Invalid state code in IC. It must be between 01 and 09.\n\n");
                continue;
            }

            // Check the last 4 digits
            char last_four[5];
            memcpy(last_four, customers[customer_count].ic + 8, 4);
            last_four[4] = '\0';
            int last_four_number = atoi(last_four);
            if (last_four_number < 0 || last_four_number > 9999) {
                printf("Invalid last 4 digits in IC. It must be between 0000 and 9999.\n\n");
                continue;
            }
            break;

        } while (1);
    } else {
        do {
            printf("Passport\t: ");
            fgets(customers[customer_count].passport, sizeof(customers[customer_count].passport), stdin);
            customers[customer_count].passport[strcspn(customers[customer_count].passport, "\n")] = 0; // Remove newline

            // Check if the length is valid
            int length = strlen(customers[customer_count].passport);
            if (length < 6 || length > 9) {
                printf("\nInvalid passport length. It should be between 6 and 9 characters.\n\n");
                continue;
            }

            // Check if all characters are alphanumeric
            int is_alphanumeric = 1;
            for (int i = 0; i < length; i++) {
                if (!isalnum(customers[customer_count].passport[i])) {
                    is_alphanumeric = 0;
                    break;
                }
            }

            if (!is_alphanumeric) {
                printf("\nInvalid passport. Please enter only letters and numbers.\n\n");
                continue;
            }

            // Convert letters to uppercase
            for (int i = 0; i < length; i++) {
                customers[customer_count].passport[i] = toupper(customers[customer_count].passport[i]);
            }
            break;

        } while (1);
    }

    customer_count++;
    printf("\nCustomer registered successfully!\n");

    return 1;
}

void edit_customer_info(char name[]) {
    int customer_index = -1;
    int choice;

    // Find customer by name
    for (int i = 0; i < customer_count; i++) {
        if (strcasecmp(customers[i].name, name) == 0) {
            customer_index = i;
            break;
        }
    }

    if (customer_index == -1) {
        printf("\nCustomer not found.\n");
        return;
    }

    while (1) {
        printf("\n-----------------------------\n");
        printf("  Edit Customer Information\n");
        printf("-----------------------------\n");
        printf("1. Name\n2. Gender\n3. Age\n4. Phone Number\n5. Nationality\n6. IC\n7. Passport\n8. Back\n> ");
        choice = inputValidationNum();
        
        switch (choice) {
            case 1: // edit name
                do {
                    printf("\nCurrent name: %s\n", customers[customer_index].name);
                    printf("Enter new name\n> ");
                    fgets(customers[customer_index].name, sizeof(customers[customer_index].name), stdin);
                    customers[customer_index].name[strcspn(customers[customer_index].name, "\n")] = 0;
                    capitalize_word(customers[customer_index].name);

                    if (strcasecmp(customers[customer_index].name, name) == 0) {
                        printf("\nYou entered the same name as before. Please enter a different name.\n");
                    } else {
                        printf("\nName updated successfully\n");
                        break;
                    }
                } while (1);
                break;

            case 2: // edit gender
                do {
                    printf("\nCurrent gender: %s\n", customers[customer_index].gender);
                    printf("Enter new gender (M/F)\n> ");
                    fgets(customers[customer_index].gender, sizeof(customers[customer_index].gender), stdin);
                    char first_char = tolower(customers[customer_index].gender[0]);

                    if (first_char == 'm') {
                        if (strcasecmp(customers[customer_index].gender, "male") == 0) {
                            printf("\nYou entered the same gender as before. Please enter a different gender.\n");
                        } else {
                            strcpy(customers[customer_index].gender, "male");
                            printf("Gender updated successfully to Male\n");
                            break;
                        }
                    } else if (first_char == 'f') {
                        if (strcasecmp(customers[customer_index].gender, "female") == 0) {
                            printf("\nYou entered the same gender as before. Please enter a different gender.\n");
                        } else {
                            strcpy(customers[customer_index].gender, "female");
                            printf("Gender updated successfully to Female\n");
                            break;
                        }
                    } else {
                        printf("\nInvalid gender. Please enter 'M' for Male or 'F' for Female.\n");
                    }
                } while (1);
                break;

            case 3: // edit age
                do {
                    printf("\nCurrent age: %d\n", customers[customer_index].age);
                    printf("Enter new age\n> ");
                    int new_age = inputValidationNum();
                    if (new_age == customers[customer_index].age) {
                        printf("\nYou entered the same age as before. Please enter a different age.\n");
                    } else if (new_age < 1 || new_age > 120) {
                        printf("\nInvalid age. Please enter a number between 1 and 120.\n");
                    } else {
                        customers[customer_index].age = new_age;
                        printf("Age updated successfully\n");
                        break;
                    }
                } while (1);
                break;

            case 4: // edit phone number
                do {
                    char original_phone_num[15];
                    strcpy(original_phone_num, customers[customer_index].phone_num);

                    printf("\nCurrent phone number: %s\n", customers[customer_index].phone_num);
                    printf("Enter new phone number\n> ");
                    fgets(customers[customer_index].phone_num, sizeof(customers[customer_index].phone_num), stdin);
                    customers[customer_index].phone_num[strcspn(customers[customer_index].phone_num, "\n")] = 0;

                    if (strcmp(customers[customer_index].phone_num, original_phone_num) == 0) {
                        printf("\nYou entered the same phone number as before. Please enter a different phone number.\n");
                        continue;
                    }

                    if (strlen(customers[customer_index].phone_num) == 10 || strlen(customers[customer_index].phone_num) == 11) {
                        printf("\nPhone number updated successfully\n");
                        break;
                    } else {
                        printf("\nInvalid phone number. Please enter a 10 or 11-digit phone number.\n");
                    }
                } while (1);
                break;
                
            case 5: // edit nationality
                do {
                    printf("\nCurrent nationality: %s\n", customers[customer_index].nationality);
                    printf("Enter new nationality\n> ");
                    fgets(customers[customer_index].nationality, sizeof(customers[customer_index].nationality), stdin);
                    customers[customer_index].nationality[strcspn(customers[customer_index].nationality, "\n")] = 0;
                    
                    int length = strlen(customers[customer_index].nationality);
                    int is_alphabetic = 1;

                    for (int i = 0; i < length; i++) {
                        if (!isalpha(customers[customer_index].nationality[i])) {
                            is_alphabetic = 0;
                            break;
                        }
                    }

                    if (!is_alphabetic || length < 2 || length > 30) {
                        printf("\nInvalid nationality. Please enter a valid name.\n");
                    } else {
                        capitalize_word(customers[customer_index].nationality);
                        printf("Nationality updated successfully\n");
                        break;
                    }
                } while (1);
                break;

            case 6: // edit IC
                if (strcasecmp(customers[customer_index].nationality, "Malaysian") == 0) {
                    do {
                        printf("\nCurrent IC: %s\n", customers[customer_index].ic);
                        printf("Enter new IC\n> ");
                        fgets(customers[customer_index].ic, sizeof(customers[customer_index].ic), stdin);
                        customers[customer_index].ic[strcspn(customers[customer_index].ic, "\n")] = 0;

                        if (strcmp(customers[customer_index].ic, customers[customer_index].ic) == 0) {
                            printf("\nYou entered the same IC as before. Please enter a different IC.\n");
                        } else {
                            printf("\nIC updated successfully.\n");
                            break;
                        }
                    } while (1);
                } else {
                    printf("\nIC is only required for Malaysian customers.\n");
                }
                break;
                
            case 7: // edit passport
                if (strcasecmp(customers[customer_index].nationality, "Malaysian") != 0) {
                    do {
                        printf("\nCurrent passport: %s\n", customers[customer_index].passport);
                        printf("Enter new passport\n> ");
                        fgets(customers[customer_index].passport, sizeof(customers[customer_index].passport), stdin);
                        customers[customer_index].passport[strcspn(customers[customer_index].passport, "\n")] = 0;

                        if (strcmp(customers[customer_index].passport, customers[customer_index].passport) == 0) {
                            printf("\nYou entered the same passport as before. Please enter a different passport.\n");
                        } else {
                            printf("\nPassport updated successfully.\n");
                            break;
                        }
                    } while (1);
                } else {
                    printf("\nPassport is only required for non-Malaysian customers.\n");
                }
                break; 
            
            case 8:
                return;

            default:
                printf("\nInvalid choice. Please select a number from 1 to 8.\n");
        }
    }
}