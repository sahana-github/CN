#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int Q[MAX], rear = -1;

void insert(){
    if(rear == MAX -1){
        printf("\nOverflow");
        return;
    }
    else
    {
        printf("\nEnter the value to be inserted : ");
        int ele, i;
        scanf("%d",&ele);
        if(rear == -1){
            Q[++rear] = ele;
        }

        else{
         for(i=rear;i>=0;i--){
             if(ele > Q[i]) Q[i+1] = Q[i];
             else break;
         }

        Q[i+1] = ele;
        rear++;

        }
    }
    
}

void delete(){
    if(rear == -1){
        printf("\nunderflow");
        return;
    }

    else{
        Q[rear--];
    }
}

void display(){
     if(rear == -1){
        printf("\nempty");
        return;
    }

    else{
        int i;
        printf("\n");
        for(i=rear;i>=0;i--){
            printf("%d\t",Q[i]);
        }
        printf("\n");

    }

}


int main()
{ int choice;
    while(1)
    {
        printf("\n1.EnQ\n2.DQ\n3.display\n4.Exit\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: insert();
                    break;

            case 2: delete();
                    break;

            case 3: display();
                    break;

            case 4: exit(0);

            default : printf("\nInvalid choice\n");
        }
    }
}