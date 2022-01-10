/* project for the fulfilment of class 12
   project name    : telephone Directory
   made by         : Priyansh Srivastava and Yashash Gupta
*/
#include<fstream.H>
#include<iostream.H>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>


class telephone
{
  private:
     char name[30];
     char fname[30];        //father's name
     char addr[100];
     char phoneno[15];
     char city[20];
     char state[30];
     char bui_addr[100];	//buisness address
     char bui_phoneno[15];      //buisness phone no
     char email[50];
  public:

	 void read_data()
	 {
	  cout<<"\n Name                :";
	  cin>>name;
	  cout<<"\n Father name         :";
	  cin>>fname;
	  cout<<"\n Address             :";
	  cin>>addr;
	  cout<<"\n Phone No            :";
	  cin>>phoneno;
	  cout<<"\n city                :";
	  cin>>city;
	  cout<<"\n State               :";
	  cin>>state;
	  cout<<"\n Business addr    :";
	  cin>>bui_addr;
	  cout<<"\n Business phoneno no . :";
	  cin>>bui_phoneno;
	  cout<<"\n Email               :";
	  cin>>email;
	  }

	  void display_record()   //displaying records
	  {
	  clrscr();
	  cout<<"\n\t\t\t\t Subscriber Details";
	  cout<<"\n\t\t=============================================";
	  cout<<"\n\n\t\tName                             :  ";
	  cout<<name;
	  cout<<"\n\n\t\tFather name                      :  ";
	  cout<<fname;
	  cout<<"\n\n\t\tAddress                          :  ";
	  cout<<addr;
	  cout<<"\n\n\t\tPhone No                         :  ";
	  cout<<phoneno;
	  cout<<"\n\n\t\tcity                             :  ";
	  cout<<city;
	  cout<<"\n\n\t\tState                            :  ";
	  cout<<state;
	  cout<<"\n\n\t\tBusiness addr                 :  ";
	  cout<<bui_addr;
	  cout<<"\n\n\t\tBusiness phoneno no .              :  ";
	  cout<<bui_phoneno;
	  cout<<"\n\n\t\tEmail                            :  ";
	  cout<<email;
	  }

	  void disp_name_phoneno()
	   {
	       cout<<"\n"<<name<<"\t\t\t"<<phoneno<<"\t"<<addr;
	   }


	 /* function to count no of pages */
	 int count_pages()
	 {
	   int rec,pages;
	   rec=pages=0;
	   ifstream fin;
	   fin.open("telephone.dat",ios::binary);
	   while(fin.read((char*)this,sizeof(telephone)))
	       rec++;
	   fin.close();

	   pages= rec/20;
	   if((rec%20)!=0)
		pages++;
	   return(pages);
	 }


	 void main_menu();
	 void search_menu();
	 void report_menu();
	 void add_member();
	 void delete_member();
	 void modify_member();

	 /*** search menu option */
	 void search_name();
	 void search_phoneno();
	 void search_addr();
	 void search_email();
	 void search_fname();

	 /* report menu options */
	 void report_list();
	 void report_name_phoneno();
	 void report_name_addr();
	 void report_name_phoneno_addr();
	 void report_name_email();
};

/* member funtion to define main menu */

void telephone :: main_menu()
{
     int choice;
	 do
	   {
	       clrscr();
	       cout<<"\n\n\n\t\t\t  M A I N    M E N U ";
	       cout<<"\n\n\t\t\t1.    Add Member";
	       cout<<"\n\n\t\t\t2.    Delete Member";
	       cout<<"\n\n\t\t\t3.    Modify Member";
	       cout<<"\n\n\t\t\t4.    Report";
	       cout<<"\n\n\t\t\t5.    Search";
	       cout<<"\n\n\t\t\t6.    Exit";
	       cout<<"\n\n\n\t\t\t    Enter your choice (1..6) :";
	       cin>>choice;

	       switch(choice)
		  {
		    case 1:           add_member();
				      break;

		    case 2:
				      delete_member();
				      break;

		    case 3:
				      modify_member();
				      break;

		    case 4:
				      report_menu();
				      break;

		    case 5:
				      search_menu();
				      break;

		    case 6:
				      break;

		    default:
				       cout<<"\n\n\n Wrong choice..... Try again";
				       getch();
		 }
	}while(choice!=6);

     return ;
}

/* member funtion to define SEARCH menu */

