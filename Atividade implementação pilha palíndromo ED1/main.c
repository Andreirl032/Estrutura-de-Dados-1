#include "Stack.h"
#include <stdio.h>
#include <string.h>

int main() {
  char *oi = "AMEOPOVONATIMEEMITANOVOPOEMA";
  int len = strlen(oi);
  Epalindromo(oi, len);
  return 0;
}
