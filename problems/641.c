#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int length;
  int start;
  int count;
  int buf[];
} MyCircularDeque;


MyCircularDeque* myCircularDequeCreate(int k) {
  MyCircularDeque* deque = malloc(sizeof(MyCircularDeque) + sizeof(int) * k);
  deque->start = 0;
  deque->count = 0;
  deque->length = 0;

  return deque;
}

bool myCircularDequeIsEmpty(MyCircularDeque* obj) {
  return !obj->count;
}

bool myCircularDequeIsFull(MyCircularDeque* obj) {
  return obj->length == obj->count;
}

bool myCircularDequeInsertFront(MyCircularDeque* obj, int value) {
  if (myCircularDequeIsFull(obj)) {
    return false;
  }

  obj->start = (obj->start ? obj->start : obj->length) - 1;
  obj->buf[obj->start] = value;
  obj->count++;

  return true;
}

bool myCircularDequeInsertLast(MyCircularDeque* obj, int value) {
  if (myCircularDequeIsFull(obj)) {
    return false;
  }

  obj->count++;
  obj->buf[(obj->start + obj->count) % obj->length] = value;

  return true;
}

bool myCircularDequeDeleteFront(MyCircularDeque* obj) {
  if (myCircularDequeIsEmpty(obj)) {
    return false;
  }

  obj->count--;
  obj->start = (obj->start + 1) % obj->length;

  return true;
}

bool myCircularDequeDeleteLast(MyCircularDeque* obj) {
  if (myCircularDequeIsEmpty(obj)) {
    return false;
  }

  obj->count--;

  return true;
}

int myCircularDequeGetFront(MyCircularDeque* obj) {
  return !obj->count ? -1 : obj->buf[obj->start];
}

int myCircularDequeGetRear(MyCircularDeque* obj) {
  return !obj->count ? -1 : obj->buf[(obj->start + obj->count - 1) % obj->length];
}

void myCircularDequeFree(MyCircularDeque* obj) {
  free(obj); 
}

int main() {
  return 0;
}
