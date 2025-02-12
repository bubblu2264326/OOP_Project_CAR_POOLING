#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#include<string.h>
#include<fstream>
#include<ostream>
#include<math.h>
#include<ctype.h>
#include<iostream>
#include<string>
#include<cctype>

using namespace std;

float fare(char[] , char[]);
void menu();
void box();
void jump(int ,int );
//person class
class Person
{
	//encapsulation 
   private:
   int rides_completed;
   char name[20],cnic[15],mobile[12],password[8];
   public:
   Person()
   {
        rides_completed = 0;
   }
   void set_password(char p[8])
   {
      strcpy(password,p);
   }
   char* get_passowrd()
   {
     return password;
   }
   void set_name(char n[20])
   {
        strcpy(name,n);
    }
   char* get_name()
   {
      return name;
   }
   void set_cnic(char c[15])
   {
          strcpy(cnic,c);
    }
   char* get_cnic()
   {
      return cnic;
   }
   void set_mobile(char m[12])
   {
    strcpy(mobile,m);      
    }
   char* get_mobile()
   {
      return mobile;
   }
   void set_rides(int rides_completed)
   {
    this->rides_completed = rides_completed;
   }
   int get_rides()
   {
      return rides_completed;
   }
   virtual void reg()=0;  
   virtual int store_data()=0;
};
// car classs
class Car
{
 private:
 int seats;
 char plate_no[8],model[8],cartype[10];
 char category;
 public: 
 void set_seats(int seats)
 {
     this-> seats = seats;
 }
 int get_seats()
 {
      return seats;
 }
 void set_category(char category)
 {
     this-> category = category;
 }
 char get_category()
 {
   return category;
 }
 void set_plate_no(char p[8])
 {
   strcpy(plate_no,p);
 }
 char* get_plate_no()
 {
   return plate_no;
 }
 void set_model(char m[8])
 {
    strcpy(model,m);
 }
 char* get_model()
 {
   return model;
 }
 void set_cartype(char c[10])
 {
    strcpy(cartype,c);
 }
 char* get_cartype()
 {
   return cartype;
 }

};
// captain class inhereted from person class
//INHERETENCE
class Captain:public Person
{
   private:
   double bounus,payment; 
   char starting_point[20],end_point[20]; 
   public:
   Captain()
   {
       bounus = 0;
       payment =0;
   }
   Car C;
   void set_starting_point(char s[20])
   {
    strcpy(starting_point,s);
   }
   char* get_starting_point()
   {
      return starting_point;
   }
    void set_end_point(char e[20])
   {
    strcpy(end_point,e);
   }
   char* get_end_point()
   {
      return end_point;
   }
   
