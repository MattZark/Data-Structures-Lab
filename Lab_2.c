//---------------------------------
//Implement Stack using Queues
//---------------------------------
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
    int size;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = 0;
    q->rear = -1;
    q->size = 0;
    return q;
}

bool queueEmpty(Queue* q) {
    return (q->size == 0);
}

void enqueue(Queue* q, int x) {
    if (q->size == MAX_SIZE) {
        return;
    }
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->data[q->rear] = x;
    q->size++;
}

int dequeue(Queue* q) {
    if (queueEmpty(q)) {
        return -1;
    }
    int val = q->data[q->front];
    q->front = (q->front + 1) % MAX_SIZE;
    q->size--;
    return val;
}

int queueFront(Queue* q) {
    return q->data[q->front];
}

typedef struct {
    Queue* q1;
    Queue* q2;
} MyStack;

MyStack* myStackCreate() {
    MyStack* obj = (MyStack*)malloc(sizeof(MyStack));
    obj->q1 = createQueue();
    obj->q2 = createQueue();
    return obj;
}

void myStackPush(MyStack* obj, int x) {
    enqueue(obj->q2, x);

    while (!queueEmpty(obj->q1)) {
        enqueue(obj->q2, dequeue(obj->q1));
    }

    Queue* temp = obj->q1;
    obj->q1 = obj->q2;
    obj->q2 = temp;
}

int myStackPop(MyStack* obj) {
    return dequeue(obj->q1);
}

int myStackTop(MyStack* obj) {
    return queueFront(obj->q1);
}

bool myStackEmpty(MyStack* obj) {
    return queueEmpty(obj->q1);
}

void myStackFree(MyStack* obj) {
    free(obj->q1);
    free(obj->q2);
    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/



//---------------------------------
//Implement Queue using Stacks
//---------------------------------
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

Stack* createStack() {
    Stack* st = (Stack*)malloc(sizeof(Stack));
    st->top = -1;
    return st;
}

bool stackEmpty(Stack* st) {
    return (st->top == -1);
}

void stackPush(Stack* st, int x) {
    if (st->top == MAX_SIZE - 1) {
        return;
    }
    st->data[++(st->top)] = x;
}

int stackPop(Stack* st) {
    if (stackEmpty(st)) {
        return -1;
    }
    return st->data[(st->top)--];
}

int stackTop(Stack* st) {
    return st->data[st->top];
}

typedef struct {
    Stack* sIn;   
    Stack* sOut;  
} MyQueue;

MyQueue* myQueueCreate() {
    MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
    obj->sIn  = createStack();
    obj->sOut = createStack();
    return obj;
}

void myQueuePush(MyQueue* obj, int x) {
    stackPush(obj->sIn, x);
}

int myQueuePop(MyQueue* obj) {
    if (stackEmpty(obj->sOut)) {
        while (!stackEmpty(obj->sIn)) {
            stackPush(obj->sOut, stackPop(obj->sIn));
        }
    }
    return stackPop(obj->sOut);
}

int myQueuePeek(MyQueue* obj) {
    if (stackEmpty(obj->sOut)) {
        while (!stackEmpty(obj->sIn)) {
            stackPush(obj->sOut, stackPop(obj->sIn));
        }
    }
    return stackTop(obj->sOut);
}

bool myQueueEmpty(MyQueue* obj) {
    return (stackEmpty(obj->sIn) && stackEmpty(obj->sOut));
}

void myQueueFree(MyQueue* obj) {
    free(obj->sIn);
    free(obj->sOut);
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/
