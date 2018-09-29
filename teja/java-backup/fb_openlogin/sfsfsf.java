package fb_openlogin;

import net.sf.cglib.core.Local;
import objectrepositery.locators;
import objectrepositery.login_data;

import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.firefox.FirefoxDriver;

public class sfsfsf
{

	public static WebDriver dr = new FirefoxDriver();
	
	
public static void main(String[] args)

{
	login_data login = new login_data();
	
    enter_textbox(locators.loc_emailid,login.email_id); 
	click_object(locator.click_login);
	
	dr.get("url");
	dr.manage().window().maximize();
	
			
	}

static void enter_textbox(String loc_value_fbemailid, String data_emailid)
{
		
	
	WebElement web_emailid = dr.findElement(By.id(loc_value_fbemailid));
	web_emailid.sendKeys(data_emailid);
}	

static void click_object(String loc_value)
{
	WebElement web_ele = dr.findElement(By.id(loc_value));
	web_ele.click();
}
}