/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sftsh_env.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 12:33:35 by sescolas          #+#    #+#             */
/*   Updated: 2017/04/13 12:59:47 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SFTSH_ENV_H
# define SFTSH_ENV_H

char	*get_env(char **envp, char *val);
void	set_env(char **envp, char *key, char *val);
void	append_env(char ***envp, char *str);
char	**copy_env(char **envp);
void	restore_env(char **envp, char **copy);

#endif
