import javax.swing.*;
import java.util.*;
class Numberguess extends JFrame
{
NumberGuess() 
{
Scanner obj = new Scanner(System.in);
int i,guess,a;
int number = (int)(50*Math.random())+1;
System.out.println("-------------------------------------------------------------------------------------------------");
System.out.println("\t\t\tGuess The Number Between  1 to 50");
System.out.println("-------------------------------------------------------------------------------------------------");
try{
for(i=1;i<=5;i++)
{
System.out.print("Guess the  Number :");
guess=obj.nextInt();
	if(number==guess)
	{
	JOptionPane.showMessageDialog(this,"Wow! You Find The Number " + number);
	System.out.println("\t\t\t\t\tThe Guess is correct");
	a=JOptionPane.showConfirmDialog(this,"Do you want to Continue This Game");
	System.out.println("\t\t\t\t\tWon The Game");
	if(a==0)
	{
	i=0;
	number = (int)(50*Math.random())+1;
	System.out.println("-------------------------------------------------------------------------------------------------");
	System.out.println("\t\t\t\t\tNew Game");
	System.out.println("-------------------------------------------------------------------------------------------------");
	}
	else if(a==1)
	{
	System.out.println("\t\t\t\t\tGame Over Bye..............");
	break;
	}
	}
	else if(guess>=51 || guess<1)
	{
		JOptionPane.showMessageDialog(this,"Number is Out Of Range");
		i--;
	}
	
	else if(i==5)
	{
	Thread.sleep(2000);
	JOptionPane.showMessageDialog(this,"Your Chance Is Over " );
	JOptionPane.showMessageDialog(this,"The Correct Number is " + number);
	a=JOptionPane.showConfirmDialog(this,"Do you want to Continue Again");
	System.out.println("\t\t\t\t\tGame Over Bye.....");
	if(a==0)
	{
	i=0;
	number = (int)(50*Math.random())+1;
	System.out.println("-------------------------------------------------------------------------------------------------");
	System.out.println("\t\t\t\t\tNew Game");
	System.out.println("-------------------------------------------------------------------------------------------------");
	}
	}
	else if(guess==0)
	{
	JOptionPane.showMessageDialog(this,"The Number is Can't Zero");
	}
	else if(number<guess)
	{
	System.out.println("Your Guess is High : Please Search little Bit Low Number" +" "+ guess);
	}
	else if(number>guess)
	{
	System.out.println("Your Guess is Low : Please Search littel Bit High Number" + " "+ guess);
	}	
	
}
}catch(Exception ex)
{
System.out.println(ex.toString());
}
}
public static void main(String str[])
{
new NumberGuess();
}
}