#include <stdio.h>
#include <stdlib.h>

#include "deq.h"

// Define the deque node structure
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;



int main() {
  Deq q=deq_new();

  char *s=deq_str(q,0);
  printf("%s\n",s);
  free(s);

  deq_del(q,0);
  return 0;
}
