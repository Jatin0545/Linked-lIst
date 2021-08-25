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
//to reverse a singly linked list
int reverse(Node** head_ref){
	if(*head_ref==NULL){
		cout<<"Singly linked list is empty"<<endl;
	}
	else{
		Node* prev=NULL;
    	Node* p=*head_ref;
    	Node* q;
	
    	while(p!=NULL){
	    	q=p->next;//fixing q , it is  always one step ahead of p
	    	p->next=prev;//reversing the link
	 	    //shifing pointers one step forward,in below steps
	    	prev=p;
	    	p=q;
	
 	}
    	//making last node as head
    	*head_ref=prev;
	}

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
	reverse(&head);
	cout<<"The reverse will be : ";
	print(head);
}
