#include<iostream>
using namespace std;
class mat{
    int col,rows;
    int **matrix;
    public:
    mat(int r,int c){ 
        matrix=new int*[rows];
        for(int i=0;i<rows;i++){
            matrix[i]=new int[col];

        }
    }
    void read(){
        for(int i=0;i<rows;i++){
            for(int j=0;j<col;j++){
                cout<<"Read elements:"<<endl;
                cin>>matrix[i][j];
            }
        }
    }
    void print(){
        for(int i=0;i<col;i++){
            for(int j=0;j<col;j++){
                cout<<matrix[i][j];
            }
        }
    }
    
};
int main(){
    mat mat1(3,3);
    mat mat2(3,3);
     mat1.read();
     mat2.read();
     
    return 0;
    
}
