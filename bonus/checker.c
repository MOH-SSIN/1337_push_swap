/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mez-zahi <mez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:16:51 by mez-zahi          #+#    #+#             */
/*   Updated: 2025/02/12 18:16:52 by mez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"


int main(int argc, char **argv)
{
    t_noeud *a;
    t_noeud *b;
    char    **args;
    char    *commande;

    commande = ft_strdup("");
    if (argc < 2)
        return (0);
    int i = 0;
    a = NULL;
    b = NULL;
    if (argc < 2)
        return (0);
    else
    {
        while(argv[++i])
        {
            if(ft_vide_space(argv[i]) == 1)
            {
                    write(1,"Error\n",6);
    	            exit(1);
            }
        }
        args = concat_arg(argc, argv);
    }
    a = ft_check_creat(&a, args);
    while ((commande = get_next_line(0)))
    {
        run_command(commande, &a, &b);
        free(commande);
    }
    if (pile_trie(a) && !b)
        write(1,"OK\n",3);
    else
        write(1,"KO\n",3);
    free_piles(a, b);
    return (0);
}