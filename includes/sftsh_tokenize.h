/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sftsh_tokenize.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 20:16:27 by sescolas          #+#    #+#             */
/*   Updated: 2017/04/13 12:56:19 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SFTSH_TOKENIZE_H
# define SFTSH_TOKENIZE_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

char	**tokenize(char *command);

#endif
