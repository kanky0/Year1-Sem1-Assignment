# Hotel Management System

## Overview

The **Hotel Management System** is a command-line application designed to streamline hotel operations, including customer registration, room booking, employee management, and administrative tasks. The system uses modular programming to ensure efficiency, ease of maintenance, and scalability.

## Features

- **User Authentication**

  - Customers, Employees, and Administrators have distinct roles.
  - Secure login system for each user type.

- **Customer Management**

  - Register new customers.
  - View and edit customer information.
  - Book rooms and view billing details.

- **Accommodation Management**

  - View available rooms.
  - Book rooms and modify reservations.
  - Edit accommodation details (admin access only).

- **Employee Management**

  - Employee registration and login.
  - View assigned roles and responsibilities.

- **Admin Controls**

  - Manage room pricing and availability.
  - Update admin credentials securely.

- **Data Persistence**

  - Stores data in binary files (`customer.dat`, `employee.dat`, `accommodation.dat`, `admin.dat`) to retain information across sessions.

## File Structure

```
├── main.c                         # Main program file
├── accommodation_functions.c      # Functions for managing accommodations
├── customer_functions.c           # Functions for handling customer data
├── employee_functions.c           # Functions for managing employees
├── admin_functions.c              # Functions for administrative controls
├── utility_functions.c            # Input validation and string manipulation
├── input_output_info.c            # Data storage and retrieval functions
├── headers/                       # Header files for modularization
│   ├── accommodation_functions.h
│   ├── customer_functions.h
│   ├── employee_functions.h
│   ├── admin_functions.h
│   ├── utility_functions.h
│   ├── input_output_info.h
```

## Installation & Compilation

### **Requirements**

- **GCC Compiler** (for compiling C programs)
- Compatible with Windows/Linux/MacOS

### **Compiling the Program**

To compile the project, use the following command:

```sh
gcc -o hotel main.c accommodation_functions.c customer_functions.c employee_functions.c admin_functions.c utility_functions.c input_output_info.c -Wall
```

### **Running the Program**

After compilation, run the program using:

```sh
./hotel
```

## Usage

1. **Start the program**: Run `./hotel` to launch the system.
2. **Main Menu**: Choose to login, register, or exit.
3. **Login Options**: Select Customer, Employee, or Administrator login.
4. **Customer Features**: Book rooms, view/edit personal details, and check bills.
5. **Employee Features**: View assigned roles, customer list, and accommodations.
6. **Admin Features**: Modify room pricing, manage employees, and update admin credentials.

## Future Improvements

- Implement a **Graphical User Interface (GUI)** for better user experience.
- Use a **database** instead of binary files for scalable data management.
- Introduce **multi-language support** for accessibility.
- Add **mobile compatibility** for remote management.

## Contributors

- **Louis Chua Khai Yi**
- **Toh Bin Bin**
- **Tan Jing Hong**
- **Lieng Yu Hao**

## License

This project is open-source and can be modified and distributed under the MIT License.
