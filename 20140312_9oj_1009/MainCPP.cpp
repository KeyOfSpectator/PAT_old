#include <stdio.h>
#include <string.h>
//using namespace std;

struct Node{
	Node *lchild;
	Node *rchild;
	int data;

}Tree[110];
int loc;

Node *creat(){
	Tree[loc].lchild=Tree[loc].rchild=NULL;
	return &Tree[loc++];
}

Node * insert(Node *root,int data){
	if(root==NULL){
		root=creat();
		root->data=data;
	}else if(root->data>data){
		root->lchild=insert(root->lchild,data);
	}else //if(root->data<data){
		root->rchild = insert(root->rchild,data);
	//}
	return root;
}

char str[26];
int loc_str;
void pro_trave(Node *root){
	str[loc_str++]=root->data+'0';
	if(root->lchild!=NULL)pro_trave(root->lchild);
	if(root->rchild!=NULL)pro_trave(root->rchild);
}

void mid_trave(Node *root){
	
	if(root->lchild!=NULL)mid_trave(root->lchild);
	str[loc_str++]=root->data+'0';
	if(root->rchild!=NULL)mid_trave(root->rchild);
}

int main(){
	int n;
	char tmp[12];

	
	while(scanf("%d",&n)!=EOF){
		if(n==0)break;
		loc=0,loc_str=0;
		scanf("%s",tmp);
		Node *root = NULL;
		for(int i=0;tmp[i]!=0;i++){
			root = insert(root,(tmp[i]-'0'));
		}
		pro_trave(root);
		mid_trave(root);
		char str_original[26];
		//char str_mid_original[26];
		strcpy(str_original,str);
		//strcpy(str_mid_original,str_mid);

		str_original[loc_str]=0;//

		
		for(int j=0;j<n;j++){
			scanf("%s",tmp);
			root=NULL;
			for(int k=0;tmp[k]!=0;k++){
				root = insert(root,(tmp[k]-'0'));
			}
			loc_str=0;
			pro_trave(root);
			mid_trave(root);
			str[loc_str]=0;//
			if(strcmp(str,str_original)==0)
			{
				printf("YES\n");
			}else{
				printf("NO\n");
			}
		}
	
	}

	return 0;
}