#include<bits/stdc++.h>
#include<conio.h>
using namespace std;


//crate array
int* createArray(int size){
    int* array= new int[size];
    for (int i = 0; i <size; i++)
    {
        cin>>array[i];
    }
    return array;
}
//print array
void printArray(int array[]){
    for (int i = 0; i <8; i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<endl;
}
//insert element by index
void insertElentByIndex(int array[],int index,int value){
 for (int i = 7; i >index; i--)
    {
        array[i]=array[i-1];
    }
    array[index]=value;

}
//Delete by Index
void deleteByIndex(int array[],int index){
    for(int i=index;i<8-1;i++){
        array[i]=array[i+1];
        //array[i-1]=array[i] --->i=index+1
  }}
//Reverse Element
  void reverseElement(int array[],int size){
    int temp;
    for (int i = 0; i<=size/2; i++)
    {
        temp=array[i];
        array[i]=array[size-1-i];
        array[size-1-i]=temp;
    }
}
// swap function
void swap(int a,int b){
    int temp=a;
    a=b;
    b=temp;
}
int main(){
    //int* array=createArray(7);
    int array[8]={1,2,3,4,5,6,7,8};
    printArray(array);
    int index,value;
    //cin>>index;
    //cin>>value;
    //insertElentByIndex(array,index,value);
   // deleteByIndex(array,index);
   // reverseElement(array,8);
    for (int i = 0; i<8; i++)
    {
       // int a=array[i],b=array[7-i];
        int temp;
        if(i<7-i){
            //swap(a,b);
            temp=array[i];
            array[i]=array[7-i];
            array[7-i]=temp;
        }
    }
    
    printArray(array);
    //delete[] array;
    
    return 0;
}
