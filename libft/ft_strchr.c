/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdijkman <jdijkman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/04 14:58:05 by jdijkman      #+#    #+#                 */
/*   Updated: 2023/10/23 17:08:10 by jdijkman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			return (&((char *)s)[i]);
		i ++;
	}
	if (s[i] == (unsigned char)c)
		return (&((char *)s)[i]);
	return (NULL);
}

// int main(void)
// {
// 	//int c = 2 + 256;
// 	char s[] = "tripouille";

// 	printf("%s\n", ft_strchr(s, 't' + 256));
// 	printf("%s\n", strchr(s, 't' + 256));
// }