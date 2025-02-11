/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdijkman <jdijkman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 18:08:10 by jdijkman      #+#    #+#                 */
/*   Updated: 2023/10/24 14:59:10 by jdijkman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	long long	totsize;
	void		*ptr;

	totsize = nmemb * size;
	if (nmemb < 0 || size < 0)
		return (NULL);
	if (nmemb == 0 || size == 0)
	{
		ptr = malloc (0);
		return (ptr);
	}
	if (totsize > 2147483647 || nmemb > 2147483647 || size > 2147483647)
		return (NULL);
	ptr = malloc (totsize);
	if (ptr == NULL)
		return (NULL);
	ft_bzero (ptr, totsize);
	return (ptr);
}

// int main (void)
// {
// 	// size_t nmemb = 23;
// 	// size_t size = 4;
// 	int *ptr = (int *)calloc(__SIZE_MAX__, __SIZE_MAX__);
// 	int *ptr2 = (int *)ft_calloc(__SIZE_MAX__, __SIZE_MAX__);
// 	*ptr = 3234;
// 	*ptr2 = 1234;
// }