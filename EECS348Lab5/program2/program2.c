#include <stdio.h>

int main(){
    int score; //sets the score to 0
    do{
        // if (score == 0){
        //     return (0);
        // }
        printf("Enter 0 or 1 to STOP\nEnter the NFL score: ");
        scanf("%d", &score);
        if (score == 0){ //the reason this is added is my code will give an output if 0 is pressed (it will say 0 for each) so to prevent that, this is here
            return (0);
        }
        for (int i=0; i<=score; i=i+6){ //represents touchdown
            for (int j=0; j<=score; j=j+3){ //represents field goal
                for (int k=0; k<=score; k=k+2){ //represents safety
                    for (int l=0; l<=score; l=l+8){ //represents Touchdown + 2 pt conversion
                        for (int m=0; m<=score; m=m+7){ //represents Touchdown + fieldgoal
                            if (score == i+j+k+l+m){
                                printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", l/8, m/7, i/6, j/3, k/2); //will print out information if the score entered in was equal to all the variables
                            }
                        }
                    }
                }
            }
        }
    }while(score>1); //the loop will run until the user inputs a score the is less than or equal to 1
}
