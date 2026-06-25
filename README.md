# Library Management System

A console-based Library Management System built in C++ using Object-Oriented Programming concepts. This project was developed as a group project and manages books across three university departments — IT, CS, and SE.

---

## Table of Contents

- [About](#about)
- [Features](#features)
- [Departments and Books](#departments-and-books)
- [How to Run](#how-to-run)
- [Project Structure](#project-structure)
- [How It Works](#how-it-works)
- [Input Validation](#input-validation)
- [Technologies Used](#technologies-used)
- [License](#license)

---

## About

This system simulates a real library where students can browse books, issue a book, and return it. The system manages books across three departments. All book data is saved to files so records are not lost when the program closes.

---

## Features

- View all books across all departments
- View only available (not issued) books per department
- Issue a book using student name, ID, and course code
- Return a book with due date tracking
- Fine calculation — 50 Rupees per day for late returns
- File persistence — book data is saved and loaded using text files
- Input validation — name, ID, course code, and date are all validated

---

## Departments and Books

The system manages 20 books per department across 3 departments:

| Department | Code Prefix | Example Books |
|---|---|---|
| Information Technology | IT101 - IT120 | Clean Coder, Data Structures, Linux Bible |
| Computer Science | CS101 - CS120 | Algorithms, AI: A Modern Approach, Database Systems |
| Software Engineering | SE101 - SE120 | Clean Code, Design Patterns, Refactoring |

---

## How to Run

### Visual Studio (Windows)
1. Download or clone the repository
2. Open `Library management system.sln` in Visual Studio
3. Press **Ctrl + F5** to build and run

### g++ (Linux / Mac / Windows with MinGW)
```bash
g++ -std=c++17 main.cpp function.cpp -o library
./library
```

---

## Project Structure

```
Library-management-system/
|
|-- Library management system/
|   |-- class.h          (All class definitions and validation functions)
|   |-- function.cpp     (All method implementations)
|   |-- main.cpp         (Entry point and menu logic)
|
|-- Library management system.sln   (Visual Studio solution file)
|-- .gitignore
|-- .gitattributes
|-- README.md
```

---

## How It Works

### Menu Options

```
========================================
|     LIBRARY MANAGEMENT SYSTEM MENU  |
========================================
| 1. Show Books List                  |
| 2. Show Available Books             |
| 3. Issue Book                       |
| 4. Return Book                      |
| 5. Clear Screen                     |
| 6. Exit                             |
========================================
```

### Issuing a Book
1. Student enters their name, 4-digit ID, and course code (e.g. CS101)
2. System searches for the book across all departments
3. Student enters the issue date manually
4. System calculates the due date (10 days from issue date)
5. Book is marked as issued

### Returning a Book
1. Student enters their 4-digit ID
2. System finds the issued book
3. Student enters the return date
4. System checks if the return is on time or late
5. If late — fine = number of late days x 50 Rupees
6. Book is marked as available again

### File Storage
Book data is saved to the following files automatically:
- `it_books.txt` — IT department books
- `cs_books.txt` — CS department books
- `se_books.txt` — SE department books

---

## Input Validation

The system validates all user input:

| Input | Rule |
|---|---|
| Name | Letters and spaces only |
| Student ID | Exactly 4 digits |
| Course Code | 2 uppercase letters + 3 digits (e.g. IT101) |
| Date | Between 1 and 31 |
| Month | Between 1 and 12 |
| Year | Between 2020 and 2024 |

---

## Technologies Used

- **Language:** C++
- **Concepts:** Object-Oriented Programming, Inheritance, Polymorphism, Abstract Classes
- **File Handling:** ifstream and ofstream for reading and writing book data
- **IDE:** Visual Studio 2022

---

## Authors

Developed as a group project.

---

## License

This project is licensed under the MIT License — see the [LICENSE](LICENSE) file for details.
