/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isprint.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdijkman <jdijkman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 17:45:03 by jdijkman      #+#    #+#                 */
/*   Updated: 2023/10/23 16:16:46 by jdijkman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c < 32 || c > 126)
		return (0);
	return (16384);
}

// int main(void)
// {
// 	for (int i = 0; i < 256; i ++)
// 	{
// 		if (ft_isprint(i)  != isprint(i))
// 		{
// 			printf("\nERROR at %i:\n", i);
// 			printf("%i\n", ft_isprint(i));
// 			printf("%i\n", isprint(i));
// 			continue;
// 		}
// 		printf("ok ");
// 	}
// }