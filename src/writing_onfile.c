/*
** Made by Victor Lucas
*/

#include "map.h"

char		**writing_onfile(t_map m, int y, int x)
{
  mode_t	mode;
  int		fd;
  int		i;

  i = -1;
  mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH;
  if ((fd = open("./maze.txt", O_RDONLY, mode)) != -1)
    remove("./maze.txt");
  fd = open("./maze.txt", O_RDWR | O_CREAT, mode);
  while (++i < y)
    {
      write(fd, m.map[i], x);
      write(fd, "\n", 1);
    }
  return (m.map);
}
