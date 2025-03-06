#include<iostream>
using namespace std;
class poly{
    private:
    int terms;
    int coeff[10];
    int expo[10];
    public:
    void accept(){
        
        cout<<"Enter the no of terms: "<<endl;
        cin>>terms;
        cout<<"Enter the coefficient and exponent in descending order: "<<endl;
        for(int i=terms;i>0;i--){
            cout<<"enter coefficient"<<endl;
            cin>>coeff[i];
            cout<<"enter exponent"<<endl;
            cin>>expo[i];
        }
    
    }
    void display(){
        
       
        cout<<"the polynomial you entered is:"<<endl;
        for(int i=terms;i>=0;i--)
        {
            if(coeff[i]!=0){
                cout<<coeff[i];
            }
            if(i>=0){
                cout<<"x^"<<expo[i];
            }
            if(i!=0){
                cout<<"+";
            }
        
       
        
        }
        
       
        
        
        cout<<endl;
        }
        int add(poly p1,poly p2){
            
            int i=0,j=0,k=0;
            poly p3;
            while(i<=p1.terms && j<=p2.terms){
                if(p1.expo[i]==p2.expo[j]){
                    p3.coeff[k]=p1.coeff[i]+p2.coeff[j];
                    p3.expo[k]=p1.expo[i];
                    i++;
                    j++;
                    k++;
                    continue;
                }
                else if(p1.expo[i]>p2.expo[j]){
                    p3.coeff[k]=p1.coeff[i];
                    p3.expo[k]=p1.expo[i];
                    k++;i++;
                    continue;
                   

                }
                else{
                    p3.coeff[k]=p2.coeff[j];
                    p3.expo[k]=p2.expo[j];
                    k++;j++;
                    
                    continue;
                }
            }
                

            
            while(i<p1.terms){
                p3.coeff[k]=p1.coeff[i];
                p3.expo[k]=p1.coeff[i];
                j++; k++;
                
               
                

            }
            while(j<p2.terms){
                p3.coeff[k]=p2.coeff[j];
                p3.expo[k]=p2.expo[j];
                j++; k++;
                
            }
              
               	 cout<<"addition:"<<endl; 
                
            cout<<k<<endl;
            for(int m=0;m<k;m++){
            
                cout<<p3.coeff[m]<<"x^"<<p3.expo[m]<<"+"<<0;
                
           
        
          
            }
        
       
        
        
                
        cout<<endl;    
            




        
    }
};    
    int main(){
        poly p1,p2,p3;
        p1.accept();
        
        p2.accept();
        p1.display();
        p2.display();
        p3.add(p1,p2);
        return 0;



    }




