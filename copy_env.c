/*
** copy_env.c for  in /home/henry_g/rendu_2/PSU/PSU_2015_minishell1
**
** Made by Clément Henry
** Login   <henry_g@epitech.net>
**
** Started on  Sat Feb 13 00:03:00 2016 Clément Henry
** Last update Sun Feb 14 22:09:44 2016 Clément Henry
*/

#include "minishell.h"

int	calc_env(char **env)
{
  int	i;

  i = 0;
  while (env[i++] != NULL);
  return (i);
}

char	**my_copy_env(char **env)
{
  int	i;
  char	**my_env;

  i = 0;
  if ((my_env = malloc((calc_env(env) + 1) * sizeof(char *))) == NULL)
    return (NULL);
  while (env[i] != NULL)
    my_env[i] = my_strdup(env[i++]);
  my_env[i] = NULL;
  return (my_env);
}

char    **get_indice(char **env)
{
  char	**before_equal;
  int	i;
  int	j;

  i = 0;
  if ((before_equal = malloc((calc_env(env) + 1) * sizeof(char *))) == NULL)
     return (NULL);
  while (env[i] !=  NULL)
    {
      j = 0;
      if ((before_equal[i] = malloc((calc_before(env[i]) + 1)
 * sizeof(char))) == NULL)
	return (NULL);
      while (env[i][j] != '=')
	before_equal[i][j] = env[i][j++];
      before_equal[i][j] = '\0';
      i++;
    }
  before_equal[i] = NULL;
  return (before_equal);
}

char    **get_line(char **env)
{
  char	**after_equal;
  int	i;
  int	j;
  int	counter;

  i = -1;
  if ((after_equal = malloc((calc_env(env) + 1) * sizeof(char *))) == NULL)
    return (NULL);
  while (env[++i] != NULL)
    {
      counter = 0;
      j = calc_before(env[i]) + 1;
      if ((after_equal[i] = malloc((calc_after(env[i]) + 1)
 * sizeof(char))) == NULL)
         return (NULL);
      while (env[i][j] != '\0')
	{
	  after_equal[i][counter] = env[i][j];
	  counter++;
	  j++;
	}
      after_equal[i][counter] = '\0';
    }
  after_equal[i] = NULL;
  return (after_equal);
}
