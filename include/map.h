/*
** Created by Victor Lucas
*/

#ifndef MAP_H_
#define MAP_H_

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <time.h>

typedef struct	s_map
{
  char		**map;
  int		a;
  int		b;
}		            t_map;

typedef struct	s_way
{
  int		up;
  int		down;
  int		left;
  int		right;
}		            t_way;

char		**generate_map(int, int, t_map);
char		**choose_mapformat(char**, t_map, int, int);
char		**writing_onfile(t_map, int, int);

void		print_map(t_map, int, int);

char		**generate_imperfect(t_map, int, int);
char		**generate_perfect(t_map, int, int);

char		**map_modif(t_map, int, int);
char		**map_edit(t_map, int, int);
char	  **map_imperf(t_map, int, int, int);

int		  my_strlen(char*);

#endif
