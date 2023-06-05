#include "types.h"
#include "stat.h"
#include "pstat.h"
#include "user.h"

void 
spin(int n) {
		int i = 0;
		int j = 0;
		int k = 0;
		for(i = 0; i < 50; ++i)
		{
			for(j = 0; j < 20000*n; ++j)
			{
				 k = j % 10;
				 k = k + 1;
			}
		}
}

void
print(struct pstat *st, int pidList[3])
{
	int i;
	int tickA, tickB, tickC;
	for(i=0;i<NPROC;i++)
	{
			if(st->pid[i] == pidList[0])
				tickA = st->ticks[i];
			if(st->pid[i] == pidList[1])
				tickB = st->ticks[i];
			if(st->pid[i] == pidList[2])
				tickC = st->ticks[i];
	}
	printf(1,"%d,%d,%d",tickA,tickB,tickC);
	printf(1,"\n");
}

int
main(int argc, char * argv[]) {

	int ticketList[3] = {10,20,30};
	int pidList[3];
	int i = atoi(argv[1]);
	//printf(1,"%d\n",i);
	struct pstat pstatus;
	pidList[0] = getpid();
	settickets(ticketList[0]);
	if(fork()==0)
	{
		pidList[1] = getpid();
		settickets(ticketList[1]);
		if(fork()==0)
		{
			pidList[2] = getpid();
			settickets(ticketList[2]);
			spin(i);
			getpinfo(&pstatus);
			print(&pstatus,pidList);
		}
	}
	spin(i);
	while(wait() > -1);
	
	exit();
	
}
