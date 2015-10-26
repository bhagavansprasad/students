char upper(char *name)
 {
 int i;
     for( i = 0 ; name[i] != '\0' ; i++ )
     {
         if(name[i] >= 'a' && name[i] <= 'z')
         {
             name[i]=name[i]-32;
         }
             
         printf("%c",name[i]);
     }
     printf("\n\n");

 }
