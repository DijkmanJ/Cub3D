/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdijkman <jdijkman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 16:52:57 by jdijkman      #+#    #+#                 */
/*   Updated: 2023/10/23 18:43:52 by jdijkman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i] != '\0' && len > 0)
	{
		while (big[i + j] == little[j] && little[j] != '\0' && len > 0)
		{
			if (little[j + 1] == '\0' && len >= ft_strlen(little))
				return ((char *)&big[i]);
			j++;
		}
		j = 0;
		i++;
		len--;
	}
	return (NULL);
}

// #include <bsd/string.h>
// int main(void)
// {
// 	// const char *big = "hello world";
// 	// const char *little = "or";
// 	// size_t len = 9;
// 	// //printf("%s\n", strnstr(big, little, len));
// 	// printf("%s", ft_strnstr(big, little, len));
// 	printf("my:%s\n", ft_strnstr("aaabcabcd", "cd", 8));
// 	printf("o :%s\n", strnstr("aaabcabcd", "cd", 8));
// }