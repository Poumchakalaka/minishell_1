/*
** do_it.c for  in /home/henry_g/rendu_2/PSU/PSU_2015_minishell1
**
** Made by Clément Henry
** Login   <henry_g@epitech.net>
**
** Started on  Wed Feb 10 18:12:14 2016 Clément Henry
** Last update Sun Feb 14 22:46:49 2016 Clément Henry
*/

#include "minishell.h"

int	all_check(t_shell *shell, t_array *array, char **env)
{
  if (check_arg(shell->buffer[0]) == 2)
    {
      builtin(shell, array);
      return (1);
    }
  else if (shell->buffer[0][0] == '/')
    {
      my_special(shell, array, env);
      return (1);
    }
  return (0);
}

void	do_it(char *path, char **buffer, char **env)
{
  pid_t	pid;
  int	status;

  pid  = fork();
  if (pid == 0)
    {
      if (execve(path, buffer, env) == -1)
	exit (1);
    }
  else
    waitpid(0, &status, WUNTRACED);
  if (WIFSIGNALED(status))
    {
      if (WTERMSIG(status) == 11)
	my_putstr("Segmentation Fault\n");
      else if (WTERMSIG(status) == 8)
	my_putstr("Floating point exception\n");
    }
}

void	do_it_1(char *path, char **buffer, char **env)
{
  int	status;
  int	pid;

  pid = fork();
  if (pid == 0)
    {
      if (execve(path, buffer, env) == -1)
	exit (1);
    }
    else
      wait(&status);
}
