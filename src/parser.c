/*
** parser.c for  in /home/romain.pillot/projects/ADM_projTester_2016/src
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Wed Jun 21 08:35:03 2017 romain pillot
** Last update Wed Jun 21 08:59:29 2017 romain pillot
*/

#include "tester.h"

t_node		*node_create(char *const name, t_type type)
{
  if (!(node = malloc(sizeof(t_node))))
    return (NULL);
  node->label = strdup(name);
  node->type = type;
  node->array = array_create();
  return (node);
}

t_node		*parse_tree(char const *str)
{
  t_node	*node;

  node = node_create(str, FOLDER);
}
