#include<stdio.h>
#include<stdlib.h>

#define MIN(x,y) (x > y) ? y : x

int main(){

    int orate, drop = 0 , cap , x , count = 0, inp[10] = {0}, i = 0, nsec , ch;
    printf("\n Enter the bucket size : ");
    scanf("%d",&cap);

    printf("\nEnter the output rate : ");
    scanf("%d",&orate);

    do{
        printf("\n Enter the number of packets comming at second %d : ",i+1);
        scanf("%d",&inp[i]);
        i++;

        printf("\nEnter 1 to continue or 0 to quit : ");
        scanf("%d",&ch);

    }while(ch);

    nsec = i;

    printf("\nsecond\t recieved\t sent\t dropped\t remained\n");

    for(i=0;count || i < nsec; i++){
        printf("\n%d",i+1);
        printf("\t %d",inp[i]);
        printf("\t\t %d",MIN(inp[i]+count, orate));

        if((x = inp[i]+count-orate) > 0){
            if(x>cap){
                count = cap;
                drop = x - cap;
            }
            else{
                count = x ;
                drop = 0;
            }
        }
        else{
            count = 0;
            drop = 0;
        }
        printf("\t %d\t\t %d \n",drop,count);
        
    }
return 0;


}