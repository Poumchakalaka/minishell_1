/*
** minishell.c for  in /home/henry_g/rendu_2/PSU/PSU_2015_minishell1
**
** Made by Clément Henry
** Login   <henry_g@epitech.net>
**
** Started on  Fri Feb 12 23:00:23 2016 Clément Henry
** Last update Sun Feb 14 23:20:25 2016 Clément Henry
*/

#include "minishell.h"

void	catch(int signal)
{
  my_putchar('\n');
  my_putstr("$>");
  return ;
}

int	check_space(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] != ' ')
	return (1);
      i++;
    }
  return (0);
}

void	exit_value(t_shell *shell)
{
  if (shell->buffer[1] == NULL)
    exit (0);
  else
    exit(my_getnbr(shell->buffer[1]));
}

int		minishell(char **env, t_array *array)
{
  t_shell	shell;
  int		i;

  while (42)
    {
      i = 0;
      my_putstr("$> ");
      shell.path = get_my_env(array);
      if (shell.path[0] == '\0')
	shell.path = my_strdup("/bin/");
      shell.str = get_next_line(0);
      if (shell.str == NULL || shell.str[0] == '\0'
	  || check_space(shell.str) != 1)
	  my_exit(shell.str);
      else
      	{
	  shell.buffer = my_str_to_wordtab(my_epur_str(shell.str), ' ');
	  if (str_check(shell.buffer[0], "exit") == 1)
	    exit_value(&shell);
	  shell.tab_path = my_str_to_wordtab(shell.path, ':');
	  shell.path = my_open(&shell, array, env, &i);
	  if (i == 1)
	    do_it(shell.path, shell.buffer, env);
	}
    }
}
