/*
** my_exec.c for  in /home/henry_g/rendu_2/PSU/PSU_2015_minishell1
**
** Made by Clément Henry
** Login   <henry_g@epitech.net>
**
** Started on  Sat Feb 13 01:42:48 2016 Clément Henry
** Last update Sun Feb 14 19:34:12 2016 Clément Henry
*/

#include "minishell.h"

void	my_exec(t_shell *shell, t_array *array, char **env)
{
  int	status;
  pid_t	pid;

  pid = fork();
  if (pid == 0)
    {
      if (execve(shell->buffer[0], shell->buffer, env) == -1)
	exit (1);
    }
    else
      waitpid(0, &status, WUNTRACED);
  if (WIFSIGNALED(status))
    {
      if (WTERMSIG(status) == 11)
	my_putstr("Segmentation Fault\n");
      if (WTERMSIG(status) == 8)
	my_putstr("Floating point exception\n");
    }
}
