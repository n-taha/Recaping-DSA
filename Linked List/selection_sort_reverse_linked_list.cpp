#include<bits/stdc++.h>
 using namespace std;

 class Node{
	public:
		int value;
		Node *next;

		Node(int value){
			this->value = value;
			this->next = NULL;
		};
 };

 void insert_at_tail(Node* &head, Node*& tail, int value){
	 Node *newnode = new Node(value);
	 if (head == NULL){
		 head = newnode;
		 tail = newnode;
	 }else{
		 tail->next = newnode;
		 tail = newnode;
	 }
 }

 void sort_linked_list(Node* head){
	 for (Node *i = head; i->next != NULL; i = i->next){
		 for (Node *j = i->next; j != NULL; j = j->next){
			if(i->value > j->value){
				swap(i->value, j->value);
			}
		 }
	 }
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

	while (true){
		int value;
		cin >> value;
		if (value == -1){
			break;
		}
		insert_at_tail(head, tail, value);
	}

	sort_linked_list(head);
	print_linked_list(head);

	return 0;
 }