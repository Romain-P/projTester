/*
** main.c for  in /home/romain.pillot/bin
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Thu Nov 24 11:14:29 2016 romain pillot
** Last update Wed Jun 21 11:39:05 2017 romain pillot
*/

#include <stdio.h>
#include <stdlib.h>
#include "tester.h"
#include "array.h"

int		main(int ac, char **args)
{
  t_node	*node;

  (void) ac;
  node = parse_tree(args[1]);
  tree(node, 0);
  return (_EXIT_SUCCESS);
}
