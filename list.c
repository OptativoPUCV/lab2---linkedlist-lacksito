#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() {
   List* newList = (List*)malloc(sizeof(List));
  if (newList == NULL)
  {
    return NULL;
  }
  newList->head = NULL;
  newList->current = NULL;
  newList->tail = NULL;
  return newList;
}

void * firstList(List * list) 
{
  if (list->head != NULL)
  {
    list->current = list->head;
    return list->current->data;
  }
  return NULL;
}

void * nextList(List * list) 
{
  if(list->current != NULL && list->current->next)
  {
    list->current = list->current->next;
    return list->current->data;
  }
  return NULL;
}

void * lastList(List * list) {
  if(list->head == NULL)
  {
    return NULL;
  }
  Node * current = list->head;
  while(current->next != NULL)
  {
    current= current->next;  
  }
  list->current = current;
  return list->current->data;
}

void * prevList(List * list) {
  if (list->current == NULL || list->current == list->head)
  {
    return NULL;
  }
  Node* current = list->head;
  while(current->next != list->current)
    {
      current = current->next;
    }
  list->current = current;
  return list->current->data;
}

void pushFront(List * list, void * data) {
  Node* newNode = createNode(data);

  newNode->next = list->head;
  if (list->head) 
  {
    list->head->prev = newNode;
  } 
  else 
  {
    list->tail = newNode;
  }

  list->head = newNode;
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
  Node* newNode = createNode(data);

  newNode->next = list->current->next;
  if(list->current->next)
  {
    list->current->next->prev = newNode;
  }
  else
  {
    list->tail = newNode;
  }
  newNode->prev = list->current;
  list->current->next = newNode;
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
    return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}