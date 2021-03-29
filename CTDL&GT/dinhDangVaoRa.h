//create object input n length va arr tam save char input form keyboard
//INPUTMAX = 200
struct INPUTSTR{  
	unsigned int n;
	char KEY[INPUTMAX];
};
//DINH dang nhap vao la lop theo chua HVCNBCVT
//D18CQCN02-N 
//- dau ko dc la dau gach ngang , lkhong duoc nhap 2 dau gach ngang lien tiep, khong co khoang trang ,va in hoa
//-->((mn>=65&&mn<=90)||(mn>=97&&mn<=122)||mn=='-'||(mn>=48&&mn<=57))<--
char *dinhDangNhapLop(char Type,int len)
{
	
	int MAXNHAP = len;
	if (MAXNHAP == 0)MAXNHAP = INPUTMAX;
	
	fflush(stdin);
	//tao ra doi tuong nhap
	INPUTSTR NHAP;	
	NHAP.n = 0;
	while(true)
	{
		char mn=getch();
		//co nhap thoa man tinh chat rang buoc du lieu va kich thuco toi da cho phep
		if (!kbhit()&&
		!(!((int)mn>=65&&(int)mn<=90)&&!((int)mn>=97&&(int)mn<=122)&&mn!='-'&&!((int)mn>=48&&(int)mn<=57))&&
		NHAP.n<MAXNHAP)
		{

			//khong cho nhap 2 ki tu lien tiep la dau gach ngang
			if (NHAP.n>0&&NHAP.KEY[NHAP.n-1]=='-'&&mn=='-')
			{
				continue;
			}
			//ki tu dau khong duoc la dau gach ngang , cac ki tu ko phai la dau nhap vo tu
			if (!(NHAP.n==0 && mn=='-') )
			{
			if (Type == 'U')mn = toupper(mn);
			else if(Type == 'L')mn = tolower(mn);
			
			cout << mn;
			//dua no vao doi tuong nhap cua chung ta
			NHAP.KEY[NHAP.n]=mn;
			NHAP.n++;
			}
			
		}
		if (mn==ENTER)
		{
			//neu no la khong rong thi cho ket thuc
			if (NHAP.n>0)
			{
		
					break;
			}
			// nguoc lai thi tiep tuc nhap
			else if(NHAP.n<=0){
				continue;
			}
			
		}
//		end enter 
		//Backspace
		else if(mn == 8&& NHAP.n > 0)
		{
			gotoxy(getX()-1,getY());
			cout << " ";
			gotoxy(getX()-1,getY());
		
			NHAP.n--;
			
		}
//		end Backspace 
	}
	char NAME[NHAP.n+1];
	for (int i=0;i<NHAP.n;i++)
	{
		NAME[i] =  NHAP.KEY[i];
	}
	NAME[NHAP.n]='\0';
	
	return NAME;
	
}
//end dinh dang nhap lop 

//dinh dang theo ma so sinh vien
// N18DCCN029--> chi duoc nhhap chu va so va tat ca deu in hoa
char *dinhDangMSSV(char Type,int len)
{
	
	int MAXNHAP = len;
	if (MAXNHAP == 0)MAXNHAP = INPUTMAX;
	
	fflush(stdin);
	//tao nen doi tuong nhap
	INPUTSTR NHAP;	
	NHAP.n = 0;
	while(true)
	{
		char mn=getch();
		if (!kbhit()
		&&!(!((int)mn>=65&&(int)mn<=90)&&!((int)mn>=97&&(int)mn<=122)&&!((int)mn>=48&&(int)mn<=57))
		&&NHAP.n<MAXNHAP)
		{

			if (NHAP.n>=0  )
			{
			if (Type == 'U')mn = toupper(mn);
			else if(Type == 'L')mn = tolower(mn);
			
			cout << mn;
			NHAP.KEY[NHAP.n]=mn;
			NHAP.n++;
			}
			
		}
		//enter
		if (mn==ENTER)
		{
				if(NHAP.n>0){
						break;
				}
			
			
		}
//		end enter
		else if(mn == 8&& NHAP.n > 0)
		{
			gotoxy(getX()-1,getY());
			cout << " ";
			gotoxy(getX()-1,getY());
		
			NHAP.n--;
			
		}
//		end Backspace 
	}
	char NAME[NHAP.n+1];
	for (int i=0;i<NHAP.n;i++)
	{
		NAME[i] =  NHAP.KEY[i];
	}
	NAME[NHAP.n]='\0';
	return NAME;
	
}
//end dinh dang nhap ma so sinhn vien 


