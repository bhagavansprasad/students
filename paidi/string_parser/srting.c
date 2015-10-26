#include <stdio.h>
#include <string.h>
main()
{
	char temp[500];
	char *ptr;
	int i=0;
	char buff[]="get subsr list succ: <iq from=\'pubsub.auranetworks.in\' to=\'linuxsim@auranetworks.in/home\' id=\'subscriptions1\' type=\'result\'><pubsub xmlns=\'http://jabber.org/protocol/pubsub\'><subscriptions><subscription jid=\'linuxsim@auranetworks.in\' subscription=\'none\'node='http://jabber.org/protocol/tune'/><subscriptionjid=\'linuxsim@auranetworks.in/home\' subid=\'56537FC7E765A\'subscription=\'subscribed\' node='cisco_node'/><subscriptionjid=\'linuxsim@auranetworks.in/home\' subid=\'56538108B203\'subscription=\'subscribed\' node='cisco_node'/><subscriptionjid=\'linuxsim@auranetworks.in/home\' subid=\'5653811D38E50\'subscription=\'subscribed\' node='cisco_node'/><subscriptionjid=\'linuxsim@auranetworks.in/home\' subid=\'5654CF6DB879\'subscription=\'subscribed\'node='nds_node'/></subscriptions></pubsub></iq><message";


	ptr=strstr(buff,"<iq from");
	for(;*ptr++!= '=';);
	for(;*ptr!=' ';ptr++)
	{
		temp[i++]=*ptr;
	}
	temp[i]='\0';

	printf("iq from=%s\n",temp);
	i=0;

	ptr=strstr(buff,"to");
	for(;*ptr++!='=';);
	for(;*ptr!=' ';ptr++)
	{
	temp[i++]=*ptr;
	}
	temp[i]='\0';
	printf("to =%s\n",temp);
	i=0;


	ptr=strstr(buff,"jid");
	for(;*ptr++!='=';);
	for(;*ptr!=' ';ptr++)
	{
	temp[i++]=*ptr;
	}
	temp[i]='\0';
	printf("jid =%s\n",temp);
	i=0;

	ptr=strstr(buff,"subscriptionjid");
	for(;*ptr++!='=';);
	for(;*ptr!=' ';ptr++)
	{
	temp[i++]=*ptr;
	}
	temp[i]='\0';
	printf("subscriptionjid =%s\n",temp);
	i=0;

 }

