#include<iostream>
using namespace std;

class Node{
	public:
	int data;
	Node* next;
	
};

//to add nodes in linked list
int push(Node** head_ref,int value){
	Node* newnode=new Node();
	newnode->data=value;
	newnode->next=*head_ref;
	*head_ref=newnode;
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

//to print the  linked list
int print(Node* n){
	while(n!=NULL){
		cout<<n->data<<" ";
		n=n->next;
	}

}
//to break the linked list
int breaking(Node* head_ref){
	int count=0;
	Node* temp=head_ref; 
	while(temp!=NULL){
		count++;
		temp=temp->next;
	}
	cout<<"the size of linked list is : ";
	cout<<count<<endl;
	
	//to check if size is even or odd
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
		while(p!=NULL){
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
		while(p!=NULL){
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
//	push(&head,9);
	push(&head,8);	
	push(&head,7);	
	push(&head,6);
	push(&head,5);
	push(&head,4);
	push(&head,3);
	push(&head,2);
	push(&head,1);
	cout<<"the linked list is : "<<endl;
	print(head);
	cout<<endl;
	breaking(head);
}
