#include<stdio.h>
#include<stdlib.h>

struct Node{
   int data;
   struct Node *right, *left;
};

typedef struct Node* NODE;
NODE head = NULL;
void insertBST(int value){

     if(head == NULL){
        NODE newNode = (NODE) malloc(sizeof(struct Node));
	newNode->data = value;
	newNode->right = NULL;
	newNode->left = NULL;
	head = newNode;
	return;
     }
     NODE temp = head, parent=NULL;
     while(temp != NULL){
        if(temp->data >= value){
	   parent = temp;
	   temp = temp->left;
	}else{
	   parent = temp;
	   temp = temp->right;
	}
     }
     
        NODE newNode = (NODE) malloc(sizeof(struct Node));
	newNode->data = value;
	newNode->right = NULL;
	newNode->left = NULL;
       if(parent->data >= value){
         parent->left = newNode;
       }else{
         parent->right = newNode;
       }

}

void inorder(NODE temp){
   if(temp == NULL) return;
   inorder(temp->left);
   printf("%d\t",temp->data);
   inorder(temp->right);
}
void printnode(){

    if(head == NULL){
       printf("List is empty");
       return ;
    }
    NODE temp = head;
    inorder(temp);
}

int main(){
    int a,n,i;
    printf("Enter size : ");
    scanf("%d",&n);
    for(i = 0 ;i < n ; i++){
       scanf("%d",&a);
       insertBST(a);
    }
    printnode();
    return 0;
}
