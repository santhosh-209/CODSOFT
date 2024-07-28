import java.util.*;
class Grade
{
public static void main(String[] args)
{
int a[]=new int[5];
Scanner x= new Scanner(System.in);
int i,sum=0,total;
String name;
double average;
char grade;
System.out.println("Enter student name");
x.nextLine();

for(i=0;i<5;i++)
{
a[i]=x.nextInt();
}
for(i=0;i<5;i++)
{
total=sum+a[i];
}
System.out.println("total marks:"+ total);
average=total/5;
System.out.println("Average:"+ average);

if(average>90)
System.out.println("O grade");
else if(average>80&&average<=90)
System.out.println("A+ grade");
else if(average>70&&average<=80)
System.out.println("A grade");
else if(average>60&&average<=70);
System.out.println("B grade");
else if(average<50&&average<=60);
System.out.println(" C grade");
else 
System.out.println("Arrear");

}
}


