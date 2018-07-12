#include "collections.h"

#define  STARTCAP  2  // starting capacity of array list

struct alist* alist_append(struct alist *list, void *data) {
	if (list == NULL) {
		list = {
			malloc(STARTCAP * sizeof(void *))
			1,
			STARTCAP
		};
		list[0] = data;
	}
	else {
		if (list->len == list->cap) {
			list->cap *= 2;
			realloc(list->arr, list->cap * sizeof(void *));
		}
		list->arr[list->len++] = data;
	}
	return list;
}

int main() {
	
}