#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int length;
  int start;
  int count;
  int buf[];
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
  MyCircularQueue* queue = malloc(sizeof(MyCircularQueue) + sizeof(int) * k);
  if (!queue) return NULL;
  
  queue->length = k;
  queue->start = 0;
  queue->count = 0;

  return queue;
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
  return obj->count == 0;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
  return obj->count == obj->length;
}

int myCircularQueueFront(MyCircularQueue* obj) {
  return myCircularQueueIsEmpty(obj) ? -1 : obj->buf[obj->start];
}

int myCircularQueueRear(MyCircularQueue* obj) {
  return myCircularQueueIsEmpty(obj) ? -1 : obj->buf[(obj->start + obj->count - 1) % obj->length];
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
  if (myCircularQueueIsFull(obj)) {
    return false;
  }

  obj->buf[(obj->start + obj->count) % obj->length] = value;
  obj->count++;

  return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
  if (myCircularQueueIsEmpty(obj)) {
    return false;
  }

  obj->start = (obj->start + 1) % obj->length;
  obj->count--;

  return true;
}

void myCircularQueueFree(MyCircularQueue* obj) {
  free(obj);
}

int main() {
  return 0;
}
