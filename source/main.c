/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpa <jimpa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 13:59:25 by jimpa             #+#    #+#             */
/*   Updated: 2025/03/25 13:59:27 by jimpa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	char **my_envp;

	my_envp =ft_array_dup(envp);
	ft_read_line(&my_envp);

	return (0);
}
