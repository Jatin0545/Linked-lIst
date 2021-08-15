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
    //making the new node head of linked list
	*head_ref=p;
	
}
//to print the linked list
int printList(Node* n){
	
	while(n!=NULL){
		cout<<n->data<<" ";
		n=n->next;
	}
}

//to remove duplicates from linked list
int remove(Node* head_ref){
	Node* p=head_ref;
	//int count=0; // this will tell how far q ptr has moved from p ptr
    int count_2=0;
    //this loop picks every node one by one in linked list
	while(p!=NULL){
		Node* q=p->next;
	    int count=0;
	    //this loop compare the picked node with rest of the nodes
    	while(q!=NULL){
    		if(p->data==q->data){
    		//if the data of p and q are equal but q is far away from p, for ex:-
			//11-->21-->43-->43-->11-->60-->null	
			//here q points to second 11 i.e 11 at index 4,then 
			//we need to get p ptr to its previous node,so we used while loop to do that
			//with increasing count by one everytime q moves to its next
    			if(p->next!=q){
    				//this loop helps p to get to the previous node of q
    				for(int i=0;i<count;i++){
    					p=p->next;
					}
					q=q->next;
    			    delete p->next;//deleting the bond with node to be deleted
    			    p->next=q;//making bond with node which is next of node to be deleted
    			    p=head_ref;// bringing back the p ptr to head
    			  
    			   
    			    for(int j=0;j<count_2;j++){
    			    	p=p->next;
					}
				}
			
				
		    	else{
					q=q->next;
    	    		delete p->next;
    		    	p->next=q;
				}
        	}
		    else{
		    	q=q->next;
		    	count++;
			}
		    
	
	}
	//we are fixing p ptr and comparing every node data with it.
	//once it is done p is shifted one step forward
	p=p->next;
	count_2++;
}


}

int main(){
	Node* head=NULL;
	push(&head,43);
	push(&head,58);
	push(&head,11);	
    push(&head,58);
    push(&head,58);
    push(&head,60);
    push(&head,43);
    push(&head,43);
	push(&head,11);
	push(&head,43);
	push(&head,10);
	push(&head,3);
	push(&head,21);
	push(&head,11);  
	push(&head,11);  
	push(&head,11);
	push(&head,11);
	push(&head,10);  
    push(&head,11);  
	push(&head,4); 
	cout<<"the linked list is : " ;
	printList(head);
	cout<<endl;
	remove(head);
	cout<<"linked list after removal : ";
	printList(head);
}
