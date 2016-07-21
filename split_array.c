/*
** split_array.c for  in /home/henry_g/rendu_2/PSU/PSU_2015_minishell1
**
** Made by Clément Henry
** Login   <henry_g@epitech.net>
**
** Started on  Sat Feb 13 02:04:26 2016 Clément Henry
** Last update Sat Feb 13 02:17:27 2016 Clément Henry
*/

#include "minishell.h"

int	calc_before(char *line)
{
  int	i;

  i = 0;
  while (line[i] != '=')
    i++;
  return (i);
}

int	calc_after(char *line)
{
  int	i;

  i = 0;
  while (line[i++] != '=');
  i = 0;
  while (line[i] != '\0')
    i++;
  return (i);
}
