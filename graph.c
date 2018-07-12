#include "collections.h"

void graph_add_edge(struct graph *g, int node1, int node2) {
	if (g == NULL) {
		g = {
			malloc(sizeof(struct graph)),
			malloc(sizeof),
			2
		};
	}
	g->adj[node1] = list_prepend(g->adj[node1], &node2);
	g->adj[node2] = list_prepend(g->adj[node2], &node1);
}

int main() {
	g->adj = malloc(sizeof())
}