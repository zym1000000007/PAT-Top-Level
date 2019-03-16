#include <stdio.h>
#include <string.h>
#define max 1234567
#define maxx pow(2,31)-1
#include <math.h>
const int zz = pow(2,31)-1;
//const int max=pow(2,21)-1;

int repeat[max];
char str[max],str2[max];

int main(void) {
	int i,j,n,m;
	long long sum,a,b,c;
	char now,last;

	scanf("%s",str);
	n = strlen(str);

	last = 'A';
	m = 0;
	for (i=0; i<n; i++) {
		now = str[i];
		if (now != last) {
			repeat[m] = 1;
			last = now;
			str2[m++] = now;
		} else {
			repeat[m-1]++;
		}
	}
	str2[m] = '\0';
	a = 0;
	b = 0;
	c = 0;
	for (i=0; i<m; i++) {
		if (repeat[i] > 1) {
			a++;
		} else if ((i > 0) && (i < m-1) && (str2[i-1] == str2[i+1])) {
			c++;
		} else {
			b++;
		}
	}
	sum = 1 + m + a*(a+1)/2 + a*b + b*(b-1)/2 + c*(a+b-1) + c*(c-1)/2;
	printf("%lld",sum);
//	printf("%s %d",str2,strlen(str2));

	return 0;
}
