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
//to remove duplicates from a doubly linked list
int remove(Node* head_ref){
	Node* p=head_ref;
	while(p!=NULL){
		Node* q=p->next;
		while(q!=NULL){
			if(q->data==p->data){
				//below if else condition is to check if last node data matches with p
				if(q->next!=NULL){
					Node* q1=q;
			    	q=q->next;
			     	q1->prev->next=q1->next;
			    	q1->next->prev=q1->prev;
		    		delete q1;
				}
				else{
					q->prev->next=NULL;
					delete q;
					break;
				}
			
			}
			else{
				q=q->next;
			}
		}
		p=p->next;
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
	push(&head,4);
	push(&head,12);
	push(&head,8);
    push(&head,4);
	push(&head,12);
	push(&head,12);		
	push(&head,10);	
	push(&head,8);	
	push(&head,4);
	push(&head,8);
	push(&head,6);
    push(&head,4);
	push(&head,4);
	push(&head,4);
	push(&head,4);	
	cout<<"The Doubly linked list is : ";
	print(head); 
	cout<<endl;
	remove(head);
	cout<<"after deletion of duplicate nodes,linked list is : ";
	
	print(head);
	
   
}
