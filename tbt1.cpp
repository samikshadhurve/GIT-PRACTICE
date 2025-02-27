#include<iostream>
#include<stack>
using namespace std;

typedef struct node {
    int data, lth, rth;
    node* left, * right;
} node;

class TBT {
public:
    node* root;
    node* dummy;

    TBT() {
        root = NULL;
        dummy = NULL;
    }

    void insert() {
        char ch;
        do {
            node* nn = new node;
            int data;
            cout << "Enter the data you want to insert: ";
            cin >> data;
            nn->data = data;
            nn->left = NULL;
            nn->right = NULL;
            nn->lth = 1;
            nn->rth = 1;

            if (root == NULL) {
                dummy = new node;
                dummy->data = 9999;
                root = nn;
                nn->left = dummy;
                nn->right = dummy;
                dummy->left = root;
                dummy->right = root;
            }
            else {
                node* cn = root;
                while (true) {
                    if (nn->data < cn->data) {
                        if (cn->lth == 1) {
                            nn->left = cn->left;
                            nn->right = cn;
                            cn->lth = 0;
                            cn->left = nn;
                            break;
                        }
                        else {
                            cn = cn->left;
                        }
                    }
                    else if (nn->data > cn->data) {
                        if (cn->rth == 1) {
                            nn->right = cn->right;
                            nn->left = cn;
                            cn->rth = 0;
                            cn->right = nn;
                            break;
                        }
                        else {
                            cn = cn->right;
                        }
                    }
                }
            }
            cout << "Do you want to insert more? (y/n): ";
            cin >> ch;
        } while (ch == 'y');
    }

    void inorder(node* cn) {
        while (cn != dummy) {
            while (cn->lth == 0) {
                cn = cn->left;
            }
            cout << cn->data << " ";
            while (cn->rth == 1) {
                cn = cn->right;
                if (cn == dummy) {
                    return;
                }
                cout << cn->data << " ";
            }
            cn = cn->right;
        }
    }

    void preorder(node* cn) {
        while (cn != dummy) {
            while (cn->lth == 0) {
                cout << cn->data << " ";
                cn = cn->left;
            }
            cout << cn->data << " ";
            while (cn->rth == 1) {
                cn = cn->right;
                if (cn == dummy) {
                    return;
                }
            }
            cn = cn->right;
        }
    }

    void postorder(node* cn) {
        stack<node*> s;
        node* curr = cn;
        node* prev = NULL;

        if (curr == NULL) {
            cout << "Tree is empty." << endl;
            return;
        }

        do {
            while (curr != NULL) {
                s.push(curr);
                curr = curr->left;
            }

            while (curr == NULL && !s.empty()) {
                curr = s.top();

                if (curr->right == NULL || curr->right == prev) {
                    cout << curr->data << " ";
                    s.pop();
                    prev = curr;
                    curr = NULL;
                }
                else {
                    curr = curr->right;
                }
            }
        } while (!s.empty());
    }

    void traversePostorder() {
        cout << "Postorder Traversal: ";
        postorder(root);
        cout << endl;
    }
};

int main() {
    TBT tbt;
    int choice;

    do {
        cout << "\nMENU" << endl;
        cout << "1. Create TBT" << endl;
        cout << "2. Inorder Traversal" << endl;
        cout << "3. Preorder Traversal" << endl;
        cout << "4. Postorder Traversal" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            tbt.insert();
            break;
        case 2:
            cout << "Inorder Traversal: ";
            tbt.inorder(tbt.root);
            cout << endl;
            break;
        case 3:
            cout << "Preorder Traversal: ";
            tbt.preorder(tbt.root);
            cout << endl;
            break;
        case 4:
            tbt.traversePostorder();
            break;
        case 5:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    } while (choice != 5);

    return 0;
}
