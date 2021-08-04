#include <stdio.h>
#include <stdlib.h>

int main()
{
    char step;
    char number_called[9];
    float charge[5][3]={0.1,0.06,0.02
                        ,0.25,0.15,0.05
                        ,0.53,0.33,0.13
                        ,0.87,0.47,0.17
                        ,1.44,0.8,0.3};
    while(scanf("%c",&step)){
        if(step == '#')
            break;
        scanf("%s",number_called);
        int start_hour,start_minute,end_hour,end_minute;
        int time_day,time_eve,time_night;
        time_day = 0;
        time_eve = 0;
        time_night = 0;
        scanf("%d %d %d %d",&start_hour,&start_minute,&end_hour,&end_minute);
        float cost_day,cost_eve,cost_night;
		cost_day = 0;
        cost_eve = 0;
        cost_night = 0;
        int charge_step = step - 'A';
        if(end_hour < start_hour || (end_hour== start_hour) && end_minute < start_minute )
                end_hour += 24;
        int next_hour;
        for(next_hour=start_hour;end_hour>next_hour;next_hour++){
            if(next_hour%24>=22 || next_hour%24 < 8){
                cost_night += (60-start_minute)*charge[charge_step][2];
                time_night += 60-start_minute;
                start_minute = 0;
            }
            else if(next_hour%24>=18){
                cost_eve += (60-start_minute)*charge[charge_step][1];
                time_eve += 60-start_minute;
                start_minute = 0;
            }
            else if(next_hour%24>=8){
                cost_day += (60-start_minute)*charge[charge_step][0];
                time_day += 60-start_minute;
                start_minute = 0;
            }
        }
        if(end_hour%24>=22 || next_hour%24 < 8){
            cost_night += (float)(end_minute)*charge[charge_step][2];
            time_night += end_minute;
            end_minute = 0;
            if(start_hour == end_hour){
                time_night -= start_minute;
                cost_night -= (float)(start_minute)*charge[charge_step][2];
            }
        }
        else if(end_hour%24>=18){
            cost_eve += (float)(end_minute)*charge[charge_step][1];
            //printf("charge[1][charge_step]:%f",charge[charge_step][1]);
            time_eve += end_minute;
            end_minute = 0;
            if(start_hour == end_hour){
                time_eve -= start_minute;
                cost_eve -= (float)(start_minute)*charge[charge_step][1];
            }
        }
        else if(end_hour%24>=8){
            cost_day += (float)(end_minute)*charge[charge_step][0];
            time_day += end_minute;
            end_minute = 0;
            if(start_hour == end_hour){
                time_day -= start_minute;
                cost_day -= (float)(start_minute)*charge[charge_step][0];
            }
        }
        printf("%10s%6d%6d%6d%3c%8.2f\n",number_called,time_day,time_eve,time_night,step,cost_day+cost_eve+cost_night);
        char c = getchar();
    }
    return 0;
}
