#include<bits/stdc++.h>
 using namespace std;

 void rec(int i, int n){
    if(i > n){
        return;
    }
    cout << i << endl;
    rec(i + 1, n);
 }

 int main(){

     int n = 5;
     int i = 1;

     rec(i, n);

     return 0;
 }