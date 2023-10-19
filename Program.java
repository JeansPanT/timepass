import java.util.Scanner;
class Program
{
	public static void main(String args[])
	{
		Scanner Sc = new Scanner(System.in);
		int n,n1,i,t=1,even=0,odd=1;
		System.out.println("Welcome to ALL IN ONE Program");
		System.out.println("1. Table");
		System.out.println("2. Factorial");
		System.out.println("3. Odd/Even Number Finder");
		System.out.println("4. Calculator");
		System.out.println("\n Enter your choice :");
		n=Sc.nextInt();
		
		switch(n)
		{
			case 1:
			{
				System.out.println("Enter your number :");
				n1=Sc.nextInt();
				for(i=1;i<=10;i++)
				{
					t=n1*i;
					System.out.println(n1+"x"+i+"="+t);
				}
				break;
			}
			case 2:
			{
		        System.out.println("Enter your number :");
				n1=Sc.nextInt();
				for(i=n1;i>=1;i--)
				{
					t=t*i;
				}
				System.out.println("Factorial of"+" "+n1+" "+"is"+" "+t);
				break;
			}
			case 3:
			{
				System.out.println("Enter the number you wish to find Even & Odd numbers till :");
				n1=Sc.nextInt();
				for(i=1;i<=n1;i++)
				{
					if(i%2==0)
					{
						System.out.println("Even numbers are :"+i);
					}
					else
					{
						System.out.println("Odd numbers are :"+i);
					}
				}
				break;
			}
			case 4:
			{
				int a,b,c;
				System.out.println("Welcome to BASIC CALCULATOR");
				System.out.println("6. Addition");
				System.out.println("7. Subtraction");
				System.out.println("8. Multiplication");
				System.out.println("9. Division");
				System.out.println("\n Enter your choice :");
				n=Sc.nextInt();
				
				switch(n)
				{
					case 6:
					{
						System.out.println("Enter any two number :");
						a=Sc.nextInt();
						b=Sc.nextInt();
						c=a+b;
						System.out.println("Addition is :"+" "+c);
					}
					break;
					case 7:
					{
						System.out.println("Enter any two number :");
						a=Sc.nextInt();
						b=Sc.nextInt();
						c=a-b;
						System.out.println("Subtraction is :"+" "+c);
					}
					break;
					case 8:
					{
						System.out.println("Enter any two number :");
						a=Sc.nextInt();
						b=Sc.nextInt();
						c=a*b;
						System.out.println("Multiplication is :"+" "+c);
					}
					break;
					case 9:
					{
						System.out.println("Enter any two number :");
						a=Sc.nextInt();
						b=Sc.nextInt();
						float d=(float)a/b;
						System.out.println("Division is :"+" "+d);
					}
					break;
					default:
					{
						System.out.println("Invalid Choice...");
					}
				}
			}
			default:
			{
				System.out.println("Invalid Option");
			}
		}
	}
}
