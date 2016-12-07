/* run0.c
 * Richard Kent
 * A program that runs other programs!
 */

int main(int argc, char** args) {
  write(1, "Get Ready!\n\n",12);
  execvp(args[1],args + 1);
  write(1, "Do you see this?\n",17);
  return 0;
}
