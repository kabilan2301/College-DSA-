#include<stdio.h>

#include<stdlib.h>

struct node {
  int data;
  struct node * next;
};
struct node * head = NULL;
struct node * p, * n, * prev;
int item, key, i;
void insert_middle() {

  n = (struct node * ) malloc(sizeof(struct node));
  printf("Enter the position to be inserted (The Positions of the list starts from \'0\')\n");
  scanf("%d", & key);
  if (key == 0 && head == NULL) {
    printf("Enter the data to be inserted");
    scanf("%d", & item);
    n -> data = item;
    n -> next = NULL;
    head = n;
    printf("Element inserted at position %d is => %d", key, n -> data);

    return;
  }
  if (head == NULL && key != 0) {
    printf("The list is empty (Enter data at the First Position(Try 0))");
  } else {
    printf("Enter the data to be inserted");
    scanf("%d", & item);
    n -> data = item;

    p = head;
    if (key == 0) {
      n -> data = item;
      n -> next = p;
      head = n;
      printf("Element inserted at position %d is => %d", key, n -> data);
      return;
    }
    for (i = 1; i < key; i++) {
      p = p -> next;
      if (p == NULL) {
        printf("\nInvalid Position");
        return;
      }
    }
    n -> next = p -> next;
    p -> next = n;
    printf("Element inserted at position %d is => %d", key, n -> data);
  }
}

void dlt_specific() {
  int flag = 0, key;
  if (head == NULL) {
    printf("The List is Empty");
  }
  printf("Enter the position element to be deleted\n The Positions of the list starts from \'0\' \n");
  scanf("%d", & key);
  p = head;
  prev = head;
  if (key == 0) {
    p = head;
    head = p -> next;
    printf("The Element Deleted is %d", p -> data);
    free(p);
  } else {
    for (i = 1; i <= key; i++) {
      prev = p;
      p = p -> next;
      if (p == NULL) {
        printf("\nInvalid Position");
        return;
      }
    }
    prev -> next = p -> next;
    printf("The Element Deleted is %d", p -> data);
    free(p);
  }
}

void display() {
  p = head;
  if (head == NULL) {
    printf("List is empty");
  }
  printf("Nodes of Singly linked list: \n");
  while (p != NULL) {
    printf(" \t %d\t", p -> data);
    p = p -> next;
  }
}

void insert_sorted() {
  n = (struct node * ) malloc(sizeof(struct node));
  printf("Enter the data to be inserted");
  scanf("%d", & item);
  n -> data = item;
  p = head;
  if (head == NULL || n -> data < p -> data) {
    n -> next = p;
    head = n;
    return;
  }
  while (p -> next != NULL && p -> next -> data < n -> data) {
    p = p -> next;
  }
  n -> next = p -> next;
  p -> next = n;
  printf("Element inserted is %d", n -> data);
}

void main() {
  int choice;
  printf("\n 1.Insert by Giving Position \n 2.Delete by given Position \n 3.Insert in Sorted Order\n 4.Display\n 5.EXIT\n");
  do {
    printf("\n Enter the choice:");
    scanf("%d", & choice);
    switch (choice) {
    case 1:
      insert_middle();
      break;
    case 2:
      dlt_specific();
      break;
    case 3:
      insert_sorted();
      break;
    case 4:
      display();
      break;
    case 5:
      printf("EXIT POINT");
      break;
    default:
      printf("Enter a valid Choice");
      break;
    }
  } while (choice != 5);
}
