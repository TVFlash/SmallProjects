#include<stdio.h>
#include<stddef.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[])
{

        FILE *infile;
        FILE *outfile;
        int pos = 0, ch;
        char c;
        char fileName[64], usr[32], chown[32];

        //Clear old dirs 
        system("rm -rf config coremods mods lib Chocolate ./jar/*");

        strcpy(fileName, "unzip ");
        strcat(fileName, argv[1]);
        system(fileName);

        //Create a temp file and past the user ID into it
        outfile = fopen("temp.txt", "w");
        system("stat -c %U server.log > temp.txt");
        fclose(outfile);

        //Open temp file and retreive ID
        infile = fopen("temp.txt", "r");
        int ret = fscanf(infile, "%s %c",usr,&c);
        fclose(infile);
        system("rm temp.txt");

        //Queue up the chown
        strcpy(chown, "chown -R ");
        strcat(chown, usr);
        strcat(chown, ":");
        strcat(chown, usr);
        strcat(chown, " *");
        system(chown);

        //Patch user file perms
        system("chmod -R a+r+x *");

        //Mission success
        return 0;
}


