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
	    Node* last=*head_ref;
	    //again,if list contians more than one node
		if(last->next!=*head_ref){
			
	     	while(last->next!=*head_ref){
		    	last=last->next;
		}
	    //now this last pointer points to last node,means next of this node points to
	    //head_ref of linked list
	    //updating bonds,below
		    newnode->next=last->next;
	        last->next=newnode;
	        newnode->prev=last;
	        *head_ref=newnode;//making the new node as head
		}
		//and otherwise, if list contains one node
		else{
			//updating bonds,below
			newnode->next=last->next;
			last->next=newnode;
			newnode->prev=last->prev;
			last->prev=newnode;
			*head_ref=newnode;//making newnode as head of list
		}
	
	}
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
bool detect(Node* head_ref){

	//here we used the concept of fast and slow pointer
	//initially they both point to head
	Node* fast=head_ref;
	Node* slow=head_ref;
	
	while(fast!=NULL && fast->next!=NULL){
		//slow ptr moves by one step
		slow=slow->next;
		//fast ptr moves by two steps
	    fast=fast->next->next;
	   	if(slow==fast){
	   		return true;
		}
	
    }
    //false is returned only when the entire "while" loop exhausts all the possibilities 
    return false;
    
}

int main(){
	Node* head=NULL;
	push(&head,6);
    push(&head,5);
	push(&head,4);
	push(&head,3);
	push(&head,2);
	push(&head,1);
	cout<<"Circular Doubly linked list is :";
	print(head);
	if(detect(head)){
		cout<<"loop found"<<endl;
	}
	else{
		cout<<"no loop found"<<endl;
	}
	
}
