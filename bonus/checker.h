#ifndef CHECKER_H
#define CHECKER_H

#include "stdio.h"
#include "unistd.h"
# include "stdlib.h"
# include "limits.h"
#include "../push_swap.h"
#include "../libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000000
# endif

char	*get_next_line(int fd);
void	*ft_free(char *ptr1, char *ptr2);

//cheker_utils.c
void run_command(char *commande, t_noeud **a, t_noeud **b);
int ft_strcmp(const char *s1, const char *s2);
t_noeud *ft_check_creat(t_noeud **a, char **args);

//verification utlis
int ft_vide_space_bonus(char *str);
int verifier_syntaxe_bonus(char *str);
int verfier_doubl_bonus(char **str, int nbr);
void liberer_erreurs_bonus(char **split);
#endif