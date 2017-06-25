/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sftsh_env.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 12:33:35 by sescolas          #+#    #+#             */
/*   Updated: 2017/05/04 14:22:09 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SFTSH_ENV_H
# define SFTSH_ENV_H

char	**create_env(char ***envp);
char	**copy_env(char **envp);
void	delete_env(char ***envp);
char	*get_env(char **envp, char *val);
void	set_env(char **envp, char *key, char *val);
void	append_env(char ***envp, char *key, char *val);

#endif
