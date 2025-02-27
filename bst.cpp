#include <iostream>
#include<stack>
#include<queue>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;
};

class bst {
    node* root;

public:
    bst() {
        root = NULL;
    }

    void create(int val) {
        node* nn = new node;
        nn->data = val;
        
        nn->left = NULL;
        nn->right = NULL;

        node* temp = root;
        node* parent = nullptr;

        if (root == NULL) {
            root = nn;
        } else {
            while (temp != NULL) {
                parent = temp;
                if (nn->data > temp->data) {
                    temp = temp->right;
                } else {
                    temp = temp->left;
                }
            }

            if (nn->data< parent->data) {
                parent->left = nn;
            } else {
                parent->right = nn;
            }
        }
    }

    void inorder(node* temp) {
        if (temp != NULL) {
            inorder(temp->left);
            cout << temp->data<<endl;
            
            inorder(temp->right);
        }
    }

    node* getRoot() {
        return root;
    }
    void search(int va){
        node *temp=root;
        bool found=false;
        while(temp!=NULL){
            if(va>temp->data){
                temp=temp->right;
            }
            else if(va<temp->data){
                temp=temp->left;
            }
            else{
                found=true;
                break;
            }
        }
        if(found){
            cout<<"found";

        }
        else{
            cout<<"not found";
        }
     
}
void delete_node(int key){
    node *temp=root;
    node *parent=NULL;
    
        bool found=false;
        while(temp!=NULL){
            if(key>temp->data){
                parent=temp;
                temp=temp->right;
            }
            else if(key<temp->data){
                parent=temp;
                temp=temp->left;
            }
            else{
                found=true;
                if(temp->left==NULL && temp->right==NULL){
                
                if(temp->data > parent->data){
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
            if(temp->left->data<parent->data){
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
            if(temp->right->data < parent->data){
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
                    int x=temp->data;
                    delete_node(temp->data);
                    temp->data=x;
                }
            }
        }
            }
        }
        if(!found){
            cout<<"Word not found!"<<endl;
        }
            
            
        }
        void inorder1(){
            stack<node *>s;
            node *cn=root;
            while(true){
                while(cn!=NULL){
                    s.push(cn);
                    cn=cn->left;

                }
                if(!s.empty()){
                    cn=s.top();
                    s.pop();
                    cout<<cn->data;
                    cn=cn->right;
                }
                else{
                    return;
                }
            }
        }
        void preorder1(){
            stack<node *>s;
            node *cn=root;
            
               if(cn==NULL){
                cout<<"Empty!"<<endl;
               }
               
            while(true){
                while(cn!=NULL){
                    s.push(cn);
                    cout<<cn->data;
                    cn=cn->left;
                }
            
            if(!s.empty()){
                cn=s.top();
                s.pop();
                cn=cn->right;
            }
            else{
                return;
            }
            }
        }
        void postorder1(){
            if(root==NULL){
                cout<<"Empty!"<<endl;
                return;
            }
            node *cn=root;
            stack<node *>s1,s2;
            s1.push(cn);
            
            while(!s1.empty()){
                cn=s1.top();
                s1.pop();
                s2.push(cn);
                if(cn->left){
                    s1.push(cn->left);
                }
                else{
                    s2.push(cn->right);
                }
                
            }
            while(!s2.empty()){
                cn=s2.top();
                s2.pop();
                cout<<cn->data;
            }
        }
        void bfs(){
            if(root==NULL){
                cout<<"Empty!"<<endl;
                return;
            }
            else{
                node *cn=root;
                queue<node *>q;
                q.push(cn);
                while(!q.empty()){
                    cn=q.front();
                    q.pop();                   
                    cout<<cn->data;
                    if(cn->left){
                        q.push(cn->left);
                    }
                    if(cn->right){
                        q.push(cn->right);
                    }
                }
            }
        }
       
    
};


int main() {
    bst b;
    int choice, val;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert element\n";
        cout << "2. Display In-order (Recursive)\n";
        cout << "3. Delete element\n";
        cout << "4. Display In-order (Iterative)\n";
        cout << "5. Display Pre-order (Iterative)\n";
        cout << "6. Display Post-order (Iterative)\n";
        cout << "7. Display BFS (Level-order)\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> val;
                b.create(val);
                break;

            case 2:
                cout << "In-order Traversal (Recursive):\n";
                b.inorder(b.getRoot());
                break;

            case 3:
                cout << "Enter value to delete: ";
                cin >> val;
                b.delete_node(val);
                cout << "In-order Traversal after deletion:\n";
                b.inorder(b.getRoot());
                break;

            case 4:
                cout << "In-order Traversal (Iterative):\n";
                b.inorder1();
                break;

            case 5:
                cout << "Pre-order Traversal (Iterative):\n";
                b.preorder1();
                break;

            case 6:
                cout << "Post-order Traversal (Iterative):\n";
                b.postorder1();
                break;

            case 7:
                cout << "BFS Traversal (Level-order):\n";
                b.bfs();
                break;

            case 8:
                cout << "Exiting the program." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 8);

    return 0;
}