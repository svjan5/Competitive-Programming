#include <cstdio>
#include <algorithm>
using namespace std;

struct node {
	int value;
	node* next;
	node(int a,node* b){
		value = a;
		next = b;
	}
};

void insertFront(node **head, int n){
	node *temp = new node(n,NULL);
	if(*head == NULL){
		*head = temp;
		temp->next = *head;
		return;
	}
	node *p = *head;
	temp->next = p->next;
	p->next = temp;
	*head = temp;
}

void insertBack(node **head,int n){
	node *temp = new node(n,NULL);
	if(*head == NULL){
		*head = temp;
		temp->next = *head;
		return;
	}
	node *first = *head;
	node *last = *head;
	while(last->next != first) last = last->next;
	last->next = temp;
	temp->next = first;
}

void displayList(node *head){
	if(head == NULL) return;
	node *p = head;
	do{
		printf("%d ",p->value);
		p = p->next;
	} while(p != head);
	printf("\n");
}

node* getMiddleElement(node *head){
	node *slow,*fast;
	slow = head;
	fast = head->next;
	while(slow != fast){
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;

}

int main(){
	node *head = NULL;
	insertBack(&head,5);insertBack(&head,50);insertBack(&head,500);insertBack(&head,5000);insertBack(&head,6 000);
	displayList(head);
	node *mid = getMiddleElement(head);
	printf("%d\n", mid->value);
}