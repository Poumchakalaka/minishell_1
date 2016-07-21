/*
** env.c for  in /home/henry_g/rendu_2/PSU/PSU_2015_minishell1
**
** Made by Clément Henry
** Login   <henry_g@epitech.net>
**
** Started on  Mon Feb  8 01:46:15 2016 Clément Henry
** Last update Sun Feb 14 21:36:41 2016 Clément Henry
*/

#include "minishell.h"

int	str_check(char *s1, char *s2)
{
  int	i;

  i = 0;
  if (my_strlen(s1) != my_strlen(s2))
    return (0);
  while (s1[i] && s2[i])
    if (s1[i] != s2[i++])
      return (0);
  return (1);
}

int	check_arg(char *str)
{
  if (str[0] == '/' || str[0] == '.')
    return (1);
  else if ((str_check(str, "cd") == 1))
    return (2);
  else if ((str_check(str, "setenv")) == 1)
    return (2);
  else if ((str_check(str, "unsetenv")) == 1)
    return (2);
  else if ((str_check(str, "env")) == 1)
    return (2);
  else
    return (0);
}

void	my_error_2(char *str)
{
  my_error(str);
  my_putstr(" :  Command not found\n");
}

char	*my_special(t_shell *shell, t_array *array, char **env)
{
  if (access(shell->buffer[0], F_OK | X_OK) == 0)
    do_it(shell->buffer[0], shell->buffer, env);
}

char	*my_open(t_shell *shell, t_array *array, char **env, int *indicateur)
{
  int	i;
  char	*path;

  i = -1;
  if (all_check(shell, array, env) == 0)
    {
      if (shell->buffer[0][0] == '.')
	my_exec(shell, array, env);
      else
	{
	  while (shell->tab_path[++i] != NULL)
	    {
	      path = my_strcat(shell->tab_path[i], "/");
	      if ((access(
my_strcat(shell->tab_path[i], shell->buffer[0]), F_OK) == 0))
		{
		  *indicateur = *indicateur + 1;
		  return (path);
		}
	    }
	  my_error_2(shell->buffer[0]);
	}
    }
}
