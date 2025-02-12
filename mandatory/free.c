/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mez-zahi <mez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:09:01 by mez-zahi          #+#    #+#             */
/*   Updated: 2025/02/12 18:15:17 by mez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	fr_single(char **s1, char **s2)
{
	if (*s1)
	{
		free(*s1);
		*s1 = NULL;
	}
	if (*s2)
	{
		free(*s2);
		*s2 = NULL;
	}
}

void liberer_erreurs(char **split)
{
	 int i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

void liberer_erreurs_2(char **split, bool droit)
{
	 int i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
	if (droit)
	{
		write(1,"Error\n",6);
    	exit(1);
	}
	else
		exit(0);
}

void free_pile(t_noeud *pile)
{
    t_noeud *temp;
    if(!pile)
        return ;
    while (pile)
    {
        temp = pile->suivant;
        free(pile);
        pile = temp;
    }
}

void free_piles(t_noeud *a, t_noeud *b)
{
    free_pile(a);
    free_pile(b);
}