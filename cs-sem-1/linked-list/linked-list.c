#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *link;
};

void count_of_nodes(struct node *head);
void print_list(struct node *head);
void add_at_end(struct node *head, int data);
struct node *add_at_beg(struct node *head, int data);
void alt_add_at_beg(struct node **head, int data);
void insert_at_pos(struct node *head, int data, int pos);
struct node *del_first_node(struct node *head);
struct node *del_last_node(struct node *head);
void alt_del_last_node(struct node **head);
struct node *del_at_pos(struct node *head, int pos);
struct node *del_entire_list(struct node *head) {
  if (head == NULL) {
    printf("The linked list has been deleted!\n");
    return NULL;
  } else {
    return del_entire_list(del_last_node(head));
  }
}

int main() {
  struct node *head = NULL;
  head = (struct node *)malloc(sizeof(struct node));
  head->data = 45;
  head->link = NULL;

  add_at_end(head, 98);
  add_at_end(head, 3);

  // struct node *current = (struct node *)malloc(sizeof(struct node));
  // current->data = 98;
  // current->link = NULL;
  // head->link = current;
  //
  // current = (struct node *)malloc(sizeof(struct node));
  // current->data = 3;
  // current->link = NULL;
  // head->link->link = current;

  count_of_nodes(head);
  print_list(head);

  add_at_end(head, 49);

  count_of_nodes(head);
  print_list(head);

  head = add_at_beg(head, 28);

  count_of_nodes(head);
  print_list(head);

  alt_add_at_beg(&head, 69);

  count_of_nodes(head);
  print_list(head);

  insert_at_pos(head, 420, 3);

  count_of_nodes(head);
  print_list(head);

  head = del_first_node(head);

  count_of_nodes(head);
  print_list(head);

  del_last_node(head);

  count_of_nodes(head);
  print_list(head);

  alt_del_last_node(&head);

  count_of_nodes(head);
  print_list(head);

  head = del_at_pos(head, 2);

  count_of_nodes(head);
  print_list(head);

  head = del_entire_list(head);

  count_of_nodes(head);
  print_list(head);

  return 0;
}

void count_of_nodes(struct node *head) {
  int count = 0;
  if (head == NULL) {
    printf("The linked list is empty!\n");
    return;
  }
  struct node *ptr = head;
  while (ptr != NULL) {
    count++;
    ptr = ptr->link;
  }
  printf("The length of the linked list is = %d\n", count);
}

void print_list(struct node *head) {
  if (head == NULL) {
    printf("The linked list is empty!\n");
    return;
  }
  struct node *ptr = head;
  while (ptr != NULL) {
    printf("%d -> ", ptr->data);
    ptr = ptr->link;
  }
  printf("NULL\n");
}

void add_at_end(struct node *head, int data) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  struct node *ptr = head;
  temp->data = data;
  temp->link = NULL;
  while (ptr->link != NULL) {
    ptr = ptr->link;
  }
  ptr->link = temp;
}

struct node *add_at_beg(struct node *head, int data) {
  struct node *ptr = (struct node *)malloc(sizeof(struct node));
  ptr->data = data;
  ptr->link = head;
  return ptr;
}

void alt_add_at_beg(struct node **head, int data) {
  struct node *ptr = (struct node *)malloc(sizeof(struct node));
  ptr->data = data;
  ptr->link = *head;
  *head = ptr;
}

void insert_at_pos(struct node *head, int data, int pos) {
  struct node *ptr = head;
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  int count = 0;
  if (pos == 1) {
    add_at_beg(head, data);
  }
  while (count < pos - 2) {
    ptr = ptr->link;
    count++;
  }
  temp->data = data;
  temp->link = ptr->link;
  ptr->link = temp;
}

struct node *del_first_node(struct node *head) {
  if (head == NULL) {
    printf("The linked list is empty!\n");
    return NULL;
  }
  struct node *ptr = head;
  ptr = head->link;
  head->link = NULL;
  free(head);
  return ptr;
}

struct node *del_last_node(struct node *head) {
  if (head == NULL) {
    printf("The linked list is empty!\n");
    return head;
  } else if (head->link == NULL) {
    return del_first_node(head);
  } else {
    struct node *ptr = head;
    while (ptr->link->link != NULL) {
      ptr = ptr->link;
    }
    free(ptr->link);
    ptr->link = NULL;
    return head;
  }
}

void alt_del_last_node(struct node **head) {
  if (*head == NULL) {
    printf("The linked list is empty!\n");
  } else if ((*head)->link == NULL) {
    *head = del_first_node(*head);
  } else {
    struct node *ptr = *head;
    while (ptr->link->link != NULL) {
      ptr = ptr->link;
    }
    free(ptr->link);
    ptr->link = NULL;
  }
}

struct node *del_at_pos(struct node *head, int pos) {
  if (pos == 1) {
    return del_first_node(head);
  }
  struct node *ptr = head;
  struct node *temp;
  int count = 0;
  while (count < pos - 2) {
    ptr = ptr->link;
    count++;
  }
  temp = ptr->link;
  ptr->link = ptr->link->link;
  free(temp);
  return head;
}
