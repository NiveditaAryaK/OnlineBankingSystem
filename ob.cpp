#include<stdio.h>
 #include<string.h> 
 #include<stdlib.h> 
 struct user { 
  char phone[50]; 
  char ac[50]; 
  char password[50]; 
  float balance; };

int main(){ struct user user,usr; char bankdetails[50],phone[50],password[50],phone2[50]; FILE *fbank,*fstatement; int opt,choice; int amount; char cont = 'y'; printf("\nWhat do you want to do?"); printf("\n\n1.Register your account"); printf("\n2.Login to your account");

printf("\n\nPlease enter your choice:\t");
scanf("%d",&opt);
if(opt == 1){
	system("clear");
	printf("\nEnter your account number:\t");
	scanf("%s",user.ac);
	printf("Enter your phone number:\t");
	scanf("%s",user.phone);
	printf("Enter your new password:\t");
	scanf("%s",user.password);
	user.balance=0;
	stpcpy(bankdetails,user.phone);
	fbank=fopen(strcat(bankdetails,".dat"),"w");
	fwrite(&user,sizeof(user),1,fbank);
	if(fwrite != 0){
		printf("Succesfully registered");
	}
}
else if(opt == 2){
	system("clear");
	printf("\nPhone No.:\t");
	scanf("%s",phone);
	printf("Password:\t");
	scanf("%s",password);
	fbank = fopen(strcat(phone,".dat"),"r");
	if(fbank == NULL)
	printf("Account number not registered");
	else {
		fread(&user,sizeof(struct user),1,fbank);
		fclose(fbank);
		if(!strcmp(password,user.password)){
			while(cont == 'y'){
			system("clear");
			printf("\n\tWelcome %s",user.phone);
			printf("\nPress 1 for balance inquiry");
			printf("\nPress 2 for adding fund");
			printf("\nPress 3 for cash withdrawal");
			printf("\nPress 4 for online transfer");
			printf("\nPress 5 for changing password\n\n");
			scanf("%d",&choice);
			switch(choice){
				case 1:
					printf("Your current balance is Rs. %.2f",user.balance);
					break;

				case 2:
					system("clear");
					printf("Enter amount to be added:\t");
					scanf("%d",&amount);
					user.balance += amount;
					fbank = fopen(phone,"w");
					fwrite(&user,sizeof(struct user),1,fbank);
					if(fwrite !=0) printf("\n\nYou have depostied Rs.%d",amount);
					fclose(fbank);
					break;

				case 3:
					system("clear");
					printf("Enter withdrawl amount:\t");
					scanf("%d",&amount);
					if(amount % 500 != 0)
					printf("\nSorryamount should be multiple of 500");
					else if(amount>user.balance)
					printf("\nSorryinsufficeint balance");
					else {
						user.balance -= amount;
					fbank = fopen(phone,"w");
					fwrite(&user,sizeof(struct user),1,fbank);
					if(fwrite !=0) printf("\n\nYou have withdrawn Rs.%d",amount);
					fclose(fbank);
					}
					break;

				case 4:
					printf("Please enter the phone number to trasnfer balance:\t");
					scanf("%s",phone);
					printf("Enter the amount to transfer:\t");
					scanf("%d",&amount);
					if(amount > user.balance)
					printf("\nSorry insufficent balance");
					else {
						fstatement = fopen(strcat(phone,".dat"),"r");
						if(fstatement==NULL) printf("Sorry number is not registered");
						else {
							fread(&usr,sizeof(struct user),1,fstatement);
							fclose(fstatement);

							usr.balance += amount;

							fstatement = fopen(phone,"w");
							fwrite(&usr,sizeof(struct user),1,fstatement);
							if(fwrite != 0){
							// 	printf("ACcount:%s",usr.ac);
							// printf("\npassword%s",usr.password);
							// printf("\nphone%s",usr.phone);
							// printf("\nbalance%f",usr.balance);
								printf("Your trasfer is completed. You have trasnfered Rs.%d to %s",amount,usr.phone);
								fclose(fstatement);
								user.balance -= amount;
								strcpy(bankdetails,user.phone);
								fbank = fopen(strcat(bankdetails,".dat"),"w");
								fwrite(&user,sizeof(struct user),1,fbank);
								fclose(fbank);
							}
						}
					}
					break;
				case 5:
					printf("\n\nPlease enter your old password:\t");
					scanf("%s",password);
					if(!strcmp(password,user.password)){
						printf("\n\nPlease enter your new password:\t");
						scanf("%s",password);
						strcpy(user.password,password);
						strcpy(bankdetails,user.phone);
						fbank = fopen(strcat(bankdetails,".dat"),"w");
						fwrite(&user,sizeof(struct user),1,fbank);
						fclose(fbank);
						printf("\nPassword succesfullly changed");
					}else printf("\nSorry your password is wrong");

				default:
				break;
			}//switch ends here
			printf("\n\nDo you want to continue?[y/n]:\t");
			scanf("%s",&cont);
			}
		}
		else {
			printf("Invalid password");
		}
	}
	printf("\n\n***Thank you for banking with MNR bank***\n\n");
}

return 0;
}