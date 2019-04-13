/* 
 * Not Accepted -- Working on it
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define SIZE 1000

int count_factors(int n) {
      if (n == 1) return 1;
      int count = 0;
      for (int i = 1; i <= sqrt(n); i++) {
            if (n % i == 0) {
                  if ( i == n / i) {
                        count++;
                  }
                  else {
                        count += 2;
                  }
            }
      }
      return count;
}

int *num_divisors;
int *numbers;

int get_num_of_divisors (int value) {
      return num_divisors[value - 1];
}

int compare(const void * a, const void * b) {
      return (( get_num_of_divisors(* (int *) a ) < get_num_of_divisors( * (int *) b ) ) || ( *(int *)a > *(int *)b ));
}

void preprocess() {
        numbers = (int *) malloc(SIZE * sizeof(int));
      num_divisors = (int *) malloc(SIZE * sizeof(int));
      for (int i = 1; i <= SIZE; i++) {
            numbers[i-1] = i;
            num_divisors[i-1] = count_factors(i);
            //printf("%d -> %d, \t", numbers[i-1], get_num_of_divisors(numbers[i-1]) );
      }
      //printf("\n\n");

      qsort(numbers, SIZE, sizeof(int), compare);

      //for (int j = 0; j < SIZE; j++) {
            //printf("%d -> %d, \t", numbers[j], get_num_of_divisors(numbers[j]));
      //}
}

int main() {
      int T, inp;
      preprocess();
        scanf("%d", &T);
        for (int i = 1; i <= T; i++) {
                scanf("%d", &inp);
                printf("Case %d: %d\n", i, numbers[SIZE - inp]);
        }
      return 0;
}
