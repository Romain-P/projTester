/*
** execute.c for  in /home/romain.pillot/projects/ADM_projTester_2016/src
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Wed Jun 21 15:36:42 2017 romain pillot
** Last update Wed Jun 21 17:02:55 2017 romain pillot
*/

#include <stdio.h>
#include <string.h>
#include "tester.h"
#include "util.h"

static void	apply_tests(t_node *root,
		    t_option *opt,
		    char *(*applier)(t_test *test, t_option *opt))
{
  char		**path;
  int		len;
  int		i;

  path = str_split(strdup(root->label), FILE_SEPARATOR);
  len = tab_length(path);
  i = 0;
  if (root->type == BINARY && root->test && root->test->args)
    {
      while (++i < len)
	{
	  if (i + 1 == len)
	    path[i][strlen(path[i]) - strlen(BINARY_EXT)] = 0;
	  printf(i + 1 == len ? "%s: " : "[%s] ", path[i]);
	}
      printf("%s\n", applier(root->test, opt));
    }
  i = -1;
  while (++i < root->nodes->length)
    apply_tests((t_node *) root->nodes->values[i], opt, applier);
  TAB_FREE(path);
}


static char	*collect_output(t_test *node, t_option *option)
{
  return ("OK");
}
void	execute(t_node *node, t_option *option)
{
  apply_tests(node, option, &collect_output);
}