    void set_bounus( double bounus)
   {
    this->bounus = bounus;
   }
   double get_bounus()
   {
      return bounus;
   }
   void set_payment( double payment)
   {
    this->payment = payment;
   }
   double get_payment()
   {
      return payment;
   }
   void reg()
   {
     int i=0;
     char a;
     char pass[32];
       char name_d[20];
         system("cls");
    	box();
      
        jump(10,3);
         fflush(stdin);
        cout<<"<---:ADD CAPTAIN RECORD:--->";
        jump(10,5);
        cout<<"Enter Your Details.";
         jump(10,7);
          fflush(stdin);
         printf("Enter Your name : ");
          gets(name_d); 
         for(i=0;name_d[i]!='\0';i++)
        {
        	if(isalpha(name_d[i])==0)
        	{
        		printf("Invalid Input!");
        		getche();
                menu();
        		
			}
		   }
         set_name(name_d);
         fflush(stdin);
        jump(10,8);
        printf("Enter your Mobile number(11 digits) : ");
        char mob[12];
        gets(mob);
        for(i=0;mob[i]!='\0';i++)
        {
        	if(isdigit(mob[i])==0)
        	{
        		printf("Invalid Input!");
            	getche();
            menu();
			}
		}
      if(strlen(mob)!=11)
      {
          jump(13,15);
			printf("Invalid Input!");
      getche();
      menu();
      }
       fflush(stdin);
       set_mobile(mob);
       jump(10,9);
        cout<<"Enter Your Password : ";
       
    for(i=0;;)
    {
        a=getch();
        if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9'))
        {
            pass[i]=a;
            ++i;
            cout<<"*";
        }
        if(a=='\b'&&i>=1)
        {
            cout<<"\b \b";
            --i;
        }
        if(a=='\r')
        {
            pass[i]='\0';
            break;
        }
    }
  
       set_password(pass);
       jump(10,10);
       char pl[10];
      cout<<"Enter Vehicle plate no. : ";
      gets(pl);
      C.set_plate_no(pl);
      jump(10,11);
      char cni[15];
        cout<<"Enter Your CNIC Number( without '-') : ";
        gets(cni);
        for(i=0;cni[i]!='\0';i++)
        {
        	if(isdigit(cni[i])==0)
        	{
        		
        		cout<<"\n\n\tInvalid Input!";
        		getche();
            menu();
			}
		}
		if(strlen(cni)!=13)
		{
			jump(13,14);
			cout<<"Invalid Input!"<<endl;
        		getche();
		}
    set_cnic(cni);
      fflush(stdin);
		jump(10,12);
      char type[10];
        printf("Enter Car type : ");
        gets(type);
        C.set_cartype(type);
        jump(10,13);
        printf("Enter Car Category:\n\n\t   A = Luxury Car\n\t   B = AC Car\n\t   C = Non AC Car\n\t   D = Rickshaw\n\t   E = Motorbike");
        jump(10,20);
        char cat;
        printf("Enter your Choice : ");
        cin >> cat;
        
      C.set_category(cat);
      char start[20],stop[20];
        fflush(stdin);
        jump(10,22);
        cout<<"Enter Your strarting Point : ";
        gets(start);
        for(i=0;start[i]!='\0';i++)
        {
        	if(isalpha(start[i])==0)
        	{
        		printf("Invalid Input!");
        		getche();
        		
			}
		}
       set_starting_point(start);
       jump(10,23);
       cout<<"Enter Your stop Point : ";
        gets(stop);
        for(i=0;stop[i]!='\0';i++)
        {
        	if(isalpha(stop[i])==0)
        	{
        		printf("Invalid Input!");
        		getche();
			}
		}
      set_end_point(stop);
      jump(10,24);
      int seat;
        cout<<"Enter seats : ";
        cin>>seat;
        if ((seat<=0) || (seat>4))
        {
        	printf("\t\n  Invalid Input!");
        	getche();
		}
        C.set_seats(seat);

   }
   int store_data()
   {
       if(get_name()=="Null")
       {
        cout<<"Data not initiallized"<<endl;
        return 0;
       }
       else
       {
       ofstream fout;
       fout.open("record.dat",ios::app|ios::binary);
       fout.write((char*)this,sizeof(*this));
       fout.close();
       return 1;
       }
   }
   void view_all_data()
   {
      char stmobile[12];
     char pass[32],a;
       int j=8,i=1;
        system("cls");
             jump(10,5);
    printf("Enter mobile number of person to view record : ");
    fflush(stdin);
    gets(stmobile);
    jump(10,6);
    cout<<"Enter Your Password: ";
    for(i=0;;)
    {
        a=getch();
        if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9'))
        {
            pass[i]=a;
            ++i;
            cout<<"*";
        }
        if(a=='\b'&&i>=1)
        {
            cout<<"\b \b";
            --i;
        }
        if(a=='\r')
        {
            pass[i]='\0';
            break;
        }
    }
        system("cls");
          jump(10,3);
           cout<<"<---:VIEW RECORD:--->";
           jump(10,5);
    cout<<"R.C   Name of Captain    Mobile        CNIC          Carplate        Cartype          Category     Seats     Startpoint        Endpoint"<<endl;
    jump(10,6);
    cout<<"---------------------------------------------------------------------------------------------------------------------------------------";
       ifstream fin;
       fin.open("record.dat",ios::in|ios::binary);
       if(!fin)
       {
           jump(10,8);
         cout<<"File not found";
         getche();
         menu();
       }
       else
       {
           
         fin.read((char*)this,sizeof(*this));
         i = 0;
         while(!fin.eof())
         {
           if(strcmp(stmobile,get_mobile()) == 0 && strcmp(pass,get_passowrd()) == 0)
           {
             jump(10,j); 
        cout<<get_rides()<<"  "<<"     "<<get_name()<<"   "<<get_mobile()<<"   "<<get_cnic()<<"        "<<C.get_plate_no()<<"         "<<C.get_cartype()<<"            "<<C.get_category()<<"         "<<C.get_seats()<<"         "<<get_starting_point()<<"           "<<get_end_point();
          }
           fin.read((char*)this,sizeof(*this));
       }
       }
       fin.close();
       jump(10,j+3);
       cout<<"Press any key to continue...";
      getch();
      menu();
   }
   void Delete_Data()
   {
     char stmobile[12];
     char pass[32],a;
     int i;
     system("cls");
    box();
    jump(10,3);
    printf("<---:DELETE RECORD:--->");
    jump(10,5);
    printf("Enter mobile number of person to delete record : ");
    fflush(stdin);
    gets(stmobile);
    jump(10,6);
    cout<<"Enter Your Password: ";
  
    for(i=0;;)
    {
        a=getch();
        if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9'))
        {
            pass[i]=a;
            ++i;
            cout<<"*";
        }
        if(a=='\b'&&i>=1)
        {
            cout<<"\b \b";
            --i;
        }
        if(a=='\r')
        {
            pass[i]='\0';
            break;
        }
    }
     ifstream fin;
     ofstream fout;
     fin.open("record.dat",ios::in|ios::binary);
     if(!fin)
     {
       cout<<"\nFile not Found"<<endl;
     }
     else
     {
       fout.open("tempfile.dat",ios::out|ios::binary);
       fin.read((char *)this,sizeof(*this));
       while (!fin.eof())
       {
         if(strcmp(stmobile,get_mobile()) != 0 && strcmp(pass,get_passowrd()) != 0)
          fout.write((char*)this,sizeof(*this));
           fin.read((char *)this,sizeof(*this));
       }
       fin.close();
       fout.close();
       remove("record.dat");
       rename("tempfile.dat","record.dat");
     }
   }
   void update_data()
   {
       char stname[20];
    string choice;
    FILE *fp;
    system("cls");
    box();
    jump(10,3);
    printf("<---:MODIFY RECORD:--->");
    jump(10,5);
    printf("Enter name of Captain to modify : ");
    fflush(stdin);
    gets(stname);
    system("cls");
    jump(10,5);
    printf("Enter the information you want to modify :");
    getline(cin,choice);
    fflush(stdin);
    fp = fopen("record.dat","rb+");
    if(fp == NULL)
	{
        jump(10,6);
        printf("Error in opening file");
        exit(1);
    }
    rewind(fp);
    fflush(stdin);
    while(fread(this,sizeof(*this),1,fp) == 1)
    {
    	    fflush(stdin);
        if(strcmp(stname,get_name()) == 0){
            if(choice=="NAME")
            {
               char nam[20];
            	 jump(10,7);
            printf("Enter name : ");
            gets(nam);
            set_name(nam);
			}
			else if(choice=="mobile")
            {
               char mobil[12];
            	 jump(10,7);
            printf("Enter Mobile No : ");
            gets(mobil);
            set_mobile(mobil);
			}
      else if(choice=="category")
            {
              char category;
            	 jump(10,7);
            printf("Enter Category : ");
            cin>>category;
            C.set_category(category);
        }
        else if(choice=="seats"||choice=="SEAT"||choice=="SEATS")
            {
              int s;
            	 jump(10,7);
            printf("Enter Availaible Seats : ");
            cin>>s;
            C.set_seats(s);
        }
         else if(choice=="START"||choice=="start")
            {
              char s[20];
            	 jump(10,7);
            printf("Enter Your Starting point: ");
            gets(s);
            set_starting_point(s);
        }
          else if(choice=="stop"||choice=="end")
            {
              char s[20];
            	 jump(10,7);
            printf("Enter Your End point: ");
            gets(s);
            set_end_point(s);
        }
    else
    {
    	jump(10,9);
    	printf("Invalid input!");
    	getch();
    	update_data();
	}
        
            fseek(fp ,-sizeof(*this),SEEK_CUR);
            fwrite(this,sizeof(*this),1,fp);
            break;
            
        }
    }
    fclose(fp);
    jump(10,16);
    printf("Press any key to continue...");
    getch();
    menu();
   }
};
//user class inhereted from 
class User: public Person
{
   
