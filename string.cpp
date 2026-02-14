//string
#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
void printString(const char name[]){
   for (int i = 0; name[i]!='\0'; i++)
   {
    cout<<name[i];
   }
   cout<<endl;
}
void printStringByPointer(const char* ptr){
    while(*ptr){
        cout<<*ptr;
        ptr++;
    }
    cout<<endl;
}

int main(){
  

  printString("Mr Jhon Show");//immutable value pass
  char s[]="Mr Jhone Doe";
  printStringByPointer(s);
  
   // reverse string 

   char str[]="EMON";
   for (int i = 0; i; i++)
   {
    /* code */
   }
   
   return 0;
}
