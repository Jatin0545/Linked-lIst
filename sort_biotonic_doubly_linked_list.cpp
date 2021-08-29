#include<iostream>
using namespace std;

class Node{
	public:
	int data;
	Node* next;
	Node* prev;
};
//to add node at front
int push(Node** head_ref,int value){
	Node* newnode=new Node();//allocating sapce for new node
	newnode->data=value;//passing the value in newnode
	newnode->prev=NULL;//as it will be the node at front,previous of first node is NULL
	newnode->next=*head_ref;//the newnode will be at front, so next of newnode will
	//point to head of previous list,if list is not null
	if(*head_ref!=NULL){
		(*head_ref)->prev=newnode;
	}
	*head_ref=newnode;//making the new node as head
}
// to add node at end in doubly linked list
void end(Node** head_ref,int value){
	Node* newnode=new Node();
	newnode->data=value;
    Node* last=*head_ref;
    
    newnode->next=NULL;
    if (*head_ref == NULL) 
    { 
        *head_ref = newnode; 
        newnode->prev=NULL;
         return; 
    }
    while (last->next != NULL) {
	
        last = last->next; 
    }
     last->next = newnode; 
     newnode->prev=last;  
}
//to print linked list
int print(Node* n){
	while(n!=NULL){
		cout<<n->data<<" ";
		n=n->next;
	}
	cout<<endl;
}
//to reverse a linked list
int reverse(Node** head_ref){
	Node* p=*head_ref;
	Node* temp=NULL;
	
	while(p!=NULL){
		temp=p->prev;
		p->prev=p->next;
		p->next=temp;
		p=p->prev;
		
	}
	if(temp != NULL )
        *head_ref = temp->prev;
}
//to merge two linked lists(given both list are in increasing order)
Node* merge_list(Node* head_ref,Node* second_ref){
	Node* p2=head_ref;
	Node* q2=second_ref;
	Node* third=NULL;
	//here we are checking,if any of the linked list is null
    
   	//if first linked list is null,then
   	if(p2==NULL){
    	//copy it in third as it is, because it is already in increasing order
    	while(q2!=NULL){
    		end(&third,q2->data);
    		q2=q2->next;
		}
	}
		//otherwise, if second linked list is NULL
	else if(q2==NULL){
		//copy it in third as it is, because it is already in increasing order
		while(p2!=NULL){
			end(&third,p2->data);
			p2=p2->next;
		}
	}
	
	//if both are not NULL
	else{
		//traverse till any of pointer reaches NULL
		while(p2!=NULL && q2!=NULL){
			//if data of p is less than q
	    	if(p2->data < q2->data){
		    	end(&third,p2->data);//put data of p in third
		    	//this is used to load all data of q,if next of pointer
		    	//p points to null
		    	if(p2->next==NULL){
		    		while(q2!=NULL){
		    			end(&third,q2->data);
		    			q2=q2->next;
					}
				    
			}
			    else{
			    	p2=p2->next;
				}
		    
		}
		    //if data of p is not less than q
	    	else{
		    	end(&third,q2->data);
		    	if(q2->next==NULL){
		    		while(p2!=NULL){
		    			end(&third,p2->data);
		    			p2=p2->next;
		    			
					}
		     		
			}
			    else{
			    	q2=q2->next;
				}
		    	
		}
	}
	}
	return(third);
}

int separation(Node* head_ref,Node** head_ref1,Node** head_ref2){
	Node* p=head_ref->next;//initializing p from next of head beacuse
	//it has to be compared with its previous node.
	//traverse till p is not equal to null
	while(p!=NULL){
		
		if(p->data < p->prev->data){
			*head_ref1=head_ref;
			p->prev->next=NULL;//updating bonds
			*head_ref2=p;
			p->prev=NULL;//updating bonds
		/*	cout<<"the first linked list is : ";
	    	print(*head_ref1);
	    	cout<<"the second linked list is : ";
	    	
		    print(*head_ref2);*/
		    reverse(head_ref2);//reversing the second list
		    break; //to save the time,we come out of the loop as soon as if condition
		    //is true,now we dont need to traverse further
		}
		//if p->data < p->prev->data is not true,
		else{
			//we make pointer p move one step further
			p=p->next;
		}
	}
}
//finally  sort
void Sort(Node** head_ref){
	Node* temp=*head_ref;
	Node* first;
	Node* second;
   	if ((temp == NULL) || (temp->next == NULL)) {
		return ;
	}
	separation(temp,&first,&second);

    *head_ref=merge_list(first,second);
	
}

int main(){
	Node* head=NULL;
	push(&head,1);
	push(&head,4);
    push(&head,6);
    push(&head,8);
    push(&head,10);
    push(&head,12);
    push(&head,7);
    push(&head,5);
    push(&head,3);
    push(&head,2);
    cout<<"the doubly linked list is : ";
    print(head);
    Sort(&head);
    cout<<"the sorted linked list is : ";
    print(head);
    

}
