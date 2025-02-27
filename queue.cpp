#include<iostream>
using namespace std;
class Que{
    int maxsize;
    int Q[20];
    int front;
    int rear;
    public:
    Que(){
        front=-1;
        rear=-1;
        int maxsize=6;
        }
    int isQempty(){
        if(rear==-1 && front==-1 || front>rear){
            return 1;
        }
        else{
            return 0;
        }
    }
    int isQfull(){
        if(rear==maxsize-1){
            return 1;
        }
        else{
            return 0;
        }
    }
    void enQ(int val){
        if(isQfull()){
            cout<<"The queue is full!"<<endl;
        }
        else if(front==-1 && rear==-1){
            
            rear=0;
            front=0;
            Q[rear]=val;
            

        }
        
        else{
            Q[++rear]=val;
        }
    }
    void delQ(){
        if(isQempty()){
            cout<<"empty!"<<endl;
        }
        else if(front==rear){
            front=rear=-1;
        }
        else{
            cout<<"deleted queue:"<<Q[front]<<endl;
            front++;
        }
    } 
    void peek(){
        if(isQempty()){
            cout<<"empty!"<<endl;
        }
        else{
            cout<<"top element"<<endl;
            cout<<Q[front]<<endl;

        }
    }
    void display(){
        if(isQempty()){
            cout<<"empty!"<<endl;

        }
        else{
            for(int i=front;i<rear+1;i++){
                cout<<Q[i];
            }
        }
    }   
    
};
int main(){
    Que a;
    int n,m,k;
    cout<<"Enter the no of elements:"<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"enter elements:"<<endl;
        cin>>m;
        a.enQ(m);

    }
    do{
        cout<<"Enter choice:1.delete,2.peek"<<endl;
        cin>>k;
        switch(k){
            case 1:
            a.delQ();
            a.display();
            break;
            case 2:
            a.peek();
            a.display();
            break;
            default:
            cout<<"InvLID";

        }
    
    }while(k!=3);
    return 0;




}