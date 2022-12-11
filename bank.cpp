#include<bits/stdc++.h>
#include<conio.h>
using namespace std;

struct acc{
    string name;
    int age;
}s[3];
int main(){
    //struct acc s[3];
    s[0].name="rahim";
    s[1].name="karim";
    s[2].name="lira";
    cout<< s[0].name<<" "<< s[1].name<<" "<< s[2].name<<endl;
    getch();
}
