/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpa <jimpa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:01:37 by jiparcer          #+#    #+#             */
/*   Updated: 2025/03/26 17:54:49 by jimpa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
// a utiliser dans une condition if 
//en verifiant aussi que le type de la valeur utilisé soit "WORD"
int	ft_is_builtin(char **cmd, char **envp)
{
	if (ft_strncmp(cmd[0], "echo", 4) == 0)
		return (ft_echo(cmd));
	else if (ft_strncmp(cmd[0], "cd", 2) == 0)
		return (ft_cd(cmd));
	else if (ft_strncmp(cmd[0], "pwd", 3) == 0)
		return (ft_pwd());
	else if (ft_strncmp(cmd[0], "export", 6) == 0)
		return (1);									//ft_export(cmd, envp); //TODO
	else if (ft_strncmp(cmd[0], "unset", 5) == 0)
		return (1);									//ft_unset(cmd, envp); //TODO
	else if (ft_strncmp(cmd[0], "env", 3) == 0)
		return (ft_env(envp));
	else if (ft_strncmp(cmd[0], "exit", 4) == 0)
		return (1);									//ft_exit(cmd, envp) //TODO
	else
		return (0); // ce n'est pas un builtin
}
