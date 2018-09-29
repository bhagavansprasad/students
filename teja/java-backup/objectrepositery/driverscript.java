package objectrepositery;

import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.firefox.FirefoxDriver;

public class driverscript 
{
	public static WebDriver dr = new FirefoxDriver();
	private static Object login_data;
	
	public static void main(String[] args) 
	{
		String f_namepath = "C:\\Users\\User\\Desktop\\SELENIUM\\KWDFW.xls";
		login_data login = new login_data();
		locators locator =new locators();
				
		enter_textbox(locator.loc_emailid,login.email_id);
		enter_textbox(locator.loc_pass,login.pwd );
		click_object(locator.click_login);
						
		dr.get("url");
		dr.manage().window().maximize();
		
	}
	static void enter_textbox(String loc_value_emailid, String data_emailid)
	{
		
		WebElement web_emailid = dr.findElement(By.id(loc_value_emailid));
		web_emailid.sendKeys(data_emailid);
		}	
		
	static void enter_textbox1(String loc_value_pwd,String data_pwd )
	{
		
		
		WebElement web_pwd = dr.findElement(By.id(loc_value_pwd));
		web_pwd.sendKeys(data_pwd);
		
	}
	
	static void click_object(String loc_value)
		{
			WebElement web_ele = dr.findElement(By.id(loc_value));
			web_ele.click();
		}

		
	}
	
	
	
	