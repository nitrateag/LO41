#define _POSIX_SOURCE //199309L
#define _XOPEN_SOURCE 
#define _XOPEN_SOURCE_EXTENDED
#define _BSD_SOURCE 500


#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>

#include "../const.h"

int millisleep(unsigned ms)
{
  return usleep(1000 * ms);
}
  
char* itoa(int i){
  char* str = calloc(12, sizeof(char));
  sprintf(str, "%d", i);
  return str;
}

void main(int argc, char* argv[])
{

int msgDec = atoi(argv[1]);
  ////////////////TOUR DE CONTROLE
  Demande *dem = malloc(sizeof(Demande));
  while(1)
  {
    msgrcv( msgDec, (void*) dem, sizeof(Demande)-4, -3, 0);
    /*pint((int)dem->demandeur, "recieve");*/

    
    if(dem->demandeur < 0)
      break; // la mission est terminée
    
    millisleep(TEMPS_PREPARATION_DECOLLAGE);
    
    
    
    /*puts("recieve");*/
    /*kill(dem->demandeur, SIGCONT);*/
    kill(dem->demandeur, SIGUSR1);
  }


}