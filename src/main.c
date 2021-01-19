/*
** Made by Victor Lucas
*/

#include "map.h"

char	**choose_mapformat(char **av, t_map m, int y, int x)
{
  if (av[3] != NULL)
    {
      if (strcmp(av[3], "imperfect") == 0)
        m.map = generate_imperfect(m, y, x);
      else if (strcmp(av[3], "perfect") == 0)
	      m.map = generate_perfect(m, y, x);
      else
        return (NULL);
    }
  else if (av[3] == NULL)
    m.map = generate_imperfect(m, y, x);
  
  return (m.map);
}

void check_args(int ac, char **av, int *x, int *y)
{
  if (ac < 3)
    exit(84);
  if ((*x = atoi(av[1])) <= 1)
    exit(84);
  if ((*y = atoi(av[2])) <= 1)
    exit(84);
}

int		main(int ac, char **av)
{
  t_map	m;
  int		x;
  int		y;

  /* Checking error in arguments */
  check_args(ac, av, &x, &y);

  srand(time(NULL));
  /* Generate the base map */
  if ((m.map = generate_map(y, x, m)) == NULL)
    return (84);

  /* Apply modification upon perfect / imperfect */
  if ((m.map = choose_mapformat(av, m, y, x)) == NULL)
    return (84);
  
  /* Write the map to the file */
  if ((writing_onfile(m, y, x)) == NULL)
    return (84);
  
  /* Free what is needed */
  free(m.map);
  return (0);
}
