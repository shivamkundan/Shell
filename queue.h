#include <stdio.h>
#include <stdlib.h>

struct node {				
       int pid;
	     char *name;
       struct node *next;
	
};


struct queue {				
       struct node *head;
       struct node *tail ;
};

     
void enqueue(int item, char *s, struct queue *q) {		
     struct node *p;						

     p= (struct node *)malloc(sizeof(struct node));
     p->pid=item;
     p->name=s;	
     p->next=NULL;
     if (q->head==NULL) q->head=q->tail=p;
     else {
          q->tail->next=p;
          q->tail=p;
     }

}


int dequeue(struct queue *q) {		
    int item;				
    struct node *p;
    
    item=q->head->pid;
    p=q->head;
    q->head=q->head->next;
    free(p);
    return item;
}


void delete(struct queue *q, int key)
{
     if (q->head->pid == key)
     {
        struct node *p = q->head;
        q->head = q->head->next;
        free(p);
        return;
    }
    struct node *current = q->head->next;
    struct node *previous = q->head;
    while (current != NULL && previous != NULL)
    {
      if (current->pid == key)
      {
        struct node *tmp = current;
        if (current == q->tail)
          q->tail = previous;
        previous->next = current->next;
        free(tmp);
        return;
      }
      previous = current;
      current = current->next;
    }
    return;  
  }

void queueRotate(struct queue *qp)
/*Pushes first element to the back of the queue.*/
{
    struct node *old_head, *old_tail = (struct node*) malloc(sizeof(struct node));
    old_head = qp->head;
    old_tail = qp->tail;

    qp->head=old_head->next;

    qp->tail->next=old_head;
    qp->tail=old_head;
    old_head->next=NULL;
}

