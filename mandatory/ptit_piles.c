/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptit_piles.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mez-zahi <mez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:09:20 by mez-zahi          #+#    #+#             */
/*   Updated: 2025/02/13 14:36:33 by mez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	trier_trois(t_noeud **a)
{
	t_noeud	* grand_node;

	grand_node = ft_grand_element(*a);
	if (!(*a) || !(*a)->suivant->suivant)
		return ;
	if (*a == grand_node)
		ra(a, false);
	if ((*a)->suivant == grand_node)
		rra(a, false);
	if((*a)->valeur > (*a)->suivant->valeur)
		sa(a, false);
}

static void trier_quatre(t_noeud **a, t_noeud **b)
{
	t_noeud	*ptit;
	t_noeud	*tmp;

	tmp = *a;
	ptit = ft_Get_PtitdNode(*a);
	while (*a != ptit)
	{
		set_abov_medlan(*a);
		if (tmp->au_dessus_median)
		{
			tmp = tmp->suivant;
			ra(a, false);
		}
		else
		{
			tmp = tmp->suivant;
			rra(a, false);
		}
	}
	pb(a, b ,false);
	trier_trois(a);
	pa(a, b, false);
}


static int get_position(t_noeud *a, t_noeud *node)
{
    int pos = 0;
    t_noeud *current = a;

    // Parcours de la pile pour trouver le nœud
    while (current != NULL)
    {
        if (current == node)
            return pos;  // Retourner la position quand le nœud est trouvé
        current = current->suivant;
        pos++;
    }
    return -1;  // Si le nœud n'est pas trouvé, on retourne -1
}



static void trier_cinq(t_noeud **a, t_noeud **b)
{
    t_noeud *min_node;
    int min_pos;

    // Cas où la pile est déjà triée
    if (pile_trie_enreverse(*a))
	{
		rra(a, false);
		pb(a, b , false);
		trier_quatre(a, b);
		pa(a, b, false);
	}

    // 1. Trouver le plus petit élément et sa position
    min_node = ft_Get_PtitdNode(*a);
    min_pos = get_position(*a, min_node); // Implémenter get_position pour obtenir la position du plus petit élément

    // 2. Si le plus petit est déjà en haut, faire un pb
    if (min_pos == 0)
    {
        pb(a, b, false);
    }
    else
    {
        // 3. Si le plus petit est en bas, effectuer rra (rotation inverse)
        if (min_pos == pile_taile(*a) - 1)
        {
            rra(a, false);
            pb(a, b, false);
        }
        else
        {
            // 4. Sinon, on fait tourner jusqu'à ce que le plus petit soit en haut
            while (min_pos-- > 0)
                ra(a, false);
            pb(a, b, false);
        }
    }
    trier_quatre(a, b);
    pa(a, b, false);
}


// static void	trier_cinq(t_noeud **a, t_noeud **b)
// {
// 	t_noeud	*ptit;
// 	t_noeud	*tmp;

// 	if (pile_trie_enreverse(*a))
// 	{
// 		rra(a, false);
// 		pb(a, b , false);
// 		trier_quatre(a, b);
// 		pa(a, b, false);
// 	}
// 	else
// 	{
//         tmp = *a;
//         ptit = ft_Get_PtitdNode(*a);
// 	    while (*a != ptit)
// 	    {
// 		    set_abov_medlan(*a);
// 		    if (tmp->au_dessus_median)
// 		    {
// 			    tmp = tmp->suivant;
// 			    ra(a, false);
// 		    }
// 		    else
// 		    {
// 			    tmp = tmp->suivant;
// 			    rra(a, false);
// 		    }
// 	}
// 	pb(a, b ,false);
// 	trier_quatre(a, b);
// 	pa(a, b, false);
// 	}
// }

void case_ptit_piles(t_noeud **a, t_noeud **b)
{
	if (pile_taile(*a) == 2)
		sa(a, false);
	else if(pile_taile(*a) == 3)
		trier_trois(a);
	else if (pile_taile(*a) == 4)
		trier_quatre(a, b);
	else if (pile_taile(*a) == 5)
		trier_cinq(a, b);
}