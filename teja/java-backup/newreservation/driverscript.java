package newreservation;

import objectrepositery.locators;
import objectrepositery.login_data;
import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.firefox.FirefoxDriver;

public class driverscript
{
	public static WebDriver dr = new FirefoxDriver();
	
	public static void main(String[] args)
	{
		method[i] = navigate,enter	;
	    login_data login = new login_data();
		locators locator = new locators();
	//	enter_textbox(locator.loc_emailid,login.email_id);
	//	enter_textbox(locator.loc_pwd,login.pwd);
	//	click_object(locator.loc_login);
		
		dr.navigate().to("http://newtours.demoaut.com/");
		dr.manage().window().maximize();
for(int i=0;i<=3;i++)
{
		
		switch (method)
	  	    
		  {
		      case  "navigate":
		    	 dr.navigate("url");
		            System.out.println("navigate");
		            break;
		      case "enter_textbox":
		    	  enter_textbox(locator.loc_emailid,login.email_id);
		    	  System.out.println("enter_textbox");
			         break;
		           	           
		      case " enter_textbox1":
		         System.out.println("enter_textbox1");
		         enter_textbox(locator.loc_pwd,login.pwd);
		            break;
		      case "click_object":
		    	  click_object(locator.loc_login);
		  		
		    	  system.out.println("click_object" );
		    	  break;
		     
		  }

		
		
		
	}
	
	static void enter_textbox(String loc_value_emailid, String data_emailid)
	{
	WebElement web_emailid = dr.findElement(By.id(loc_value_emailid));
	web_emailid.sendKeys(data_emailid);
	}	
	
	static void enter_textbox1(String loc_value_pwd, String data_pwd)
	{
	WebElement web_emailid = dr.findElement(By.id(loc_value_pwd));
	web_emailid.sendKeys(data_pwd);
	}	
	

	static void click_object(String loc_value)
	{
		WebElement web_ele = dr.findElement(By.id(loc_value));
		web_ele.click();
	}


/*

  switch (method)
	  	    
	  {
	      case  "navigate":
	    	 dr.navigate("url");
	            System.out.println("navigate");
	            break;
	      case "enter_textbox":
	    	  enter_textbox(locator.loc_emailid,login.email_id);
	    	  System.out.println("enter_textbox");
		         break;
	           	           
	      case " enter_textbox1":
	         System.out.println("enter_textbox1");
	         enter_textbox(locator.loc_pwd,login.pwd);
	            break;
	      case "click_object":
	    	  click_object(locator.loc_login);
	  		
	    	  system.out.println("click_object" );
	    	  break;
	     
	  }
	
*/   
  

