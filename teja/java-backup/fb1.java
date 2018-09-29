import java.io.FileNotFoundException;
import java.io.IOException;

import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.firefox.FirefoxDriver;


public class fb1 
{
	public static void main(String[] args)
	{
	try
	{
		WebDriver dr = new FirefoxDriver();
		dr.get("https://login.naukri.com");
		dr.findElement(By.id("emailTxt")).sendKeys("guvvalatheja@gmail.com");
	//  dr.findElement(By.id("next")).click();
		dr.findElement(By.id("pwd1")).sendKeys("8123850122");
    	dr.findElement(By.name("sigIn")).click();
	//	dr.switchTo().frame(0);
	//	dr.switchTo().frame("frame");


	 }

    catch(RuntimeException e)
    {
      System.out.println("** RuntimeException from main");
    }
    System.out.println("Main stoped");
	
	}
}






