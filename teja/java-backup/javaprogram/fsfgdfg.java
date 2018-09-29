

package javaprogram;

public class fsfgdfg 
{

	public static void main(String[] args)
	{
		
		int i,j,n=5,flag=0;
		for(i=2;i<=n;i++)
		{
			for(j=2;j<=i/2;j++)
			{
				if(i%j==0)
				{
					flag=1;
					break;
				}
			}
			if(flag==0)
			{

				System.out.println("prime");  
			}
			flag=0;
		}
	}


		
	}


