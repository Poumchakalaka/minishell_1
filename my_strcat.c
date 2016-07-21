/*
** my_strcat.c for  in /home/henry_g/rendu_2/PSU/PSU_2015_minishell1
**
** Made by Clément Henry
** Login   <henry_g@epitech.net>
**
** Started on  Sun Feb 14 03:58:51 2016 Clément Henry
** Last update Sun Feb 14 22:35:37 2016 Clément Henry
*/

#include "minishell.h"

char	*my_strcat(char *s, char *s2)
{
  char	*tmp;

  tmp = s;
  while (*tmp)
    ++tmp;
  while (*s2)
    *(tmp++) = *(s2++);
  *(tmp) = *(s2);
  return (s);
}
