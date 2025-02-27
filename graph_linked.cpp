#include<iostream>
using namespace std;

class node {
public:
    int data;
    node* next;

};

class graph {
    node* hn[100];  // Assuming a maximum of 100 vertices
public:
    graph() {
        for (int i = 0; i < 100; ++i) {
            hn[i] = NULL;
        }
       
    }

    void create() {
        int v1, v2;
        char ch;
        do {
            cout << "Enter vertices:" << endl;
            cin >> v1 >> v2;

            // Creating a new node for the first vertex
            node* nn = new node;
            nn->next = NULL;
            nn->data = v1;

            if (hn[v2] == NULL) {
                hn[v2] = nn;
            }
            else {
                // Traverse the linked list to the end and add the new node
                node* cn = hn[v2];
                while (cn->next != NULL) {
                    cn = cn->next;
                }
                cn->next = nn;
            }

            // Creating a new node for the second vertex
            node* nn1 = new node;
            nn1->next = NULL;
            nn1->data = v2;

            if (hn[v1] == NULL) {
                hn[v1] = nn1;
            }
            else {
                // Traverse the linked list to the end and add the new node
                node* cn = hn[v1];
                while (cn->next != NULL) {
                    cn = cn->next;
                }
                cn->next = nn1;
            }

            cout << "Enter the choice:";
            cin >> ch;

        } while (ch != 'n');
    }

    void display() {
        for (int i = 0; i < 100; ++i) {
            node* current = hn[i];
            cout << "Vertex " << i << ": ";
            while (current != NULL) {
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }
    }
};

int main() {
    graph g;
    g.create();
    g.display();
    return 0;
}

