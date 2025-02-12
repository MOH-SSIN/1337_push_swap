#include "checker.h"


int ft_strcmp(const char *s1, const char *s2)
{
    if (!s1 || !s2)
        return (-1);

    while (*s1 && *s2)
    {
        if (*s1 != *s2)
            break;
        s1++;
        s2++;
    }

    return ((unsigned char)*s1 - (unsigned char)*s2);
}

t_noeud *ft_check_creat(t_noeud **a, char **args)
{
    int     i;
    long    nombre;

    nombre = 0;
    i = 0;
    if (!args || !args[i])// hna fach kndire "   " ou "" normalemt split 4ada t5rje liya pointeure null hdi dartha bach nhadli hde cas !!!
            liberer_erreurs_bonus(args);
    while (args[i])
    {
        if (verifier_syntaxe_bonus(args[i]) == 1)
            liberer_erreurs_bonus(args);
        nombre = ft_atoi(args[i]);
        if (nombre < INT_MIN || nombre > INT_MAX)
            liberer_erreurs_bonus(args);
        if (verfier_doubl_bonus(args,(int)nombre))
            liberer_erreurs_bonus(args);
        i++;
    }
    *a = ajouter_noeud(args, false);
    return (*a);
}

void run_command(char *commande, t_noeud **a, t_noeud **b)
{
    if (!commande)
        return ;
    if (ft_strcmp(commande, "sa\n") == 0)
        sa(a, true);
    else if (ft_strcmp(commande, "sb\n") == 0)
        sb(b, true);
    else if (ft_strcmp(commande, "ss\n") == 0)
        ss(a, b, true);
    else if (ft_strcmp(commande, "pa\n") == 0)
        pa(a, b, true);
    else if (ft_strcmp(commande, "pb\n") == 0)
        pb(a, b, true);
    else if (ft_strcmp(commande, "ra\n") == 0)
        ra(a, true);
    else if (ft_strcmp(commande, "rb\n") == 0)
        rb(b, true);
    else if (ft_strcmp(commande, "rr\n") == 0)
        rr(a, b, false);
    else if (ft_strcmp(commande, "rra\n") == 0)
        rra(a, true);
    else if (ft_strcmp(commande, "rrb\n") == 0)
        rrb(b, true);
    else if (ft_strcmp(commande, "rrr\n") == 0)
        rrr(a, b, false);
    else
    {
        write(2, "Error\n", 6);
        free(commande);
        exit(1);
    }
}