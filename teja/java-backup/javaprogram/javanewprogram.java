package javaprogram;

public class javanewprogram 
{

	public static void main(String[] args)
	{
		
		int[][] a = {  { 4, 5,4,5}, {1,2,4,6},{ 7, 9,10,11 } };
		
		for (int i = 0; i < 3; i++) 
		 {
	            for (int j = 0; j < 3; j++)
	            {
	                System.out.print(a[i][j]);
	            }
	            System.out.println();
		  }
					
		for (int i = 0; i < 3; i++) 
		{
            for (int j = i + 1; j<3; j++)
            {
                int temp = a[i][j];
                a[i][j] = a[j][i];
             
            }
            System.out.println();
		}
            
            for (int i = 0; i < 3; i++) 
   		 {
   	            for (int j = 0; j < 3 ; j++)
   	            {
   	                System.out.print(a[i][j]);
   	            }
   	            System.out.println();
   		  }      
   		
            
            
        }
			} 

	 

