# General Store Management System

Creating a **console-based General Store Management System in C++** is an excellent way to master **Logic**, **Object-Oriented Programming (OOP)**, and **Data Structures & Algorithms (DSA)**. Below is a full breakdown of **techniques used** and an **example code skeleton** to get you started.

---

## ✅ **1. Techniques to Use**

### 🔹 **Logic**

* Menu-based interaction system
* Input validation (e.g., price can't be negative)
* Managing inventory: add, update, delete, search, and sell products
* Bill generation and total calculation
* File I/O for persistent storage

### 🔹 **Object-Oriented Programming (OOP)**

* **Classes**: `Product`, `Inventory`, `Bill`, `User` (for login access if needed)
* **Encapsulation**: Keep product details private
* **Inheritance**: Extend `User` class for Admin and Cashier (optional)
* **Polymorphism**: Common methods like `displayDetails()` in multiple classes

### 🔹 **Data Structures & Algorithms (DSA)**

* **Vectors** / **Linked Lists**: To store products
* **File Handling**: Save/load inventory or bills
* **Maps/Unordered Maps** (if allowed): For quick search by Product ID
* **Sorting**: Products by price, quantity, or name
* **Searching**: Binary search or linear search by name/ID

---

## 🎯 **Main Features**

* Add/Edit/Delete Product
* Search Product
* Display Inventory
* Sell Product (Generate bill)
* Save and Load Data

---

## 🧱 **Code Skeleton**

```cpp
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <algorithm>
using namespace std;

class Product {
private:
    int id;
    string name;
    float price;
    int quantity;
public:
    Product(int i, string n, float p, int q)
        : id(i), name(n), price(p), quantity(q) {}

    void display() const {
        cout << setw(5) << id << setw(15) << name << setw(10) 
             << price << setw(10) << quantity << endl;
    }

    int getId() const { return id; }
    string getName() const { return name; }
    float getPrice() const { return price; }
    int getQuantity() const { return quantity; }

    void updateQuantity(int q) { quantity = q; }
};

class Store {
private:
    vector<Product> inventory;

public:
    void addProduct(Product p) {
        inventory.push_back(p);
    }

    void displayInventory() {
        cout << setw(5) << "ID" << setw(15) << "Name"
             << setw(10) << "Price" << setw(10) << "Qty" << endl;
        for (const auto& p : inventory) {
            p.display();
        }
    }

    void sellProduct(int pid, int qty) {
        for (auto& p : inventory) {
            if (p.getId() == pid) {
                if (p.getQuantity() >= qty) {
                    cout << "Product sold! Total: Rs. " << p.getPrice() * qty << endl;
                    p.updateQuantity(p.getQuantity() - qty);
                } else {
                    cout << "Not enough stock!\n";
                }
                return;
            }
        }
        cout << "Product not found!\n";
    }

    void saveToFile(string filename) {
        ofstream fout(filename);
        for (auto& p : inventory) {
            fout << p.getId() << "," << p.getName() << "," 
                 << p.getPrice() << "," << p.getQuantity() << endl;
        }
        fout.close();
    }

    void loadFromFile(string filename) {
        ifstream fin(filename);
        inventory.clear();
        int id, qty;
        float price;
        string name;
        char comma;

        while (fin >> id >> comma && getline(fin, name, ',') &&
               fin >> price >> comma >> qty) {
            inventory.push_back(Product(id, name, price, qty));
        }

        fin.close();
    }
};
```

---

## 🖥️ **Sample `main()` Function**

```cpp
int main() {
    Store store;

    store.addProduct(Product(101, "Soap", 50.0, 100));
    store.addProduct(Product(102, "Shampoo", 120.0, 50));
    
    int choice;
    while (true) {
        cout << "\n--- General Store Management ---\n";
        cout << "1. Display Inventory\n2. Sell Product\n3. Save Data\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
            store.displayInventory();
        else if (choice == 2) {
            int pid, qty;
            cout << "Enter Product ID and Quantity: ";
            cin >> pid >> qty;
            store.sellProduct(pid, qty);
        }
        else if (choice == 3)
            store.saveToFile("store.txt");
        else
            break;
    }

    return 0;
}
```

---

## 📈 **How to Make It Scalable**

| Feature         | Technique                                             |
| --------------- | ----------------------------------------------------- |
| Fast Search     | Use `unordered_map<int, Product>`                     |
| Large Inventory | Load/save using binary or CSV files                   |
| Stock Alerts    | Add threshold alert system                            |
| User Roles      | Use Inheritance (`Admin`, `Cashier`)                  |
| Security        | Login system using encrypted password (basic hashing) |
| GUI (optional)  | Later shift to Qt or SFML for graphical interface     |

---
