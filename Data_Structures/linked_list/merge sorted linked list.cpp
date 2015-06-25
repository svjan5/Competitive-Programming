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

void insertBack(node **head,int n){
	node *temp,*p;
	temp = new node(n,NULL);

	if(*head == NULL)
		*head = temp;
	else{
		p = *head;
		while(p->next!=NULL)
			p = p->next;
		p->next = temp;
	}
}
void printAll(node *head){
	node *p = head;
	while(p!=NULL){
		printf("%d ",p->value);
		p = p->next;
	}
	printf("\n");
}

void mergeSortedList(node **list1,node **list2,node **list3){
	node *p,*q;
	p = *list1; q = *list2;
	while(p!=NULL && q!=NULL){
		if(p->value < q->value){
			insertBack(list3,p->value);
			p = p->next;
		} else{
			insertBack(list3,q->value);
			q = q->next;
		}
	}
	if(p == NULL && q == NULL) return;
	if(p != NULL){
		while(p!=NULL){
			insertBack(list3,p->value);
			p = p->next;
		}
	}
	else if( q != NULL){
		while(q!=NULL){
			insertBack(list3,q->value);
			q = q->next;
		}	
	}
}

int main(){
	node *list1,*list2,*list3;
	list1 = list2 = list3 = NULL;
	insertBack(&list1,1);insertBack(&list1,10);insertBack(&list1,100);insertBack(&list1,1000);
	insertBack(&list2,5);insertBack(&list2,50);insertBack(&list2,500);insertBack(&list2,5000);
	printAll(list1);
	printAll(list2);
	mergeSortedList(&list1,&list2,&list3);
	printAll(list3);

}