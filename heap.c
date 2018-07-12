#include <stdlib.h>
#include <stdio.h>

#define  parent(i)  ((i)/2)
#define  swap(a,b)  { int temp = a; a = b; b = temp; }

struct heap {
	int *arr;
	int capacity;
	int size;
};

void h_print(struct heap *H);
void h_printR(struct heap *H, int i, int level);
inline int min(int a, int b) {
	return a < b ? a : b;
}

struct heap makeheap(int cap) {
	struct heap temp;

	temp.arr = malloc(sizeof(int) * (cap+1));
	temp.capacity = cap;
	temp.size = 0;
	return temp;
}

void h_print(struct heap *H) {
	h_printR(H, 1, 0);
}

void h_printR(struct heap *H, int i, int level) {
	int n;

	if (i > H->size)
		return;
	for (n = 0; n < level; ++n)
		printf("  ");
	printf("%02d\n", H->arr[i]);

	h_printR(H, i*2, level+1);
	h_printR(H, i*2+1, level+1);
}

void heapify_up(struct heap *H, int i) {
	int j;
	while (i > 1) {	
		j = parent(i);
		if (H->arr[i] >= H->arr[j])
			break;
		swap(H->arr[i], H->arr[j]);
		i = j;
	}
}

void heapify_down(struct heap *H, int i) {
	int j, size = H->size;

	for (;;) {
		j = 2*i;
		if (j > size)
			break;
		if (j < size && H->arr[j] > H->arr[j+1])
			j++;
		if (H->arr[i] <= H->arr[j])
			break;
		swap(H->arr[i], H->arr[j]);
		i = j;
	}
}

void h_insert(struct heap *H, int i) {
	if (H->size == H->capacity) {
		H->capacity = 2 * H->capacity;
		H->arr = realloc(H->arr, sizeof(int) * (H->capacity+1));
	}
	H->size++;
	H->arr[H->size] = i;
	heapify_up(H, H->size);
}

int h_extractmin(struct heap *H) {
	int result = H->arr[1];
	H->arr[1] = H->arr[H->size--];
	heapify_down(H, 1);
	return result;
}

int h_findmin(struct heap *H) {
	return H->arr[1];
}

void h_merge(struct heap *G, struct heap *H) {
	struct heap R = makeheap(G->capacity+H->size);
	G->arr = R->s
}

int main() {
	int n, i;
	struct heap heap = makeheap(16);

	srand(1001);
	for (i = 0; i < 32; ++i) {
		int key = rand() % 100;
		h_insert(&heap, key);
	}

	printf("%d", h_extractmin(&heap));
	for (i = 0; i < 31; ++i) {
		printf(" %d", h_extractmin(&heap));
	}
	printf("\n");

	return 0;
}

