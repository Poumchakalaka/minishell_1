/*
** my_epurSTR.c for  in /home/henry_g/rendu_2/PSU/PSU_2015_minishell1
**
** Made by Clément Henry
** Login   <henry_g@epitech.net>
**
** Started on  Tue Feb  9 17:25:59 2016 Clément Henry
** Last update Tue Feb  9 19:41:18 2016 Clément Henry
*/

#include "minishell.h"

int	first_step(char *str)
{
  int	i;

  i = 0;
  if (str[0] != ' ')
    return (0);
  else
    {
      while (str[i] == ' ')
	i++;
      return (i);
    }
}

char	*my_epur_str(char *str)
{
  char	*tmp;
  int	i;
  int	counter;

  counter = 0;
  i = 0;
  if ((tmp = malloc((my_strlen(str) + 1) * sizeof(char))) == NULL)
     return (NULL);
  str = str + (first_step(str));
  while (str[i] != '\0')
    {
      if (str[i] == ' ')
	{
	  while (str[i] == ' ')
	    i++;
	  if (str[i] != '\0')
	    {
	      tmp[counter] = ' ';
	      counter++;
	    }
	}
      tmp[counter++] = str[i++];
    }
  tmp[counter] = '\0';
  return (tmp);
}
