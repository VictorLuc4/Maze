/*
** Made by Nathan Anné
*/

#include "map.h"

int	my_strlen(char *str)
{
  int	i;

  i = -1;
  while (str[++i]);
  return (i);
}
