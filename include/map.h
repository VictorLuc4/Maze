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

/* Create a map sized X (lenght) and Y (height) */
char		**generate_map(int, int, t_map);

/* Generate a map upon the perfect / imperfect choice */
char		**choose_mapformat(char**, t_map, int, int);

/* Writing the map to a maze.txt file (override it) */
char		**writing_onfile(t_map, int, int);

void		print_map(t_map, int, int);

/* Core imperfect generation function */
char		**generate_imperfect(t_map, int, int);
/* Core perfect generation function */
char		**generate_perfect(t_map, int, int);

/* Usefull functions to perfom modifications on the map */
char		**map_modif(t_map, int, int);
char		**map_edit(t_map, int, int);
char	  **map_imperf(t_map, int, int, int);

int		  my_strlen(char*);

#endif /* MAP_H_ */
