/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cben-bar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 13:52:20 by cben-bar          #+#    #+#             */
/*   Updated: 2022/07/19 16:54:55 by cben-bar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **envp)
{
	char			*line;
	char			**line_tab;
	t_control_parse	*parsing;
	size_t			i;
	int				q;

	parsing = NULL;
	(void)ac;
	(void)av;
//	line = "\"|<infile $cat -e $|\" $wc -l >>'$'hey ";
//	line = "\"|<infile cat -e |\" wc \'-l\' >> out << delim  | \"ls -la\" | echo \'oui\' < oui.txt hoho<<ici\'>>   \'hey ";
//	line = "cat jeanette\'fleur\' | cat  \"maman\" blurp\"Jean-Jacques\"ouioui\'non\'ici | cat \"flop\"jardin | cat $USER | cat 012$XPC_FLAGS $LGNAME$USER | cat \"soleil\"noir ";
//	line = "cat \"$?\"";
	line = "cat $SH_AUTH_SOCK $BLOP \'$USER\'$USER >> >> out| cat \"$?\"  $iXPC_FLAGS $PWD $TERM $L_CTYPE $SHLVL $iiiii $ih $pph $fl$fv cat i >> >> out2";
//	line = "\"$USER $PAGER$USER |cat\" \'$i\' \" $$merdekh\" \"$COLORFGBG\" 012$XPC_FLAGS $HOME \"$LESS$SHLVL\"";
//	line = "cat $USER | cat $?$?$?$? \"$TERM\"     ";
//	line = "ls -la";
//	line = "echo \"$USER\" | $kh ls | wc -l >>> out";
	i = 0;
	q = 0;
	printf("LINE MAIN =%s\n\n", line);
	if (first_check(line))
	{
		line_tab = ft_split_it(line, '|', i, q);
		parsing = set_pars(parsing, line_tab, envp);
		if (!printer_error(parsing))
		{	
			printf("PAS D'EXEC\n");
		}
		parsing_printer(parsing);
		cleaner(parsing);
	}
	return (0);
}
