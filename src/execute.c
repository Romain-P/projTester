/*
** execute.c for  in /home/romain.pillot/projects/ADM_projTester_2016/src
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Wed Jun 21 15:36:42 2017 romain pillot
** Last update Wed Jun 21 23:44:09 2017 romain pillot
*/

#include <stdio.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include "tester.h"
#include "util.h"

static void	apply_tests(t_node *root,
			    t_option *opt,
			    char *(*applier)(t_test *test, t_option *opt))
{
  char		**path;
  int		len;
  int		i;
  char		*output;

  path = str_split(strdup(root->label), FILE_SEPARATOR);
  len = tab_length(path);
  i = 0;
  if (root->type == BINARY && root->test && root->test->args &&
      (output = applier(root->test, opt)))
    {
      while (++i < len)
	{
	  if (i + 1 == len)
	    path[i][strlen(path[i]) - strlen(BINARY_EXT)] = 0;
	  printf(i + 1 == len ? "%s: " : "[%s] ", path[i]);
	}
      printf("%s\n", output);
    }
  i = -1;
  while (++i < root->nodes->length)
    apply_tests((t_node *) root->nodes->values[i], opt, applier);
  TAB_FREE(path);
}

static void	exec_child(int link[2], t_test *test, t_option *option)
{
  int		fd;
  t_array	*args;
  int		i;

  if (test->input && (fd = open(test->input, O_RDONLY)) != -1)
    dup2(fd, STDIN_FILENO);
  dup2(link[CHANNEL_WRITE], STDOUT_FILENO);
  close(link[CHANNEL_READ]);
  close(link[CHANNEL_WRITE]);
  args = array_create();
  array_add(args, strdup(option->binary));
  i = -1;
  while (test->args[++i])
    array_add(args, test->args[i]);
  execv(option->binary, (char **) args->values);
  _exit(_EXIT_FAILURE);
}

static char	*collect_output(t_test *test, t_option *option)
{
  int		pid;
  int		status;
  int		link[2];
  char		*str;
  char		*output;

  if (pipe(link) == -1 || (pid = fork()) == -1)
    return (NULL);
  else if (pid)
    {
      close(link[CHANNEL_WRITE]);
      output = NULL;
      while ((str = scan_line(link[CHANNEL_READ])))
	output = str_concat(output, str_concat(str, "\n", true), true);
      if (output)
	output[strlen(output) - 1] = 0;
      waitpid(pid, &status, 0);
      return (test->result ?
	      str_equals(output, test->result) ? "OK" : "KO" : output);
    }
  else
    exec_child(link, test, option);
  return (NULL);
}

void	execute(t_node *node, t_option *option)
{
  FILE	*file;
  int	hold;

  if (option->output &&
      (file = fopen(option->output, "a")))
    {
      setbuf(stdout, NULL);
      fflush(stdout);
      hold = dup(STDOUT_FILENO);
      dup2(fileno(file), STDOUT_FILENO);
    }
  apply_tests(node, option, &collect_output);
  if (option->output && file)
    {
      dup2(hold, STDOUT_FILENO);
      close(hold);
      fclose(file);
    }
}
