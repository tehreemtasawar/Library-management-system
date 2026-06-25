#include "class.h"

// ─── Books ────────────────────────────────────────────────────────────────────

void Books::display() const {
    cout << courseCode << "\t\t" << title << "\t\t\t" << authorName << "\n";
}

// ─── Department ───────────────────────────────────────────────────────────────

void Department::display() const {
    cout << "\nS.No\tCourse Code\tBook Name\t\t\t\tAuthor Name\n";
    cout << "-------------------------------------------------------------------------\n";
    for (int i = 0; i < bookCount; ++i) {
        cout << (i + 1) << ".\t";
        books[i].display();
    }
}

void Department::displayAvailableBooks() const {
    bool anyAvailable = false;
    cout << "\nS.No\tCourse Code\tBook Name\t\t\t\tAuthor Name\n";
    cout << "-------------------------------------------------------------------------\n";
    for (int i = 0; i < bookCount; ++i) {
        if (!books[i].isIssued) {
            cout << (i + 1) << ".\t";
            books[i].display();
            anyAvailable = true;
        }
    }
    if (!anyAvailable)
        cout << " No books currently available in this department.\n";
}

void Department::searchBooks(const string& query) const {
    bool found = false;
    string lowerQuery = query;
    for (char& c : lowerQuery) c = tolower(c);

    cout << "\n Search results for \"" << query << "\" in " << getName() << ":\n";
    cout << "-------------------------------------------------------------------------\n";
    for (int i = 0; i < bookCount; ++i) {
        string lowerTitle = books[i].title;
        string lowerAuthor = books[i].authorName;
        string lowerCode = books[i].courseCode;

        for (char& c : lowerTitle)  c = tolower(c);
        for (char& c : lowerAuthor) c = tolower(c);
        for (char& c : lowerCode)   c = tolower(c);

        if (lowerTitle.find(lowerQuery) != string::npos ||
            lowerAuthor.find(lowerQuery) != string::npos ||
            lowerCode.find(lowerQuery) != string::npos) {
            cout << (i + 1) << ".\t";
            books[i].display();
            cout << "   Status: " << (books[i].isIssued ? "[ISSUED]" : "[AVAILABLE]") << "\n";
            found = true;
        }
    }
    if (!found)
        cout << " No matching books found.\n";
}

void Department::saveToFile(const string& filename) const {
    ofstream file(filename);
    if (!file) { cerr << " Error: Could not open " << filename << " for writing.\n"; return; }
    file << bookCount << "\n";
    for (int i = 0; i < bookCount; ++i) {
        file << books[i].courseCode << "\n"
            << books[i].title << "\n"
            << books[i].authorName << "\n"
            << books[i].isIssued << "\n";
    }
}

void Department::loadFromFile(const string& filename) {
    ifstream file(filename);
    if (!file) { cerr << " Error: Could not open " << filename << " for reading.\n"; return; }
    file >> bookCount;
    file.ignore();
    for (int i = 0; i < bookCount; ++i) {
        getline(file, books[i].courseCode);
        getline(file, books[i].title);
        getline(file, books[i].authorName);
        file >> books[i].isIssued;
        file.ignore();
    }
}

// ─── IT Department Books ──────────────────────────────────────────────────────

void ITDepartment::addBooks() {
    books[0] = Books("IT101", "Clean Coder", "Robert C. Martin");
    books[1] = Books("IT102", "AI", "S. Russell, P. Norvig");
    books[2] = Books("IT103", "Big Data", "V. Mayer-Schonberger, K. Cukier");
    books[3] = Books("IT104", "Operating Systems", "A. Silberschatz");
    books[4] = Books("IT105", "Learning Python", "M. Lutz");
    books[5] = Books("IT106", "SQL for Web", "J. R. Vacca");
    books[6] = Books("IT107", "JavaScript", "D. Crockford");
    books[7] = Books("IT108", "Linux Bible", "C. Negus");
    books[8] = Books("IT109", "Computer Networks", "A. S. Tanenbaum");
    books[9] = Books("IT110", "Data Science", "J. Grus");
    books[10] = Books("IT111", "HTML & CSS", "J. Duckett");
    books[11] = Books("IT112", "Web Development", "B. W. Kernighan");
    books[12] = Books("IT113", "C Programming", "B. W. Kernighan, D. Ritchie");
    books[13] = Books("IT114", "Swift Programming", "M. Mathias, J. Gallagher");
    books[14] = Books("IT115", "Java 8", "R. G. Urma");
    books[15] = Books("IT116", "Web APIs", "K. Rother");
    books[16] = Books("IT117", "PHP & MySQL", "L. Welling, L. Thomson");
    books[17] = Books("IT118", "Java 7", "J. Gosling, J. Joy");
    books[18] = Books("IT119", "Android Programming", "B. Phillips, C. Stewart");
    books[19] = Books("IT120", "Data Structures", "A. K. Sharma");
    bookCount = 20;
}

