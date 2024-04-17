#include "edges.h"

static my_error_t edges_array_allocate(edge_t **array, const int size)
{
    if (!array)
        return NULLPTR_ERROR;
    if (size < 0)
        return EDGES_SIZE_ERROR;

    auto *tmp_array = (edge_t *) malloc(size * sizeof(edge_t));
    if (!tmp_array)
        return MEMORY_ERROR;

    *array = tmp_array;

    return SUCCESS;
}

my_error_t edges_allocate(edges_t **edges) {
    if (!edges)
        return NULLPTR_ERROR;

    auto *tmp_edges = (edges_t *) malloc(sizeof(edges_t));
    if (!tmp_edges)
        return MEMORY_ERROR;

    *edges = tmp_edges;

    return SUCCESS;
}

static my_error_t edges_array_free(edge_t **array) {
    if (!array)
        return NULLPTR_ERROR;

    if (*array)
    {
        free(*array);
        *array = nullptr;
    }

    return SUCCESS;
}

my_error_t edges_free(edges_t **edges) {
    if (!edges)
        return NULLPTR_ERROR;

    my_error_t rc = edges_array_free(&(*edges)->array);
    if (rc != SUCCESS)
        return rc;

    free(*edges);

    return rc;
}

my_error_t edges_initialize(edges_t &edges)
{
    edges.array = nullptr;
    edges.size = 0;
    return SUCCESS;
}


my_error_t edges_size_read(int &size, FILE *fin)
{
    if (!fin)
        return FILE_OPEN_ERROR;
    if (fscanf(fin, "%d", &size) != 1)
        return FILE_READ_ERROR;
    if (size <= 0)
        return EDGES_SIZE_ERROR;
    return SUCCESS;
}

my_error_t edges_array_read(edge_t *array, const int size, FILE *fin)
{
    if (!fin)
        return FILE_OPEN_ERROR;
    if (!array)
        return MEMORY_ERROR;
    if (size <= 0)
        return EDGES_SIZE_ERROR;

    my_error_t rc = SUCCESS;
    for (int i = 0; rc == SUCCESS && i < size; i++)
        rc = edge_read(array[i], fin);

    return rc;
}

my_error_t edges_read(edges_t &edges, FILE *fin)
{
    if (!fin)
        return NULLPTR_ERROR;

    my_error_t rc = edges_size_read(edges.size, fin);
    if (rc != SUCCESS)
        return rc;

    // todo maybe to hide allocation into reading
    // todo а может и вообще не стоит давать возможность выделения памяти без чтения...
    rc = edges_array_allocate(&edges.array, edges.size);
    if (rc != SUCCESS)
        return rc;

    rc = edges_array_read(edges.array, edges.size, fin);
    if (rc != SUCCESS)
        edges_array_free(&edges.array);

    return rc;
}


static my_error_t edges_size_write(const int size, FILE *fout) {
    if (!fout)
        return NULLPTR_ERROR;
    if (size < 0)
        return EDGES_SIZE_ERROR;
    if (0 > fprintf(fout, "%d\n", size))
        return FILE_WRITE_ERROR;
    return SUCCESS;
}

static my_error_t edges_array_write(const edge_t *array, const int size, FILE *fout) {
    if (!fout)
        return NULLPTR_ERROR;
    if (!array)
        return NO_DATA_ERROR;
    if (size < 0)
        return EDGES_SIZE_ERROR;

    my_error_t rc = SUCCESS;
    for (int i = 0; rc == SUCCESS && i < size; i++)
        rc = edge_write(array[i], fout);

    return rc;
}

my_error_t edges_write(const edges_t &edges, FILE *fout)
{
    if (!fout)
        return NULLPTR_ERROR;

    my_error_t rc = edges_size_write(edges.size, fout);
    if (rc == SUCCESS)
        rc = edges_array_write(edges.array, edges.size, fout);

    return rc;
}


my_error_t edges_get(const edges_t &edges, edge_t **edge, const int index)
{
    if (!edges.array || edges.size <= 0)
        return NO_DATA_ERROR;

    *edge = &edges.array[index];

    return SUCCESS;
}
