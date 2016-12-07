char* itoa(int num, char* str);

int main(void) {
  char str1[10];
  printf("%s\n",itoa(2009, str1));
}

char* itoa(int num, char* str) {
  int i = 0;
  while (num != 0) {
    str[i++] = num%10 + 48;
    num /= 10;
  }
  str[i++] = '\0';
  char *copy =  str;
  char *copy2 = copy + i+1;
  for (; copy < copy2; copy++, copy2--) {
    char temp = *copy;
    *copy = *copy2;
    *copy2 = temp;
  }
  return copy;
}
