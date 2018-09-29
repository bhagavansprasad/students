package javaprogram;

public class abcd 
{
	public static void main(String[] args)
	{
						try
				{
				      int arr[]={1,2};
		                      System.out.println("devided by zero");
		 			arr[2]=3/0;
				} 
				catch(ArithmeticException ae)
				{
					System.out.println("devided by zero");
				}
				catch(ArrayIndexOutOfBoundsException e)
				{
					System.out.println("array index out of bound exception");
				}
			}
		
	}


