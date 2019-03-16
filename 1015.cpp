#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <vector>
//using namespace std;

int find(char *str,int f,char c) {
	int i;
	for (i=f; i<strlen(str); i++) {
		if (str[i] == c) {
			break;
		}
	}
	if (i == strlen(str)) {
		i = -2;
	}
	return i;
}

int main(void) {
	int i,j,n,site,cnt[26]= {0},now,last,max,len;
	char str[2][1100];
//	vector <int> a[26];

	scanf("%s",str[0]);
	scanf("%s",str[1]);
	n = strlen(str[0]);
//	for (i=0; i<n; i++) {
//		site = str[0][i] - 'a';
//		a[site].push_back(i);
//	}
	max = -1;
	for (i=0; i<n; i++) {
		now = 0;
		last = -1;
		for (j=0; j<26; j++) {
			cnt[j] = 0;
		}
		for (j=i; j<n; j++) {
//			site = str[1][j] - 'a';
//			now = a[site][cnt[site]++];
			now = find(str[0],last+1,str[1][j]);
//			printf("last=%d now=%d\n",last,now);
			if (j == i) {
				last = now;
			} else {
				if (now < last) {
					len = j - i;
//					printf("%s\n",&str[1][j]);
					break;
				} else {
					last = now;
				}
			}
		}
		if (j == n) {
			len = j - i;
		}
//		printf("i=%d j=%d len=%d\n",i,j,len);
		if (len > max) {
			max = len;
		}
	}
	printf("%d",n-max);
//	for (i=0; i<26; i++) {
//		if (a[i].size() > 0) {
//			printf("%c\n",'a'+i);
//			for (j=0; j<a[i].size(); j++) {
//				printf("%d ",a[i][j]);
//			}
//			printf("\n");
//		}
//	}

	return 0;
}
