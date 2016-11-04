package javaExamples;

public class program 
{
	public static void main(String args[])
    {
        
		int a,b,c;
        a=10;
        b=0;
        System.out.println("devided by zero");
        c=a/b;
        System.out.println("devided by zero");
		
		try
            {
                   System.out.println("devided by zero");
                    
            }
            catch(ArithmeticException ae)
            {
                    System.out.println("devided by zero");
            }
            
    
}
}
