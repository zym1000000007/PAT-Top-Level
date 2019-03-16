#include <stdio.h>
#include <map>
using namespace std;

int main(void) {
	int i,j,n,x,l,left,right,length,max=-1,L,R,ML,MR,p,MP;

	scanf("%d",&n);
	int a[n+1],b[n];
//	set <int> s;
	map <int,int> m;

	for (i=1; i<=n; i++) {
		scanf("%d",&x);
		a[i] = x;
	}
	for (i=0; i<n; i++) {
		scanf("%d",&x);
		b[i] = x;
	}

	left = 0;
	for (i=0; i<n;) {
//		printf("L=%d R=%d %d %d\n",L,R,left,right);
//		for (auto it=m.begin(); it!=m.end(); it++) {
//			printf("%d ",it->first);
//		}
//		printf("\n\n");
		for (j=i; j<n; j++) {
//			printf("j=%d b[j]=%d\n",j,b[j]);
			if (m.find(b[j]) == m.end()) {
				m.insert(make_pair(b[j],j));
			} else {
				L = left;
				R = j-1;
				left = m[b[j]] + 1;

				for (l=L; l<left; l++) {
					m.erase(b[l]);
				}
				right = j + 1;
				m.insert(make_pair(b[j],j));
				i = right;
				break;
			}
		}
		if (j == n) {
			L = left;
			R = n-1;
			right = n;
			length = R-L+1;
			i = n;
//			printf("L=%d R=%d\n",L,R);
//			for (auto it=m.begin(); it!=m.end(); it++) {
//				printf("%d ",it->first);
//			}
//			printf("\n\n");
		}
		length = R-L+1;
		p = 0;
		for (j=L; j<=R; j++) {
			p += a[b[j]];
		}
		if (length > max) {
			max = length;
			ML = L;
			MR = R;
			MP = p;
		} else if ((length == max) && (p > MP)) {
			max = length;
			ML = L;
			MR = R;
			MP = p;
		}
	}
	printf("%d %d %d",MP,ML,MR);

	return 0;
}
