/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 15:37:06 by tda-silv          #+#    #+#             */
/*   Updated: 2022/09/03 13:10:55 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static t_data	g_d;
static void	handler(int signal);

int	main(void)
{
	int					i;

	int					j;
	int					nb_ten;
	char				stock_octet[9];
	t_li				*li_cpy;
	
	int					nb_of_zero;
	int					pid_server;
	int					pid_client;
	struct sigaction	start_signal;
	
	stetup_struct(&g_d);
	
	start_signal.sa_handler = &handler;
	start_signal.sa_flags = 0;
	sigemptyset(&start_signal.sa_mask);
	
	i = 0;
	nb_ten = 1;
	nb_of_zero = 0;
	pid_server = getpid();
	pid_client = 0;
	printf("\033[36mPid server : \033[36;04m%d\033[00m\n", pid_server);
		
	while (1)
	{
		sigaction(SIGUSR1, &start_signal, 0);
		sigaction(SIGUSR2, &start_signal, 0);

		if (g_d.i_zero == 8)
		{
			printf("\033[32mEND OF FIRST COMMUNICATION - Pid of client received\033[00m\n");
			g_d.on_off = 0;
			g_d.i_zero = 0;

//			{	
				j = 0;
				stock_octet[8] = 0;
				li_cpy = g_d.list_bit;
				printf("\033[33;02mPid client in binary :\033[00m\n");
				while (li_cpy)
				{
					if (j == 8)
					{
						j = 0;
						printf("\033[00;02m(%s)\033[00m", stock_octet);
						printf("%c", conv_oct_int(stock_octet));
						
						printf("   %d = (%d - '0') * %d\n", pid_client, conv_oct_int(stock_octet), nb_ten);
						pid_client += (conv_oct_int(stock_octet) - '0') * nb_ten;
						nb_ten *= 10;
					}
					stock_octet[j] = li_cpy->content + '0';
					printf("%d", li_cpy->content);
					li_cpy = li_cpy->next;
					j++;
				}
				printf("\n");
				printf("\033[33mPid client : \033[33;04m%d\033[00m\n", pid_client);
				j = 0;

				if (kill(pid_client, 0) == 0)
				{
					printf("\033[32;03mConnexion establised with the server\033[00m\n");	
				}
				
//			}
			
			li_clear(&g_d.list_bit);
		}
	}

	return (0);
}

/*

Le serveur doit être lancé en premier, puis afficher son PID

*/

static void	handler(int signal)
{
	if (signal == 10)
	{
		if (g_d.i_signal % 8 == 0)
			g_d.i_zero = 0;
		g_d.stock_signal_rec = 1;
		g_d.i_signal += 1;
		g_d.i_zero += 1;
		g_d.on_off = 1;
		li_add_back(&g_d.list_bit, li_new(0));
		printf("\033[34mSIGUSR1\033[34;02m received - 0   | i.zero = %d\t\t\ti.signal = %d  (%d)\033[00m\n", g_d.i_zero, g_d.i_signal,g_d.stock_signal_rec);
	}
	else if (signal == 12)
	{
		g_d.stock_signal_rec = 2;
		g_d.i_signal += 1;
		g_d.on_off = 1;
		li_add_back(&g_d.list_bit, li_new(1));
		printf("\033[35mSIGUSR2\033[35;02m received - 1\t\t\t\t\ti.signal = %d  (%d)\033[00m\n", g_d.i_signal, g_d.stock_signal_rec);
	}
}

/*

	printf("\033[34;00m ;OO nothing\n\033[00m");
	printf("\033[34;01m ;01 bold\n\033[00m");
	printf("\033[34;02m ;02 opacity \n\033[00m");
	printf("\033[34;03m ;03 italic\n\033[00m");
	printf("\033[34;04m ;04 highlighted\n\033[00m");
	printf("\033[34;07m ;07 add back\n\033[00m");
	printf("\033[34;08m ;08 ??\n\033[00m");
	printf("\033[34;09m ;09 crossed out\n\033[00m");

	printf("\033[30m 30 black\n\033[00m");
	printf("\033[31m 31 red\n\033[00m");
	printf("\033[32m 32 green\n\033[00m");
	printf("\033[33m 33 yellow\n\033[00m");
	printf("\033[34m 34 bue\n\033[00m");
	printf("\033[35m 35 magenta\n\033[00m");
	printf("\033[36m 36 cyan\n\033[00m");
	printf("\033[37m 37 grey\n\033[00m");

*/