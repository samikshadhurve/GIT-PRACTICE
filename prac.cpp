/*#include<iostream>
#include<stack>
#include<queue>
using namespace std;

typedef struct node {
    node *l, *r;
    string word, mean;
} node;

class bst {
    node *root;

public:
    bst() {
        root = NULL;
    }

    void insertion(string m, string w) {
        node *nn = new node;
        nn->mean = m;
        nn->word = w;
        nn->l = NULL;
        nn->r = NULL;

        if (root == NULL) {
            root = nn;
        } else {
            node *temp = root;
            node *parent = NULL;

            while (temp != NULL) {
                parent = temp;
                if (nn->word > temp->word) {
                    temp = temp->r;
                } else {
                    temp = temp->l;
                }
            }

            if (nn->word > parent->word) {
                parent->r = nn;
            } else {
                parent->l = nn;
            }
        }
    }

    void inorder(node *temp) {
        if (temp != NULL) {
            inorder(temp->l);
            cout << temp->word << ": " << temp->mean << endl;
            inorder(temp->r);
        }
    }
    void preorder(node *temp) {
        if (temp != NULL) {
            cout << temp->word << ": " << temp->mean << endl;
            preorder(temp->l);
            preorder(temp->r);
        }
    }
     void postorder(node *temp) {
        if (temp != NULL) {
          
            preorder(temp->l);
            preorder(temp->r);
            cout << temp->word << ": " << temp->mean << endl;
        }
    }
     void search(string word){
        bool found =false;
        node *temp=root;
        while(temp!=NULL){
            if(temp->word>word){
            temp=temp->l;
        }
        else if(temp->word<word){
            temp=temp->r;
        }
        else{
            found =true;
            cout<<"The word is found in  dictoinary"<<endl;
            cout<<temp->word<<":"<<temp->mean<<endl;
            break;

        }
    
        }
        
    if(!found){
        cout<<"This word is not found in this dictionary!"<<endl;
    }
     }


    void del(string word){
        bool found =false;
        node *parent;
        node *temp=root;
        while(temp!=NULL){
            if(temp->word>word){
            parent=temp;           
            temp=temp->l;
        }
        else if(temp->word<word){
            parent=temp;
            temp=temp->r;
        }else{
            found =true;
            
            if(temp->l==NULL && temp->r==NULL){
                if(temp->word<parent->word){
                    parent->l=NULL;
                }
                else{
                    parent->r=NULL;
                }
                delete temp;
                return;
            }
            else if(temp->l==NULL && temp->r!=NULL){
                if(temp==root){
                    temp=temp->r;
                    delete temp;
                
                }
                if(temp->r->word<parent->word){
                    temp->r=parent->l;
                }
                else{
                    temp->r=parent->r;
                }
                delete temp;
                return;
            }
            else if(temp->r==NULL && temp->l!=NULL){
                if(temp==root){
                    temp=temp->l;
                    delete temp;
                    
                }
                if(temp->l->word>parent->word){
                      temp->l=parent->r;
                }
                else{
                    temp->l=parent->l;
                }
                delete temp;
                return;
            }
            else{
                if(temp->l!=NULL && temp->r!=NULL){
                    temp=temp->l;
                    while(temp!=NULL){
                        temp=temp->r;
                        string x=temp->word;
                        del(temp->word);
                        temp->word=x;
                    }
                }
            }

        }
        }
        
         if(!found){
        cout<<"This word is not found in this dictionary!"<<endl;
    }
    }
    void preoder1(){
        stack<node *>s;
        node *temp=root;
        if(root==NULL){
            cout<<"Empty"<<endl;
        }
        while(true){
            while(temp!=NULL){
                s.push(temp);
                cout<<temp->word<<":"<<temp->mean<<endl;
                temp=temp->l;
            }
            if(!s.empty()){
                temp=s.top();
                s.pop();
                temp=temp->r;
                
            }
            else{
                return;
            }
        }
    }
    void inorder1(){
        stack<node *>s;
        node *temp=root;
        if(root==NULL){
            cout<<"EMpty"<<endl;
        }
        
        while(true){
             while(temp!=NULL){
                 s.push(temp);
            temp=temp->l;
           
        }
        if(!s.empty()){
            temp=s.top();
            s.pop();
            cout<<temp->word<<":"<<temp->mean<<endl;
            temp=temp->r;

        }
        else{
            return;
        }
        }
       
    }
    void postorder1(){
        stack<node *>s1,s2;
        node *temp=root;
        if(root==NULL){
            cout<<"Empty"<<endl;
            return;
        }
        s1.push(temp);
        while(!s1.empty()){
            temp=s1.top();
            s1.pop();
            s2.push(temp);
            if(temp->l){
                s1.push(temp->l);
            }
            else{
                s1.push(temp->r);
            }
        }
        while(!s2.empty()){
            temp=s2.top();
            s2.pop();
            cout<<temp->word<<":"<<temp->mean<<endl;
        }




    }
    node* getroot() {
        return root;
    }
    void bfs(){
        queue<node *>q;
        node *temp=root;
        if(root==NULL){
            cout<<"Empty"<<endl;
            return;
        }
        q.push(temp);
        while(!q.empty()){

            temp=q.front();
            q.pop();
            cout<<temp->word<<":"<<temp->mean<<endl;
             if(temp->l){
            q.push(temp->l);
        }
        if(temp->r){
            q.push(temp->r);
        }
        
        }
       
    }
    void dfs(){
        stack<node *>s;
        node *temp=root;
        if(root==NULL){
            cout<<"Empty"<<endl;
            return;
        }
        s.push(temp);
        while(!s.empty()){
            temp=s.top();
            s.pop();
            cout<<temp->word<<":"<<temp->mean<<endl;
             if(temp->l){
            s.push(temp->l);
        }
        if(temp->r){
            s.push(temp->r);
        }
            
        }
    }


};

int main() {
    bst b;
    int choice;
    string word, mean;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert element\n";
        cout << "2. Display In-order ,preorder,postorder(Recursive),bfs,dfs\n";
        cout << "3. DELETE a node\n"; 
        cout << "4. Search a node\n";
        cout << "5. Display In-order ,preorder,postorder(Iterative))\n";       
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter word and meaning to insert: ";
                cin >> word >> mean;
                b.insertion(mean, word);
                break;

            case 2:
                cout << "In-order Traversal (Recursive):\n";
                b.inorder(b.getroot());
                cout << "PRE-order Traversal (Recursive):\n";
                b.preorder(b.getroot());
                cout << "post-order Traversal (Recursive):\n";
                b.postorder(b.getroot());
                cout << "bfs:\n";
                b.bfs();
                cout << "dfs:\n";
                b.dfs();

                break;

            case 3:
            cout<<"Word to delete:"<<endl;
            cin>>word;
                cout<<"Deleting a node:\n";
                b.del(word);
                cout<<"After deleting INorder:"<<endl;
                b.inorder(b.getroot());
                break;  


            case 4:
            cout<<"Word to search:";
            cin>>word;
            cout<<"Searching"<<endl;
            b.search(word);
            break;

            case 5:
                cout << "In-order Traversal (Iterative):\n";
                b.inorder1();
                cout << "PRE-order Traversal (Iterative):\n";
                b.preoder1();
                cout << "post-order Traversal (Iterative):\n";
                b.postorder1();
                break;



            case 6:
                cout << "Exiting program.\n";
                break;
             

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
*/
#include<iostream>
#include<stack>
#include<queue>
using namespace std;
struct node{
    
