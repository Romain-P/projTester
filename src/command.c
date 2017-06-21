/*
** command.c for  in /home/romain.pillot/projects/ADM_projTester_2016/src
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Wed Jun 21 12:03:15 2017 romain pillot
** Last update Wed Jun 21 19:43:35 2017 romain pillot
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

static bool	in_directory(char const *cmd)
{
  struct	stat rights;

  return (!stat(cmd, &rights) &&
	  access(cmd, F_OK) != -1 && access(cmd, X_OK) != -1 &&
	  rights.st_mode && (rights.st_mode & S_IEXEC));
}

char	*cmd_getpath(char const *cmd)
{
  char	*paths;
  int	i;
  int	j;
  char	*path;

  if (in_directory(cmd))
    return (strdup(cmd));
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
	if (access(path, F_OK) != -1 && access(path, X_OK) != -1)
	  return (path);
	free(path);
	j = i + 1;
      }
  return (NULL);
}
