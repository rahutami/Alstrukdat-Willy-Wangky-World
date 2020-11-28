#include "saveload.h"

void load(){
    struct dirent *entries;  // Pointer for directory entry 
    char* directory = "../../Save";
    char namelist[10][10];

    DIR *dr = opendir(directory); 
  
    if (dr != NULL)  // opendir returns NULL if couldn't open directory 
    {
        int i = 0;
        entries = readdir(dr);
        entries = readdir(dr);
        if((entries = readdir(dr)) != NULL){
            printf("Pilih user:\n");
            printf("%s\n", entries->d_name); 
            namelist[i] = entries->d_name;
            i++;
        }
        while ((entries = readdir(dr)) != NULL) 
            printf("%s\n", entries->d_name); 
            namelist[i] = entries->d_name;
            i++;
        closedir(dr); 
    } 

    STARTKATA();
}

//gcc driver.c saveload.c ../mesinkar/mesinkar.c ../mesinkata/mesinkata.c -o test