#include <stdbool.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int top;
} Stack;

typedef struct {
    Stack in;
    Stack out;
} MyQueue;

/* ===== stack functions ===== */
void push(Stack* s, int x) {
    s->data[++s->top] = x;
}

int pop(Stack* s) {
    return s->data[s->top--];
}

int peek(Stack* s) {
    return s->data[s->top];
}

bool isEmpty(Stack* s) {
    return s->top == -1;
}

/* ===== queue functions ===== */

MyQueue* myQueueCreate() {
    MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
    obj->in.top = -1;
    obj->out.top = -1;
    return obj;
}

void myQueuePush(MyQueue* obj, int x) {
    push(&obj->in, x);
}

int myQueuePop(MyQueue* obj) {
    if (isEmpty(&obj->out)) {
        while (!isEmpty(&obj->in)) {
            push(&obj->out, pop(&obj->in));
        }
    }
    return pop(&obj->out);
}

int myQueuePeek(MyQueue* obj) {
    if (isEmpty(&obj->out)) {
        while (!isEmpty(&obj->in)) {
            push(&obj->out, pop(&obj->in));
        }
    }
    return peek(&obj->out);
}

bool myQueueEmpty(MyQueue* obj) {
    return isEmpty(&obj->in) && isEmpty(&obj->out);
}

void myQueueFree(MyQueue* obj) {
    free(obj);
}