#include <stdio.h>
#include <stdlib.h>
#include <set>
#include <queue>
#define MAX 1234567
using namespace std;

typedef struct _Node {
	int id,num,group,level;
	set <struct _Node*> fri;
} Node;

int GM[1000],D;

int DFS(Node* node,int group) {
	if (node) {
		node->group = group;
		GM[group]++;
		for (auto it = node->fri.begin(); it != node->fri.end(); it++) {
			if ((*it)->group == -1) {
				DFS(*it,group);
			}
		}
	}
}

int BFS(Node* node) {
	int d=0,fir;
	queue<Node*> q;
	if (node) {
		node->level = -1;
		q.push(node);
		while (q.size()>0) {
			fir = 1;
			for (auto it = q.front()->fri.begin(); it != q.front()->fri.end(); it++) {
				if ((*it)->level == MAX) {
					(*it)->level = q.front()->level+1;
					q.push(*it);
				}
			}
			if (q.front()->level > d) {
				d = q.front()->level;
			}
//			printf("id=%d level=%d\n",q.front()->id,q.front()->level);
			q.pop();
		}
	}
//	system("pause");
	return d;
}

int cmp(const void *a,const void *b) {
	Node **p = (Node**)a;
	Node **q = (Node**)b;
	return (*p)->group - (*q)->group;
}

int main(void) {
	int i,j,n,group,k,x,d,maxd=0,mind = MAX,be,en;

	scanf("%d",&n);
	Node *node[n+1];
	for (i=0; i<=n; i++) {
		node[i] = new Node;
//		node[i] = (Node*)malloc(sizeof(Node));
	}

	for (i=1; i<=n; i++) {
		scanf("%d",&k);
		node[i]->id = i;
		node[i]->group = -1;
		for (j=0; j<k; j++) {
			scanf("%d",&x);
			(node[i]->fri).insert(node[x]);
			(node[x]->fri).insert(node[i]);
		}
		node[i]->num = (node[i]->fri).size();
	}

	group = 0;
	for (i=1; i<=n; i++) {
		if (node[i]->group == -1) {
			DFS(node[i],group);
			group++;
		}
	}
//	for (i=1; i<=n; i++) {
//		printf("id=%d ",node[i]->id);
//		for (auto it = node[i]->fri.begin(); it != node[i]->fri.end(); it++) {
//			printf("%d ",(*it)->id);
//		}
//		printf("\n\n");
//	}
	qsort(&node[1],n,sizeof(node[1]),cmp);

	be = 1;
	for (int i1=0; i1<group; i1++) {
		en = be + GM[i1];
//		printf("be=%d en=%d\n",be,en);
		for (i=be; i<en; i++) {
			for (j=be; j<en; j++) {
				node[j]->level = MAX;
			}
			d = BFS(node[i]);
//			printf("i=%d d=%d\n",i,d);
			if (d > maxd) {
				maxd = d;
			}
//			printf("mind=%d\n",mind);
		}
		be = en;
//		if (mind > maxd) {
//			maxd = mind;
//		}
	}


	printf("%d %d",group,maxd);

	return 0;
}
