#include"define.h"
#include<windows.h>xo
void fullscreen()
{
	keybd_event(VK_MENU,0x38,0,0);
	keybd_event(VK_RETURN,0x1c,0,0);
	keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
	keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
}
void resizeConsole(int width, int height)
{
	HWND c = GetConsoleWindow();
	DWORD style = GetWindowLong(c , GWL_STYLE);
	RECT r;
	COORD s={width,height};
	GetWindowRect(c, &r);
	MoveWindow(c, 1, 1, width, height, TRUE);
	style &= ~WS_MAXIMIZEBOX ;
	SetWindowLong(c , GWL_STYLE, style);
	SetWindowPos(c , NULL, 1, 1, width, height, SWP_NOSIZE|SWP_NOMOVE|SWP_FRAMECHANGED);
	

}
void remove_scrollbar()
{
	
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(handle, &info);
    COORD new_size = 
    {
        info.srWindow.Right - info.srWindow.Left +1,
        info.srWindow.Bottom - info.srWindow.Top + 1
    };
    SetConsoleScreenBufferSize(handle, new_size);
  	system("color F0");
	string title = ("     ");
	SetConsoleTitle(title.c_str());
}
void gotoxy(int x, int y)
{
  static HANDLE h = NULL;  
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };  
  SetConsoleCursorPosition(h,c);
}
void gotoXY(float x, float y)
{
  static HANDLE h = NULL;  
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };  
  SetConsoleCursorPosition(h,c);
}
int getX()//lay toa do x hien tai cua con tro console.
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.X;
	return -1;
}
int getY()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.Y;
	return -1;
}
void Nocursortype()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}
void Yescursortype()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = TRUE;Info.dwSize=20;
	SetConsoleCursorInfo (GetStdHandle (STD_OUTPUT_HANDLE), &Info);
}
HANDLE console()
{
	return GetStdHandle(STD_OUTPUT_HANDLE); 
} 
void Color(int num)
{
	SetConsoleTextAttribute(console(), num);
}
void TextColor (int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , color);
}
void SetColor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
void SetBGColor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	color <<= 4;
	wAttributes &= 0xff0f;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
void clrscr()
{
	CONSOLE_SCREEN_BUFFER_INFO	csbiInfo;                  
	HANDLE	hConsoleOut;
	COORD	Home = {0,0};
	DWORD	dummy;

	hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOut,&csbiInfo);

	FillConsoleOutputCharacter(hConsoleOut,' ',csbiInfo.dwSize.X * csbiInfo.dwSize.Y,Home,&dummy);
	csbiInfo.dwCursorPosition.X = 0;
	csbiInfo.dwCursorPosition.Y = 0;
	SetConsoleCursorPosition(hConsoleOut,csbiInfo.dwCursorPosition);
}
int GetKey()
{
	char key;
	key = _getch();
	if (key == -32 || key == 0)
		return -_getch();
	else return key;
}
void HienThiTrang(int trang, int tongtrang, int x, int y) {
	TextColor(164);	gotoxy(x, y); cout << " Trang:        ";
	gotoxy(x + 8, y); cout << trang << "/" << tongtrang;
	
}
void XoaMhlop(){
	for(int i=0;i<60;i++)
	{
		SetBGColor(231);
		gotoxy(0,i);
		cout << "                                                                                                                                                                                                                     ";
	}
}

void ChuChay(){
	char s[] = { "    CHUC NANG QUAN LY LOP HOC     " };
	int m = strlen(s) - 1;	
	while (!_kbhit()) {
		for (int i = m; i > 0; i--) {
			s[i] = s[i - 1];
			s[0] = s[m - 1];
		}
		gotoXY(3, 1);       cout << s;
		gotoXY(3, 1); cout << " ";	   Sleep(150);
	}
}
void ChuChayMenuMain(){
	char s[] = { " CHUONG TRINH QUAN LY KHOA HOC                                                                                                              " };
	int m = strlen(s) - 1;	
	while (!_kbhit()) {
		for (int i = m; i > 0; i--) {
			s[i] = s[i - 1];
			s[0] = s[m - 1];
		}
		TextColor(48);
		gotoXY(41, 2);       cout << s;
		gotoXY(41, 2); cout << " ";	   Sleep(150);
	}
}
char MENUMAIN[7][40] = {
	" 1.QUAN LY KHOA HOC           ",
	" 2.QUAN LY SINH VIEN          ",
	" 3.QUAN LY LOP HOC            ",
	" 4.QUAN LY TIEN DO            ",
	" 5.THONG KE KET QUA SINH VIEN ",
	" 6.LOGIN/LOGOUT               ",
	" 7.THOAT CHUONG TRINH         "};
