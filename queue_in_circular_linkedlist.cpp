#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
	};

//to add nodes at last
int enQueue(Node** head_ref,int value){
	Node* newnode=new Node();
	newnode->data=value;

	//if linked list is null,newnode is only node
	if(*head_ref==NULL){
		newnode->next=newnode;//so link it with itself to make circular linked list
		*head_ref=newnode;//and make it head
	
	}
	//if it is not null
	else{
		Node* rear=*head_ref;//make a new ptr 
		while(rear->next!=*head_ref){
		rear=rear->next; //and traverse it to last node i.e. to node after which 
		//loop starts again
	} 
	
		newnode->next=rear->next;//now newnode points to first node of loop
		rear->next=newnode;//and making next of last to newnode as it has been added to last
		rear=newnode;//updating last
	}
}

//to print the circular linked list
int print(Node* n){
	Node* temp=n;
	do{
		cout<<temp->data<<" ";
		temp=temp->next;
	}while(temp!=n);
}
//to delete the last node
int deQueue(Node** head_ref){
	Node* first=*head_ref;
	Node* rear=first->next;
	while(rear->next!=*head_ref){
			rear=rear->next;
	}
	//now last is at last node of circular list
	*head_ref=first->next;//making next of first node as head
    rear->next=first->next;//updating link
	delete first;//de-allocating the space
}
int main(){
	Node* head=NULL;
	enQueue(&head,9);
	enQueue(&head,18);
    enQueue(&head,24);
    
	cout<<"the circular linked list is : ";
	print(head);
	cout<<endl;
    deQueue(&head);
    deQueue(&head);
    enQueue(&head,90);
    enQueue(&head,34);
    
    cout<<"circular list after updation : ";
	print(head);
	cout<<endl;
}
