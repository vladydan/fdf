#ifndef MY_H_
# define MY_H_
# define C1 0.9
# define C2 0.5

typedef struct	 s_mlx
{
  void		 *ptr;
  void		 *window;
}		 t_mlx;

typedef struct	s_image
{
  char		*data;
  void		*img;
  int		bpp;
  int		sizeline;
  int		endian;
}		t_image;

typedef struct  s_coord1
{
  int	        **x;
  int           **y;
}               t_coord1;

typedef struct  s_position
{
  int           i;
  int           j;
}		t_position;

typedef struct	c_draw
{
  int		x;
  int		y;
  int		x2;
  int		y2;
  int		Dx;
  int		Dy;
  int		xincr;
  int		yincr;
  int		error;
  int		i;
  int		color;
  int		x1;
  int		y1;
}		t_draw;

typedef struct	s_tools
{
  int		size_x;
  int		size_y;
  t_mlx		ml;
  t_image	mg;
  int		**tab;
  int		taille_i;
  int		taille_j;
  int		i;
}		t_tools;

typedef struct	s_init
{
  int		fd;
  int		i;
  int		j;
  char		*line;
  int		a;
  int		x;
  int		y;
  int		size;
}		t_init;

int		draw(t_tools *tool, t_coord1 *coord, t_position *pos, int direction);
int		my_getnbr(char *str, int *i);
int		my_abs(int nbr);
int		draw2(t_draw *drw, t_tools *tool);
int	        draw3(t_draw *drw, t_tools *tool);
int		draw4(t_draw *drw, t_tools *tool);
int		fdf(t_coord1 *coord, t_position pos, t_init *init, t_tools *tool);
void		*xmalloc(int nbr);
void            str_to_tab(t_tools *tool, t_coord1 *coord, char *path, t_init *init);
int             zero(int *a, int *j, int *x);
int		my_putchar(char c);
int		my_putstr(char *str);
void            size_of_tab(t_tools *tool, t_coord1 *coord, t_init *init, char *path);
char		*pixel_put_to_image(int x , int y, t_image img);
int             gere_key(int key , void *param);
int             gere_expose(t_tools *tool);
#endif  /* !MY_H_ */
