/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sftsh_expand.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 20:48:51 by sescolas          #+#    #+#             */
/*   Updated: 2017/04/17 15:13:43 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SFTSH_EXPAND_H
# define SFTSH_EXPAND_H

char	*expand_tilde(char *path, char **envp);
void	expand_tokens(char **tokens, char **envp);

#endif
