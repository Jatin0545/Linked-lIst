#include<iostream>
using namespace std;

class Node{
	public:
	int data;
	Node* next;
};
//program to add node at front in linked list
int push(Node** head_ref,int value){
	Node* p=new Node();
	p->data=value;
	p->next=*head_ref;
    //making the new node as head of linked list
	*head_ref=p;
	
}
//to check whether linked list contains loop or not
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
//to count the length of loop
int count(Node* head){
	Node* fast=head;
	Node* slow=head;
	
	do{
		slow=slow->next;
	    fast=fast->next->next;
	}while(fast!=slow);
	
    int count=1;//it is initialised from 1 one beacuse in next step we have
    //made fast ptr to move one step forward
    //------//
    //make fast ptr move one step forward and then iterate till
    //fast ptr is not equal to slow ptr
	fast=fast->next;
	while(fast!=slow){
	    fast=fast->next;
	   	count++;
}
	cout<<"the size of loop is : "<<count;	
	
}
//to print linked list
int printList(Node* n){
	
	while(n!=NULL){
		cout<<n->data<<" ";
		n=n->next;
	}
}

int main(){
	Node* head=NULL;
    push(&head,1);
	push(&head,2);
	push(&head,3);
	push(&head,4);
	push(&head,5);  
	cout<<"the linked list is : " ;
	printList(head);
	head->next->next->next->next->next=head->next; //making of loop
	cout<<endl; 	
	
   
    if(detect(head)){
		cout<<"loop  found"<<endl;
	    count(head);
	}
	else{
		cout<<"loop not found";
	}
}
