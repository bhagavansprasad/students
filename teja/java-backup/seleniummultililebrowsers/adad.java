package seleniummultililebrowsers;

import java.util.Set;

import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.firefox.FirefoxDriver;

public class adad
{
	public static void main(String[] args)
	
	{
	
		try
		{
		
		// .//*[@id='login_Layer']
		// .//*[@id='eLogin']
		// .//*[@id='pLogin']
		/*// .//*[@id='lgnFrm']/div[7]/button
		
		dr.findElement(By.xpath(".//*[@id='login_Layer']")).click();
		dr.findElement(By.xpath(".//*[@id='eLogin']")).sendKeys("");
		dr.findElement(By.xpath(".//*[@id='pLogin']")).sendKeys("");
		dr.findElement(By.xpath(".//*[@id='lgnFrm']/div[7]/button")).click();
		*/

		WebDriver dr = new FirefoxDriver();	
		dr.get("https://www.naukri.com/");
		String mainWinHnd = dr.getWindowHandle();
		
     	dr.findElement(By.xpath("html/body/div[2]/div/ul/li[1]/a")).click();
		dr.manage().window().maximize();
		
		Set <String> allWinHnd= dr.getWindowHandles();
		
		// html/body/div[2]/div/ul/li[1]/a
		// html/body/div[2]/div/ul/li[1]/a/span
		// Search Skills = .//*[@id='skill']/div[1]/div[2]/input  // Loc = .//*[@id='location']/div[1]/div[2]/input
		// Expericne = .//*[@id='exp_dd']/div[1]   Salary = .//*[@id='salary_dd']/div[1]		
		// Search Button = .//*[@id='qsbFormBtn']
		
		int i = 1;
		for(String cur_handle:allWinHnd)
		{
			dr.switchTo().window(cur_handle);
			System.out.println("Title of Window : " + i + " = " + dr.getTitle());
        	i = i +1;
		}
		}
		
		catch(RuntimeException e)
	    {
	      System.out.println("** RuntimeException from main");
	    }
	    System.out.println("Main stoped");
			
		}
		
	}