package javaprogram;

import java.util.Scanner;

public class javatranposematrix 

{
	public static void main(String[] args)
	{
		
			
		 int[][] a = { { 1,2,3 }, { 4, 5,6  }, { 7, 8,9  } };
		 
		 
	        // print the matrix
	        for (int i = 0; i < 3; i++) {
	            for (int j = 0; j < 3; j++) {
	                System.out.print(a[i][j]);
	            }
	            System.out.println();
	        }   
	         // operation for transpose
	        for (int i = 0; i < 3; i++) {
	            for (int j = i + 1; j < 3; j++) {
	                int temp = a[i][j];
	                a[i][j] = a[j][i];
	                a[j][i] = temp;                 
	                            	                                
	              }
	            System.out.println();
	        }
	       
	        // After Transpose the matrix print the result
	        for (int i = 0; i < 3; i++) {
	            for (int j = 0; j < 3; j++) {
	                System.out.print(a[i][j]);
	            }
	            System.out.println();
		  }
		       
		 }
}
