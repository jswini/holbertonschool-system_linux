#include "signals.h"
/**
* message - prints the message required by the instructions
* @sig: signal number to print
*
* Return: void
*/
void message(int sig)
{
	printf("Gotcha! [%d]\n", sig);
	fflush(stdout);
}
/**
* handle_signal - this is a signal handler for task 0 of 0x00-signals
*
* Return: integer 0 for success, -1 for failure
*/
int handle_signal(void)
{
	sig_t my_signal = signal(SIGINT, message);

	if (my_signal == SIG_ERR)
		return (-1);

	return (0);
}
