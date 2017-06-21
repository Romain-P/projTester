/*
** tester.h for  in /home/romain.pillot/projects/ADM_projTester_2016/inc
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Wed Jun 21 06:59:37 2017 romain pillot
** Last update Wed Jun 21 11:31:08 2017 romain pillot
*/

#ifndef TESTER_H_
# define TESTER_H_

# define _EXIT_FAILURE	(84)
# define _EXIT_SUCCESS	(0)

# define FILE_SEPARATOR	('/')
# define BINARY_EXT	(".tdf")
# include "array.h"

typedef enum	e_type
{
  UNDEFINED,
  BINARY,
  DIRECTORY
}		t_type;

typedef struct	s_node
{
  char		*label;
  t_type	type;
  t_array	*nodes;
}		t_node;

t_node		*parse_tree(char const *str);

char		*file_getname(char const *path);

#endif /** !TESTER_H_ **/
