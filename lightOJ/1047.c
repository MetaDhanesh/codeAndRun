/*
 * 1047 - Neighbor House
*/
#include<stdio.h>

#define MIN(a, b) a < b ? a : b
#define MIN_3(a, b, c) a < b ? MIN(a, c) : MIN(b, c)
int main() {

      int T, i, j;
      int size;
      int prev_r, prev_g, prev_b;
      int r, g, b;
      int min_cost;
      scanf("%d", &T);
      for(i = 1; i <= T; i++) {
            scanf("\n%d", &size);
            prev_r = 0;
            prev_g = 0;
            prev_b = 0;
            for ( j = 0; j < size; j++) {
                  scanf("%d %d %d", &r, &g, &b);
                  r += MIN(prev_g, prev_b);
                  g += MIN(prev_r, prev_b);
                  b += MIN(prev_r, prev_g);
                  prev_r = r;
                  prev_g = g;
                  prev_b = b;
            }
            min_cost = MIN_3(prev_r, prev_g, prev_b);
            printf("Case %d: %d\n", i, min_cost);
      }
      return 0;
}
