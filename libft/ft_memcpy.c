/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdijkman <jdijkman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/04 12:43:35 by jdijkman      #+#    #+#                 */
/*   Updated: 2023/10/24 14:43:33 by jdijkman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!src && !dest)
		return (NULL);
	while (n > i)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i ++;
	}
	return (dest);
}

// int main(void)
// {
// // 	char src[20] = "hello world";
// // 	char dest[20] = "goodbye";
// // 	size_t n = 5;
// // 	printf("dest: %s\n", dest);
// // 	printf("src: %s\n", src);
// // 	//ft_memcpy(dest, src, n);
//  	ft_memcpy("", "", 5);
// // 	printf("new dest: %s\n", dest);
// // 	printf("new src: %s\n", src);
// }