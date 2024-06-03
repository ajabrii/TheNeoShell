/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajabri <ajabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:15:43 by ajabri            #+#    #+#             */
/*   Updated: 2024/06/03 10:21:34 by ajabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../HEADERS/neoshell.h"

int main(int ac, char **av, char **envp)
{
    if (ac == 1)
    {
        neoinit(envp);
    }
    else
	{
		printf(ORG "Warrning :Please run it like this:\n" RES);
		printf(CY"++++++++++++++++++++++$\n\v"RES);
		printf(G "bash-3.2$ ./minishell\n\v" RES);
		printf(CY"++++++++++++++++++++++$\n"RES);
	}
}