  private:
  double coverd_distance;
  char status[20];
  public:
  User()
  {
      coverd_distance = 0;
  }
  void set_coverd_distance(double coverd_distance)
   {
    this->coverd_distance = coverd_distance;
   }
   double get_coverd_distance()
   {
      return coverd_distance;
   }
   void set_status(char s[20])
   {
       strcpy(status,s);
   }
   char* get_status()
   {
      return status;
   }
   void reg()
   {
    system("cls");
    box();
    char dummy[20];
    char pass[32],a;
    int i;
       box();
       jump(10,3);
       cout<<"<---:ADD USER RECORD:--->";
        jump(10,5);
        cout<<"Enter Your details.";
        jump(10,7);
        cout<<"Enter Name : ";
        fflush(stdin);
        gets(dummy);
        fflush(stdin);
        set_name(dummy);
         fflush(stdin);
        jump(10,8);
        cout<<"Enter Mobile Number : ";
        char dummy_m[12];
        gets(dummy_m);
        for(i=0;dummy_m[i]!='\0';i++)
        {
        	if(isdigit(dummy_m[i])==0)
        	{
        		printf("Invalid Input!");
        		getche();
        		menu();
			}
		}
      if(strlen(dummy_m)!=11)
      {
          jump(13,9);
			printf("Invalid Input!");
        		getche();
        		menu();
      }
       fflush(stdin);
        set_mobile(dummy_m);
          char cn[15];
          jump(10,9);
          try{
        cout<<"Enter Your CNIC Number : ";
        gets(cn);
        for(i=0;cn[i]!='\0';i++)
        {
        	if(isdigit(cn[i])==0)
        	{
        		
        		throw(cn);
        		getche();
        		menu();
			}
		}
		if(strlen(cn)!=13)
		{
			jump(13,14);
			cout<<"Invalid Input!"<<endl;
        		getche();
        		menu();
		}
	}
	catch(int cn){
		cout << "invalid input!";
		exit(1);
	}
    set_cnic(cn);
      fflush(stdin);
      fflush(stdin);
        jump(10,12);
        char sta[10];
        fflush(stdin);
        cout<<"Enter your status : ";
        gets(sta);
        fflush(stdin);
        set_status(sta);
        set_coverd_distance(0);
        fflush(stdin);
        jump(10,14);
      cout<<"Enter Your Password: ";
       
    for(i=0;;)
    {
        a=getch();
        if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9'))
        {
            pass[i]=a;
            ++i;
            cout<<"*";
        }
        if(a=='\b'&&i>=1)
        {
            cout<<"\b \b";
            --i;
        }
        if(a=='\r')
        {
            pass[i]='\0';
            break;
        }
    }
  
       set_password(pass);
   }
    int store_data()
   {
      FILE *fu;
      system("cls");
    jump(10,5);
    fflush(stdin);
    system("cls");
    fu = fopen("record_user.dat","ab+");
    if(fu == NULL)
	{
        jump(10,5);
        printf("Error in opening file");
        exit(1);
    }
    fflush(stdin);
    fflush(stdin);
    int i=0;
    reg();
    fwrite(this,sizeof(*this),1,fu);
    system("cls");
        fflush(stdin);
    fclose(fu);
    jump(10,20);
    printf("Press any key to continue...");
    getch();
    menu();
   }
   void view_all_data()
   { 
     char stmobile[12];
     char pass[32],a;
       int j=8,i=1;
        system("cls");
             jump(10,5);
    printf("Enter mobile number of person to view record : ");
    fflush(stdin);
    gets(stmobile);
    jump(10,6);
    cout<<"Enter Your Password: ";
    for(i=0;;)
    {
        a=getch();
        if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9'))
        {
            pass[i]=a;
            ++i;
            cout<<"*";
        }
        if(a=='\b'&&i>=1)
        {
            cout<<"\b \b";
            --i;
        }
        if(a=='\r')
        {
            pass[i]='\0';
            break;
        }
    }
     system("cls");
    jump(10,3);
    cout<<"<---:VIEW RECORD:--->";
    jump(10,5);
    cout<<"S.No  UserName           Mobile          CNIC        Covered distance(km)  Occupation";
    jump(10,6);
    cout<<"-----------------------------------------------------------------------------------";
     ifstream fin;
       fin.open("record_user.dat",ios::in|ios::binary);
    if(!fin)
       {
           jump(10,8);
         cout<<"File not found";
         getche();
         menu();
       }
       else
       {
         fin.read((char*)this,sizeof(*this));
         while(!fin.eof())
         {
             if(strcmp(stmobile,get_mobile()) == 0 && strcmp(pass,get_passowrd()) == 0)
             {
             jump(10,j); 
             cout<<i<<"     "<<get_name()<<"         "<<get_mobile()<<"     "<<get_cnic()<<"       "<<get_coverd_distance()<<"              "<<get_status();
              i++;j++;
             }
             fin.read((char*)this,sizeof(*this));
       }
       }
       fin.close();
       jump(10,j+3);
       cout<<"Press any key to continue...";
      getch();
      menu();
   }
   
