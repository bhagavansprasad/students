package seleniumprogram;

import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.firefox.FirefoxDriver;

public class seleniumaruba 
{

	public static void main(String[] args)
	{
		
		try
				{
				
				String x_uid = "html/body/div[1]/table/tbody/tr/td[2]/table/tbody/tr[4]/td/table/tbody/tr/td[2]/table/tbody/tr[2]/td[3]/form/table/tbody/tr[4]/td/table/tbody/tr[2]/td[2]/input";
			    String x_pwd = "html/body/div[1]/table/tbody/tr/td[2]/table/tbody/tr[4]/td/table/tbody/tr/td[2]/table/tbody/tr[2]/td[3]/form/table/tbody/tr[4]/td/table/tbody/tr[3]/td[2]/input ";
		        String x_click ="html/body/div[1]/table/tbody/tr/td[2]/table/tbody/tr[4]/td/table/tbody/tr/td[2]/table/tbody/tr[2]/td[3]/form/table/tbody/tr[4]/td/table/tbody/tr[4]/td[2]/div/input";
		        String x_usign ="html/body/div[1]/table/tbody/tr/td[2]/table/tbody/tr[2]/td/table/tbody/tr/td[1]/a ";       
		        String x_pofil ="html/body/div[1]/table/tbody/tr/td[2]/table/tbody/tr[2]/td/table/tbody/tr/td[3]/a";
		        String x_back = "html/body/div[1]/table/tbody/tr/td[2]/table/tbody/tr[4]/td/table/tbody/tr[1]/td[2]/table/tbody/tr[4]/td/a/img";
		        String x_flight = "html/body/div[1]/table/tbody/tr/td[1]/table/tbody/tr/td/table/tbody/tr/td/table/tbody/tr[1]/td[2]/font/a" ;
		        String x_vacations ="html/body/div[1]/table/tbody/tr/td[1]/table/tbody/tr/td/table/tbody/tr/td/table/tbody/tr[1]/td[2]/font/a";
		        String x_click1 ="html/body/div[1]/table/tbody/tr/td[2]/table/tbody/tr[4]/td/table/tbody/tr/td[2]/table/tbody/tr[5]/td/form/p/input";
		        
		        
		        
		        
		  		WebDriver dr = new FirefoxDriver();
		    	dr.get("http://newtours.demoaut.com/");
		    	dr.manage().window().maximize();    	  	
		    	dr.findElement(By.xpath(x_uid)).sendKeys("admin");
		    	dr.findElement(By.xpath(x_pwd)).sendKeys("mercury");
		    	dr.findElement(By.xpath(x_click)).click();	
		    	dr.findElement(By.xpath(x_usign)).click();
		    	dr.findElement(By.xpath(x_pofil)).click();
		    	dr.findElement(By.xpath( x_back )).click();
		    	dr.findElement(By.xpath(x_flight )).click();
		    	dr.findElement(By.xpath(x_vacations )).click();
		        dr.close();
		    	    	
				}	

			catch(RuntimeException e)
		    {
		      System.out.println("** RuntimeException from main");
		    }
		    System.out.println("Main stoped");
				
			}
			

	}


