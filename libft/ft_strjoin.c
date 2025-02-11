/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdijkman <jdijkman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/10 14:31:39 by jdijkman      #+#    #+#                 */
/*   Updated: 2024/09/18 13:36:37 by jdijkman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *) malloc (ft_strlen(s1) + ft_strlen(s2) + 1);
	if (str == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i ++;
	}
	i = 0;
	while (s2[i])
	{
		str[ft_strlen(s1) + i] = s2[i];
		i ++;
	}
	str[ft_strlen(s1) + i] = '\0';
	free(s1);
	return (str);
}