void ToMauMenuMain(int color, int vitri)
{
	TextColor(color);
	gotoXY(6, 4 + vitri * 4); cout << "                              ";
	gotoXY(6, 5 + vitri * 4); cout << MENUMAIN[vitri];
	gotoXY(6, 6 + vitri * 4); cout << "                              ";
}
void Khung_MenuMain()
{
	for(int i=0;i<40;i++)
	{
		SetBGColor(222);
		gotoxy(41,3+i);
		cout << "                                                                                                                                            ";
	}
	for(int i=0;i<12;i++)
	{
		SetBGColor(222);
		gotoxy(2,31+i);
		cout << "                                      ";
	}
	for(int i=0;i<27;i++)
	{
		SetBGColor(222);
		gotoxy(2,4+i);
		cout << "    ";
		gotoxy(36,4+i);
		cout << "    ";
		
	}
	TextColor(48);
	gotoxy(2,2);
	cout << "              TRANG CHU               ";
	SetBGColor(110);
	gotoxy(2,3);
	cout << "                                      ";
	gotoxy(6,7);
	cout << "                              ";
	gotoxy(6,11);
	cout << "                              ";
	gotoxy(6,15);
	cout << "                              ";
	gotoxy(6,19);
	cout << "                              ";
	gotoxy(6,23);
	cout << "                              ";
	gotoxy(6,27);
	cout << "                              ";
	TextColor(225);
	gotoxy(1,1);
	cout << char(218) << setw(180) << setfill(char(196)) << char(191);
	for(int i = 2; i < 43; i++){
		gotoxy(1,i);
		cout << char(179);
		gotoxy(181,i);
		cout << char(179);
		gotoxy(40,i);
		cout << char(179);
		gotoxy(111,i+1);
		cout << char(179);
	}
	gotoxy(41,20);
	cout << setw(140) << setfill(char(196))<<char(196) ; 
	gotoxy(1,43);
	cout << char(192) << setw(180) << setfill(char(196)) << char(217);
	gotoxy(70,5);
	cout << "NHOM TRUONG";
	gotoxy(60,7);
	cout << "HO VA TEN: PHAN TRAN MINH NHAT";
	gotoxy(60,9);
	cout << "MSSV: N14DCCN242";
	gotoxy(60,11);
	cout << "LOP: D14CQCP01-N";
	gotoxy(60,13);
	cout << "CHUC NANG: QUAN LY KHOA HOC";
	gotoxy(70,23);
	cout << "THANH VIEN";
	gotoxy(60,25);
	cout << "HO VA TEN: NGUYEN ANH DUY";
	gotoxy(60,27);
	cout << "MSSV: N18DCCN029";
	gotoxy(60,29);
	cout << "LOP: D18CQCN02-N";
	gotoxy(60,31);
	cout << "CHUC NANG: QUAN LY SINH VIEN";
	gotoxy(141,5);
	cout << "THANH VIEN";
	gotoxy(131,7);
	cout << "HO VA TEN: NGUYEN MINH THUAN";
	gotoxy(131,9);
	cout << "MSSV: N18DCCN221";
	gotoxy(131,11);
	cout << "LOP: D18CQCN02-N";
	gotoxy(131,13);
	cout << "CHUC NANG: QUAN LY LOP HOC";
	gotoxy(141,23);
	cout << "THANH VIEN";
	gotoxy(131,25);
	cout << "HO VA TEN: DAO VAN CU";
	gotoxy(131,27);
	cout << "MSSV: N15DCDT015";
	gotoxy(131,29);
	cout << "LOP: D15CQDT01-N";
	gotoxy(131,31);
	cout << "CHUC NANG: QUAN LY TIEN DO";
}
int Menukey()
{
	
	int vitri = 0;
	while (1)
	{
		
		Khung_MenuMain();
		ChuChayMenuMain();
		char key = GetKey();
		if (key == ENTER )
		{
			return vitri+1;
		}
		switch (key)
		{
		case DOWN:
		{
			if (vitri == 6)
			{
				ToMauMenuMain(240, vitri);
				vitri = 0;
				ToMauMenuMain(52, vitri);
			}
			else
			{
				ToMauMenuMain(240, vitri);
				vitri++;
				ToMauMenuMain(52, vitri);
			}
		}break;
		case UP:
		{
			if (vitri == 0)
			{
				ToMauMenuMain(240, vitri);
				vitri = (6);
				ToMauMenuMain(52, vitri);
			}
			else
			{
				ToMauMenuMain(240, vitri);
				vitri--;
				ToMauMenuMain(52, vitri);
			}
		}break;
		}
	}
}
void Khung_Chucnang()
{
	
	for(int i=0;i<41;i++)
	{
		SetBGColor(110);
		gotoxy(41,2+i);
		cout << "                                                                                                                                            ";
		
	}
	for(int i=0;i<24;i++)
	{
		SetBGColor(110);
		gotoxy(2,19+i);
		cout << "                                      ";
	}
	for(int i=0;i<17;i++)
	{
		SetBGColor(110);
		gotoxy(2,4+i);
		cout << "   ";
		gotoxy(35,4+i);
		cout << "     ";
		
	}
	SetBGColor(110);
	gotoxy(2,2);
	cout << "                                      ";
	gotoxy(2,3);
	cout << "                                      ";
	gotoxy(5,7);
	cout << "                              ";
	gotoxy(5,11);
	cout << "                              ";
	gotoxy(5,15);
	cout << "                              ";
	TextColor(176);
	gotoxy(1,1);
	cout << char(218) << setw(180) << setfill(char(196)) << char(191);
	for(int i = 2; i < 43; i++){
		gotoxy(1,i);
		cout << char(179);
		gotoxy(181,i);
		cout << char(179);
		gotoxy(40,i);
		cout << char(179);
	}

	gotoxy(1,43);
	cout << char(192) << setw(180) << setfill(char(196)) << char(217);
	
}
void Khung_Cha()
{
	
	for(int i=0;i<40;i++)
	{
		SetBGColor(110);
		gotoxy(41,3+i);
		cout << "                                                                                                                                            ";
		
	}
	for(int i=0;i<24;i++)
	{
		SetBGColor(110);
		gotoxy(2,19+i);
		cout << "                                      ";
	}
	for(int i=0;i<17;i++)
	{
		SetBGColor(110);
		gotoxy(2,4+i);
		cout << "   ";
		gotoxy(35,4+i);
		cout << "     ";
		
	}
	SetBGColor(110);
	gotoxy(2,2);
	cout << "                                      ";
	gotoxy(2,3);
	cout << "                                      ";
	gotoxy(5,7);
	cout << "                              ";
	gotoxy(5,11);
	cout << "                              ";
	gotoxy(5,15);
	cout << "                              ";
	TextColor(176);
	gotoxy(1,1);
	cout << char(218) << setw(180) << setfill(char(196)) << char(191);
	for(int i = 2; i < 43; i++){
		gotoxy(1,i);
		cout << char(179);
		gotoxy(181,i);
		cout << char(179);
		gotoxy(40,i);
		cout << char(179);
	}

	gotoxy(1,43);
	cout << char(192) << setw(180) << setfill(char(196)) << char(217);
	
}
void Khung_Main()
{
	for(int i=0;i<41;i++)
	{
		SetBGColor(222);
		gotoxy(41,2+i);
		cout << "                                                                                                                                            ";
	}
	for(int i=0;i<12;i++)
	{
		SetBGColor(222);
		gotoxy(2,31+i);
		cout << "                                      ";
	}
	for(int i=0;i<27;i++)
	{
		SetBGColor(222);
		gotoxy(2,4+i);
		cout << "    ";
		gotoxy(36,4+i);
		cout << "    ";
		
	}
	TextColor(48);
	gotoxy(2,2);
	cout << "              TRANG CHU               ";
	SetBGColor(110);
	gotoxy(2,3);
	cout << "                                      ";
	gotoxy(6,7);
	cout << "                              ";
	gotoxy(6,11);
	cout << "                              ";
	gotoxy(6,15);
	cout << "                              ";
	gotoxy(6,19);
	cout << "                              ";
	gotoxy(6,23);
	cout << "                              ";
	gotoxy(6,27);
	cout << "                              ";
	TextColor(225);
	gotoxy(1,1);
	cout << char(218) << setw(180) << setfill(char(196)) << char(191);
	for(int i = 2; i < 43; i++){
		gotoxy(1,i);
		cout << char(179);
		gotoxy(181,i);
		cout << char(179);
		gotoxy(40,i);
		cout << char(179);
		
	}
	gotoxy(1,43);
	cout << char(192) << setw(180) << setfill(char(196)) << char(217);
	
}
void Khung_Login(){
	
	XoaMhlop();
	Khung_Main();
	for (int i = 0; i < 7 ; i++)
		{
			if (i == 5) { TextColor(52); }
			else { TextColor(240); }
			gotoXY(6, 4 + i * 4); cout << "                              ";
			gotoXY(6, 5 + i * 4); cout << MENUMAIN[i];
			gotoXY(6, 6 + i * 4); cout << "                              ";
		}
	for(int i=0;i<16;i++)
	{
		SetBGColor(179);
		gotoxy(86,10+i);
		cout << "                                                ";
	}
	gotoxy(86,10);
	cout << char(218) <<setw(46) << setfill(char(196))<<char(196) << char(191);
	gotoxy(86,12);
	cout << setw(47) << setfill(char(196))<<char(196) ;
	for(int i=0;i<15;i++)
	{
		gotoxy(86,11+i);
		cout << char(179);
		gotoxy(133,11+i);
		cout << char(179);
	}
	gotoxy(86,25);
	cout << char(192) << setw(47) << setfill(char(196)) << char(217);
	gotoxy(101,13);
	cout << char(218) <<setw(28) << setfill(char(196))<<char(196) << char(191);
	gotoxy(101,14);
	cout << char(179);
	gotoxy(130,14);
	cout << char(179);
	gotoxy(101,15);
	cout << char(192) << setw(29) << setfill(char(196)) << char(217);
	gotoxy(101,17);
	cout << char(218) <<setw(28) << setfill(char(196))<<char(196) << char(191);
	gotoxy(101,18);
	cout << char(179);
	gotoxy(130,18);
	cout << char(179);
	gotoxy(101,19);
	cout << char(192) << setw(29) << setfill(char(196)) << char(217);
	gotoxy(88,11);
	cout << "LOGIN";
	gotoxy(109,22);
	cout << "LOGIN";
	gotoxy(90,14);
	cout << "USERNAME:";
	//-------------------
	gotoxy(90,18);
	cout << "PASSWORD:";
	gotoxy(104,21);
	cout << char(218) <<setw(13) << setfill(char(196))<<char(196) << char(191);
	gotoxy(104,22);
	cout << char(179);
	gotoxy(118,22);
	cout << char(179);
	gotoxy(104,23);
	cout << char(192) << setw(14) << setfill(char(196)) << char(217);
}

char MENULOP[4][40] = {
	"  1.XEM DANH SACH KHOA        ",
	"  2.XEM DANH SACH LOP         ",
	"  3.DANG KY KHOA HOC CHO LOP  ",
	"  4.QUAY LAI TRANG CHU        "};
void ToMauMenuLop(int color, int vitri)
{
	TextColor(color);
	gotoxy(5, 4 + vitri * 4); cout << "                              ";
	gotoxy(5, 5 + vitri * 4); cout << MENULOP[vitri];
	gotoxy(5, 6 + vitri * 4); cout << "                              ";
}

