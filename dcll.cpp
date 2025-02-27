#include<iostream>
using namespace std;

struct node{
    int data;
    node *next;
    node *prev; // New pointer for doubly linked list
};

class dcll{
private:
    node *hn;
    node *ln;
public:
    dcll(){
        hn = NULL;
        ln = NULL;
    }

    void insert_end(int val){
        node *nn = new node;
        nn->data = val;
        nn->next = NULL;
        nn->prev = NULL; // Initialize the prev pointer
        if(hn == NULL){
            hn = nn;
            ln = nn;
            nn->next = nn;
            nn->prev = nn;
        } else {
            nn->prev = ln; // Update the prev pointer of the new node
            ln->next = nn;
            nn->next = hn;
            ln = nn;
            hn->prev = ln; // Update the prev pointer of the head node
        }
    }

    void insert_start(int val){
        node *nn = new node;
        nn->data = val;
        nn->next = NULL;
        nn->prev = NULL;
        if(hn == NULL){
            hn = nn;
            ln = nn;
            nn->next = nn;
            nn->prev = nn;
        } else {
            nn->next = hn;
            hn->prev = nn;
            hn = nn;
            ln->next = hn;
            hn->prev = ln;
        }
    }

    void insert_after(int val){
        node *nn = new node;
        nn->data = val;
        nn->next = NULL;
        nn->prev = NULL;
        int target;
        cout << "Enter target:" << endl;
        cin >> target;
        if(hn == NULL){
            cout << "Empty list" << endl;
            return;
        }
        node *temp = hn;
        do {
            if(temp->data == target){
                nn->next = temp->next;
                temp->next->prev = nn; // Update the prev pointer of the next node
                temp->next = nn;
                nn->prev = temp;
                if(temp == ln){
                    ln = nn;
                }
                return;
            }
            temp = temp->next;
        } while(temp != hn);
        cout << "Data not found!" << endl;
    }

    void insert_before(int val){
        node *nn = new node;
        nn->data = val;
        nn->next = NULL;
        nn->prev = NULL;
        int target;
        cout << "Enter target:" << endl;
        cin >> target;
        if(hn == NULL){
            cout << "Empty list" << endl;
            return;
        }
        node *temp = hn;
        do {
            if(temp->next->data == target){
                nn->next = temp->next;
                temp->next->prev = nn;
                temp->next = nn;
                nn->prev = temp;
                if(temp == ln){
                    ln = nn;
                }
                if(temp == hn){
                    hn = nn;
                }
                return;
            }
            temp = temp->next;
        } while(temp != hn);
        cout << "Data not found!" << endl;
    }

    void del(){
        int target;
        cout << "Enter the target:" << endl;
        cin >> target;
        if(hn == NULL){
            cout << "Empty list" << endl;
            return;
        }
        node *temp = hn;
        if(temp->data == target){
            hn = hn->next;
            hn->prev = ln; // Update the prev pointer of the new head node
            ln->next = hn;
            delete temp;
            return;
        }
        while(temp->next->data != target && temp->next != hn){
            temp = temp->next;
        }
        if(temp->next->data == target){
            node *targetnode = temp->next;
            temp->next = temp->next->next;
            temp->next->prev = temp; // Update the prev pointer of the next node
            delete targetnode;
        } else {
            cout << "Data not found" << endl;
        }
    }

    void display(){
        if(hn == NULL){
            cout << "Empty" << endl;
            return;
        }
        node *temp = hn;
        do {
            cout << temp->data << endl;
            temp = temp->next;
        } while(temp != hn);
    }
};

int main(){
    dcll c;
    int n, m, opt;
    cout << "Enter the number of elements:" << endl;
    cin >> n;
    for(int i = 0; i < n; i++){
        cout << "Enter element " << i + 1 << ":" << endl;
        cin >> m;
        c.insert_end(m);
    }
    cout << "Enter option: 1. insert at start 2. insert after 3. insert before 4. delete";
    cin >> opt;
    c.display();
    switch(opt){
        case 1:
            c.insert_start(20);
            c.display();
            break;
        case 2:
            c.insert_after(44);
            c.display();
            break;
        case 3:
            c.insert_before(21);
            c.display();
            break;
        case 4:
            c.del();
            c.display();
            break;
        default:
            cout << "Invalid choice";
    }
    return 0;
}
