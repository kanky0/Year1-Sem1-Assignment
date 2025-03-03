#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "input_output_info.h"

void save_all_data() {
    // Save customer data
    FILE *customerFile = fopen("customer.dat", "wb");
    if (customerFile) {
        fwrite(&customer_count, sizeof(int), 1, customerFile);
        fwrite(customers, sizeof(Customer), customer_count, customerFile);
        fclose(customerFile);
    } else {
        printf("Error opening customer.dat for writing.\n");
    }

    // Save employee data
    FILE *employeeFile = fopen("employee.dat", "wb");
    if (employeeFile) {
        fwrite(&num_employee, sizeof(int), 1, employeeFile);
        fwrite(employee, sizeof(Employee), num_employee, employeeFile);
        fclose(employeeFile);
    } else {
        printf("Error opening employee.dat for writing.\n");
    }

    // Save accommodation data
    FILE *accommodationFile = fopen("accommodation.dat", "wb");
    if (accommodationFile) {
        fwrite(accommodation, sizeof(accommodation), 1, accommodationFile);
        fwrite(&room1, sizeof(Room), 1, accommodationFile);
        fwrite(&room2, sizeof(Room), 1, accommodationFile);
        fwrite(&room3, sizeof(Room), 1, accommodationFile);
        fwrite(&room4, sizeof(Room), 1, accommodationFile);
        fclose(accommodationFile);
    } else {
        printf("Error opening accommodation.dat for writing.\n");
    }

    // Save admin data
    FILE *adminFile = fopen("admin.dat", "wb");
    if (adminFile) {
        fwrite(&admin, sizeof(Admin), 1, adminFile);
        fclose(adminFile);
    } else {
        printf("Error opening admin.dat for writing.\n");
    }
}

void load_all_data() {
    // Load customer data
    FILE *customerFile = fopen("customer.dat", "rb");
    if (customerFile) {
        fread(&customer_count, sizeof(int), 1, customerFile);
        fread(customers, sizeof(Customer), customer_count, customerFile);
        fclose(customerFile);
    }

    // Load employee data
    FILE *employeeFile = fopen("employee.dat", "rb");
    if (employeeFile) {
        fread(&num_employee, sizeof(int), 1, employeeFile);
        fread(employee, sizeof(Employee), num_employee, employeeFile);
        fclose(employeeFile);
    }

    // Load accommodation data
    FILE *accommodationFile = fopen("accommodation.dat", "rb");
    if (accommodationFile) {
        fread(accommodation, sizeof(accommodation), 1, accommodationFile);
        fread(&room1, sizeof(Room), 1, accommodationFile);
        fread(&room2, sizeof(Room), 1, accommodationFile);
        fread(&room3, sizeof(Room), 1, accommodationFile);
        fread(&room4, sizeof(Room), 1, accommodationFile);
        fclose(accommodationFile);
    }

    // Load admin data
    FILE *adminFile = fopen("admin.dat", "rb");
    if (adminFile) {
        fread(&admin, sizeof(Admin), 1, adminFile);
        fclose(adminFile);
    }
}