/*
** str_to_tab.c for str_to_tab in /home/danilo_d/rendu/MUL_2014_fdf
** 
** Made by Danilov Dimitri
** Login   <danilo_d@epitech.net>
** 
** Started on  Sun Dec  7 11:45:34 2014 Danilov Dimitri
** Last update Sun Dec  7 19:21:43 2014 Dimitri Danilov
*/

#include "my.h"
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int             nbr_int(char *str)
{
  int   nbr_int;
  int   j;

  j = 0;
  nbr_int = 0;
  while (str[j] != '\0')
    {
      if (str[j] == ' ')
        {
          while (str[j] == ' ')
            j++;
          nbr_int++;
	}
      j = j + 1;
    }
  return (nbr_int);
}

void		size_of_tab(t_tools *tool, t_coord1 *coord, t_init *init, char *path)
{
  int		ok;
  int		fd;
  char		*line;

  ok = 0;
  tool->size_x = 0;
  tool->size_y = 0;
  if ((fd = open(path, O_RDONLY)) == (-1))
    exit(1);
  while ((line = get_next_line(fd)))
    {
      if (ok == 1 && tool->size_x != nbr_int(line))
	{
	  my_putstr("Line are not all in the same size. Exiting....\n");
	  exit(1);
	}
      tool->size_x = nbr_int(line);
      ok = 1;
      tool->size_y++;
      free(line);
    }
  close(fd);
  if (tool->size_x != tool->size_y - 1)
    exit(1);
}

int             zero(int *a, int *j, int *x)
{
  *a = 0;
  *j = 0;
  *x = 0;
  return (0);
}

void            str_to_tab(t_tools *tool, t_coord1 *coord, char *path, t_init *init)
{
  if ((init->fd = open(path, O_RDONLY)) == (-1))
    exit(1);
  while ((init->line = get_next_line(init->fd)))
    {
      init->size = nbr_int(init->line);
      zero(&init->a, &init->j , &init->x);
      while (init->a <= init->size)
        {
          tool->tab[init->i][init->a] = -(my_getnbr(init->line, &init->j));
	  coord->x[init->i][init->a] = (C1 * (init->i + 1)) - (C2 * init->a) + init->x;
          coord->y[init->i][init->a] = (tool->tab[init->i][init->a] + 
					((C1 / 2) * init->i) +
					((C2 / 2)* init->a)) + init->y;
          init->a++;
          init->x = init->x + (750 / init->size - 5);
        }
      init->y = init->y + (750 / init->size - 5);
      free(init->line);
      init->i++;
    }
  close(init->fd);
  tool->taille_i = init->i;
  tool->taille_j = init->a;
}
