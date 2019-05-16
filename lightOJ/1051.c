/*
 * 1051 - Good or Bad
*/ 

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {

      int T, i, j;
      int size;
      int consonant, vowel, question;
      int flag; // 0 -> BAD, 1 -> MIXED, 2 -> GOOD
      char * s = (char *)malloc(sizeof(char) * 50);
      scanf("%d", &T);
      for(i = 1; i <= T; i++) {
            scanf("%s", s);
            size = strlen(s);
            flag = 2;
            consonant = 0;
            vowel = 0;
            question = 0;
            for(j = 0; j < size; j++) {
                  switch(s[j]) {
                        case 'A':
                        case 'E':
                        case 'I':
                        case 'O':
                        case 'U':
                              vowel++;
                              consonant = 0;
                              break;
                        case '?':
                              vowel++;
                              consonant++;
                              question += 1;
                              break;
                        default:
                              consonant++;
                              vowel = 0;
                  }
                  if ( (vowel == 3 && question > 0 ) || ( question > 0 && consonant == 5) ) {
                        if (flag == 1) {
                              flag = 0;
                              break;
                        }
                        flag = 1;
                  }
                  else if (vowel == 3 || consonant == 5) {
                        flag = 0;
                        break;
                  }

            }
            if (flag == 0) {
                  printf("Case %d: %s\n", i, "BAD");
            } else if (flag == 1) {
                  printf("Case %d: %s\n", i, "MIXED");
            } else {
                  printf("Case %d: %s\n", i, "GOOD");
            }
      }
      return 0;
}
