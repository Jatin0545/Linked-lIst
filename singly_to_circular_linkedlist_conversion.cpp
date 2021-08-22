#include<iostream>
using namespace std;
class Node{
	public:
	int data;
	Node* next;
};
//to add nodes at front in singly linked list
int push(Node** head_ref,int value){
	Node* newnode=new Node();//allocating soace to new node 
	newnode->data=value;
	newnode->next=*head_ref;
	*head_ref=newnode;//to make the new node formed as head
}

//function to convert singly linked list into circular linked list
int circular(Node* head_ref){
	Node* p=head_ref;
	while(p->next!=NULL){
		p=p->next;
	}
    //p is present at last node of singly linked list
	p->next=head_ref;//linking last node with first node
	

}

//to check whether loop is made or not
bool detect(Node* head){
	//here we used the concept of fast and slow pointer
	//initially they both point to head
	Node* fast=head;
	Node* slow=head;
	
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
//to print the singly linked list
int print(Node* n){
	while(n!=NULL){
		cout<<n->data<<" ";
		n=n->next;
	}
}
//to print cicular linked list
int printcircular(Node* n){
	Node* temp=n;
	do{
		cout<<temp->data<<" ";
		temp=temp->next;
	}while(temp!=n);
}
int main(){
	Node* head=NULL;
	push(&head,5);
	push(&head,4);
	push(&head,3);
	push(&head,2);
	push(&head,1);
	cout<<"singly linked list : ";
	print(head);
	cout<<endl;
	cout<<"after making it into cirular,the list is  : ";
	circular(head);
	printcircular(head);
	cout<<endl;
    if(detect(head)){
		cout<<"yes the loop is found"<<endl;
	  
	}
	else{
		cout<<"loop not found";
	}
}
