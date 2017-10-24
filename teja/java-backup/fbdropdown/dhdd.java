package fbdropdown;

import java.util.concurrent.TimeUnit;

import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.firefox.FirefoxDriver;
import org.openqa.selenium.support.ui.ExpectedConditions;
import org.openqa.selenium.support.ui.Select;
import org.openqa.selenium.support.ui.WebDriverWait;

public class dhdd {

	
	public static void main(String[] args)
	{
		
		
		WebDriver dr = new FirefoxDriver();
		dr.get("https://www.naukri.com/");
		dr.manage().window().maximize();  
		
		WebElement dropdown =dr.findElement(By.id("day"));
		dr.manage().timeouts().implicitlyWait(10, TimeUnit.SECONDS);
		Select sel =new Select(dropdown);
		//select month by index
		sel.selectByIndex(5);
	    dr.manage().timeouts().implicitlyWait(10, TimeUnit.SECONDS);
		//select by month in the visible text		
		sel.selectByVisibleText("Nov");
		
	}

}
