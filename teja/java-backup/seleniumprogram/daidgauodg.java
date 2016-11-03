



package seleniumprogram;

import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.firefox.FirefoxDriver;

public class daidgauodg 
{

	public static void main(String[] args) 
	{
		
		
		try
		    {
				
			
		String u_id =".//*[@id='emailTxt']"	;
		String u_pwd =".//*[@id='pwd1']";
		String u_click="click ";
		
			
		WebDriver dr = new FirefoxDriver();
		dr.get("https://login.naukri.com");
		dr.manage().window().maximize();
		
		
		dr.findElement(By.xpath(" u_id")).sendKeys("guvvalatheja@gmail.com");
		dr.findElement(By.xpath("u_pwd")).sendKeys("8123850122");
		//dr.findElement(By.xpath(".//*[@id='sbtLog']")).click();
		//dr.findElement(By.className("logSBtn")).click();
	 	dr.findElement(By.id("sbtLog")).click();
	 	
		    }
		catch(RuntimeException e)
	    {
	      System.out.println("** RuntimeException from main");
	    }
	    System.out.println("Main stoped");
		
	  }
					
	}
		
		
	
		
