#include<bits/stdc++.h>
 using namespace std;

 class Node{
    public:
        int value;
        Node *next;

    Node(int value){
        this->value = value;
        this->next = NULL;
    }
 };

 void insert_at_tail(Node* &tail, Node* &head, int value){
     Node *newnode = new Node(value);
     if(head == NULL){
         head = newnode;
         tail = newnode;
         return;
     }
     tail->next = newnode;
     tail = newnode;
 }

 void reverse_print(Node* temp){
     if(temp == NULL){
         return;
     }
     reverse_print(temp->next);
     cout << temp->value << " ";
}

void print_linked_list(Node* head){
    Node *temp = head;
    while(temp != NULL){
        cout << temp->value << " ";
        temp = temp->next;
    }
}

 int main(){
     Node *head = NULL;
     Node *tail = NULL;

     while(true){
         int value;
         cin >> value;
         if(value == -1){
            break;
         }
         insert_at_tail(tail, head, value);
     }

     reverse_print(head);
    //  print_linked_list(head);

     return 0;
 }