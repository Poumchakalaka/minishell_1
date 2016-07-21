/*
** unset.c for  in /home/henry_g/PSU_2015_minishell1
** 
** Made by Clément Henry
** Login   <henry_g@epitech.net>
** 
** Started on  Sun Feb 14 21:56:09 2016 Clément Henry
** Last update Sun Feb 14 22:18:45 2016 Clément Henry
*/

#include "minishell.h"

char	**unset(t_shell *shell, t_array *array, int indic, int w_r)
{
  char	**nw_tab;
  int	i;
  int	counter;

  counter = 0;
  i = 0;
  if ((nw_tab = malloc((calc_env(array->indice) - 1) *sizeof(char *))) == NULL)
    return NULL;
  while (array->indice[i] != NULL)
    {
      if (i == indic)
	i++;
      if (w_r == 1)
	nw_tab[counter] = my_strdup(array->line[i]);
      else
	nw_tab[counter] = my_strdup(array->indice[i]);
      counter++;
      i++;
    }
  nw_tab[counter] = NULL;
  if (w_r == 1)
    print_my_tab(nw_tab);
  return (nw_tab);
}
