/*
** parser.c for  in /home/romain.pillot/projects/ADM_projTester_2016/src
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Wed Jun 21 08:35:03 2017 romain pillot
** Last update Thu Jun 22 07:10:55 2017 romain pillot
*/

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include "tester.h"
#include "util.h"

char	*path_concat(char const *a, char const *b)
{
  int	len;
  char	*new;

  len = strlen(a);
  new = strdup(a);
  if (a[len - 1] != FILE_SEPARATOR)
    new = str_concat(new, "/", true);
  return (str_concat(new, b, true));
}

static t_node	*node_create(char const *name, t_type type)
{
  t_node	*node;
  int		fd;

  if (!(node = malloc(sizeof(t_node))))
    return (NULL);
  node->label = strdup(name);
  node->test = NULL;
  node->type = type;
  node->nodes = array_create();
  parse_tdf(node);
  return (node);
}

t_type		file_gettype(char const *file)
{
  struct stat	infos;

  if (!file || stat(file, &infos))
    return (false);
  return (S_ISDIR(infos.st_mode) ? DIRECTORY :
	  S_ISREG(infos.st_mode) && str_ends(file, BINARY_EXT) ? BINARY :
	  S_ISREG(infos.st_mode) ? OTHER_FILE : UNDEFINED);
}

char	*file_getname(char const *path)
{
  int	i;
  int	j;

  i = -1;
  j = 0;
  while (path[++i])
    if (path[i] == FILE_SEPARATOR && path[i + 1])
      j = i;
  return (strdup(path + j + (!j ? 0 : 1)));
}

t_node		*parse_tree(char const *str)
{
  t_node	*node;
  struct dirent	**files;
  int		i;
  int		j;

  node = node_create(str, file_gettype(str));
  if (node->type != DIRECTORY)
    return (node);
  if ((i = scandir(str, &files, NULL, alphasort)) <= 0)
    return (node);
  j = -1;
  while (++j < i)
    if (!str_equals(files[j]->d_name, ".") &&
	!str_equals(files[j]->d_name, ".."))
      array_add(node->nodes, parse_tree(path_concat(str, files[j]->d_name)));
  return (node);
}
