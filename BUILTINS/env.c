/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajabri <ajabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:39:54 by ajabri            #+#    #+#             */
/*   Updated: 2024/06/03 11:56:24 by ajabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../HEADERS/neoshell.h"
# include "../HEADERS/utils.h"

g_neo shell;

void    ft_env()
{
    t_envl *tmp;

    tmp = shell.envl;
    while (shell.envl)
    {
        printf("%s=%s\n",shell.envl->envar, shell.envl->value);
        shell.envl = shell.envl->next;
    }
    shell.envl = tmp;
}
