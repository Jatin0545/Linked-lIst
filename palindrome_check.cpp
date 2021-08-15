#include<iostream>
using namespace std;

class Node{
	public:
	char data;
	Node* next;
};
//program to add node at front in linked list
char push(Node** head_ref,char value){
	Node* p=new Node();
	p->data=value;
	p->next=*head_ref;
    //making the new node head of linked list
	*head_ref=p;
	
}
//to print the linked list
char printList(Node* n){
	
	while(n!=NULL){
		cout<<n->data<<" ";
		n=n->next;
	}
}
//to check whether data linked of linked list is palindrome or not
bool chkPalindrome(Node* head_ref){
	Node* temp=head_ref;
	Node* p=head_ref;
	int count=0;
	Node* first=new Node();
	while(temp!=NULL){
		temp=temp->next;
		count++;
	}
	cout<<"the size of list is : "<<count<<endl;
	
	//getting reverse of linked list head_ref into a new linked list "first" 
	while(p!=NULL){
		push(&first,p->data);
	//	cout<<p->data<<endl;
		p=p->next;
	
	}
	cout<<"the new linked list is : ";
	printList(first);
	cout<<endl;

	while(first!=NULL && head_ref!=NULL){
		if(first->data!=head_ref->data){
			return false;
			// here break is used to make program more efficient
			//as soon as data of first and head_ref doesn't match
			//while loop is terminated
			break;  
	
		}	
		first=first->next;
		head_ref=head_ref->next;
	}
	//true is returned only when the entire "while" loop exhausts all the possibilities 
   	return true;
}

int main(){
	Node* head=NULL;
	push(&head,'r');
	push(&head,'a');
    push(&head,'c');
	push(&head,'e');
	push(&head,'c');
	push(&head,'a');
//	push(&head,'r');  
	cout<<"the linked list is : " ;
	printList(head);
	cout<<endl;
	
	if(chkPalindrome(head)){
		cout<<"it is palindrome";
		
	}
	else{
		cout<<"it is not palindrome";
	}

	
}
