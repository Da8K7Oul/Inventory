#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include <sstream>
using namespace std;

// defined functions
int welcome();
int CASES(int);
int List();
int admin();
int stockO();
int stockI();
int deleteItem();            // ADDED

void loadFromCSV();
void saveToCSV();

// global variable
int choice;
int Hard_Password = 123456789;

// this is how i am storing data
struct Item {
    int id;
    string name;
    int quantity;
    string stockInDate;
    string lastStockOutDate;
};

// vector
vector<Item> inventory;

int main(){
    loadFromCSV(); // ADDED

    welcome();
    if (choice == 0 || choice > 5){
        cout << "Please Enter A Valid Number" << endl;
        welcome();
    }
    else{
        CASES(choice);
    }

    saveToCSV(); // ADDED
    return 0;
}

// ================= CSV FUNCTIONS =================

void loadFromCSV(){
    inventory.clear(); // ✅ CRITICAL FIX (no duplicates)

    ifstream file("inventory.csv");
    if (!file.is_open()) return;

    string line;
    getline(file, line); // skip header

    while (getline(file, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        Item item;
        string temp;

        try {
            getline(ss, temp, ',');

            // BOM protection
            if (temp.size() >= 3 &&
                (unsigned char)temp[0] == 0xEF &&
                (unsigned char)temp[1] == 0xBB &&
                (unsigned char)temp[2] == 0xBF) {
                temp = temp.substr(3);
            }

            item.id = stoi(temp);

            getline(ss, item.name, ',');

            getline(ss, temp, ',');
            item.quantity = stoi(temp);

            getline(ss, item.stockInDate, ',');
            getline(ss, item.lastStockOutDate, ',');

            inventory.push_back(item);
        }
        catch (...) {
            continue; // skip bad row safely
        }
    }
    file.close();
}

void saveToCSV(){
    ofstream file("inventory.csv");
    file << "id,name,quantity,stockInDate,lastStockOutDate\n";

    for (auto &item : inventory) {
        file << item.id << ","
             << item.name << ","
             << item.quantity << ","
             << item.stockInDate << ","
             << item.lastStockOutDate << "\n";
    }
    file.close();
}

// =================================================

int welcome(){
    cout << "**********|Hello Welcome To MY INVENTORY|**********" << endl;
    cout << "*********|Select What Task You Want To Perform|*********" << endl;
    cout << "********|Enter Only Numbers And Enter Between 1-5 Respectivily"<<endl;
    cout << "1.Admin" << endl;
    cout << "2.Stock IN" << endl;
    cout << "3.Stock OUT" << endl;
    cout << "4.List" << endl;
    cout << "5.Exit" << endl;
    cout<<"Enter Your Choice :";
    cin >> choice;
    return choice;
}

int CASES(int choice){
    int user_entered_password;

    switch (choice){
    case 1:
        cout << "User:Admin" << endl;
        cout << "Enter Password: ";
        cin >> user_entered_password;
        if (user_entered_password == Hard_Password){
            admin();
        } else {
            cout << "Wrong Password" << endl;
            main();
        }
        break;

    case 2:
        cout << "Please Enter Admin Password :";
        cin >> user_entered_password;
        if (user_entered_password == Hard_Password){
            stockI();
        } else {
            cout << "You Have Wrong Password" << endl;
            main();
        }
        break;

    case 3:
        cout<<"Getting You There...."<<endl;
        stockO();
        break;

    case 4:
        cout<<"Getting Your Data...."<<endl;
        List();
        break;

    case 5:
        saveToCSV();
        return 0;

    default:
        cout<<"Invalid Input"<<endl;
        main();
    }
    return 0;
}

int List(){
    char useri;

    cout << "\n================ INVENTORY TABLE ================\n";
    cout << left
         << setw(6)  << "ID"
         << setw(12) << "Name"
         << setw(14) << "Stock-In"
         << setw(18) << "Last-Out"
         << setw(8)  << "Stock" << endl;
    cout << "-------------------------------------------------\n";

    if (inventory.empty()) {
        cout << "No Items In Inventory\n";
    } else {
        for (auto item : inventory) {
            cout << left
                 << setw(6)  << item.id
                 << setw(12) << item.name
                 << setw(14) << item.stockInDate
                 << setw(18) << item.lastStockOutDate
                 << setw(8)  << item.quantity << endl;
        }
    }

    cout<<"Enter E For Exit"<<endl;
    cout<<"Enter I For Stock In"<<endl;
    cout<<"Enter O For Stock Out"<<endl;
    cin>>useri;

    if (useri == 'E' || useri == 'e') main();
    else if(useri == 'I' || useri == 'i') CASES(2);
    else if(useri == 'O' || useri == 'o') CASES(3);
    else List();

    return 0;
}

int admin(){
    int TPassword;

    cout << "Welcome Master" << endl;
    cout << "2.Stock IN" << endl;
    cout << "4.List" << endl;
    cout << "5.LogOut" << endl;
    cout << "6.Change Password" << endl;
    cout << "7.Delete Item" << endl; // ADDED
    cin >> choice;

    if(choice == 2) CASES(choice);
    else if(choice == 4) List();
    else if(choice == 5) main();
    else if(choice == 6){
        cout<< "Enter Your Current Password :";
        cin>>TPassword;
        if (TPassword == Hard_Password){
            cout<<"Enter New Password :";
            cin>>Hard_Password;
            admin();
        } else {
            cout<<"Wrong Password";
            main();
        }
    }
    else if(choice == 7){
        deleteItem(); // ADDED
    }
    else{
        cout<<"Please Enter Valid Input"<<endl;
        admin();
    }
    return 0;
}

int stockO(){
    int id, qty;
    string date;

    cout << "Enter Item ID: ";
    cin >> id;
    cout << "Enter Quantity to remove: ";
    cin >> qty;

    for (auto &item : inventory) {
        if (item.id == id) {
            if (item.quantity >= qty) {
                item.quantity -= qty;
                cout << "Enter Stock-Out Date (DD-MM-YYYY): ";
                cin >> date;
                item.lastStockOutDate = date + "(" + to_string(qty) + ")";
                cout << "Stock Updated Successfully\n";
            } else {
                cout << "Not Enough Stock\n";
            }
            List();
            return 0;
        }
    }

    cout << "Item Not Found\n";
    List();
    return 0;
}

int stockI(){
    int id, qty;
    cout << "Enter Item ID: ";
    cin >> id;

    cout << "Enter Quantity To Add: ";
    cin >> qty;

    for (auto &item : inventory) {
        if (item.id == id) {
            item.quantity += qty;
            cout << "Stock Updated For Existing Item\n";
            main();
            return 0;
        }
    }

    Item temp;
    temp.id = id;
    cout << "Enter Item Name: ";
    cin >> temp.name;
    cout << "Enter Stock-In Date (DD-MM-YYYY): ";
    cin >> temp.stockInDate;
    temp.lastStockOutDate = "-";
    temp.quantity = qty;

    inventory.push_back(temp);
    cout << "New Item Added Successfully\n";
    List();
    return 0;
}

// ADDED — delete item completely
int deleteItem(){
    int id;
    cout << "Enter Item ID To Delete: ";
    cin >> id;

    for (auto it = inventory.begin(); it != inventory.end(); ++it) {
        if (it->id == id) {
            inventory.erase(it);
            cout << "Item Deleted Successfully\n";
            List();
            return 0;
        }
    }

    cout << "Item Not Found\n";
    admin();
    return 0;
}
