#include <stdio.h>
#include <string.h>

//using namespace std;

struct Node{
	Node *Lchild;
	Node *Rchild;
	char data;


}root;

	char pre_tran[26];
	char mid_tran[26];
	int length;


void build_tree(int mid_l_id,int mid_r_id,Node &root,int pro_l_id,int pro_r_id){
	root.Rchild =root.Lchild = NULL;
	

	for(int i=mid_l_id;i<=mid_r_id;i++){
		if(pre_tran[pro_l_id]==mid_tran[i]){
		
			
			if(i!=mid_l_id){//左子树不空
					
					root.Lchild=new Node;
					
					root.Lchild->data=pre_tran[pro_l_id+1];

					build_tree(mid_l_id,i-1,*root.Lchild,pro_l_id+1,pro_l_id+i-mid_l_id);

			}
			if(i!=mid_r_id){//右子树不空
					
					root.Rchild=new Node;
					
					root.Rchild->data=pre_tran[pro_l_id+i-mid_l_id+1];

					build_tree(i+1,mid_r_id,*root.Rchild,pro_l_id+i-mid_l_id+1,pro_r_id);
			}
		}
	}


	return ;
}

void postOrder(Node root){
	if(root.Lchild!=NULL){
		postOrder(*root.Lchild);
	}
	if(root.Rchild!=NULL)
		postOrder(*root.Rchild);
	printf("%c",root.data);

}

int main(){

	while(scanf("%s",pre_tran)!=EOF){
		scanf("%s",mid_tran);
		length = strlen(mid_tran);
		//Node root;
		root.data = pre_tran[0];
		build_tree(0,length-1,root,0,length-1);
		

		postOrder(root);
		printf("\n");
	
	}
	return 0;
}
