#include<bits/stdc++.h>
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
	*head_ref=p;
	
}
// function to combine data of linked list
// for eg.-if linked list is :2-->4-->3-->
//then combining them we get number 243
int data_from_linked_list(Node* n){
	
	int count=0;
	Node* temp=n;
	while(temp!=NULL){
		count++;
		temp=temp->next;
	}
    //count will the size of linked list
	
	int sum=0;
    Node* p=n;
    int y=count-1;
	for(int i=0;i<count;i++){
		sum=pow(10,y)*(p->data)+sum;
		p=p->next;
		y=y-1;
	}
	cout<<"linked list in form of number : "<<sum;
	return sum;
}
// to print the linked list
int printList(Node* n){
	
	while(n!=NULL){
		cout<<n->data<<" ";
		n=n->next;
	}
}
//function to break the sum and make it a linked list
int newNode(Node* n,int value){
	int count=0;
	int a;
	while(value!=0){
		a=value%10;
		
		push(&n,a);
		value=value/10;
		count++;
		
	}
	cout<<"the size of new linked list is : "<<count<<endl;
	cout<<"new linked list is : "<<endl;
	//printing the new linked list formed by calling the function printList()
    printList(n);

}


int main(){
	Node* head=NULL;
	Node* first=NULL;
	Node* second=NULL; 
    int a,b,sum;
	cout<<"first linked list : ";
    push(&head,3);
	push(&head,9);
	push(&head,9);
	printList(head);//this will give linked list,2-->4-->3-->NULL
	cout<<endl;
    a=data_from_linked_list(head);
	
	cout<<endl;
	cout<<"second Linked List : ";
    push(&first,8);
	push(&first,3);
	push(&first,6);	
	printList(first);//this will give linked list,6-->3-->8-->NULL
	cout<<endl;
    b=data_from_linked_list(first);
    cout<<endl;
    sum=a+b;
    cout<<"the total sum is : "<<sum;
    cout<<endl;
    newNode(second,sum);
    
    
}
