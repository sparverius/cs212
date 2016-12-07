#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node* next;
};

struct node* build123() {
  struct node* head = NULL;
  struct node* second = NULL;
  struct node* third = NULL;

  head = (node *) malloc(sizeof(struct node));

  second = (node *) malloc(sizeof(struct node));
  third = (node *) malloc(sizeof(struct node));
  
  head->data = 1;
  head->next = second;
  
  second->data = 2;
  second->next = third;
  
  third->data = 3;
  third->next = NULL; 
  return head;
}

int main(void) {
 d  
}