void telephone :: search_menu()
{
     int choice;
	 do
	   {
	       clrscr();
	       cout<<"\n\n\n\t\t\t    S E A R C H     M E N U ";
	       cout<<"\n\n\t\t\t1.    NAME";
	       cout<<"\n\n\t\t\t2.    PHONE NO";
	       cout<<"\n\n\t\t\t3.    ADDRESS";
	       cout<<"\n\n\t\t\t4.    EMAIL";
	       cout<<"\n\n\t\t\t5.    FATHER NAME";
	       cout<<"\n\n\t\t\t6.    Exit";
	       cout<<"\n\n\n\t\t\t    Enter your choice (1..6) :";
	       cin>>choice;
	       switch(choice)
		  {
		    case 1:           search_name();
				      break;

		    case 2:
				      search_phoneno();
				      break;

		    case 3:
				      search_addr();
				      break;

		    case 4:
				      search_email();
				      break;

		    case 5:
				      search_fname();
				      break;

		    case 6:
				      break;

		    default:
				       cout<<"\n\n\n Wrong choice..... Try again";
				       getch();
		 }
	}while(choice!=6);

     return ;
}

/* member funtion to define report menu */

void telephone :: report_menu()
{
     int choice;
	 do
	   {
	       clrscr();
	       cout<<"\n\n\n\t\t\t    R E P O R T      M E N U ";
	       cout<<"\n\n\t\t\t1.    LIST";
	       cout<<"\n\n\t\t\t2.    NAME --TELEPHONE";
	       cout<<"\n\n\t\t\t3.    NAME - TELEPHONE - ADDRESS";
	       cout<<"\n\n\t\t\t4.    NAME - EMAIL";
	       cout<<"\n\n\t\t\t5.    Exit";
	       cout<<"\n\n\n\t\t\t    Enter your choice (1..5) :";
	       cin>>choice;

	       switch(choice)
		  {
		    case 1:           report_list();
				      break;

		    case 2:
				      report_name_phoneno();
				      break;

		    case 3:
				      report_name_addr();
				      break;

		    case 4:
				      report_name_email();
				      break;

		    case 5:
				      break;

		    default:
				       cout<<"\n\n\n Wrong choice..... Try again";
				       getch();
		 }
	}while(choice!=5);

     return ;
}

/* member function to add new information in a file */
void telephone::add_member()
{
  ofstream file;
  file.open("telephoneno.dat",ios::app);
  read_data();
  file.write((char*)this ,sizeof(telephone));
  file.close();
  return;
}


/* delete a record from a binary file */
void telephone::delete_member()
{
  ofstream fout;
  ifstream fin;
  fin.open("telephone.dat",ios::binary);
  fout.open("temp.dat",ios::binary);
  char tphoneno[15];
  int found=0;
  cout<<"\n Enter Telephoneno no to delete :";
  cin>>tphoneno;
  while(fin.read((char *)this,sizeof(telephone)))
   {
     if(strcmp(this->phoneno,tphoneno)==0)
	fout.write((char*)this,sizeof(telephone));
     else
	found=1;
   }
   fin.close();
   fout.close();
   remove("telephone.dat");
   rename("temp.dat","telephone.dat");
   if(found==1)
       cout<<"\n Record Sucessfully deleted";
   else
       cout<<"\n Record not found";
   getch();

}

/* member function to modify member information */

void telephone::modify_member()
{
  ofstream fout;
  ifstream fin;
  fin.open("telephone.dat",ios::binary);
  fout.open("temp.dat",ios::binary);
  char tphoneno[15];
  int found=0;
  clrscr();
  cout<<"\n Enter Telephone no to modify :";
  cin>>tphoneno;
  while(fin.read((char *)this,sizeof(telephone)))
   {
     if(strcmp(tphoneno,this->phoneno)==0)
	{
	  cout<<"\n New values \n";
	  cout<<"\n Name    :";
	  cin>>this->name;
	  cout<<"\n Father name :";
	  cin>>this->fname;
	  cout<<"\n Address    :";
	  cin>>this->addr;
	  cout<<"\n city :";
	  cin>>this->city;
	  cout<<"\n State :";
	  cin>>this->state;
	  cout<<"\n Business addr :";
	  cin>>this->bui_addr;
	  cout<<"\n Business phoneno no . :";
	  cin>>this->bui_phoneno;
	  cout<<"\n Email :";
	  cin>>this->email;
	 found=1;
	 }
      fout.write((char*)this,sizeof(telephone));
    }
   fin.close();
   fout.close();
   remove("telephone.dat");
   rename("temp.dat","telephone.dat");
   if(found==1)
       cout<<"\n Record Sucessfully modified";
   else
       cout<<"\n Record not found";
   getch();
}


