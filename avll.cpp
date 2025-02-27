#include <iostream>
#include <string>
using namespace std;

class node {
public:
    string word;
    string meaning;
    node* left;
    node* right;
};

class AVL {
private:
    node* root;

public:
    AVL() {
        root = nullptr;
    }

    node* insert(node* temp, const string& word, const string& meaning) {
        if (temp == nullptr) {
            temp = new node;
            temp->word = word;
            temp->meaning = meaning;
            temp->left = temp->right = nullptr;
        } else {
            if (word < temp->word) {
                temp->left = insert(temp->left, word, meaning);
            } else {
                temp->right = insert(temp->right, word, meaning);
            }
            int balance = height(temp->left) - height(temp->right);

            if (balance > 1) {
                if (word < temp->left->word) {
                    return LL(temp);
                } else {
                    return LR(temp);
                }
            }

            if (balance < -1) {
                if (word > temp->right->word) {
                    return RR(temp);
                } else {
                    return RL(temp);
                }
            }
        }
        return temp;
    }

    int height(node* temp) {
        if (temp == nullptr) {
            return -1;
        }
        int leftHeight = height(temp->left);
        int rightHeight = height(temp->right);
        return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
    }

    node* LL(node* parent) {
        node* temp = parent->left;
        parent->left = temp->right;           
        temp->right = parent;                 
        return temp;
    }

    node* RR(node* parent) {
        node* temp = parent->right;
        parent->right = temp->left;          
        temp->left = parent;                 
        return temp;
    }

    node* LR(node* parent) {
        parent->left = RR(parent->left);      
        return LL(parent);
    }

    node* RL(node* parent) {
        parent->right = LL(parent->right);     
        return RR(parent);
    }

    void create() {
        char ch;
        string word, meaning;

        do {
            cout << "Enter word: ";
            cin >> word;
            cout << "Enter meaning: ";
            cin>>meaning;
            root = insert(root, word, meaning);
            cout << "Root of the tree is: " << root->word << " - " << root->meaning << endl;
            cout << "Do you want to add more? (y/n): ";
            cin >> ch;
        } while (ch != 'n');
    }

    void inorder(node* temp) {
            if (temp != nullptr) {
            inorder(temp->left);
            cout << "Word: " << temp->word << " - Meaning: " << temp->meaning << "\n";
            inorder(temp->right);
        }
    }

    void display() {
        cout << "AVL tree in ascending order: " << endl;
        inorder(root);
        cout << endl;
    }

    void search(const string& word) {
        string meaning = searchNode(root, word);
        if (!meaning.empty()) {
            cout << "Word: " << word << " - Meaning: " << meaning << " found in the AVL tree." << endl;
        } else {
            cout << "Word: " << word << " not found in the AVL tree." << endl;
        }
    }

    string searchNode(node* temp, const string& word) {
        if (temp == nullptr) {
            return "";
        }

        if (word == temp->word) {
            return temp->meaning; 
        } else if (word < temp->word) {
            return searchNode(temp->left, word); 
        } else {
            return searchNode(temp->right, word); 
        }
    }
    };

int main() {
    int ch;
    string word;
    AVL avl;

    do {
        cout << "\n********Menu*********" << endl;
        cout << "1. Insert a Word in AVL Tree" << endl;
        cout << "2. Display AVL Tree" << endl;
        cout << "3. Search a Word in AVL Tree" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your Choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                avl.create();
                break;
            case 2:
                avl.display();
                break;
            case 3:
                cout << "Enter Word to search in Tree: ";
                cin >> word;
                avl.search(word);
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid Choice!" << endl;
        }
    } while (ch != 4);

    return 0;
}