/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdijkman <jdijkman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/10 14:17:46 by jdijkman      #+#    #+#                 */
/*   Updated: 2023/10/27 15:12:35 by jdijkman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_fill(char *sub, const char *s, size_t len, unsigned int start)
{
	int	i;

	i = 0;
	while (s[start + i] && len > 0)
	{
		sub[i] = s[start + i];
		i++;
		len--;
	}
	sub[i] = '\0';
	return (sub);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	if (start >= ft_strlen(s))
	{
		sub = (char *)malloc(1);
		if (sub == NULL)
			return (NULL);
		sub[0] = '\0';
		return (sub);
	}
	if (start + len > ft_strlen(s))
		sub = (char *)malloc(ft_strlen(s) - start + 1);
	else
		sub = (char *)malloc(len + 1);
	if (sub == NULL)
		return (NULL);
	ft_fill(sub, s, len, start);
	return (sub);
}

// int main(void)
// {
//     // const char *s = "";
//     // unsigned int start = 0;
//     // size_t len = 42;
//     printf("%s", ft_substr("0123456789", 9, 10));
// }