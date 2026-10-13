#include<bits/stdc++.h>
 using namespace std;

 class Node{
    public:
        int value;
        Node* next;
 };

 int main(){

     Node a, b, c;
     a.value = 10;
     b.value = 20;
     c.value = 30;

     a.next = &b;
     b.next = &c;

     cout << a.value << " " << a.next->value << " " << a.next->next->value;

     return 0;
 }