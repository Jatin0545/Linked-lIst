#include<iostream>
using namespace std;

class Node{
	public:	
	char data;
	Node* next;
	Node* prev;
	
};

//to add node at front
int push(Node** head_ref,char value){
	Node* newnode=new Node();//allocating sapce for new node
	newnode->data=value;//passing the value in newnode
	newnode->prev=NULL;//as it will be the node at front,previous of first node is NULL
	newnode->next=*head_ref;//the newnode will be at front, so next of newnode will
	//point to head of previous list,if list is not null
	if(*head_ref!=NULL){
		(*head_ref)->prev=newnode;
	}
	*head_ref=newnode;//making the new node as head
}
//to print the doubly linked list
int print(Node* n){
	while(n!=NULL){
		cout<<n->data<<" ";
		n=n->next;
}
}
//to rotate linked list anti-clockwise by N nodes
int rotate(Node** head_ref,int n){
	
	for(int i=0;i<n;i++){
	    Node* p=*head_ref;
		Node* last=p->next;
		while(last->next!=NULL){
			last=last->next;
		}
		last->next=p;
		*head_ref=p->next;
		p->next->prev=NULL;
		p->prev=last;
		p->next=NULL;
	}
	cout<<"doubly linked list is : ";
	print(*head_ref);
}
int main(){
	Node* head=NULL;
	push(&head,'h');
	push(&head,'g');
	push(&head,'f');
    push(&head,'e');
	push(&head,'d');
	push(&head,'c');
	push(&head,'b');
	push(&head,'a');	
	cout<<"The Doubly linked list is : ";
	print(head); 
	cout<<endl;
	rotate(&head,4);
}
