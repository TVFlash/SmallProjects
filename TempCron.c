#include<stdio.h>
#include<time.h>

#define secondsToHours 3600;
/**
* Runs a cron job every 24 hours
**/
int main(void)
{
        int cycle = 24 * secondsToHours;

        while(1)//Don't ask c is weird
        {
                sleep(cycle);
                runCron();
        }
}


int runCron()
{
        system("echo Running Cron...");
        system("/home/YOUR/CRON/PATH/cron.php");
        system("echo Done!");
}
~
~
~
~
