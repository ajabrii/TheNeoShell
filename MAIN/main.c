/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajabri <ajabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:15:43 by ajabri            #+#    #+#             */
/*   Updated: 2024/06/03 12:03:34 by ajabri           ###   ########.fr       */
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
    shell.line = NULL;
    get_neoenvp(env);
}

void       read_prompt()
{
    while (1)
    {
        shell.line = readline(PROMPT);
        if (shell.line)
            add_history(shell.line);
        if (!ft_strncmp(shell.line, "env", 4))
            ft_env();
        if (!ft_strncmp(shell.line, "exit", 5))
            ft_exit(0);
    }
}

int main(int ac, char **av, char **env)
{
    (void)av;
    if (ac == 1)
    {
        neoinit(env);
        read_prompt();
    }
    else
	{
		printf(ORG "Warrning :Please run it like this:\n" RES);
		printf(CY"++++++++++++++++++++++$\n\v"RES);
		printf(G "bash-3.2$ ./minishell\n\v" RES);
		printf(CY"++++++++++++++++++++++$\n"RES);
	}
}
