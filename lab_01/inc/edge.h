#ifndef EDGE_H
#define EDGE_H

#include <cstdio>
#include <cstdlib>

#include "my_error.h"

typedef struct edge
{
    int p1;
    int p2;
} edge_t;

my_error_t edge_read(FILE *fin, edge_t &edge);

my_error_t edge_write(FILE *fin, const edge_t &edge);

#endif //EDGE_H