   void Delete_Data()
   {
      char stname[12];
      char pass[32],a;
      int i;
    FILE *fp,*ft;
    system("cls");
    box();
    jump(10,3);
    printf("<---:DELETE RECORD:--->");
    jump(10,5);
    printf("Enter Mobile Number to delete record : ");
    fflush(stdin);
    gets(stname);
      jump(10,7);
      cout<<"Enter Your Password: ";
       
    for(i=0;;)
    {
        a=getch();
        if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9'))
        {
            pass[i]=a;
            ++i;
            cout<<"*";
        }
        if(a=='\b'&&i>=1)
        {
            cout<<"\b \b";
            --i;
        }
        if(a=='\r')
        {
            pass[i]='\0';
            break;
        }
    }
    fp = fopen("record_user.dat","rb+");
    if(fp == NULL){
        jump(10,6);
        printf("Error in opening file");
        exit(1);
    }
    ft = fopen("temp.dat","wb+");
    if(ft == NULL){
        jump(10,6);
        printf("Error in opening file");
        exit(1);
    }
    int count;
    while(fread(this,sizeof(*this),1,fp) == 1){
        if(strcmp(stname,get_mobile()) != 0 && strcmp(pass,get_passowrd()) != 0){
            fwrite(this,sizeof(*this),1,ft);
        
        }
count++;
    }
    if(count>0)
    printf("\t\tRemoved Succesfully!");
    fclose(fp);
    fclose(ft);
    remove("record_user.dat");
    rename("temp.dat","record_user.dat");
    jump(10,10);
    printf("Press any key to continue...");
    getch();
    menu();
   }
   
