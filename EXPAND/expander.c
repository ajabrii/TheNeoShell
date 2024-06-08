/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajabri <ajabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 11:00:57 by ajabri            #+#    #+#             */
/*   Updated: 2024/06/08 17:04:45 by ajabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../HEADERS/neoshell.h"
# include "../HEADERS/utils.h"


/* i need to handle
those cases:
    if i have "hello $USER jddjhdf $PWD" i need to handel this echo $?
    i need to hande this case $
    and maybe i will handle this echo $$
*/


bool check_expand(char *value)
{
    int i;

    i = 0;
    if (!value)
        return (false);
    if (value[0] == 39) // 39 is sq '
        return (false);
    while (value[i])
    {
        if(value[i] == '$' && (value[i + 1] != '$' || value[i + 1] != '\0'))
            return (true);
        i++;
    }
    return (false);
}

char    *fitch_value(char *varname)
{
    t_envl *save;
    char *expanded;

    expanded = NULL;
    printf("varname ->[%s]\n", varname);
    save = shell.envl;
    while (save)
    {
        if (!ft_strncmp(save->envar, varname, ft_strlen(save->envar)))
        {
            expanded = ft_strdup(save->value);
            break;
        }
        save = save->next;
    }
    return (expanded);
}

char    *grep_value(char *val)
{
    char *expanded;
    int i;
    int len;
    int tmp;

    i = 0;
    len = 0;
    tmp = 0;
    while (1)
    {
        if (val[i] == 34) // 34 is dq "
            i++;
        else
        {
            if (val[i] == '$')
                i++;
            tmp = i;
            while (val[i] && val[i] != ' ') // TO DO add all white spaces
            {
                i++;
            }
            len = i - tmp;
            printf(" [i ->%i] [tem ->%d] [len ->%d]\n", i, tmp, len);
            expanded = fitch_value(ft_substr(val, tmp, len));
        }
        if(!val[i])
            break;
         i++;
    }
    return (expanded);
}
void    expander()
{
    t_block *save;

    save = shell.block;
    while (shell.block)
    {
        // printf("hello %p\n", save);
        if(check_expand(shell.block->value))
            shell.block->value = grep_value(shell.block->value);
        shell.block = shell.block->next;
    }
    save = shell.block;
    // while (save)
    // {
    //     printf("hello\n");
    //     printf("[%s]\n", save->value);
    //     save = save->next;
    // }
}
