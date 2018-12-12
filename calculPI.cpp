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

//#include "Random/CLHEP/Random/SobolQRNGB.h"
#include "CLHEP/Random/MTwistEngine.h"
//#include "Random/CLHEP/Random/SobolQRNG.h"





int main(int argc, char** argv)
{
    
    float x, y, pi;
    float i, pts_dans_cercle, pts_tot, t;
	int n=200000;
	int value=0;
    CLHEP::MTwistEngine * s = new CLHEP::MTwistEngine();

    int fs; 
    double f;
    unsigned int nbr;   
	s->restoreStatus(argv[1]);
    fs = open("./qrngb",O_CREAT|O_TRUNC|O_WRONLY,S_IRUSR|S_IWUSR);

    i=0;
    pts_dans_cercle=0;
    pts_tot=0;
    while (i<=n)
    {
    	  x=s->flat();
          y=s->flat();
          if (x*x+y*y<1)
          {
    	  		pts_dans_cercle=pts_dans_cercle+1;
          }
          pts_tot=pts_tot+1;
          i=i+1;
           
    }
	printf("estimation de pi : %4f",(4*pts_dans_cercle)/(pts_tot));     
    return 0;
}
