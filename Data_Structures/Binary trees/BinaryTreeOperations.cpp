#include <bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(int i=a;i<b;i++)
#define FOR(i,n) REP(i,0,n)

struct node{
	int value;
	node *left;
	node *right;
};

node* newNode(int n){
	node *temp = new node;
	temp->value = n;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void insert(node **root,int n){
	node *temp = newNode(n);
	if(*root == NULL){				/*Case when tree is completely empty*/
		*root = temp;
		return;
	}
	node *p = *root;
	while(true){
		if(p->value < n){			/*If value of node is larger then current node*/
			if(p->right == NULL) {p->right = temp;return;}
			else p = p->right;
		}
		else{					/*If value of node is smaller then current node*/
			if(p->left == NULL) {p->left = temp;return;}
			else p = p->left;
		}
	}
}

void displayTree(node *root){
	if(root == NULL) return;			/*Inorder traversal of tree*/
	displayTree(root->left);
	printf("%d ",root->value);
	displayTree(root->right);
}

int size(node *root){
	if(root == NULL) return 0;
	return size(root->left)+size(root->right)+1;	/*Recursively find size of right and left subtree*/
}

bool identical(node *root1,node *root2){
	if(root1 == NULL && root2 == NULL) return true;
	if(root1 == NULL || root2 == NULL) return false;
	if(root1->value != root2->value) return false;
	return identical(root1->left,root2->left) & identical(root1->right,root2->right);
}

node* search(node *root,int n){
	if(root == NULL) return NULL;			/*Case when tree is empty*/
	if(root->value == n) return root;		/*Node found*/
	if(root->value < n) return search(root->right,n);/*If node has larger value then search in right subtree*/
	else return search(root->left,n);		/*If node has smaller value then search in left subtree*/
}

node* minNode(node *root){
	if(root == NULL) return NULL;
	while(root->left != NULL)			/*Traverse to leftmost child*/
		root = root->left;
	return root;
}

node* maxNode(node *root){
	if(root == NULL) return NULL;
	while(root->right != NULL)			/*Traverse to rightmost child*/
		root = root->right;
	return root;
}

node *successor(node *root,int n){
	node* temp = search(root,n);

	if(temp == NULL) return NULL;			/*Node doesn't exists*/
	if(temp->right != NULL)				/*When right child is not null*/
		return minNode(temp->right);

	node *succ = NULL;
	while(root != NULL){				/*When right child is null*/
		if(root->value == n) break;
		else if(root->value > n){
			succ = root;
			root = root->left;
		}
		else root = root->right;
	}
	return succ;
}

node *predecessor(node *root,int n){
	node *temp = search(root,n);

	if(temp == NULL) return NULL;			/*Node doesn't exists*/
	if(temp->left != NULL)				/*When left child exists*/
		return maxNode(temp->left);

	node *pred = NULL;
	while(root != NULL){
		if(root->value == n) break;
		else if(root->value < n){
			pred = root;
			root = root->right;
		}
		else root = root->left;
	}
	return pred;
}

void findPreSuc(node* root, node*& pred, node*& succ, int value){
	if (root == NULL)  return ;
	if (root->value == value){
		succ = successor(root,value);
		pred = predecessor(root,value);
		return ;
	}

	if (root->value > value){			/*If value is smaller than root's value, go to left subtree*/
		succ = root ;
		findPreSuc(root->left, pred, succ, value) ;
	}
	else{						/*Go to right subtree*/
		pred = root ;
		findPreSuc(root->right, pred, succ, value) ;
	}
}

int maxDepth(node *root){
	if(root == NULL) return 0;
	int left = maxDepth(root->left);
	int right = maxDepth(root->right);
	return max(left,right)+1;
}

node* deleteNode(node *root,int key){
	if(root == NULL) return NULL;
	else if(root->value < key)				/*If node value is larger search in right tree*/
		root->right = deleteNode(root->right,key);	
	else if(root->value > key)				/*If node value is smaller search in left tree*/
		root->left = deleteNode(root->left,key);
	else{							/*If node is found*/
		if(root->left == NULL){				/*Case when right child is NULL(includes one child+no child case)*/
			node *temp = root->right;		
			delete root;
			return temp;
		}
		else if(root->right == NULL){			/*Case when left child is NULL second possibility of one child case*/
			node *temp = root->left;
			delete root;
			return temp;
		}
		else{						/*If node has both the children*/
			node *succ = minNode(root->right);	/*Knowing that right child is not NULL get successor easily*/
			root->value = succ->value;		/*Replace node by its succ*/
			root->right = deleteNode(root->right,succ->value);/*Delete the successor*/
		}
	}
	return root;

}

bool checkBST(node *root){
	if(root == NULL) return true;
	if((root->left == NULL) && (root->right == NULL)) return true;
	if(root->left == NULL) return (root->value <= root->right->value) && checkBST(root->right);
	if(root->right == NULL) return (root->value >= root->left->value) && checkBST(root->left);
	return (root->value <= root->right->value) && (root->value >= root->left->value) && checkBST(root->right) && checkBST(root->left);
}

node *lca(node *root,node *node1,node *node2){
	if(root == NULL) return NULL;
	if((node1->value > root->value) && (node2->value > root->value))
		return lca(root->right,node1,node2);
	if((node1->value < root->value) && (node2->value < root->value))
		return lca(root->left,node1,node2);
	return root;
}

node *kthSmallest(node *root,int k){
	int sizeLeft = size(root->left);
	if(k == sizeLeft+1)
		return root;
	if(k < sizeLeft+1)
		return kthSmallest(root->left,k);
	else
		return kthSmallest(root->right,k-sizeLeft-1);
}

void rangeDisplay(node *root,int a,int b){
	if(root == NULL) return;
	rangeDisplay(root->left,a,b);
	if(root->value >= a && root->value <=b)	printf("%d ",root->value);
	rangeDisplay(root->right,a,b);
}

void sortedToTree(node **root,int *arr,int beg,int end){
	if(beg > end) return;
	int mid = (beg+end)/2;
	insert(root,arr[mid]);
	sortedToTree(root,arr,beg,mid-1);
	sortedToTree(root,arr,mid+1,end);
}

void transform2GreaterSum(node *root,int *sum){
	if(root == NULL) return;
	transform2GreaterSum(root->right,sum);
	*sum += root->value;
	root->value = *sum - root->value;
	transform2GreaterSum(root->left,sum);
}

void storeInorder(node *root,int *arr, int *index){
	if(root == NULL) return;
	storeInorder(root->left,arr,index);
	arr[*index] = root->value;(*index)++;
	storeInorder(root->right,arr,index);
}

void alterInorder(node *root,int *arr,int *index){
	if(root == NULL) return;
	alterInorder(root->left,arr,index);
	root->value = arr[*index];(*index)++;
	alterInorder(root->right,arr,index);
}

void binaryTreetoBST(node *root){
	int n = size(root);
	int arr[n];int index=0;
	storeInorder(root,arr,&index);
	// FOR(i,n) printf("%d ",arr[i]);
	sort(arr,arr+n);index=0;
	alterInorder(root,arr,&index);
}

void inOrderIterative(node *root){
	stack<node*> st;
	node *curr = root;
	while(true){
		if(curr != NULL){
			st.push(curr);
			curr = curr->left;
		}
		else{
			if(st.empty())
				break;
			else{
				curr = st.top();st.pop();
				printf("%d ",curr->value);
				curr = curr->right;
			}
		}

	}
}

int main(){
	int n;
	node *root = NULL;
	node *root1 = NULL;
	while(scanf("%d",&n)!=EOF){					/*Inserting nodes*/
		insert(&root,n);
		insert(&root1,n);
	}

	displayTree(root);printf("\n");					/*Display*/
	printf("Size of Tree: %d\n",size(root));			/*Size*/
	if(identical(root,root1)) printf("Yes trees are identical \n");	/*Identical*/

	node *temp = search(root,150);					/*Search*/
	if(temp == NULL) printf("Node not found\n");
	else printf("Node found value: %d\n",temp->value);

	temp = minNode(root);						/*Minimum value*/
	printf("Minimum node: %d\n",temp->value);

	temp = successor(root,150);					/*Successor*/
	if(temp == NULL) printf("No Successor\n");
	else printf("Successor: %d\n",temp->value);

	temp = predecessor(root,50);					/*predecessor*/
	if(temp == NULL) printf("No predecessor\n");
	else printf("predecessor: %d\n",temp->value);

	node *succ,*pred;						/*Predecessor and successor for any value*/
	findPreSuc(root,pred,succ,50);
	printf("Successor : %d & Predecessor: %d \n",succ->value,pred->value );

	printf("maxDepth of tree: %d\n",maxDepth(root));		/*Maximum depth*/

	root = deleteNode(root,175);					/*Delete node*/
	printf("Node %d deleted\n",175);
	displayTree(root);printf("\n");
	insert(&root,175);

	node *root2	   = newNode(4);				/*Check if tree is BST or not*/
	root2->left        = newNode(2);
	root2->right       = newNode(5);
	root2->left->left  = newNode(1);
	root2->left->right = newNode(3);
	if(checkBST(root2)) printf("Yes its a BST\n");
	else printf("No its not a BST\n");

	node *node1 = search(root,75);					/*Lowest common ancestor*/
	node *node2 = search(root,175);
	temp = lca(root,node1,node2);
	printf("Lowest common ancestor of %d & %d :%d\n",node1->value,node2->value,temp->value);

	temp = kthSmallest(root,3);					/*Kth smallest element in BST*/
	printf("%drd smallest=> %d\n",3,temp->value);

	printf("Range Display :");					/*Range display*/
	rangeDisplay(root,100,150);printf("\n");

	printf("Constructing balanced tree from sorted array\n");	/*Constructing binary tree from sorted array*/
	int arr[10];FOR(i,10) arr[i]=i;
	node *newTree = NULL;
	sortedToTree(&newTree,arr,0,9);
	displayTree(newTree);printf("\n");
	printf("Height = %d\n", maxDepth(newTree)-1);

	int sum = 0;							/*Convert to greater sum tree*/
	transform2GreaterSum(root1,&sum);
	printf("Greater sum tree: ");displayTree(root1);printf("\n");

	root1 = newNode(10);						/*Convert Binary Tree to BST*/
	root1->left = newNode(30);
	root1->right = newNode(15);
	root1->left->left = newNode(20);
	root1->right->right = newNode(5);
	binaryTreetoBST(root1);
	displayTree(root1);

	inOrderIterative(root);
}