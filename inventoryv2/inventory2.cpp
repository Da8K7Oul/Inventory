#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cstdlib>

using namespace std;

struct Item {
    int id;
    string name;
    int quantity;
    string stockInDate;
    string lastStockOutDate;
};

vector<Item> inventory;
int Hard_Password = 123456789;

// ================= CSV =================

void loadFromCSV(){
    inventory.clear();
    ifstream file("inventory.csv");
    if (!file.is_open()) return;

    string line;
    getline(file, line);

    while (getline(file, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        Item item;
        string temp;

        getline(ss, temp, ',');
        item.id = stoi(temp);

        getline(ss, item.name, ',');
        getline(ss, temp, ',');
        item.quantity = stoi(temp);

        getline(ss, item.stockInDate, ',');
        getline(ss, item.lastStockOutDate, ',');

        inventory.push_back(item);
    }
}

void saveToCSV(){
    ofstream file("inventory.csv");
    file << "id,name,quantity,stockInDate,lastStockOutDate\n";

    for (auto &item : inventory){
        file << item.id << ","
             << item.name << ","
             << item.quantity << ","
             << item.stockInDate << ","
             << item.lastStockOutDate << "\n";
    }
}

// ================= LOW STOCK EMAIL =================

void sendLowStockEmail(Item &item){
    if(item.quantity <= 2){
        string command = "python send_email.py " +
                         to_string(item.id) + " " +
                         item.name + " " +
                         to_string(item.quantity);
        system(command.c_str());
    }
}

// ================= FUNCTIONS =================

void stockI(){
    int id, qty;
    Item temp;

    cout << "Enter Item ID: ";
    cin >> id;

    cout << "Enter Quantity To Add: ";
    cin >> qty;

    for (auto &item : inventory){
        if(item.id == id){
            string date;
            cout<<"enter stock-in data (DD-MM-YYYY): ";
            cin>>date;

            item.quantity += qty;
            item.stockInDate = date + "(+" + to_string(qty) + ")";
            saveToCSV();
            cout<<"stock updated";
            return;
        }
    }


    temp.id = id;
    cout << "Enter Item Name: ";
    cin >> temp.name;
    cout << "Enter Stock-In Date (DD-MM-YYYY): ";
    cin >> temp.stockInDate;
    temp.lastStockOutDate = "-";
    temp.quantity = qty;

    inventory.push_back(temp);
    saveToCSV();
}

void stockO(){
    int id, qty;
    string date;

    cout << "Enter Item ID: ";
    cin >> id;
    cout << "Enter Quantity to remove: ";
    cin >> qty;

    for(auto &item : inventory){
        if(item.id == id){
            if(item.quantity >= qty){
                item.quantity -= qty;
                cout << "Enter Stock-Out Date: ";
                cin >> date;
                item.lastStockOutDate = date + "(-" + to_string(qty) + ")";
                saveToCSV();
                sendLowStockEmail(item);
            }
            return;
        }
    }
}

void deleteItem(){
    int id;
    cout << "Enter ID To Delete: ";
    cin >> id;

    for(auto it = inventory.begin(); it != inventory.end(); ++it){
        if(it->id == id){
            inventory.erase(it);
            saveToCSV();
            cout << "Deleted\n";
            return;
        }
    }
}

void List(){
    while(true){
        cout << "\n================ INVENTORY TABLE ================\n";
        cout << left
             << setw(6)  << "ID"
             << setw(12) << "Name"
             << setw(14) << "Stock-In"
             << setw(18) << "Last-Out"
             << setw(8)  << "Stock" << endl;

        for(auto &item : inventory){
            cout << left
                 << setw(6)  << item.id
                 << setw(12) << item.name
                 << setw(14) << item.stockInDate
                 << setw(18) << item.lastStockOutDate
                 << setw(8)  << item.quantity << endl;
        }

        char c;
        cout << "\nI = Stock In | O = Stock Out | E = Exit\n";
        cin >> c;

        if(c=='I'||c=='i') stockI();
        else if(c=='O'||c=='o') stockO();
        else break;
    }
}

void admin(){
    while(true){
        int choice;
        cout << "\nADMIN PANEL\n";
        cout << "1.Stock IN\n";
        cout << "2.List\n";
        cout << "3.Delete\n";
        cout << "4.Logout\n";
        cin >> choice;

        if(choice==1) stockI();
        else if(choice==2) List();
        else if(choice==3) deleteItem();
        else break;
    }
}

int main(){
    loadFromCSV();

    while(true){
        int choice;
        cout << "\n1.Admin\n2.Stock OUT\n3.List\n4.Exit\n";
        cin >> choice;

        if(choice==1){
            int pass;
            cout << "Enter Password: ";
            cin >> pass;
            if(pass==Hard_Password) admin();
        }
        else if(choice==2) stockO();
        else if(choice==3) List();
        else break;
    }

    return 0;
}
