#include <cstdio>
using namespace std;

/************LINKED LIST IMPLEMENTATION***********
-Pointer to pointers will be used if we want to make change to pointer

*/


struct node {
	int value;
	node* next;
};

void printAll(node *head){
	node *p = head;
	while(p!=NULL){
		printf("%d ",p->value);
		p = p->next;
	}
	printf("\n");
}

void insert(node **head,int n){
	node *temp,*p;
	temp = new node();
	temp->value = n;
	temp->next = NULL;

	if(*head == NULL)			/*When linked list is initially empty*/
		*head = temp;
	else{
		p = *head;
		while(p->next!=NULL)
			p = p->next;
		p->next = temp;
	}
	printAll(*head);
}

/*Two pointers will be used for deleting an node*/

void deleteNode(node **head,int n){
	node *prev,*p;
	p = *head;prev = NULL;

	while(p!=NULL){
		if(p->value == n){
			if(prev == NULL)		/*First node to be deleted*/
				*head = p->next;
			else
				prev->next = p->next;

			delete p;			/*Free the memory*/
			printf("Successfully deleted\n");
			printAll(*head);
			return;
		}
		prev = p;
		p = p->next;
	}
	printf("Not found\n");
	printAll(*head);
}

void search(node *head,int n){
	node *p=head;
	while(p!=NULL){
		if(p->value == n){
			printf("Yes node is presen\n");
			return;
		}
		p = p->next;
	}
	printf("No node is not present\n");
}

int main(){
	int ch,n;
	bool Exit=false;
	node *head;
	while(!Exit){
		printf("************************Menu**************************\n");
		printf("1.Insert\n");
		printf("2.Delete\n");
		printf("3.Search\n");
		printf("4.Print\n");
		printf("5.Exit\n");;
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("Insert Value: ");scanf("%d",&n);
				insert(&head,n);
				break;
			case 2:
				printf("Delete Value: ");scanf("%d",&n);
				deleteNode(&head,n);
				break;
			case 3:
				printf("Search Value: ");scanf("%d",&n);
				search(head,n);
				break;
			case 4:
				printAll(head);
				break;
			case 5:
				Exit = true;
		}

	}
}