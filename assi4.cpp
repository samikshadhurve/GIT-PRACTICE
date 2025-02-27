/*#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

class stack {
    node* top;

public:
    stack() {
        top = NULL;
    }

    int isempty() {
        return top == NULL;
    }

    void push(int val) {
        node* nn = new node;
        nn->data = val;
        nn->next = top;
        top = nn;
    }

    void pop() {
        if (isempty()) {
            cout << "The stack is empty" << endl;
            return;
        }
        node* temp = top;
        top = top->next;
        cout << "Deleted data: " << temp->data << endl;
        delete temp; // Use delete instead of free
    }

    int peek() {
        if (isempty()) {
            return 0;
        }
        else{
            return top->data;
        }

    }

    void display() {
        if (isempty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        node* temp = top;
        while (temp != NULL) {
            cout << "data: " << temp->data << endl;
            temp = temp->next;
        }
    }
};

int main() {
    stack s;
    int n, m;
    cout << "Enter the number of elements: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Element " << i + 1 << ": ";
        cin >> m;
        s.push(m);
    }
    
    cout << "Popping" << endl;
    s.pop();
    s.display();

    cout << "Peeking" << endl;
    
    int peekValue = s.peek();
    if (peekValue != 0) {
        cout << "Top element: " << peekValue << endl;
    } else {
        cout << "The stack is empty." << endl;
    }


    return 0;
}*/
#include<iostream>
using namespace std;
struct node{
    int data;
    node *next;
};
class Q{
    private:
    node *front;
    node *rear;
    public:
    Q(){
        front=NULL;
        rear=NULL;
    }
    int isempty(){
        if(front==NULL && rear==NULL || front>rear){
            return 1;
        }
        else{
            return 0;
        }
    }
    void enQ(int val){
        node *nn=new node;
        nn->data=val;
        nn->next=NULL;
        if(front==0 && rear==0){
            front=rear=nn;
        }
        else{
            rear->next=nn;
            rear=nn;
        }

    }
    void delQ(){
        if(isempty()){
            cout<<"Empty"<<endl;
        }
        else{
            node *temp=front;
            front=front->next;
            cout<<"deleted data"<<temp->data<<endl;
            delete temp;
        }
    }
    void display(){
        if(isempty()){
            cout<<"Empty"<<endl;
        }
        else{
            node *temp=front;
            while(temp!=NULL){
                cout<<temp->data<<endl;
                temp=temp->next;
            }
        }
    }
};
int main(){
    Q a;
    int n,m;
    cout<<"Enter no of elements:"<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"elements:"<<endl;
        cin>>m;
        a.enQ(m);
    }
    cout<<"pop"<<endl;
    a.delQ();
    cout<<"displaying"<<endl;
    a.display();
    return 0;

}
