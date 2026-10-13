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

    Node* head = NULL;
    Node *tail = NULL;

    while(true){
        int value;
        cin >> value;
        if(value == -1){
            break;
        }
        insert_at_tail(head, tail, value);
    }
    printing_linked_list(head);

    return 0;
}