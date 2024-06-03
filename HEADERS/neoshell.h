/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   neoshell.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajabri <ajabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:11:53 by ajabri            #+#    #+#             */
/*   Updated: 2024/06/03 12:01:05 by ajabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef NEOSHELL_H
# define NEOSHELL_H

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <fcntl.h>
# include <stdbool.h>
#include <sys/wait.h>
#include <readline/readline.h>
#include <readline/history.h>

#define PROMPT G "🌟::NeoShell~/💎[" ORG "Prompt" RES G "]🗿$\n|~↠$ " RES


typedef struct s_env
{
    char *envar;// envp variable name
    char *value; //the value of the var
    struct s_env *next;
}               t_envl; //env_list

typedef struct s_neo
{
    char    **envp;
    char    *line;
    t_envl  *envl;
    size_t size;
} g_neo;

t_envl *ft_lstlast(t_envl *lst);
t_envl *ft_lstnew(char *var);
void    ft_lstadd_back(t_envl **lst, t_envl *newx);
void    ft_strcpy(char *dst, char *src, char c);
void    ft_env();
void    ft_exit(int x);
#endif