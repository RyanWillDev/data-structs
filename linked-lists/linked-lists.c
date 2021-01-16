#include <stdlib.h>
#include <stdio.h>

struct Element {
  int data;
  struct Element *next;
};

struct Element* newList(int n) {
  struct Element *el;
  el = (struct Element*) malloc(sizeof(struct Element));

  el->next = NULL;
  el->data = n;

  return el;
}

struct Element* prepend(struct Element* list, int n) {
  struct Element *el = newList(n);
  el->next = list;

  return el;
}

struct Element* append(struct Element* list, int n) {
  struct Element *el = newList(n);
  struct Element* current = list;

  // A next value of NULL indicates we're at the end of the list
  while (current->next != NULL) {
    current = current->next;
  }

  // Since we're now at the end we just need to set the current
  // elements next value to the newly created element
  current->next = el;

  return list;
}

int includes(struct Element* list, int n) {
  struct Element* current = list;

  // Traverse the list
  while (current != NULL) {
    // If the current element is the value we're looking for return 1 (TRUE)
    if (current->data == n) {
      return 1;
    }
    // Keep looking for the element
    current = current->next;
  }

  return 0;
}

int valueAt(struct Element* list, int n) {
  struct Element* current = list;
  int i = 0;

  while (current != NULL && n != i) {
    current = current->next;
    i++;
  }

  return current->data;
}


struct Element* insertAt(struct Element* list, int n, int v) {
  struct Element* current = list;
  int i = 0;
  struct Element* next;
  struct Element* new;

  // This is the equivalent of calling prepend so we'll just do that
  if (n == 0) {
    return prepend(list, v);
  }

  // We want to stop just before the index we're looking for so we can
  // update its next value ot the new element
  while (current != NULL && i < n - 1) {
    current = current->next;
    i++;
  }

  new = newList(v);

  // Insert the new element between the current one and its next value
  next = current->next;
  new->next = next;
  current->next = new;

  return list;
}

// Does not allow concatenating a list with itself
struct Element* concat(struct Element* a, struct Element* b) {
  struct Element* current = a;

  while(current->next != NULL) {
    current = current->next;
  }

  current->next = b;

  return a;
}

struct Element* mapList(struct Element* list, int (*f)(int)) {
  struct Element* current = list;

  while (current != NULL) {
    current->data = (*f)(current->data);
    current = current->next;
  }

  return list;
}

// Just a way to see what's in the list
int peak(int n) {
  printf("%i\n", n);

  return n;
}

int main() {
  struct Element* list = newList(1);
  list = prepend(list, 2);
  list = prepend(list, 3);
  list = append(list, 4);
  list = insertAt(list, 1, 5);

  int includesFour = includes(list, 4);
  int includesFive = includes(list, 5);
  int value2 = valueAt(list, 2);

  printf("includesFour %i; includesFive %i\n", includesFour, includesFive);
  printf("valueAt 2: %i\n", value2);

  list = mapList(list, &peak);
  printf("-------------------\n");
  list = concat(list, newList(6));
  list = mapList(list, &peak);
  printf("-------------------\n");
  list = append(list, 7);
  list = mapList(list, &peak);

  return 0;
}
