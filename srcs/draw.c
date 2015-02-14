/*
** draw.c for dra in /home/danilo_d/rendu/MUL_2014_fdf
** 
** Made by Danilov Dimitri
** Login   <danilo_d@epitech.net>
** 
** Started on  Sat Dec  6 16:14:11 2014 Danilov Dimitri
** Last update Thu Feb 12 14:28:34 2015 danilov dimitri
*/

#include "my.h"
#include "mlx.h"
#include <stdlib.h>

int	draw(t_tools *tool, t_coord1 *coord, t_position *pos, int direction)
{
  t_draw *drw;

  drw = malloc(sizeof *drw);
  drw->color =0xFFFFFFFF;
  if (direction == 1)
    {
      drw->x2 = 200 + coord->x[pos->i][pos->j + 1];
      drw->y2 = 100 + coord->y[pos->i][pos->j + 1];
      drw->x1 = 200 + coord->x[pos->i][pos->j];
      drw->y1 = 100 + coord->y[pos->i][pos->j];
    }
  if (direction == 2)
    {
      drw->x2 = 200 + coord->x[pos->i + 1][pos->j];
      drw->y2 = 100 + coord->y[pos->i + 1][pos->j];
      drw->x1 = 200 + coord->x[pos->i][pos->j];
      drw->y1 = 100 + coord->y[pos->i][pos->j];
    }
  drw->Dx = my_abs(drw->x2 - drw->x1);
  drw->Dy = my_abs(drw->y2 - drw->y1);
  draw2(drw, tool);
  return (0);
}

int	draw2(t_draw *drw, t_tools *tool)
{
  if (drw->x1 < drw->x2)
    drw->xincr = 1;
  else
    drw->xincr = -1;
  if (drw->y1 < drw->y2)
    drw->yincr = 1;
  else
    drw->yincr = -1;
  drw->x = drw->x1;
  drw->y = drw->y1;
  drw->i = 0;
  if (drw->Dx > drw->Dy)
    draw3(drw, tool);
  else
    draw4(drw, tool);
  return (0);
}
int     draw3(t_draw *drw, t_tools *tool)
{
  drw->error = drw->Dx / 2;
  while (drw->i < drw->Dx)
    {
      drw->x += drw->xincr;
      drw->error += drw->Dy;
      if (drw->error > drw->Dx)
	{
	  drw->error -= drw->Dx;
	  drw->y += drw->yincr;
	}
      drw->i++;
      if (drw->x > 0 && drw->x < 1500 && drw->y > 0 && drw->y < 1000)
	tool->mg.data = pixel_put_to_image(drw->x, drw->y, tool->mg);
    }
  return (0);
}

int     draw4(t_draw *drw, t_tools *tool)
{
  drw->error = drw->Dy / 2;
  while (drw->i < drw->Dy)
    {
      drw->y += drw->yincr;
      drw->error += drw->Dx;
      if (drw->error > drw->Dy)
	{
	  drw->error -= drw->Dy;
	  drw->x += drw->xincr;
	}
      if (drw->x > 0 &&drw->x < 1000 && drw->y> 0 && drw->y <1000)
	tool->mg.data = pixel_put_to_image(drw->x, drw->y, tool->mg);
      drw->i++;
    }
  return (0);
}
