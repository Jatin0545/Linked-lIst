#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
	};
//to add nodes at front of circular linked list	
int push(Node** head_ref,int value){
	Node* newnode=new Node();
	newnode->data=value;
	newnode->next=*head_ref;
	Node* last=*head_ref;
	
	if(*head_ref==NULL){
		newnode->next=newnode;//if linked list is empty,the link the node with itself
	}
	else{
		//otherwise,make a ptr which points to last node i.e. to node after which 
		//loop starts again
		do{
			last=last->next;
		}while(last->next!=*head_ref);
		//and point it to the newnode
		last->next=newnode;
	
	}
	//make the new node as head 
	*head_ref=newnode;
}	
//to print the circular linked list
int print(Node* n){
	Node* temp=n;
	do{
		cout<<temp->data<<" ";
		temp=temp->next;
	}while(temp!=n);
}
//to exchange the first and last node in linked list using swap method
int exchange(Node* head_ref){
	Node* p=head_ref;
	while(p->next!=head_ref){
		p=p->next;
	}
   
    int a=head_ref->data;
    head_ref->data=p->data;
    p->data=a;

   
   
}
int main(){
	Node* head=NULL;

	push(&head,6);
	push(&head,5);
	push(&head,4);
	push(&head,3);
	push(&head,2);
	push(&head,1);


	cout<<"the circular linked list is : ";
	print(head);
	cout<<endl;	
	cout<<"updated circular linked list : ";
	exchange(head);
	print(head);
}
