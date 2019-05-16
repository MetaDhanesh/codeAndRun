/*
* 1001 - Opposite Task
*/

#include <stdio.h>

int main(void) {
	int i;
	int T, a, b;
	scanf("%d", &T);
	for (int i =1; i<= T; i++) {
		scanf("%d", &a);
		b = a / 2;
		a = a % 2 + a / 2;
		printf("%d %d\n", a, b );
	}
	return 0;
}

