/*
CHAMADA UPTIME - Mostra a quanto tempo o computador está ligado
*/

#include <sys/sysinfo.h>

int main (void)
{
    struct sysinfo info;
    sysinfo(&info);
    printf("Uptime (tempo em segundos desde que foi iniciado ao tempo que foi chamada a função) = %ld",info.uptime);
    printf(" segundos\n");
    return 0;
}