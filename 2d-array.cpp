// Online C++ compiler to run C++ program online ..
#include <iostream>
using namespace std;
/*

 2D Array Operations
____________________________________________________________
1. Create or Take input dynamically 
2. Read / Traverse
3. Sum elements per row or columb wise
Total Sum and Diagonal Sum
4. Create Transpose Matrix
5. Find Max value
6. Find Second Max
7. Find Duplicate 
8. Update by value
9. Update by index
10. Serarch value by index

*/
int main() {
    
     //
     int row,colm;
     
     cout<<"Enter Row: ";
     cin>>row;
     cout<<"Enter Colum: ";
     cin>>colm;
    cout<<endl;
    int matrix[row][colm];

     //Matrix input
     cout<<"Enter Elements"<<endl;
      for (int i = 0; i < row; i++)
     {
        for (int j = 0; j < colm; j++)
        {
            cin>>matrix[i][j];
        }
        
     };
     cout<<endl;

     //traversal 
     cout<<"Your Matrix is "<<endl;
     for (int i = 0; i < row; i++)
     {
        for (int j = 0; j < colm; j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
     }
     cout<<endl;
     //sum all elements of matrix

     int sumColm=0,sumRow=0,sumTotal=0;
     for (int i = 0; i < row; i++)
     {
        for (int j = 0; j < colm; j++)
        {
            sumColm=sumColm+matrix[i][j];
            sumRow=sumRow+matrix[j][i];
            sumTotal=sumTotal+matrix[i][j];
        }
       // cout<<i+1 <<" Row's All colum's Summation is "<<sumColm<<endl;
        //cout<<i+1 <<" Col's All row's Summation is "<<sumRow<<endl;
        cout<<"Row "<<i+1<<" Sum: "<<sumColm<<endl;
        cout<<"Col "<<i+1<<" Sum: "<<sumRow<<endl;
        cout<<endl;
        sumColm=0;
        sumRow=0;
        
     }
     int sumDiagon=0;
     for (int i = 0; i < row; i++)
     {
        sumDiagon=sumDiagon+matrix[i][i];
     }
     
     cout<<"Total Sum: "<<sumTotal<<endl;
     cout<<"Total Dia: "<<sumDiagon<<endl;

     //Transpose Matrix
     int transpose[row][colm];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < colm; j++)
        {
            transpose[i][j]=matrix[j][i];
        }
        
    }
    cout<<"Transpose Matrix"<<endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < colm; j++)
        {
            cout<<transpose[i][j]<<" ";
        }
        cout<<endl;
    }
    
    //Find Max value 

    //Update by index

    //Update by value 

    return 0;
}
