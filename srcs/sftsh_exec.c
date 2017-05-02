/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sftsh_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 19:49:51 by sescolas          #+#    #+#             */
/*   Updated: 2017/04/20 15:31:35 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sftsh_exec.h"
#include "sftsh_types.h"

static void	print_error_execve(char *str)
{
	write(1, "psh: no such file or directory: ", 32);
	ft_putendl(str);
}

int		exec_command(t_command *command)
{
	pid_t	child_pid;
	int		status;

	if (command->builtin_id >= 0)
		return (0/*exec_builtin(command)*/);
	if (!command->path)
		print_error_execve(command->args[0]);
	child_pid = fork();
	if (child_pid < 0)
		return (1);
	if (child_pid == 0)
		execve(command->path, command->args, command->envp);
	else
		wait(&status);
	return (status);
}

static int	ex_cmd(t_command *command)
{
	if (command->builtin_id >= 0)
		return (0/*exec_builtin(command)*/);
	else
		execve(command->path, command->args, command->envp);
	return (0);
}

static int	set_read_fd(t_command *cmd, int *pipes)
{
	ft_putendl("inside set_read_fd");
	if(cmd->path && ft_strcmp(cmd->path, "|") == 0)
	{
		ft_putendl("setting stdin to pipe");
		close(pipes[0]);
		close(pipes[1]);
		return (dup2(pipes[0], STDIN_FILENO));
	}
	return (0);
}

static int	set_write_fd(t_command *cmd, int *pipes)
{
	ft_putendl("inside set_write_fd");
	if (cmd->path && ft_strcmp(cmd->path, "|") == 0)
	{
		if (cmd->next->next && cmd->next->next->path && ft_strcmp(cmd->next->next->path, "|"))
		{
			ft_putendl("setting stdout to pipe");
			close(pipes[0]);
			close(pipes[1]);
			return (dup2(pipes[1], STDOUT_FILENO));
		}
		else
		{
			close(pipes[0]);
			close(pipes[1]);
			return (dup2(1, pipes[1]));
		}
	}
	else
	{
		ft_putendl("setting stdout to pipe");
		close(pipes[0]);
		close(pipes[1]);
		return (dup2(pipes[1], STDOUT_FILENO));
	}
}

int		pipe_command(t_command *cmd, int in, int out)
{
	pid_t	child_pid;
	int		status;

	if (!cmd->path && cmd->builtin_id < 0)
	{
		print_error_execve(cmd->args[0]);
		return (-1);
	}
	if ((child_pid = fork()) < 0)
		return (-1);
	if (child_pid == 0)
	{
		/* set fds */
		close(STDIN_FILENO);
		dup2(in, STDIN_FILENO);
		close(STDOUT_FILENO);
		dup2(out, STDOUT_FILENO);
		if (cmd->builtin_id < 0)
			execve(cmd->path, cmd->args, cmd->envp);
		else
			return (0); /* execute builtin */
	}
	else
	{
		close(in);
		close(out);
		wait(&status);
		return (status);
	}
	return (0);
}

int		exec_pipe(t_command *cmd)
{
	int		pipes[4];
	int		num_commands;

	pipe(pipes);
	num_commands = 0;
	while (1)
	{
		if (!cmd || (cmd->path && ft_strcmp(cmd->path, ";") == 0))
			break ;
		++num_commands;
		if ((cmd->path && ft_strlen(cmd->path) > 1) || cmd->builtin_id >= 0)
		{
			pipe_command(cmd, dup(STDIN_FILENO), pipes[1]);
			cmd = cmd->next;
		}
		else if (cmd->path && ft_strcmp(cmd->path, "|") == 0)
		{
			if (cmd->next->next && cmd->next->next->path && ft_strcmp(cmd->next->next->path, "|") == 0)
			{
				pipe(pipes + 2);
				pipe_command(cmd->next, pipes[0], pipes[3]);
			}
			else
				pipe_command(cmd->next, pipes[0 + (num_commands % 2)], dup(STDIN_FILENO));
			cmd = cmd->next->next;
		}
		else
			break ;
	}
	return (0);
}

int		sftsh_exec(t_command *commands)
{
	t_command	*cmd;

	while ((cmd = pop_command(&commands)))
	{
		if (cmd->path && ft_strcmp(cmd->path, "exit") == 0)
			break ;
		if (cmd->next)
		{
			if (cmd->next->path && ft_strcmp(cmd->next->path, "|") == 0 && cmd->next->next)
			{
				exec_pipe(cmd);
				while (cmd && cmd->path && ft_strcmp(cmd->path, ";"))
				{
					// free_command(cmd);
					cmd = pop_command(&commands);
				}

			}
			else if (ft_strcmp(cmd->next->path, ";") == 0)
			{
				exec_command(commands);
				/* these should all be freed... */
				pop_command(&commands);
				pop_command(&commands);
			}
		}
		else 
			exec_command(cmd);
	}
	return (0);
}
