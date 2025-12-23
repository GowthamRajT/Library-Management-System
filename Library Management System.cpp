#include <iostream>
#include <map>
using namespace std;

// Book class
class Book {
public:
    int id;
    string title;
    string author;

    Book() {}

    Book(int id, string title, string author) {
        this->id = id;
        this->title = title;
        this->author = author;
    }
};

// Library class
class Library {
private:
    map<int, Book> books;

public:
    void addBook() {
        int id;
        string title, author;

        cout << "Enter Book ID: ";
        cin >> id;
        cin.ignore();

        cout << "Enter Book Title: ";
        getline(cin, title);

        cout << "Enter Author Name: ";
        getline(cin, author);

        if (books.find(id) != books.end()) {
            cout << "Book ID already exists!\n";
            return;
        }

        books[id] = Book(id, title, author);
        cout << "Book added successfully!\n";
    }

    void removeBook() {
        int id;
        cout << "Enter Book ID to remove: ";
        cin >> id;

        if (books.erase(id))
            cout << "Book removed successfully!\n";
        else
            cout << "Book not found!\n";
    }

    void searchBook() {
        int id;
        cout << "Enter Book ID to search: ";
        cin >> id;

        if (books.find(id) != books.end()) {
            Book b = books[id];
            cout << "\nBook Found:\n";
            cout << "ID: " << b.id << "\n";
            cout << "Title: " << b.title << "\n";
            cout << "Author: " << b.author << "\n";
        } else {
            cout << "Book not found!\n";
        }
    }

    void displayBooks() {
        if (books.empty()) {
            cout << "No books available.\n";
            return;
        }

        cout << "\nLibrary Records:\n";
        for (auto &pair : books) {
            cout << "ID: " << pair.second.id
                 << ", Title: " << pair.second.title
                 << ", Author: " << pair.second.author << "\n";
        }
    }
};

int main() {
    Library library;
    int choice;

    do {
        cout << "\n===== Library Management System =====\n";
        cout << "1. Add Book\n";
        cout << "2. Remove Book\n";
        cout << "3. Search Book\n";
        cout << "4. Display All Books\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            library.addBook();
            break;
        case 2:
            library.removeBook();
            break;
        case 3:
            library.searchBook();
            break;
        case 4:
            library.displayBooks();
            break;
        case 5:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
