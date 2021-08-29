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
//to print the doubly linked list
int print(Node* n){
	while(n!=NULL){
		cout<<n->data<<" ";
		n=n->next;
}
    cout<<endl;
}
//to divide the linked list
int divide(Node* head_ref,Node** head_ref1,Node** head_ref2){
	Node* temp1=head_ref;
	int count=0;
	while(temp1!=NULL){
		temp1=temp1->next;
		count++;
	}
//	cout<<"the size of list is :"<<count<<endl;
	
	if(count%2==0){
		Node* p=head_ref;
		for(int i=1;i<count/2;i++){
			p=p->next;
		}
		*head_ref2=p->next;//making next of p as head of second list
		p->next->prev=NULL; 
		*head_ref1=head_ref;//making head of first linked list
		p->next=NULL;
		cout<<"the first linked list is : ";
		print(*head_ref1);
		cout<<"the second linked list is : ";
		print(*head_ref2);
	}
	else{
		Node* p=head_ref;
		for(int i=0;i<count/2;i++){
			p=p->next;
		}
		*head_ref2=p->next; //making next of p as head of second list
		p->next->prev=NULL; //making previous of first node of second list as null
		*head_ref1=head_ref;//making head of first linked list
		p->next=NULL;
		cout<<"the first linked list is : ";
		print(*head_ref1);
		cout<<"the second linked list is : ";
		print(*head_ref2);
	} 
	
}
int main(){
	Node* head=NULL;
	Node* first=NULL;
	Node* second=NULL;
	push(&head,70);
	push(&head,6);
    push(&head,5);
	push(&head,4);
	push(&head,3);
	push(&head,2);
	push(&head,1);	
	cout<<"The Doubly linked list is : ";
	print(head); 
	cout<<endl;
	divide(head,&first,&second);
}
