/*
** set_env.c for  in /home/henry_g/rendu_2/PSU/PSU_2015_minishell1
**
** Made by Clément Henry
** Login   <henry_g@epitech.net>
**
** Started on  Sat Feb 13 02:39:27 2016 Clément Henry
** Last update Sun Feb 14 21:49:53 2016 Clément Henry
*/

#include "minishell.h"

char	**create_new(t_array *array, char *name, int c)
{
  char	**new;
  int	i;

  i = 0;
  if ((new = malloc((calc_env(array->indice) + 2) * sizeof(char *))) == NULL)
     return (NULL);
  while (array->indice[i] != NULL)
    {
      if (c == 1)
	new[i] = my_strdup(array->line[i]);
      else
	new[i] = my_strdup(array->indice[i]);
      i++;
    }
  if (c == 1)
    new[i] = my_strdup("\0");
  else
    new[i] = my_strdup(name);
  new[i + 1] = NULL;
  return (new);
}

void	one_setenv(t_array *array, char *what)
{
  int	i;
  int	counter;

  i = 0;
  counter = 1;
  while (array->indice[i] != NULL)
    {
      if (str_check(array->indice[i], what) == 1)
	{
	  counter--;
	  array->line[i] = my_strdup("\0");
	}
      i++;
    }
  if (counter == 1)
    {
      array->line = create_new(array, what, 1);
      array->indice = create_new(array, what, 0);
    }
}

void	two_setenv(t_array *array, t_shell *shell)
{
  int	i;
  int	counter;

  counter = 0;
  i = 0;
  while (array->indice[i] != NULL)
    {
      if (str_check(array->indice[i], shell->buffer[1]) == 1)
	{
	  array->line[i] = my_strdup(shell->buffer[2]);
	  counter++;
	}
      i++;
    }
}
