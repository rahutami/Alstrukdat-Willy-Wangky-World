/* file : build.h
merupakan bagian preparation phase
yang menampilkan commad BUILD
*/

#include "../wahana/wahana.h"
#include "../point/point.h"
#include "../player/player.h"
#include "../stack/stackt.h"
#include <stdio.h>

void ProsedureBuild(POINT Pos, ListWahanaD *L);
// funsgi pembantu

void CommmandBuild();
// funsi yang dipanggil pada command