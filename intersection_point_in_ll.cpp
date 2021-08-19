#include<iostream>
using namespace std;
class Node{
	public:
	int data;
	Node* next=NULL;
	int flag;
};

//to print the linked list
int print(Node* n){
	while(n!=NULL){
		cout<<n->data<<" ";
		n=n->next;
	}
}
int intersection(Node* head_ref,Node* head_ref2){
	Node* p=head_ref;
	while(p!=NULL){
		p->flag=1;
		p=p->next;
	}//making all nodes of first linked list visited by making flag=1
	Node* q=head_ref2;
    while(q!=NULL){
    	if(q->flag==1){
    		cout<<"the intersection point is : "<<endl;
    		cout<<q->data;
    		break;//come out of loop if point is found earlier
		}
		
		q=q->next;
	
	}
	
	
}
int main(){
    Node* newNode;
 
    Node* head = new Node();
    head->data = 1;
    Node* second = new Node();
    second->data = 5;
 
    newNode = new Node();
    newNode->data = 10;
    second->next = newNode;
 
    newNode = new Node();
    newNode->data = 23;
    head->next = newNode;
    second->next->next = newNode;
 
    newNode = new Node();
    newNode->data = 17;
    
    second->next->next->next = newNode;
 
    newNode = new Node();
    newNode->data = 30;
    head->next->next = newNode;
 
    head->next->next->next = NULL;
    cout<<"first linked list : "<<endl;
    print(head);
    cout<<endl;
    cout<<"second linked list : "<<endl;
    print(second);
    cout<<endl;
	intersection(head,second);
}
