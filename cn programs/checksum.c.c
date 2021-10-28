#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int checksum(int fl){
    char in[100];
    int buf[25], i, sum=0, n, temp, temp1;
    scanf("%s",in);
    if(strlen(in)%2 != 0)
       n = (strlen(in)+1) /2;
    else
       n = (strlen(in))/2;

    for(i=0; i<n;i++){
        temp = in[i*2];
        temp = temp * 256 + in[(i*2)+1];
        sum =  sum + temp;
    }

    if(fl){
        printf("\nEnter the check sum value : ");
        scanf("%x",&temp1);
        sum = sum + temp1;
    
    }

    if(sum % 65536 != 0){
        n =  sum % 65536;
        sum  = (sum / 65536) + n;
    }

    sum  = 65535 - sum;
    printf("\n%x", sum);
    return sum;
}


void main(){
    int ch , sum ;
    do{
        printf("\n1.Encode \n2.Decode \n3.Exit \nEnter Your choice : ");
        scanf("%d",&ch);
        switch (ch)
        {
            case 1 : printf("\nEnter the String : ");
                     sum  =  checksum(0);
                     printf("\nCheckSum to append is %x",sum);
                     break;

            case 2 : printf("Enter the string : ");
                     sum = checksum(1);
                     if(sum != 0) printf("\nData has been tampered with or invalid checksum");
                     else printf("\n The checksum is valid");
                     break;
            case 3 : exit(0);

            default : printf("\nInvalid Choice");
                      break;

        }
    }while(ch != 3);
}
