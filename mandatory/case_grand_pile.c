/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_grand_pile.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mez-zahi <mez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:08:46 by mez-zahi          #+#    #+#             */
/*   Updated: 2025/02/13 13:57:17 by mez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static bool is_true(t_noeud *a)
{
    while (a)
    {
        if (a->appartient == false)
            return (1);
        a = a->suivant;
    }
    return (0);
}


void push_non_list(t_noeud **a, t_noeud**b)
{
    t_noeud *tmp;

    while (is_true(*a))
    {
        set_index(*a);
        tmp = *a;
        if ((tmp)->appartient)
            ra(a, false);
        else
            pb(a, b, false);
        tmp = (tmp)->suivant;
    }
}

void	set_index(t_noeud *pile)
{
	int i;

    i = -1;
    while (pile)
    {
        pile->indice = ++i;
        pile = pile->suivant;
    }
}

void case_grand_pile(t_noeud **a,t_noeud **b)
{
    t_noeud *ptit;
    
    push_non_list(a,b);
    while (*b)
    {
        init_pile(a,b);
        move_b_vers_a(a,b);
    }
    ptit = ft_Get_PtitdNode(*a);
    if (ptit->au_dessus_median)
        while (*a != ptit)
            ra(a, false);
    else
        while (*a != ptit)
            rra(a, false);
}
