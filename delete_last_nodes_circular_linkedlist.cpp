#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
	};

//to add nodes at last
int end(Node** head_ref,int value){
	Node* newnode=new Node();
	newnode->data=value;

	//if linked list is null,newnode is only node
	if(*head_ref==NULL){
		newnode->next=newnode;//so link it with itself to make circular linked list
		*head_ref=newnode;//and make it head
	
	}
	//if it is not null
	else{
		Node* last=*head_ref;//make a new ptr 
		while(last->next!=*head_ref){
		last=last->next; //and traverse it to last node i.e. to node after which 
		//loop starts again
	} 
	
		newnode->next=last->next;//now newnode points to first node of loop
		last->next=newnode;//and making next of last to newnode as it has been added to last
		last=newnode;//updating last
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

int deletelast(Node* head_ref){
	Node* temp=head_ref;
	while(temp->next->next!=head_ref){
		temp=temp->next;
	}
	Node* q=temp->next;
	temp->next=q->next;
	delete q;
}
int main(){
	Node* head=NULL;
	end(&head,6);
	end(&head,5);
	end(&head,4);
	end(&head,3);
	end(&head,2);
	end(&head,1);

	cout<<"the circular linked list is : ";
	print(head);
	cout<<endl;
	deletelast(head);
	deletelast(head);

	cout<<"circular list after deletion : ";
	print(head);
	cout<<endl;
}
