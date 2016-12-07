#include <stdio.h>
#include <stdlib.h>

typedef struct node node;

struct node {
  int info;
  node* next;
};

int main() {
  node* head;
  head = (node *) malloc(sizeof(node));
  head->info = 5;
  node* current = (node *) malloc(sizeof(node));

  current->info = 10;
  current->next = NULL;
  head->next = current;
  current = head;
  while(current != NULL) {
    printf("%d\n", current->info);
    current = current->next;
  }
}
