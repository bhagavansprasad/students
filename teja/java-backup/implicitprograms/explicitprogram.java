
package implicitprograms;

import java.util.concurrent.TimeUnit;

import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.firefox.FirefoxDriver;
import org.openqa.selenium.support.ui.ExpectedConditions;
import org.openqa.selenium.support.ui.WebDriverWait;

public class explicitprogram 
{

public static void main(String[] args)
{
	WebDriver dr = new FirefoxDriver();
	dr.get("http://www.shine.com/myshine/login");
	dr.findElement(By.id("id_email")).sendKeys("guvvalatheja@gmail.com");
	dr.findElement(By.id("id_password")).sendKeys("9533669184");
	dr.findElement(By.id("btn_login")).click();
	dr.manage().timeouts().implicitlyWait(10,TimeUnit.SECONDS);
//	WebDriverWait wait = new WebDriverWait(dr, 10);
//	WebElement element = wait.until(ExpectedConditions.elementToBeClickable(By.id("emailTxt")));
	}
}
