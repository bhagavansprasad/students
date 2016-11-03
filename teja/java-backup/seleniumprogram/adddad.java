package seleniumprogram;

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

public class adddad 
{

	public static void main(String[] args) 
	{		// TODO Auto-generated method stub
		try
		{
			int i,j,row,cell;
			// C:\\Users\\User\\Desktop\\SELENIUM\\FACEBOOK.xls
			
		//	File xl = new File("C:\\Users\\User\\Desktop\\SELENIUM\\FACEBOOK.xls");
			File xl = new File("//home//bhagavan//teja//selenium//1.xls");
			FileInputStream fis = new FileInputStream(xl);
			HSSFWorkbook wb = new HSSFWorkbook(fis);
			
			String emailid, passwd, expected_firstname, actual_firstname;
			
			
			for(i=0;i<row;i++)
			{
				for(j=0;j<cell;j++)
				{
					HSSFSheet sh = wb.getSheet("Sheet1");
					HSSFRow row1 = sh.getRow(1);
					HSSFCell cell1 = row1.getCell(0);
					emailid = cell1.getStringCellValue();
					passwd = cell1.getStringCellValue();			
					expected_firstname = cell1.getStringCellValue();
					actual_firstname  =  cell1.getStringCellValue();
					System.out.println("emailid = " + emailid + " passwd = " + passwd + " expected_firstname = " + expected_firstname);
						 						
					WebDriver dr = new FirefoxDriver();
			    	dr.get("http://www.shine.com/myshine/login");
			    	dr.manage().window().maximize();
					dr.findElement(By.id("id_email")).sendKeys("guvvalatheja@gmail.com");
					dr.findElement(By.id("id_password")).sendKeys("9533669184");
					dr.findElement(By.id("btn_login")).click();
			      
			     //  wb.clone();  
			      
					
					
					
					
					
			    // email
			     // pass

			
			
			// .//*[@id='u_0_2']/div[1]/div[1]/div/a/span
			
			
			//actual_firstname = dr.findElement(By.xpath(".//*[@id='u_0_2']/div[1]/div[1]/div/a/span")).getText();
			
					int status = actual_firstname.compareToIgnoreCase(expected_firstname);
					
					if(status == 0)
					{
			
				System.out.println("Login Is Successful. Actual FN is " +actual_firstname  + " TC Passed");
			}
			else
			{
				System.out.println("Actual FN is " + expected_firstname+ "  FN is wrong. TC Failed");

			} 
				}
			
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





