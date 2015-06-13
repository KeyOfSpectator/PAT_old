#include <stdio.h>


struct Node{
	int data;
	Node * Lchild;
	Node * Rchild;

}root;

void compare(Node &root,int data){

	if(data>=root.data){
		if(root.Rchild==NULL){
			Node* new_node = new Node;
			new_node->data=data;
			new_node->Lchild=new_node->Rchild=NULL;
			root.Rchild=new_node;
		}
		else{
		compare(*root.Rchild,data);
		}
	}
	else{
		if(root.Lchild==NULL){
			Node* new_node = new Node;
			new_node->data=data;
			new_node->Lchild=new_node->Rchild=NULL;
			root.Lchild=new_node;
		}
		else{
		compare(*root.Lchild,data);
		}
	
	}
	return;
}

void pro_travel(Node root){
	printf("%d ",root.data);
	if(root.Lchild!=NULL)pro_travel(*root.Lchild);
	if(root.Rchild!=NULL)pro_travel(*root.Rchild);
}

void mid_travel(Node root){

	if(root.Lchild!=NULL)mid_travel(*root.Lchild);
		printf("%d ",root.data);
	if(root.Rchild!=NULL)mid_travel(*root.Rchild);
}

void end_travel(Node root){
	
	if(root.Lchild!=NULL)end_travel(*root.Lchild);
	if(root.Rchild!=NULL)end_travel(*root.Rchild);
	printf("%d ",root.data);
}

int main(){
	int n;
	int data[100];
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++){
			scanf("%d",&data[i]);
		}
		root.data=data[0];
		root.Lchild=root.Rchild=NULL;
		for(int j=1;j<n;j++){
			compare(root,data[j]);
		}

		pro_travel(root);
		printf("\n");
		mid_travel(root);
		printf("\n");
		end_travel(root);
		printf("\n");

	}//end while
	
	return 0;
}