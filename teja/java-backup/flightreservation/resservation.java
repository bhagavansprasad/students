package flightreservation;

import java.awt.List;

import junit.framework.Assert;

import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.firefox.FirefoxDriver;
import org.openqa.selenium.support.ui.Select;
                   
                         /*flight reservation*/
public class resservation 
{


public static void main(String[] args)
{
		
	String expected_firstname,actual_firstname;
    WebDriver dr = new FirefoxDriver();
	dr.get("http://newtours.demoaut.com/");
	dr.manage().window().maximize();    	  	
	
	dr.findElement(By.name("userName")).sendKeys("admin");
	dr.findElement(By.name("password")).sendKeys("mercury");
	dr.findElement(By.name("login")).click();	
	dr.findElement(By.name("findFlights")).click();
	dr.findElement(By.name("reserveFlights")).click();
	dr.findElement(By.name("passFirst0")).sendKeys("teja");
	dr.findElement(By.name("passLast0")).sendKeys("kumar");
	dr.findElement(By.name("creditnumber")).sendKeys("8123850122");
	dr.findElement(By.name("cc_frst_name")).sendKeys("guvvala");
	dr.findElement(By.name("cc_mid_name")).sendKeys("javeed");
	dr.findElement(By.name("cc_last_name")).sendKeys("kumar");
	dr.findElement(By.name("billAddress2")).sendKeys("j.p.nagur");
	dr.findElement(By.name("delAddress2")).sendKeys("banglore");
	dr.findElement(By.name("buyFlights")).click();	
    String expected_firstname1 = "teja";
    String actual_firstname1 ="teja";
    System.out.println(expected_firstname1.compareTo(actual_firstname1));  
    System.out.println(expected_firstname1.substring(2,4));
		
	if( expected_firstname1==actual_firstname1)
	{
		System.out.println("teja");
		
	}
	else
	{
		System.out.println("guvvala");
		
	}
	
	
	
	
	/*radioo buttion*/
	   
	 java.util.List<WebElement>  rb  = dr.findElements(By.name("triptype"));
	 boolean bValue = false;
	 boolean b = ((WebElement)rb.get(0)).isSelected();	 	  
	 
	 
	 if(bValue = true)
	 {
	  rb.get(1).click();
	 
	 }
	 else
	 {
	 	rb.get(0).click();
		
	 
	 } 

/* drop down*/
	 
	 
	WebElement element=dr.findElement(By.name("passCount"));
	Select sel =new Select(element);
	sel.selectByValue("2");
	sel.selectByVisibleText("september");
	WebElement element1=dr.findElement(By.name("fromMonth"));
	Select sel1 =new Select(element1);
	sel1.selectByVisibleText("london");
	sel1.selectByIndex(2);
	sel.selectByIndex(1);
	}

}	


