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

 void insert_at_tail(Node *&head, Node *&tail, int value){
     Node *newnode = new Node(value);
     if(head == NULL){
         head = newnode;
         tail = newnode;
         return;
     }
     tail->next = newnode;
     tail = newnode;
 }

 void print_linked_list(Node* head){
     Node *temp = head;
     while(temp != NULL){
         cout << temp->value << " ";
         temp = temp->next;
     }
 }

 void delete_at_any_postion(Node* head, int index){
     Node *temp = head;
     for (int i = 0; i < index - 1; i++){
         temp = temp->next;
     }

     Node *deletenode = temp->next;
     temp->next = temp->next->next;
     delete deletenode;
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
         insert_at_tail(head, tail, value);
     }

     print_linked_list(head);
     delete_at_any_postion(head, 2);
     cout << endl
          << "Head -> " << head->value << endl;
     print_linked_list(head);
     return 0;
 }