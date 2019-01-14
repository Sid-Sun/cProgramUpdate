//
// Created by sids on 1/9/19.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int upgrade(char *argv[],char versionNumber[]);
int main(int argc, char *argv[]){
    char currentVersionNumber="v1.0.0";
    upgrade(argv,currentVersionNumber); //call it if there is an upgrade argument provided
    return 0;
}
int upgrade(char *argv[],char versionNumber[]){
    char command[300]; //make it larger than required to idiot-proof against users calling command with a long argument {argv[0])
    sprintf(command, "export currentlyInstalledVersion=%s; export calledCommand=%s; $(curl -s {upstream upgrade script link} > /tmp/upgradeScript); bash /tmp/upgradeScript; rm -rf /tmp/upgradeScript",versionNumber,argv[0]); //argv[0] gives the argument of the program & version number is current version number
    system(command);
    return 0;
}