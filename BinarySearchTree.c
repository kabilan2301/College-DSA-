#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *lc, *rc;
};

struct node *root, *p, *cr, *n, *temp, *min, *max;
/*
lc	=>	left child
rc	=>	right child
p 	=>	parent node
cr	=>	current root
n	=>	new node
temp => temperory node
min	=>	to store minimum value
max =>	to store maximum value
item => assigns the given value in the input as node's data
*/
int item;
void insert(){
	n=(struct node*) malloc(sizeof(struct node));
	printf("\nEnter Data: ");
	scanf("%d",&item);
	n->data=item;
	n->lc=n->rc=NULL;
	p=root;
	if(root==NULL){
		root=n;
		return;
	}
	else{
		cr=root;
		while(cr!=NULL){
			p=cr;
			if(n->data < cr->data){
				cr=cr->lc;
			}
			else{
				cr=cr->rc;
			}
		}
		if(n->data < p->data){
			p->lc=n;
		}
		else{
			p->rc=n;
		}
	}
}


void inorder(struct node *temp){
	if(temp!=NULL){
		inorder(temp->lc);
		printf("\t%d\t",temp->data);
		inorder(temp->rc);
	}
}

void preOrder(struct node *temp){
	if(temp!=NULL){
		printf("\t%d\t",temp->data);
		preOrder(temp->lc);
		preOrder(temp->rc);
	}
}

void postOrder(struct node *temp){
	if(temp!=NULL){
		postOrder(temp->lc);
		postOrder(temp->rc);
		printf("\t%d\t",temp->data);
	}
}

int mini(struct node *root){
	p=root;
	if(root==NULL){
		printf("Tree is Empty");
	}
	else{
		while(p!=NULL){
			min=p;
			p=p->lc;
		}
	}
	return min->data;
}
int maxi(struct node *root){
	p=root;
	if(root==NULL){
		printf("Tree is Empty");
	}
	else{
		while(p!=NULL){
			max=p;
			p=p->rc;
		}
	}
	return max->data;
}

struct node *deletion(struct node *root, int val){
	if(root==NULL){
		printf("Tree is Empty");
		return NULL;
	}
	// To Delete Root Node
	if(root->data < val){
		root->rc=deletion(root->rc,val);
	}
	else if(root->data > val){
		root->lc=deletion(root->lc,val);
	}
	else{
		// Leaf 
		if(root->lc==NULL && root->rc==NULL){
			free(root);
			return NULL;
		}
		// Node with RC
		else if (root->lc==NULL){
			temp=root->rc;
			free(root);
			return temp;
		}
		// Node with LC
		else if(root->rc==NULL){
			temp=root->lc;
			free(root);
			return temp;
		}
		// Node with both LC & RC
		else{
			int rightMin=mini(root->rc);
			root->data=rightMin;
			root->rc=deletion(root->rc,rightMin);
		}
	}
	return root;
}

void main(){
	int choice,val,min,max;
	printf(" 1.Insert\n 2.InOrder Traversal\n 3.PreOrder Traversal\n 4.PostOrder Traversal\n 5.Find Minimum\n 6.Find Maximum\n 7.Delete\n 8.Exit\n");
	do{
		printf("\nEnter the Choice: ");
		scanf("%d",&choice);
		switch(choice){
			case 1: insert(); break;
			case 2: inorder(root); break;
			case 3: preOrder(root); break;
			case 4: postOrder(root); break;
			case 5:{
				min=mini(root);
				printf("Minimum value in the Tree is => %d",min);
				break;
			}
			case 6:{
				max=maxi(root);
				printf("Maximum value in the Tree is => %d",max);
				break;
			}
			case 7:{
				printf("Enter the Node to be Deleted: ");
				scanf("%d",&val);
				deletion(root,val);
				break;
			}
			case 8: printf("EXIT POINT"); break;
			default: printf("\nEnter a valid Choice"); break;
		}
	}while(choice!=8);
}


/*
void deleteLeaf(){
	int key;
	if(root==NULL){
		printf("Tree is Empty");
	}
	else{
		printf("Enter the data of a node to be Deleted: ");
		scanf("%d",&key);
		cr=root;
		while(cr->lc!=NULL || cr->rc!=NULL){
			p=cr;
			if(key <= cr->data){
				cr=cr->lc;
			}
			else{
				cr=cr->rc;
			}
		}
		if(cr==p->lc){
			p->lc=NULL;
		}
		else{
			p->rc=NULL;
		}
		free(cr);
	}
}


*/
