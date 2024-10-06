#include <stdio.h>
#include <string.h>

void poscheck(const char* str, char char1, char char2) {
  char *pos1 = strchr(str, char1);
  char *pos2 = strchr(str, char2);
  if (pos1 < pos2) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }
}

int main() {
  char str[10];
  char char1 = 'R';
  char char2 = 'M';
  fgets(str, sizeof(str), stdin);
  str[strcspn(str, "\n")] = 0;
  poscheck(str, char1, char2);
  return 0;
}
