#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

// defined functions
int welcome();
int CASES(int);
int List();
int admin();
int stockO();
int stockI();

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
    welcome();
    if (choice == 0 || choice > 5){
        cout << "Please Enter A Valid Number" << endl;
        welcome();
    }
    else{
        CASES(choice);
    }
    return 0;
}

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
         << setw(14) << "Last-Out"
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
                 << setw(14) << item.lastStockOutDate
                 << setw(8)  << item.quantity << endl;
        }
    }
    cout<<"Enter E For Exit"<<endl;
    cout<<"Enter I For Stock In"<<endl;
    cout<<"Enter O For Stock Out"<<endl;
    cin>>useri;
    if (useri == 'E' || useri == 'e')
    {
        main();
    }else if(useri == 'I' || useri == 'i'){
        CASES(2);
    }else if(useri == 'O' || useri == 'o'){
       CASES(3);
    }else{
       cout<<"Still In View Mode";
        List();
    }
    
    return 0;
}

int admin(){
    int TPassword;

    cout << "Welcome Master" << endl;
    cout << "What Would You Like To Perform: "<<endl;
    cout << "2.Stock IN" << endl;
    cout << "4.List" << endl;
    cout << "5.LogOut" << endl;
    cout << "6.Change Password" << endl;
    cin >> choice;

    if(choice == 2){
        CASES(choice);
    } else if(choice == 4){
        List();
    } else if(choice == 5){
        main();
    } else if(choice == 6){
        cout<< "Enter Your Current Password :";
        cin>>TPassword;
        if (TPassword == Hard_Password){
            cout<<"Enter New Password :";
            cin>>Hard_Password;
            admin();
        } else {
            cout<<"Wrong Password, You Are Being Logged Out";
            main();
        }
    } else {
        cout<<"Please Enter Valid Input"<<endl;
        admin();
    }
    return 0;
}

// here all the stock out activities work
int stockO(){
    int id, qty;
    cout << "Enter Item ID: ";
    cin >> id;

    cout << "Enter Quantity to remove: ";
    cin >> qty;

    for (auto &item : inventory) {
        if (item.id == id) {
            if (item.quantity >= qty) {
                item.quantity -= qty;
                cout << "Enter Stock-Out Date (DD-MM-YYYY): ";
                cin >> item.lastStockOutDate;
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

// here all the stock In activities work
int stockI(){
    int id, qty;
    cout << "Enter Item ID: ";
    cin >> id;

    cout << "Enter Quantity To Add: ";
    cin >> qty;

    // check if item exists
    for (auto &item : inventory) {
        if (item.id == id) {
            item.quantity += qty;
            cout << "Stock Updated For Existing Item\n";
            main();
            return 0;
        }
    }

    // new item
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
