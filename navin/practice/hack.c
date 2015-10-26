
#include <stdio.h>
int main (void){
    system("sudo ssh -X 192.168.1.30 shutdown -a");
    wait(5);
//    system("sudo shutdown 1");

return 0;
}
