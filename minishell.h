/*
** minishell.h for  in /home/henry_g/rendu_2/PSU/PSU_2015_minishell1
**
** Made by Clément Henry
** Login   <henry_g@epitech.net>
**
** Started on  Mon Feb  8 00:25:26 2016 Clément Henry
** Last update Sun Feb 14 21:02:13 2016 Clément Henry
*/

#ifndef MINISHELL_H_
# define MINISHELL_H_

#ifndef READ_SIZE
# define READ_SIZE (100)
#endif /* !READ_SIZE */

typedef struct  s_line
{
  int           i;
  int           c;
}               t_line;

typedef struct	s_shell
{
  char		**buffer;
  char		*path;
  char		**tab_path;
  char		*str;
}		t_shell;

typedef struct	s_array
{
  char		**line;
  char		**indice;
}		t_array;

# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <signal.h>

void    my_cd(t_shell *shell, t_array *array);
void    my_setenv(t_shell *shell, t_array *array);
void    my_unsetenv(t_shell *shell, t_array *array);
void    my_env(t_shell *shell, t_array *array);
int     check_builtin(char **arg);
void    builtin(t_shell *shell, t_array *array);
int     calc_env(char **env);
char    **my_copy_env(char **env);
char    **get_indice(char **env);
char    **get_line(char **env);
void    do_it(char *path, char **buffer, char **env);
int     first_step(char *str);
char    *my_epur_str(char *str);
void    my_exit(char *str);
char    *get_my_env(t_array *array);
char    *get_s_env(char **env, char *what);
int     len(char *str);
int     check_read(char *stat_line);
char    *my_realloc(char *s_1, char *s_2);
char    *copy_backslash(char *buff);
char    *get_next_line(const int fd);
char    *real_path(char *path, char *str);
void    catch(int signal);
int     minishell(char **env, t_array *array);
void    my_exec(t_shell *shell, t_array *array, char **env);
void    my_putchar(char c);
int     my_strlen(char *str);
void    my_putstr(char *str);
int     str_check(char *s1, char *s2);
int     check_arg(char *str);
char    *my_open(t_shell *shell, t_array *array, char **env, int *i);
char    **create_new(t_array *array, char *name, int c);
void    one_setenv(t_array *array, char *what);
void    two_setenv(t_array *array, t_shell *shell);
int     calc_before(char *line);
int     calc_after(char *line);
int     how_alloc(char *str, char what, int index);
void    print_my_tab(char **tab);
int     count_words(char *str, char what);
void    initialise(int *i, int *j);
char    **my_str_to_wordtab(char *str, char what);
char	*my_strcat(char *s, char *ss);
char	*my_strdup(char *);

#endif /* !MINISHELL_H_ */
