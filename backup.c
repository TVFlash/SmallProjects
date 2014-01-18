#include<stdio.h>
#include<time.h>

#define secondsToHours 3600;
/**
* Backup creates a scheduled backup for the set cycle (in hours)
* @author Tim Vincent
**/
int main(int argc, char *argv[])
{
	int cycle = atoi(argv);
	
	//Protect from bad or no input
	if(cycle < 1)
		n = secondsToHours;
	n = n * secondsToHours;

	while(1 == 1)
	{ 	
		sleep(cycle);
		runBackup();
	}
}


int runBackup()
{
	system("echo Creating a backup...");
	system("zip -R Backup.zip ./* ");
	system("echo Done!");
}
