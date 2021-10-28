#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>

void divide(char agdtw[],char divs[],char remd[])

{
    int i,r,l,a,t;
    r=strlen(divs);
    t=strlen(agdtw)-r+1;
    char divd[18],rem[18];
    strncpy(divd,agdtw,r);
    divd[r]='\0';
    l=0;
    memset(rem, 0,18);
    while(l<t)
    {
        a=0;
        memset(rem, 0,18);
        if(divd[0]==divs[0])
        {
            for(i=1;i<r;i++)
            {
                if(divd[i]==divs[i])
                    rem[a++]='0';
                else
                    rem[a++]='1';
            }
            rem[a]='\0';
            strcpy(divd,rem);
        }
        else
        {
            strncpy(divd,&divd[1],strlen(divd)-1);
            divd[r-1]='\0';
        }
        int o=strlen(divd);
        divd[o]=agdtw[l+r];
        divd[r]='\0';
        l++;
    }

    strncpy(remd,divd,r-1);
    remd[r-1]='\0';
}

void binary(char letter,char bin[])
{
    int t,c,i=7;
    c=(int)letter;
    while(i>=0)
    {
        t=c%2;
        c=c/2;
        bin[i--]=t+'0';
    }
    bin[8]='\0';
}

char ascii(char bin[])
{
    int t=0,c,i=7;
    while(i>=0)
    {
        t=t+pow(2,7-i)*(bin[i]-'0');
        i--;
    }
    return t;
}

void main()
{    
char dw[126],augdw[1018],div[18],rem[18],cw[1018],rcw[1018],bin[9],rdw[1001],msg[126];
    printf("Enter a Message to be sent (Max 125 Char)\n");
    fgets(dw, sizeof(dw), stdin);
    binary(dw[0],bin);
    strcpy(augdw,bin);
    int j,k,e;
    for(j=1;j<strlen(dw);j++)
    {
        binary(dw[j],bin);
        strcat(augdw,bin);
    }
    strcat(augdw,"0000000000000000");

    printf("\nEnter Divisor (generator) of 17 bits\n");
    scanf("%s",div);
    divide(augdw,div,rem);
    strcpy(cw,augdw);
    strcpy(&cw[strlen(augdw)-16],rem);
    strcpy(rcw,cw);
    printf("\nEnter no. of errors to be introduced during transmission :");
    scanf("%d",&e);
    srand(time(0));
    for(j=0;j<e;j++)
    {
        k=rand()%strlen(rcw)-1;
        if(rcw[k]=='0')
            rcw[k]='1';
        else
            rcw[k]='0';
        printf("Error Generated at %d th bit %d thcharacter\n",k,(k/8)+1);
    }
    divide(rcw,div,rem);
    if(strcmp(rem,"0000000000000000")!=0)
        printf("\n\nErroneous Transmission detected!\n");
    strncpy(rdw,rcw,strlen(rcw)-16);
    rdw[strlen(rcw)-16]='\0';
    for(j=0,k=0;j<strlen(rdw);j=j+8)
    {
        strncpy(bin,&rdw[j],8);
        bin[8]='\0';
        msg[k++]=ascii(bin);
    }
    msg[k]='\0';
    printf("\nRecieved Message = %s\n\n",msg);
}
