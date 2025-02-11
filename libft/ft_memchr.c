/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdijkman <jdijkman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/04 16:32:29 by jdijkman      #+#    #+#                 */
/*   Updated: 2023/10/24 14:52:59 by jdijkman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		if (((unsigned char *)s)[i] == (unsigned char) c)
			return (&((unsigned char *)s)[i]);
		i ++;
		n --;
	}
	return (NULL);
}

// i removed: 
	// if (!s)
	// 	return (NULL);
// because its supposed to crash according to unit test 
//
// int main(void)
// {
// 	char s[] = {0, 1, 2, 3, 4, 5};
// 	int c =  2 + 256;
// 	size_t n = 3;
// 	printf("%s\n", (char *)memchr(s, c, n));
// 	printf("%s\n", (char *)ft_memchr(s, c, n));
// }