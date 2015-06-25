#include <cstdio>
#include <algorithm>
using namespace std;

/************LINKED LIST IMPLEMENTATION***********
-Pointer to pointers will be used if we want to make change to pointer
*/

struct node {
	int value;
	node* next;
	node(int a,node* b){
		value = a;
		next = b;
	}
};

node* getNthFromEnd(node *head,int n);
int getMiddleElement(node *head);
node* getNth(node *head,int n);
void printAll(node *head);
void search(node *head,int n);
void reverseList(node **head);
void insertAfter(node **head,int n,int after);
void insertFront(node **head,int n);
void insertBack(node **head,int n);
void deleteNode(node **head,int n);
void deleteCompeleteList(node **head);

void alternateSplit(node *head){
	node *first,*second;
	first = head;
	second = head;
	while(second->next != NULL) 
		second = second->next;
	printf("from second: %d\n", second->value);
	node *p = first;
	node *q = second;
	while(p->next!=second){
		q->next = p->next;
		p->next = p->next->next;
		q->next->next = NULL;
		p = p->next;
		q = q->next;
	}
	p->next = NULL;
	printAll(first);
	printAll(second);
}

void intersectionOfTwoLinkedList(node *head1,node *head2){
	while(head1 != NULL && head2 != NULL){
		if(head1->value == head2->value){
			printf("%d ",head1->value);
			head1 = head1->next;
			head2 = head2->next;
		}
		else if(head1->value < head2->value)
			head1 = head1->next;
		else
			head2 = head2->next;
	}
}

void interchangeFirstAndLast(node **head){
	if(*head==NULL || (*head)->next == NULL) return;
	node *first,*secLast,*last;
	node *p,*prev;
	p = *head;prev = NULL;
	while(p->next != NULL){
		prev = p;
		p = p->next;
	}
	first = *head;
	secLast = prev;
	last = p;
	*head = last;
	secLast->next = first;
	(*head)->next = first->next;
	first->next = NULL;
}


void pairwiseSwap(node *head){
	if(head == NULL || head->next == NULL) return;
	node *prev,*p;
	prev = head;p = head->next;
	while(p!=NULL){
		swap(p->value,prev->value);
		prev = p->next;
		p = (p->next != NULL) ?p->next->next :NULL;
	}
}

void reversePrint(node *head){
	if(head != NULL){
		reversePrint(head->next);
		printf("%d ",head->value);
	}
}

void removeDuplicates(node **head){
	if(*head == NULL) return;
	node *p = *head,*temp;

	while(p->next != NULL){
		if(p->value == p->next->value){
			temp = p->next;
			p->next = p->next->next;
			delete temp;
		}
		else{
			p = p->next;
		}
	}
}

void insertSorted(node **head,int n){
	node *temp = new node(n,NULL);
	
	// if(*head == NULL) *head = temp,return;
	if(*head == NULL || (*head)->value >= n){
		temp->next = *head;
		*head = temp;
		printf("Ho\n");
		return;
	}

	node *p = *head;
	while(p->next!=NULL && p->next->value < n){
		p = p->next;
	}
	temp->next = p->next;
	p->next = temp;
}

bool checkSorted(node *head){
	node *p=head;
	while(p->next != NULL){
		if(p->value > p->next->value)
			return false;
		p = p->next;
	}
	return true;}

bool checkPallindrome(node *head){
	node *slow,*fast;
	fast = slow = head;
	if(head==NULL) return true;	/*Empty list case*/

	node *middleNode;
	node *firstHalf,*secondHalf;
	bool isOdd=false;

	while(fast != NULL){
		if(fast->next == NULL){		/*Case when length of list is odd*/
			isOdd = true;
			// printf("Odd\n");
			middleNode = slow;
			secondHalf = middleNode->next;
			break;
		}
		fast = fast->next->next;
		slow = slow->next;
	}

	if(isOdd == false){			/*Case when length of list is even*/
		// printf("Even\n");
		middleNode = slow;
		secondHalf = middleNode;
	}

	firstHalf = head;
	reverseList(&secondHalf);
	bool ispallin = true;

	node *p,*q;
	p = firstHalf;q = secondHalf;

	while(q != NULL){
		if(p->value != q->value){
			ispallin = false;
			break;
		}
		p = p->next;
		q = q->next;
	}

	reverseList(&secondHalf);
	return ispallin;}

bool detectLoop(node *head){
	node *slow,*fast;
	slow = head;fast = head;
	while(fast != NULL && fast->next != NULL){
		slow = slow->next;
		fast = fast->next->next;
		if(slow == fast)
			return true;
	}
	return false;}

void createLoop(node *head,int n){
	node *last,*p;
	last = head;
	while(last->next!=NULL) last = last->next;
	p = getNth(head,n);
	last->next = p;}

void deleteCompeleteList(node **head){
	node *p,*prev;
	p = *head;
	prev = NULL;
	while(p!=NULL){
		prev = p;
		p = p->next;
		delete prev;
	}
	*head = NULL;}

node* getNthFromEnd(node *head,int n){
	int len=0;
	node *p=head;
	while(p!=NULL) len++,p = p->next;
	return getNth(head,len-n-1);}

