/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdijkman <jdijkman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/04 17:10:56 by jdijkman      #+#    #+#                 */
/*   Updated: 2023/10/23 16:47:31 by jdijkman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i ++;
		n --;
	}
	return (0);
}

// int main(void)
// {
// 	const char *s1 = "hello world";
// 	const char *s2 = "hella world";
// 	size_t n = 8;
// 	printf("%d\n", memcmp(s1, s2, n));
// 	printf("%d\n", ft_memcmp(s1, s2, n));
// }