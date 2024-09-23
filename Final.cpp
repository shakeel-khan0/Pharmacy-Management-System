#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <stack>
#include <queue>

using namespace std;
void intro() {
	cout<<"\n\n\t            ";
	cout<<"\t\t      Project On Pharmacy Management System";
	cout<<"\n\n\t\t\t\t\t\t  MADE BY";
	cout<<"\n\n\t\t\t\t\t Shakeel Khan & Nimra Sajid\n";
	cout<<"\n\t\t같같같같같같같같같같같같같같같같같같같같같";
	cout<<"같같같같같같같같같같같같같같같같같같같";
	cout<<"\t\t\t\t\t      \t\t\t";
	cout<<"\t\t\tGroup No 11\t\t\t\t\t\t";
	cout<<"\t\t\t\t\t";
	cout<<"\t\t\t\t같같같같같같같같같같같같같같같같같같같같같";
	cout<<"같같같같같같같같같같같같같같같같같같같\n\n";
}
class Medicine {
public:
	string name;
    int quantity;
    float price;
    Medicine(const string& name, int quantity, float price) : name(name), quantity(quantity), price(price) {}
    string getName() const {
        return name;
    }

    int getQuantity() const {
        return quantity;
    }

    float getPrice() const {
        return price;
    }

    void printDetails() const {
        cout << "\tName: " << name << "\tQuantity: " << quantity << "\tPrice: " << price << endl;
    }
};

class Pharmacy { 
public:
	list<Medicine> inventory;
    stack<string> stackMedicines;
    queue<string> queueMedicines;
    list<string> customerList;
    void addMedicine(const Medicine& medicine) {
        inventory.push_back(medicine);
        stackMedicines.push(medicine.getName());
        queueMedicines.push(medicine.getName());
    }

    void updateMedicine(const string& medicineName, int newQuantity, float newPrice) {
        for (Medicine& medicine : inventory) {
            if (medicine.getName() ==
			 medicineName) {
                medicine.quantity = newQuantity;
                medicine.price = newPrice;
                cout << "\tMedicine updated successfully.\n";
                return;
            }
        }
        cout << "\tMedicine not found.\n";
    }

    void removeMedicine(const string& medicineName) {
        inventory.remove_if([&](const Medicine& medicine) { return medicine.getName() == medicineName; });
        cout << "\tMedicine removed successfully.\n";
    }

    void showAllInventoryMedicines() const {
        cout << "\tInventory Medicines:\n";
        for (const Medicine& medicine : inventory) {
            medicine.printDetails();
        }
    }

    void showStackMedicines() const {
        cout << "\tStack Medicines:\n";
        stack<string> tempStack = stackMedicines;
        while (!tempStack.empty()) {
            cout << tempStack.top() << endl;
            tempStack.pop();
        }
    }

    void showQueueMedicines() const {
        cout << "\tQueue Medicines:\n";
        queue<string> tempQueue = queueMedicines;
        while (!tempQueue.empty()) {
            cout << tempQueue.front() << endl;
            tempQueue.pop();
        }
    }

    void addCustomerOrder(const string& customerName, const list<Medicine>& orderedMedicines, float totalBill) {
        customerList.push_back(customerName);
        generateReceipt(customerName, orderedMedicines, totalBill);
    }

    void generateReceipt(const string& customerName, const list<Medicine>& orderedMedicines, float totalBill) const {
        ofstream file("receipt.txt", ios::app);
        if (file.is_open()) {
            file << "\tCustomer Name: " << customerName << endl;
            file << "\tOrdered Medicines:\n";
            for (const Medicine& medicine : orderedMedicines) {
                file << "- " << medicine.getName() << endl;
            }
            file << "\tTotal Bill: Rs." << totalBill << endl;
            file << "\t-------------------------\n";
            file.close();
        } else {
            cout << "\tUnable to open the receipt file.\n";
        }
    }

    void showCustomerList() const {
        cout << "\tCustomer List:\n";
        for (const string& customer : customerList) {
            cout << "- " << customer << endl;
        }
    }

    void showCustomerReceipts() const {
        ifstream file("receipt.txt");
        if (file.is_open()) {
            string line;
            cout << "\tCustomer Receipts:\n";
            while (getline(file, line)) {
                cout << line << endl;
            }
            file.close();
        } else {
            cout << "\tUnable to open the receipt file.\n";
        }
    }

    void loadInventoryFromFile() {
        ifstream file("inventory.txt");
        if (file.is_open()) {
            string name;
            int quantity;
            float price;
            while (file >> name >> quantity >> price) {
                Medicine medicine(name, quantity, price);
                addMedicine(medicine);
            }
            file.close();
        } else {
            cout << "\tUnable to open the inventory file.\n";
        }
    }

    void saveInventoryToFile() const {
        ofstream file("inventory.txt");
        if (file.is_open()) {
            for (const Medicine& medicine : inventory) {
                file << medicine.getName() << " " << medicine.getQuantity() << " " << medicine.getPrice() << endl;
            }
            file.close();
        } else {
            cout << "\tUnable to open the inventory file.\n";
        }
    }
};

