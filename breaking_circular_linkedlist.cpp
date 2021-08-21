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

//to break the circular linked list into two
int breaking(Node* head_ref){
	int count=0;
	Node* temp=head_ref;
	do{
		count++;
		temp=temp->next;
		
	}while(temp!=head_ref);
	cout<<"the size of circular linked list is : ";
	cout<<count<<endl;
	
	//to chack if the size of circular linked list is even or odd
	if(count%2==0){
		cout<<"the size is even,so it will be splitted into halves"<<endl;
		Node* p=head_ref;
	
		Node* list1=NULL; // a null linked list is made where first half is stored
		for(int i=0;i<count/2;i++){
			end(&list1,p->data);
			p=p->next;
		}
		
		cout<<"the first half is : "<<endl;
		print(list1);
		cout<<endl;
		
		Node* list2=NULL;// a null linked list is made where second half is stored
		for(int i=0;i<count/2;i++){
			end(&list2,p->data);
			p=p->next;
		}
		cout<<"the second half is : "<<endl;
		print(list2);
		cout<<endl;
	}
	else{
		cout<<"the size is odd,so first list will have one extra node"<<endl;
		Node* p=head_ref;
		Node* list1=NULL;// a null linked list is made where first half is stored
		for(int i=0;i<count/2+1;i++){
			end(&list1,p->data);
			p=p->next;
		}
		cout<<"the first half is : "<<endl;
		print(list1);
		cout<<endl;
	
	
		Node* list2=NULL;// a null linked list is made where second half is stored
		for(int i=0;i<count/2;i++){
			end(&list2,p->data);
			p=p->next;
		}
		cout<<"the second half is : "<<endl;
		print(list2);
		cout<<endl;
	
		
	}
}

int main(){
	Node* head=NULL;
	end(&head,34);
	end(&head,10);
    end(&head,9);
	push(&head,6);
	push(&head,5);
	push(&head,4);
	push(&head,3);
	push(&head,2);
	push(&head,1);


	cout<<"the circular linked list is : ";
	print(head);
	cout<<endl;
	breaking(head);
}
