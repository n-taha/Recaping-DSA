#include<bits/stdc++.h>
 using namespace std;

 class Node{
	public:
	int value;
	Node *next;
	Node *prev;

	Node(int value){
		this->value = value;
		this->next = NULL;
		this->prev = NULL;
	}
 };

 int size_list(Node *head){
	 int count = 0;
	 Node *temp = head;
	 while(temp != NULL){
		 temp = temp->next;
		 count++;
	 }
	 return count;
 }

 void insert_at_head(Node* &head, Node* &tail, int value){
	 Node *newNode = new Node(value);
	 if (head == NULL){
		 head = newNode;
		 tail = newNode;
		 return;
	 }

	 newNode->next = head;
	 head->prev = newNode;
	 head = newNode;
 }

 void insert_at_tail(Node* &head, Node* &tail, int value){
	 Node *newNode = new Node(value);
	 if(tail == NULL){
		 head = newNode;
		 tail = newNode;
		 return;
	 }
	 tail->next = newNode;
	 newNode->prev = tail;
	 tail = newNode;
 }

 void insert_at_any_position(Node* &head, Node* &tail, int position, int value){
	if(position > size_list(head)){
		cout << "invalid index";
		return;
	}else if (position == size_list(head)){
		insert_at_tail(head, tail, value);
		return;
	} else if (position == 0){
		insert_at_head(head, tail, value);
	} else{
		Node *temp = head;
		Node *newNode = new Node(value);
		for (int i = 1; i <= position - 1; i++){
			temp = temp->next;
		}
		newNode->next = temp->next;
		temp->next = newNode;
		newNode->prev = temp;
		newNode->next->prev = newNode;
	}
 }

 void print_linked_list_forward(Node* head){
	 Node *temp = head;
	 while(temp != NULL){
		 cout << temp->value << " ";
		 temp = temp->next;
	 }
	 cout << endl;
 }

 void print_linked_list_backward(Node *tail){
	 Node *temp = tail;
	 while(temp != NULL){
		 cout << temp->value << " ";
		 temp = temp->prev;
	 }
	 cout << endl;
 }

 void delete_at_head(Node* &head){
	 if(head != NULL){
		 Node *deleteNode = head;
		 head = head->next;
		 head->prev = NULL;
		 delete deleteNode;
	 }
 }

 void delete_at_tail(Node* &tail){
	if(tail != NULL){
		Node *deletenode = tail;
		tail = tail->prev;
		tail->next = NULL;
		delete deletenode;
	}
 }

 void delete_at_any_position(Node* &head, Node* &tail, int position){
	if(position > size_list(head)){
		cout << "Invalid Position";
		return;
	} else if(position == size_list(head)){
		delete_at_tail(tail);
		return;
	} else if(position == 0){
		delete_at_head(head);
		return;
	} else{
		Node *temp = head;
		for (int i = 1; i <= position - 1; i++){
			temp = temp->next;
		}
		Node *deletenode = temp->next;
		temp->next = temp->next->next;
		temp->next->prev = temp;
		delete deletenode;
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
	 insert_at_any_position(head, tail, 0, 5);

	 insert_at_any_position(head, tail, 6, 7);

	 insert_at_any_position(head, tail, 3, 2);
	 delete_at_any_position(head, tail, 3);
	 delete_at_head(head);
	 delete_at_tail(tail);

	 print_linked_list_forward(head);
	 print_linked_list_backward(tail);



	 cout << head->value << endl;
	 cout << tail->value << endl;
	 return 0;
 }