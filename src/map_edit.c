/*
** Made by Victor Lucas
*/

#include "map.h"

char	**map_modif(t_my_map m, int y, int x)
{
  if ((y % 2) == 0 || (x % 2) == 0)
    {
      if ((y % 2) % 2 == 0 && (x % 2) == 0)
	{
	  m.map[y - 1][x - 1] = '*';
	  m.map[y - 1][x - 2] = '*';
	}
      else
	m.map[y - 1][x - 1] = '*';
    }
  return (m.map);
}

int	choose_ran2(t_my_way way)
{
  int	ran;

  ran = rand() % 4;
  if ((ran == 0 && way.up == 1)
      || (ran == 1 && way.right == 1)
      || (ran == 2 && way.left == 1)
      || (ran == 3 && way.down == 1))
    ran = choose_ran2(way);
  return (ran);
}

char	**map_edit(t_my_map m, int i, int j)
{
  t_my_way	way;
  int		ran;

  way.up = way.down = ran = 1;
  way.left = way.right = 1;
  if (i != 0 && m.map[i - 1][j] == 'X' && m.map[i - 2][j] >= 20)
    way.up = 0;
  if (m.map[i][j + 1] != '\0' && m.map[i][j + 2] != '\n'
      && (j + 2) < my_strlen(m.map[i]))
    if (m.map[i][j + 1] == 'X' && m.map[i][j + 2] >= 20)
      way.right = 0;
  if (j != 0 && m.map[i][j - 1] == 'X' && m.map[i][j - 2] >= 20)
    way.left = 0;
  if (i == 0 && j == 0 && m.map[i + 1][j] == 'X' && m.map[i + 2][j] >= 20)
    way.down = 0;
  ran = choose_ran2(way);
  if (ran == 0)
    m.map[i - 1][j] = '*';
  else if (ran == 1)
    m.map[i][j + 1] = '*';
  else if (ran == 2)
    m.map[i][j - 1] = '*';
  else
    m.map[i + 1][j] = '*';
  return (m.map);
}

char	**map_imperf(t_my_map m, int y, int x, int floor)
{
  int	i;
  int	j;
  int	perc;
  int	k;

  perc = floor * (0.02);
  perc = (perc <= 1) ? 2 : perc;
  perc = (floor == 1) ?	1 : perc;
  i = j = -1;
  k = 0;
  m.map[1][1] = '*';
  while (++i < y)
    {
      while (++j < x)
	if (m.map[i][j] == 'X')
	  if (++k == perc)
	    {
	      m.map[i][j] = '*';
	      k = 0;
	    }
      j = -1;
    }
  return (m.map);
}
