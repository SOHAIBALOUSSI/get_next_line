#include <stdio.h>

int main() {

  char *content[4];
  
  char res[10] = "batman";
  content[1] = res;
  content[2] = "salam";
  
  printf("%s ::: %s", content[1], content[2]);
  return 0;
}