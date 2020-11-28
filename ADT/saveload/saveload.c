#include "saveload.h"
#include <string.h>

void load(){
    struct dirent *entries;  // Pointer for directory entry 
    char* directory = "../../Save";
    char* namelist[10];
    boolean found = false;

    DIR *dr = opendir(directory); 
  
    if (dr != NULL)  // opendir returns NULL if couldn't open directory 
    {
        entries = readdir(dr);
        entries = readdir(dr);
        if((entries = readdir(dr)) != NULL){
            printf("Pilih user:\n");
            printf("%s\n", entries->d_name);
        }
        while ((entries = readdir(dr)) != NULL){
            printf("%s\n", entries->d_name);
        }
    } 

    closedir(dr); 

    STARTKATA();

    while(!found){
        DIR *dr = opendir(directory);
        entries = readdir(dr);
        do{
            if(IsKataSama(entries->d_name)) found = true;
            else entries = readdir(dr);
        } while (entries != NULL && IsKataSama(entries->d_name));
        closedir(dr);

        if(!found){
            printf("User tidak ada\n");
            STARTKATA();
        }
    }
    strcat(directory, )
}

//gcc driver.c saveload.c ../mesinkar/mesinkar.c ../mesinkata/mesinkata.c -o test