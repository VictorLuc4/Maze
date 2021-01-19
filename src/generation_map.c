/*
** Made by Victor Lucas
*/

#include "map.h"

char	**generate_map(int y, int x, t_map m)
{
  m.a = m.b = -1;
  if ((m.map = malloc(sizeof(char*) * (y + 1))) == NULL)
    return (NULL);
  while (++m.a < y)
    {
      if ((m.map[m.a] = malloc(x + 1)) == NULL)
	      return (NULL);
      while (++m.b < x)
	      (m.b % 2) == 0 && (m.a % 2) == 0 ?
	    m.map[m.a][m.b] = '*' : (m.map[m.a][m.b] = 'X');
      m.map[m.a][m.b] = 0;
      m.b = -1;
    }
  m.map[m.a] = NULL;
  return (m.map);
}

char	**generate_perfect(t_map m, int y, int x)
{
  int	i;
  int	j;
  int	save;

  save = j = (((x % 2) == 1) ? x - 1 : x - 2);
  i = (((y % 2) == 1) ? y - 1 : y - 2);
  while (i >= 0)
    {
      j = save;
      while (j >=  0)
      {
        if (j != 0 || i != 0)
          m.map = map_edit(m, i, j);
        j -= 2;
      }
      i -= 2;
    }
  m.map = map_modif(m, y, x);
  return (m.map);
}

char	**generate_imperfect(t_map m, int y, int x)
{
  int	floor;
  int	i;
  int	j;

  i = j = -1;
  floor = 0;
  m.map = generate_perfect(m, y, x);
  while (++i < y)
    {
      while (++j < x)
	      if (m.map[i][j] == 'X')
	        floor++;
      j = -1;
    }
  map_imperf(m, y, x, floor);
  return (m.map);
}
