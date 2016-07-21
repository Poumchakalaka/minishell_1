/*
** get_env.c for  in /home/henry_g/rendu_2/PSU/PSU_2015_minishell1
**
** Made by Clément Henry
** Login   <henry_g@epitech.net>
**
** Started on  Mon Feb  8 00:10:15 2016 Clément Henry
** Last update Sun Feb 14 22:30:39 2016 Clément Henry
*/

#include "minishell.h"

char	*get_my_env(t_array *array)
{
  int	i;
  char	*tmp;

  i = 0;
  while (array->indice[i] != NULL)
    {
      if (str_check(array->indice[i], "PATH") == 1)
	{
	  tmp = my_strdup(array->line[i]);
	  return (tmp);
	}
      i++;
    }
}

char	*get_s_env(char **env, char *what)
{
  int	i;
  int	j;
  char	*tmp;
  int	counter;
  int	cpt;

  cpt = 0;
  i = -1;
  while (env[++i] != NULL)
    {
      j = 0;
      if (env[i][0] == what[0] && env[i][1] == what[1])
	if (env[i][2] == what[2])
	  {
	    while (env[i][j++] != '=');
	    counter = my_strlen(&(env[i][j]));
	    if ((tmp = malloc(counter + 1 * sizeof(char))) == NULL)
	      return (NULL);
	    while (env[i][j] != '\0')
	      tmp[cpt++] = env[i][j++];
	    tmp[cpt] = '\0';
	    return (tmp);
	  }
    }
  return (0);
}
