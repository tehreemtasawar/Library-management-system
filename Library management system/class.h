#include <iostream>
#include<fstream>
#include <string>
#include <cctype>  // For isalpha function
#include <limits>
using namespace std;
static bool isInteger(const string& str) {
    // Check if the string is a valid integer
    for (char c : str) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}
// Function to check if a name is valid (only contains alphabetic characters)
static bool isValidName(const string& str) {
    for (char c : str) {
        if (!isalpha(c) && c != ' ') {  // Allow spaces in between words
            return false;
        }
    }
    return true;
}
static bool isValidCourseCode(const string& str) {
    // Check if the length of the course code is 5 characters
    if (str.length() != 5) {
        return false;
    }

    // First two characters should be uppercase letters (A-Z)
    if (!isalpha(str[0]) || !isalpha(str[1]) || !isupper(str[0]) || !isupper(str[1])) {
        return false;
    }

    // Last three characters should be digits (0-9)
    if (!isdigit(str[2]) || !isdigit(str[3]) || !isdigit(str[4])) {
        return false;
    }

    return true;
}

// Function to check if the ID is valid (4 digits and no alphabetic characters)
static bool isValidId(const string& str) {
    if (str.length() != 4) {
        return false;  // ID must be exactly 4 characters long
    }
    for (char c : str) {
        if (!isdigit(c)) {  // Check if each character is a digit
            return false;  // Return false if there's a non-digit character
        }
    }
    return true;  // Return true if all characters are digits and length is 4
}

class Books {
public:
    string title;
    string courseCode;
    string authorName;
    bool isIssued;  // Flag to track if the book is issued

    // Constructor to initialize book details
    Books(string c = "", string t = "", string a = "", bool issued = false)
        : courseCode(c), title(t), authorName(a), isIssued(issued) {}

    // Function to display book details
    void display()const;
};

// Abstract Department base class
class Department {
public:
    Books books[20];  // Array to store books for the department
    int bookCount;

public:
    Department();

    virtual void addBooks() = 0;  // Pure virtual function to add books to the department
    void displayAvailableBooks() const;

    void display() const;
    void saveToFile(const string& filename) const;

    void loadFromFile(const string& filename);

};
// IT Department class inheriting from Department
class ITDepartment : public Department {
public:
    ITDepartment();
    void addBooks()override;
};

// CS Department class inheriting from Department
class CSDepartment : public Department {
public:
    CSDepartment();

    void addBooks()override;
};

// SE Department class inheriting from Department
class SEDepartment : public Department {
public:
    SEDepartment();
    void addBooks() override;
};
class date
{
public:
    int issuedate;
    int issuemonth;
    int issueyear;
    int duedate;
    int duemonth;
    int dueyear;
    date();

    // Function to calculate the due date
    void calculateDueDate();
};

class Student {
private:
    string name;
    int id = 0;
    date D;
    string title;
    string courseCode;
    int issuedBookId = 0;  // Store the ID of the issued book
public:

    void issue(Books books[], int bookCount);

    void returnbook(Books books[], int bookCount);
    bool isFirstTime = true;
    // Global variable to track the first time the menu is shown
    void displayMenu()const;

};