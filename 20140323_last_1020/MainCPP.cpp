#include <stdio.h>
#include <queue>
using namespace std;

struct Node{
	Node* lchild;
	Node* rchild;
	int id;
	
}tree[31];
int loc;

Node* create(int x){
		tree[loc].lchild=tree[loc].rchild=NULL;
		tree[loc].id=x;
		return &tree[loc++];

	}


int strP[31];
int strI[31];

queue<Node*> Q;

Node* build(int ps,int pe,int is,int ie){
	int find=0;
	for(int f=is;f<=ie;f++){
		if(strP[pe]==strI[f]){
			find = f;
			break;
		}
	}
	//if(find==0)return NULL;
	Node * rec = create(strP[pe]);
	if(find!=is){
		rec->lchild = build(ps,find-is+ps-1,is,find-1);
	}
	if(find!=ie){
		rec->rchild = build(find-is+ps,pe-1,find+1,ie);
	}

	return rec;

}

void push_queue(Node* root,int n){
		int ans_num = 0;
	while(!Q.empty()){
		printf("%d",Q.front()->id);
	
		ans_num++;
		if(Q.front()->lchild!=NULL)
		Q.push(Q.front()->lchild);
		if(Q.front()->rchild!=NULL)
		Q.push(Q.front()->rchild);

			Q.pop();

		if(ans_num<n)
			printf(" ");
	}
	printf("\n");
}

int main(){
	int n;
	loc=0;

	//freopen( "C:\\Users\\fsc\\Desktop\\input_test.txt","r", stdin );


	while(scanf("%d",&n)!=EOF){
			int tmp;

		for(int p=1;p<=n;p++){
		
			scanf("%d",&tmp);
			strP[p]=tmp;
		}
		for(int pi=1;pi<=n;pi++){
			scanf("%d",&tmp);
			strI[pi]=tmp;
		}
		
		Node * root = build(1,n,1,n);
		
		while(!Q.empty())Q.pop();

		Q.push(root);
		push_queue(root,n);

	
	
	}


	return 0;
}