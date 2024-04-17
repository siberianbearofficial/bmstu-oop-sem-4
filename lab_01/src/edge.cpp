#include "edge.h"

my_error_t edge_read(edge_t &edge, FILE *fin)
{
    if (!fin)
        return FILE_OPEN_ERROR;
    if (fscanf(fin, "%d %d", &edge.p1, &edge.p2) != 2)
        return FILE_READ_ERROR;
    return SUCCESS;
}

my_error_t edge_write(const edge_t &edge, FILE *fout)
{
    int rc = fprintf(fout, "%d %d\n", edge.p1, edge.p2);
    if (0 > rc)
        return FILE_WRITE_ERROR;
    return SUCCESS;
}
