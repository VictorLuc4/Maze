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

typedef struct	s_my_map
{
  char		**map;
  int		a;
  int		b;
}		            t_my_map;

typedef struct	s_my_way
{
  int		up;
  int		down;
  int		left;
  int		right;
}		            t_my_way;

char		**generate_map(int, int, t_my_map);
char		**choose_mapformat(char**, t_my_map, int, int);
char		**writing_onfile(t_my_map, int, int);

void		print_map(t_my_map, int, int);

char		**generate_imperfect(t_my_map, int, int);
char		**generate_perfect(t_my_map, int, int);

char		**map_modif(t_my_map, int, int);
char		**map_edit(t_my_map, int, int);

int		  my_strlen(char*);

#endif
