#include "fdf.h"

float     max_len(float x, float y)
{
    if (fabs(x) > fabs(y))
        return (fabs(x));
    return (fabs(y));
}

void    get_distance(t_dot *dot)
{
    dot->distance = max_len(dot->screen_ex - dot->screen_bx, dot->screen_ey - dot->screen_by);
    dot->step_x = (dot->screen_ex - dot->screen_bx) / dot->distance;
    dot->step_y = (dot->screen_ey - dot->screen_by) / dot->distance;
}

void    apply_angle(t_info *info, t_dot *dot)
{
    dot->screen_bx = info->offset_x + (sin(info->angleH * M_PI / 180) * dot->screen_bx);
    dot->screen_by = info->offset_y + (cos(info->angleV * M_PI / 180) * dot->screen_by);
    dot->screen_ex = info->offset_x + (sin(info->angleH * M_PI / 180) * dot->screen_ex);
    dot->screen_ey = info->offset_y + (cos(info->angleV * M_PI / 180) * dot->screen_ey);
}

void    get_render_info(t_info *info, t_dot *dot, char axis)
{
    dot->screen_bx = (dot->flag_x - dot->flag_y) * info->tile_size * info->mode;
    dot->screen_by = (dot->flag_x + dot->flag_y) * info->tile_size - \
                        (info->tab[dot->flag_y][dot->flag_x] * \
                        info->z_scale);
    if (axis == 'H')
    {
        dot->screen_ex = (dot->flag_x + 1 - dot->flag_y) * info->tile_size * info->mode;
        dot->screen_ey = (dot->flag_x + 1 + dot->flag_y) * info->tile_size - \
                            (info->tab[dot->flag_y][dot->flag_x + 1] * \
                            info->z_scale);
    }
    else if (axis == 'V')
    {
        dot->screen_ex = (dot->flag_x - dot->flag_y - 1) * info->tile_size * info->mode;
        dot->screen_ey = (dot->flag_x + dot->flag_y + 1) * info->tile_size - \
                            (info->tab[dot->flag_y + 1][dot->flag_x] * \
                            info->z_scale);
    }
    apply_angle(info, dot);
}
