# Book Store Management System

Creating a **console-based Book Store Management System in C++** is an excellent real-world project that will help you apply **Logic**, **Object-Oriented Programming (OOP)**, and **Data Structures & Algorithms (DSA)**. Here's a clear and detailed breakdown of what you should use and a code example to get started.

---

## ✅ **Techniques to Use**

### 🔹 1. **Logic**

* Menu-driven interface (clear, user-friendly)
* Input validation (no negative prices, valid ISBN)
* Inventory and order logic
* Bill generation
* Search, sort, add, edit, delete, save, and load operations

### 🔹 2. **Object-Oriented Programming (OOP)**

* **Classes**: `Book`, `Inventory`, `Customer`, `Bill`
* **Encapsulation**: Keep book data members private
* **Inheritance** (Optional): For roles like Admin vs Customer
* **Polymorphism**: Method overriding for displaying different reports

### 🔹 3. **Data Structures & Algorithms (DSA)**

* **Vectors** or **Linked Lists**: For book list
* **Maps** / `unordered_map`: For quick lookup via ISBN
* **Sorting**: Alphabetically by title or by price
* **Searching**: Linear/Binary search
* **File Handling**: Save inventory persistently

---

## 🧰 **Planned Features**

| Feature              | Description                      |
| -------------------- | -------------------------------- |
| Add/Edit/Delete Book | Manage books in inventory        |
| Search Book          | By title, ISBN, or author        |
| Display Books        | Full inventory listing           |
| Sell Book            | Reduce stock and calculate bill  |
| Save/Load Data       | Persistent inventory using files |
| Sort Books           | By title or price                |

---

## 🧱 **Basic Code Example**

### 📁 `bookstore.cpp`

```cpp
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <algorithm>
using namespace std;

class Book {
private:
    string isbn;
    string title;
    string author;
    float price;
    int stock;
public:
    Book(string i, string t, string a, float p, int s)
        : isbn(i), title(t), author(a), price(p), stock(s) {}

    void display() const {
        cout << left << setw(12) << isbn << setw(25) << title 
             << setw(20) << author << setw(10) << price 
             << setw(8) << stock << endl;
    }

    string getISBN() const { return isbn; }
    string getTitle() const { return title; }
    float getPrice() const { return price; }
    int getStock() const { return stock; }

    void updateStock(int s) { stock = s; }

    void sell(int qty) {
        if (stock >= qty) {
            stock -= qty;
            cout << "Sold! Total = Rs. " << price * qty << endl;
        } else {
            cout << "Insufficient stock.\n";
        }
    }
};

class BookStore {
private:
    vector<Book> books;
public:
    void addBook(Book b) {
        books.push_back(b);
    }

    void displayBooks() {
        cout << left << setw(12) << "ISBN" << setw(25) << "Title" 
             << setw(20) << "Author" << setw(10) << "Price" 
             << setw(8) << "Stock" << endl;
        for (const auto& b : books) b.display();
    }

    void searchByTitle(string keyword) {
        bool found = false;
        for (const auto& b : books) {
            if (b.getTitle().find(keyword) != string::npos) {
                b.display();
                found = true;
            }
        }
        if (!found) cout << "No book found with title containing '" << keyword << "'\n";
    }

    void sellBook(string isbn, int qty) {
        for (auto& b : books) {
            if (b.getISBN() == isbn) {
                b.sell(qty);
                return;
            }
        }
        cout << "Book not found.\n";
    }

    void sortByTitle() {
        sort(books.begin(), books.end(), [](Book a, Book b) {
            return a.getTitle() < b.getTitle();
        });
    }

    void saveToFile(string filename) {
        ofstream fout(filename);
        for (const auto& b : books) {
            fout << b.getISBN() << "," << b.getTitle() << "," 
                 << b.getPrice() << "," << b.getStock() << "\n";
        }
        fout.close();
    }
};
```

---

## 🧪 **Sample `main()`**

```cpp
int main() {
    BookStore store;
    store.addBook(Book("9781234567", "C++ Basics", "Talha", 500, 10));
    store.addBook(Book("9787654321", "DSA in Depth", "Areeb", 650, 5));

    int choice;
    while (true) {
        cout << "\n--- Book Store Menu ---\n";
        cout << "1. Display All Books\n";
        cout << "2. Search by Title\n";
        cout << "3. Sell Book\n";
        cout << "4. Sort by Title\n";
        cout << "5. Save to File\n";
        cout << "6. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) store.displayBooks();
        else if (choice == 2) {
            string keyword;
            cout << "Enter title keyword: ";
            cin.ignore(); getline(cin, keyword);
            store.searchByTitle(keyword);
        }
        else if (choice == 3) {
            string isbn;
            int qty;
            cout << "Enter ISBN and quantity: ";
            cin >> isbn >> qty;
            store.sellBook(isbn, qty);
        }
        else if (choice == 4) {
            store.sortByTitle();
            cout << "Sorted by title.\n";
        }
        else if (choice == 5) {
            store.saveToFile("books.txt");
            cout << "Data saved.\n";
        }
        else break;
    }
    return 0;
}
```

---

## 📦 How to Make It Scalable

| Feature              | Strategy                                            |
| -------------------- | --------------------------------------------------- |
| Quick lookup by ISBN | Use `unordered_map<string, Book>`                   |
| Data persistence     | Use file streams (text/CSV), or upgrade to SQLite   |
| Multi-user login     | Add `User` class and inherit for `Admin`, `Cashier` |
| Reporting            | Generate sales reports, top-selling books           |
| GUI (future)         | Migrate to Qt or create a Web front-end later       |

---
