/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isascii.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdijkman <jdijkman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 17:06:41 by jdijkman      #+#    #+#                 */
/*   Updated: 2023/10/23 16:16:26 by jdijkman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c < 0 || c > 127)
		return (0);
	return (1);
}

// int main(void)
// {
// 	for (int i = 0; i < 256; i ++)
// 	{
// 		if (ft_isascii(i)  != isascii(i))
// 		{
// 			printf("\nERROR at %i:\n", i);
// 			printf("%i\n", ft_isascii(i));
// 			printf("%i\n", isascii(i));
// 			continue;
// 		}
// 		printf("ok ");
// 	}
// }