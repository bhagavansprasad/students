package seleniummultililebrowsers;

import java.util.Set;

import org.openqa.selenium.WebDriver;
import org.openqa.selenium.firefox.FirefoxDriver;



public class sdadad 
{

	public static void main(String[] args)
	
	{
	try
	{
		WebDriver dr = new FirefoxDriver();	
		dr.get("https://www.naukri.com/");
		String mainWinHnd = dr.getWindowHandle();
		dr.manage().window().maximize();
		
		Set <String> allWinHnd= dr.getWindowHandles();
		
			
			String cur_handle = null;
			dr.switchTo().window(cur_handle);
			System.out.println("Title of Windows");

	  
	}	
		catch(RuntimeException e)
	    {
	      System.out.println("** RuntimeException from main");
	    }
	    System.out.println("Main stoped");
			
		}
	
	}