int MenuChaLop(bool phanquyen)
{
	
	int vitri = 0;
	while (1)
	{
		if(phanquyen == true){
			TextColor(48);
			gotoxy(41,2);
			cout << "                                                       DANG XEM VOI TU CACH QUAN TRI VIEN                                                   ";
		}
		else{
			TextColor(48);
			gotoxy(41,2);
			cout << "                                                         DANG XEM VOI TU CACH SINH VIEN                                                     ";
		}
		Khung_Cha();
		ChuChay();
		char key = GetKey();
		if (key == ENTER )
		{
			return vitri+1;
		}
		switch (key)
		{
		case DOWN:
		{
			if (vitri == 3)
			{
				ToMauMenuLop(240, vitri);
				vitri = 0;
				ToMauMenuLop(180, vitri);
			}
			else
			{
				ToMauMenuLop(240, vitri);
				vitri++;
				ToMauMenuLop(180, vitri);
			}
		}break;
		case UP:
		{
			if (vitri == 0)
			{
				ToMauMenuLop(240, vitri);
				vitri = (3);
				ToMauMenuLop(180, vitri);
			}
			else
			{
				ToMauMenuLop(240, vitri);
				vitri--;
				ToMauMenuLop(180, vitri);
			}
		}break;
		}
	}
}


