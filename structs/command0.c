#include <stdio.h>
#include <stdlib.h>

typedef struct command command;

struct command {
  char* _cmd;
  char* _in;
  char* _out;
  char* _err;
  command* prev;
  command* next;
} 

int main() {
  command* head;
  head = (command *) malloc(sizeof(command));
  head->_cmd = "ls";
  head->_in = head->prev;
  head->_out = head->next;
  head->prev = NULL;
  head->next = NULL; 
   
  command* current = (command *) malloc(sizeof(command));
  current->_cmd = "sort";
  head->next = current;
  current.prev = head; 

   
}
