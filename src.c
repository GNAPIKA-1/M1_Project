#include <stdio.h>
#include <time.h>
#include <math.h>

/*define the Functions*/
/*it defines the seconds per minute time, minutes per hour time and hours per day*/ 

#define SECS_PER_MIN 60
#define MINS_PER_HR 60
#define HRS_PER_DAY 24

/*define Time*/ 

#define TIME_TYPE unsigned long 

/*now let us know the Time Copmlexity of assumed program*/

void updateTimes();
void initTimes() ;

void printTime (TIME_TYPE timeInit) ;

TIME_TYPE start, end;

/*let the assumed program be 'area of circle' as following*/

int main (const char agc, char* agv[]) { 
    
        
        initTimes();
                area_circle();
                
                updateTimes();
                printTime(end-start);
        
        return 0;
}

/*update time*/

void updateTimes() {
        end = time(0);
} 


void area_circle()
{
       float r, area; 
       
       /* let us assume radius of two or three digit number for better results */
       
        printf("radius of circle:  ") ; 
        scanf("%f", & r) ;
        
        /* area of circle */
        
        area=3.14*r*r;
        printf("area of circle: %f \n",area);
}

/*start time*/

void initTimes()
{
        start = time(0); 
        end = start;
}


void printTime (TIME_TYPE timeInit) 
{
    
        /* Declarations */
        
        TIME_TYPE time = timeInit;
        int days, hrs, mins, secs;
        int timeDif = 0;
        
        /* assigning, reassigning remaining secs to 'time' */
        /* days */
        
        timeDif = (SECS_PER_MIN *
                                MINS_PER_HR *
                                HRS_PER_DAY);
        days = (time/timeDif);
        time -= timeDif*days;
        
        /* Hrs */
        
        timeDif = (SECS_PER_MIN *
                                MINS_PER_HR);
        hrs = (time/timeDif);
        time -= timeDif*hrs;
        
        /* Mins */
        
        timeDif = (SECS_PER_MIN);
        mins = (time/timeDif);
        time -= timeDif*mins;
        
        /* Secs */
        
        secs = time;
        
        /* check for validity, then print.
         * also print error if need */
         
        if (!(secs < 60 && secs >= 0 &&
                        mins < 60 && mins >= 0 &&
                        hrs < 24 && hrs >= 0 )) {
                printf ("ERROR! TIME FORMAT SCREWY!\n");
        }
        
        printf ("Total time (s): %u\n %2dd %2dh %2dm %2ds\n", timeInit, 
                        days, hrs, mins, secs);
}