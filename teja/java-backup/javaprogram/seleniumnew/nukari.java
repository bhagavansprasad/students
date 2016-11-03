package seleniumnew;

import java.io.FileInputStream;

import org.apache.poi.hssf.usermodel.HSSFCell;
import org.apache.poi.hssf.usermodel.HSSFRow;
import org.apache.poi.hssf.usermodel.HSSFSheet;
import org.apache.poi.hssf.usermodel.HSSFWorkbook;
import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.firefox.FirefoxDriver;

import com.gargoylesoftware.htmlunit.javascript.host.file.File;



public class nukari {

	
	public static void main(String[] args) 
	{
		
	     	 WebDriver driver = new FirefoxDriver(); 
		     driver.get("https://Gmail.com");
		
	     	 
	         driver.findElement(By .id("Email")).sendKeys("guvvalatheja");
		     driver.findElement(By .id("next")).click() ;
		     driver.findElement(By .id("Passwd")).sendKeys("8123850122");
			 driver.findElement(By .id("signIn")).click();
		     File x1 = new File("C:\\Users\\User\\Desktop\\SELENIUM\\FACEBOOK.xls"); 
		     try 
		     {
		    	 
				    FileInputStream fis = new FileInputStream(xls);
		    		HSSFWorkbook wb = new HSSFWorkbook(fis); 
		    		HSSFSheet sh = wb.getSheet("Sheet1");
		    		HSSFRow row = sh.getRow(1);
		    		HSSFCell cell = row.getCell(0);
		    		
		    		String emailid, passwd, expected_firstname, actual_firstname;

		    		emailid = cell.getStringCellValue();
		    		
		    		cell = row.getCell(1);
		    		passwd = cell.getStringCellValue();			
		    		cell = row.getCell(2);
		    		expected_firstname = cell.getStringCellValue();
		    		System.out.println("emailid = " + emailid + " passwd = " + passwd + " expected_firstname = " + expected_firstname);
		    		
		    		
		     driver.get("https://Gmail.com");
		       
			 driver.findElement(By .id("Email")).sendKeys("guvvalatheja");
			 driver.findElement(By .id("next")).click() ;

		       driver.findElement(By .id("Passwd")).sendKeys("8123850122");
			   driver.findElement(By .id("signIn")).click();
		     System.out.println("Exception caught: Division by zero.");
		     }
		    	    
		   catch (ArithmeticException e) 
		   {
		       System.out.println("Exception caught: Division by zero.");
		   }
	} 
}

		
	


