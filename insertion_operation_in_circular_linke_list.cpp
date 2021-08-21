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

//to add nodes at last
int end(Node** head_ref,int value){
	Node* newnode=new Node();
	newnode->data=value;

	//if linked list is null,newnode is only node
	if(*head_ref==NULL){
		newnode->next=newnode;//so link it with itself to make circular linked list
		*head_ref=newnode;//and make it head
	
	}
	//if it is not null
	else{
		Node* last=*head_ref;//make a new ptr 
		while(last->next!=*head_ref){
		last=last->next; //and traverse it to last node i.e. to node after which 
		//loop starts again
	} 
	
		newnode->next=last->next;//now newnode points to first node of loop
		last->next=newnode;//and making next of last to newnode as it has been added to last
		last=newnode;//updating last
	}
}
//to insert node after the given index in the circular linked list
int insertafter(Node** head_ref,int value,int index){
	Node* newnode=new Node();
	newnode->data=value;
	Node* p=*head_ref;
	for(int i=0;i<index;i++){
		p=p->next;
	}
	//now p ptr is at given index
	newnode->next=p->next;
	p->next=newnode;
	
}
//to insert node before the given index in the circular linked list
int insertbefore(Node** head_ref,int value,int index){
	Node* newnode=new Node();
	newnode->data=value;
	Node* p=*head_ref;
	for(int i=0;i<index-1;i++){
		p=p->next;
	}
	//now p ptr is at node previous of given index
	newnode->next=p->next;
	p->next=newnode;
	
}

//to print the circular linked list
int print(Node* n){
	Node* temp=n;
	do{
		cout<<temp->data<<" ";
		temp=temp->next;
	}while(temp!=n);
	
}
int main(){
	Node* head=NULL;
	end(&head,7);
	end(&head,8);
    end(&head,9);
	push(&head,6);
	push(&head,5);
	push(&head,4);
	push(&head,3);
	push(&head,2);
	push(&head,1);
    insertafter(&head,20,3);
   insertafter(&head,89,10);
    insertbefore(&head,70,3);
    insertafter(&head,90,3);
	cout<<"the circular linked list is : ";
	print(head);
	cout<<endl;
}
