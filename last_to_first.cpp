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
//to print the linked list
int print(Node* n){
	while(n!=NULL){
		cout<<n->data<<" ";
		n=n->next;
	}
}
//rotating clockwise by one step i.e. moving last element to first
int rotateByOne(Node** head_ref){
	Node* p=*head_ref;
    //bringing p ptr to second last node
	while(p->next->next!=NULL){
		p=p->next;
	}

    //new ptr pointing at last node
	Node* q=p->next;

    p->next=NULL;  // making second last node point to null
    q->next=*head_ref; //making last node -> next point to head
    *head_ref=q;//making last node as head
    
}
int main(){
	Node* head=NULL;
	 
  
	push(&head,5);
	push(&head,4);
	push(&head,3);
	push(&head,2);
	push(&head,1);
	cout<<"the linked list is : "<<endl;
	print(head);
	cout<<endl;
	rotateByOne(&head);
	print(head);	
	
	
}
