#include<iostream>
using namespace std;
class Node{
	public:
	int data;
	Node* next=NULL;
};
//to add nodes at front of linked list
int push(Node** head_ref,int value){
	Node* temp=new Node();
	temp->data=value;
	temp->next=*head_ref;
	*head_ref=temp;
}
//to add nodes at last
void end(Node** head_ref,int value){
	Node* temp=new Node();
	Node* last=*head_ref;  
	temp->data=value;
	temp->next=NULL;
	
	//checking if linked list is empty or not
	//if it is empty make the new node formed as head
	if(*head_ref==NULL){
		*head_ref=temp;  //making new node as head
		return;
	}
	//otherwise make a ptr p and traverse it till last node
	
	while(last->next!=NULL){
		last=last->next;
	}
	//after make p ptr point to the new node formed
	//in this way it is added to last of linked list
	last->next=temp;

}

//to print the linked list
int print(Node* n){
	while(n!=NULL){
		cout<<n->data<<" ";
		n=n->next;
	}
}
int separation(Node* head_ref){
	Node* p=head_ref;
	Node* temp=NULL;
	int count=0;
	while(p!=NULL){
		if(p->data%2==0){
			push(&temp,p->data);//means every node with even data will be pushed at front
			count++;
		}
		else{
			end(&temp,p->data);// and every node with odd data will be pushed at end
		}
		p=p->next;
	}
	
	cout<<"the linked list after is : "<<endl;
	print(temp);


		
	
	}
	

int main(){
	Node* head=NULL;
//	push(&head,6);	
	push(&head,7);	
	push(&head,1);	
	push(&head,4);	 
 	push(&head,5); 
	push(&head,10);
	push(&head,12);
	push(&head,8);
	push(&head,15);
	push(&head,17);
	cout<<"the linked list is : "<<endl;
	print(head);
	cout<<endl;
	separation(head);
}
