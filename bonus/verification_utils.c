/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mez-zahi <mez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:16:31 by mez-zahi          #+#    #+#             */
/*   Updated: 2025/02/12 18:16:32 by mez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"


int verifier_syntaxe_bonus(char *str)
{
    int     i;

    i = 0;
    while (str[i] == ' ')
        i++;
    if (!str[i])
        return (1);
    if(str[i] == '+' || str[i] == '-')
        i++;
    while (str[i] != '\0')
    {
        if (!ft_isdigit(str[i]))
                return (1);
        i++;
    }
    return (0);
}

int verfier_doubl_bonus(char **str, int nbr)
{
    int i;
    int check;

    check = 0;
    i = 0;
    while (str[i])
	{
        if (ft_atoi(str[i]) == nbr)
            check++;
        i++;
	}
    if (check == 1)
        return (0);
    else
        return (1);
}

void liberer_erreurs_bonus(char **split)
{
    int i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
	write(1,"Error\n",6);
    exit(1);
}