   void Booking()
   {
     int test,option,test1,req_seats,i;
     char pass[32],a;
	   string promocode;
       char ststart[20], stend[20], status[10], stname[20];
     char category;
     Captain std;
     FILE *fp;
	   FILE *fu;
     system("cls");
    jump(10,5);
    fflush(stdin);
    system("cls");
    fflush(stdin);
    box();
    jump(10,6);
    cout<<"Enter your Mobile Number : ";
    gets(stname);
     jump(10,8);
    cout<<"Enter Your Password: ";
  
    for(i=0;;)
    {
        a=getch();
        if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9'))
        {
            pass[i]=a;
            ++i;
            cout<<"*";
        }
        if(a=='\b'&&i>=1)
        {
            cout<<"\b \b";
            --i;
        }
        if(a=='\r')
        {
            pass[i]='\0';
            break;
        }
    }
    fu = fopen("record_user.dat","ab+");
    if(fu == NULL){
        jump(10,5);
        cout<<"Error in opening file";
        exit(1);
    }
    test =0;
    while(fread(this,sizeof(*this),1,fu ) == 1){
        if(strcmp(stname,get_mobile()) == 0 && strcmp(pass,get_passowrd()) == 0){
        	++test;
           system("cls");
           box();
            jump(10,8);
            cout<<"Name : "<<get_name();
            jump(10,9);
            cout<<"Mobile Number : "<<get_mobile();
            jump(10,10);
            cout<<"CNIC : "<<get_cnic();
            jump(10,11);
            cout<<"Covered Distance : "<<get_coverd_distance();
            jump(10,12);
            cout<<"Status : "<<get_status();
        }
    }
    if(test<1)
    {
    	jump(12,15);
      cout<<"Your not registered!";
    	getch();
    	jump(10,16);
    	printf("Kindly First Regiter Yourself");
    	jump(10,17);
    	printf("Press 1 to register, 2 to go back & 3 go to menu!");
    	cin>>option;
    	switch(option)
		{
    		case 1:
          store_data();
    		break;
    		case 2:
    			 Booking();
    			break;
    		case 3:
    			menu();
    			break;
    		default:
    			printf("Invalid Input!");
    			menu();
    			break;
		}
	}
   fclose(fu);
    getche();
    system("cls");
    
    box();
    jump(10,5);
    cout<<"Enter The starting point : ";
    gets(ststart);
    jump(10,6);
    cout<<"Enter The End point : ";
    gets(stend);
    fflush(stdin);
    jump(10,7);
    cout<<"Enter the category : ";
    fflush(stdin);
     cin>>category;
    jump(10,8);
	cout<<"Enter the rquired seats: ";
  cin>>req_seats;
   fp = fopen("record.dat","rb+");
    if(fp == NULL){
        jump(10,6);
        cout<<"Error in opening file";
        exit(1);
    }
      test1=0;
    while(fread(&std,sizeof(std),1,fp ) == 1)
    {
    if(strcmp(strupr(ststart),strupr(std.get_starting_point()))==0&&strcmp(strupr(stend),strupr(std.get_end_point()))== 0&&std.C.get_category()==category&&(req_seats<=std.C.get_seats()))
    	{
    		test1=1;
    		system("cls");
    		box();
    		jump(10,8);
            cout<<"Name : "<<std.get_name();
            jump(10,9);
            cout<<"Mobile Number :"<<std.get_mobile(); 
            jump(10,10);
            cout<<"CNIC : "<<std.get_cnic();
            jump(10,11);
            cout<<"Course : "<<std.C.get_plate_no();
            jump(10,12);
            cout<<"Cartype : "<<std.C.get_cartype();
            
            jump(10,13);
            cout<<"Seats : "<<std.C.get_seats();
            
            jump(10,14);
            cout<<"Start Point : "<<std.get_starting_point();
            
            jump(10,15);
            cout<<"Endpoint : "<<std.get_end_point();
            
            jump(10,16);
            cout<<"Category : "<<std.C.get_category();
            jump(10,17);
             cout<<"Rides Completed : "<<std.get_rides();
            getche();
        }
        
    }	
     if(test1<1)
        {
        	system("cls");
        	jump(10,14);
		cout<<"SORRY WE CURRENTLY HAVE NO CAPTAIN AVAILAIBLE AT THE MOMENT!";
        fclose(fp);
	    getche();
	    system("cls");
        menu();
		}
  fclose(fp);
	getche();
	system("cls");	
		if(strcmp("STUDENT",strupr(get_status()))==0||strcmp("student",get_status())==0)
	{
		cout<<"\t\t USe code 'DIS100' for discount";
	}
  float dis =fare(ststart,stend),base_fair;
  if(category=='A'||category=='a')
	{
		base_fair=250;
	}
  else if(category=='A'||category=='a')
	{
		base_fair=150;
	}
  else if(category=='A'||category=='a')
	{
		base_fair=100;
	}
  else if(category=='A'||category=='a')
	{
		base_fair=50;
	}
   else if(category=='A'||category=='a')
	{
		base_fair=20;
	}
   fflush(stdin);
   
   cout<<"Promo Code: ";
   getline(cin,promocode);
  fflush(stdin);
  base_fair =100;
	dis = fare(ststart,stend);
  if("DIS100"==promocode||get_coverd_distance()>100)
  {
   cout<<"\tExpected Fair :"<<((dis+base_fair)*req_seats*3)-100;
  }
  else
   cout<<"\tExpected Fair :"<<(dis+base_fair)*req_seats*2;
  getche();
    jump(10,20);
    cout<<"If you wish to use the service press 1 or press 2:";
    int wish=0;
    cin>>wish;
    if(wish==1)
    {
     FILE *fu;
     system("cls");
    jump(10,3);
     fu = fopen("record_user.dat","rb+");
    if(fu == NULL){
        jump(10,6);
        printf("Error in opening file");
        exit(1);
    }
    rewind(fu);
     fflush(stdin);
    while(fread(this,sizeof(*this),1,fu) == 1)
    {
        if(strcmp(stname,get_mobile())==0){
            jump(10,7);
            set_coverd_distance(get_coverd_distance()+dis);
            fseek(fu ,-sizeof(*this),SEEK_CUR);
            fwrite(this,sizeof(*this),1,fu);
            break;
        }
    }
      fclose(fu);
    system("cls");
    jump(10,16);
    FILE *fp;
     system("cls");
    jump(10,3);
    cout<<"<---:ENTER THE NAME OF THE CAPTAIN:--->";
    jump(10,5);
    cout<<"Enter name : ";
    fflush(stdin);
     gets(stname);
     fp = fopen("record.dat","rb+");
    if(fp == NULL){
        jump(10,6);
        printf("Error in opening file");
        exit(1);
    }
     rewind(fp);
    fflush(stdin);
     while(fread(&std,sizeof(std),1,fp) == 1)
    {
        if(strcmp(stname,std.get_name())==0){
            jump(10,7);
        
            int h = std.get_rides();
            int f = this->get_rides();
            std.C.set_seats(std.C.get_seats()-req_seats);
            std.set_rides(++h);
            this->set_rides(++f);
            fseek(fp ,-sizeof(std),SEEK_CUR);
            fwrite(&std,sizeof(std),1,fp);
            break;
        }
    }
    fclose(fu);
    jump(10,16);
    printf("Press any key to continue...");
    getch();
    menu();
    }
     else
     menu();
   }
   void update_data()
   {
       char stname[20];
    string choice;
    FILE *fp;
    system("cls");
    box();
    jump(10,3);
    printf("<---:MODIFY RECORD:--->");
    jump(10,5);
    printf("Enter mobile Number to modify : ");
    fflush(stdin);
    gets(stname);
    system("cls");
    jump(10,5);
    printf("Enter the infotmation you want to modify :");
    getline(cin,choice);
    fflush(stdin);
    fp = fopen("record.dat","rb+");
    if(fp == NULL)
	{
        jump(10,6);
        printf("Error in opening file");
        exit(1);
    }
    rewind(fp);
    fflush(stdin);
    while(fread(this,sizeof(*this),1,fp) == 1)
    {
    	    fflush(stdin);
        if(strcmp(stname,get_mobile()) == 0){
            if(choice=="NAME")
            {
               char nam[20];
            	 jump(10,7);
            printf("Enter name : ");
            gets(nam);
            set_name(nam);
			}
			else if(choice=="mobile")
            {
               char mobil[12];
            	 jump(10,7);
            printf("Enter Mobile No : ");
            gets(mobil);
            set_mobile(mobil);
			}
      else if(choice=="status")
            {
              char c[20];
            	 jump(10,7);
            printf("Enter Status : ");
            gets(c);
            set_status(c);
        }
    else
    {
    	jump(10,9);
    	printf("Invalid input!");
    	getch();
    	update_data();
	}
        
            fseek(fp ,-sizeof(*this),SEEK_CUR);
            fwrite(this,sizeof(*this),1,fp);
            break;
            
        }
    }
    fclose(fp);
    jump(10,16);
    printf("Press any key to continue...");
    getch();
    menu();
   }
};

