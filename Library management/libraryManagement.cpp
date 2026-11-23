#include <bits/stdc++.h>
using namespace std;

struct Book {
    int id;
    string name;
    bool issued;
    Book* next;
};

// Add Book
void addBook(Book*& head, int id, string name) {
    Book* newBook = new Book{id, name, false, NULL};

    if (head == NULL) {
        head = newBook;
    } else {
        Book* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newBook;
    }
    cout << "Book Added Successfully "<<endl;
}

// Issue Book
void issueBook(Book* head, int id) {
    while (head != NULL) {
        if (head->id == id) {
            if (!head->issued) {
                head->issued = true;
                cout << "Book Issued "<<endl;
            } else {
                cout << "Book Already Issued "<<endl;
            }
            return;
        }
        head = head->next;
    }
    cout << "Book Not Found "<<endl;
}

// Return Book
void returnBook(Book* head, int id) {
    while (head != NULL) {
        if (head->id == id) {
            if (head->issued) {
                head->issued = false;
                cout << "Book Returned "<<endl;
            } else {
                cout << "Book was not issued "<<endl;
            }
            return;
        }
        head = head->next;
    }
    cout << "Book Not Found "<<endl;
}

// Search Book
void searchBook(Book* head, int id) {
    while (head != NULL) {
        if (head->id == id) {
            cout << "B<<endlook Found "<<endl;
            cout << "ID: " << head->id << endl;
            cout << "Name: " << head->name << endl;
            cout << "Status: " << (head->issued ? "Issued" : "Available") << endl;
            return;
        }
        head = head->next;
    }
    cout << "Book Not Found "<<endl;
}

// Display All Books
void displayBooks(Book* head) {
    if (head == NULL) {
        cout << "No Books Available "<<endl;
        return;
    }

    cout << "-<<endl-- Library Books ---"<<endl;
    while (head != NULL) {
        cout << "ID: " << head->id
             << " | Name: " << head->name
             << " | Status: " << (head->issued ? "Issued" : "Available") 
             << endl;
        head = head->next;
    }
}

// Delete Book 
void deleteBook(Book*& head, int id) {
    Book* temp = head;
    Book* prev = NULL;

    while (temp != NULL) {
        if (temp->id == id) {
            if (prev == NULL) {
                head = temp->next;
            } else {
                prev->next = temp->next;
            }
            delete temp;
            cout << "Book Deleted "<<endl;
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    cout << "Book Not Found "<<endl;
}

// Main Function
int main() {
    Book* head = NULL;
    int choice, id;
    string name;

    while (true) {
        cout << "=<<endl==== Library Menu ====="<<endl;
        cout << "1. Add Book"<<endl;
        cout << "2. Issue Book"<<endl;
        cout << "3. Return Book"<<endl;
        cout << "4. Search Book"<<endl;
        cout << "5. Display Books"<<endl;
        cout << "6. Delete Book"<<endl;
        cout << "7. Exit"<<endl;
        cout << "Enter choice: ";
        cin >> choice;

        cin.ignore(); // clear buffer

        switch (choice) {
            case 1:
                cout << "Enter Book ID: ";
                cin >> id;
                cin.ignore();
                cout << "Enter Book Name: ";
                getline(cin, name);
                addBook(head, id, name);
                break;

            case 2:
                cout << "Enter Book ID: ";
                cin >> id;
                issueBook(head, id);
                break;

            case 3:
                cout << "Enter Book ID: ";
                cin >> id;
                returnBook(head, id);
                break;

            case 4:
                cout << "Enter Book ID: ";
                cin >> id;
                searchBook(head, id);
                break;

            case 5:
                displayBooks(head);
                break;

            case 6:
                cout << "Enter Book ID: ";
                cin >> id;
                deleteBook(head, id);
                break;

            case 7:
                cout << "Exiting Program "<<endl;
                return 0;

            default:
                cout << "Invalid Choice "<<endl;
        }
    }
}