int getMiddleElement(node *head){
	node *slow,*fast;
	slow = head;
	fast = head;

	if(head == NULL){
		printf("List is empty\n");
		return -999999;
	}

	while(fast != NULL){
		if(fast->next == NULL )
			return slow->value;
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow->value;}

void reverseList(node **head){
	node *prev,*current,*next;
	prev = NULL;
	current = *head;
	while(current != NULL){
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*head = prev;}

node* getNth(node *head,int n){
	int index=0;
	node *p = head;

	while(p!=NULL){
		if(index == n)
			return p;
		p = p->next;
		index++;
	}
	printf("Node found\n");
	return NULL;}

void printAll(node *head){
	node *p = head;
	while(p!=NULL){
		printf("%d ",p->value);
		p = p->next;
	}
	printf("\n");}

void insertAfter(node **head,int n,int after){
	node *p,*temp;
	temp = new node(n,NULL);

	p = *head;
	while(p!=NULL){
		if(p->value == after){
			temp->next = p->next;
			p->next = temp;
			return;
		}
		p = p->next;
	}
	printf("Element doesn't exist\n");}

void insertFront(node **head,int n){
	node *temp;
	temp = new node(n,NULL);

	if(*head == NULL)
		*head = temp;
	else{
		temp->next = *head;
		*head = temp;
	}}

void insertBack(node **head,int n){
	node *temp,*p;
	temp = new node(n,NULL);

	if(*head == NULL)			/*When linked list is initially empty*/
		*head = temp;
	else{
		p = *head;
		while(p->next!=NULL)
			p = p->next;
		p->next = temp;
	}}

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
			return;
		}
		prev = p;
		p = p->next;
	}
	printf("Not found\n");}

void search(node *head,int n){
	node *p=head;
	while(p!=NULL){
		if(p->value == n){
			printf("Yes node is presen\n");
			return;
		}
		p = p->next;
	}
	printf("No node is not present\n");}

int main(){
	int ch,n;
	bool Exit=false;
	node *head;
	while(!Exit){
		printf("************************Menu**************************\n");
		printf("1.InsertFront\n");
		printf("101.InsertBack\n");
		printf("102.InsertAfter\n");
		printf("103.Insert Sorted\n");
		printf("2.Delete\n");
		printf("201.Delete complete list\n");
		printf("3.Search\n");
		printf("4.Print\n");
		printf("5.GetNth Element\n");
		printf("6.Reverse List\n");
		printf("7.Get Middle element\n");
		printf("8.Get Nth element from end\n");
		printf("9.Create Loop\n");
		printf("10.Detect loop\n");
		printf("11.Check pallindrome\n");
		printf("12.Check Sorted\n");
		printf("13.Remove Duplicates\n");
		printf("14.Recursive reverse print\n");
		printf("15.Pairwise swap\n");
		printf("16.Interchange first and last node\n");
		printf("17.Intersection of two linked list\n");
		printf("18.Alternate split linked list\n");
		printf("99.Exit\n");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("Insert Value: ");scanf("%d",&n);
				insertFront(&head,n);
				printAll(head);
				break;
			case 101:
				printf("Insert Value: ");scanf("%d",&n);
				insertBack(&head,n);
				printAll(head);
				break;
			case 102:
				int after;
				printf("Insert Value: ");scanf("%d",&n);
				printf("Insert After: ");scanf("%d",&after);
				insertAfter(&head,n,after);
				printAll(head);
				break;
			case 103:
				printf("Insert Value: ");scanf("%d",&n);
				insertSorted(&head,n);
				printAll(head);
				break;
			case 2:
				printf("Delete Value: ");scanf("%d",&n);
				deleteNode(&head,n);
				printAll(head);
				break;
			case 201:
				deleteCompeleteList(&head);
				break;
			case 3:
				printf("Search Value: ");scanf("%d",&n);
				search(head,n);
				break;
			case 4:
				printAll(head);
				break;
			case 5:
				printf("Index: ");scanf("%d",&n);
				printf("%d\n",getNth(head,n)->value);
				break;
			case 6:
				reverseList(&head);
				printAll(head);
				break;
			case 7:
				printf("Middle element :%d\n",getMiddleElement(head));
				break;
			case 8:
				printf("Index from end: ");scanf("%d",&n);
				printf("%d\n",getNthFromEnd(head,n)->value);
				break;
			case 9:
				printf("Index to add lopp: ");scanf("%d",&n);
				createLoop(head,n);
				break;
			case 10:
				if(detectLoop(head))
					printf("Loop Exists\n");
				else
					printf("Loop Doesn't exist\n");
				break;
			case 11:
				if(checkPallindrome(head))
					printf("Yes list is pallindrome\n");
				else
					printf("No list is not pallindrome\n");
				printAll(head);
				break;
			case 12:
				if(checkSorted(head))
					printf("List is Sorted\n");
				else
					printf("List is not Sorted\n");
				printAll(head);
				break;
			case 13:
				removeDuplicates(&head);
				printAll(head);
				break;
			case 14:
				reversePrint(head);
				printf("\n");
				break;
			case 15:
				pairwiseSwap(head);
				printAll(head);
				break;
			case 16:
				interchangeFirstAndLast(&head);
				printAll(head);
				break;
			case 17:
				intersectionOfTwoLinkedList(head,head->next->next);printf("\n");
				break;
			case 18:
				alternateSplit(head);
				break;
			case 99:
				Exit = true;
				break;
		}

	}
}