    node *next;
};
class graph{
    int v;
    int **arr;
    int *vis;

    public:
    graph(){
        v=0;
        arr=NULL;
        vis=NULL;
    }
    void create(){
        cout<<"Enter the number of vertices:"<<endl;
        cin>>v;
        arr=new int*[v];
        for(int i=0;i<v;i++){
            arr[i]=new int[v];
            for(int j=0;j<v;j++){
                arr[i][j]=0;

            }
        }
        vis=new int[v]();
        char ch;
        int v1,v2;
        do{
            
            cout<<"Enter the two edges v1 and v2:"<<endl;
            cin>>v1>>v2;
            if(v1>=0 && v1<v && v2>=0 && v2<v){
                arr[v1][v2]=1;
                arr[v2][v1]=1;
            }
            cout<<"Want to enter again?y or n"<<endl;
            cin>>ch;

        }while(ch=='y');
    }
    void bfs(){
        queue<int>q;
        int k;
        cout<<"Enter tthe starting point:"<<endl;
        cin>>k;
        if(v==0)
        {
            cout<<"Graph yet not created!"<<endl;
        }
        q.push(k);
        vis[k]=1;
        while(!q.empty()){
            int cn=q.front();
            q.pop();
            cout<<cn<<endl;
            for(int i=0;i<v;i++){
               if(arr[cn][i]==1 && vis[i]==0){
                q.push(i);
                vis[i]=1;
            }
            }
         
        }

    }
    void dfs(){
        int k;
        stack<int>s;
        cout<<"Enter the starting vertex:"<<endl;
        cin>>k;
        if(v==0){
            cout<<"Graph not created yet"<<endl;

        }
        else{
            s.push(k);
            vis[k]=1;
            while(!s.empty()){
                int temp=s.top();
                s.pop();
                cout<<temp<<endl;
                for(int i=0;i<v;++i){
                    if(arr[temp][i]==1 && vis[i]==0){
                        s.push(i);
                        vis[i]=1;
                    }
                }

            }


        }
    }
    void initialize_visited(){
        for(int i=0;i<v;i++){
            vis[i]=0;
        }
    }
};
int main(){
   
    graph G;
    int choice;

    do {
        cout << "\n------ Menu ------" << endl;
        cout << "1. Create Graph" << endl;
        cout << "2. BFS Traversal" << endl;
        cout << "3. DFS Traversal" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                G.create();
                break;
            case 2:
             G.initialize_visited();
                
                G.bfs();
                break;
            case 3:
                G.initialize_visited();
                G.dfs();
                break;
            case 4:
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a valid option (1-4)." << endl;
        }
    } while (choice != 4);

    return 0;
}/*
#include<iostream>
using namespace std;
typedef struct employee{
    long int phone;
    string name;
}emp;
class search{
    public:
    emp *e;
    int size;
    search(){
        e=NULL;
        size=0;
    }
    void getinfo(){
        
        cout<<"Enter the number of employee"<<endl;
        cin>>size;
        e=new emp[size];
        for(int i=0;i<size;i++){
            cout<<"Enter employee name:"<<endl;
            cin>>e[i].name;
            cout<<"Enter employee number:"<<endl;
            cin>>e[i].phone;
        }
        for(int i=0;i<size;i++){
            int j;
            int minindex=i;
            for(j=i+1;j<size;j++){
                if(e[minindex].name>e[j].name){
                    minindex=j;
                }
            }
            swap(e[i],e[minindex]);
        }
        cout<<"name of employee"<<":"<<"phone number"<<endl;
        for(int i=0;i<size;i++){
            cout<<e[i].name<<":"<<e[i].phone<<endl;
        }
    }
    void linear_search(){
        string nm;
        cout<<"Enter the name to search for phone number:";
        cin>>nm;
        bool found=false;
        for(int i=0;i<size;++i){
            if(e[i].name==nm){
                found = true;
                cout<<"The phone nuber of this employee is:"<<e[i].phone<<endl;
            }
        }
        if(!found){
            cout<<"This name not in a list"<<endl;
        }
    }
  
    void binary_search(){
        string nm;
        cout<<"Enter the name to serach :"<<endl;
        cin>>nm;
        bool found=false;
        int beg=0;
        int end=size-1;
        while(end>=beg){
            int mid=(end+beg)/2;
            if(e[mid].name==nm){
                cout<<"The phone number of employee is:"<<e[mid].phone<<endl;

            }
            else if(e[mid].name<nm){
                beg=mid+1;
            }
            else{
                beg=mid-1;
            }
        }
        if(!found){
            cout<<"Employee not in the list"<<endl;
        }
    }
    ~search(){
        delete[] e;
    }
};
int main() {
    search s;
    int choice;
    string name;

    do{
        cout << "Menu:\n1. Create employee records\n2. Linear Search\n3. Binary Search\n4. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                s.getinfo();
                break;

            case 2:
                if (s.size == 0) {
                    cout << "No records to search. Please create employee records first." << endl;
                } else {
                    
                    s.linear_search();
                }
                break;

            case 3:
                if (s.size == 0) {
                    cout << "No records to search. Please create employee records first." << endl;
                } else {
                    
                     s.binary_search();
                  
                }
                break;

            case 4:
                cout << "Exiting program." << endl;
                break;

            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
                break;
        }
    } while(choice!=4);

    return 0;
}

#include<iostream>
using namespace std;
typedef struct node{
    node *l,*r;
    int data;
    int lth,rth;
}node;
class TBT{
    public:
    node *root,*dummy;
    TBT(){
        root=NULL;
        dummy=NULL;
    }
    void insert(){
        int k;
        char ch;
        do{
        cout<<"Enter the data you want to insert:"<<endl;
        cin>>k;
        node *nn=new node;
        nn->data=k;
        nn->l=NULL;
        nn->r=NULL;
        nn->lth=1;
        nn->rth=1;
        if(root==NULL){
            dummy=new node;
            dummy->data=999;
            root=nn;
            nn->l=dummy;
            nn->r=dummy;
            dummy->l=root;
            dummy->r=root;

        }
        else{
            node *cn=root;
            while(true){
                if(cn->data>nn->data){
                    if(cn->lth==1){
                        nn->l=cn->l;
                        nn->r=cn;
                        cn->lth=0;
                        cn->l=nn;
                        break;

                    }
                    else{
                        cn->l=nn;
                    }
                }
                else{
                    if(cn->rth==1){
                        nn->r=cn->r;
                        cn->rth=0;
                        nn->l=cn;
                        cn->r=nn;
                        break;
                    }
                    else{
                        cn->r=nn;
                    }
                }
            }
        }
        cout<<"Do you want to insert again?y/n"<<endl;
        cin>>ch;

        }while(ch=='y');

       
    }
    void inorder(node *cn){
        if(root==NULL){
            cout<<"Empty!"<<endl;
        }
        while(cn!=dummy){
            while(cn->lth==0){
                cn=cn->l;
            }
            cout<<cn->data;
             while(cn->rth==1){
            cn=cn->r;
            if(cn==dummy){
                return;
            }
            cout<<cn->data;
        }
        cn=cn->r;

        }
    }
    void preorder(node *cn){
        if(root==NULL){
            cout<<"Empty!"<<endl;
        }
        while(cn!=dummy){
            while(cn->lth==0){
                cout<<cn->data;
                cn=cn->l;
            }
            while(cn->rth==1){
                cn=cn->r;
                if(cn==dummy){
                    return;
                }
                
            }
            cn=cn->r;
        }
    }

    void postorder(node *cn){
        int post[30];
        int i=0;

        while(cn!=dummy){
            while(cn->rth==1){
              
                post[i]=cn->data;
                i++;
                cn=cn->r;

            
            }
            post[i]=cn->data;
            i++;
            while(cn->lth==1){
                cn=cn->l;
                if(cn==dummy){
                    return;
                }
            }
        }
        for(int j=i-1;j>=0;j--){
            cout<<cn->data<<endl;
        }
        
    }


};
int main()
{
    TBT b;
    int key;
    int choice;
    do
    {   cout<<"\n";
        cout << "*****  Menu  *****" << endl;
        cout << " 1.Insert" << endl;
        cout << " 2. Inorder" << endl;
        cout << " 3. Preorder" << endl;
        cout << " 4. Exit" << endl;
        cout<<" 5.post"<<endl;

        cout << " Enter the choice " << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            int c;
            cout<<"Enter the number of data you want to insert"<<endl;
           b.insert();
            break;

        case 2:
            b.inorder(b.root);
            break;

        case 3:
            b.preorder(b.root);
            break;

        case 4:
            return 0;
            
        case 5:
           b.postorder(b.root);
        }

    } while (choice != 4);
    return 0;
}

#include<iostream>
#include<string>
using namespace std;
class node{
    public:
    string meaning;
    string word;
    node *left;
    node *right;

};
class AVL{
     public:
    node *root;
   
    AVL(){
        root=NULL;
    }
    node* insert(node *temp,const string& word,const string& meaning){
        if(temp==NULL){
            temp=new node;
            temp->word=word;
            temp->meaning=meaning;
            temp->left=temp->right=NULL;
        }  
        else{
            if(temp->word>word){
                temp->left=insert(temp->left,word,meaning);
            }
            else{
                temp->right=insert(temp->right,word,meaning);
            }
        }
        int balance=height(temp->left)-height(temp->right);
        if(balance>1){
            if(word<temp->left->word){
                return LL(temp);
            }
            else{
                return LR(temp);
            }
        }
        if(balance<-1){
            if(word>temp->right->word){
                return RR(temp);
            }
            else{
                return RL(temp);
            }
        }
        return temp;
    }
    int height(node *temp){
        if(temp==NULL){
            return -1;
        }
        int rightheight=height(temp->right);
        int leftheight=height(temp->left);
        return 1+ (leftheight>rightheight ? leftheight : rightheight);
    }
    node* LL(node *parent){
        node *temp=parent->left;
        parent->left=temp->right;
        temp->right=parent;
        return temp;
    }
    node* RR(node *parent){
        node *temp=parent->right;
        parent->right=temp->left;
        temp->left=parent;
        return temp;
    }
    node *LR(node *parent){
        parent->left=RR(parent->left);
        return LL(parent);
    }
    node *RL(node *parent){
        parent->right=LL(parent->right);
        return RR(parent);
    }
    void search(){
        string wd;
        cout<<"Enter the word to search:"<<endl;
        cin>>wd;
        node *temp=root;
        bool found=false;
        while(temp!=NULL){
            if(wd<temp->word){
                temp=temp->left;
            }   
            else if(wd>temp->word){
                temp=temp->right;
            }  
            else{
                found=true;
                cout<<"The word found in dictionary!"<<endl;
                cout<<temp->word<<"-"<<temp->meaning<<endl;
            }  
        }
        if(!found){
            cout<<"Word not found in dictionary";
        }
    }
    void inorder(node* temp) {
        while (temp != nullptr) {
            inorder(temp->left);
            cout << "Word: " << temp->word << " - Meaning: " << temp->meaning << "\n";
            inorder(temp->right);
        }
    }
    void create(){
        char ch;
        string word,meaning;
        do{
            cout<<"Enter the word:"<<endl;
            cin>>word;
            cout<<"Enter the meaning:"<<endl;
            cin>>meaning;
            root=insert(root,word,meaning);
            cout<<"The root of tree is:"<<root->word<<":"<<root->meaning<<endl;
            cout<<"Do you want to add a word in dictionary?y/n"<<endl;
            cin>>ch;
        }while(ch!='n');
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
                avl.inorder(avl.root);
                break;
            case 3:
               
                avl.search();
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



*/