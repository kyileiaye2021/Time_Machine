//Kyi Lei Aye
//CS002_77215:Midterm2_Prompt_3
//Going_Forward_With_Time_Machine
//Instructor:Hilario_Balajadia
//Last_Edited_Date:11/1/2022

#include <iostream>
const int MAXHOUR = 24;
const int MAXMINUTE = 60;
//declaring a function
int time();
int main(){
    using namespace std;
    
    char ans;
    do{
        //Testing function in driver program
        int timeAhead = time();
        cout << "You will be " << timeAhead << " minutes ahead of your start time." << endl;
        cout << "Do you want to do this again?: ";
        cin >> ans;
    }while(ans == 'Y' || ans == 'y');

    return 0;
}

/**
 * @brief Return difference of start time and end time// 
 * To break down the military notation for hour difference, the difference between start and end time will be divided by 100//
 * For minutes, the military notation will be broken down by using modulo operator//
 * For going forward in time during a day, the time would be difference in minutes//
 * For going forward to the time of following day, the time would be subtracted from midnight 
 * and add that time amount to the time amount of another day
 * @return int 
 */
int time(){
    using namespace std;

    int startTime, endTime,hours, minutes;

    cout << "Your time machine is capable of going forward in time up to 24 hours." << endl;
    cout << "Please write both start time and end time in a military notation such as "
            << "0000 for midnight and 2359 for one minute before midnight" << endl;
    cout << "Start Time: ";
    cin >> startTime;
    cout << "End Time: ";
    cin >> endTime;

    //For the time which goes ahead to the following day or up to 24 hr
    if(startTime >= endTime){
        //if the startTime minutes are greater than endTime minutes, subtract startTime minute from 60min.
        //Then add the subtracted amount to the endTime minutes
        //For eg. 2350 --> 0400 = 250min
        if((startTime % 100) > (endTime % 100)){
            hours = (((MAXHOUR - (startTime / 100)) + (endTime / 100)) - 1 ) * 60;
            minutes = (MAXMINUTE - (startTime % 100)) + (endTime % 100); 
            return (hours + minutes);
        }
        //if the endTime minutes are greater than or equal to the startTime minutes, subtract startTime minutes fom endTime minutes
        //For eg. 2200 --> 2200 = 1440min
        //For eg. 0930 --> 0850 = 1400min
        else{
            hours = ((MAXHOUR - (startTime / 100)) + (endTime / 100)) * 60;
            minutes = (endTime % 100) - (startTime % 100);
            return (hours + minutes);
        }
    }

    //calculating the time difference that happen during a day
    else{
        //for time difference which is less than 1 hr
        if(endTime - startTime < 100){
            //if endTime minute is greater than 0, 
            if((endTime % 100) > 0){
                //if endTime minutes are less than startTime minutes, the startTime minutes would be first subtracted from 60min
                //then minutes of startTime and endTime will be added to become time difference
                //For eg. 0345 --> 0415 = 30min
                if((endTime % 100) < (startTime % 100)){
                    minutes = (endTime % 100) + (MAXMINUTE - (startTime % 100));
                    return minutes;
                }
                //if endTime minutes are greater than or equal to startTime minutes, 
                //the startTime minutes would be subtracted from endTime minutes which become the time difference
                //For eg. 0300 --> 0345 = 45min
                else{
                    minutes = (endTime % 100) - (startTime % 100);
                    return minutes;
                }
            }
            //if the minute of endTime is 0, the startTime minute will be subtracted from 60min which become time difference
            else{
                minutes = MAXMINUTE - (startTime % 100);
                return minutes;
            }
        }
        //for the time difference which is more than 1 hr
        else{
            hours = ((endTime / 100) - (startTime / 100)) * 60;
            minutes = ((endTime % 100) - (startTime % 100));
            return (hours + minutes);
        }
    }
}