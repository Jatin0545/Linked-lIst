#include<iostream>
using namespace std;

class Node{
	public:
	int data;
	Node* next;
};
//to add node at front
int push(Node** head_ref,int value){
	Node* newnode=new Node();//allocating space for new node
	newnode->data=value;
	newnode->next=*head_ref;//the newnode will be at front ,so next of newnode
	//will point at head of previous list,if it is not NULL
	*head_ref=newnode;//making newnode as head
}
// to add node at end in singly linked list
int end(Node** head_ref,int value){
	Node* newnode=new Node();
	newnode->data=value;
    if(*head_ref!=NULL){
    	Node* p=*head_ref;
     	while(p->next!=NULL){
	    	p=p->next;
	}
	    //now p points at  last node
    	p->next=newnode;

    	newnode->next=NULL;
	}
	else{
		newnode->next=NULL;
		*head_ref=newnode;
	}
}
//to print linked list
int print(Node* n){
	while(n!=NULL){
		cout<<n->data<<" ";
		n=n->next;
	}
	cout<<endl;
}
//to merge two linked lists(given both list are in increasing order)
int merge_list(Node* head_ref,Node* second_ref){
	Node* p=head_ref;
	Node* q=second_ref;
	Node* third=NULL;
	//here we are checking,if any of the linked list is null
    
   	//if first linked list is null,then
   	if(p==NULL){
    	//copy it in third as it is, because it is already in increasing order
    	while(q!=NULL){
    		end(&third,q->data);
    		q=q->next;
		}
	}
	
		//otherwise, if second linked list is NULL
	else if(q==NULL){
		//copy it in third as it is, because it is already in increasing order
		while(p!=NULL){
			end(&third,p->data);
			p=p->next;
		}
	}

	//if both are not NULL
	else{
		//traverse till any of pointer reaches NULL
		while(p!=NULL && q!=NULL){
			//if data of p is less than q
	    	if(p->data < q->data){
		    	end(&third,p->data);//put data of p in third
		    	//this is used to load all data of q,if next of pointer
		    	//p points to null
		    	if(p->next==NULL){
		    		while(q!=NULL){
		    			end(&third,q->data);
		    			q=q->next;
					}
				    
			}
		    	p=p->next;
		}
		    //if data of p is not less than q
	    	else{
		    	end(&third,q->data);
		    	if(q->next==NULL){
		    		while(p!=NULL){
		    			end(&third,p->data);
		    			p=p->next;
					}
		     		
			}
		    	q=q->next;
		}
	}
	}
    print(third);
}
int main(){
	Node* head=NULL;
	Node* second=NULL;
    push(&head,15);
 //   push(&head,10);
    push(&head,5);
    
    push(&second,20);
    push(&second,3);
    push(&second,2);
    cout<<"the 1st singly linked list is : ";
    print(head);
    cout<<"the 2nd singly linked list is : ";
    print(second);
    cout<<"the sorted linked list is : ";
    merge_list(head,second);
   
}
    


