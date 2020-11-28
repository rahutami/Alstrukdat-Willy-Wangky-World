#include <stdio.h> 
#include <dirent.h> 
  
int main() 
{ 
    struct dirent *de;  // Pointer for directory entry 
  
    // opendir() returns a pointer of DIR type.  
    DIR *dr = opendir("../../Save"); 
  
    if (dr != NULL)  // opendir returns NULL if couldn't open directory 
    { 
        while ((de = readdir(dr)) != NULL) 
            printf("%s\n", de->d_name); 
        closedir(dr); 
    } 
  
    // Refer http://pubs.opengroup.org/onlinepubs/7990989775/xsh/readdir.html 
    // for readdir()     
    return 0; 
} 