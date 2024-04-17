#include "figure_draw.h"

point_t point_global_to_view(point_t point, const view_t &view)
{
    point.x += view.width / 2;
    point.y += view.height / 2;
    return point;
}

segment_t edge_to_segment(const view_t &view, const edge_t &edge, const points_t &points)
{
    segment_t segment;
    segment.p1 = point_global_to_view(points.array[edge.p1], view);
    segment.p2 = point_global_to_view(points.array[edge.p2], view);
    return segment;
}

my_error_t view_scene_clear(const view_t &view)
{
    if (!view.scene)
        return SCENE_ERROR;
    view.scene->clear();
    return SUCCESS;
}

my_error_t segment_draw(const view_t &view, const point_t &p1, const point_t &p2)
{
    if (!view.scene)
        return SCENE_ERROR;
    view.scene->addLine(p1.x, p1.y, p2.x, p2.y);
    return SUCCESS;
}

my_error_t segments_draw(const view_t &view, const points_t &points, const edges_t &edges)
{
    my_error_t rc = SUCCESS;
    if (view.scene)
    {
        edge_t *edge;
        segment_t segment;
        for (int i = 0; rc == SUCCESS && i < edges.size; i++)
        {
            rc = edges_get(edges, &edge, i);
            if (rc == SUCCESS)
            {
                segment = edge_to_segment(view, *edge, points);
                rc = segment_draw(view, segment.p1, segment.p2);
            }
        }
    }
    else
        rc = SCENE_ERROR;
    return rc;
}

my_error_t figure_draw(figure_t *figure, const view_t &view)
{
    if (!figure)
        return NULLPTR_ERROR;

    my_error_t rc = view_scene_clear(view);
    if (rc != SUCCESS)
        return rc;

    rc = segments_draw(view, *figure->points, *figure->edges);

    return rc;
}
