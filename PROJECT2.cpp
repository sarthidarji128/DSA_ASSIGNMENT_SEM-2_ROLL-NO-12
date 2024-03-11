#include <iostream>
#include <string>
using namespace std;


class Book {
    public:
    string title;
    string author;
    Book* next; 

    
    Book(string t, string a) {
        this->title=t;
        this->author=a;
        this->next=NULL;
    }
};


class Catalog {
    public:
    Book* head;
    
    Catalog() { 
        head = NULL;
    }

    
    void addBook(string t, string a) {
        Book* b = new Book(t, a);
        if (head == NULL) { 
            head = b;
        }
        else { 
            Book* curr = head; 
            while (curr->next != NULL) { 
                curr = curr->next; 
            }
            curr->next = b; 
        }
    }
    
    
    void removeBookByTitle(string t) {
        if (head == NULL) { 
            cout << "The catalog is empty." << endl;
            return;
        }
        Book* curr = head; 
        Book* prev = NULL; 
        while (curr != NULL) { 
            if (curr->title == t) {
                if (prev == NULL) { 
                    head = curr->next;
                }
                else { 
                    prev->next = curr->next;
                }
                cout << "Removed " << t << " by " << curr->author << " from the catalog." << endl;
                delete curr; 
                return;
            }
            prev = curr; 
            curr = curr->next;
        }
        cout << "No such book in the catalog." << endl;
    }


    void removeBookByAuthor(string a) {
        if (head == NULL) { 
            cout << "The catalog is empty." << endl;
            return;
        }
        Book* curr = head; 
        Book* prev = NULL; 
        bool found = false;
        while (curr != NULL) {
            if (curr->author == a) { 
                if (prev == NULL) { 
                    head = curr->next; 
                }
                else { 
                    prev->next = curr->next;
                }
                cout << "Removed " << curr->title << " by " << a << " from the catalog." << endl;
                Book* temp = curr;
                curr = curr->next;
                delete temp; 
                found = true; 
            }
            else { 
                prev = curr; 
                curr = curr->next;
            }
        }
        if (!found) { 
            cout << "No such author in the catalog." << endl;
        }
    }


    void searchBookByTitle(string t) {
        if (head == NULL) { 
            cout << "The catalog is empty." << endl;
            return;
        }
        Book* curr = head; 
        while (curr != NULL) { 
            if (curr->title == t) { 
                cout << "Found " << t << " by " << curr->author << " in the catalog." << endl;
                return;
            }
            curr = curr->next; 
        }
        cout << "No such book in the catalog." << endl;
    }


    void searchBookByAuthor(string a) {
        if (head == NULL) { 
            cout << "The catalog is empty." << endl;
            return;
        }
        Book* curr = head; 
        bool found = false; 
        while (curr != NULL) { 
            if (curr->author == a) { 
                cout << "Found " << curr->title << " by " << a << " in the catalog." << endl;
                found = true; 
            }
            curr = curr->next; 
        }
        if (!found) { 
            cout << "No such author in the catalog." << endl;
        }
    }

    
    void displayCatalog() {
        if (head == NULL) { 
            cout << "The catalog is empty." << endl;
            return;
        }
        cout << "The catalog contains:" << endl;
        Book* curr = head; 
        while (curr != NULL) { 
            cout << curr->title << " by " << curr->author << endl; 
            curr = curr->next; 
        }
    }
};

int main() {
    Catalog cat;
    cat.addBook("The Catcher in the Rye", "J.D. Salinger"); 
    cat.addBook("To Kill a Mockingbird", "Harper Lee");  
    cat.displayCatalog(); 
    return 0;
}
