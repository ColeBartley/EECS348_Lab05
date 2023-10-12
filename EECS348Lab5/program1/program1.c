#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *months[12] = {"January", "Febuary", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

void monthly_sales(float sales[12]){
    printf("Monthly Sales for 2022:\nMonth     Sales\n");
    for(int i=0; i<12; i++){
        printf("%-10s$%0.2f\n", *(months + i), sales[i]);
    }
}

void minmax(float sales[12]){ //function for finding the minimum and maximum
    float min = sales[0];
    float max = sales[0];
    int min_i; //index of the minimum month
    int max_i; //index of the maximum month
    float total = 0; //variable that will find the total amount of sales (used for avg)

    for (int i=0; i<12; i++){
        total = total + sales[i];
        if (sales[i] < min){
            min = sales[i];
            min_i = i;
        }
        if (sales[i] > max){
            max = sales[i];
            max_i = i;
        }
    }
    total = total/12;
    printf("\nSales summary:\n");
    printf("Minimum sales: $%-10.2f(%s)\n", min, *(months + min_i));
    printf("Maximum sales: $%-10.2f(%s)\n", max, *(months + max_i));
    printf("Average sales: $%-10.2f\n", total);
}

void sixmonthavg(float sales[12]){ //function for finding six month averages
    printf("\nSix-Month Moving Average Report:\n");
    float total = 0;
    for (int i =0; i<6; i++){
        total = total + sales[i];
    }
    printf("January     -  June          $%.2f\n", total/6);
    total = total - sales[0] + sales[6]; //subtracts off january and adds june
    printf("Febuary     -  July          $%.2f\n", total/6);
    total = total - sales[1] + sales[7]; //does this for each month until we add december
    printf("March       -  August        $%.2f\n", total/6);
    total = total - sales[2] + sales[8];
    printf("April       -  September     $%.2f\n", total/6);
    total = total - sales[3] + sales[9];
    printf("May         -  October       $%.2f\n", total/6);
    total = total - sales[4] + sales[10];
    printf("June        -  November      $%.2f\n", total/6);
    total = total - sales[5] + sales[11];
    printf("July        -  December      $%.2f\n", total/6);
}


void swap(float* x, float* y){ //function used to swap two of the numbers when ordering them
    float temp = *x; 
    *x = *y; 
    *y = temp;
}

void hightolow(float sales[12]){ //function for sorting out the sales
    printf("\nSales Report (Highest to Lowest):\n");
    char *sortmonths[12] = {"January", "Febuary", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int i, j, max_i;
    for (i = 0; i < 11; i++) { 
        max_i = i; 
        for (j = i + 1; j < 12; j++){
            if (sales[j] > sales[max_i]){
                max_i = j;
            }
        }
    swap(&sales[max_i], &sales[i]); //function call for swap
    char *temp = sortmonths[max_i]; //this swaps the months in the same way as the swap function up above
    sortmonths[max_i] = sortmonths[i];
    sortmonths[i] = temp;
    }
    for (int k=0; k<12;k++){
        printf("%-10s$%0.2f\n", *(sortmonths + k), sales[k]);
    }
}


int main() //all main does in this code is handle the file as an input and call the other functions
{
    float sales[12];
    float number;
    FILE* in_file = fopen("input.txt", "r"); // we only need to read, hense "r" 
    if (! in_file ) // equivalent to saying if ( in_file == NULL )
    {
        printf("file was not read");
        exit(1);
    }
    int i = 0;
    while (fscanf(in_file, "%f", &number) == 1)
    {
        sales[i] = number;
        i++;
    }

    fclose(in_file); //closes file

    // for (int j=0; j<12; j++){
    //     printf("%f\n", sales[j]);
    // } (this was used for testing if File input was working)
    //The rest down below is function calls
    monthly_sales(sales);
    minmax(sales);
    sixmonthavg(sales);
    hightolow(sales);
}
