/*
JTSK-320112
Problem 6.2
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

/**
 * @file queue.c
 */

#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

static void copy_to_node(Item item, Node *pn);
static void copy_to_item(Node *pn, Item *pi);

void initialize_queue(Queue *pq)
{
	pq->front = pq->rear = NULL;
	pq->items = 0;
}

int queue_is_full(const Queue *pq)
{
	return pq->items == MAXQUEUE;
}

int queue_is_empty(const Queue *pq)
{
	return pq->items == 0;
}

int queue_item_count(const Queue *pq)
{
	return pq->items;
}

int enqueue(Item item, Queue *pq)
{
    //Overflow of queue
    if(queue_is_full(pq)){
        return -1;
    }

    Node *newel = (Node*)malloc(sizeof(Node));
    
    //If not allocated memo
    if(newel == NULL){
        return -1;
    }
    copy_to_node(item, newel);
    newel->next = NULL;

    //Checking if the queue is empty
    if(queue_is_empty(pq)){
        pq->front = newel;
        pq->rear = pq->front;
    } else {
        pq->rear->next = newel;
        pq->rear = pq->rear->next;
    }

    pq->items++;

    return 0;
}

int dequeue(Item *pitem, Queue *pq)
{
	if(queue_is_empty(pq)){
        // Queue is Underflow
        return -1;
    }

    Node *temp = pq->front;
    copy_to_item(pq->front, pitem);
    pq->front = pq->front->next;

    //Freeing the memory occupied by the first item in the queue
    free(temp);
    pq->items--;

    //Checking if the number of items is equall to 0
    if(pq->items == 0){
        pq->front = pq->rear = NULL;
    }

    return 0;
}

void empty_queue(Queue *pq)
{
	Item dummy;
	while (!queue_is_empty(pq)) {
		dequeue(&dummy, pq);
	}
}

static void copy_to_node(Item item, Node *pn)
{
	pn->item = item;
}

static void copy_to_item(Node *pn, Item *pi)
{
	*pi = pn->item;
}