void Khung_XemLop()
{
	XoaMhlop();
	Khung_Chucnang();
	for (int i = 0; i < 4 ; i++)
		{
			if (i == 1) { TextColor(180); }
			else { TextColor(240); }
			gotoxy(5, 4 + i * 4); cout << "                              ";
			gotoxy(5, 5 + i * 4); cout << MENULOP[i];
			gotoxy(5, 6 + i * 4); cout << "                              ";
		}
	for(int i=0;i<25;i++)
	{
		SetBGColor(179);
		gotoxy(46,4+i);
		cout << "                                                                                                               ";
		
	}
	gotoxy(46,7);
	cout << char(218) << setw(110) << setfill(char(196)) << char(191);
	gotoxy(46,9);
	cout << char(218) << setw(110) << setfill(char(196)) << char(191);
	for(int i = 0; i < 20; i++){
		
		gotoxy(46,8+i);
		cout << char(179);
		gotoxy(156,8+i);
		cout << char(179);
	}
		
	for(int i = 0; i < 19; i++){
		
		gotoxy(52,8+i);
		cout << char(179);
		gotoxy(72,8+i);
		cout << char(179);
		gotoxy(113,8+i);
		cout << char(179);
		gotoxy(132,8+i);
		cout << char(179);
	}
	gotoxy(47,26);
	cout << setw(109) << setfill(char(196))<<char(196) ;
	gotoxy(46,28);
	cout << char(192) << setw(110) << setfill(char(196)) << char(217);
	gotoxy(48,8);
	cout << "STT";
	gotoxy(58,8);
	cout << "MA LOP HOC";
	gotoxy(88,8);
	cout << "TEN LOP HOC";
	gotoxy(120,8);
	cout << "MA KHOA";
	gotoxy(139,8);
	cout << "MA KHOA HOC";
	gotoxy(50,27);
	cout <<        "ESC: EXIT || F1: INSERT || F2: EDIT || F3: DELETE || UP-DOWN-LEFT-RIGHT: NEXT PAGE";
	gotoxy(46,4);
	cout << char(218) <<setw(109) << setfill(char(196))<<char(196) << char(191);
	gotoxy(46,5);
	cout << char(179);
	gotoxy(156,5);
	cout << char(179);
	gotoxy(46,6);
	cout << char(192) << setw(110) << setfill(char(196)) << char(217);

}
void Khung_XemLopDK()
{
	XoaMhlop();
	Khung_Chucnang();
	for (int i = 0; i < 4 ; i++)
		{
			if (i == 1) { TextColor(180); }
			else { TextColor(240); }
			gotoxy(5, 4 + i * 4); cout << "                              ";
			gotoxy(5, 5 + i * 4); cout << MENULOP[i];
			gotoxy(5, 6 + i * 4); cout << "                              ";
		}
	for(int i=0;i<25;i++)
	{
		SetBGColor(179);
		gotoxy(46,4+i);
		cout << "                                                                                                               ";
		
	}
	gotoxy(46,7);
	cout << char(218) << setw(110) << setfill(char(196)) << char(191);
	gotoxy(46,9);
	cout << char(218) << setw(110) << setfill(char(196)) << char(191);
	for(int i = 0; i < 20; i++){
		
		gotoxy(46,8+i);
		cout << char(179);
		gotoxy(156,8+i);
		cout << char(179);
	}
		
	for(int i = 0; i < 19; i++){
		
		gotoxy(52,8+i);
		cout << char(179);
		gotoxy(72,8+i);
		cout << char(179);
		gotoxy(113,8+i);
		cout << char(179);
		gotoxy(132,8+i);
		cout << char(179);
	}
	gotoxy(47,26);
	cout << setw(109) << setfill(char(196))<<char(196) ;
	gotoxy(46,28);
	cout << char(192) << setw(110) << setfill(char(196)) << char(217);
	gotoxy(48,8);
	cout << "STT";
	gotoxy(58,8);
	cout << "MA LOP HOC";
	gotoxy(88,8);
	cout << "TEN LOP HOC";
	gotoxy(120,8);
	cout << "MA KHOA";
	gotoxy(139,8);
	cout << "MA KHOA HOC";
	gotoxy(50,27);
	cout <<        "ESC: BACK || UP-DOWN-LEFT-RIGHT: NEXT PAGE";
	gotoxy(46,4);
	cout << char(218) <<setw(109) << setfill(char(196))<<char(196) << char(191);
	gotoxy(46,5);
	cout << char(179);
	gotoxy(156,5);
	cout << char(179);
	gotoxy(46,6);
	cout << char(192) << setw(110) << setfill(char(196)) << char(217);

}
void Khung_XemKhoa()
{
	Khung_Chucnang();
	for (int i = 0; i < 4 ; i++)
		{
			if (i == 0) { TextColor(180); }
			else { TextColor(240); }
			gotoxy(5, 4 + i * 4); cout << "                              ";
			gotoxy(5, 5 + i * 4); cout << MENULOP[i];
			gotoxy(5, 6 + i * 4); cout << "                              ";
		}
	for(int i=0;i<25;i++)
	{
		SetBGColor(179);
		gotoxy(76,4+i);
		cout << "                                                                      ";
		
	}
	gotoxy(76,7);
	cout << char(218) << setw(70) << setfill(char(196)) << char(191);
	gotoxy(76,9);
	cout << char(218) << setw(70) << setfill(char(196)) << char(191);
	for(int i = 0; i < 20; i++){
		
		gotoxy(76,8+i);
		cout << char(179);
		gotoxy(146,8+i);
		cout << char(179);
	}
		
	for(int i = 0; i < 19; i++){
		
		gotoxy(82,8+i);
		cout << char(179);
		gotoxy(102,8+i);
		cout << char(179);
		
	}
	gotoxy(77,26);
	cout << setw(69) << setfill(char(196))<<char(196) ;
	gotoxy(76,28);
	cout << char(192) << setw(70) << setfill(char(196)) << char(217);
	gotoxy(78,8);
	cout << "STT";
	gotoxy(88,8);
	cout << "MA KHOA";
	gotoxy(118,8);
	cout << "TEN KHOA";
	gotoxy(80,27);
	cout <<        "ESC: EXIT || F1: XEM LOP THEO KHOA";
	gotoxy(76,4);
	cout << char(218) <<setw(69) << setfill(char(196))<<char(196) << char(191);
	gotoxy(76,5);
	cout << char(179);
	gotoxy(146,5);
	cout << char(179);
	gotoxy(76,6);
	cout << char(192) << setw(70) << setfill(char(196)) << char(217);

}
void Khung_XemLopTheoKhoa()
{
	Khung_Chucnang();
	for (int i = 0; i < 4 ; i++)
		{
			if (i == 0) { TextColor(180); }
			else { TextColor(240); }
			gotoxy(5, 4 + i * 4); cout << "                              ";
			gotoxy(5, 5 + i * 4); cout << MENULOP[i];
			gotoxy(5, 6 + i * 4); cout << "                              ";
		}
	for(int i=0;i<37;i++)
	{
		SetBGColor(179);
		gotoxy(46,4+i);
		cout << "                                                                                                               ";
	}
	gotoxy(46,7);
	cout << char(218) << setw(110) << setfill(char(196)) << char(191);
	gotoxy(46,9);
	cout << char(218) << setw(110) << setfill(char(196)) << char(191);
	for(int i = 0; i < 32; i++){
		
		gotoxy(46,8+i);
		cout << char(179);
		gotoxy(156,8+i);
		cout << char(179);
	}
		
	for(int i = 0; i < 31; i++){
		
		gotoxy(72,8+i);
		cout << char(179);
		gotoxy(113,8+i);
		cout << char(179);
		gotoxy(132,8+i);
		cout << char(179);
	}
	gotoxy(47,38);
	cout << setw(109) << setfill(char(196))<<char(196) ;
	gotoxy(46,40);
	cout << char(192) << setw(110) << setfill(char(196)) << char(217);
	gotoxy(54,8);
	cout << "MA LOP HOC";
	gotoxy(88,8);
	cout << "TEN LOP HOC";
	gotoxy(120,8);
	cout << "MA KHOA";
	gotoxy(139,8);
	cout << "MA KHOA HOC";
	gotoxy(50,39);
	cout <<        "ESC: BACK || UP - DOWN - LEFT - RIGHT : NEXT PAGE";
	gotoxy(46,4);
	cout << char(218) <<setw(109) << setfill(char(196))<<char(196) << char(191);
	gotoxy(46,5);
	cout << char(179);
	gotoxy(156,5);
	cout << char(179);
	gotoxy(46,6);
	cout << char(192) << setw(110) << setfill(char(196)) << char(217);
	
}
void Khung_ThemLop()
{
	Khung_Chucnang();
	for (int i = 0; i < 4 ; i++)
		{
			if (i == 1) { TextColor(180); }
			else { TextColor(240); }
			gotoxy(5, 4 + i * 4); cout << "                              ";
			gotoxy(5, 5 + i * 4); cout << MENULOP[i];
			gotoxy(5, 6 + i * 4); cout << "                              ";
		}
	for(int i=0;i<26;i++)
	{
		SetBGColor(179);
		gotoxy(65,8+i);
		cout << "                                                                       ";
	}
	gotoxy(65,8);
	cout << char(218) << setw(70) << setfill(char(196)) << char(191);
	gotoxy(65,10);
	cout << char(218) << setw(70) << setfill(char(196)) << char(191);
	for(int i = 0; i < 25; i++){
		
		gotoxy(65,9+i);
		cout << char(179);
		gotoxy(135,9+i);
		cout << char(179);
	}
		
	gotoxy(66,31);
	cout << setw(69) << setfill(char(196))<<char(196) ;
	gotoxy(65,33);
	cout << char(192) << setw(70) << setfill(char(196)) << char(217);
	
	for(int i=0; i<3; i++)
	{
		gotoxy(86,12+3*i);
		cout << char(218) <<setw(31) << setfill(char(196))<<char(196) << char(191);
		gotoxy(86,13+3*i);
		cout << char(179);
		gotoxy(118,13+3*i);
		cout << char(179);
		gotoxy(86,14+3*i);
		cout << char(192) << setw(32) << setfill(char(196)) << char(217);
	}
	gotoxy(73,13);
	cout << "MA LOP HOC:";
	gotoxy(73,16);
	cout << "TEN LOP HOC:";
	gotoxy(73,19);
	cout << "MA KHOA:";
	gotoxy(85,28);
	cout << "HUY";
	gotoxy(111,28);
	cout << "THEM LOP";
	gotoxy(79,27);
	cout << char(218) <<setw(13) << setfill(char(196))<<char(196) << char(191);
	gotoxy(79,28);
	cout << char(179);
	gotoxy(93,28);
	cout << char(179);
	gotoxy(79,29);
	cout << char(192) << setw(14) << setfill(char(196)) << char(217);
	gotoxy(107,27);
	cout << char(218) <<setw(13) << setfill(char(196))<<char(196) << char(191);
	gotoxy(107,28);
	cout << char(179);
	gotoxy(121,28);
	cout << char(179);
	gotoxy(107,29);
	cout << char(192) << setw(14) << setfill(char(196)) << char(217);
	
	
}
void Khung_Sua()
{
	XoaMhlop();
	Khung_Chucnang();
	for (int i = 0; i < 4 ; i++)
		{
			if (i == 1) { TextColor(180); }
			else { TextColor(240); }
			gotoxy(5, 4 + i * 4); cout << "                              ";
			gotoxy(5, 5 + i * 4); cout << MENULOP[i];
			gotoxy(5, 6 + i * 4); cout << "                              ";
		}
	for(int i=0;i<26;i++)
	{
		SetBGColor(179);
		gotoxy(65,8+i);
		cout << "                                                                       ";
	}
	gotoxy(65,8);
	cout << char(218) << setw(70) << setfill(char(196)) << char(191);
	gotoxy(65,10);
	cout << char(218) << setw(70) << setfill(char(196)) << char(191);
	for(int i = 0; i < 25; i++){
		
		gotoxy(65,9+i);
		cout << char(179);
		gotoxy(135,9+i);
		cout << char(179);
	}
		
	gotoxy(66,31);
	cout << setw(69) << setfill(char(196))<<char(196) ;
	gotoxy(65,33);
	cout << char(192) << setw(70) << setfill(char(196)) << char(217);
	
	for(int i=0; i<3; i++)
	{
		gotoxy(86,12+3*i);
		cout << char(218) <<setw(31) << setfill(char(196))<<char(196) << char(191);
		gotoxy(86,13+3*i);
		cout << char(179);
		gotoxy(118,13+3*i);
		cout << char(179);
		gotoxy(86,14+3*i);
		cout << char(192) << setw(32) << setfill(char(196)) << char(217);
	}
	gotoxy(73,13);
	cout << "MA LOP HOC:";
	gotoxy(73,16);
	cout << "TEN LOP HOC:";
	gotoxy(73,19);
	cout << "MA KHOA:";
	gotoxy(85,28);
	cout << "HUY";
	gotoxy(111,28);
	cout << "SUA LOP";
	gotoxy(79,27);
	cout << char(218) <<setw(13) << setfill(char(196))<<char(196) << char(191);
	gotoxy(79,28);
	cout << char(179);
	gotoxy(93,28);
	cout << char(179);
	gotoxy(79,29);
	cout << char(192) << setw(14) << setfill(char(196)) << char(217);
	gotoxy(107,27);
	cout << char(218) <<setw(13) << setfill(char(196))<<char(196) << char(191);
	gotoxy(107,28);
	cout << char(179);
	gotoxy(121,28);
	cout << char(179);
	gotoxy(107,29);
	cout << char(192) << setw(14) << setfill(char(196)) << char(217);
	
	
}
void Khung_Xoa()
{
	XoaMhlop();
	Khung_Chucnang();
	for (int i = 0; i < 4 ; i++)
		{
			if (i == 1) { TextColor(180); }
			else { TextColor(240); }
			gotoxy(5, 4 + i * 4); cout << "                              ";
			gotoxy(5, 5 + i * 4); cout << MENULOP[i];
			gotoxy(5, 6 + i * 4); cout << "                              ";
		}
	for(int i=0;i<26;i++)
	{
		SetBGColor(179);
		gotoxy(65,8+i);
		cout << "                                                                       ";
	}
	gotoxy(65,8);
	cout << char(218) << setw(70) << setfill(char(196)) << char(191);
	gotoxy(65,10);
	cout << char(218) << setw(70) << setfill(char(196)) << char(191);
	for(int i = 0; i < 25; i++){
		
		gotoxy(65,9+i);
		cout << char(179);
		gotoxy(135,9+i);
		cout << char(179);
	}
		
	gotoxy(66,31);
	cout << setw(69) << setfill(char(196))<<char(196) ;
	gotoxy(65,33);
	cout << char(192) << setw(70) << setfill(char(196)) << char(217);
	
	for(int i=0; i<3; i++)
	{
		gotoxy(86,12+3*i);
		cout << char(218) <<setw(31) << setfill(char(196))<<char(196) << char(191);
		gotoxy(86,13+3*i);
		cout << char(179);
		gotoxy(118,13+3*i);
		cout << char(179);
		gotoxy(86,14+3*i);
		cout << char(192) << setw(32) << setfill(char(196)) << char(217);
	}
	gotoxy(73,13);
	cout << "MA LOP HOC:";
	gotoxy(73,16);
	cout << "TEN LOP HOC:";
	gotoxy(73,19);
	cout << "MA KHOA:";
	gotoxy(85,28);
	cout << "HUY";
	gotoxy(111,28);
	cout << "XOA LOP";
	gotoxy(79,27);
	cout << char(218) <<setw(13) << setfill(char(196))<<char(196) << char(191);
	gotoxy(79,28);
	cout << char(179);
	gotoxy(93,28);
	cout << char(179);
	gotoxy(79,29);
	cout << char(192) << setw(14) << setfill(char(196)) << char(217);
	gotoxy(107,27);
	cout << char(218) <<setw(13) << setfill(char(196))<<char(196) << char(191);
	gotoxy(107,28);
	cout << char(179);
	gotoxy(121,28);
	cout << char(179);
	gotoxy(107,29);
	cout << char(192) << setw(14) << setfill(char(196)) << char(217);
	
	
}
void Khung_SuaLop()
{
	
	Khung_Chucnang();
	for (int i = 0; i < 4 ; i++)
		{
			if (i == 1) { TextColor(180); }
			else { TextColor(240); }
			gotoxy(5, 4 + i * 4); cout << "                              ";
			gotoxy(5, 5 + i * 4); cout << MENULOP[i];
			gotoxy(5, 6 + i * 4); cout << "                              ";
		}
	for(int i=0;i<11;i++)
	{
		SetBGColor(179);
		gotoxy(75,10+i);
		cout << "                                                             ";
	}
	gotoxy(75,10);
	cout << char(218) << setw(60) << setfill(char(196)) << char(191);
	gotoxy(75,12);
	cout << char(218) << setw(60) << setfill(char(196)) << char(191);
	for(int i = 0; i < 9; i++){
		
		gotoxy(75,11+i);
		cout << char(179);
		gotoxy(135,11+i);
		cout << char(179);
	}
	
	gotoxy(76,18);
	cout << setw(59) << setfill(char(196))<<char(196) ;
	gotoxy(75,20);
	cout << char(192) << setw(60) << setfill(char(196)) << char(217);
	gotoxy(108,14);
	cout << char(218) <<setw(13) << setfill(char(196))<<char(196) << char(191);
	gotoxy(108,15);
	cout << char(179);
	gotoxy(122,15);
	cout << char(179);
	gotoxy(108,16);
	cout << char(192) << setw(14) << setfill(char(196)) << char(217);
	gotoxy(83,15);
	cout << "Nhap Ma Lop Hoc Can Sua:";
	gotoxy(112,19);
	cout << "|| ECS:";
	gotoxy(124,19);
	cout << "|| ENTER:";
	gotoxy(96,11);
	cout << "SUA THONG TIN LOP HOC";
	gotoxy(119,19);
	cout << "BACK";
	gotoxy(133,19);
	cout << "OK";
	
	
}
void Khung_HuongDan()
{
	gotoxy(86,27);
	cout << "                    HUONG DAN                   ";
	gotoxy(86,29);
	cout << "      DANG NHAP DE CAP QUYEN QUAN TRI VIEN      ";
	gotoxy(86,31);
	cout << "      ECS: XEM VOI TU CACH SINH VIEN            ";
}
void Khung_XoaLop()
{
	Khung_Chucnang();
	for (int i = 0; i < 4 ; i++)
		{
			if (i == 1) { TextColor(180); }
			else { TextColor(240); }
			gotoxy(5, 4 + i * 4); cout << "                              ";
			gotoxy(5, 5 + i * 4); cout << MENULOP[i];
			gotoxy(5, 6 + i * 4); cout << "                              ";
		}
	for(int i=0;i<11;i++)
	{
		SetBGColor(179);
		gotoxy(75,10+i);
		cout << "                                                             ";
	}
	gotoxy(75,10);
	cout << char(218) << setw(60) << setfill(char(196)) << char(191);
	gotoxy(75,12);
	cout << char(218) << setw(60) << setfill(char(196)) << char(191);
	for(int i = 0; i < 9; i++){
		
		gotoxy(75,11+i);
		cout << char(179);
		gotoxy(135,11+i);
		cout << char(179);
	}
	
	gotoxy(76,18);
	cout << setw(59) << setfill(char(196))<<char(196) ;
	gotoxy(75,20);
	cout << char(192) << setw(60) << setfill(char(196)) << char(217);
	gotoxy(108,14);
	cout << char(218) <<setw(13) << setfill(char(196))<<char(196) << char(191);
	gotoxy(108,15);
	cout << char(179);
	gotoxy(122,15);
	cout << char(179);
	gotoxy(108,16);
	cout << char(192) << setw(14) << setfill(char(196)) << char(217);
	gotoxy(83,15);
	cout << "Nhap Ma Lop Hoc Can Xoa:";
	gotoxy(112,19);
	cout << "|| ECS:";
	gotoxy(124,19);
	cout << "|| ENTER:";
	gotoxy(96,11);
	cout << "XOA THONG TIN LOP HOC";
	gotoxy(119,19);
	cout << "BACK";
	gotoxy(133,19);
	cout << "OK";
		
}
void Khung_DK()
{
	XoaMhlop();
	Khung_Chucnang();
	for (int i = 0; i < 4 ; i++)
		{
			if (i == 2) { TextColor(180); }
			else { TextColor(240); }
			gotoxy(5, 4 + i * 4); cout << "                              ";
			gotoxy(5, 5 + i * 4); cout << MENULOP[i];
			gotoxy(5, 6 + i * 4); cout << "                              ";
		}
	for(int i=0;i<11;i++)
	{
		SetBGColor(179);
		gotoxy(80,10+i);
		cout << "                                                  ";
	}
	gotoxy(80,10);
	cout << char(218) << setw(50) << setfill(char(196)) << char(191);
	gotoxy(80,12);
	cout << char(218) << setw(50) << setfill(char(196)) << char(191);
	for(int i = 0; i < 9; i++){
		
		gotoxy(80,11+i);
		cout << char(179);
		gotoxy(130,11+i);
		cout << char(179);
	}
	
	gotoxy(81,18);
	cout << setw(49) << setfill(char(196))<<char(196) ;
	gotoxy(80,20);
	cout << char(192) << setw(50) << setfill(char(196)) << char(217);
	gotoxy(112,14);
	cout << char(218) <<setw(13) << setfill(char(196))<<char(196) << char(191);
	gotoxy(112,15);
	cout << char(179);
	gotoxy(126,15);
	cout << char(179);
	gotoxy(112,16);
	cout << char(192) << setw(14) << setfill(char(196)) << char(217);
	gotoxy(83,15);
	cout << "Nhap Ma Lop Hoc Can Dang Ky";
	gotoxy(81,19);
	cout << "F1: XEM DANH SACH LOP";
	gotoxy(103,19);
	cout << "|| ECS:";
	gotoxy(116,19);
	cout << "|| ENTER:";
	gotoxy(93,11);
	cout << "DANG KY KHOA HOC LOP HOC";
	gotoxy(111,19);
	cout << "BACK";
	gotoxy(125,19);
	cout << "OK";
	
	
}
void Khung_DKKHOAHOC()
{
	XoaMhlop();
	Khung_Chucnang();
	for (int i = 0; i < 4 ; i++)
		{
			if (i == 2) { TextColor(180); }
			else { TextColor(240); }
			gotoxy(5, 4 + i * 4); cout << "                              ";
			gotoxy(5, 5 + i * 4); cout << MENULOP[i];
			gotoxy(5, 6 + i * 4); cout << "                              ";
		}
	for(int i=0;i<26;i++)
	{
		SetBGColor(179);
		gotoxy(65,8+i);
		cout << "                                                                       ";
	}
	gotoxy(65,8);
	cout << char(218) << setw(70) << setfill(char(196)) << char(191);
	gotoxy(65,10);
	cout << char(218) << setw(70) << setfill(char(196)) << char(191);
	for(int i = 0; i < 25; i++){
		
		gotoxy(65,9+i);
		cout << char(179);
		gotoxy(135,9+i);
		cout << char(179);
	}
		
	gotoxy(66,31);
	cout << setw(69) << setfill(char(196))<<char(196) ;
	gotoxy(65,33);
	cout << char(192) << setw(70) << setfill(char(196)) << char(217);
	
	for(int i=0; i<4; i++)
	{
		gotoxy(86,12+3*i);
		cout << char(218) <<setw(31) << setfill(char(196))<<char(196) << char(191);
		gotoxy(86,13+3*i);
		cout << char(179);
		gotoxy(118,13+3*i);
		cout << char(179);
		gotoxy(86,14+3*i);
		cout << char(192) << setw(32) << setfill(char(196)) << char(217);
	}
	gotoxy(73,13);
	cout << "Ma Lop Hoc:";
	gotoxy(73,16);
	cout << "Ten Lop Hoc:";
	gotoxy(73,19);
	cout << "Ma Khoa:";
	gotoxy(73,22);
	cout << "Ma Khoa Hoc:";
	gotoxy(85,28);
	cout << "Huy";
	gotoxy(111,28);
	cout << "DANG KY";
	gotoxy(66,32);
	cout << "F1: DANH SACH KHOA HOC";
	gotoxy(79,27);
	cout << char(218) <<setw(13) << setfill(char(196))<<char(196) << char(191);
	gotoxy(79,28);
	cout << char(179);
	gotoxy(93,28);
	cout << char(179);
	gotoxy(79,29);
	cout << char(192) << setw(14) << setfill(char(196)) << char(217);
	gotoxy(107,27);
	cout << char(218) <<setw(13) << setfill(char(196))<<char(196) << char(191);
	gotoxy(107,28);
	cout << char(179);
	gotoxy(121,28);
	cout << char(179);
	gotoxy(107,29);
	cout << char(192) << setw(14) << setfill(char(196)) << char(217);
	
}
void Khung_XLTK()
{
	
	Khung_Chucnang();
	for (int i = 0; i < 4 ; i++)
		{
			if (i == 0) { TextColor(180); }
			else { TextColor(240); }
			gotoxy(5, 4 + i * 4); cout << "                              ";
			gotoxy(5, 5 + i * 4); cout << MENULOP[i];
			gotoxy(5, 6 + i * 4); cout << "                              ";
		}
	for(int i=0;i<11;i++)
	{
		SetBGColor(179);
		gotoxy(80,10+i);
		cout << "                                                  ";
	}
	gotoxy(80,10);
	cout << char(218) << setw(50) << setfill(char(196)) << char(191);
	gotoxy(80,12);
	cout << char(218) << setw(50) << setfill(char(196)) << char(191);
	for(int i = 0; i < 9; i++){
		
		gotoxy(80,11+i);
		cout << char(179);
		gotoxy(130,11+i);
		cout << char(179);
	}
	
	gotoxy(81,18);
	cout << setw(49) << setfill(char(196))<<char(196) ;
	gotoxy(80,20);
	cout << char(192) << setw(50) << setfill(char(196)) << char(217);
	gotoxy(108,14);
	cout << char(218) <<setw(13) << setfill(char(196))<<char(196) << char(191);
	gotoxy(108,15);
	cout << char(179);
	gotoxy(122,15);
	cout << char(179);
	gotoxy(108,16);
	cout << char(192) << setw(14) << setfill(char(196)) << char(217);
	gotoxy(83,15);
	cout << "Nhap Ma Khoa Can Xem";
	gotoxy(111,19);
	cout << "ECS:";
	gotoxy(121,19);
	cout << "ENTER:";
	gotoxy(92,11);
	cout << "XEM DANH SACH LOP THEO KHOA";
	gotoxy(116,19);
	cout << "Exit";
	gotoxy(128,19);
	cout << "OK";
	
}
void Khung_Loading(){
	system("color 71");
	Nocursortype();
	gotoxy(51,12);
	cout << "CHUONG TRINH DANG KHOI DONG";
	gotoxy(50,14);
	cout << char(218) <<setw(101) << setfill(char(196))<<char(196) << char(191);
	gotoxy(50,15);
	cout << char(179);
	gotoxy(152,15);
	cout << char(179);
	gotoxy(50,16);
	cout << char(192) << setw(102) << setfill(char(196)) << char(217);
	for(int i=1;i<101;i++)
	{
		gotoxy(37,15);
		cout << "LOADING   ";
		Sleep(10);
		gotoxy(37,15);
		cout << "LOADING.  ";
		Sleep(10);
		gotoxy(37,15);
		cout << "LOADING.. ";
		Sleep(10);
		gotoxy(37,15);
		cout << "LOADING...";
		SetBGColor(225);
		gotoxy(51+i, 15);
		cout << " ";
		TextColor(113);
		gotoxy(154, 15);
		cout << i << "%";
		Sleep(10);
	}
	Sleep(1000);
	cout << "\a \a \a \a";
	system("cls");
}
void Khung_Thoat(){
	system("color 71");
	Nocursortype();
	gotoxy(51,12);
	cout << "DANG THOAT CHUONG TRINH";
	gotoxy(50,14);
	cout << char(218) <<setw(101) << setfill(char(196))<<char(196) << char(191);
	gotoxy(50,15);
	cout << char(179);
	gotoxy(152,15);
	cout << char(179);
	gotoxy(50,16);
	cout << char(192) << setw(102) << setfill(char(196)) << char(217);
	for(int i=1;i<101;i++)
	{
		gotoxy(37,15);
		cout << "LOADING   ";
		Sleep(10);
		gotoxy(37,15);
		cout << "LOADING.  ";
		Sleep(10);
		gotoxy(37,15);
		cout << "LOADING.. ";
		Sleep(10);
		gotoxy(37,15);
		cout << "LOADING...";
		SetBGColor(225);
		gotoxy(51+i, 15);
		cout << " ";
		TextColor(113);
		gotoxy(154, 15);
		cout << i << "%";
		Sleep(10);
	}
	Sleep(1000);
	system("cls");
}
void Khung_ThemKhoaHoc()
{
	system("color 71");
	for(int i=0;i<13;i++)
	{
		SetBGColor(110);
		gotoxy(65,8+i);
		cout << "                                                                                 ";
	}
	gotoxy(70,13);
	cout << char(218) <<setw(13) << setfill(char(196))<<char(196) << char(191);
	gotoxy(70,14);
	cout << char(179);
	gotoxy(84,14);
	cout << char(179);
	gotoxy(70,15);
	cout << char(192) << setw(14) << setfill(char(196)) << char(217);
	gotoxy(88,13);
	cout << char(218) <<setw(32) << setfill(char(196))<<char(196) << char(191);
	gotoxy(88,14);
	cout << char(179);
	gotoxy(121,14);
	cout << char(179);
	gotoxy(88,15);
	cout << char(192) << setw(33) << setfill(char(196)) << char(217);
	gotoxy(125,13);
	cout << char(218) <<setw(4) << setfill(char(196))<<char(196) << char(191);
	gotoxy(125,14);
	cout << char(179);
	gotoxy(130,14);
	cout << char(179);
	gotoxy(125,15);
	cout << char(192) << setw(5) << setfill(char(196)) << char(217);
	gotoxy(72,12);
	cout << "MA KHOA HOC";
	gotoxy(99,12);
	cout << "TEN KHOA HOC";
	gotoxy(124,12);
	cout << "THOI HAN";
	
	gotoxy(65,8);
	cout << char(218) << setw(80) << setfill(char(196)) << char(191);
	gotoxy(65,10);
	cout << char(218) << setw(80) << setfill(char(196)) << char(191);
	for(int i = 0; i < 12; i++){
		
		gotoxy(65,9+i);
		cout << char(179);
		gotoxy(145,9+i);
		cout << char(179);
	}
		
	gotoxy(66,18);
	cout << setw(79) << setfill(char(196))<<char(196) ;
	gotoxy(65,20);
	cout << char(192) << setw(80) << setfill(char(196)) << char(217);
	gotoxy(126,19);
	cout << "ECS:";
	gotoxy(136,19);
	cout << "ENTER:";
	gotoxy(131,19);
	cout << "BACK";
	gotoxy(143,19);
	cout << "OK";
	
}
void Khung_SuaKhoaHoc()
{
	
	system("color 71");
	for(int i=0;i<11;i++)
	{
		SetBGColor(110);
		gotoxy(80,10+i);
		cout << "                                                  ";
	}
	gotoxy(80,10);
	cout << char(218) << setw(50) << setfill(char(196)) << char(191);
	gotoxy(80,12);
	cout << char(218) << setw(50) << setfill(char(196)) << char(191);
	for(int i = 0; i < 9; i++){
		
		gotoxy(80,11+i);
		cout << char(179);
		gotoxy(130,11+i);
		cout << char(179);
	}
	
	gotoxy(81,18);
	cout << setw(49) << setfill(char(196))<<char(196) ;
	gotoxy(80,20);
	cout << char(192) << setw(50) << setfill(char(196)) << char(217);
	gotoxy(108,14);
	cout << char(218) <<setw(13) << setfill(char(196))<<char(196) << char(191);
	gotoxy(108,15);
	cout << char(179);
	gotoxy(122,15);
	cout << char(179);
	gotoxy(108,16);
	cout << char(192) << setw(14) << setfill(char(196)) << char(217);
	gotoxy(83,15);
	cout << "Nhap Ma Khoa Hoc Can Sua";
	gotoxy(110,19);
	cout << "ECS:";
	gotoxy(121,19);
	cout << "ENTER:";
	gotoxy(96,11);
	cout << "SUA THONG TIN KHOA HOC";
	gotoxy(115,19);
	cout << "BACK";
	gotoxy(128,19);
	cout << "OK";
	
	
}
void Khung_XoaKhoaHoc()
{
	system("color 71");
	for(int i=0;i<11;i++)
	{
		SetBGColor(110);
		gotoxy(80,10+i);
		cout << "                                                  ";
	}
	gotoxy(80,10);
	cout << char(218) << setw(50) << setfill(char(196)) << char(191);
	gotoxy(80,12);
	cout << char(218) << setw(50) << setfill(char(196)) << char(191);
	for(int i = 0; i < 9; i++){
		
		gotoxy(80,11+i);
		cout << char(179);
		gotoxy(130,11+i);
		cout << char(179);
	}
	
	gotoxy(81,18);
	cout << setw(49) << setfill(char(196))<<char(196) ;
	gotoxy(80,20);
	cout << char(192) << setw(50) << setfill(char(196)) << char(217);
	gotoxy(108,14);
	cout << char(218) <<setw(13) << setfill(char(196))<<char(196) << char(191);
	gotoxy(108,15);
	cout << char(179);
	gotoxy(122,15);
	cout << char(179);
	gotoxy(108,16);
	cout << char(192) << setw(14) << setfill(char(196)) << char(217);
	gotoxy(83,15);
	cout << "Nhap Ma Khoa Hoc Can Xoa";
	gotoxy(110,19);
	cout << "ECS:";
	gotoxy(121,19);
	cout << "ENTER:";
	gotoxy(96,11);
	cout << "XOA THONG TIN KHOA HOC";
	gotoxy(115,19);
	cout << "BACK";
	gotoxy(128,19);
	cout << "OK";
	
	
}
void Khung_XemKhoaHoc()
{
	system("color 71");
	for(int i=0;i<25;i++)
	{
		SetBGColor(110);
		gotoxy(46,1+i);
		cout << "                                                                                       ";
		
	}
	gotoxy(46,4);
	cout << char(218) << setw(86) << setfill(char(196)) << char(191);
	gotoxy(46,6);
	cout << char(218) << setw(86) << setfill(char(196)) << char(191);
	for(int i = 0; i < 20; i++){
		
		gotoxy(46,5+i);
		cout << char(179);
		gotoxy(132,5+i);
		cout << char(179);
	}
		
	for(int i = 0; i < 19; i++){
		
		gotoxy(52,5+i);
		cout << char(179);
		gotoxy(72,5+i);
		cout << char(179);
		gotoxy(113,5+i);
		cout << char(179);
		
	}
	gotoxy(47,23);
	cout << setw(85) << setfill(char(196))<<char(196) ;
	gotoxy(46,25);
	cout << char(192) << setw(86) << setfill(char(196)) << char(217);
	gotoxy(48,5);
	cout << "STT";
	gotoxy(58,5);
	cout << "MA KHOA HOC";
	gotoxy(88,5);
	cout << "TEN KHOA HOC";
	gotoxy(120,5);
	cout << "THOI HAN";
	gotoxy(50,24);
	cout <<        "ESC:EXIT || F1:INSERT || F2:EDIT || F3:DELETE || UP-DOWN-LEFT-RIGHT:NEXT PAGE";
	gotoxy(46,1);
	cout << char(218) <<setw(85) << setfill(char(196))<<char(196) << char(191);
	gotoxy(46,2);
	cout << char(179);
	gotoxy(132,2);
	cout << char(179);
	gotoxy(46,3);
	cout << char(192) << setw(86) << setfill(char(196)) << char(217);

}
void Khung_XemKhoaHocDK()
{
	XoaMhlop();
	Khung_Chucnang();
	for (int i = 0; i < 4 ; i++)
		{
			if (i == 2) { TextColor(180); }
			else { TextColor(240); }
			gotoxy(5, 4 + i * 4); cout << "                              ";
			gotoxy(5, 5 + i * 4); cout << MENULOP[i];
			gotoxy(5, 6 + i * 4); cout << "                              ";
		}
	for(int i=0;i<25;i++)
	{
		SetBGColor(179);
		gotoxy(46,4+i);
		cout << "                                                                                       ";
		
	}
	gotoxy(46,7);
	cout << char(218) << setw(86) << setfill(char(196)) << char(191);
	gotoxy(46,9);
	cout << char(218) << setw(86) << setfill(char(196)) << char(191);
	for(int i = 0; i < 20; i++){
		
		gotoxy(46,8+i);
		cout << char(179);
		gotoxy(132,8+i);
		cout << char(179);
	}
		
	for(int i = 0; i < 19; i++){
		
		gotoxy(52,8+i);
		cout << char(179);
		gotoxy(72,8+i);
		cout << char(179);
		gotoxy(113,8+i);
		cout << char(179);
		
	}
	gotoxy(47,26);
	cout << setw(85) << setfill(char(196))<<char(196) ;
	gotoxy(46,28);
	cout << char(192) << setw(86) << setfill(char(196)) << char(217);
	gotoxy(48,8);
	cout << "STT";
	gotoxy(58,8);
	cout << "MA KHOA HOC";
	gotoxy(88,8);
	cout << "TEN KHOA HOC";
	gotoxy(120,8);
	cout << "THOI HAN";
	gotoxy(50,27);
	cout <<        "ESC:BACK || UP-DOWN-LEFT-RIGHT:NEXT PAGE";
	gotoxy(46,4);
	cout << char(218) <<setw(85) << setfill(char(196))<<char(196) << char(191);
	gotoxy(46,5);
	cout << char(179);
	gotoxy(132,5);
	cout << char(179);
	gotoxy(46,6);
	cout << char(192) << setw(86) << setfill(char(196)) << char(217);
}
void Khung_ThemMonHoc()
{
	system("color 71");
	for(int i=0;i<13;i++)
	{
		SetBGColor(110);
		gotoxy(65,8+i);
		cout << "                                                                                 ";
	}
	gotoxy(80,13);
	cout << char(218) <<setw(13) << setfill(char(196))<<char(196) << char(191);
	gotoxy(80,14);
	cout << char(179);
	gotoxy(94,14);
	cout << char(179);
	gotoxy(80,15);
	cout << char(192) << setw(14) << setfill(char(196)) << char(217);
	gotoxy(98,13);
	cout << char(218) <<setw(32) << setfill(char(196))<<char(196) << char(191);
	gotoxy(98,14);
	cout << char(179);
	gotoxy(131,14);
	cout << char(179);
	gotoxy(98,15);
	cout << char(192) << setw(33) << setfill(char(196)) << char(217);
	gotoxy(82,12);
	cout << "MA MON HOC";
	gotoxy(109,12);
	cout << "TEN MON HOC";
	gotoxy(65,8);
	cout << char(218) << setw(80) << setfill(char(196)) << char(191);
	gotoxy(65,10);
	cout << char(218) << setw(80) << setfill(char(196)) << char(191);
	for(int i = 0; i < 12; i++){
		
		gotoxy(65,9+i);
		cout << char(179);
		gotoxy(145,9+i);
		cout << char(179);
	}
		
	gotoxy(66,18);
	cout << setw(79) << setfill(char(196))<<char(196) ;
	gotoxy(65,20);
	cout << char(192) << setw(80) << setfill(char(196)) << char(217);
	gotoxy(126,19);
	cout << "ECS:";
	gotoxy(136,19);
	cout << "ENTER:";
	gotoxy(131,19);
	cout << "BACK";
	gotoxy(143,19);
	cout << "OK";
	
}
void Khung_SuaMonHoc()
{
	
	system("color 71");
	for(int i=0;i<11;i++)
	{
		SetBGColor(110);
		gotoxy(80,10+i);
		cout << "                                                  ";
	}
	gotoxy(80,10);
	cout << char(218) << setw(50) << setfill(char(196)) << char(191);
	gotoxy(80,12);
	cout << char(218) << setw(50) << setfill(char(196)) << char(191);
	for(int i = 0; i < 9; i++){
		
		gotoxy(80,11+i);
		cout << char(179);
		gotoxy(130,11+i);
		cout << char(179);
	}
	
	gotoxy(81,18);
	cout << setw(49) << setfill(char(196))<<char(196) ;
	gotoxy(80,20);
	cout << char(192) << setw(50) << setfill(char(196)) << char(217);
	gotoxy(108,14);
	cout << char(218) <<setw(13) << setfill(char(196))<<char(196) << char(191);
	gotoxy(108,15);
	cout << char(179);
	gotoxy(122,15);
	cout << char(179);
	gotoxy(108,16);
	cout << char(192) << setw(14) << setfill(char(196)) << char(217);
	gotoxy(83,15);
	cout << "Nhap Ma Mon Hoc Can Sua";
	gotoxy(110,19);
	cout << "ECS:";
	gotoxy(121,19);
	cout << "ENTER:";
	gotoxy(96,11);
	cout << "SUA THONG TIN MON HOC";
	gotoxy(115,19);
	cout << "BACK";
	gotoxy(128,19);
	cout << "OK";
	
	
}
void Khung_XoaMonHoc()
{
	system("color 71");
	for(int i=0;i<11;i++)
	{
		SetBGColor(110);
		gotoxy(80,10+i);
		cout << "                                                  ";
	}
	gotoxy(80,10);
	cout << char(218) << setw(50) << setfill(char(196)) << char(191);
	gotoxy(80,12);
	cout << char(218) << setw(50) << setfill(char(196)) << char(191);
	for(int i = 0; i < 9; i++){
		
		gotoxy(80,11+i);
		cout << char(179);
		gotoxy(130,11+i);
		cout << char(179);
	}
	
	gotoxy(81,18);
	cout << setw(49) << setfill(char(196))<<char(196) ;
	gotoxy(80,20);
	cout << char(192) << setw(50) << setfill(char(196)) << char(217);
	gotoxy(108,14);
	cout << char(218) <<setw(13) << setfill(char(196))<<char(196) << char(191);
	gotoxy(108,15);
	cout << char(179);
	gotoxy(122,15);
	cout << char(179);
	gotoxy(108,16);
	cout << char(192) << setw(14) << setfill(char(196)) << char(217);
	gotoxy(83,15);
	cout << "Nhap Ma Mon Hoc Can Xoa";
	gotoxy(110,19);
	cout << "ECS:";
	gotoxy(121,19);
	cout << "ENTER:";
	gotoxy(96,11);
	cout << "XOA THONG TIN MON HOC";
	gotoxy(115,19);
	cout << "BACK";
	gotoxy(128,19);
	cout << "OK";
	
	
}
void Khung_XemMonHoc()
{
	system("color 71");
	for(int i=0;i<25;i++)
	{
		SetBGColor(110);
		gotoxy(46,1+i);
		cout << "                                                                                       ";
		
	}
	gotoxy(46,4);
	cout << char(218) << setw(86) << setfill(char(196)) << char(191);
	gotoxy(46,6);
	cout << char(218) << setw(86) << setfill(char(196)) << char(191);
	for(int i = 0; i < 20; i++){
		
		gotoxy(46,5+i);
		cout << char(179);
		gotoxy(132,5+i);
		cout << char(179);
	}
		
	for(int i = 0; i < 19; i++){
		
		gotoxy(52,5+i);
		cout << char(179);
		gotoxy(72,5+i);
		cout << char(179);
		
		
	}
	gotoxy(47,23);
	cout << setw(85) << setfill(char(196))<<char(196) ;
	gotoxy(46,25);
	cout << char(192) << setw(86) << setfill(char(196)) << char(217);
	gotoxy(48,5);
	cout << "STT";
	gotoxy(58,5);
	cout << "MA MON HOC";
	gotoxy(88,5);
	cout << "TEN MON HOC";
	gotoxy(50,24);
	cout <<        "ESC:EXIT || F1:INSERT || F2:EDIT || F3:DELETE || UP-DOWN-LEFT-RIGHT:NEXT PAGE";
	gotoxy(46,1);
	cout << char(218) <<setw(85) << setfill(char(196))<<char(196) << char(191);
	gotoxy(46,2);
	cout << char(179);
	gotoxy(132,2);
	cout << char(179);
	gotoxy(46,3);
	cout << char(192) << setw(86) << setfill(char(196)) << char(217);

}
void Khung_ChucnangKhoaHoc()
{
	for(int i=0;i<41;i++)
	{
		SetBGColor(110);
		gotoxy(41,2+i);
		cout << "                                                                                                                                            ";
		
	}
	for(int i=0;i<20;i++)
	{
		SetBGColor(110);
		gotoxy(2,23+i);
		cout << "                                      ";
	}
	for(int i=0;i<19;i++)
	{
		SetBGColor(110);
		gotoxy(2,4+i);
		cout << "   ";
		gotoxy(35,4+i);
		cout << "     ";
		
	}
	SetBGColor(110);
	gotoxy(2,2);
	cout << "                                      ";
	gotoxy(2,3);
	cout << "                                      ";
	gotoxy(5,7);
	cout << "                              ";
	gotoxy(5,11);
	cout << "                              ";
	gotoxy(5,15);
	cout << "                              ";
	gotoxy(5,19);
	cout << "                              ";
	TextColor(176);
	gotoxy(1,1);
	cout << char(218) << setw(180) << setfill(char(196)) << char(191);
	for(int i = 2; i < 43; i++){
		gotoxy(1,i);
		cout << char(179);
		gotoxy(181,i);
		cout << char(179);
		gotoxy(40,i);
		cout << char(179);
	}

	gotoxy(1,43);
	cout << char(192) << setw(180) << setfill(char(196)) << char(217);
	
}