// ─── CS Department Books ──────────────────────────────────────────────────────

void CSDepartment::addBooks() {
    books[0] = Books("CS101", "Algorithms", "Thomas H. Cormen, Charles E. Leiserson");
    books[1] = Books("CS102", "Art of Programming", "Donald E. Knuth");
    books[2] = Books("CS103", "Discrete Mathematics", "Kenneth H. Rosen");
    books[3] = Books("CS104", "Compilers", "Alfred V. Aho, Monica S. Lam");
    books[4] = Books("CS105", "Artificial Intelligence", "Stuart Russell, Peter Norvig");
    books[5] = Books("CS106", "Programming Pearls", "Jon Bentley");
    books[6] = Books("CS107", "Structure of Computer Programs", "Harold Abelson, Gerald Jay Sussman");
    books[7] = Books("CS108", "Operating Systems", "Abraham Silberschatz");
    books[8] = Books("CS109", "Compiler Design", "Alfred V. Aho, Jeffrey D. Ullman");
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

// ─── SE Department Books ──────────────────────────────────────────────────────

void SEDepartment::addBooks() {
    // Fixed: sequential order, corrected typos, added missing authors
    books[0] = Books("SE101", "Code Complete", "Steve McConnell");
    books[1] = Books("SE102", "Clean Code", "Robert C. Martin");       // Fixed "Rober Engineering"
    books[2] = Books("SE103", "Refactoring", "Martin Fowler");
    books[3] = Books("SE104", "Design Patterns", "Erich Gamma, Richard Helm, Ralph Johnson, John Vlissides");
    books[4] = Books("SE105", "Pragmatic Programmer", "Andrew Hunt, David Thomas");
    books[5] = Books("SE106", "Agile Software Development", "Robert C. Martin");
    books[6] = Books("SE107", "Mythical Man-Month", "Frederick P. Brooks");
    books[7] = Books("SE108", "Software Estimation", "Mike Cohn");              // Fixed truncated title
    books[8] = Books("SE109", "Continuous Delivery", "David Farley");
    books[9] = Books("SE110", "Test-Driven Development", "Kent Beck");
    books[10] = Books("SE111", "Extreme Programming", "Kent Beck");
    books[11] = Books("SE112", "Software Requirements", "Karl Wiegers");
    books[12] = Books("SE113", "Managing Software", "Robert T. Futrell");
    books[13] = Books("SE114", "Clean Coder", "Robert C. Martin");
    books[14] = Books("SE115", "Software Testing", "Glenford J. Myers");
    books[15] = Books("SE116", "Enterprise Patterns", "Martin Fowler");
    books[16] = Books("SE117", "Agile Estimating", "Mike Cohn");              // Fixed "Estimatingt C. Martin"
    books[17] = Books("SE118", "Domain-Driven Design", "Eric Evans");
    books[18] = Books("SE119", "Software Architecture", "Mary Shaw");
    books[19] = Books("SE120", "Microservices", "Sam Newman");
    bookCount = 20;
}

// ─── Student ──────────────────────────────────────────────────────────────────

void Student::issue(Department* depts[], int deptCount) {
    // FIXED: check hasIssuedBook instead of old issuedBookId sentinel
    if (hasIssuedBook) {
        cout << "\n You already have a book issued. Please return it before issuing a new one.\n";
        return;
    }

    cout << "\n--- Issue Book ---\n";

    // Get student name
    do {
        cout << " Name: ";
        getline(cin, name);
        if (!isValidName(name))
            cout << " Error: Name should only contain letters and spaces. Try again.\n";
    } while (!isValidName(name));

    // Get student ID
    string idInput;
    do {
        cout << " Student ID (4 digits): ";
        getline(cin, idInput);
        if (isValidId(idInput)) { id = stoi(idInput); break; }
        cout << " Error: ID must be exactly 4 digits. Try again.\n";
    } while (true);

    // Get course code
    string code;
    do {
        cout << " Course Code (e.g. CS101): ";
        getline(cin, code);
        for (char& c : code) c = toupper(c);
        if (!isValidCourseCode(code))
            cout << " Error: Must be 2 uppercase letters + 3 digits (e.g. IT103). Try again.\n";
    } while (!isValidCourseCode(code));

    // Search all departments for the book
    for (int d = 0; d < deptCount; d++) {
        for (int i = 0; i < depts[d]->getBookCount(); i++) {
            Books& b = depts[d]->getBook(i);
            if (b.courseCode == code && !b.isIssued) {
                cout << "\n ==================================\n";
                cout << " Book Found!\n";
                cout << " Title:       " << b.title << "\n";
                cout << " Course Code: " << b.courseCode << "\n";
                cout << " Author:      " << b.authorName << "\n";
                cout << " ==================================\n";

                // FIXED: issue date is set automatically using system clock
                issueDate.setToToday();
                issueDate.calculateDueDate(14);   // 14-day loan period

                b.isIssued = true;
                issuedCourseCode = code;
                hasIssuedBook = true;

                cout << "\n Book issued successfully!\n";
                cout << " Issue Date: "; issueDate.printIssue(); cout << "\n";
                cout << " Due Date:   "; issueDate.printDue();   cout << "\n";
                return;
            }
        }
    }

    cout << "\n Book not found or already issued.\n";
}

void Student::returnBook(Department* depts[], int deptCount) {
    cout << "\n--- Return Book ---\n";

    // FIXED: use hasIssuedBook flag — reliable check
    if (!hasIssuedBook) {
        cout << "\n No book is currently issued to you.\n";
        return;
    }

    // Verify student ID
    string idInput;
    do {
        cout << " Enter your Student ID (4 digits): ";
        getline(cin, idInput);
        if (isValidId(idInput)) {
            if (stoi(idInput) != id) {
                cout << " Error: ID does not match the record. Try again.\n";
                continue;
            }
            break;
        }
        cout << " Error: ID must be exactly 4 digits.\n";
    } while (true);

    // Find the issued book across all departments
    for (int d = 0; d < deptCount; d++) {
        for (int i = 0; i < depts[d]->getBookCount(); i++) {
            Books& b = depts[d]->getBook(i);
            if (b.courseCode == issuedCourseCode && b.isIssued) {
                cout << "\n Book: " << b.title << " (" << b.courseCode << ")\n";
                cout << " Issue Date: "; issueDate.printIssue(); cout << "\n";
                cout << " Due Date:   "; issueDate.printDue();   cout << "\n";

                // FIXED: use getValidatedInt helper — no copy-paste date loops
                int curYear = getCurrentYear();
                int rDay, rMonth, rYear;

                while (true) {
                    rDay = getValidatedInt(" Return Day   (1-31):  ", 1, 31);
                    rMonth = getValidatedInt(" Return Month (1-12):  ", 1, 12);
                    rYear = getValidatedInt(
                        " Return Year  (" + to_string(curYear - 1) + "-" + to_string(curYear + 1) + "): ",
                        curYear - 1, curYear + 1
                    );

                    if (issueDate.isBeforeIssue(rDay, rMonth, rYear)) {
                        cout << " Error: Return date cannot be before the issue date. Try again.\n";
                    }
                    else {
                        break;
                    }
                }

                // FIXED: proper fine calculation
                int lateDays = issueDate.calcLateDays(rDay, rMonth, rYear);
                if (lateDays > 0) {
                    int fine = lateDays * 50;
                    cout << "\n Book returned late by " << lateDays << " day(s).\n";
                    cout << " Fine: " << fine << " Rupees (50/day)\n";
                }
                else {
                    cout << "\n Book returned on time. No fine.\n";
                }

                b.isIssued = false;
                hasIssuedBook = false;
                issuedCourseCode = "";
                cout << " Book returned successfully!\n";
                return;
            }
        }
    }

    cout << "\n Could not locate the issued book in records.\n";
}

void Student::saveToFile(const string& filename) const {
    ofstream file(filename);
    if (!file) { cerr << " Error: Could not open " << filename << "\n"; return; }
    file << hasIssuedBook << "\n"
        << id << "\n"
        << name << "\n"
        << issuedCourseCode << "\n";
    if (hasIssuedBook)
        issueDate.saveToFile(file);
}

void Student::loadFromFile(const string& filename) {
    ifstream file(filename);
    if (!file) return;   // No save file yet — that's fine on first run
    file >> hasIssuedBook;
    file >> id;
    file.ignore();
    getline(file, name);
    getline(file, issuedCourseCode);
    if (hasIssuedBook)
        issueDate.loadFromFile(file);
}

void Student::displayMenu() const {
    cout << "\n\t========================================\n";
    cout << "\t|     LIBRARY MANAGEMENT SYSTEM        |\n";
    cout << "\t========================================\n";
    cout << "\t| 1. Show All Books                    |\n";
    cout << "\t| 2. Show Available Books              |\n";
    cout << "\t| 3. Search Books                      |\n";
    cout << "\t| 4. Issue Book                        |\n";
    cout << "\t| 5. Return Book                       |\n";
    cout << "\t| 6. Clear Screen                      |\n";
    cout << "\t| 7. Exit                              |\n";
    cout << "\t========================================\n";
    if (hasIssuedBook)
        cout << "\t  [Book currently issued: " << issuedCourseCode << "]\n";
}

// ─── Library ──────────────────────────────────────────────────────────────────

Library::Library() {
    depts[0] = &itDept;
    depts[1] = &csDept;
    depts[2] = &seDept;
}

void Library::loadAll() {
    itDept.loadFromFile("it_books.txt");
    csDept.loadFromFile("cs_books.txt");
    seDept.loadFromFile("se_books.txt");
    student.loadFromFile("student_session.txt");
}

void Library::saveAll() {
    itDept.saveToFile("it_books.txt");
    csDept.saveToFile("cs_books.txt");
    seDept.saveToFile("se_books.txt");
    student.saveToFile("student_session.txt");
}

void Library::showAllBooks() const {
    for (int d = 0; d < DEPT_COUNT; d++) {
        cout << "\n" << string(73, '-') << "\n";
        cout << " " << depts[d]->getName() << "\n";
        cout << string(73, '-') << "\n";
        depts[d]->display();
    }
}

void Library::showAvailableBooks() const {
    cout << "\n Select Department:\n";
    for (int d = 0; d < DEPT_COUNT; d++)
        cout << " " << (d + 1) << ". " << depts[d]->getName() << "\n";

    int choice = getValidatedInt(" Your choice: ", 1, DEPT_COUNT);
    depts[choice - 1]->displayAvailableBooks();
}

void Library::searchAllBooks() const {
    cout << "\n Enter search term (title, author, or course code): ";
    string query;
    getline(cin, query);
    if (query.empty()) { cout << " Search term cannot be empty.\n"; return; }
    for (int d = 0; d < DEPT_COUNT; d++)
        depts[d]->searchBooks(query);
}

void Library::run() {
    cout << "\n=====================================================================\n";
    cout << "         Welcome to the Library Management System\n";
    cout << "=====================================================================\n";

    // Save default data on first run, then load saved state
    itDept.saveToFile("it_books.txt");
    csDept.saveToFile("cs_books.txt");
    seDept.saveToFile("se_books.txt");
    loadAll();

    string input;
    int choice;

    do {
        student.displayMenu();
        cout << "\n Enter your choice: ";
        getline(cin, input);

        while (!isInteger(input) || input.empty()) {
            cout << " Error: Please enter a valid menu number: ";
            getline(cin, input);
        }
        choice = stoi(input);

        switch (choice) {
        case 1:
            showAllBooks();
            break;
        case 2:
            showAvailableBooks();
            break;
        case 3:
            searchAllBooks();
            break;
        case 4:
            student.issue(depts, DEPT_COUNT);
            saveAll();
            break;
        case 5:
            student.returnBook(depts, DEPT_COUNT);
            saveAll();
            break;
        case 6:
#ifdef _WIN32
            system("cls");
#else
            system("clear");
#endif
            break;
        case 7:
            cout << "\n Saving data and exiting... Goodbye!\n";
            saveAll();
            break;
        default:
            cout << "\n Invalid choice. Please select a number from the menu.\n";
        }
    } while (choice != 7);
}
