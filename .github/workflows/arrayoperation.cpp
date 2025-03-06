#include<iostream>
using namespace std;



void accept(){
	int a[10][10]
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>a[i][j];
        }
    }
void display(){
	int a[10][10];
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<a[i][j];
        }
    }
}    

}
int main(){
    int row,col;
    cout<<"enter the rows and column"<<endl;
    cin>>row>>col;
    accept(a);
    display(a);
    return 0;
}
