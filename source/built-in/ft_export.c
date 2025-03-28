/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpa <jimpa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 14:12:26 by jimpa             #+#    #+#             */
/*   Updated: 2025/03/28 17:58:07 by jimpa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
//verifie si le nom de la variable d'environnement est valable
//car le nom d'un env_var ne peut pas commencer par un chiffre
//mais peut commencer par "_" ou une lettre

char **ft_array_add(char **array, const char *str)
{
    int count = 0;
    while (array[count])
        count++;

    char **new = malloc((count + 2) * sizeof(char *));
    if (!new)
        return (NULL);

    for (int i = 0; i < count; i++)
        new[i] = array[i];  // Recopier les anciennes valeurs
    new[count] = ft_strdup(str);  // Ajouter la nouvelle
    new[count + 1] = NULL;  // Terminer le tableau

    free(array);  // Libérer l'ancien tableau
    return (new);
}

void print_sorted_env(char **envp)
{
	(void)envp;

	printf("comming soon\n");
}


int	is_valid_id(char *str)
{
	int i;

	i = 1;
	if(!str || !*str || (!isalpha(*str) && *str != '_'))
		return (0);
	while (str[i])
	{
		if(!isalnum(str[i]) && str[i] != '_')
			return (0);
		i++;
	}
	return (1);
}
// cmd doit contenir le prompt sans le word "export" pour fonctionner
int ft_export(char **cmd, char ***envp)
{
	int i;
	//int j;
	//int count;
	char *egal;
	int var_len;
	char *var_name;
	//char **new_env;

	if(!cmd[1]) // export sans argument 
	{
		//doit seulement afficher toutes les var
		// (peut etre dans l'ordre alphabetique)
		print_sorted_env(*envp);
		return (1);
	}
	egal = ft_strchr(cmd[1], '=');
	var_len = egal ? (size_t)(egal - cmd[1]) : ft_strlen(cmd[1]);
	var_name =ft_substr(cmd[1], 0, var_len);
	if(!is_valid_id(var_name))
	{
		ft_putstr_fd("export: not a valid identifier\n", STDERR_FILENO);
		free(var_name);
		return (0);
	}
	i = 0;
	while((*envp)[i])
	{
		if(ft_strncmp((*envp)[i], var_name, var_len) == 0 && (*envp)[i][var_len] == '=')
		{
			free((*envp)[i]);
			(*envp)[i] = ft_strdup(cmd[1]);
			free(var_name);
			return (1);
		}
		i++;
	}
	*envp = ft_array_add(*envp, cmd[1]);
	free(var_name);
	return (1);
}
	












	/* i = 0;
	if((egal = ft_strchr(cmd[1], '=')))
	{
		//1) savoir si la var existe deja (en verifiant si nom = legit) (peut etre split avec le "=" mais pour l instant pas besoin)
		//2) si oui la metre a jour
		//3) si non creer nouvelle
		var_len = egal - cmd[1];
		var_name = malloc(sizeof(char) * var_len + 1);
		ft_strlcpy(var_name, cmd[1], var_len);
		while(envp[i])
		{
			if (ft_strncmp(envp[i], var_name, var_len) == 0 && envp[i][var_len] == '=')
			{
				break; // break interdit!   trouver une autre manière de retenir le bon "i"
			}
			i++;
		}
		if(envp[i])
		{
			free(envp[i]);
			envp[i] = ft_strdup(cmd[1]);
		}
		else
		{
			count = 0;
			while (envp[count])
				count++;
			new_env = malloc((count + 2) * sizeof(char *));
			j = 0;
			while (j < count)
			{
				new_env[j] = envp[j];
				j++;
			}
			new_env[count] = ft_strdup(cmd[1]);
			new_env[count + 1] = NULL;
			//free(envp);
			envp = new_env;
		}
	}
	else si il n y a pas de "=" dans la commande */
	