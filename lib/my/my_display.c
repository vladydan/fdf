/*
** my_display.c for display in /home/danilo_d/rendu/MUL_2014_fdf
** 
** Made by Danilov Dimitri
** Login   <danilo_d@epitech.net>
** 
** Started on  Sun Dec  7 12:18:41 2014 Danilov Dimitri
** Last update Sun Dec  7 15:32:51 2014 Danilov Dimitri
*/

#include <unistd.h>
#include "my.h"


int	my_putchar(char c)
{
  write(1, &c, 1);
  return (0);
}

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i++;
    }
  return (0);
}

char	*pixel_put_to_image(int x , int y, t_image img)
{
  int	octet;
  int	i;

  octet = ((y * img.sizeline - img.sizeline) + (x * img.bpp / 8 ));
  i = octet - img.bpp / 8;
  while (i != octet)
    {
      img.data[i] = -1;
      i++;
    }
  return (img.data);
}
