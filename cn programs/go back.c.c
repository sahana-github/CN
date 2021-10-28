#include<stdio.h>

int main(){

    int w, i, f, frames[50];

    printf("enter the window size : ");
    scanf("%d",&w);

    printf("\nEnter the number frames to transmit : ");
    scanf("%d",&f);

    printf("\n Enter %d frames : ",f);
    for(i=1; i<=f; i++){
        scanf("%d",&frames[i]);
    }

    printf("\nWith the sliding window protocol the frames will be sent in the following manner(assuming no corruption of frames)");

    printf("\nAfter sending %d frames at each stage, sender waits for ack sent by the receiver  ",w);

    for(i=1;i<=f;i++){
        if(i%w == 0){
            printf("\n%d",frames[i]);
            printf("\n Ack of the above frames sent is received by sender\n");
        }
        else printf("\n%d",frames[i]);
    }
    
    if(f%w != 0)
    printf("\nAck of the above frames sent is received by sender\n");
    return 0;
}