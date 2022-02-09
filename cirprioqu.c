#include <stdio.h>
#define SIZE 5

int front = -1;
int rear = -1;

int items[SIZE];

struct element {
    int value;
    int priority;
};

struct element queue[SIZE];

void add(int value, int priority) {
    if (rear == SIZE - 1) {
        printf("Queue is full\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear++;

    int pos;
    for (pos = rear; pos > 0; pos--) {
        if (queue[pos - 1].priority < priority) {
            queue[pos].value = queue[pos - 1].value;
            queue[pos].priority = queue[pos - 1].priority;
        } else {
            break;
        }
    }
    queue[pos].value = value;
    queue[pos].priority = priority;
}

void pop() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("%d\n", queue[front].value);
    for(int i = front; i < rear; i++) {
        queue[i].value = queue[i + 1].value;
        queue[i].priority = queue[i + 1].priority;
    }
    rear--;
    if(rear == -1) {
        front = -1;
    }
}
void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    for (int i = front; i <= rear; i++) {
        printf("%d\n", queue[i].value);
    }
}

int isFull() {
  if ((front == rear + 1) || (front == 0 && rear == SIZE - 1)) return 1;
  return 0;
}

// Check if the queue is empty
int isEmpty() {
  if (front == -1) return 1;
  return 0;
}

// Adding an element
void enQueue(int element) {
  if (isFull())
    printf("\n Queue is full!! \n");
  else {
    if (front == -1) front = 0;
    rear = (rear + 1) % SIZE;
    items[rear] = element;
    printf("\n Inserted -> %d", element);
  }
}

// Removing an element
int deQueue() {
  int element;
  if (isEmpty()) {
    printf("\n Queue is empty !! \n");
    return (-1);
  } else {
    element = items[front];
    if (front == rear) {
      front = -1;
      rear = -1;
    } 
    // Q has only one element, so we reset the 
    // queue after dequeing it. ?
    else {
      front = (front + 1) % SIZE;
    }
    printf("\n Deleted element -> %d \n", element);
    return (element);
  }
}

// Display the queue
void display2() {
  int i;
  if (isEmpty())
    printf(" \n Empty Queue\n");
  else {
    printf("\n Front -> %d ", front);
    printf("\n Items -> ");
    for (i = front; i != rear; i = (i + 1) % SIZE) {
      printf("%d ", items[i]);
    }
    printf("%d ", items[i]);
    printf("\n Rear -> %d \n", rear);
  }
}

void main()
{
    while(1) {
        printf("\n1. Priority Queue\n");
        printf("2. Circualr Queue\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);
        if(choice==1) {
            front = -1;
            rear = -1;
            while(1) {
                printf("\n1. Add\n");
                printf("2. Remove\n");
                printf("3. Display\n");
                printf("4. Exit\n");
                printf("Enter your choice: ");
                int choice2;
                scanf("%d", &choice2);
                if(choice2==1) {
                    int value;
                    int priority;
                    scanf("%d", &value);
                    scanf("%d", &priority);
                    add(value, priority);
                }
                else if(choice2==2) {
                    pop();
                }
                else if(choice2==3) {
                    display();
                }
                else if(choice2==4) {
                    break;
                }
            }
        }
        else if(choice==2) {
            front = -1;
            rear = -1;
            while(1) {
                printf("\n1. Add\n");
                printf("2. Remove\n");
                printf("3. Display\n");
                printf("4. Exit\n");
                printf("Enter your choice: ");
                int choice2;
                scanf("%d", &choice2);
                if(choice2==1) {
                    int value;
                    scanf("%d", &value);
                    enQueue(value);
                }
                else if(choice2==2) {
                    deQueue();
                }
                else if(choice2==3) {
                    display2();
                }
                else if(choice2==4) {
                    break;
                }
            }
        }
        else if(choice==3) {
            break;
        }
    }
}