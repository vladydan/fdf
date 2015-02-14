/*
** fdf.c for fdf in /home/danilo_d/rendu/MUL_2014_fdf
** 
** Made by Danilov Dimitri
** Login   <danilo_d@epitech.net>
** 
** Started on  Sat Dec  6 18:52:46 2014 Danilov Dimitri
** Last update Sat Dec  6 20:32:48 2014 Danilov Dimitri
*/

#include "my.h"

int	fdf(t_coord1 *coord, t_position pos, t_init *init, t_tools *tool)
{
  while (pos.i != tool->taille_i)
    {
      pos.j = 0;
      while (pos.j != tool->taille_j - 1) 
	{
	  draw(tool, coord, &pos, 1);
	  pos.j++;
	}
      pos.i++;
    }
  pos.i = 0;
  while (pos.i != tool->taille_i - 1)
    {
      pos.j = 0;
      while (pos.j != tool->taille_j)
        {
          draw(tool, coord, &pos, 2);
	  pos.j++;
        }
      pos.i++;
    }
  return (0);
}
