/*
** Created by Victor Lucas
*/

#ifndef MY_H_
#define MY_H_

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>

#ifndef NORM
#define NORM	(m[p->y + 1] == NULL && m[p->y][p->x] == '*')
#endif

typedef struct	s_pos
{
  int		x;
  int		y;
}		t_pos;

char	**my_str_to_wordtab(char *);
char	**str_to_wordtab(char *);
char	**fill_end(char **);
char	**refresh_map(char **);
char	**change_map(char **);
char	**star(char **, int *, int *);
char	**two(char **, int *, int *);
char	**one(char **, int *, int *);
char	**middle_1(char **, int *, int *);
char	**middle_2(char **, int *, int *);
char	**middle_3(char **, int *, int *);
char	**middle_4(char **, int *, int *);
char	**solver_breadth(char **);
char	**check_pos(char **, int *, int *);
char	*get_next_line(const int);
int	count_line(char *);
int	my_l(char *);
int	len(char**);
int	check(char **, int , int );
int	my_printf(char *, ...);
int	is_finish(char **);
int	search_star(char **, t_pos *);
int	search_zero(char **, t_pos *);
int	nbr_word(char *);
void	print_map(char **);

/* breath */
char	**solver_breadth(char **map);

#endif
