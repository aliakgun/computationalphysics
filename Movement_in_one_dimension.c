/*
**************************************************
*Program description                             *
*================================================*
* Due to the forward derivative velocity and     *
*position of the particle in one dimension can be*
*represented as:                                 *
*F=ma,a=F/m                                      *
*a=dv/dt>>>>>>>>vi=((vi+1)-vi)/h                 *
*v=dx/dt>>>>>>>>vi=((xi+1)-xi)/h                 *
*V(i+1)=Vi+(Fi/m)*h, h is the time step.         *
*x(i+1)=xi+Vi*h                                  *
*                                                *
*Program Requirements                            *
*================================================*
*1)Ýnitial velocity and position.                *
*2)Time step.                                    *
*3)Force.                                        *
*4)Mass.                                         *
*                                                *
*Program Algorithm                               *
*================================================*
*1)Get the initial velocity and position of the  *
*particle.                                       *
*2)Get the h(time step) and time interval.       *
*3)Get the F and m.                              *
*4)Calculate the x(i+1) and V(i+1)               *
*5)Print them to the screen.                     *
*                                                *
*In the future                                   *
*================================================*
*Print the v and x to the separate files.        *
*External force menu                             *
*Please chose the force acting to the particle:  *
*1)-kx                                           *
*2)x                                             *
*3)x^2                                           *
*.                                               *
*.                                               *
*.                                               *
*================================================*
*Last change 10.02.2019                          *
**************************************************
*/
#include<stdio.h>
typedef struct{
    double initial_position,initial_velocity,time_step,time_interval,mass,spring_constant,position,velocity,force;//spring_constant for harmonic osilator.
}particle_t;
void driver_f(particle_t *particle);//This function interacts with the user.
void force_f(particle_t *particle);//External force function.
void velocity_f(particle_t *particle);//Calculates velocity of the particle
void position_f(particle_t *particle); //Calculates position of the particle
void prints_f(particle_t *particle);//This function prints velocity and position
int main(){
    particle_t particle;
    driver_f(&particle);
    prints_f(&particle);
}
void driver_f(particle_t *particle){
    printf("Velocity and position calculator for 1 dimensional particle system. F=-kx default\n");
    printf("Please enter the initial position of the particle.\n");
    scanf(" %lf",&(*particle).initial_position);
    printf("Please enter the initial velocity of the particle.\n");
    scanf(" %lf",&(*particle).initial_velocity);
    printf("Please enter the time step of the movement.\n");
    scanf(" %lf",&(*particle).time_step);
    printf("Please enter the time interval of the movement.\n");
    scanf(" %lf",&(*particle).time_interval);
    printf("Please enter the mass of the particle\n");
    scanf(" %lf",&(*particle).mass);
    printf("Please enter the spring constant(k)\n");
    scanf(" %lf",&(*particle).spring_constant);
}
void force_f(particle_t *particle){
    ((*particle).force)=-((*particle).spring_constant)*((*particle).position);
}
void velocity_f(particle_t *particle){
    force_f(particle);
    ((*particle).velocity)=((*particle).velocity)+(((*particle).force)/((*particle).mass))*((*particle).time_step);
}
void position_f(particle_t *particle){
    ((*particle).position)=((*particle).position)+((*particle).velocity)*((*particle).time_step);
}
void prints_f(particle_t *particle){
    (*particle).position=((*particle).initial_position);
    (*particle).velocity=((*particle).initial_velocity);
    for(double i=0;i<=(*particle).time_interval;i=i+(*particle).time_step){
            position_f(particle);
            force_f(particle);
            velocity_f(particle);

            printf("force is%lf, position is %lf, velocitiy is %lf time is %lf\n",(*particle).force,(*particle).position,(*particle).velocity,i);
            //printf("%lf  %lf  %lf %lf\n",(*particle).force,(*particle).position,(*particle).velocity,i);

    }
}

