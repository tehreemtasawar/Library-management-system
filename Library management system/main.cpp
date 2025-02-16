#include "class.h"
#include <iostream>
#include <string>
#include <fstream>
int main()
{



    cout << "=====================================================================";
    cout << "\n              Welcome to the Library Management System\n";
    cout << "=====================================================================";
    ITDepartment itDept;
    CSDepartment csDept;
    SEDepartment seDept;
    Student student;

    itDept.saveToFile("it_books.txt");
    itDept.loadFromFile("it_books.txt");

    csDept.saveToFile("cs_books.txt");
    csDept.loadFromFile("cs_books.txt");

    seDept.saveToFile("se_books.txt");
    seDept.loadFromFile("se_books.txt");

    int choice;
    string input;

    // Create a combined array of books from all departments
    Books allBooks[60]; // Assuming a maximum of 20 books per department
    int totalBooks = 0;

    // Add IT Department books
    for (int i = 0; i < itDept.bookCount; i++) {
        allBooks[totalBooks++] = itDept.books[i];
    }

    // Add CS Department books
    for (int i = 0; i < csDept.bookCount; i++) {
        allBooks[totalBooks++] = csDept.books[i];
    }

    // Add SE Department books
    for (int i = 0; i < seDept.bookCount; i++) {
        allBooks[totalBooks++] = seDept.books[i];
    }

    do {
        student.displayMenu();
        cout << "\n Enter your choice :";
        getline(cin, input);
        while (!isInteger(input)) {
            cout << "\n Error: Please enter only an integer for the choice. Try again: ";
            getline(cin, input);
        }
        choice = stoi(input);

        switch (choice)
        {
        case 1:

        {
            if (student.isFirstTime)
            {
                cout << "__________________________________________________________________________";
                cout << "\nIT Department Books:\n";
                cout << "__________________________________________________________________________";
                itDept.display();  // Display all books for IT Department
                cout << "__________________________________________________________________________";
                cout << "\nComputer Science Department Books:\n";
                cout << "__________________________________________________________________________";
                csDept.display();
                cout << "__________________________________________________________________________";
                cout << "\nSoftware Engineering Department Books:\n";
                cout << "__________________________________________________________________________";
                seDept.display();
            }
            break;
        }
        case 2:
        {
            int availableDeptChoice;
            string deptInput; // Use a string to read input

            cout << "\n Select Department for Available Books: ";

            cout << "\n 1. IT Department";
            cout << "\n 2. CS Department";
            cout << "\n 3. SE Department";

            while (true) {
                cout << "\nEnter your choice: ";
                getline(cin, deptInput); // Read input as a string

                // Check if the input is an integer
                if (isInteger(deptInput)) {
                    availableDeptChoice = stoi(deptInput); // Convert to integer
                    break; // Exit loop if valid
                }
                else {
                    cout << "Invalid input! Please enter only an integer." << endl;
                }
            }

            // Display available books based on the selected department
            switch (availableDeptChoice) {
            case 1:
                itDept.displayAvailableBooks(); // Show available books in IT Department
                break;
            case 2:
                csDept.displayAvailableBooks(); // Show available books in CS Department
                break;
            case 3:
                seDept.displayAvailableBooks(); // Show available books in SE Department
                break;
            default:
                cout << "\n Invalid choice! Please enter a valid number from the menu.";
                break;
            }
            break;
        }

        case 3: {
            student.issue(allBooks, totalBooks);
            for (int i = 0; i < totalBooks; i++) {
                if (i < itDept.bookCount) {
                    itDept.books[i] = allBooks[i];
                }
                else if (i < itDept.bookCount + csDept.bookCount) {
                    csDept.books[i - itDept.bookCount] = allBooks[i];
                }
                else {
                    seDept.books[i - itDept.bookCount - csDept.bookCount] = allBooks[i];
                }
            }
            break;
        }

        case 4: {
            student.returnbook(allBooks, totalBooks);
            for (int i = 0; i < totalBooks; i++) {
                if (i < itDept.bookCount) {
                    itDept.books[i] = allBooks[i];
                }
                else if (i < itDept.bookCount + csDept.bookCount) {
                    csDept.books[i - itDept.bookCount] = allBooks[i];
                }
                else {
                    seDept.books[i - itDept.bookCount - csDept.bookCount] = allBooks[i];
                }
            }
            break;
        }

              //case 3:
              //{
              //    student.issue(allBooks, totalBooks); // Pass combined books
              //    break;
              //}
              //case 4:
              //{
              //    student.returnbook(allBooks, totalBooks); // Pass combined books
              //    break;
              //}

        case 5:
        {
            system("cls");
            break;
        }
        case 6:
        {
            cout << "\n Exiting system... Goodbye!";
            break;
        }

        default:
        {
            cout << "\n Invalid choice! Please enter a valid number from the menu.";
            break;
        }
        }
    } while (choice != 6);
    system("pause");
    return 0;
}