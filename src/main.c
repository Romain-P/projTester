/*
** main.c for  in /home/romain.pillot/bin
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Thu Nov 24 11:14:29 2016 romain pillot
** Last update Wed Jun 21 10:37:25 2017 romain pillot
*/

#include <stdio.h>
#include <stdlib.h>
#include "tester.h"
#include "array.h"

void		tree(t_node *node, int state)
{
  for (int i = 0; i < state; i++)
    printf("-");
  printf("%s\n", node->label);
  for (int i = 0; i < node->nodes->length; i++)
    tree((t_node *) node->nodes->values[i], state + 5);
}

int		main(int ac, char **args)
{
  t_node	*node;

  (void) ac;
  node = parse_tree(args[1]);
  tree(node, 0);
  return (_EXIT_SUCCESS);
}
