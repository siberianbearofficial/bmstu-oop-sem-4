#ifndef EDGES_H
#define EDGES_H

#include <cstdio>
#include <cstdlib>

#include "my_error.h"
#include "edge.h"

typedef struct edges
{
    edge_t *array;
    int size;
} edges_t;

my_error_t edges_allocate(edges_t **edges);

my_error_t edges_free(edges_t **edges);

my_error_t edges_initialize(edges_t &edges);

my_error_t edges_read(FILE *fin, edges_t &edges);

my_error_t edges_write(FILE *fin, const edges_t &edges);

my_error_t edges_get(const edges_t &edges, edge_t **edge, const int index);

#endif // EDGES_H
