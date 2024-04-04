#include "edges.h"

static my_error_t edges_array_allocate(edge_t **array, const int size)
{
    my_error_t rc = SUCCESS;
    if (!array)
        rc = NULLPTR_ERROR;
    else if (size < 0)
        rc = EDGES_SIZE_ERROR;
    else
    {
        auto *tmp_array = (edge_t *) malloc(size * sizeof(edge_t));
        if (tmp_array)
            *array = tmp_array;
        else
            rc = MEMORY_ERROR;
    }
    return rc;
}

my_error_t edges_allocate(edges_t **edges) {
    my_error_t rc = SUCCESS;
    if (edges) {
        auto *tmp_edges = (edges_t *) malloc(sizeof(edges_t));
        if (tmp_edges)
            *edges = tmp_edges;
        else
            rc = MEMORY_ERROR;
    }
    else
        rc = NULLPTR_ERROR;
    return rc;
}

static my_error_t edges_array_free(edge_t **array) {
    my_error_t rc = SUCCESS;
    if (!array)
        rc = NULLPTR_ERROR;
    else if (*array)
        free(*array);
    return rc;
}

my_error_t edges_free(edges_t **edges) {
    my_error_t rc;
    if (edges) {
        rc = edges_array_free(&(*edges)->array);
        if (rc == SUCCESS)
            free(*edges);
    }
    else
        rc = NULLPTR_ERROR;
    return rc;
}

my_error_t edges_initialize(edges_t &edges)
{
    edges.array = nullptr;
    edges.size = 0;
    return SUCCESS;
}


my_error_t edges_size_read(FILE *fin, int &size)
{
    my_error_t rc = SUCCESS;
    if (fin == nullptr)
        rc = FILE_OPEN_ERROR;
    else if (fscanf(fin, "%d", &size) != 1)
        rc = FILE_READ_ERROR;
    else if (size <= 0)
        rc = EDGES_SIZE_ERROR;
    return rc;
}

my_error_t edges_array_read(FILE *fin, edge_t *array, const int size)
{
    my_error_t rc = SUCCESS;
    if (fin == nullptr)
        rc = FILE_OPEN_ERROR;
    else if (array == nullptr)
        rc = MEMORY_ERROR;
    else if (size <= 0)
        rc = EDGES_SIZE_ERROR;
    else
        for (int i = 0; rc == SUCCESS && i < size; i++)
            rc = edge_read(fin, array[i]);
    return rc;
}

my_error_t edges_read(FILE *fin, edges_t &edges)
{
    my_error_t rc;
    if (fin)
    {
        rc = edges_size_read(fin, edges.size);
        if (rc == SUCCESS)
        {
            rc = edges_array_allocate(&edges.array, edges.size);
            if (rc == SUCCESS)
            {
                rc = edges_array_read(fin, edges.array, edges.size);
                if (rc != SUCCESS)
                    edges_array_free(&edges.array);
            }
        }
    }
    else
        rc = FILE_OPEN_ERROR;
    return rc;
}


static my_error_t edges_size_write(FILE *fout, const int size) {
    my_error_t rc = SUCCESS;
    if (fout == nullptr)
        rc = NULLPTR_ERROR;
    else if (size < 0)
        rc = EDGES_SIZE_ERROR;
    else if (0 > fprintf(fout, "%d\n", size))
        rc = FILE_WRITE_ERROR;
    return rc;
}

static my_error_t edges_array_write(FILE *fout, const edge_t *array, const int size) {
    my_error_t rc = SUCCESS;
    if (fout == nullptr)
        rc = NULLPTR_ERROR;
    else if (array == nullptr)
        rc = NO_DATA_ERROR;
    else if (size < 0)
        rc = EDGES_SIZE_ERROR;
    else
        for (int i = 0; rc == SUCCESS && i < size; i++)
            rc = edge_write(fout, array[i]);
    return rc;
}

my_error_t edges_write(FILE *fout, const edges_t &edges)
{
    my_error_t rc;
    if (fout)
    {
        rc = edges_size_write(fout, edges.size);
        if (rc == SUCCESS)
            rc = edges_array_write(fout, edges.array, edges.size);
    }
    else
        rc = NULLPTR_ERROR;
    return rc;
}


my_error_t edges_get(const edges_t &edges, edge_t **edge, const int index)
{
    my_error_t rc = SUCCESS;
    if (edges.array && edges.size > 0)
        *edge = &edges.array[index];
    else
        rc = NO_DATA_ERROR;
    return rc;
}