void handleCustomerSection(Pharmacy& pharmacy) {
    string customerName;
    list<Medicine> orderedMedicines;
    float totalBill = 0.0;
	cout << "\n\n\t\t\t\t\t\t|---------------------|";
    cout << "\n\t\t\t\t\t\t|CUSTOMER MENU	      |";
    cout << "\n\t\t\t\t\t\t|---------------------|";
    cout << "\n\t Enter Customer Name: ";
    cin >> customerName;

//    cout << "\tAvailable Medicines:\n";
    pharmacy.showAllInventoryMedicines();

    int orderChoice;
    do {
        string medicineName;
        cout << "\tEnter Medicine Name (or enter '0' to finish ordering): ";
        cin >> medicineName;

        if (medicineName == "0") {
            break;
        }

        bool medicineFound = false;
        for (const Medicine& medicine : pharmacy.inventory) {
            if (medicine.getName() == medicineName) {
                orderedMedicines.push_back(medicine);
                totalBill += medicine.getPrice();
                medicineFound = true;
                break;
            }
        }

        if (!medicineFound) {
            cout << "\tMedicine not found. Please enter a valid medicine name.\n";
        }

    } while (true);

    // Generate and save the receipt
    pharmacy.addCustomerOrder(customerName, orderedMedicines, totalBill);

    float payment;
    cout << "\tTotal Bill: Rs." << totalBill << endl;
    cout << "\tEnter Payment: Rs.";
    cin >> payment;

    if (payment < totalBill) {
        cout << "\tInsufficient payment. Order cancelled.\n";
    } else {
        float change = payment - totalBill;
        cout << "\tChange: Rs." << change << endl;
        cout << "\tOrder Successful. Thank you!\n";
    }
}

void handleAdminSection(Pharmacy& pharmacy) {
    int adminChoice;
    do {
        cout << "\n\n\t\t\t\t\t\t |---------------------|\n";
    	cout << "\n\n\t\t\t\t\t\t |ADMIN MENU\n			|";
    	cout << "\n\n\t\t\t\t\t\t |---------------------|\n";
        cout << "\t1. Add Medicine\n";
        cout << "\t2. Update Medicine\n";
        cout << "\t3. Remove Medicine\n";
        cout << "\t4. Display All Medicines\n";
        cout << "\t5. Show Stack Medicines\n";
        cout << "\t6. Show Queue Medicines\n";
        cout << "\t7. Show Customer List\n";
        cout << "\t8. Show Customer Receipts\n";
        cout << "\t9. Exit Admin Section\n";
        cout << "\tChoice: ";
        cin >> adminChoice;

        switch (adminChoice) {
            case 1: {
                string name;
                int quantity;
                float price;
                cout << "\tEnter Medicine Details:\n";
                cout << "\tName: ";
                cin >> name;
                cout << "\tQuantity: ";
                cin >> quantity;
                cout << "\tPrice: ";
                cin >> price;
                Medicine medicine(name, quantity, price);
                pharmacy.addMedicine(medicine);
                cout << "\tMedicine added successfully.\n";
                break;
            }
            case 2: {
                string name;
                int quantity;
                float price;
                cout << "\tEnter Medicine Name to Update: ";
                cin >> name;
                cout << "\tEnter New Quantity: ";
                cin >> quantity;
                cout << "\tEnter New Price: ";
                cin >> price;
                pharmacy.updateMedicine(name, quantity, price);
                break;
            }
            case 3: {
                string name;
                cout << "\tEnter Medicine Name to Remove: ";
                cin >> name;
                pharmacy.removeMedicine(name);
                break;
            }
            case 4:
                pharmacy.showAllInventoryMedicines();
                break;
            case 5:
                pharmacy.showStackMedicines();
                break;
            case 6:
                pharmacy.showQueueMedicines();
                break;
            case 7:
                pharmacy.showCustomerList();
                break;
            case 8:
                pharmacy.showCustomerReceipts();
                break;
            case 9:
                cout << "\tExiting Admin Section.\n";
                break;
            default:
                cout << "\tInvalid choice. Try again.\n";
                break;
        }
    } while (adminChoice != 9);
}

int main() {
	intro();
    Pharmacy pharmacy;
    // Load inventory from file
    pharmacy.loadInventoryFromFile();

    int choice;
    do {
        cout << "\n\n\t\t\t\t\t\t  Select an option:\n";
        cout << "\n\n\t\t\t\t\t\t  1. Admin Section\n";
        cout << "\n\n\t\t\t\t\t\t  2. Customer Section\n";
        cout << "\n\n\t\t\t\t\t\t  3. Exit\n";
        cout << "\n\n\t\t\t\t\t\t  Choice: ";
        cin >> choice;
        system("cls");

        switch (choice) {
            case 1:
                handleAdminSection(pharmacy);
                break;
            case 2:
                handleCustomerSection(pharmacy);
                break;
            case 3:
                // Save inventory to file before exiting
                pharmacy.saveInventoryToFile();
                cout << "\tExiting program.\n";
                break;
            default:
                cout << "\tInvalid choice. Try again.\n";
                break;
        }
    } while (choice != 3);

    return 0;
}
