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
//to print the circular linked list
int print(Node* n){
	Node* temp=n;
	do{
		cout<<temp->data<<" ";
		temp=temp->next;
	}while(temp!=n);
}
//to delete a node
int deletenode(Node** head_ref,int value){
	Node* p=*head_ref;
	///if given value is present at first node
	if(p->data==value){
		Node* last=p->next;
		while(last->next!=*head_ref){
			last=last->next;
		}
		//now last is at last node of circular list
		*head_ref=p->next;//making next of first node as head
		last->next=p->next;//updating link
		delete p;//de-allocating the space
	}
	//and if given value is at node other than 1
	else{
		Node* temp=*head_ref;
     	while(temp->next->data!=value){
        	temp=temp->next;
    }
        // now temp is at node which is previous of node to be deleted
   
        Node* q=temp->next; //now q points to node with given value
    
        temp->next=q->next;//updating link of previous node
        delete q;
   }
	}

   


int main(){
	Node* head=NULL;
	push(&head,6);
	push(&head,5);
	push(&head,4);
	push(&head,3);
	push(&head,2);
	push(&head,1);
	cout<<"the circular linked list is : ";
	print(head);
	cout<<endl;
	deletenode(&head,5);
	cout<<"circular list after deletion : ";
	print(head);
	cout<<endl;
}
