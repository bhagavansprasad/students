package seleniumprogram;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;

import org.apache.poi.hssf.usermodel.HSSFCell;
import org.apache.poi.hssf.usermodel.HSSFRow;
import org.apache.poi.hssf.usermodel.HSSFSheet;
import org.apache.poi.hssf.usermodel.HSSFWorkbook;

import com.gargoylesoftware.htmlunit.javascript.host.file.File;



public class excel_create_cell 
{

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		File f = new File("//home//bhagavan//teja//selenium//1.xls");
		try 
		{
			String xls;
			FileInputStream fis = new FileInputStream(xls);
			HSSFWorkbook wb = new HSSFWorkbook(fis);
			HSSFSheet sheet = wb.getSheet("Sheet1");
			HSSFRow row = sheet.getRow(0);
			HSSFCell cell = row.getCell(0);
			String str = cell.getStringCellValue();
			System.out.println("The string value from excel is " + str);
			
			// ===================================
			String s1="hello1",s2 = "hello2";
			cell.setCellValue(s1);
						
			
			HSSFSheet sheet1 = wb.getSheet("Sheet2");
			HSSFRow row1 = sheet1.createRow(0);
			// HSSFRow row1 = sheet1.getRow(0);
			HSSFCell cell1 = row1.createCell(0);
			// HSSFCell cell1 = row1.getCell(0);
			   cell.setCellValue(s2);
			
			FileOutputStream fos = new FileOutputStream(xls);
			wb.write(fos);
			
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


