package seleniumprogram;

import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.firefox.FirefoxDriver;

public class seleniumfgufg 
{
	

	public static void main(String[] args) 
	{			
		try
		    {
			
			    WebDriver dr = new FirefoxDriver();
		    	dr.get("http://newtours.demoaut.com/");
		    	dr.manage().window().maximize();
		    	dr.findElement(By.xpath("html/body/div[1]/table/tbody/tr/td[2]/table/tbody/tr[4]/td/table/tbody/tr/td[2]/table/tbody/tr[5]/td/form/table/tbody/tr[4]/td/input")).sendKeys("admin");
			//	dr.findElement(By.id("userName")).sendKeys("admin");
				dr.findElement(By.xpath("html/body/div[1]/table/tbody/tr/td[2]/table/tbody/tr[4]/td/table/tbody/tr/td[2]/table/tbody/tr[5]/td/form/table/tbody/tr[4]/td/input")).sendKeys("mercury");
				dr.findElement(By.id("Sign-In")).click();
				
		    }
		    catch(RuntimeException e)
		    {
		      System.out.println("** RuntimeException from main");
		    }
		    System.out.println("Main stoped");
			
		  }


		
	  }

			
