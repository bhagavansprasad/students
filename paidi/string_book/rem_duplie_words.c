#include <stdio.h>
  #include <string.h>

  int main() {
        char string[500]="paidi kumar paidi kumar banagalore aura institut paidi",text[256],words[100][256];
        int i, j, k, n;
        i = j = k = n = 0;
         string[strlen(string) - 1] = '\0';
        /* copying each and every word from the string */
        while (string[i] != '\0') {
                if (string[i] == ' ') {
                        words[j][k] = '\0';
                        k = 0;
                        j++;
                } else {
                        words[j][k++] = string[i];
                }
                i++;
        }
        words[j][k] = '\0';
        n = j;
        /* remove duplicate words in the given string */
        for (i = 0; i < n; i++) {
                for (j = i + 1; j <= n; j++) {
                        if (strcmp(words[i], words[j]) == 0) {
                                for (k = j; k < n; k++) {
                                        strcpy(words[k], words[k + 1]);
                                }
                                n--, j--;
                        }
                }
        }

        /* print the unique words */
        for (i = 0; i <= n; i++) {
                printf("%s ", words[i]);
        }

        printf("\n");
        return 0;
  }

