/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrimonte <rrimonte@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 17:39:51 by rrimonte          #+#    #+#             */
/*   Updated: 2024/04/28 12:15:50 by rrimonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_check_semicolon(char *start, t_data *g_data, t_env	*envp)
{
	int	i;

	i = 0;
	while (start[i])
	{
		if (start[i] == ';')
			ft_error(0, g_data, envp);
		if (start[i] == '\\')
			ft_error(5, g_data, envp);
		i++;
	}
}

void	ft_check_quotes(t_data *g_data, t_env *envp)
{
	int	i;
	int	count;
	int	count2;
	int	qt;
	int	qtd;

	i = 0;
	ft_init_check_quotes(&count, &count2, &qt, &qtd);
	while (g_data->cmd_lst->cmdaux[i])
	{
		if (g_data->cmd_lst->cmdaux[i] == '"' && qt == 0)
		{
			count++;
			qtd = ft_quotes(qt, qtd, 0);
		}
		else if (g_data->cmd_lst->cmdaux[i] == '\'' && qtd == 0)
		{
			count2++;
			g_data->cmd_lst->bvar = 1;
			qt = ft_quotes(qt, qtd, 1);
		}
		i++;
	}
	if (count % 2 != 0 || count2 % 2 != 0)
		ft_error(4, g_data, envp);
}

void	check_tag(t_data *g_data, char *end)
{
	if (*end == '|')
		g_data->cmd_lst->tag = 2;
	else if (*end == '>')
	{
		end++;
		if (*end == '>')
			g_data->cmd_lst->tag = 3;
		else
			g_data->cmd_lst->tag = 4;
	}
}

char	*check_if_pipe(t_data *g_data, char *start, char	*end)
{
	const char	delimiters[] = "<|>";

	start = end;
	start = skip_spaces(start);
	if (ft_strchr(delimiters, *start) != NULL)
	{
		if (*start == '|')
		{
			g_data->cmd_lst->tag = 2;
			g_data->bsection++;
		}
	}
	return (start);
}

void	check_marks(t_data *g_data, int option)
{
	if (option == 0)
	{
		if (g_data->cmd_lst->bcomillas == 0
			&& g_data->cmd_lst->bcomillas2 == 0)
			g_data->cmd_lst->bcomillas = 1;
		else
			g_data->cmd_lst->bcomillas = 0;
	}
	else
	{
		if (g_data->cmd_lst->bcomillas2 == 0
			&& g_data->cmd_lst->bcomillas == 0)
			g_data->cmd_lst->bcomillas2 = 1;
		else
			g_data->cmd_lst->bcomillas2 = 0;
	}
}
