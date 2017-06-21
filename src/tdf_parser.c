/*
** tdf_parser.c for  in /home/romain.pillot/projects/ADM_projTester_2016/src
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Wed Jun 21 15:12:03 2017 romain pillot
** Last update Wed Jun 21 15:29:39 2017 romain pillot
*/

#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include "tester.h"
#include "util.h"

void		parse_tdf(t_node *node)
{
  int		fd;
  char		*str;
  t_type	type;

  if ((fd = open(node->label, O_RDONLY)) == -1 ||
      !(node->test = malloc(sizeof(t_test))))
    return ;
  node->test->args = NULL;
  node->test->result = NULL;
  node->test->input = NULL;
  while ((str = scan_line(fd)))
    {
      if (str_starts(str, LINE_ARGS))
	node->test->args = str_split(strdup(str + strlen(LINE_ARGS)), ' ');
      else if (str_starts(str, LINE_INPUT))
	node->test->input = strdup(str + strlen(LINE_INPUT));
      else if (str_starts(str, LINE_RESULT))
	node->test->result = strdup(str + strlen(LINE_RESULT));
      FREE(str);
    }
  if ((type = file_gettype(node->test->input)) != OTHER_FILE &&
      type != BINARY)
    FREE(node->test->input);
}
