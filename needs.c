/*
** needs.c for  in /home/henry_g/rendu_2/PSU/PSU_2015_minishell1
**
** Made by Clément Henry
** Login   <henry_g@epitech.net>
**
** Started on  Mon Feb  8 00:24:23 2016 Clément Henry
** Last update Sun Feb 14 17:41:06 2016 Clément Henry
*/

#include "minishell.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    my_putchar(str[i++]);
}

int      my_getnbr(char *str)
{
  int    i;
  int    nb;
  int    res;

  i = 0;
  res = 0;
  while (str[i] != '\0')
    {
      if (str[i] <= '9' && str[i] >= '0')
        {
          nb = str[i] - 48;
          res = res + nb;
          if (str[i + 1] != '\0' && (str[i + 1] <= '9' && str[i + 1] >= '0'))
            res = res * 10;
        }
      i = i + 1;
    }
  if (str[0] == '-')
    res = res * -1;
  return (res);
}
