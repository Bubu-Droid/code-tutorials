#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *link;
};

void reverse_list(struct node *head) {
  struct node *ptr1 = head;
  struct node *ptr2 = head;
  struct node *ptr3 = head;

  ptr1 = NULL;
  ptr2 = head;
  head->link = ptr1;
  while (ptr2 != NULL) {
    ptr1 = ptr2;
    ptr2 = ptr2->link;
    ptr1->link = ptr1;
  }
}

int main() {
  struct node *head = NULL;
  head = (struct node *)malloc(sizeof(struct node));
  head->data = 75;
  head->link = NULL;

  return 0;
}
