#include <stdio.h>

int main(int argc, char* argv[]) {

  FILE *p_in, *p_out;
  char buf[80];
  p_in = popen(argv[1], "r");
  p_out = popen(argv[2], "w");

  while (fgets(buf, 80, p_in))
    fputs(buf, p_out);
  pclose(p_in);
  pclose(p_out);
  return 0;
}

