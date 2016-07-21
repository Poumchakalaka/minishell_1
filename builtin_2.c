/*
** builtin_2.c for  in /home/henry_g/rendu_2/PSU/PSU_2015_minishell1
**
** Made by Clément Henry
** Login   <henry_g@epitech.net>
**
** Started on  Sat Feb 13 01:38:01 2016 Clément Henry
** Last update Sun Feb 14 23:31:01 2016 Clément Henry
*/

#include "minishell.h"

void	cd_home(t_shell *shell, t_array *array)
{
  int	counter;
  int	i;
  char	*tmp;

  while (str_check(array->indice[i], "HOME") != 1)
    i++;
  tmp = array->line[i];
  chdir(tmp);
}

void	my_cd(t_shell *shell, t_array *array)
{
  shell->buffer[1] == NULL ? cd_home(shell, array) :
    chdir(shell->buffer[1]);
}

void	my_setenv(t_shell *shell, t_array *array)
{
  if (shell->buffer[1] == NULL)
    return ;
  else if (shell->buffer[2] == NULL)
    one_setenv(array, shell->buffer[1]);
  else if (shell->buffer[3] == NULL)
    two_setenv(array, shell);
}

void	my_unsetenv(t_shell *shell, t_array *array)
{
  return ;
}

void	my_env(t_shell *shell, t_array *array)
{
  int	i;

  if (shell->buffer[1] != NULL)
    return ;
  i = 0;
  while (array->indice[i] != NULL || array->line[i] != NULL)
    {
      my_putstr(array->indice[i]);
      if (array->indice[i][0] != '\0')
	my_putchar('=');
      my_putstr(array->line[i]);
      if (array->indice[i][0] != '\0')
	my_putchar('\n');
      i++;
    }
}
