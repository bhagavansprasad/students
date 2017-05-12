#include <stdio.h>

int main(){
	char string1[20] = "malayalam";
	int i, length;
	int flag = 0;
	for( length = 0; string1[length] != '\0'; length++); 

	for(i=0;i < length ;i++){
		if(string1[i] != string1[length-i-1]){
			flag = 1;
			break;
		}
	}

	if (flag) {
		printf("%s is not a palindrome\n", string1);
	}    
	else {
		printf("%s is a palindrome\n", string1);
	}
	return 0;
}
