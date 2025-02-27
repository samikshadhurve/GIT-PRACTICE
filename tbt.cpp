#include<iostream>
#include<stack>
using namespace std;
typedef struct node{
int data,lth,rth;
node*left,*right;

}node;

class TBT{
    private:
    node*root;
     node *dummy;
      public:
     TBT(){
    root=NULL;
    dummy=NULL;
}
   void insert(){
    char ch;
do{
    node*nn=new node;
    int data;
    cout<<"enter the data you want to insert :";
    cin>>data;
    nn->data=data;
    nn->left=NULL;
    nn->right=NULL;
    nn->lth=1;
    nn->rth=1;
    if(root==NULL){
    dummy=new node;
    dummy->data=9999;
    root=nn;
    nn->left=dummy;
    nn->right=dummy;
    dummy->left=root;
    dummy->right=root;

}
    else{
        node*cn=root;
        while(1){
            if(nn->data<cn->data){
        if(cn->lth==1){
        nn->left=cn->left;
        nn->right=cn;
        cn->lth=0;
        cn->left=nn;
        break;


}
    else{
        cn=cn->left;
}
}
        else if(nn->data>cn->data){
        if(cn->rth==1){
        nn->right=cn->right;
        nn->left=cn;
        cn->rth=0;
        cn->right=nn;
        break;
}
    else{
        cn=cn->right;
}
}
}
}
    cout<<"do you want to insert more?";
    cin>>ch;
    }while(ch=='y');
}
    void inorder(){
    node *cn=root;
    while(cn!=dummy){
    while(cn->lth==0){
    cn=cn->left;
}
    cout<<cn->data;
    while (cn->rth==1){
    cn=cn->right;
    if(cn==dummy){
        return;
}
    cout<<cn->data;
}
    cn=cn->right;
}
}
    void preorder() {
    if (root == NULL) {
    cout << "Tree is empty." << endl;
    return;
}
    node* cn = root;

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
    


};
int main(){
TBT tbt;
int choice;
do{
cout<<"\nMENU"<<endl;
cout<<"1.create tbt"<<endl;
cout<<"2.inorder traversal"<<endl;
cout<<"3.preorder traversal"<<endl;
cout<<"4.postorder"<<endl;
cout<<"5.exit"<<endl;
cout<<"enter the choice :";
cin>>choice;
switch(choice){
case 1:
tbt.insert();
break;
case 2:
tbt.inorder();
break;
case 3:
tbt.preorder();
break;

case 5:
cout<<"exit";
break;
default:

cout<<"invalid choice"<<endl;
break;
}
}while(choice!=4);
}