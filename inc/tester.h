/*
** tester.h for  in /home/romain.pillot/projects/ADM_projTester_2016/inc
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Wed Jun 21 06:59:37 2017 romain pillot
** Last update Wed Jun 21 08:34:13 2017 romain pillot
*/

#ifndef TESTER_H_
# define TESTER_H_

# define _EXIT_FAILURE	(84)
# define _EXIT_SUCCESS	(0)

typedef enum	e_type
{
  UNDEFINED,
  BINARY,
  FOLDER,
  ARRAY
}		t_type;

typedef struct	s_node
{
  char		*label;
  t_type	type;
  t_array	*nodes;
}		t_node;

#endif /** !TESTER_H_ **/
