#include<iostream>
using namespace std;

class Node{
	public:
	int data;
	Node* next;
	Node* prev;
};
//to add node at front
int push(Node** head_ref,int value){
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
//to reverse a doubly linked list
int reverse(Node** head_ref){
	Node* p=*head_ref;
	if(p==NULL){
		cout<<"doubly linked list is empty"<<endl;
	}
	else if(p->next==NULL){
		//means if there is only one node
		cout<<"Only one node is present, so reverse will be node itself"<<endl;
		
	}
	else{
		Node* temp=NULL;
		
		while(p!=NULL){
			temp=p->prev;
			p->prev=p->next;
			p->next=temp;
			p=p->prev;
		}
		
		*head_ref=temp->prev;
	}
	
}
//to print the doubly linked list
int print(Node* n){
	while(n!=NULL){
		cout<<n->data<<" ";
		n=n->next;
}
}
int main(){
	Node* head=NULL;
	push(&head,7);
	push(&head,6);
    push(&head,5);
	push(&head,4);
	push(&head,3);
	push(&head,2);
	push(&head,1);	
	cout<<"The Doubly linked list is : ";
	print(head); 
	cout<<endl;
	reverse(&head);
	cout<<"The reverse will be : ";
	print(head);
}
