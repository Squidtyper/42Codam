/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   megaphone.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/12 12:42:12 by lizhang       #+#    #+#                 */
/*   Updated: 2023/01/20 19:56:03 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int    main(int ac, char **av)
{
	int i = 1;
	int j;

	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *"<<std::endl;
	else
	{
		while (av[i])
		{
			j = 0;
			while (av[i][j])
			{
				av[i][j] = toupper(av[i][j]);
				j++;
			}
			std::cout << av[i];
		i++;
		}
		std::cout << std::endl;
	}
	return (0);
}