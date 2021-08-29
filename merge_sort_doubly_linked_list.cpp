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
//to divide the linked list
int divide(Node* head_ref,Node** head_ref1,Node** head_ref2){
	Node* temp1=head_ref;
	int count=0;
	while(temp1!=NULL){
		temp1=temp1->next;
		count++;
	}
//	cout<<"the size of list is :"<<count<<endl;
	
	if(count%2==0){
		Node* p1=head_ref;
		for(int i=1;i<count/2;i++){
			p1=p1->next;
		}
		*head_ref2=p1->next; //making next of p as head of second list
		p1->next->prev=NULL;
		*head_ref1=head_ref;//making head of first linked list
		p1->next=NULL;
	/*	cout<<"the first linked list is : ";
		print(*head_ref1);
		cout<<"the second linked list is : ";
		print(*head_ref2);*/
	}
	else{
		Node* p1=head_ref;
		for(int i=0;i<count/2;i++){
			p1=p1->next;
		}
		*head_ref2=p1->next; //making next of p as head of second list
		p1->next->prev=NULL;
		*head_ref1=head_ref;//making head of first linked list
		p1->next=NULL;
	/*	cout<<"the first linked list is : ";
		print(*head_ref1);
		cout<<"the second linked list is : ";
		print(*head_ref2);*/
	} 
	
}
//finally merge sort
void MergeSort(Node** head_ref){
	Node* temp=*head_ref;
	Node* first;
	Node* second;
   	if ((temp == NULL) || (temp->next == NULL)) {
		return;
	}
	divide(temp,&first,&second);
	
	MergeSort(&first);
	MergeSort(&second);
	
	*head_ref=merge_list(first,second);
}
int main(){
	Node* head=NULL;
    push(&head, 5);
    push(&head, 20);
    push(&head, 4);
    push(&head, 3);
    push(&head, 30);
    push(&head, 10);
    cout<<"the doubly linked list is : ";
    print(head);
    MergeSort(&head);
    cout<<"the sorted linked list is : ";
    print(head);
    

}
