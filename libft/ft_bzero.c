/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdijkman <jdijkman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/04 12:33:59 by jdijkman      #+#    #+#                 */
/*   Updated: 2023/10/23 16:10:10 by jdijkman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	while (n > 0)
	{
		((char *)s)[n -1] = '\0';
		n --;
	}
}

// int main(void)
// {
// 	char str[20] = "hello world";
// 	size_t n = 8;
// 	printf("%s\n", str);
// 	ft_bzero(str + 5, n);
// 	printf("%s", str);
// }