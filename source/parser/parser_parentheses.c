/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_parentheses.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadikaj <lsadikaj@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 15:00:00 by lsadikaj          #+#    #+#             */
/*   Updated: 2025/03/28 15:00:00 by lsadikaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// Trouve la parenthèse fermante correspondante
t_token	*find_matching_paren(t_token *start)
{
	int		depth;
	t_token	*current;

	depth = 1;
	current = start->next;
	while (current && depth > 0)
	{
		if (current->type == TOKEN_LPAREN)
			depth++;
		else if (current->type == TOKEN_RPAREN)
			depth--;
		if (depth > 0)
			current = current->next;
	}
	return (current);
}

// Clone une liste de tokens entre start et end (non inclus)
t_token	*clone_tokens(t_token *start, t_token *end)
{
	t_token	*result;
	t_token	*current;

	result = NULL;
	current = start;
	while (current && current != end)
	{
		add_token(&result, current->value, current->type);
		current = current->next;
	}
	return (result);
}

// Traite une expression entre parenthèses
t_node	*parse_parenthesized_expr(t_token *tokens)
{
	t_token	*closing;
	t_token	*expr_tokens;
	t_node	*node;

	if (!tokens || tokens->type != TOKEN_LPAREN)
		return (NULL);
	closing = find_matching_paren(tokens);
	if (!closing)
		return (NULL);
	expr_tokens = clone_tokens(tokens->next, closing);
	if (!expr_tokens)
		return (NULL);
	node = parse_ast(expr_tokens);
	free_tokens(expr_tokens);
	return (node);
}
