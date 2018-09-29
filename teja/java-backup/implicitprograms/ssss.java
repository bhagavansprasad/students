package implicitprograms;

import java.util.concurrent.TimeUnit;

import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.firefox.FirefoxDriver;
import org.openqa.selenium.interactions.Actions;

public class ssss 
{
public static void main(String[] args) 
	{
	
	try
	{
	WebDriver dr = new FirefoxDriver();
	dr.get("https://www.naukri.com/");
	dr.manage().window().maximize();
	Actions a =new Actions(dr);
	dr.manage().timeouts().implicitlyWait(10,TimeUnit.SECONDS);
	WebElement ele1 =dr.findElement(By.xpath("html/body/div[1]/div/div/ul/li[2]/a/span"));
	a.moveToElement(ele1);
	a.perform();
	WebElement ele2 = dr.findElement(By.xpath(" html/body/div[2]/div[5]/div[1]/ul/li[2]/ul/li[2]/a"));
	a.moveToElement(ele1);
	a.perform();
	a.click();
	WebElement ele3 = dr.findElement(By.xpath(".//*[@id='emailTxt']"));
	a.moveToElement(ele3);
	a.click();
	}
	catch(RuntimeException e)
    {
      System.out.println("** RuntimeException from main");
    }
    System.out.println("Main stoped");
	 }
}



