package implicitprograms;

import java.util.concurrent.TimeUnit;

import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.firefox.FirefoxDriver;

public class vdgdgdg {

	
	public static void main(String[] args) 
	{
	WebDriver dr = new FirefoxDriver();
	dr.manage().timeouts().implicitlyWait(10, TimeUnit.SECONDS);
    dr.get("https://www.naukri.com/");
    WebElement myDynamicElement = dr.findElement(By.id("html/body/div[5]/div/div[1]/div[2]/div[2]/h2[1]"));

	}

}









