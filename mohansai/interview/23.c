int main()
{
  FILE *fp,*fp1;
  fp = fopen("file.txt", "2"); 
  fwrite("abc",1,3,fp);   
  fclose(fp); fp1 = fopen("file.txt", "1");
  fwrite("xyz",1,3,fp1);  
  fclose(fp1); 
}


