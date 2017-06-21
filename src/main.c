/*
** main.c for  in /home/romain.pillot/bin
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Thu Nov 24 11:14:29 2016 romain pillot
** Last update Wed Jun 21 12:19:31 2017 romain pillot
*/

#include <stdio.h>
#include <stdlib.h>
#include "tester.h"
#include "array.h"

int		main(int ac, char **args)
{
  t_node	*node;
  t_option	*option;

  if (!(option = parse_options(ac, args)))
    return (_EXIT_FAILURE);
  node = parse_tree(args[1]);
  return (_EXIT_SUCCESS);
}
