package seleniumprogram;

import java.io.FileInputStream;

import org.apache.poi.hssf.usermodel.HSSFCell;
import org.apache.poi.hssf.usermodel.HSSFRow;
import org.apache.poi.hssf.usermodel.HSSFSheet;
import org.apache.poi.hssf.usermodel.HSSFWorkbook;

import com.gargoylesoftware.htmlunit.javascript.host.file.File;

public class CSDFSDF 
{

	public static void main(String[] args)
	{
		
		try
		{
			int i,j,row=0,cell=0;
			
			int[][] a = {{ 1,2,3},{4,5,6},{ 7,8, 9 } };
								 
		 // C:\\Users\\User\\Desktop\\SELENIUM\\FACEBOOK.xls
			
		//	File xl = new File("C:\\Users\\User\\Desktop\\SELENIUM\\FACEBOOK.xls");
			File xl = new File("//home//bhagavan//teja//selenium//1.xls");
			FileInputStream fis = new FileInputStream(xl);
			HSSFWorkbook wb = new HSSFWorkbook(fis);
			
					HSSFSheet sh = wb.getSheet("Sheet1"); 
			
					for (i = 0; i < 3; i++)
					{
			            for ( j = 0; j < 3; j++)
			            {
			                System.out.print(a[i][j]);
			                
				            HSSFRow row1 = sh.getRow(i);
							HSSFCell cell1 = row1.getCell(j);
							a[i][j]=(int) cell1.getNumericCellValue();
			            }
					}    
							
					for (i = 0; i < 3; i++)
					{
			            for ( j = 0; j < 3; j++)
			            {
			                System.out.print(a[i][j]);
			                
				            HSSFRow row1 = sh.getRow(j);
							HSSFCell cell1 = row1.getCell(i);
							cell1.setCellNum((short) a[i][j]);
							
							
						
							
							
							
							
							
			            }
			            
					} 
						
	           
	        
	
		
		
		


			
			
			
			