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

my_error_t edge_read(edge_t &edge, FILE *fin);

my_error_t edge_write(const edge_t &edge, FILE *fout);

#endif //EDGE_H
