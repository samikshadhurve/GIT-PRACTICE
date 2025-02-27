#include <iostream>
using namespace std;

typedef struct emp_data {
    string name;
    long int phone;
} emp_data;

class Search {
    public:
    int size;
    emp_data *e;


    Search() {
        size = 0;
        e = NULL;
    }

    void create() {
        cout << "Enter the number of employees: " << endl;
        cin >> size;
        e = new emp_data[size];

        for (int i = 0; i < size; i++) {
            cout << "Enter name: ";
            cin >> e[i].name;
            cout << "Enter mobile number: ";
            cin >> e[i].phone;
        }
    }

    void linearSearch(string name) {
        bool found = false;

        for (int i = 0; i < size; i++) {
            if (e[i].name == name) {
                found = true;
                cout << "The phone number of " << e[i].name << " is: " << e[i].phone << endl;
            }
        }

        if (!found) {
            cout << "Name not found!" << endl;
        }
    }

    int binarySearch(string name) {
        int beg = 0;
        int end = size - 1;

        while (beg <= end) {
            int mid = (beg + end) / 2;
            if (e[mid].name == name) {
                cout << "The phone number of " << e[mid].name << " is: " << e[mid].phone << endl;
                return mid; 
            } else if (e[mid].name < name) {
                beg = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return -1; 
    }

    ~Search() {
        delete[] e; 
    }
};

int main() {
    Search s;
    int choice;
    string name;

    do {
        cout << "Menu:\n1. Create employee records\n2. Linear Search\n3. Binary Search\n4. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                s.create();
                break;

            case 2:
                if (s.size == 0) {
                    cout << "No records to search. Please create employee records first." << endl;
                } else {
                    cout << "Enter the name to search: ";
                    cin >> name;
                    s.linearSearch(name);
                }
                break;

            case 3:
                if (s.size == 0) {
                    cout << "No records to search. Please create employee records first." << endl;
                } else {
                    cout << "Enter the name to search: ";
                    cin >> name;
                    int result = s.binarySearch(name);
                    if (result == -1) {
                        cout << "Name not found!" << endl;
                    }
                }
                break;

            case 4:
                cout << "Exiting program." << endl;
                break;

            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
                break;
        }
    } while (choice != 4);

    return 0;
}