void telephone::search_addr()
{
   ifstream fin;
   fin.open("telephone.dat",ios::binary);
   char taddr[100];
   int found ;
   found =0;
   clrscr();
   cout<<"\n     Search Screen";
   cout<<"\n\n\t\t Address     :";
   cin>>taddr;
   while(fin.read((char*)this, sizeof(telephone)))
    {
	if (strcmp(taddr,this->addr)==0)
	   {
	      display_record();
	      found =1;
	      }
     }
   fin.close();
   if(found ==0)
       cout<<"\n Record does not exist";
    getch();
   return;
}


void telephone::search_email()
{
ifstream fin;
   fin.open("telephone.dat",ios::binary);
   char temail[100];
   int found ;
   found =0;
   system("cls");
   cout<<"\n     Search Screen";
   cout<<"\n\n\t\t Email     :";
   cin>>temail;
   while(fin.read((char*)this, sizeof(telephone)))
    {
	if (strcmp(temail,this->email)==0)
	   {
	      display_record();
	      found =1;
	      }
     }
   fin.close();
   if(found ==0)
       cout<<"\n Record does not exist";
    getch();
   return;

}


void telephone::search_fname()
{
  ifstream fin;
   fin.open("telephone.dat",ios::binary);
   char tfname[100];
   int found ;
   found =0;
   clrscr();
   cout<<"\n     Search Screen";
   cout<<"\n\n\t\t Father Name     :";
   cin>>tfname;
   while(fin.read((char*)this, sizeof(telephone)))
    {
	if (strcmp(tfname,this->fname)==0)
	   {
	      display_record();
	      found =1;
	      }
     }
   fin.close();
   if(found ==0)
       cout<<"\n Record does not exist";
    getch();
   return;
}


void telephone::search_name()
{
   ifstream fin;
   fin.open("telephone.dat",ios::binary);
   char tname[100];
   int found ;
   found =0;
   system("cls");
   cout<<"\n     Search Screen";
   cout<<"\n\n\t\t Name     :";
   cin>>tname;
   while(fin.read((char*)this, sizeof(telephone)))
    {
	if (strcmp(tname,this->name)==0)
	   {
	      display_record();
	      found =1;
	      }
     }
   fin.close();
   if(found ==0)
       cout<<"\n Record does not exist";
    getch();
   return;
}

void telephone::search_phoneno()
{
ifstream fin;
   fin.open("telephoneno.dat",ios::binary);
   char tphoneno[100];
   int found ;
   found =0;
   clrscr();
   cout<<"\n     Search Screen";
   cout<<"\n\n\t\t Phone No     :";
   cin>>tphoneno;
   while(fin.read((char*)this, sizeof(telephone)))
    {
	if (( strcmp(tphoneno,this->phoneno)==0) || strcmp(tphoneno,this->bui_phoneno)==0)
	   {
	      display_record();
	      found =1;
	      }
     }
   fin.close();
   if(found ==0)
       cout<<"\n Record does not exist";
    getch();
   return;
}


void telephone::report_list()
{
  int pages = count_pages();
  int cur_page=1;
  /* steps to show report menu and data */
  int n=0;
  ifstream fin;
  fin.open("telephone.dat",ios::binary);
  clrscr();

  cout<<"\n\t\t\t\t  Report                        "<<cur_page<< " of "<<pages;
  cout<<"\n-----------------------------------------------------------------------------";
  cout<<"\n\n S.No"<<"\t\t Name \t\t\tAddress\t\t Phone\t\tEmail";
  cout<<"\n-----------------------------------------------------------------------------";
  while(fin.read((char*)this, sizeof(telephone)))
  {
     n++;
     if(n%21==0)
       {
	 cout<<"\n----------------------------------------------------------------------";
	 cout<<"\n\t\t\t\tPress any key to continue...........";
	 getch();
	 cur_page++;
	 clrscr();
	 cout<<"\n\t\t\t\t  Report                        "<<cur_page<< " of "<<pages;
	 cout<<"\n--------------------------------------------------------------------------";
	 cout<<"\n\n S.No"<<"\t\t Name \t\t\tAddress\t\t Phone\t\tEmail";
	 cout<<"\n--------------------------------------------------------------------------";
       }
     cout<<"\n"<<n<<"\t |\t"<<this->name<<"\t |\t"<<this->name<<"\t |\t "<<this->phoneno<<"\t | \t"<<this->email;
  }
  cout<<"\n----------------------------------------------------------------------------";
  cout<<"\n Total Records :"<<n;
  fin.close();
  getch();
  return;


}