int main()
{
	system("color b0");
 box();
	int i,j;
	for ( i=17 ; i<=54 ; i++ ) // upper border
	{
		jump(i,4);
		printf("%c",176);
	}
	jump(17,5);
    printf("\a\a<---:Management System:--->");
    for ( i=17 ; i<=54 ; i++ ) // lower border
	{
		jump(i,6);
		printf("%c",176);
		
	}
	jump(26,8);
    printf("W  E  L  C  O  M  E");
    jump(29,11);
    printf("Developed By:");
    jump(24,13);
    //printf("Muhammad Junaid Asif 22K-4369");
    jump(24,14);
   // printf("Ashish Maheshwari 22K-4533");
    jump(24,15);
    printf("Abdul Rehamn 22k-4291");
    jump(26,19);
    printf("Course  Instructor:");
    jump(28,21);
    printf("Miss NIDA MUNAWAR");
    jump(15,23);
    printf("LOADING...");
     for ( i=15 ; i<=55 ; i++ ) // loader;
	{
		jump(i,24);
		printf("%c",178);
	}
	jump(22,28);
    printf("Press any key to continue...");
    getch();
    menu();
    return 0;
 
}
void box()
{
 int i;
	for ( i=2 ; i<=30 ; i++ ) // for y left
	{
		jump(4,i);
		printf("*");
	}
	for ( i=4 ; i<=70 ; i++ ) // for x up
	{
		jump(i,2);
		printf("*");
	}
	for ( i=4 ; i<=70 ; i++ ) // for x down
    {
		jump(i,30);
		printf("*");
	}
	for ( i=2 ; i<=30 ; i++ ) // for y right
	{
		jump(70,i);
		printf("*");
	}

}
void jump(int x,int y)
{
        COORD c;
        c.X=x;
        c.Y=y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
void menu()
{
    int choice;
    string mob;
    Captain C1;
    User U1;
    system("cls");
    box();
    jump(10,3);
    printf("\t\t   <---:MENU:--->");
    printf("\n\t\t         ----------------");
    jump(10,6);
    printf("Enter appropriate number to perform following task.");
    jump(10,8);
    printf("1 : Are You A Captain");
    jump(10,10);
    printf("2 : Are You A User");
    jump(10,12);
    printf("3 : Exit");
    jump(10,27);
    printf("Enter your Choice : ");
    jump(30,27);
    cin>>choice;
    switch(choice)
    {
    case 1:
         system("cls");
          box();
          jump(10,3);
          printf("\t\t   <---:CAPTAIN'S MENU:--->");
          printf("\n\t\t         ----------------");
          jump(10,6);
          printf("Enter appropriate number to perform following task.");
          jump(10,8);
          printf("1 : To Signup as a Captain");
          jump(10,10);
          printf("2 : View Your Record");
          jump(10,12);
          printf("3 : Modify Captain Record");
          jump(10,14);
          printf("4 : Delete Your Record");
          jump(10,16);
          printf("5 :To go back to main Menu");
          jump(10,27);
           printf("Enter your Choice : ");
          jump(30,27);
          cin>>choice;
          switch (choice)
          {
          case 1:
               C1.reg();
               C1.store_data();
               menu();
            break;
          case 2:
                 C1.view_all_data();
                 menu();
            break;
            case 3:
            C1.update_data();
            break;
            case 4:
               C1.Delete_Data();
            break;
            case 5:
                  menu();
            break;
          default:
                 jump(10,19);
                printf("Invalid Choice!");
            break;
          }
        break;
        
    case 2:
          system("cls");
          box();
          jump(10,3);
          printf("\t\t   <---:USER'S MENU:--->");
          printf("\n\t\t         ----------------");
          jump(10,6);
          printf("Enter appropriate number to perform following task.");
          jump(10,8);
          printf("1 : To Signup as a USER");
          jump(10,10);
          printf("2 : View Your Record");
          jump(10,12);
          printf("3 : Book Your Ride");
          
          jump(10,14);
          printf("4 : Delete Your Record");
           jump(10,16);
          printf("5 : Back to Main menu");
          jump(10,27);
           printf("Enter your Choice : ");
          jump(30,27);
          cin>>choice;
          switch (choice)
          {
          case 1:
               U1.store_data();
            break;
          case 2:
                 U1.view_all_data();
                 menu();
            break;
            case 4:
               U1.Delete_Data();
            break;
            case 3:
              U1.Booking();
            break;
            case 5:
                menu();
                break;
          default:
                 jump(10,19);
                printf("Invalid Choice!");
            break;
          }
    	break;
    
    case 3:
        exit(1);
    	break;    
	default:
        jump(10,19);
        printf("Invalid Choice!");
        getch();
        menu();
    }
}
float fare(char area[10],char area1[10])
{
	float long1,lat1,long2,lat2,distance,r=6378;
	int i;
	char  proper[50],proper1[50], ch;
	
	i = 0;
	
	for(i=0;i<=strlen(area);i++)
	{
		proper[i] = toupper(area[i]);
	}
	printf("\n\n");
	
	if(strcmp(proper, "BHARIATOWN") == 0)
	{
	long1=67.0841;
		lat1=24.9253;
	}
	 if(strcmp(proper, "TARIQROAD") == 0)
	{
	long1=67.059906;
	lat1=24.871641;
	}
	 if(strcmp(proper, "UNIVERSITYOFKARACHI") == 0)
	{
			long1=67.1244;
		lat1=24.9391;
	}
	 if(strcmp(proper, "DISCOBAKERY") == 0)
	{
			long1=67.097218306;
		lat1=24.928846576;
	}
	 if(strcmp(proper, "FAST") == 0)
	{
		long1=67.2647;
		lat1=24.8569;
	}
	 if(strcmp(proper, "CLIFTON") == 0)
	{
		long1=67.0306;
		lat1=24.8021;
	
	}
	 if(strcmp(proper, "BURNSROAD") == 0)
	{
		long1=67.0174;
		lat1=24.8554;
	}
	 if(strcmp(proper, "NORTHNAZIMABAD") == 0)
	{
			long1=67.0423;
		lat1=24.9372;
	}
	 if(strcmp(proper, "GULSHANEIQBAL") == 0)
	{
		long1=67.0841;
		lat1=24.9253;
	}
	 if(strcmp(proper, "DEFENCE") == 0)
	{
		long1=67.0577;
		lat1=24.8043;
	}
	else if(strcmp(proper, "BUFFERZONE") == 0)
	{
		long1=67.0678;
		lat1=24.9571;
	}
	 if(strcmp(proper, "JOHAR") == 0)
	{
		long1=74.2728;
		lat1=31.4697;
	}
	 if(strcmp(proper, "HYDERI") == 0)
	{
		long1=67.0601;
		lat1=24.9395;
	}
     if(strcmp(proper, "BAHADURABAD") == 0)
	{
		long1=67.069389;
		lat1=24.882450;	
	}
	if(strcmp(proper, "FEDERALBAREA")==0);
	{
	    long1=67.0641;
		lat1=24.9275;
	}

	
	for(i=0;i<=strlen(area1);i++)
	{
		proper1[i] = toupper(area1[i]);
	}
	printf("\n\n");
	
	if((strcmp(proper1, "BHARIATOWN") == 0) && (strcmp(proper1, "BHARIA TOWN") == 0))
	{
	long2=2.0841;
		lat2=24.9253;
	}
	 if((strcmp(proper1, "TARIQROAD") == 0) && (strcmp(proper1, "TARIQ ROAD") == 0))
	{
	long2=78.059906;
	lat2=22.871641;
	}
	 if((strcmp(proper1, "UNIVERSITYOFKARACHI") == 0) && (strcmp(proper1, "UNIVERSITY OF KARACHI") == 0))
	{
			long2=67.1244;
		lat2=24.9391;
	}
	 if((strcmp(proper1, "DISCOBAKERY") == 0) && (strcmp(proper1, "DISCO BAKERY") == 0))
	{
			long2=67.097218306;
		lat2=24.928846576;
	}
	 if(strcmp(proper1, "FAST") == 0)
	{
		long2=67.2647;
		lat2=24.8569;
	}
	 if(strcmp(proper1, "CLIFTON") == 0)
	{
		long2=67.0306;
		lat2=24.8021;
	
	}
	 if((strcmp(proper1, "BURNSROAD") == 0) && (strcmp(proper1, "BURNS ROAD") == 0))
	{
		long2=67.0174;
		lat2=24.8554;
	}
	 if((strcmp(proper1, "NORTHNAZIMABAD") == 0) && (strcmp(proper1, "NORTH NAZIMABAD") == 0))
	{
			long2=67.0423;
		lat2=24.9372;
	}
	 if((strcmp(proper1, "GULSHANEIQBAL") == 0) && (strcmp(proper1, "GULSHAN-E-IQBAL") == 0))
	{
		long2=67.0841;
		lat2=24.9253;
	}
	 if(strcmp(proper1, "DEFENCE") == 0)
	{
		long2=67.0577;
		lat2=24.8043;
	}
	else if((strcmp(proper1, "BUFFERZONE") == 0) && (strcmp(proper1, "BUFFER ZONE") == 0))
	{
		long2=67.0678;
		lat2=24.9571;
	}
	 if(strcmp(proper1, "JOHAR") == 0)
	{
		long2=74.2728;
		lat2=31.4697;
	}
	 if(strcmp(proper1, "HYDERI") == 0)
	{
		long2=67.0601;
		lat2=24.9395;
	}
     if(strcmp(proper1, "BAHADURABAD") == 0)
	{
		long2=66.069389;
		lat2=24.882450;	
	}
	if(strcmp(proper1, "FEDERALBAREA")==0);
	{
	    long2=67.0641;
		lat2=24.9275;
	}
	;
	 distance= 2*r*asin(sqrt(pow(sin((lat2-lat1)/2),2) + (1-pow(sin((lat2-lat1)/2),2)) - pow(sin((lat2+lat1)/2),2) * pow(sin((long2-long1)/2),2)));
    srand(time(NULL));
	distance= distance/1000-(rand()%10);
	
	return distance;
}