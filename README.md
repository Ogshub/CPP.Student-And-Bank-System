# Management System (Bank & Student)

This project is a simple Management System implemented in C++ that includes two modules: Bank System and Student System. It allows users to interact with a bank account and a student record, where they can deposit/withdraw money, and view student details with grades, marks, and percentages.

## About
This project was developed as a practice to enhance C++ programming skills, focusing on classes, functions, loops, conditionals, and user input handling. The system has two main modules:
1. **Bank System**: Allows depositing and withdrawing money, and displaying account details.
2. **Student System**: Manages student details including roll number, marks, percentage, and grade.

## Features
- **Bank System**:
  - Deposit money to your account.
  - Withdraw money from your account, with checks for insufficient funds.
  - Print account details including name, account number, and balance.
- **Student System**:
  - Enter student details including name, roll number, and marks for various papers.
  - Calculate percentage and assign grades (O, A, B, C, D, F).
  - Print student details including marks, percentage, and grade.

## Requirements
- C++11 or later
- A C++ compiler (G++, Clang, etc.)

## How to Use
1. When the program starts, you will be presented with a menu to choose between the **Bank System** or **Student System**.
2. In the **Bank System**, you can deposit or withdraw money and print account details.
3. In the **Student System**, you can enter student details, calculate marks, and view the final grade.

### Example Output
```text
Welcome to Management System.
Choose an option:
(b) Bank system.
(s) Student system.
(e) Exit
Your choice: b

Welcome to the Bank!
Enter your name: John Doe
Enter account number: 12345
Initial balance set to 0.

Choose an option:
(d) Deposit
(w) Withdraw
(p) Print account details
(e) Exit
Your choice: d

Enter money to deposit: 500
Money deposited: 500$
...