/* function to print name and addr  */
void telephone::report_name_addr()
{
  int pages = count_pages();
  int cur_page=1;
  /* steps to show report menu and data */
  int n=0;
  ifstream fin;
  fin.open("telephone.dat",ios::binary);
  clrscr();

  cout<<"\n\t\t\t\t  Report                        "<<cur_page<< " of "<<pages;
  cout<<"\n-----------------------------------------------------------------------------";
  cout<<"\n\n S.No"<<"\t\t Name \t\t\t\t\t\t Address";
  cout<<"\n-----------------------------------------------------------------------------";
  while(fin.read((char*)this, sizeof(telephone)))
  {
     n++;
     if(n%21==0)
       {
	 cout<<"\n----------------------------------------------------------------------";
	 cout<<"\n\t\t\t\tPress any key to continue...........";
	 getch();
	 cur_page++;
	 clrscr();
	 cout<<"\n\t\t\t\t  Report                        "<<cur_page<< " of "<<pages;
	 cout<<"\n--------------------------------------------------------------------------";
	 cout<<"\n S.No"<<"\t\t Name \t\t\t\t\t\t Address";
	 cout<<"\n--------------------------------------------------------------------------";
       }
     cout<<"\n"<<n<<"\t |\t"<<this->name<<"\t |\t\t\t\t\t"<<this->addr;
  }
  cout<<"\n----------------------------------------------------------------------------";
  cout<<"\n Total Records :"<<n;
  fin.close();
  getch();
  return;

}


/* member function to print name and email addr */

void telephone::report_name_email()
{
  int pages = count_pages();
  int cur_page=1;
  /* steps to show report menu and data */
  int n=0;
  ifstream fin;
  fin.open("telephone.dat",ios::binary);
  clrscr();

  cout<<"\n\t\t\t\t  Report                        "<<cur_page<< " of "<<pages;
  cout<<"\n-----------------------------------------------------------------------------";
  cout<<"\n\n S.No"<<"\t\t Name \t\t\t\t\t\t Email";
  cout<<"\n-----------------------------------------------------------------------------";
  while(fin.read((char*)this, sizeof(telephone)))
  {
     n++;
     if(n%21==0)
       {
	 cout<<"\n----------------------------------------------------------------------";
	 cout<<"\n\t\t\t\tPress any key to continue...........";
	 getch();
	 cur_page++;
	 clrscr();
	 cout<<"\n\t\t\t\t  Report                        "<<cur_page<< " of "<<pages;
	 cout<<"\n--------------------------------------------------------------------------";
	 cout<<"\n S.No"<<"\t\t Name \t\t\t\t\t\t Email";
	 cout<<"\n--------------------------------------------------------------------------";
       }
     cout<<"\n"<<n<<"\t |\t"<<this->name<<"\t |\t\t\t\t\t"<<this->email;
  }
  cout<<"\n----------------------------------------------------------------------------";
  cout<<"\n Total Records :"<<n;
  fin.close();
  getch();
  return;

}

void telephone::report_name_phoneno()
{
  int pages = count_pages();

  int cur_page=1;
  /* steps to show report menu and data */
  int n=0;
  ifstream fin;
  fin.open("telephone.dat",ios::binary);
  clrscr();

  cout<<"\n\t\t\t\t  Report                        "<<cur_page<< " of "<<pages;
  cout<<"\n-----------------------------------------------------------------------------";
  cout<<"\n\n S.No"<<"\t\t Name \t\t\t\t\t\t Phone";
  cout<<"\n-----------------------------------------------------------------------------";
  while(fin.read((char*)this, sizeof(telephone)))
  {
     n++;
     if(n%21==0)
       {
	 cout<<"\n----------------------------------------------------------------------";
	 cout<<"\n\t\t\t\tPress any key to continue...........";
	 getch();
	 cur_page++;
	 clrscr();
	 cout<<"\n\t\t\t\t  Report                        "<<cur_page<< " of "<<pages;
	 cout<<"\n--------------------------------------------------------------------------";
	 cout<<"\n S.No"<<"\t\t Name \t\t\t\t\t\t Phone";
	 cout<<"\n--------------------------------------------------------------------------";
       }
     cout<<"\n"<<n<<"\t |\t"<<this->name<<"\t |\t\t\t\t\t"<<this->phoneno;
  }
  cout<<"\n----------------------------------------------------------------------------";
  cout<<"\n Total Records :"<<n;
  fin.close();
  getch();
  return;
}



int main()
 {
	  telephone t;
	  t.main_menu();
	  return 0;
}
