/*
** main.c for  in /home/romain.pillot/bin
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Thu Nov 24 11:14:29 2016 romain pillot
** Last update Wed Jun 21 16:50:42 2017 romain pillot
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "tester.h"
#include "array.h"
#include "util.h"

static void	show_dirs(t_node *node, int step)
{
  int		i;
  char		*file;

  i = -1;
  while (++i < step * 5)
    printf("-");
  file = file_getname(node->label);
  printf("%s", file);
  if (file[strlen(file) - 1] != FILE_SEPARATOR && node->type == DIRECTORY)
    printf("%c\n", FILE_SEPARATOR);
  else
    printf("\n");
  i = -1;
  while (++i < node->nodes->length)
    show_dirs((t_node *)node->nodes->values[i], step + 1);
}

int		main(int ac, char **args)
{
  t_node	*node;
  t_option	*option;

  if (!(option = parse_options(ac, args)))
    return (_EXIT_FAILURE);
  node = parse_tree(args[1]);
  if (!option->binary)
    show_dirs(node, 0);
  else
    execute(node, option);
  return (_EXIT_SUCCESS);
}
