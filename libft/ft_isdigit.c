/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isdigit.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdijkman <jdijkman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 16:44:08 by jdijkman      #+#    #+#                 */
/*   Updated: 2023/10/23 16:16:12 by jdijkman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c < '0' || c > '9')
		return (0);
	else
		return (2048);
}

// int main(void)
// {
// 	for (int i = 0; i < 256; i ++)
// 	{
// 		if (ft_isdigit(i)  != isdigit(i))
// 		{
// 			printf("\nERROR at %i:\n", i);
// 			printf("%i\n", ft_isdigit(i));
// 			printf("%i\n", isdigit(i));
// 			continue;
// 		}
// 		printf("ok ");
// 	}
// }