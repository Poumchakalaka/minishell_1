/*
** str_dup.c for  in /home/henry_g/PSU_2015_minishell1
** 
** Made by Clément Henry
** Login   <henry_g@epitech.net>
** 
** Started on  Sun Feb 14 17:41:13 2016 Clément Henry
** Last update Sun Feb 14 20:39:56 2016 Clément Henry
*/

#include "minishell.h"

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i])
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}

char	*my_strdup(char *str)
{
  char	*tmp;

  if ((tmp = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    return (NULL);
  tmp = my_strcpy(tmp, str);
  tmp[my_strlen(str)] = 0;
  return (tmp);
}
