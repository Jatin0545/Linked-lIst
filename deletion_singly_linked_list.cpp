#include<iostream>
using namespace std;

class Node{
	public:
	int data;
	Node* next;
};
//to add node at front
int push(Node** head_ref,int value){
	Node* newnode=new Node();//allocating space for new node
	newnode->data=value;
	newnode->next=*head_ref;//the newnode will be at front ,so next of newnode
	//will point at head of previous list,if it is not NULL
	*head_ref=newnode;//making newnode as head
}
//to delete the front node i.e head node
int deleteAtFirst(Node** head_ref){
	Node* p=*head_ref;
	*head_ref=p->next;
	delete p;
}
//deleting a node at given index in singly linked list
int deleteAtGivenIndex(Node* head_ref,int index){
	Node* p=head_ref;
	Node* q=head_ref;
	for(int i=0;i<index;i++){
	   	q=q->next;
	}
    //now q points at node to be deleted
    //if p->next is not equal to q,
    if(p->next!=q){
    	//then move p one step further until,p->next is not equal to q
    	//as we need pointer pointing at node previous of node to be deleted.
    	do{
    		p=p->next;
		}while(p->next!=q);
		
	}
	p->next=q->next;//updating links
	
	delete q;//deallocating space
   
    
}
//deleting last node in singly linked list
int deleteAtLast(Node* head_ref){
	Node* p=head_ref;
	while(p->next->next!=NULL){
		p=p->next;
	}
    //now p is at second last node
    Node* q=p->next;//q points at last node
    //updating links below
	p->next=NULL;

	delete q;//deallocating memory
}
//to print linked list
int print(Node* n){
	while(n!=NULL){
		cout<<n->data<<" ";
		n=n->next;
	}
	cout<<endl;
}
int main(){
	Node* head=NULL;
	push(&head,6);
    push(&head,5);
	push(&head,4);
	push(&head,3);
	push(&head,2);
	push(&head,1);	
	cout<<"The singly linked list is : ";
	print(head); 
	deleteAtFirst(&head);
	cout<<"The singly linked list after deletion of head node is : ";
	print(head);
	deleteAtLast(head);
	cout<<"The singly linked list after deleting last node is : ";
	print(head);
	deleteAtGivenIndex(head,2);
	cout<<"The Doubly linked list after deleting node at given index is : ";
	print(head);
}
