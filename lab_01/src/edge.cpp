#include "edge.h"

my_error_t edge_read(FILE *fin, edge_t &edge)
{
    my_error_t rc = SUCCESS;
    if (fin == nullptr)
        rc = FILE_OPEN_ERROR;
    else if (fscanf(fin, "%d %d", &edge.p1, &edge.p2) != 2)
        rc = FILE_READ_ERROR;
    return rc;
}

my_error_t edge_write(FILE *fin, const edge_t &edge)
{
    int rc = fprintf(fin, "%d %d\n", edge.p1, edge.p2);
    if (0 > rc)
        return FILE_WRITE_ERROR;
    return SUCCESS;
}
