/*
** main.c for main in /home/danilo_d/rendu/MUL_2014_fdf/srcs
** 
** Made by Dimitri Danilov
** Login   <danilo_d@epitech.net>
** 
** Started on  Sun Nov 16 14:27:29 2014 Dimitri Danilov
** Last update Sun Dec  7 21:55:28 2014 Dimitri Danilov
*/

#include <stdlib.h>
#include "mlx_int.h"
#include "mlx.h"
#include "my.h"
#include <stdio.h>

int		my_abs(int a)
{
  if (a < 0)
    a = a * -1;
  return (a);
}

int		initilization(t_tools *tool, t_coord1 *coord, t_position *pos, t_init *init)
{
  tool->tab = xmalloc(sizeof(*tool->tab) * tool->size_y + 10);
  coord->x = xmalloc(sizeof(*coord->x) * tool->size_y + 10);
  coord->y = xmalloc(sizeof(*coord->y) * tool->size_y + 10);
  tool->i = 0;
  while (tool->i < tool->size_y)
    {
      tool->tab[tool->i] = xmalloc(sizeof(**tool->tab) * tool->size_x + 10);
      coord->x[tool->i] = xmalloc(sizeof(**coord->x) * tool->size_x + 10);
      coord->y[tool->i] = xmalloc(sizeof(**coord->y) * tool->size_x + 10);
      tool->i++;
    }
  pos->i = 0;
  init->i = 0;
  init->y = 0;
  tool->mg.img = mlx_new_image(tool->ml.ptr, 1500, 1000); 
  tool->mg.data = mlx_get_data_addr(tool->mg.img, &tool->mg.bpp, 
			       &tool->mg.sizeline, &tool->mg.endian);
  return (0);
}

int		free_all(int **tab, t_coord1 *coord, t_init *init, t_tools *tool)
{
  int	i;

  i = 0;
  while (i != tool->size_y)
    {
      free(tab[i]);
      free(coord->x[i]);
      free(coord->y[i]);
      i++;
    }
  free(coord);
  free(tool);
  free(init);
  free(coord->x);
  free(coord->y);
  free(tab);
  return (0);
}

int		main(int argc, char **argv)
{
  t_coord1	*coord;
  t_position	pos;
  t_tools	*tool;
  t_init        *init;

  if (argc != 2)
    return (0);
  tool = xmalloc(sizeof *tool);
  coord = xmalloc(sizeof *coord);
  init = xmalloc(sizeof *init);
  size_of_tab(tool, coord, init, argv[1]);
  if ((tool->ml.ptr = mlx_init()) == NULL ||
      (tool->ml.window = mlx_new_window(tool->ml.ptr, 1500, 1000, "fdf")) == NULL)
    return (-1);
  initilization(tool , coord, &pos, init);
  str_to_tab(tool, coord, argv[1], init);
  fdf(coord, pos, init, tool);
  mlx_put_image_to_window(tool->ml.ptr, tool->ml.window, tool->mg.img, 0, 0);
  mlx_key_hook(tool->ml.window, &gere_key, &tool->ml);
  mlx_expose_hook(tool->ml.window, &gere_expose, tool);
  mlx_loop(tool->ml.ptr);
  free_all(tool->tab, coord, init, tool);
  return (0);
}
