/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sftsh_lexer.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 09:41:47 by sescolas          #+#    #+#             */
/*   Updated: 2017/05/30 09:41:49 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SFTSH_LEXER_H
# define SFTSH_LEXER_H

# include <unistd.h>
# include <stdlib.h>

char	*expand_tilde(char *path, char **envp);
char	*expand_vars(char *str, char **envp);
char	*expand_dots(char *str);
void	expand_tokens(char **tokens, char **envp);
char	**tokenize(char *cmd_str);

#endif
