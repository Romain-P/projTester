/*
** requirement.c for  in /home/romain.pillot/projects/ADM_palindrome_2016
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** * sStarted on  Thu Jun 14 07:05:30 2017 romain pillot
** Last update Wed Jun 21 08:02:49 2017 romain pillot
*/

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>

char	*get_path(char const *cmd)
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

void	my_ps_synthesis()
{
  int	pid;
  char	*path;

  if (!(path = get_path("ps")) || (pid = fork()) == -1)
    {
      perror("fork");
      return ;
    }
  else if (pid)
    wait(&pid);
  else
    execv(path, (char *[]){"ps", NULL});
  if (path)
    free(path);
}