//Dinh dang nhap ten
//Nguyen Anh Duy -> chi duoc chu hoa, thuong va khoang trang sau khoang trang viet hoa len
char *dinhDangNhapTen(int len)
{

	int MAXNHAP = len;
	if (MAXNHAP == 0)MAXNHAP = INPUTMAX;
	
	fflush(stdin);
	INPUTSTR NHAP;	
	NHAP.n = 0;
	while(true)
	{
		char mn=getch();
		//neu co nhap va thoa man chu hoa va thuong va khoang trang thi cho nhap va nho hon max nhap cho phep
		if (!kbhit()&&!(!((int)mn>=65&&(int)mn<=90)&&!((int)mn>=97&&(int)mn<=122)&&mn!=' ')&& NHAP.n<MAXNHAP)
		{
			// khong cho phep nhap hai khoang trang lien tiep
			if (NHAP.n>0&&NHAP.KEY[NHAP.n-1]==' '&&mn==' ')
			{
				continue;
			}
			// ki tu dau tien khong la khoang trang
			if (!(NHAP.n==0 && mn==' ') )
			{
			//ki tu dauu nen viet hoa
			if (NHAP.n==0)
			mn = toupper(mn);
//			else 
//			{
//				 mn = tolower(mn);
//			}
			else 
			{
				//sau koang trang thi viet hoa
				if (NHAP.KEY[NHAP.n-1]==' ')mn = toupper(mn);
				// con khong thi viet thuong
				else mn = tolower(mn);
			}
			
			
			cout << mn;
			NHAP.KEY[NHAP.n]=mn;
			NHAP.n++;
			}
			
		}
		// su ly su kien an nut enter
		if (mn==ENTER)
		{
			if (NHAP.n>0&&NHAP.KEY[NHAP.n-1]==' ')
			{
			gotoxy(getX()-1,getY());
			cout << " ";
			gotoxy(getX()-1,getY());
			if (NHAP.n > 0) 
			{
				NHAP.n--;
			}
			
			}else if(NHAP.n<=0){
				continue;
			}
			break;
		}
//		end su kien an nut enter 
//		su ly su kien nut xoa 
		else if(mn == BACKSPACE && NHAP.n > 0)
		{
			gotoxy(getX()-1,getY());
			cout << " ";
			gotoxy(getX()-1,getY());
				
		
			NHAP.n--;
					
			
		}
	}
	//coppy no qua thoi 
char NAME[NHAP.n+1];
	for (int i=0;i<NHAP.n;i++)
	{
		NAME[i] =  NHAP.KEY[i];
	}
	// ki tu cuoi la null 
	NAME[NHAP.n]='\0';
	return NAME;
	
}
//end dinh dang nhap ten 

//bat dau cho dinh danh nhap so 
//24178136855164656 --> chi toan la so
char *dinhDangSo(int len)
{

	fflush(stdin);
	INPUTSTR NHAP;
	int MAXNHAP = len;
	if (MAXNHAP == 0)MAXNHAP = INPUTMAX;
	NHAP.n = 0;
	while(true)
	{
		char mn=getch();
		if (NHAP.n<MAXNHAP)
		{
			// co nhap va chi toan la so va nho hon kich thuoc toi da thi cho no nhap
			if (!kbhit()&&((int)mn>=48&&(int)mn<=57)&&NHAP.n<MAXNHAP)
			{
				cout << mn;
				NHAP.KEY[NHAP.n]=mn;
				NHAP.n++;
			}			
		}
		// bat su kien cho phimm xoa
		if(mn == BACKSPACE && NHAP.n > 0)
		{
			gotoxy(getX()-1,getY());
			cout << " ";
			gotoxy(getX()-1,getY());
			NHAP.n--;
					

			
		}
//		end su kien cho phim xoa 
//		bat su kien cho enter 
		if (mn == ENTER && NHAP.n >0)
		{
			break;
		}
//		end su kien cho enter 

	}	
	char Num[NHAP.n+1];
	for (int i=0;i<NHAP.n;i++)
	{
		Num[i] =  NHAP.KEY[i];
	}
	Num[NHAP.n]='\0';
	
	return Num;
}
