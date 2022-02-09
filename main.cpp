#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <iostream>
#include <string>

extern char *optarg;
extern int optind, opterr, optopt;

void daemonize()
{
	if (0 > chdir("/"))
	{
		printf("Error changing working directory\n");
		exit(1);
	}

 	if (0 != setsid())
 	{
 		printf("Error in setsid\n");
 		exit(1);
 	}

 	fclose(stdin);
 	fclose(stdout);
 	fclose(stderr);
}

void print_help()
{
	/* TO DO */
}

 int main(int argc, char **argv)
 {
 	
 	if (argc != 7)
 	{
 		printf("Not enough args\n");
 		print_help();
 		return -1;
 	}

 	char option;

 	std::string str_listener_ip, str_listener_port, str_directory;

	while (-1 != (option = getopt(argc, argv, "h:p:d:")))
	{
		switch (option)
		{
			case '?':
				printf("Founded incorrect option\n");
				print_help();
				return -1;
			case ':':
				printf("Missed mandatory argument of option");
				print_help();
				return -1;
			case 'h':
				str_listener_ip = optarg;
				break;
			case 'p':
				str_listener_port = optarg;
				break;
			case 'd':
				str_directory = optarg;
				break;
			default:
				printf("Unrecognized option\n");
				return -1;
		}
	}

 	pid_t pid;

 	pid = fork();

 	if (-1 == pid)
 	{
 		printf("Error forking\n");
 		return -1;
 	}
 	else if (0 == pid)
 	{
 		return 0;
 	}
 	else
 	{
		//daemonize();

 	}

 	return 0;
 }