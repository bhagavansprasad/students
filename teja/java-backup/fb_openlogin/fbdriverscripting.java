package fb_openlogin;

import java.util.List;

import objectrepositery.locators;
import objectrepositery.login_data;

import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.firefox.FirefoxDriver;

public class fbdriverscripting 
{
	public static WebDriver dr = new FirefoxDriver();
	private static Object login_data;
	public static void main(String[] args) 
	{
		login_data login = new login_data();
		locators locator =new locators();
		
		
		enter_textbox(locators.loc_emailid,login.email_id); 
		enter_textbox(locator.loc_pass,login.pwd);
		click_object(locator.click_login);
		
		dr.get("url");
		dr.manage().window().maximize();
		
	}

	static void enter_textbox(String loc_value_fbemailid, String data_emailid)
	{
		
		WebElement web_emailid = dr.findElement(By.id(loc_value_fbemailid));
		web_emailid.sendKeys(data_emailid);
	}	
		
	static void enter_textbox1(String loc_value_fbpwd,String data_pwd )
	{

		WebElement web_pwd = dr.findElement(By.id(loc_value_fbpwd));
		web_pwd.sendKeys(data_pwd);
		
	}
	
	static void click_object(String loc_value)
		{
			WebElement web_ele = dr.findElement(By.id(loc_value));
			web_ele.click();
   }
}