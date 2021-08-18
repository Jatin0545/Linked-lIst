#include<iostream>
using namespace std;

class Node{
	public:
	int data;
	Node* next;
};
//function to add nodes at front
int push(Node** head_ref,int value){
	Node* p=new Node();
	p->data=value;
	p->next=*head_ref;
	// making new node head
	*head_ref=p;
	
}
//printing list
int printList(Node* n){
	
	while(n!=NULL){
		cout<<n->data<<" ";
		n=n->next;
	}
}

// function to swap pairs in linked list
int swapPairs(Node* head_ref){
	Node* p=head_ref;
	Node* q=p->next;
	//here in linked list:1-->2-->3-->4-->5-->6-->NULL
	//p points at 1 and q points at 2
	
	//to get the size of linked list
	Node* temp=head_ref;
	int count=0;
	while(temp!=NULL){
		temp=temp->next;
		count++;
	}
	cout<<"the size of linked list is : "<<count<<endl; 
	//now these three lines below changes 1-->2 to 2-->1 i.e swap first two nodes
	p->next=q->next;
	q->next=p;
	head_ref=q;
	//if size is even then use if condition
	//otherwise use else condition
    if(count%2==0){
   		while(p->next!=NULL){
	    	Node* p1=p->next;// we have made a p1 ptr which will be always one step ahead of p
		    q=p1->next;//q will be always one step ahead of p1
		
	     	p1->next=q->next;
	    	p->next=q;
	    	q->next=p1;
		
	    	p=p1;// at last bringing the p ptr to p1 , so that we can complete our using these
		    //pointers only
	
	}
}
	else{
		while(p->next->next!=NULL){
	    	Node* p1=p->next;// we have made a p1 ptr which will be always one step ahead of p
		    q=p1->next;//q will be always one step ahead of p1
		
	     	p1->next=q->next;
	    	p->next=q;
	    	q->next=p1;
		
	    	p=p1;// at last bringing the p ptr to p1 , so that we can complete our using these
		    //pointers only
	}
	
}
    cout<<"the final list is : "<<endl;
	printList(head_ref);

}
int main(){
	Node* head=NULL;
	push(&head,80);
    push(&head,70);
	push(&head,60);
    push(&head,50);
	push(&head,40);
	push(&head,30);
	push(&head,20);
	push(&head,10);
	cout<<"The linked list Formed is :";
	printList(head);
	cout<<endl;
	swapPairs(head);
}
