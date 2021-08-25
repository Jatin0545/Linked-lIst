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
//deletion of node at the front i.e head node
int deleteAtFront(Node** head_ref){
	Node* p=*head_ref;

	*head_ref=p->next;
	
	delete p;
}
//deleting node at given index in doubly linked list
int deleteAtGivenIndex(Node* head_ref,int index){
	
    Node* p=head_ref;
   	for(int i=0;i<index;i++){
	    	p=p->next;
	}
     	//now p points at node to be deleted
        //updating links below
    p->prev->next=p->next;
	
    if(p->next!=NULL){
	   	p->next->prev=p->prev;
	}
 
    
    delete p;//de-allocating memory
	}

 
//deleting last node in doubly linked list
int deleteAtLast(Node* head_ref){
	Node* p=head_ref;
	while(p->next!=NULL){
		p=p->next;
	}
   //now p is at last node
   
	p->prev->next=NULL;
	delete p;//deallocating memory
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
	push(&head,6);
    push(&head,5);
	push(&head,4);
	push(&head,3);
	push(&head,2);
	push(&head,1);	
	cout<<"The Doubly linked list is : ";
	print(head); 
	cout<<endl;
	deleteAtFront(&head);
	cout<<"The Doubly linked list after deleting first node is : ";
	print(head);
	cout<<endl;
	deleteAtLast(head);
	cout<<"The Doubly linked list after deleting last node is : ";
	print(head);
	cout<<endl;
	deleteAtGivenIndex(head,2);
	cout<<"The Doubly linked list after deleting node at given index is : ";
	print(head);
	cout<<endl;
}
