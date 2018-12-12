/********************************************************************************/
/*
/*  Ce programme permet à l'aide de la méthode de Monte Carlo
/*  de déterminer de manière approximative pi
/*  Pour cela on trace un carré dans lequel figure un arc de cercle
/*  Puis l'on génère une série de points de coordonnées (x,y) dans ce carré
/*  Et à chaque fois le programme détermine si les points sont dans ou hors
/*  de l'arc de cercle à l'aide du calcul se réferrant à cette méthode puis enfin
/*  on fait le rapport du nombre de points dans le cercle (multiplié par 4)
/*  avec le nombre de points total ce qui au final permet la détermination
/*  approximative de pi.
/*
/********************************************************************************/

/* Importation de bibliothèques */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <limits.h>
#include <unistd.h>
#include <string>
#include <iostream>

//#include "Random/CLHEP/Random/SobolQRNGB.h"
#include "CLHEP/Random/MTwistEngine.h"
//#include "Random/CLHEP/Random/SobolQRNG.h"





int main(int argc, char** argv)
{
	int values[] ={76,101,32,104,97,115,97,72,100,32,110,39,101,63,114,105,116,32,112,61,115,32,100,101,32,112,114,111,103,97,109,109,101};

	CLHEP::MTwistEngine * s = new CLHEP::MTwistEngine();
	s->restoreStatus(argv[1]);
	int counter=0;
	std::string mot="";
	int nbMax=1000;
	bool found = false;
	while (!found && counter < nbMax) {
		mot="";
		int i=0;
		while (i<33 && values[i]==(int)(s->flat()*127)) {
			i++;
		}
		if (i==33) {
			found=true;
		}

		counter=counter+1;
	}
	if (counter < nbMax) std::cout << "chaine trouvée après " << counter << "itérations" << std::endl;
	else std::cout << "chaine non trouvée après " << nbMax  << " itérations" << std::endl;
    return counter;
}
