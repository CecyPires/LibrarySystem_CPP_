#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    string isbn;
    bool available;

public:
    void setBookDetails(string t, string a, string i) {
        title = t;
        author = a;
        isbn = i;
        available = true;
    }

    void displayBookDetails() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "Available: " << (available ? "Yes" : "No") << endl;
    }

    string getISBN() { return isbn; }

    bool isAvailable() { return available; }

    void borrowBook() {
        if (available) {
            available = false;
            cout << "Book borrowed successfully.\n";
        }
        else {
            cout << "Book is not available.\n";
        }
    }

    void returnBook() {
        available = true;
    }
};

int main() {
    Book myBook;
    myBook.setBookDetails("1984", "George Orwell", "1234567890");
    myBook.displayBookDetails();
    myBook.borrowBook();
    myBook.displayBookDetails();
    myBook.returnBook();
    myBook.displayBookDetails();

    return 0;
}
