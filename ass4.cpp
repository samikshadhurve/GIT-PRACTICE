#include<iostream>
using namespace std;
struct node{
    int data;
   
    node *next;
};
class stack{
     node *top;
    public:
    stack(){
        top=NULL;
    }
    int isempty(){
        if(top==NULL){
            return 1;
        }
        else{
            return 0;

        }
    }
    void push(int val){
        node *nn=new node;
        nn->data=val;
        if(top==NULL){
            top=nn;
        }
        
        nn->next=top;
        top=nn;
    }
    void pop(){
        if(isempty()){
            cout<<"The stack is empty"<<endl;
            return;
        }
        node *temp=top;
        top=top->next;
        free(temp);
        temp=NULL;
        cout<<"deleted data"<<temp->data<<endl;

    }
    int peek(){
       if(!isempty()){
        return top->data;
       }
       return -1;
    }
    void display(){
        if(isempty()){
            cout<<"empty"<<endl;
            return;
        }
        node *temp=top;
        while(temp!=NULL){
            cout<<"data:"<<temp->data<<endl;
            temp=temp->next;
        }
        
    }
    
};
int main(){
    stack s;
    int n,m;
    cout<<"entr no of elements"<<endl;
    cin>>n;
    for(int i=0;i<n;i++ ){
        cout<<"elemnt:"<<endl;
        cin>>m;
        s.push(m);
    }
    cout<<"popping"<<endl;
    s.pop();
    s.display();
    cout<<"peeking"<<endl;
    s.peek();
    s.display();
    return 0;



}
