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
//to insert a new node after a given node using index
int afterInsert(Node* head_ref,int index,int value){
	Node* newnode=new Node();//allocating space for new node
	Node* p=head_ref;
	for(int i=0;i<index;i++){
		p=p->next;
	}
//	cout<<p->data;
	newnode->data=value;//passing value into new node
	//updating links of next and prev,in below statements
	newnode->next=p->next;
	p->next=newnode;
	newnode->prev=p;
	
	if(newnode->next!=NULL){
		newnode->next->prev=newnode;
	}
	

}
//to add a node at the end
int end(Node** head_ref,int value){
	Node* newnode=new Node();//allocating sapce
	Node* p=*head_ref;

	//now p is pointing at last node
	newnode->data=value;
	newnode->next=NULL;

//if list is empty,make the node as head
    if(head_ref==NULL){
    	newnode->prev=NULL;
    	*head_ref=newnode;
	}
	while(p->next!=NULL){
		p=p->next;
	}
	p->next=newnode;
	newnode->prev=p;
	
}
//adding a node before a given node
int addBefore(Node* head_ref,int index,int value){
	Node* newnode=new Node();//allocating new space
	Node* p=head_ref;
	for(int i=0;i<index;i++){
		p=p->next;
	}
	//now p is at node before which a new node is to be inserted
	//updating links below:-
	newnode->data=value;
	newnode->next=p;
	newnode->prev=p->prev;
	p->prev=newnode;
	
	if(newnode->prev!=NULL){
		newnode->prev->next=newnode;
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
	push(&head,1);
    push(&head,2);
	push(&head,3);
	push(&head,4);
	push(&head,5);
	push(&head,6);	
	cout<<"The Doubly linked list is : ";
	print(head); 
	cout<<endl;
	afterInsert(head,2,10);
	afterInsert(head,6,20);
	cout<<"After insertion : ";
	print(head);
	cout<<endl;
	end(&head,67);
	end(&head,98);
	cout<<"after adding nodes at end : ";
	print(head);
	cout<<endl;
	addBefore(head,1,144);
	addBefore(head,7,356);
	cout<<"after adding nodes before : ";
	print(head);
	cout<<endl;
}
