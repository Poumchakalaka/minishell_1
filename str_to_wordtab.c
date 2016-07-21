/*
** str_to_wordtab.c for  in /home/henry_g/rendu/projTester
**
** Made by Clément Henry
** Login   <henry_g@epitech.net>
**
** Started on  Fri Jun 19 19:02:30 2015 Clément Henry
** Last update Sat Jun 25 10:06:06 2016 Clément
*/

#include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>

static int	how_alloc_2(char *str, char what, int index)
{
  int		ct;

  ct = 0;
  while (str[index] != '\0' && str[index] != what)
    {
      index++;
      ct++;
    }
  return (ct);
}

void		print_my_tab(char **tab)
{
  int		i;

  i = 0;
  while (tab[i] != NULL)
    {
      my_putstr(tab[i]);
      my_putchar('\n');
      i++;
    }
}

static int     count_words_2(char *str, char what)
{
  int		i;
  int		counter;

  i = 0;
  counter = 0;
  while (str[i] != '\0')
    {
      if (str[i] == what)
	counter++;
      i++;
    }
  return (counter);
}

static void	initialise_2(int *i, int *j)
{
  *i = -1;
  *j = 0;
}

char		**my_str_to_wordtab(char *str, char what)
{
  int		column;
  int		line;
  char		**tab;
  int		i;

  initialise_2(&i, &line);
  if ((tab = malloc((count_words_2(str, what) + 2) * sizeof(char *))) == NULL)
    return (NULL);
  while (++i < my_strlen(str))
    {
      column = 0;
      if ((tab[line] = malloc((how_alloc_2(str, what, i) + 2) *
 sizeof(char))) == NULL)
	return (NULL);
      while (str[i] && str[i] != what)
	  tab[line][column++] = str[i++];
      tab[line][column] = '\0';
      line++;
    }
  tab[line] = NULL;
  return (tab);
}
