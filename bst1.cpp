#include <iostream>
using namespace std;

struct node {
    string word;
    string meaning;
    node* left;
    node* right;
};

class bst {
    node* root;

public:
    bst() {
        root = NULL;
    }

    void insertion(string data,string mean) {
        node* nn = new node;
        nn->word = data;
        nn->meaning=mean;
        nn->left = NULL;
        nn->right = NULL;

        node* temp = root;
        node* parent = nullptr;

        if (root == NULL) {
            root = nn;
        } else {
            while (temp != NULL) {
                parent = temp;
                if (nn->word > temp->word) {
                    temp = temp->right;
                } else {
                    temp = temp->left;
                }
            }

            if (nn->word < parent->word) {
                parent->left = nn;
            } else {
                parent->right = nn;
            }
        }
    }

    void inorder(node* temp) {
        if (temp != NULL) {
            inorder(temp->left);
            cout << temp->word<<endl;
            cout<<temp->meaning<<endl;
            inorder(temp->right);
        }
    }
    void preorder(node *temp){
        if(temp!=NULL){
            cout<<temp->word<<endl;
            cout<<temp->meaning<<endl;
            preorder(temp->left);
            preorder(temp->right);
        }
    }
    void postorder(node *temp){
        if(temp!=NULL){
            postorder(temp->left);
            postorder(temp->right);
            cout<<temp->word<<endl;
            cout<<temp->meaning<<endl;

        }
    }

    node* getRoot() {
        return root;
    }
    void search(string w){
        node *temp=root;
        bool found=false;
        while(temp!=NULL){
            if(w>temp->word){
                temp=temp->right;
            }
            else if(w<temp->word){
                temp=temp->left;
            }
            else{
                found=true;
                break;
            }
        }
        if(found){
            cout<<"found";
            cout<<temp->word;
            cout<<temp->meaning;
        }
        else{
            cout<<"not found";
        }
     
}
void delete_node(string key){
    node *temp=root;
    node *parent=NULL;
    
        bool found=false;
        while(temp!=NULL){
            if(key>temp->word){
                parent=temp;
                temp=temp->right;
            }
            else if(key<temp->word){
                parent=temp;
                temp=temp->left;
            }
            else{
                found=true;
                break;
            }
        }
        if(!found){
            return;
        }
            if(temp->left==NULL && temp->right==NULL){
                
                if(temp->word > parent->word){
                    parent->right=NULL;

                }
                else{
                    parent->left=NULL;
                }
                delete temp;
            return;
            }
            
            else if(temp->right==NULL && temp->left!=NULL){
            if(temp==root){
                root=temp->left;
                delete temp;

            }
            if(temp->left->word<parent->word){
                parent->left=temp->left;
            }
            else{
                parent->right=temp->left;
            }
            delete temp;
            return ;

        }
        else if(temp->right!=NULL && temp->left==NULL){
            if(temp==root){
                root=temp->right;
                delete temp;
            }
            if(temp->right->word < parent->word){
                parent->left=temp->right;

            }
            else{
                parent->right=temp->right;
            }
            delete temp;
            return;
        }
        else{
            if(temp->left!=NULL && temp->right!=NULL){
                temp=temp->left;
                while(temp->right!=NULL){
                    temp=temp->right;
                    string x=temp->word;
                    delete_node(temp->word);
                    temp->word=x;
                }
            }
        }
            
        }
};

   


int main() {
    bst b;
    int choice;
    string word, meaning, searchWord,delword;

    do {
        cout << "\nBST Operations:\n";
        cout << "1. Insert Word\n";
        cout << "2. Inorder Traversal\n";
        cout << "3. Preorder Traversal\n";
        cout << "4. Postorder Traversal\n";
        cout << "5. Search Word\n";
        cout << "6. Delete Word\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the word: ";
                cin >> word;
            cout << "Enter meaning: ";
                cin >> meaning;
                b.insertion(word, meaning);
                break;
            case 2:
                cout << "Inorder Traversal:\n";
                b.inorder(b.getRoot());
                break;
            case 3:
                cout << "Preorder Traversal:\n";
                b.preorder(b.getRoot());
                break;
            case 4:
                cout << "Postorder Traversal:\n";
                b.postorder(b.getRoot());
                break;
            case 5:
                cout << "Enter the word to search: ";
                cin >> searchWord;
                b.search(searchWord);
                break;
            case 6:
                cout<<"Enter word to delete:"<<endl;
                cin>>delword;
                b.delete_node(delword);
                b.inorder(b.getRoot());
                break;
            case 7:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 7);

    return 0;
}        