/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmoren <migmoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:46:41 by migmoren          #+#    #+#             */
/*   Updated: 2023/06/07 09:29:33 by migmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*cpy;
	int		i;

	i = -1;
	cpy = (char *)malloc(sizeof(char) * (ft_strlen(src) + 2));
	if (!cpy)
		return (0);
	while (src[++i] != '\0')
		cpy[i] = src[i];
	cpy[i] = '\0';
	return (cpy);
}
