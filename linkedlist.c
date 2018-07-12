#include <stdio.h>
#include <stdlib.h>
#include "collections.h"

struct list* list_prepend(struct list *list, void *data) {
	struct list *n;

	n = malloc(sizeof(struct list));
	n->data = data;
	n->prev = NULL;
	n->next = list;

	if (list != NULL)
		list->prev = n;

	return n;
}

struct list* list_append(struct list *list, void *data) {
	struct list *n, *l = list;

	n = malloc(sizeof(struct list));
	n->data = data;
	n->next = NULL;

	if (l == NULL)
		list = n;
	else {
		while (l->next != NULL)
			l = l->next;
		l->next = n;
	}
	n->prev = l;
	return list;
}

// struct list* list_remove_link(
// 	struct list *list,
// 	struct list *llink
// 	)

void queue_push_head(struct queue *q, void *data) {
	q->head = list_prepend(q->head, data);
	q->len++;
}

void queue_push_tail(struct queue *q, void *data) {
	q->tail = list_append(q->tail, data);
	q->len++;
}

int main() {
	struct list *mylist = NULL, *l;
	mylist = list_append(mylist, "happy");
	mylist = list_append(mylist, "to");
	mylist = list_append(mylist, "meet");
	mylist = list_append(mylist, "you");

	for (l = mylist; l != NULL; l = l->next) {
		printf("%s ", l->data);
	}
	return 0;
}