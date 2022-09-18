#include <stdio.h>
#include <stdlib.h>

int welcome (void);
void Menu(int *,int *,int *,int *);
int main()
{
  int ID[10] , temp[10] , speed[10];
  int x,top=0;
  printf(" * Welcome to the motors system *\n");

  x=welcome();
  if (x==2)
    return 0;
if (x==1)
    Menu(ID,temp,speed,&top);

    return 0;
}
int welcome (void){
    int x;

printf(" please choose an option : \n (1) Enter \n (2) Exit\n");
scanf("%d",&x);
if (x==1)
    return 1;

else if (x==2)
return 2;
else
     {
      printf("option is not available\n");
      return 0;
     }

}
void Menu(int *iptr,int *teptr,int *sptr,int *t){
int y,i,k,flag=0,a,b,c,e;
printf(" please choose an option : \n (1) Add \n (2) Delete \n (3) View list \n (4) View \n (5) Back \n");
    scanf("%d",&y);
    if (y==1){
     printf("Enter ID : \n");
scanf("%d",& iptr[*t]);

printf("Enter temperature : \n");
scanf("%d",& teptr[*t]);

printf("Enter speed : \n");
scanf("%d",& sptr[*t]);

(*t)++;
Menu(iptr,teptr,sptr,t);}

if (y==2){
do{
 printf(" Enter the ID of the motor you want to delete : \n");
 scanf("%d",&i);

  for(k=0;k<=10;k++)
  {   if(k==10){
  printf("this ID does not exist \n");
  printf(" please choose an option :\n (1) Enter another ID \n (2) Return to menu \n");
  scanf("%d",&flag);
    }
      if(i==iptr[k])
      { for(e=k;e<*t;e++){
          iptr[e]=iptr[e+1];
          teptr[e]=teptr[e+1];
          sptr[e]=sptr[e+1];
          (*t)--;}
          printf(" the motor with ID %d is deleted\n",i);
          Menu(iptr,teptr,sptr,t);
          break;
      }

  }
}while(flag==1);
flag=0;
Menu(iptr,teptr,sptr,t);
}

if (y==3){
 for(a=0;a<*t;a++)
 {
     printf("ID of the motor number %d : %d \n",a+1 , iptr[a]);
      printf("temperature of the motor number %d : %d \n",a+1 , teptr[a]);
       printf("speed of the motor number %d : %d \n",a+1 , sptr[a]);
 }
  Menu(iptr,teptr,sptr,t);
}

if (y==4){
  printf(" Enter the ID of the motor you want to view : \n");
 scanf("%d",&c);
 for(b=0;b<=*t;b++){
     if (b==*t)
    printf("this ID does not exist \n");
    if(c==iptr[b])
 {
      printf("ID of the motor number %d : %d \n",b+1 , iptr[b]);
      printf("temperature of the motor number %d : %d \n",b+1 , teptr[b]);
       printf("speed of the motor number %d : %d \n",b+1 , sptr[b]);
       break;
 }
 }
 Menu(iptr,teptr,sptr,t);
}

if(y==5){
   if( welcome()==1)
    Menu(iptr,teptr,sptr,t);
}
}

