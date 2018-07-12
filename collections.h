// doubly linked list
struct list {
	void *data;
	struct list *next;
	struct list *prev;
};

struct alist {
	void *arr[];
	int len;	// current number of elements
	int cap; 	// allocated capacity
}

// queue implemented on top of linked list
struct queue {
	struct list *head;
	struct list *tail;
	int len;
};

struct graph {
	struct list *adj[];
	int num_nodes;
};

struct list* list_prepend(struct list *list, void *data);
struct list* list_append(struct list *list, void *data);
struct alist* alist_append(struct alist *list, void *data);
void queue_push_head(struct queue *q, void *data);
void queue_push_tail(struct queue *q, void *data);
void graph_add_edge(struct graph *g, int node1, int node2);
// void graph_serialize(struct graph *g, FILE *stream);
// struct graph *graph_deserialize(FILE *stream);