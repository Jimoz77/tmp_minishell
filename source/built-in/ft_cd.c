/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpa <jimpa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:08:22 by jimpa             #+#    #+#             */
/*   Updated: 2025/04/10 16:34:13 by jimpa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

//sert a update toutes les env_var
//verifier si OLDPWD est recrée apres une utilisation de CD + suppresion de OLDPWD au préalable
// si oui ajouter fonctionnalité pour rajouter une env_var si elle manque
//demander a gpt quel sont les buit-in qui modifient des env_var
void	ft_setenv(char ***envp, char *var, char *new_val)
{
	char	*part1;
	char	*new_entry;
	int		var_len;
	int		i;

	part1 = ft_strjoin(var, "=");
	new_entry = ft_strjoin(part1, new_val);
	free(part1);

	var_len = ft_strlen(var);
	i = 0;
	while ((*envp)[i] != NULL)
	{
		if (ft_strncmp((*envp)[i], var, var_len) == 0 \
		&& (*envp)[i][var_len] == '=')
		{
			free((*envp)[i]);
			(*envp)[i] = new_entry;
			printf("%s\n", (*envp)[i]);
			return ;
		}
		i++;
	}
	free(new_entry);
}




int	ft_cd(char **cmd, char ***envp)
{
	char		cwd[BUFSIZ];
	char		*new_dir;
	static char	*old_pwd;
	char		*tmp_pwd;

	if (!old_pwd)
	{
		old_pwd = getenv("OLDPWD");
	}
	if (cmd[1] == NULL || (cmd[1][0] == '-' && cmd[1][1] == '-'))
	{
		getcwd(cwd, sizeof(cwd));
		old_pwd = ft_strdup(cwd);
		chdir(getenv("HOME"));
	}
	else if(cmd[1][0] == '-' && cmd[1][1] == '\0')
	{
		getcwd(cwd,sizeof(cwd));
		tmp_pwd = ft_strdup(cwd);
		chdir(old_pwd);
		old_pwd = tmp_pwd;
	}
	else
	{
		getcwd(cwd, sizeof(cwd));
		old_pwd = ft_strdup(cwd);
		new_dir = ft_strjoin(cwd, "/");
		new_dir = ft_strjoin(new_dir, cmd[1]);
		if ((chdir(new_dir)) != 0)
		{
			printf("bash: cd: %s: Aucun fichier ou dossier de ce nom\n", cmd[1]);
			old_pwd = NULL;
		}
	}
	ft_setenv(envp, "OLDPWD", old_pwd);
	ft_setenv(envp, "PWD", getcwd(cwd, sizeof(cwd)));
	return (1);
}
