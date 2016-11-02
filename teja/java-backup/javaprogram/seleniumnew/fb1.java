package seleniumnew;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;

import org.apache.poi.hssf.usermodel.HSSFCell;
import org.apache.poi.hssf.usermodel.HSSFRow;
import org.apache.poi.hssf.usermodel.HSSFSheet;
import org.apache.poi.hssf.usermodel.HSSFWorkbook;
import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.firefox.FirefoxDriver;

import com.gargoylesoftware.htmlunit.javascript.host.file.File;


	
	

public class fb1 
{
	public static void main(String[] args)
	{
			
	// C:\\Users\\User\\Desktop\\SELENIUM\\FACEBOOK.xls
		try
		{
			int i,j,k,rows,columns,cell;
					
			String xl = null;
			FileInputStream fis = new FileInputStream(xl);
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
			
			
			for(i=0;i<rows;i++)
			{
				for(j=0;j<columns;j++)
				{
					for(k=0;k<cell;k++);
										
			    }
			}
			
			System.out.println("emailid = " + emailid + " passwd = " + passwd + " expected_firstname = " + expected_firstname);
			
			WebDriver dr  = new FirefoxDriver();
				
			// email
			// pass
			// u_0_m
			// .//*[@id='u_0_2']/div[1]/div[1]/div/a/span
			
		//	dr.findElement(By.id("email")).sendKeys(emailid);
		//	dr.findElement(By.id("pass")).sendKeys(passwd);
		//	dr.findElement(By.id("u_0_m")).click();
			
			actual_firstname = dr.findElement(By.xpath(".//*[@id='u_0_2']/div[1]/div[1]/div/a/span")).getText();
			
			int status = actual_firstname.compareToIgnoreCase(expected_firstname);
			
			if(status == 0)
			{
				System.out.println("Login Is Successful. Actual FN is " + actual_firstname + " TC Passed");
			}
			else
			{
				System.out.println("Actual FN is " + actual_firstname + "  FN is wrong. TC Failed");
			}
					
		} 
		
		catch (FileNotFoundException e) 
		{
			// TODO Auto-generated catch block
			e.printStackTrace();
		} 
		catch (IOException e) 
		{
			// TODO Auto-generated catch block
			e.printStackTrace();
		}	
		

	}


	}


