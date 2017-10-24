package seleniumnew;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;

import org.apache.poi.hssf.usermodel.HSSFCell;
import org.apache.poi.hssf.usermodel.HSSFRow;
import org.apache.poi.hssf.usermodel.HSSFSheet;
import org.apache.poi.hssf.usermodel.HSSFWorkbook;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.firefox.FirefoxDriver;

import com.gargoylesoftware.htmlunit.javascript.host.file.File;

public class seleniumworkbook
{

	public static void main(String[] args) 
	{
	
try
{
	String xl = newFile();
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
	System.out.println("emailid = " + emailid + " passwd = " + passwd + " expected_firstname = " + expected_firstname);
	
	
	wb.clone();
	WebDriver driver = new FirefoxDriver();
	driver.get("https://www.Gmail.com");
}
	}

	}

	

