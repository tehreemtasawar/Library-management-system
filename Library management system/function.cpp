#include "class.h"
void Books::display() const
{
    cout << courseCode << "\t\t" << title << "\t\t\t" << "\t" << authorName << endl;
}
Department::Department()
{
    bookCount = 0;
}
void Department::displayAvailableBooks() const {
    cout << "\nS.No \tCourse Code \tBook Name \t\t\t\t   Author Name\n";
    for (int i = 0; i < bookCount; ++i) {
        if (!books[i].isIssued) {  // Only display books that are not issued
            cout << (i + 1) << ". \t";
            books[i].display();
        }
    }
}
void Department::display() const {
    cout << "\nS.No \tCourse Code \tBook Name \t\t\t\tAuthor Name\n";
    for (int i = 0; i < bookCount; ++i) {
        cout << (i + 1) << ". \t";
        books[i].display();
    }
}
void Department::saveToFile(const string& filename) const {
    ofstream file(filename);
    if (!file) {
        cerr << "Error opening file for writing!" << endl;
        return;
    }
    file << bookCount << endl;
    for (int i = 0; i < bookCount; ++i) {
        file << books[i].courseCode << endl
            << books[i].title << endl
            << books[i].authorName << endl
            << books[i].isIssued << endl;
    }
    file.close();

}
void Department::loadFromFile(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error opening file for reading!" << endl;
        return;
    }
    file >> bookCount;
    file.ignore(); // Ignore the newline character
    for (int i = 0; i < bookCount; ++i) {
        getline(file, books[i].courseCode);
        getline(file, books[i].title);
        getline(file, books[i].authorName);
        file >> books[i].isIssued;
        file.ignore(); // Ignore the newline character
    }
    file.close();

}
ITDepartment::ITDepartment() {
    addBooks();  // Add books for IT Department
}
void ITDepartment::addBooks() {
    books[0] = Books("IT101", "Clean Coder", "R.C. Martin");
    books[1] = Books("IT102", "AI", "   S.Russell, P. Norvig");
    books[2] = Books("IT103", "Big Data", "V. Mayer-Schonberger, K. Cukier");
    books[3] = Books("IT104", "Operating Systems", "A. Silberschatz");
    books[4] = Books("IT105", "Learning Python", "M. Lutz");
    books[5] = Books("IT106", "SQL for Web", "J. R. Vacca");
    books[6] = Books("IT107", "JavaScript", "D. Crockford");
    books[7] = Books("IT108", "Linux Bible", "C. Negus");
    books[8] = Books("IT109", "Computer Networks", "A. S. Tanenbaum");
    books[9] = Books("IT110", "Data Science", "J. Grus");
    books[10] = Books("IT111", "HTML & CSS", "J. Duckett");
    books[11] = Books("IT112", "Web Dev", "    B.W.Kernighan");
    books[12] = Books("IT113", "C Programming", "B. W. Kernighan, D. Ritchie");
    books[13] = Books("IT114", "Swift Programming", "M. Mathias, J. Gallagher");
    books[14] = Books("IT115", "Java 8", "R. G. Urma");
    books[15] = Books("IT116", "Web APIs", "K. Rother");
    books[16] = Books("IT117", "PHP & MySQL", "L. Welling, L. Thomson");
    books[17] = Books("IT118", "Java 7", "J. Gosling, J. Joy");
    books[18] = Books("IT119", "Android Prog", "B. Phillips, C. Stewart");
    books[19] = Books("IT120", "Data Structures", "A. K. Sharma");
    bookCount = 20;  // Set the book count correctly
}
CSDepartment::CSDepartment() {
    addBooks();  // Add books for CS Department
}
void CSDepartment::addBooks() {
    books[0] = Books("CS101", "Algorithms", "Thomas H. Cormen, Charles E. Leiserson");
    books[1] = Books("CS102", "Art of Programming", "Donald E. Knuth");
    books[2] = Books("CS103", "Discrete Math", "Kenneth H. Rosen");
    books[3] = Books("CS104", "Compilers", "Alfred V. Aho, Monica S. Lam");
    books[4] = Books("CS105", "Artificial Intelligence", "Stuart Russell, Peter Norvig");
    books[5] = Books("CS106", "Programming Pearls", "Jon Bentley");
    books[6] = Books("CS107", "Structure of Computer Programs", "Harold Abelson, Gerald Jay Sussman");
    books[7] = Books("CS108", "Operating Systems", "Abraham Silberschatz");
    books[8] = Books("CS109", "Compilers Design", "Alfred V. Aho, Jeffrey D. Ullman");
    books[9] = Books("CS110", "Pragmatic Programmer", "Andrew Hunt, David Thomas");
    books[10] = Books("CS111", "Database Systems", "Abraham Silberschatz");
    books[11] = Books("CS112", "Software Engineering", "Ian Sommerville");
    books[12] = Books("CS113", "Algorithms", "Robert Sedgewick");
    books[13] = Books("CS114", "C Programming", "Brian W. Kernighan, Dennis M. Ritchie");
    books[14] = Books("CS115", "Learning Python", "Mark Lutz");
    books[15] = Books("CS116", "C++ Programming", "Bjarne Stroustrup");
    books[16] = Books("CS117", "AI: A Modern Approach", "Stuart Russell, Peter Norvig");
    books[17] = Books("CS118", "Computer Organization", "Carl Hamacher");
    books[18] = Books("CS119", "Compiler Principles", "Alfred V. Aho, Jeffrey D. Ullman");
    books[19] = Books("CS120", "Data Science from Scratch", "Joel Grus");
    bookCount = 20;
}
SEDepartment::SEDepartment() {
    addBooks();  // Add books for SE Department
}
void SEDepartment::addBooks() {
    books[0] = Books("SE101", "Code Complete", "Steve McConnell");
    books[1] = Books("SE102", "Clean Code", "Rober Engineering");
    books[8] = Books("SE109", "Continuous Delivery", "David Farley");
    books[9] = Books("SE110", "Test-Driven Development", "Kent Beck");
    books[10] = Books("SE111", "Extreme Programming", "Kent Beck");
    books[11] = Books("SE112", "Software Requirements", "Karl Wiegers");
    books[12] = Books("SE113", "Managing Software", "Robert T. Futrell");
    books[13] = Books("SE114", "Clean Coder", "Robert C. Martin");
    books[14] = Books("SE115", "Software Testing", "Glenford J. Myers");
    books[15] = Books("SE116", "Enterprise Patterns", "Martin Fowler");
    books[16] = Books("SE117", "Agile Estimatingt C. Martin");
    books[2] = Books("SE103", "Refactoring", "Martin Fowler");
    books[3] = Books("SE104", "Design Patterns", "Erich Gamma, Richard Helm, Ralph Johnson, John Vlissides");
    books[4] = Books("SE105", "Pragmatic Programmer", "Andrew Hunt, David Thomas");
    books[5] = Books("SE106", "Agile Software Development", "Robert C. Martin");
    books[6] = Books("SE107", "Mythical Man-Month", "Frederick P. Brooks");
    books[7] = Books("SE108", "Software ", "Mike Cohn");
    books[17] = Books("SE118", "Domain-Driven Design", "Eric Evans");
    books[18] = Books("SE119", "Software Architecture", "Mary Shaw");
    books[19] = Books("SE120", "Microservices", "Sam Newman");
    bookCount = 20;
}
date::date()
{
    issuedate = 0;
    issuemonth = 0;
    issueyear = 0;
    duedate = 0;
    duemonth = 0;
    dueyear = 0;
}
// Function to calculate the due date
void date::calculateDueDate() {
    // Add 10 days to the issue date
    duedate = issuedate + 10;
    duemonth = issuemonth;
    dueyear = issueyear;

    // Handle month overflow based on number of days in each month
    if (duedate > 30) {
        duedate -= 30;
        duemonth += 1;
        if (duemonth > 12) {
            duemonth = 1;
            dueyear += 1;
        }
    }
}
void Student::issue(Books books[], int bookCount) {
    if (issuedBookId)
    {
        cout << "\n You already have a book Issued . Please return it before issuing a new one ! \n";
        return;
    }

    cout << "\n For Issue Book enter details  ";

    do {
        cout << "\n Name: ";
        getline(cin, name);
        if (!isValidName(name)) {
            cout << "\n Error: Name should only contain alphabets and spaces. Please try again.";
        }
    } while (!isValidName(name));

    do {
        cout << "\n ID: ";
        string idInput;
        getline(cin, idInput);  // Read the input as a string

        if (isValidId(idInput)) {
            id = stoi(idInput);  // Convert to integer if valid
            break;  // Exit loop if valid
        }
        else {
            cout << "\n Error: ID should be exactly 4 digits and contain only numbers. Please try again.";
        }
    } while (true);  // Keep asking until valid input is provided

    do {
        cout << "\n Course Code :";
        getline(cin, courseCode);
        if (!isValidCourseCode(courseCode)) {
            cout << "\n Error: Course code should follow the format: <2 uppercase letters> followed by <3 digits>. Please try again.";
        }
    } while (!isValidCourseCode(courseCode));

    bool bookfound = false;  // Flag to track if the book is found

    for (int i = 0; i < bookCount; i++) {
        if (books[i].courseCode == courseCode && !books[i].isIssued) {
            bookfound = true;
            courseCode = books[i].courseCode;
            cout << "==================================";
            cout << "\nBook Found: " << books[i].title;
            cout << "\nCourse Code: " << books[i].courseCode;
            cout << "\nAuthor Name: " << books[i].authorName;
            cout << "\n==================================";
            cout << "\n Enter :";
            // Input validation for date, month, and year
            do {
                cout << "\n Issue Date: ";
                string dateInput;
                getline(cin, dateInput);
                if (isInteger(dateInput)) {
                    D.issuedate = stoi(dateInput);
                    if (D.issuedate >= 1 && D.issuedate <= 31) {
                        break;  // Exit loop if valid date
                    }
                    else {
                        cout << "\n Error: Date should be between 1 and 31. Please try again.";
                    }
                }
                else {
                    cout << "\n Error: Invalid input. Please enter a valid integer for the date.";
                }
            } while (true);

            do {
                cout << "\n Issue Month :";
                string monthInput;
                getline(cin, monthInput);
                if (isInteger(monthInput)) {
                    D.issuemonth = stoi(monthInput);
                    if (D.issuemonth >= 1 && D.issuemonth <= 12) {
                        break;  // Exit loop if valid month
                    }
                    else {
                        cout << "\n Error: Month should be between 1 and 12. Please try again.";
                    }
                }
                else {
                    cout << "\n Error: Invalid input. Please enter a valid integer for the month.";
                }
            } while (true);

            do {
                cout << "\n Issue Year :";
                string yearInput;
                getline(cin, yearInput);
                if (isInteger(yearInput)) {
                    D.issueyear = stoi(yearInput);
                    if (D.issueyear >= 2020 && D.issueyear <= 2024) {
                        break;  // Exit loop if valid year
                    }
                    else {
                        cout << "\n Error: Year should be between 2020 and 2024. Please try again.";
                    }
                }
                else {
                    cout << "\n Error: Invalid input. Please enter a valid integer for the year.";
                }
            } while (true);
            D.calculateDueDate();
            cout << "\n Book Issued Successfully !";
            cout << "\nDue Date: " << D.duedate << "/" << D.duemonth << "/" << D.dueyear;
            books[i].isIssued = true;
            this->issuedBookId = id; // Store the ID of the student who issued the book

            break;
        }
    }

    if (!bookfound) {
        cout << "\nBook not found or already issued!";
    }
}
void Student::returnbook(Books books[], int bookCount) {
    cout << "\n For return enter details  ";

    // Check if any book is issued
    if (issuedBookId == -1) {
        cout << "\n No books have been issued. Please issue a book first.";
        return;  // Exit the function if no books are issued
    }

    string idInput;
    // Ask for ID only
    do {
        cout << "\n ID: ";
        getline(cin, idInput);  // Read the input as a string

        if (isValidId(idInput)) {
            id = stoi(idInput);  // Convert to integer if valid
            break;  // Exit loop if valid
        }
        else {
            cout << "\n Error: ID should be exactly 4 digits and contain only numbers. Please try again.";
        }
    } while (true);  // Keep asking until valid input is provided

    bool bookFound = false;
    for (int i = 0; i < bookCount; i++) {
        if (books[i].isIssued && issuedBookId == id) { // Check if the ID matches
            // Display the book information
            cout << "\nBook Found: " << books[i].title;
            cout << "\nCourse Code: " << books[i].courseCode;
            cout << "\nAuthor Name: " << books[i].authorName;

            // Display the issue date and due date
            cout << "\n Issue Date: " << D.issuedate << "/" << D.issuemonth << "/" << D.issueyear;
            cout << "\n Due Date: " << D.duedate << "/" << D.duemonth << "/" << D.dueyear;

            // Asking user for return date
            int returnDate, returnMonth, returnYear;
            string dateInput, monthInput, yearInput;

            // Validate return date input
            do {
                cout << "\n Return Date: ";
                getline(cin, dateInput);
                if (isInteger(dateInput)) {
                    returnDate = stoi(dateInput);
                    if (returnDate >= 1 && returnDate <= 31) {
                        break;  // Exit loop if valid date
                    }
                    else {
                        cout << "\n Error: Return Date should be between 1 and 31. Please try again.";
                    }
                }
                else {
                    cout << "\n Error: Invalid input. Please enter a valid integer for the return date.";
                }
            } while (true);

            // Validate return month input
            do {
                cout << "\n Return Month: ";
                getline(cin, monthInput);
                if (isInteger(monthInput)) {
                    returnMonth = stoi(monthInput);
                    if (returnMonth >= 1 && returnMonth <= 12) {
                        break;  // Exit loop if valid month
                    }
                    else {
                        cout << "\n Error: Return Month should be between 1 and 12. Please try again.";
                    }
                }
                else {
                    cout << "\n Error: Invalid input. Please enter a valid integer for the return month.";
                }
            } while (true);

            // Validate return year input
            do {
                cout << "\n Return Year: ";
                getline(cin, yearInput);
                if (isInteger(yearInput)) {
                    returnYear = stoi(yearInput);
                    if (returnYear >= 2020 && returnYear <= 2025) {
                        break;  // Exit loop if valid year
                    }
                    else {
                        cout << "\n Error: Return Year should be between 2020 and 2025. Please try again.";
                    }
                }
                else {
                    cout << "\n Error: Invalid input. Please enter a valid integer for the return year.";
                }
            } while (true);

            // Check if the return date is earlier than the issue date
            while (returnYear < D.issueyear ||
                (returnYear == D.issueyear && returnMonth < D.issuemonth) ||
                (returnYear == D.issueyear && returnMonth == D.issuemonth && returnDate < D.issuedate)) {
                    {
                        cout << "\n Error: Return date cannot be earlier than the issue date.";
                        do {
                            cout << "\n Return Date: ";
                            getline(cin, dateInput);
                            if (isInteger(dateInput)) {
                                returnDate = stoi(dateInput);
                                if (returnDate >= 1 && returnDate <= 31) {
                                    break;  // Exit loop if valid date
                                }
                                else {
                                    cout << "\n Error: Return Date should be between 1 and 31. Please try again.";
                                }
                            }
                            else {
                                cout << "\n Error: Invalid input. Please enter a valid integer for the return date.";
                            }
                        } while (true);

                        // Validate return month input
                        do {
                            cout << "\n Return Month: ";
                            getline(cin, monthInput);
                            if (isInteger(monthInput)) {
                                returnMonth = stoi(monthInput);
                                if (returnMonth >= 1 && returnMonth <= 12) {
                                    break;  // Exit loop if valid month
                                }
                                else {
                                    cout << "\n Error: Return Month should be between 1 and 12. Please try again.";
                                }
                            }
                            else {
                                cout << "\n Error: Invalid input. Please enter a valid integer for the return month.";
                            }
                        } while (true);

                        // Validate return year input
                        do {
                            cout << "\n Return Year: ";
                            getline(cin, yearInput);
                            if (isInteger(yearInput)) {
                                returnYear = stoi(yearInput);
                                if (returnYear >= 2020 && returnYear <= 2025) {
                                    break;  // Exit loop if valid year
                                }
                                else {
                                    cout << "\n Error: Return Year should be between 2020 and 2025. Please try again.";
                                }
                            }
                            else {
                                cout << "\n Error: Invalid input. Please enter a valid integer for the return year.";
                            }
                        } while (true);
                        return;  // Exit the function if return date is earlier than issue date
                    }
            }

            // Calculate the fine if the book is returned late
            int fine = 0;
            if (returnYear > D.dueyear || (returnYear == D.dueyear && returnMonth > D.duemonth) ||
                (returnYear == D.dueyear && returnMonth == D.duemonth && returnDate > D.duedate)) {
                // Calculate number of late days
                int lateDays = (returnYear - D.dueyear) * 365 + (returnMonth - D.duemonth) * 30 + (returnDate - D.duedate);
                if (lateDays > 0) {
                    fine = lateDays * 50;  // Fine is 50 rupees per day
                    cout << "\n Book returned late! Fine: " << fine << " Rupees";
                }
            }

            // Mark the book as available
            books[i].isIssued = false;
            cout << "\n Book returned successfully!";
            this->issuedBookId = 0;
            bookFound = true;
            break;  // Exit the loop after processing the found book
        }
    }

    // Check if no book was found after the loop
    if (!bookFound) {
        cout << "\n No book found for the given ID or the book was not issued!";
    }
}

void Student::displayMenu()const
{


    // Menu items inside the box
    if (isFirstTime) {
        cout << "\n\n\t========================================";
        cout << "\n\t|     LIBRARY MANAGEMENT SYSTEM MENU    |";
        cout << "\n\t========================================";
        cout << "\n\t| 1. Show Books List                    |";
    }
    cout << "\n\t| 2. Show Available Books               |";
    cout << "\n\t| 3. Issue Book                         |";
    cout << "\n\t| 4. Return Book                        |";
    cout << "\n\t| 5. Clear screen                       |";
    cout << "\n\t| 6. Exit                               |";
    cout << "\n\t========================================";
}