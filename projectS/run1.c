/* run1.c
 * Richard Kent
 * exec demo
 */

#define MAX 5

int main(void) {
  char *args[MAX];
  args[0] = "ps";
  args[1] = "-1";
  args[2] = 0;

  write(1, "Get Ready!\n\n", 12);
  execvp("ps", args);
  write(1, "Do you see this?\n",17);
  return 0;
}
