#include "push_swap.h"


// void mohcine(t_noeud **b, int len_a, int len_b)
// {
//     int inder_a;
//     int inder_b;
//     if ((*b)->au_dessus_median && (*b)->noeud_cible->au_dessus_median)
//     {
//         if ((*b)->indice > (*b)->noeud_cible->indice)
//             (*b)->push_price = (*b)->noeud_cible->indice + ((*b)->indice - (*b)->noeud_cible->indice);
//         else if ((*b)->indice < (*b)->noeud_cible->indice)
//             (*b)->push_price = (*b)->indice + ((*b)->noeud_cible->indice - (*b)->indice);
//         else
//             (*b)->push_price = (*b)->indice;
//     }
//     else if (!(*b)->au_dessus_median && !(*b)->noeud_cible->au_dessus_median)
//     {
//         inder_a = len_a - (*b)->noeud_cible->indice;
//         inder_b = len_b - (*b)->indice;

//         if (inder_b > inder_a)
//             (*b)->push_price = inder_a + (inder_b - inder_a);
//         else if (inder_b < inder_a)
//             (*b)->push_price = inder_b + (inder_a - inder_b);
//         else
//             (*b)->push_price = inder_b;
//     }
// }
// static void    set_push_price(t_noeud **a, t_noeud **b)
// {
//     int len_a;
//     int len_b;

//     len_a = pile_taile(a);
//     len_b = pile_taile(*b);
//     while (*b)
//     {
//         (*b)->push_price = (!b)->indice;
//         if (!(*b)->au_dessus_median)
//             (*b)->push_price = len_b - (*b)->indice;
//         if ((*b)->noeud_cible->au_dessus_median)
//             (*b)->push_price += (*b)->noeud_cible->indice;
//         else
//             (*b)->push_price += len_a - (*b)->noeud_cible->indice;
//         mohcine(&b, len_a, len_b);
//         b = (*b)->suivant;
//     }
// }

static void    set_push_price(t_noeud *a, t_noeud *b)
{
    int len_a;
    int len_b;

    int inder_a;
    int inder_b;

    len_a = pile_taile(a);
    len_b = pile_taile(b);
    while (b)
    {
        b->push_price = b->indice; // une fois kn7ydha les movmente ki n9so une fois kan5aliha les movmente ki tzado hhh ms kn7ydha o kn9osha m3a implimentation tanya ok
        if (!b->au_dessus_median)
            b->push_price = len_b - b->indice;
        if (b->noeud_cible->au_dessus_median)
            b->push_price += b->noeud_cible->indice;
        else
            b->push_price += len_a - b->noeud_cible->indice;
        if (b->au_dessus_median && b->noeud_cible->au_dessus_median)
        {
            if (b->indice > b->noeud_cible->indice)
                b->push_price = b->noeud_cible->indice + (b->indice - b->noeud_cible->indice);
            else if (b->indice < b->noeud_cible->indice)
                b->push_price = b->indice + (b->noeud_cible->indice - b->indice);
            else
                b->push_price = b->indice;
        }
        else if (!b->au_dessus_median && !b->noeud_cible->au_dessus_median)
        {
            inder_a = len_a - b->noeud_cible->indice;
            inder_b = len_b - b->indice;

            if (inder_b > inder_a)
                b->push_price = inder_a + (inder_b - inder_a);
            else if (inder_b < inder_a)
                b->push_price = inder_b + (inder_a - inder_b);
            else
                b->push_price = inder_b;
        }
        b = b->suivant;
    }
}
static void    set_push_price_2(t_noeud *a, t_noeud *b)
{
    int len_a;
    int len_b;

    int inder_a;
    int inder_b;

    len_a = pile_taile(a);
    len_b = pile_taile(b);
    while (b)
    {
        b->push_price = b->indice;// une fois kn7ydha les movmente ki n9so une fois kan5aliha les movmente ki tzado hhh ms kn7ydha o kn9osha m3a implimentation tanya ok
        if (!b->au_dessus_median)
            b->push_price = len_b - b->indice;
        if (b->noeud_cible->au_dessus_median)
            b->push_price += b->noeud_cible->indice;
        else
            b->push_price += len_a - b->noeud_cible->indice;
        b = b->suivant;
    }
}