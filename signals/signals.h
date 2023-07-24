#ifndef SIGNALS_H
#define SIGNALS_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>

int handle_signal(void);
void message(int sig);

#endif /*SIGNALS_H*/
