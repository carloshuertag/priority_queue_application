/******************************************************
 * dynamic_string_priority_queue
 * @author: Carlos Huerta García
 * @description: String priority queue implementation
 * ***************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

typedef struct QueueElement{
    char entry[255];
    struct QueueElement * next;
} QueueElement;

typedef struct Queue{
    QueueElement * front;
} Queue;

Queue * createQueue(){
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if(!queue)
        exit(1);
    queue->front = NULL;
    return queue;
}

bool queueIsEmpty(Queue * queue) {
    return !queue->front;
}

QueueElement * createQueueElement(char item[]) {
    QueueElement* element = (QueueElement*)malloc(sizeof(QueueElement));
    if (!element) 
        exit(1);
    strcpy(element->entry, item);
    element->next = NULL;
    return element;
}

// @returns: string1 priority is higher than string2 priority
bool isHigher(char string1[], char string2[]) {
    int i = 0;
    while(i <= strlen(string1)){
        if(tolower(string1[i]) > tolower(string2[i]))
            return true;
        if(tolower(string1[i]) < tolower(string2[i]))
            return false;
        if(tolower(string1[i]) == tolower(string2[i]))
            i++;
    }
    return true;
}

void enQueue(char item[], Queue * queue) {
    QueueElement * element = createQueueElement(item);
    if(queueIsEmpty(queue))
        queue->front = element;
    else {
        QueueElement * tmp = queue->front;
        if(isHigher(queue->front->entry, element->entry)){
            element->next = queue->front;
            queue->front = element;
        } else {
            while (tmp->next && isHigher(element->entry, tmp->next->entry))
                tmp = tmp->next;
            element->next = tmp->next;
            tmp->next = element;
        }
    }
}

void front(Queue * queue, char front[]) {
    if(queueIsEmpty(queue)){
        strcpy(front, "");
        return;
    }
    strcpy(front, queue->front->entry);
}

void deQueue(Queue * queue, char dequeued[]) {
    if(queueIsEmpty(queue)){
        strcpy(dequeued, "");
        return;
    }
    QueueElement* temp = queue->front;
    strcpy(dequeued, queue->front->entry);
    queue->front = queue->front->next;
    free(temp);
}

void printQueue(Queue * queue) {
    if(queueIsEmpty(queue)){
        puts("[ ]");
        return;
    }
    QueueElement* element = queue->front;
    while (element->next) {
        printf("-[%s]-", element->entry);
        element = element->next;
    }
    printf("-[%s]-", element->entry);
}

void clearQueue(Queue * queue) {
    if(!queueIsEmpty(queue)){
        QueueElement* element;
        while ((element = queue->front)) {
            queue->front = queue->front->next;
            free(element);
        }
        queue->front = NULL;
    }
}
