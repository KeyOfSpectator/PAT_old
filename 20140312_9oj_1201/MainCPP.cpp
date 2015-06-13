#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	Node * Lchild;
	Node * Rchild;

}node[110];
int Node_id ;

Node * compare(Node *root,int data){

	if(root==NULL){
		root = &node[Node_id++];
		root->Lchild=root->Rchild=NULL;
		root->data=data;
	}else if(root->data>data){
		root->Lchild = compare(root->Lchild,data);
	
	}else if(root->data<data){
		root->Rchild = compare(root->Rchild,data);
	}
	return root;

}

void pro_travel(Node* root){
	printf("%d ",root->data);
	if(root->Lchild!=NULL)pro_travel(root->Lchild);
	if(root->Rchild!=NULL)pro_travel(root->Rchild);
}

void mid_travel(Node* root){

	if(root->Lchild!=NULL)mid_travel(root->Lchild);
		printf("%d ",root->data);
	if(root->Rchild!=NULL)mid_travel(root->Rchild);
}

void end_travel(Node* root){
	
	if(root->Lchild!=NULL)end_travel(root->Lchild);
	if(root->Rchild!=NULL)end_travel(root->Rchild);
	printf("%d ",root->data);
}

/*void delete_tree(Node* root){
	if(root->Lchild == NULL&&root->Rchild == NULL)
    {
        free(root);
    }
    else
    {
        if(root->Lchild != NULL)
        {
            delete_tree(root->Lchild);
            root->Lchild = NULL;  //把删除之后的左子树置空
        }
        if(root->Rchild != NULL)
        {
            delete_tree(root->Rchild);
            root->Rchild = NULL; //把删除之后的右子树置空
        }
    }
	return ;
}*/

int main(){
	int n;
	int data;
	Node_id = 0;
	while(scanf("%d",&n)!=EOF){
		//for(int i=0;i<n;i++){
		//	scanf("%d",&data[i]);
		//}
		Node *root=NULL;
		for(int j=0;j<n;j++){
			scanf("%d",&data);
			root  = compare(root,data);
		}

		pro_travel(root);
		printf("\n");
		mid_travel(root);
		printf("\n");
		end_travel(root);
		printf("\n");
		
		//delete_tree(root);
	}//end while
	
	return 0;
}