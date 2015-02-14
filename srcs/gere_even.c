/*
** gere_even.c for gere_even in /home/danilo_d/MUL_2014_fdf/srcs
** 
** Made by Dimitri Danilov
** Login   <danilo_d@epitech.net>
** 
** Started on  Sun Dec  7 18:25:55 2014 Dimitri Danilov
** Last update Sun Dec  7 20:08:43 2014 Danilov Dimitri
*/

#include "my.h"
#include "mlx.h"
#include <unistd.h>
#include <stdlib.h>

int             gere_key(int key , void *param)
{
  if (key == 65307)
    exit(0);
  return (0);
}

int             gere_expose(t_tools *tool)
{
  mlx_put_image_to_window(tool->ml.ptr, tool->ml.window, tool->mg.img, 0, 0);
  return (0);
}
