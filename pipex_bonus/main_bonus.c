/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrimonte <rrimonte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 18:02:11 by rrimonte          #+#    #+#             */
/*   Updated: 2024/05/10 22:27:17 by rrimonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

t_env	*pipex(t_data *g_data, t_env	*envp)
{
	ft_check_files(g_data, envp);
	g_data->i = 0;
	ft_backward_node(g_data);
	while (g_data->cmd_lst && g_data->cmd_lst->next != 0)
	{
		g_data->cmd_lst = g_data->cmd_lst->next;
		g_data->ncmd++;
	}
	g_data->ncmd++;
	ft_backward_node(g_data);
	g_data->i = 0;
	envp = create_pipes(g_data, envp);
	ft_free_all(g_data);
	return (envp);
}

void	ft_error_exit(int err, t_data *g_data)
{
	if (err == 0 || err == 2 || err == 4)
	{
		if (err == 0)
			perror ("incorrect number of argument");
		else if (err == 2)
			perror("incorrect outfile");
		g_data->exit_status = 1;
	}
	else if (err == 3 || err == 4)
	{
		if (err == 3)
			perror("command not found");
		else if (err == 4)
			perror("failed to execute");
		g_data->exit_status = 127;
	}
	exit (g_data->exit_status);
}

void	ft_error_quotes(int err, t_data *g_data, t_env *envp)
{
	g_data->exit_status = 1;
	perror("found forbiden char `quotes'");
	ft_free_error(g_data, err);
	ft_loop_input(g_data, envp);
}

void	ft_error(int err, t_data *g_data, t_env *envp)
{
	if (err == 0 || err == 4 || err == 5)
	{
		if (err == 0)
			perror("found forbiden char `;'");
		else if (err == 4)
			ft_error_quotes(err, g_data, envp);
		else if (err == 5)
			perror("found forbiden char `\\'");
		g_data->exit_status = 1;
	}
	else if (err == 1 || err == 2 || err == 3)
	{
		if (err == 1)
			perror("syntax error near unexpected token `|'");
		else if (err == 2)
			perror("syntax error near unexpected token `<'");
		else if (err == 3)
			perror("syntax error near unexpected token `>'");
		g_data->exit_status = 2;
	}
	ft_free_error(g_data, err);
	ft_loop_input(g_data, envp);
}
