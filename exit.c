/*
** exit.c for  in /home/henry_g/rendu_2/PSU/PSU_2015_minishell1
**
** Made by Clément Henry
** Login   <henry_g@epitech.net>
**
** Started on  Fri Feb 12 22:47:55 2016 Clément Henry
** Last update Sun Feb 14 05:09:59 2016 Clément Henry
*/

#include "minishell.h"

void	my_putcherror(char c)
{
  write(2, &c, 1);
}

void	my_error(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    my_putcherror(str[i++]);
}

void	my_exit(char *str)
{
  if (str[0] == '\0')
    return ;
  if (check_space(str) != 1)
    return ;
  if (str == NULL)
    {
      my_putchar('\n');
      exit (0);
    }
}
