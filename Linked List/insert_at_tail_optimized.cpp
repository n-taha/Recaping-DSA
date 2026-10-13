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

void printing_linked_list(Node* head){
    Node *temp = head;
    while(temp != NULL){
        cout << temp->value << " ";
        temp = temp->next;
    }
}

void insert_at_tail(Node* &head,Node *&tail, int value){
    Node *newnode = new Node(value);
    if (head == NULL){
        head = newnode;
        tail = newnode;
    }

    tail->next = newnode;
    tail = newnode;
}

int main(){

    Node *head = new Node(10);
    Node *a = new Node(20);
    Node *tail = new Node(30);

    head->next = a;
    a->next = tail;
    insert_at_tail(head, tail, 40);
    insert_at_tail(head, tail, 50);
    insert_at_tail(head, tail, 60);
    printing_linked_list(head);

    cout << endl << "Tail = " << tail->value << endl;

    return 0;
}