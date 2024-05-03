/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rib <joao-rib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:30:33 by joao-rib          #+#    #+#             */
/*   Updated: 2024/04/03 18:24:33 by joao-rib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/push_swap.h"

char	*ft_substr(const char *str, unsigned int start, size_t len)
{
	unsigned int	l;
	char			*dest;
	size_t			i;

	l = (unsigned int)ft_strlen(str);
	i = 0;
	if (l < start || len == 0)
		dest = (char *)ft_calloc(1, sizeof(char));
	else if ((l - start) > (unsigned int)len)
		dest = (char *)ft_calloc(len + 1, sizeof(char));
	else
		dest = (char *)ft_calloc(l - start + 1, sizeof(char));
	if (!dest)
		return (NULL);
	while (i < len && l > start && str[start] != '\0')
	{
		dest[i] = str[start];
		start++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
