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
	Node* newnode=new Node();//allocating memory for new node
	newnode->data=value;//giving new node the value
	
	//if linked list is null
	if(*head_ref==NULL){
		newnode->next=newnode;//next of new node will point to itself
		newnode->prev=newnode;//prev of new node will also point to itself
		*head_ref=newnode;//making the new node as head
		
	}
	//otherwise,
	else{
	    Node* last=(*head_ref)->prev;
	    newnode->next=*head_ref;
	    newnode->prev=last;
	    
	    last->next=newnode;
	    *head_ref=newnode;
		
	
	}
}
//to add node at end in circular doubly linked list
int end(Node** head_ref,int value){
	Node* newnode=new Node();
	newnode->data=value;
	
	if(*head_ref==NULL){
		newnode->next=newnode;
		newnode->prev=newnode;
		*head_ref=newnode;
	}
	else{
		Node* last=*head_ref;
		while(last->next!=*head_ref){
			last=last->next;
		}
		//if there are more than one node, this last pointer points to last node,
		//means next of this node points to head_ref of linked list
	    //otherwise last is pointing to that one node only
		
		//updating bonds,below
		last->next->prev=newnode;
		newnode->next=last->next;
		last->next=newnode;
		newnode->prev=last;
		
	}
}
//to insert node after a given index
int insertAfter(Node** head_ref,int value,int index){
	Node* newnode=new Node();
	newnode->data=value;
	Node* p=*head_ref;
	for(int i=0;i<index;i++){
		p=p->next;
	}
	//now p points at given index
	//updating bonds,below
	p->next->prev=newnode;
	newnode->next=p->next;
	p->next=newnode;
	newnode->prev=p;
}
//to print the circular doubly linked list
int print(Node* n){
    Node* temp=n;
  	do{
		cout<<temp->data<<" ";
		temp=temp->next;
	}while(temp!=n);
	
	cout<<endl;
}


int main(){
	Node* head=NULL;
	push(&head,10);
	end(&head,6);
    end(&head,5);
	end(&head,4);
	end(&head,3);
	end(&head,2);
	end(&head,1);
    insertAfter(&head,7,7);
    push(&head,100);
	cout<<"Circular Doubly linked list is :";
	print(head);


}
