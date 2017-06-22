/*
** option.c for  in /home/romain.pillot/projects/ADM_projTester_2016/src
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Wed Jun 21 11:43:05 2017 romain pillot
** Last update Thu Jun 22 07:27:13 2017 romain pillot
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tester.h"
#include "util.h"

t_option	*parse_options(int ac, char **args)
{
  t_option	*option;

  option = NULL;
  if (ac < 2 || file_gettype(args[1]) != DIRECTORY ||
      !(option = malloc(sizeof(t_option))) ||
      (args[2] && !(option->binary = cmd_getpath(args[2]))))
    {
      FREE(option);
      fprintf(stderr, ac <= 2 ? "%s: expected a directory as argument.\n" :
	      "%s: invalid binary.\n", *args);
      return (NULL);
    }
  else if (!args[2])
    option->binary = NULL;
  option->directory = args[1];
  option->directory_name = file_getname(args[1]);
  if (option->directory_name[strlen(option->directory_name) - 1]
      == FILE_SEPARATOR)
    option->directory_name[strlen(option->directory_name) - 1] = 0;
  option->output = args[2] ? args[3] : NULL;
  return (option);
}
