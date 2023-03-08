/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmoren <migmoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:06:49 by migmoren          #+#    #+#             */
/*   Updated: 2023/03/08 18:23:04 by migmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_validate_extension(char *map)
{
	int		len;
	char	*aux;

	if (!map)
		return (0);
	len = ft_strlen(map);
	aux = ft_substr(map, len-4, len-1);
	if (!map || ft_strncmp(aux, ".ber", 4))
		return(0);
	return (1);
}
