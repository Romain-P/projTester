/*
** command.c for  in /home/romain.pillot/projects/ADM_projTester_2016/src
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Wed Jun 21 12:03:15 2017 romain pillot
** Last update Wed Jun 21 12:05:16 2017 romain pillot
*/

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>
#include "tester.h"

char	*cmd_getpath(char const *cmd)
{
  char	*paths;
  int	i;
  int	j;
  char	*path;

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