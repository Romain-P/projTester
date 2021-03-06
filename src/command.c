/*
** command.c for  in /home/romain.pillot/projects/ADM_projTester_2016/src
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Wed Jun 21 12:03:15 2017 romain pillot
** Last update Thu Jun 22 07:51:58 2017 romain pillot
*/

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "tester.h"
#include "util.h"

static bool	in_directory(char const *cmd)
{
  struct	stat rights;

  return (file_gettype(cmd) != DIRECTORY && !stat(cmd, &rights) &&
	  access(cmd, F_OK) != -1 && access(cmd, X_OK) != -1 &&
	  rights.st_mode && (rights.st_mode & S_IEXEC));
}

char	*cmd_getpath(char const *cmd)
{
  char	*paths;
  int	i;
  int	j;
  char	*path;

  if (str_contains(cmd, (char[]){FILE_SEPARATOR, 0}) || in_directory(cmd))
    return (file_gettype(cmd) != DIRECTORY
	    && file_gettype(cmd) != UNDEFINED ? strdup(cmd) : NULL);
  if (!(paths = getenv("PATH")))
    return (NULL);
  i = -1;
  j = 0;
  while (paths[++i])
    if (paths[i] == ':' || !paths[i + 1])
      {
	paths[i] = 0;
	if (!(path = malloc(sizeof(char) * (strlen(paths + j) + strlen(cmd) + 2))))
	  return (NULL);
	strcat(strcat(strcat(path, paths + j), "/"), cmd);
	if (access(path, F_OK) != -1 && access(path, X_OK) != -1 &&
	    file_gettype(path) != DIRECTORY)
	  return (path);
	free(path);
	j = i + 1;
      }
  return (NULL);
}
