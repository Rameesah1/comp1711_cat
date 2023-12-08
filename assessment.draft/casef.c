 /* case 'F': {

                int startofDuration = -1;
                int endofDuration = -1;
                //int currentDuration = 0;
                int startofLong = -1;
                int endofLong = -1;
                int longestDuration = 0;

                for(int i = 0; i < records; i++) {

                    if(Fitnessdata[i].steps > 500) {   //if the steps are above 500 then if:   
                       if (startofDuration == 0) { //if the start of the duration is still 0 which means it had finished reading the steps from the condition above and ready to look for next one, or it hasn't found a record yet with this condition... then:
                        startofDuration = Fitnessdata[i].time;  //then update the current duration to that current time read
                       }
                       endofDuration = Fitnessdata[i].time;
                    
                    }  
                    else {

                    if (startofDuration != 0 ) {  //condition to check when the long period ends
                         currentDuration = endofDuration - startofDuration;
                         if (currentDuration > longestDuration) {
                            longestDuration = currentDuration;  //update new value as this is the new longest duration
                            startofLong = startofDuration;
                            endofLong = endofDuration;
                    
                    }
                    startofDuration = 0;

                }
            }
        }
        

                        printf("Start of longest period: %s, End of longest period %s\n", startofLong, endofLong);

                    }

                    } 
                    break;  */
                    

                   


                    

                
                 
                
