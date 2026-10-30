#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define lx 50
#define ly 50 //Dimensions of the box
#define drand ( ( double ) rand () /RAND_MAX ) //Random number between 0 and 1

typedef struct part{
	double x;
	double y;
	double vx;
	double vy;
}*p,q;

double dist(double x1,double y1,double x2,double y2){
	double deltax,deltay;
	deltax=x2-x1;
	deltay=y2-y1;
	return(sqrt(deltax*deltax+deltay*deltay));
	printf("%f",sqrt(deltax*deltax+deltay*deltay));
}

int main(){
	struct part *p;
	struct part q;
	int i,j,k,nsteps=1000,np=0,coll;
	int l;
	double r=0.5;
	p=calloc(nsteps,sizeof(struct part));

	for (i=0;i<nsteps;i++){
		// Creation of a new particle with random position and speed
		q.x=drand*lx;
		q.y=drand*ly;
		q.vx=drand*2-1;
		q.vy=drand*2-1; 
		
		for (j=0;j<np;j++){
			// Moving the particles and changing their directions if they go outside the boundaries
			p[j].x+=p[j].vx; 
			p[j].y+=p[j].vy;
			if (p[j].x>=lx || p[j].x<=0) p[j].vx=-p[j].vx; 
			if (p[j].y>=ly || p[j].y<=0) p[j].vy=-p[j].vy;
			}			
		
		coll=0;
		for (j=0;j<np;j++){ 
			// Sees if the new particle has collided with an existent one
			if (dist(q.x,q.y,p[j].x,p[j].y)<2*r && coll==0) { 
				printf("COLLISSION ");
				//If ithey collided, both of them disappear
				coll++;
				p[k]=p[np-1]; np--;
			}
		}
			
		if(coll==0) { //If the new particle did not collide, it is added as a new one
			np++;
			p[np].x=q.x; 
			p[np].y=q.y;
			p[np].vx=q.vx;
			p[np].vy=q.vy;
		}

		// Checking for collisions between existing particles
		for (k=0; k<np; k++){
			for (l=k+1; l<np; l++){
				if (dist(p[k].x,p[k].y,p[l].x,p[l].y)<2*r){
					p[l] = p[np-1]; np--;   
					p[k] = p[np-1]; np--;
					k--;  
					coll++;
					printf("DOUBLE COLLISSION ");
				}
			}	
		}
		
	printf("%i Particles\n",np);
	printf("\n");
}
printf("Final number of particles %i",np);

return(0);
}		
