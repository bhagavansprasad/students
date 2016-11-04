import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.firefox.FirefoxDriver;

import strings.string;



public class first_sel
{

	public static void main(String[] args)
	{

		WebDriver driver = new FirefoxDriver();
		driver.get("https://www.Gmail.com");
 	    //driver.navigate().to("http://www.rediff.com");
	  //  driver.navigate().back();
	//	driver.navigate().forward();
	  //  driver.navigate().refresh();
	   // driver.close();
		driver.findElement(By .id("Email")).sendKeys("guvvalatheja");
        driver.findElement(By .id("next")).click();
        driver.findElement(By.xpath(".//*[@id='Passwd']")).sendKeys("8123850122");
        driver.findElement(By .id("signIn")).click();
	//	driver.findElement(By .id("Passwd")).sendKeys("8123850122");
	//  driver.findElement(By.xpath(".//*[@id='Passwd']")).sendKeys("indiao19@");
		
	
	}

}
