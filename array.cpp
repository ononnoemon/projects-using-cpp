// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int main() {
    
    //prime number
    int a[7]={10,17,15,42,97,3,22};
    int out[7];
    int index=0;
    int isPrime=1;
    for(int i=0;i<7;i++){
        for(int j=2;j<a[i];j++){
            if(a[i]%j==0){
                isPrime=0;
                break;
            }
            isPrime=1;
        }
        
        if(isPrime==1){
           // cout<<a[i]<<endl;
           out[index]=a[i];
           index++;
        }
    }
    for(int i=0;i<index;i++){
        cout<<out[i]<<endl;
     };

    return 0;
}
