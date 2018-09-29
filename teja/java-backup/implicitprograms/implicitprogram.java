package implicitprograms;

import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.firefox.FirefoxDriver;
import org.openqa.selenium.interactions.Actions;

import com.gargoylesoftware.htmlunit.WebClient;

public class implicitprogram {

	
public static void main(String[] args)
	{
    WebDriver dr = new FirefoxDriver();
    dr.get("http://www.shine.com/myshine/login");
	dr.manage().window().maximize();
    Actions a = new Actions(dr);
    WebElement  ele1 = dr.findElement(By.xpath(""));
    a.moveToElement(ele1);
    a.perform();
    
    WebElement  ele2 = dr.findElement(By.xpath(""));
    a.moveToElement(ele2);
    a.click();
    a.perform();
    
	}
}
