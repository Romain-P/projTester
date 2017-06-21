/*
** tester.h for  in /home/romain.pillot/projects/ADM_projTester_2016/inc
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Wed Jun 21 06:59:37 2017 romain pillot
** Last update Wed Jun 21 18:09:20 2017 romain pillot
*/

#ifndef TESTER_H_
# define TESTER_H_

# define _EXIT_FAILURE	(84)
# define _EXIT_SUCCESS	(0)

# define FILE_SEPARATOR	('/')
# define BINARY_EXT	(".tdf")

# define LINE_ARGS	("ARGS:")
# define LINE_INPUT	("INPUT:")
# define LINE_RESULT	("RES:")

# define CHANNEL_READ	(0)
# define CHANNEL_WRITE	(1)

# include "array.h"

typedef enum	e_type
{
  UNDEFINED,
  BINARY,
  OTHER_FILE,
  DIRECTORY
}		t_type;

typedef struct	s_test
{
  char		*result;
  char		**args;
  char		*input;
}		t_test;

typedef struct	s_node
{
  char		*label;
  t_type	type;
  t_test	*test;
  t_array	*nodes;
}		t_node;

typedef struct	s_option
{
  char		*directory;
  char		*binary;
  char		*output;
}		t_option;

void		execute(t_node *node, t_option *option);

t_node		*parse_tree(char const *str);

t_option	*parse_options(int ac, char **args);

void		parse_tdf(t_node *node);

char		*file_getname(char const *path);

char		*path_concat(char const *a, char const *b);

t_type		file_gettype(char const *file);

char		*cmd_getpath(char const *cmd);

#endif /** !TESTER_H_ **/
