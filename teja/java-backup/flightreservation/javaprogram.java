package flightreservation;

public class javaprogram {

	public static void main(String[] args)
	{
		String s1 ="tendulkar";
		String s2 ="sachin";
		String s3 ="sachin";
		String s4 ="length";
		String s1upper=s1.toUpperCase(); 
		String s1lower =s1.toLowerCase();
		System.out.println(s1.compareTo(s2));  
		System.out.println(s2.compareTo(s3));  
		System.out.println(s1.equalsIgnoreCase(s2));
		System.out.println(s2.equalsIgnoreCase(s3));
		System.out.println(s1.substring(2,4));
		System.out.println(s1.substring(2));
		System.out.println(s1upper);  
		System.out.println(s1lower);
		System.out.println("string length is: "+s4.length());
	
		
	}

}
