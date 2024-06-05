/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajabri <ajabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:15:43 by ajabri            #+#    #+#             */
/*   Updated: 2024/06/05 14:50:00 by ajabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../HEADERS/neoshell.h"
#include "../HEADERS/utils.h"

g_neo shell;

void    get_neoenvp(char **env)
{
    int i;
    if (!env)
        return ;
    i = 0;
    while (env[i])
    {
        ft_lstadd_back(&shell.envl, ft_lstnew(env[i]));
        i++;
    }
    shell.size = i;
    // ft_env();
}

void    neoinit(char **env)
{
    shell.envl = NULL;
    shell.leaks = NULL;
    shell.line = NULL;
    get_neoenvp(env);
}

void    ft_printf_out()
{
    t_block *save;

    save = shell.block;
    while (shell.block)
    {
        printf("node[%s][%d]\n", shell.block->value, shell.block->token);
        shell.block = shell.block->next;
    }
    shell.block = save;
}
void       read_prompt()
{
    // int pid;
    while (1)
    {
        shell.line = readline(PROMPT);
        if (shell.line)
            add_history(shell.line);
        if (!ft_strncmp(shell.line, "env", 4))
            ft_env(shell.envl);
        if (!ft_strncmp(shell.line, "exit", 5))
            ft_exit(0);
        ft_lexical();
        give_token();
        ft_printf_out();
        free(shell.line);
    }
}

void ft_free_leaks()
{
    t_leak *current = shell.leaks;
    t_leak *next;

    while (current != NULL)
    {
        next = current->next;
        free(current->address);
        free(current);
        current = next;
    }
    shell.leaks = NULL;
}


int main(int ac, char **av, char **env)
{
    (void)av;
    if (ac == 1)
    {
        neoinit(env);
        read_prompt();
        ft_free_leaks();
    }
    else
	{
		printf(ORG "Warrning :Please run it like this:\n" RES);
		printf(CY"++++++++++++++++++++++$\n\v"RES);
		printf(G "bash-3.2$ ./minishell\n\v" RES);
		printf(CY"++++++++++++++++++++++$\n"RES);
	}
}
