package seleniumprogram;

import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.firefox.FirefoxDriver;
public class seleneiumrediffmail 
{

	public static void main(String[] args) 
	{
		
	try
	    {
			
		    WebDriver dr = new FirefoxDriver();
	    	dr.get("http://www.shine.com/myshine/login");
	    	dr.manage().window().maximize();
			dr.findElement(By.id("id_email")).sendKeys("guvvalatheja@gmail.com");
			dr.findElement(By.id("id_password")).sendKeys("9533669184");
			dr.findElement(By.id("btn_login")).click();
			dr.findElement(By.id("cls_logout")).click();
			dr.findElement(By.xpath("html/body/div[2]/div[5]/div[1]/ul/li[2]/ul/li[2]/a")).click();
			dr.findElement(By.id("id_updateProfileNow")).click();
		
	    }
	    catch(RuntimeException e)
	    {
	      System.out.println("** RuntimeException from main");
	    }
	    System.out.println("Main stoped");
		
	  }
					
	}




