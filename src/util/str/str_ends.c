/*
** str_ends.c for  in /home/romain.pillot/projects/ADM_projTester_2016/src/util/str
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Wed Jun 21 11:10:09 2017 romain pillot
** Last update Wed Jun 21 11:18:45 2017 romain pillot
*/

#include "util.h"

bool	str_ends(char const *str, char const *charset)
{
  int	len;

  if ((len = str_length(str) - str_length(charset)) < 0)
    return (false);
  return (str_equals(str + len, charset));
}
