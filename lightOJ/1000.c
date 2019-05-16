/*
 * 1000 - Greetings from LightOJ
*/

#include <stdio.h>
 
int main(void) {
	int i;
	int T, a, b;
	scanf("%d", &T);
	for (int i =1; i<= T; i++) {
		scanf("%d %d", &a, &b);
		printf("Case %d: %d\n", i, a + b);
	}
	return 0;
}
