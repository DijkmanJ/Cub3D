/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdijkman <jdijkman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 18:10:50 by jdijkman      #+#    #+#                 */
/*   Updated: 2023/10/23 17:03:45 by jdijkman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	while (n > 0)
	{
		((char *)s)[n - 1] = c;
		n --;
	}
	return (s);
}

// int main(void)
// {
// 	char str[20] = "hello world";
// 	int c = 'a';
// 	size_t n = 5;
// 	printf("%s\n", str);
// 	ft_memset(str, c, n);
// 	printf("%s", str);
// }