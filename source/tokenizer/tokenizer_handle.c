/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_handle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadikaj <lsadikaj@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:21:49 by lsadikaj          #+#    #+#             */
/*   Updated: 2025/03/28 16:39:53 by lsadikaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// Gère les charactères parenthèses ( ) et ajoute un token correspondant
int	handle_parenthesis(t_token **tokens, char *input)
{
	char			*paren;
	t_token_type	type;

	paren = ft_substr(input, 0, 1);
	if (!paren)
		return (0);
	if (input[0] == '(')
		type = TOKEN_LPAREN;
	else
		type = TOKEN_RPAREN;
	add_token(tokens, paren, type);
	free(paren);
	return (1);
}

// Gère les opérateurs (|, <, >, etc.) et ajoute un token correspondant
int	handle_operator(t_token **tokens, char *input)
{
	int				len;
	char			*op;
	t_token_type	type;

	len = operator_length(input);
	op = ft_substr(input, 0, len);
	if (!op)
		return (0);
	type = get_operator_type(op);
	add_token(tokens, op, type);
	free(op);
	return (len);
}

// Gère une chaîne entre guillemets et l’ajoute à la liste des tokens
int	handle_quotes(t_token **tokens, char *input)
{
	char	quote;
	int		len;
	char	*word;

	quote = input[0];
	len = 1;
	while (input[len] && input[len] != quote)
		len++;
	if (input[len] == quote)
	{
		word = ft_substr(input + 1, 0, len - 1);
		if (!word)
			return (-1);
		add_token(tokens, word, TOKEN_WORD);
		free(word);
		return (len + 1);
	}
	ft_printf("minishell: syntax error: unclosed quote\n");
	return (-1);
}

// Gère un mot simple (non cité) et l’ajoute à la liste des tokens
int handle_word(t_token **tokens, char *input)
{
	int		len;
	char	*word;

	len = 0;
	while (input[len] && !is_space(input[len]) &&
		!is_operator_str(&input[len]) &&
		input[len] != '"' && input[len] != '\'' &&
		input[len] != '(' && input[len] != ')')
		len++;
	if (len <= 0)
		return (0);
	word = ft_substr(input, 0, len);
	if (!word)
		return (0);
	add_token(tokens, word, TOKEN_WORD);
	free(word);
	return (len);
}
