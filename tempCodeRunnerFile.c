//Car booking
#include<stdio.h>
#define  max   5
struct student
{
  char name[30];
  char id[30];
  char m[50];
  long int no;
} queue[max],*ptr=&queue[0];
FILE *fp;
int r=-1,f=-1;
enum boolean{FALSE,TRUE};
enum boolean isempty()
{

   if(r==-1||f==-1)
      return TRUE;
   else
      return FALSE;

}
enum boolean isfull()
{

   if((f==0&&r==(max-1))||f==r+1)
      return TRUE;
   else
      return FALSE;

}
void carPush()
{

    if(isfull())
    {
	printf("Today all bookings are full\nOrder tomorrow\n");
    }
    else
    {
       if(r==-1)
       {
	  f=0;
	  r=0;
       }
       else
       {
	 r=(r+1)%max;
       }
      if(r==0)
       {
	 fp=fopen("Car.xlsx","w");
      }
       else
       {
	 fp=fopen("Car.xlsx","a");
       }
       printf("Enter Customer ID number\n");
       fflush(stdin);
       scanf("%s",(ptr+r)->id);
       printf("Enter Cusomer Name\n");
       fflush(stdin);
       scanf("%s",(ptr+r)->name);
       printf("Enter Mobile number\n");
       fflush(stdin);
       scanf("%ld",&(ptr+r)->no);
       printf("Enter Model name\n");
       fflush(stdin);
       scanf("%s",(ptr+r)->m);
       fprintf(fp,"%s,%s,%ld,%s,\n",(ptr+r)->id,(ptr+r)->name,(ptr+r)->no,(ptr+r)->m);
       printf("Booking process completed\n");
       fclose(fp);

    }

}
void carPop()
{
    if(isempty())
    {
       printf("Todays Booking list is empty\n");
    }
   else
   {
       printf(" One Car is deliveried so it is removed from booking list\nThose Details:\n");
       printf("ID = %s\nName = %s\nMobile number = %ld\nCar model = %s\n",(ptr+f)->id,(ptr+f)->name,(ptr+f)->no,(ptr+f)->m);
       if(f==r)
     {
       f=-1;
       r=-1;
     }
     else
     {
       f=(f+1)%max;
     }

   }

}
void carFrontele()
{
    if(isempty())
    {
       printf("No orders today\n");
    }
    else
    {
      printf("First order in booking list\n");
      printf("ID = %s\nName = %s\nMobile number = %ld\nCar model = %s\n",(ptr+f)->id,(ptr+f)->name,(ptr+f)->no,(ptr+f)->m);
   }

}

void carRearele()
{

    if(isempty())
    {
       printf("No orders today\n");
    }
    else
    {
      printf("Last order in booking list\n");
      printf("ID = %s\nName = %s\nMobile number = %ld\nCar model\n",(ptr+r)->id,(ptr+r)->name,(ptr+r)->no,(ptr+r)->m);
    }

}
void carDisplay()
{
    int i,count=0;
    if(isempty())
    {
       printf("No orders today\n");
       return;
    }
    else
    {
       if(f<=r)
       {
	 for(i=f;i<=r;i++)
	  {
		printf("Today order number %d details\n",i+1);
		printf("ID = %s\nName = %s\nMobile number = %ld\nCar model = %s\n",(ptr+i)->id,(ptr+i)->name,(ptr+i)->no,(ptr+i)->m);

	  }
       }
       else
       {
	    count++;
	    printf("Today order number %d details\n",count);
	   for(i=f;i<=max-1;i++)
	      printf("ID = %s\nName = %s\nMobile number = %ld\nCar model = %s\n",(ptr+i)->id,(ptr+i)->name,(ptr+i)->no,(ptr+i)->m);
	   for(i=0;i<=r;i++)
	      printf("ID = %s\nName = %s\nMobile number = %ld\nCar model = %s\n",(ptr+i)->id,(ptr+i)->name,(ptr+i)->no,(ptr+i)->m);
      }
    }
}

int main()
{

    int num,item;
    printf("\t\tWelocme to Dhanush Showroom\t\n");
    printf("In our DLS3 showroom present car models and its cost\n");
    printf("1 Mahindra XUV700 =  Rs 13Lakhs\n2 Hyundai Nexo =  Rs 65Lakhs\n3 Hyundai Alcazar =  Rs 13Lakhs\n");
    printf("4 Bugatii Chiron =  Rs 21Crores\n5 Skoda Kushaq =  Rs 13Lakhs\n");
  do
  {
      printf("Press\n1 for book order\n2 for remove order\n3 for display orders\n4 for First order display\n");
      printf("5 for Last order display\n6 for exit\n");
      scanf("%d",&num);
    switch(num)
    {

       case 1:
       carPush();
       break;

       case 2:
       carPop();
       break;

       case 3:
       carDisplay();
       break;

       case 4:
       carFrontele();
       break;

       case 5:
       carRearele();
       break;
    }
  }while(num!=6);
  
}