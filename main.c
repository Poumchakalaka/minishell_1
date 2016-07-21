/*
** main.c for  in /home/henry_g/rendu_2/PSU/PSU_2015_minishell1
**
** Made by Clément Henry
** Login   <henry_g@epitech.net>
**
** Started on  Sun Feb  7 17:28:38 2016 Clément Henry
** Last update Sun Feb 14 23:34:59 2016 Clément Henry
*/

#include "minishell.h"

int		main(int ac, char **av, char **env)
{
  t_array	array;
  char		*str;

  signal(SIGINT, &catch);
  if (env[0] == NULL)
    while (42)
      {
	my_putstr("$> ");
	str = get_next_line(0);
      }
  array.indice = get_indice(env);
  array.line = get_line(env);
  minishell(env, &array);
  return (0);
}
