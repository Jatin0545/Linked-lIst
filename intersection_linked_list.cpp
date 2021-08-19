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

//to give intersection of two linked lists
int intersection(Node* head_ref,Node* head_ref2){
	Node* p=head_ref;// p ptr points to head of first linked list
	Node* q=head_ref2; // q ptr points to head of second linked list
	Node* list=NULL;// new linked list has been made
	
	while(p!=NULL){
		while(q!=NULL){
			if(q->data==p->data){
			   	end(&list,q->data);//this will be adding nodes at end
		    	break; //if data matches,then second loop i.e.while(q!=NULL) directly breaks
		    	//we dont need further more to check ASA data of both linked lists are equal
	    	}
	    	else{
	    		q=q->next; // if data doesn't matches ,then move q to next node
	    		//so that the data of next node can be checked if it is equal
	    		// to data of p or not
		    
            }
		}
	
		p=p->next; //once the whole q is traversed ,p is moved to next node
		q=head_ref2;//bringing back the q ptr to head, so that whole process can be repeated
		
		
	}
	cout<<"the new linked list formed is : ";
	print(list);
	
	
}
int main(){
	Node* head=NULL;
	Node* second=NULL;
	push(&head,6);
	push(&head,4);
	push(&head,3);
	push(&head,2);
	push(&head,1);
	cout<<"first linked list is : "<<endl;
	print(head);
	cout<<endl;
	end(&second,12);	
	push(&second,11);
	push(&second,10);
	push(&second,8);
	push(&second,6);
	push(&second,4);
	push(&second,2);
//	end(&second,1);
    cout<<"second linked list is : "<<endl;
	print(second);	
	cout<<endl;
	intersection(head,second);
}
