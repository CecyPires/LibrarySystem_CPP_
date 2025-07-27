#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    string isbn;
    bool available;
    string dateAdd;

public:
    void setBookDetails(string t, string a, string i, bool avail, string d) {
        title = t;
        author = a;
        isbn = i;
        available = avail;
        dateAdd = d;
    }

    void displayBookDetails() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "Available: " << (available ? "Yes" : "No") << endl;
        cout << "Date Added: " << dateAdd << endl;
        cout << "-----------------------------" << endl;
    }

    string getISBN() {
        return isbn;
    }

    bool isAvailable() {
        return available;
    }

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
    Book library[5];
    library[0].setBookDetails("The Alchemist", "Paulo Coelho", "111", true, "2022-01-01");
    library[1].setBookDetails("1984", "George Orwell", "222", true, "2021-10-10");
    library[2].setBookDetails("Clean Code", "Robert C. Martin", "333", true, "2020-06-20");
    library[3].setBookDetails("Brave New World", "Aldous Huxley", "444", true, "2023-03-15");
    library[4].setBookDetails("Sapiens", "Yuval Noah Harari", "555", false, "2019-11-05");

    string inputISBN;

    while (true) {
        cout << "\nEnter ISBN to borrow (0 to exit): ";
        cin >> inputISBN;

        if (inputISBN == "0") break;

        bool found = false;
        for (int i = 0; i < 5; i++) {
            if (library[i].getISBN() == inputISBN) {
                found = true;
                if (library[i].isAvailable()) {
                    library[i].borrowBook();
                }
                else {
                    cout << "Sorry, this book is currently not available.\n";
                }
                break;
            }
        }

        if (!found) {
            cout << "ISBN not found.\n";
        }
    }

    cout << "\nFinal status of books:\n";
    for (int i = 0; i < 5; i++) {
        library[i].displayBookDetails();
    }

    return 0;
}
