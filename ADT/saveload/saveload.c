#include "saveload.h"
#include <string.h>

void load(){
    struct dirent *entries;  // Pointer for directory entry 
    char directory[50] = "../../Save";
    boolean found = false;
    char* tempdir;

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
        } while (entries != NULL && !found);
        closedir(dr);

        if(!found){
            printf("User tidak ada\n");
            STARTKATA();
        }
    }
    strcat(directory, "/");
    strcat(directory, entries->d_name);
    printf("%s\n", directory);

    tempdir = directory;
    strcat(tempdir, "/");
    strcat(tempdir, "player.txt");
    printf("%s\n", tempdir);
    STARTFILE(tempdir);
    SalinKataFile();
    CopyKata(CKata, &(Player.Name));
    SalinKataFile();
    X(Player) = convToInt(CKata);
    SalinKataFile();
    Y(Player) = convToInt(CKata);
    SalinKataFile();
    MapNum(Player) = convToInt(CKata);
    SalinKataFile();
    int Jam = convToInt(CKata);
    SalinKataFile();
    int Menit = convToInt(CKata);
    CJam(Player) = MakeJAM(Jam, Menit);
    SalinKataFile();
    Money(Player) = convToInt(CKata);
    SalinKataFile();
    Day(Player) = convToInt(CKata);

    printf("Player Name: ");
    PrintKata(NamaPlayer(Player));
    printf("\n");
    TulisPOINT(Position(Player));
    printf("\nMapnum:%d\nDay:%d\n", MapNum(Player), Day(Player));
    TulisJAM(CJam(Player));
    printf("\nMoney: %d\n", Money(Player));
}

// gcc driver.c ../point/point.c saveload.c ../jam/jam.c ../player/player.c ../mesinkar/mesinkar.c ../mesinkata/mesinkata.c -o test