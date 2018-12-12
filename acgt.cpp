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
    
	char values[]= {'A','C','G','T'};
	CLHEP::MTwistEngine * s = new CLHEP::MTwistEngine();
	s->restoreStatus(argv[1]);
	int counter=0;
	std::string mot="";
	while (mot!="GATTACA") {
		mot="";
		for (int i =0; i<7;i++){
			mot+=values[(int)(s->flat()*4)];
		}
		counter=counter+1;
	}
	
	std::cout << counter << std::endl;
    return counter;
}
