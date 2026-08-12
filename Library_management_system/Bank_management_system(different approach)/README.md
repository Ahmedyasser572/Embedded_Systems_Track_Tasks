# Smart Bank Management System

A simple console-based bank management system written in C. The application manages customer accounts, balances, deposits, withdrawals, and money transfers using a singly linked list.

## Features

- Add a customer
- View customer information
- Edit a customer's name and phone number
- Delete a customer account
- Deposit money
- Withdraw money
- Transfer money between customers
- Display all customers
- Save customer data to a file
- Load customer data when the application starts
- Colored and simple console menu

## Project Structure

| File or folder | Description |
|---|---|
| `bank_main.c` | Main menu and user interface |
| `bank_customer.c` | Customer-management implementations |
| `bank_customer.h` | Customer structure and function declarations |
| `customer.txt` | Persistent customer data |
| `output/` | Compiled application output |

## Technologies

- C programming language
- Structures and pointers
- Singly linked lists
- Dynamic memory allocation
- File handling
- Standard C libraries

## Customer Information

Each customer record contains:

- Name
- Phone number
- Customer ID
- Account balance
- Pointer to the next customer

## Build

Open PowerShell in the project directory and run:

```powershell
gcc -Wall -Wextra -g3 bank_main.c bank_customer.c -o output\bank_main.exe
```

Both source files must be compiled together because `bank_main.c` calls functions implemented in `bank_customer.c`.

## Run

After building, run the application with:

```powershell
.\output\bank_main.exe
```

The main menu provides these operations:

```text
1. Add customer
2. View customer
3. Edit customer
4. Delete customer
5. Deposit money
6. Withdraw money
7. Transfer money
8. Show all customers
0. Save and exit
```

## Data Persistence

Customer data is saved in `customer.txt` when the application exits. Existing data is loaded automatically when the application starts.

Run the program from the project directory so that `customer.txt` is found correctly.

> Names currently should not contain spaces because the data file uses spaces as separators.

## Validation

The system handles:

- Invalid customer IDs
- Invalid transaction amounts
- Insufficient account balance
- Transfers to the same account
- Missing data files
- Memory-allocation failures

## Example Data

```text
Ahmed 20000.00 01005224469 222658
Mohamed 20000.00 01064414572 222678
Hosam 25000.00 01065514572 222333
```

## Learning Objectives

This project demonstrates:

- Modular C programming
- Header files and function prototypes
- Linked-list insertion, searching, and deletion
- Dynamic memory management
- File reading and writing
- Basic banking transaction logic

## Future Improvements

- Support names containing spaces
- Prevent duplicate customer IDs
- Add transaction history
- Add account authentication
- Use a CSV or binary data format
- Add automated tests
- Add a graphical user interface

## Author
Ahmed Yasser

Developed as a C programming and data-structures project.
