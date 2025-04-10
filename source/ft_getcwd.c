/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getcwd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiparcer <jiparcer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:33:44 by jiparcer          #+#    #+#             */
/*   Updated: 2025/03/24 17:29:27 by jiparcer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_getcwd(void)
{
	char cwd[BUFSIZ];
	getcwd(cwd, sizeof(cwd)); //* donne le path actuel a cwd
		printf("\033[34m[~%s]\033[0m\n", cwd);
}