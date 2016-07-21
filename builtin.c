/*
** builtin.c for  in /home/henry_g/rendu_2/PSU/PSU_2015_minishell1
**
** Made by Clément Henry
** Login   <henry_g@epitech.net>
**
** Started on  Sat Feb 13 01:21:39 2016 Clément Henry
** Last update Sun Feb 14 21:00:58 2016 Clément Henry
*/

#include "minishell.h"

int	check_builtin(char **arg)
{
  int	indic;

  if (str_check(arg[0], "env") == 1)
    indic = 0;
  if (str_check(arg[0], "setenv") == 1)
    indic = 1;
  if (str_check(arg[0], "unsetenv") == 1)
    indic = 2;
  if (str_check(arg[0], "cd") == 1)
    indic = 3;
  return (indic);
}

void	builtin(t_shell *shell, t_array *array)
{
  void	(*tab[4])(t_shell *, t_array *);

  tab[0] = &my_env;
  tab[1] = &my_setenv;
  tab[2] = &my_unsetenv;
  tab[3] = &my_cd;
  tab[check_builtin(shell->buffer)](shell, array);
}
