package javaprogram;

public class javatranpose
{
	public static void main(String[] args) 
	{
				
		final int size1=2,size2=4,size3=5;

		        int[][] number={{1,4,7,8},{2,5,8,5}};

		        int row=0,col=0;

		        for(row=0;row<=size1;row++)
		        {

		            for(col=0;col<=size2;col++)
		            {

		                System.out.print(number[col][row]+"\t");     		
		                             		
		            }
		           
		            System.out.print(" \n");
		        }
		    }

}	
	
	


