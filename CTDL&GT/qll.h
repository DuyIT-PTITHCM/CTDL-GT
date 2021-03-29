//////// USERNAME: admin ---- PASSWORD: 123456 ////////
#include"qlkh.h"

// Cay nhi phan
// LOP
struct LopHoc {
	char Idlop[12]; // ma lop hoc // vd: D18CQCN02-N
	char Namelop[30]; // ten lop hoc // Cong Nghe Thong Tin 2
	char Idkhoa[4]; // ma khoa// vd: INT
	char Idkhoahoc[11]; // ma khoa hoc: CTDL
	};
struct dslop {
	LopHoc data;
	dslop *left;
	dslop *right;
};
typedef dslop *PTRLOP;
//KHOA
struct Khoa{
	char Idkhoa[4];
	char NameKhoa[30];
};
struct dskhoa{
	Khoa data;
	dskhoa *left;
	dskhoa *right;
};
typedef dskhoa *PTRKHOA;
//check rong
bool EmptyDSLOP(PTRLOP DSLOP) { 
	if (DSLOP == NULL) return true;
	return false;
}
bool EmptyDSKHOA(PTRKHOA DSKHOA) { 
	if (DSKHOA == NULL) return true;
	return false;
}
//Khoi tao Lop
void InsertNode_Lop(PTRLOP &DSLOP, LopHoc lop) {
	if (EmptyDSLOP(DSLOP)) {
		PTRLOP p = new dslop;
		p->data = lop;
		p->left = p->right = NULL;
		DSLOP = p;
		return;
	}
	else {
		if (0< strcmp(DSLOP->data.Idlop, lop.Idlop)) {
			InsertNode_Lop(DSLOP->left, lop);
		}
		else {
			InsertNode_Lop(DSLOP->right, lop);
		}
	}
}
//khoi tao khoa
void InsertNode_Khoa(PTRKHOA &DSKHOA, Khoa khoa) {
	if (EmptyDSKHOA(DSKHOA)) {
		PTRKHOA p = new dskhoa;
		p->data = khoa;
		p->left = p->right = NULL;
		DSKHOA = p;
		return;
	}
	else {
		if (0< strcmp(DSKHOA->data.Idkhoa, khoa.Idkhoa)) {
			InsertNode_Khoa(DSKHOA->left, khoa);
		}
		else {
			InsertNode_Khoa(DSKHOA->right, khoa);
		}
	}
}
bool KTSV_LOP(char a[])
{
	ifstream infile;
	string data;
	infile.open(a, ios::in);
	if (!infile) { return false;} //Khong tim thay file
	if (infile.good())
	{
		getline(infile, data);
		if(data.size() == 0){ // da co file nhung chua cho du lieu
			return false; // lop khong co sinh vien
		}
		else{
			return true; // lop da co sinh vien
		}
	}
	infile.close();
	
}
//----thao tac file-------
void DocFileLop(PTRLOP &DSLOP) {
	ifstream infile;
	string data;
	infile.open("DSLOP.txt", ios::in);
	if (!infile) {return; } //Khong tim thay file
	while (infile.good())
	{
		
		LopHoc lop;
		getline(infile, data);
		if (data.size() == 0) { break; } //Da co file nhung chua co du lieu
		strcpy(lop.Idlop, data.c_str());
		getline(infile, data);		strcpy(lop.Namelop, data.c_str());
		getline(infile, data);		strcpy(lop.Idkhoa, data.c_str());
		getline(infile, data);		strcpy(lop.Idkhoahoc, data.c_str());
		InsertNode_Lop(DSLOP, lop);
	}
	infile.close();
}
void GhiFile_LNR(ofstream &file, PTRLOP DSLOP)
{
	if (DSLOP != NULL)
	{
		GhiFile_LNR(file, DSLOP->left);
		file << DSLOP->data.Idlop << endl
			<< DSLOP->data.Namelop << endl
			<< DSLOP->data.Idkhoa << endl
			<< DSLOP->data.Idkhoahoc << endl;
		GhiFile_LNR(file, DSLOP->right);
	}
}
void GhiFileLop(PTRLOP DSLOP) {
	ofstream outfile;
	outfile.open("DSLOP.txt", ios::out);
	GhiFile_LNR(outfile, DSLOP);
	outfile.close();
}
void DocFileKhoa(PTRKHOA &DSKHOA) {
	ifstream infile;
	string data;
	infile.open("DSKHOA.txt", ios::in);
	if (!infile) {return;} //Khong tim thay file
	while (infile.good())
	{
		Khoa khoa;
		getline(infile, data);
		if (data.size() == 0) { break; } //Da co file nhung chua co du lieu
		strcpy(khoa.Idkhoa, data.c_str());
		getline(infile, data);		strcpy(khoa.NameKhoa, data.c_str());
		InsertNode_Khoa(DSKHOA, khoa);
	}
	infile.close();
}

// KT ID LOP
int KTIDLOP(PTRLOP DSLOP, char lop[]) {
	if (DSLOP == NULL)
	{
		return 0; // id lop khong ton tai
	}
	else {
		if (strcmp(DSLOP->data.Idlop, lop) == 0)
		{
			return 1; // tim thay id lop
		}
		else if (strcmp(DSLOP->data.Idlop, lop) >0)
		{
			KTIDLOP(DSLOP->left, lop);
		}
		else {
			KTIDLOP(DSLOP->right, lop);
		}
	}
}
// KT ID KHOA THEO DSKHOA
int CHECKKHOA(PTRKHOA DSKHOA, char khoa[]) {
	if (DSKHOA == NULL)
	{
		return 0;
	}
	else {
		if (strcmp(DSKHOA->data.Idkhoa, khoa) == 0)
		{
			return 1;
		}
		else if (strcmp(DSKHOA->data.Idkhoa, khoa) >0)
		{
			CHECKKHOA(DSKHOA->left, khoa);
		}
		else {
			CHECKKHOA(DSKHOA->right, khoa);
		}
	}
}


PTRLOP Search_IDLop(PTRLOP &DSLOP, char lop[]) {
	if (EmptyDSLOP(DSLOP)) { return NULL; } 
	else {
		if (0 == strcmp(DSLOP->data.Idlop, lop)) {
			return DSLOP; // tra ve thong tin lop can tim
		}
		else if (0< strcmp(DSLOP->data.Idlop, lop)) {
			Search_IDLop(DSLOP->left, lop);
		}
		else {
			Search_IDLop(DSLOP->right, lop);
		}
	}
}
PTRLOP Search_IDKhoa(PTRLOP &DSLOP, char lop[]) {
	if (EmptyDSLOP(DSLOP)) { return NULL; }
	else {
		if (0 == strcmp(DSLOP->data.Idkhoa, lop)) {
			return DSLOP;
		}
		else if (0< strcmp(DSLOP->data.Idkhoa, lop)) {
			Search_IDKhoa(DSLOP->left, lop);
		}
		else {
			Search_IDKhoa(DSLOP->right, lop);
		}
	}
}
int DemLopHoc(PTRLOP DSLOP) {
	if (DSLOP != NULL)
	{
		return (DemLopHoc(DSLOP->left) + DemLopHoc(DSLOP->right) + 1);
	}
	else return 0;
}
int DemKhoa(PTRKHOA DSKHOA) {
	if (DSKHOA != NULL)
	{
		return (DemKhoa(DSKHOA->left) + DemKhoa(DSKHOA->right) + 1);
	}
	else return 0;
}
// Do cay ra mang
void MangTam_Lop(PTRLOP DSLOP, LopHoc lop[], int &dem) {
	//phep duyet LNR
	if (DSLOP != NULL)
	{
		MangTam_Lop(DSLOP->left, lop, dem);
		lop[dem++] = DSLOP->data;
		MangTam_Lop(DSLOP->right, lop, dem);
	}
}
void MangTam_Khoa(PTRKHOA DSKHOA, Khoa khoa[], int &dem) {
	//phep duyet LNR
	if (DSKHOA != NULL)
	{
		MangTam_Khoa(DSKHOA->left, khoa, dem);
		khoa[dem++] = DSKHOA->data;
		MangTam_Khoa(DSKHOA->right, khoa, dem);
	}
}
void Sort_MangLop(LopHoc a[], int n) { //Lop khong qua nhieu. Dung Selection Sort
	LopHoc min;
	int vitrimin;
	int i, j;
	for (i = 0; i < n - 1; i++) {
		min = a[i];
		vitrimin = i;
		for (j = i + 1; j < n; j++) {
			if (strcmp(min.Namelop, a[j].Namelop) >0)
			{
				min = a[j];
				vitrimin = j;
			}
		}
		min = a[vitrimin];
		a[vitrimin] = a[i];
		a[i] = min;
	}
}
void Sort_MangKhoa(Khoa a[], int n) { //Lop khong qua nhieu. Dung Selection Sort
	Khoa min;
	int vitrimin;
	int i, j;
	for (i = 0; i < n - 1; i++) {
		min = a[i];
		vitrimin = i;
		for (j = i + 1; j < n; j++) {
			if (strcmp(min.NameKhoa, a[j].NameKhoa) >0)
			{
				min = a[j];
				vitrimin = j;
			}
		}
		min = a[vitrimin];
		a[vitrimin] = a[i];
		a[i] = min;
	}
}
bool Login(){
	
	system("color 70");
	char name[25], pass[25];
	int sizename = 0, sizepass = 0;
	char key1 = '\0';
	Khung_Login();
	Khung_HuongDan();
Username:
	Yescursortype();
	while(1)
	{
		gotoxy(103+sizename,14);
		key1 = GetKey();
		if( key1 == UP)
		{
			gotoxy(103+sizename,14);
			goto Username;
		}
		if( key1 == DOWN)
		{
			gotoxy(103+sizepass,18);
			goto Password;
		}
		if( key1 == ENTER)
		{
			Nocursortype();
			TextColor(240);
			gotoxy(104, 21 ); cout << "             ";
			gotoxy(104, 22 ); cout << "     LOGIN    ";
			gotoxy(104, 23 ); cout << "             ";
			gotoxy(104,21);
			cout << char(218) <<setw(13) << setfill(char(196))<<char(196) << char(191);
			gotoxy(104,22);
			cout << char(179);
			gotoxy(118,22);
			cout << char(179);
			gotoxy(104,23);
			cout << char(192) << setw(14) << setfill(char(196)) << char(217);
			gotoxy(111,22);
			goto Login;
		}
		if(name[0] == '\0')
		{
			while(true)
			{
				key1 = GetKey();
				if(key1 != 8)
				{
					break;
				}
			}
		}
		if(key1 == 8)
		{
			if(sizename != 0)
			{
				name[sizename] = '\0';
				sizename--;
				cout << "\b  \b";
			}
			
		}
		else
		{
			if(sizename >= 0 && ((key1 >= 'A' && key1 <= 'Z') || (key1 <= '9' && key1 >= '0') || (key1 >= 'a' && key1 <= 'z')) && (sizename < 26) ){
			gotoxy(103+sizename,14);
			cout << key1;
			name[sizename] = key1;
			sizename++;
			Sleep(100);
			}
			
		}
		if (key1 == ESC || key1 == F1) { return false; }
	}	
Password:
	Yescursortype();
	while(1)
	{
		key1 = GetKey();
		if( key1 == UP)
		{
			gotoxy(103+sizename,14);
			goto Username;
		}
		if( key1 == DOWN)
		{
			Nocursortype();
			TextColor(240);
			gotoxy(104, 21 ); cout << "             ";
			gotoxy(104, 22 ); cout << "     LOGIN    ";
			gotoxy(104, 23 ); cout << "             ";
			gotoxy(104,21);
			cout << char(218) <<setw(13) << setfill(char(196))<<char(196) << char(191);
			gotoxy(104,22);
			cout << char(179);
			gotoxy(118,22);
			cout << char(179);
			gotoxy(104,23);
			cout << char(192) << setw(14) << setfill(char(196)) << char(217);
			gotoxy(111,22);
			goto Login;
		}
		if( key1 == ENTER)
		{
			Nocursortype();
			TextColor(240);
			gotoxy(104, 21 ); cout << "             ";
			gotoxy(104, 22 ); cout << "     LOGIN    ";
			gotoxy(104, 23 ); cout << "             ";
			gotoxy(104,21);
			cout << char(218) <<setw(13) << setfill(char(196))<<char(196) << char(191);
			gotoxy(104,22);
			cout << char(179);
			gotoxy(118,22);
			cout << char(179);
			gotoxy(104,23);
			cout << char(192) << setw(14) << setfill(char(196)) << char(217);
			gotoxy(111,22);
			goto Login;
		}
		if(pass[0] == '\0')
		{
			while(true)
			{
				key1 = GetKey();
				if(key1 != 8)
				{
					break;
				}
			}
		}
		if(key1 == 8)
		{
			if(sizepass != 0 )
			{
				pass[sizepass] = '\0';
				sizepass--;
				cout << "\b \b";
			}
			
		}
		else
		{
			if(sizepass >= 0 && ((key1 >= 'A' && key1 <= 'Z') || (key1 <= '9' && key1 >= '0') || (key1 >= 'a' && key1 <= 'z')) && (sizepass < 26) ){
			gotoxy(103+sizepass,18);
			cout << key1;
			pass[sizepass] = key1;
			sizepass++;
			Sleep(50);
			cout << "\b \b*";
			}
			
		}
		if (key1 == ESC || key1 == F1) { return false; }
	}
Login:
	while(1){
		key1 = GetKey();
			if( key1 == UP)
			{
				TextColor(48);
				gotoxy(104, 21 ); cout << "             ";
				gotoxy(104, 22 ); cout << "     LOGIN    ";
				gotoxy(104, 23 ); cout << "             ";
				gotoxy(104,21);
				cout << char(218) <<setw(13) << setfill(char(196))<<char(196) << char(191);
				gotoxy(104,22);
				cout << char(179);
				gotoxy(118,22);
				cout << char(179);
				gotoxy(104,23);
				cout << char(192) << setw(14) << setfill(char(196)) << char(217);
				gotoxy(103+sizepass,18);
				goto Password;
			}
			if(key1 == ENTER){
				
				if(strcmp(name,"admin") != 0 || strcmp(pass,"20062020") != 0)
				{
					TextColor(48);
					gotoxy(102,20);
					cout << "Tai khoan khong hop le";
					Beep(1000,1000);
					gotoxy(104, 21 ); cout << "             ";
					gotoxy(104, 22 ); cout << "     LOGIN    ";
					gotoxy(104, 23 ); cout << "             ";
					gotoxy(104,21);
					cout << char(218) <<setw(13) << setfill(char(196))<<char(196) << char(191);
					gotoxy(104,22);
					cout << char(179);
					gotoxy(118,22);
					cout << char(179);
					gotoxy(104,23);
					cout << char(192) << setw(14) << setfill(char(196)) << char(217);
					gotoxy(103+sizename,14);
					goto Username;
				}
				else {
					TextColor(48);
					gotoxy(102,20);
					cout << "                      ";
					gotoxy(102,20);
					cout << "Dang nhap thanh cong";
					cout << "\a";
					Sleep(1000);
					return true;
				}
			}
			if (key1 == ESC || key1 == F1) { return false; }
}		

}
//--them lop hoc

void ThemLopHoc(PTRLOP &DSLOP, PTRKHOA &DSKHOA)
{
	
	int key, vitri = 0, x = 88, y = 13, check_trung;
	LopHoc lop;	lop.Idlop[0] = NULL;	lop.Namelop[0] = NULL;	lop.Idkhoa[0] = NULL; lop.Idkhoahoc[11];
	gotoxy(x, y);Khung_ThemLop();
	gotoxy(95,9);
	cout << "THEM LOP MOI";
IDLOP:
	while (1)
	{
		
		gotoxy(88 + vitri, y);
		key = GetKey();
		if (((key >= 'A' && key <= 'Z')  || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z') || (key == '-')) && (vitri < 11))
		{
			lop.Idlop[vitri] = char(key);
			lop.Idlop[vitri] = toupper(lop.Idlop[vitri]);
			cout << lop.Idlop[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoxy(88 + vitri, y);
			cout << " ";
			gotoxy(88 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			lop.Idlop[vitri] = '\0';
			check_trung = KTIDLOP(DSLOP, lop.Idlop);
			if (check_trung == 1) {
				gotoxy(66, 32);
				cout << "Trung Ma Lop Hoc. Nhap Lai!";
				Beep(1000, 500);
				continue;
			}
			vitri = strlen(lop.Namelop);
			gotoxy(88 + vitri, 16);
			goto NAMELOP;
		}
		if (key == DOWN)
		{
			lop.Idlop[vitri] = '\0';
			check_trung = KTIDLOP(DSLOP, lop.Idlop);
			if (check_trung == 1) {
				gotoxy(66, 32);
				cout << "Trung Ma Lop Hoc. Nhap Lai!";
				Beep(1000, 500); continue;
			}
			vitri = strlen(lop.Namelop);
			gotoxy(88 + vitri, y);
			goto NAMELOP;
		}
		
	}
NAMELOP:
	while (1)
	{
		
		  
		if (lop.Idlop[0] == '\0')
		{
			GhiChu("Ban Chua Nhap Ma Lop Hoc!", 66, 32, 200);
			Beep(1000, 500);
			gotoxy(88, y);
			goto IDLOP;
		}
		gotoxy(88+vitri, 16);
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 29))
		{
			lop.Namelop[vitri] = char(key);
			lop.Namelop[vitri] = toupper(lop.Namelop[vitri]);
			cout << lop.Namelop[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoxy(88 + vitri, 16);
			cout << " ";
			gotoxy(88 + vitri, 16);
		}
		if (key == SPACE && lop.Namelop[vitri - 1] != ' ' && vitri > 0 && vitri < 30) // ko cho 2 khoang trang && vitri = 0
		{
			gotoxy(88 + vitri, 16);
			cout << " ";
			lop.Namelop[vitri] = ' ';
			vitri++;
		}
		if (key == ENTER && vitri != 0)
		{
			if (lop.Namelop[vitri - 1] == ' ') { vitri--; } //Kiem tra ki tu cuoi cung la khoang trang thi xoa khoang trang
			lop.Namelop[vitri] = '\0';
			vitri = strlen(lop.Idkhoa);
			gotoxy(88 + vitri, 19);
			goto IDKHOA;
		}
		if (key == UP)
		{
			lop.Namelop[vitri] = '\0';
			vitri = strlen(lop.Idlop);
			gotoxy(88 + vitri, y);
			goto IDLOP;
		}
		if (key == DOWN)
		{
			if (lop.Namelop[vitri - 1] == ' ') { vitri--; } //Kiem tra ki tu cuoi cung la khoang trang thi xoa khoang trang
			lop.Namelop[vitri] = '\0';
			vitri = strlen(lop.Idkhoa);
			gotoxy(88 + vitri, 19);
			goto IDKHOA;
		}
		
	}
IDKHOA:
	Yescursortype();
	while (1)
	{
		// Ghi chú
		if (lop.Namelop[0] == '\0')
		{
			GhiChu("Ban Chua Nhap Ten Lop Hoc!", 66, 32, 200);
			Beep(1000, 500);
			gotoxy(88 , 16);
			goto NAMELOP;
		}
		gotoxy(88 + vitri,19);
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 3))
		{
			lop.Idkhoa[vitri] = char(key);
			lop.Idkhoa[vitri] = toupper(lop.Idkhoa[vitri]);
			cout << lop.Idkhoa[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoxy(88 + vitri, 19);
			cout << " ";
			gotoxy(88 + vitri, 19);
		}
		if (key == ENTER && vitri != 0)
		{
			lop.Idkhoa[vitri] = '\0';
			TextColor(128);
			gotoxy(107, 27 ); cout << "             ";
			gotoxy(107, 28 ); cout << "   THEM LOP   ";
			gotoxy(107, 29 ); cout << "             ";
			gotoxy(107,27);
			cout << char(218) <<setw(13) << setfill(char(196))<<char(196) << char(191);
			gotoxy(107,28);
			cout << char(179);
			gotoxy(121,28);
			cout << char(179);
			gotoxy(107,29);
			cout << char(192) << setw(14) << setfill(char(196)) << char(217);
			gotoxy(114,28);
			goto THEMLOP;
		}
		if (key == UP)
		{
			lop.Idkhoa[vitri] = '\0';
			vitri = strlen(lop.Namelop);
			gotoxy(88 + vitri, 16);
			goto NAMELOP;
		}
		if (key == DOWN && vitri != 0)
		{
			lop.Idkhoa[vitri] = '\0';
			TextColor(128);
			gotoxy(107, 27 ); cout << "             ";
			gotoxy(107, 28 ); cout << "   THEM LOP   ";
			gotoxy(107, 29 ); cout << "             ";
			gotoxy(107,27);
			cout << char(218) <<setw(13) << setfill(char(196))<<char(196) << char(191);
			gotoxy(107,28);
			cout << char(179);
			gotoxy(121,28);
			cout << char(179);
			gotoxy(107,29);
			cout << char(192) << setw(14) << setfill(char(196)) << char(217);
			gotoxy(114,28);
			goto THEMLOP;
		}
		
	}
THEMLOP:
	Nocursortype();
	while(1)
	{
		
		key = GetKey();
		if(key == UP){
			
			TextColor(48);
			gotoxy(79, 27 ); cout << "             ";
			gotoxy(79, 28 ); cout << "      HUY     ";
			gotoxy(79, 29 ); cout << "             ";
			gotoxy(79,27);
			cout << char(218) <<setw(13) << setfill(char(196))<<char(196) << char(191);
			gotoxy(79,28);
			cout << char(179);
			gotoxy(93,28);
			cout << char(179);
			gotoxy(79,29);
			cout << char(192) << setw(14) << setfill(char(196)) << char(217);
			TextColor(48);
			gotoxy(107, 27 ); cout << "             ";
			gotoxy(107, 28 ); cout << "   THEM LOP   ";
			gotoxy(107, 29 ); cout << "             ";
			gotoxy(107,27);
			cout << char(218) <<setw(13) << setfill(char(196))<<char(196) << char(191);
			gotoxy(107,28);
			cout << char(179);
			gotoxy(121,28);
			cout << char(179);
			gotoxy(107,29);
			cout << char(192) << setw(14) << setfill(char(196)) << char(217);
			vitri = strlen(lop.Idkhoa);
			gotoxy(88 + vitri, 19);
			goto IDKHOA;
		}
		if((key == LEFT) || (key == RIGHT))
		{
			TextColor(128);
			gotoxy(79, 27 ); cout << "             ";
			gotoxy(79, 28 ); cout << "      HUY     ";
			gotoxy(79, 29 ); cout << "             ";
			gotoxy(79,27);
			cout << char(218) <<setw(13) << setfill(char(196))<<char(196) << char(191);
			gotoxy(79,28);
			cout << char(179);
			gotoxy(93,28);
			cout << char(179);
			gotoxy(79,29);
			cout << char(192) << setw(14) << setfill(char(196)) << char(217);
			TextColor(48);
			gotoxy(107, 27 ); cout << "             ";
			gotoxy(107, 28 ); cout << "   THEM LOP   ";
			gotoxy(107, 29 ); cout << "             ";
			gotoxy(107,27);
			cout << char(218) <<setw(13) << setfill(char(196))<<char(196) << char(191);
			gotoxy(107,28);
			cout << char(179);
			gotoxy(121,28);
			cout << char(179);
			gotoxy(107,29);
			cout << char(192) << setw(14) << setfill(char(196)) << char(217);
			gotoxy(87,28);
			goto HUY;
		}
		if(key == ENTER)
		{
			TextColor(48);
			lop.Idkhoa[vitri] = '\0';
			check_trung = CHECKKHOA(DSKHOA, lop.Idkhoa);
			if (check_trung != 1) {
				gotoxy(66, 32);
				cout <<"Ma Khoa Khong Ton Tai!      ";
				Beep(1000,600);
				gotoxy(66, 32);
				cout <<"                            ";
				continue;
			}
			else {
				InsertNode_Lop(DSLOP, lop);
				gotoxy(66,32);
				cout << "                            ";
				gotoxy(66,9);
				GhiChu("Them Thanh Cong", 66, 32, 1000);
				cout << "\a";
				GhiFileLop(DSLOP);
				return;
			}
		}
	}
HUY:
	Nocursortype();
	while(1)
	{
		key = GetKey();
		if(key == UP){
			TextColor(48);
			gotoxy(79, 27 ); cout << "             ";
			gotoxy(79, 28 ); cout << "      HUY     ";
			gotoxy(79, 29 ); cout << "             ";
			gotoxy(79,27);
			cout << char(218) <<setw(13) << setfill(char(196))<<char(196) << char(191);
			gotoxy(79,28);
			cout << char(179);
			gotoxy(93,28);
			cout << char(179);
			gotoxy(79,29);
			cout << char(192) << setw(14) << setfill(char(196)) << char(217);
			TextColor(48);
			gotoxy(107, 27 ); cout << "             ";
			gotoxy(107, 28 ); cout << "   THEM LOP   ";
			gotoxy(107, 29 ); cout << "             ";
			gotoxy(107,27);
			cout << char(218) <<setw(13) << setfill(char(196))<<char(196) << char(191);
			gotoxy(107,28);
			cout << char(179);
			gotoxy(121,28);
			cout << char(179);
			gotoxy(107,29);
			cout << char(192) << setw(14) << setfill(char(196)) << char(217);
			vitri = strlen(lop.Idkhoa);
			gotoxy(88 + vitri, 19);
			goto IDKHOA;
		}
		if((key == LEFT) || (key == RIGHT))
		{
			TextColor(48);
			gotoxy(79, 27 ); cout << "             ";
			gotoxy(79, 28 ); cout << "      HUY     ";
			gotoxy(79, 29 ); cout << "             ";
			gotoxy(79,27);
			cout << char(218) <<setw(13) << setfill(char(196))<<char(196) << char(191);
			gotoxy(79,28);
			cout << char(179);
			gotoxy(93,28);
			cout << char(179);
			gotoxy(79,29);
			cout << char(192) << setw(14) << setfill(char(196)) << char(217);
			TextColor(128);
			gotoxy(107, 27 ); cout << "             ";
			gotoxy(107, 28 ); cout << "   THEM LOP   ";
			gotoxy(107, 29 ); cout << "             ";
			gotoxy(107,27);
			cout << char(218) <<setw(13) << setfill(char(196))<<char(196) << char(191);
			gotoxy(107,28);
			cout << char(179);
			gotoxy(121,28);
			cout << char(179);
			gotoxy(107,29);
			cout << char(192) << setw(14) << setfill(char(196)) << char(217);
			gotoxy(114,28);
			goto THEMLOP;
		}
		if(key == ENTER)
		{
			return;
		}
	}
}


//--sua lop hoc----
void SuaLopHoc(PTRLOP &DSLOP, PTRKHOA &DSKHOA)
{
	int key, vitri = 0, x = 110, y = 15, check_trung;
	PTRLOP p;
	LopHoc lop;	lop.Idlop[0] = NULL;	lop.Namelop[0] = NULL;	lop.Idkhoa[0] = NULL;	lop.Idkhoahoc[11];
	Khung_SuaLop();gotoxy(x, y);
	//dau tien phai tim cai vi tri cua ma lop 
TIMIDLOP:	
	while (1)
	{
		
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z') || (key == '-')) && (vitri < 11))
		{
			lop.Idlop[vitri] = char(key);
			lop.Idlop[vitri] = toupper(lop.Idlop[vitri]);
			cout << lop.Idlop[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoxy(110 + vitri, y);
			cout << " ";
			gotoxy(110 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			
			lop.Idlop[vitri] = '\0';	//Ngat chuoi~
			check_trung = KTIDLOP(DSLOP, lop.Idlop); //KT trung`. 1: trung, co ton tai 0: ko trung
			if (check_trung != 0)
			{
				bool check = KTSV_LOP(lop.Idlop);
				p = Search_IDLop(DSLOP, lop.Idlop);
				strcpy(lop.Idlop, p->data.Idlop);
				strcpy(lop.Idkhoahoc, p->data.Idkhoahoc);
				if(strcmp(lop.Idkhoahoc, "") == 0 && check == false) //lop chua dk khoa hoc va chua co SV
				{
					system("cls");
					p = Search_IDLop(DSLOP, lop.Idlop);
					Khung_Sua();
					gotoxy(90,9);
					cout << "THONG TIN LOP CAN SUA";
					strcpy(lop.Idlop, p->data.Idlop);
					strcpy(lop.Namelop, p->data.Namelop);
					strcpy(lop.Idkhoa, p->data.Idkhoa);
					gotoxy(88, 13); cout << lop.Idlop;
					gotoxy(88, 16); cout << lop.Namelop;
					gotoxy(88, 19); cout << lop.Idkhoa;
					vitri = strlen(lop.Idlop);
					goto IDLOP;
					break;
				}
				else { //Lop da dk khoa hoc
					GhiChu("Lop Hoc Da Co Khoa Hoc/Sinh vien!", 76, 19, 1000);Beep(1000, 500);
					gotoxy(110 + vitri, y);
				}
			}
			else {
					GhiChu("Ma Lop Hoc Khong Ton Tai!        ", 76, 19, 100); Beep(1000, 500);	gotoxy(110 + vitri, y);
				}
		}
		if (key == ESC || key == F2) { return; }
	}
IDLOP:
	while (1)
	{
		
		gotoxy(88 + vitri, 13);
		key = GetKey();
		if (((key >= 'A' && key <= 'Z')  || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z') || (key == '-')) && (vitri < 11))
		{
			lop.Idlop[vitri] = char(key);
			lop.Idlop[vitri] = toupper(lop.Idlop[vitri]);
			cout << lop.Idlop[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoxy(88 + vitri, 13);
			cout << " ";
			gotoxy(88 + vitri, 13);
		}
		if (key == ENTER && vitri != 0)
		{
			lop.Idlop[vitri] = '\0';
			check_trung = KTIDLOP(DSLOP, lop.Idlop);
			if (check_trung == 1) {
				gotoxy(66, 32);
				cout << "Trung Ma Lop Hoc. Nhap Lai!";
				Beep(1000, 500);
				continue;
			}
			vitri = strlen(lop.Namelop);
			gotoxy(88 + vitri, 16);
			goto NAMELOP;
		}
		if (key == DOWN)
		{
			lop.Idlop[vitri] = '\0';
			check_trung = KTIDLOP(DSLOP, lop.Idlop);
			if (check_trung == 1) {
				gotoxy(66, 32);
				cout << "Trung Ma Lop Hoc. Nhap Lai!";
				Beep(1000, 500); continue;
			}
			vitri = strlen(lop.Namelop);
			gotoxy(88 + vitri, 16);
			goto NAMELOP;
		}
		
	}
NAMELOP:
	while (1)
	{
		
		  
		if (lop.Idlop[0] == '\0')
		{
			GhiChu("Ban Chua Nhap Ma Lop Hoc!", 66, 32, 100);
			Beep(1000, 500);
			vitri = 0;
			goto IDLOP;
		}
		gotoxy(88+vitri, 16);
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 29))
		{
			lop.Namelop[vitri] = char(key);
			lop.Namelop[vitri] = toupper(lop.Namelop[vitri]);
			cout << lop.Namelop[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoxy(88 + vitri, 16);
			cout << " ";
			gotoxy(88 + vitri, 16);
		}
		if (key == SPACE && lop.Namelop[vitri - 1] != ' ' && vitri > 0 && vitri < 30) // ko cho 2 khoang trang && vitri = 0
		{
			gotoxy(88 + vitri, 16);
			cout << " ";
			lop.Namelop[vitri] = ' ';
			vitri++;
		}
		if (key == ENTER && vitri != 0)
		{
			if (lop.Namelop[vitri - 1] == ' ') { vitri--; } //Kiem tra ki tu cuoi cung la khoang trang thi xoa khoang trang
			lop.Namelop[vitri] = '\0';
			vitri = strlen(lop.Idkhoa);
			gotoxy(88 + vitri, 19);
			goto IDKHOA;
		}
		if (key == UP)
		{
			lop.Namelop[vitri] = '\0';
			vitri = strlen(lop.Idlop);
			gotoxy(88 + vitri, y);
			goto IDLOP;
		}
		if (key == DOWN)
		{
			if (lop.Namelop[vitri - 1] == ' ') { vitri--; } //Kiem tra ki tu cuoi cung la khoang trang thi xoa khoang trang
			lop.Namelop[vitri] = '\0';
			vitri = strlen(lop.Idkhoa);
			gotoxy(88 + vitri, 19);
			goto IDKHOA;
		}
		
	}
IDKHOA:
	Yescursortype();
	while (1)
	{
		// Ghi chú
		if (lop.Namelop[0] == '\0')
		{
			GhiChu("Ban Chua Nhap Ten Lop Hoc!", 66, 32, 200);
			Beep(1000, 500);
			vitri = 0;
			goto NAMELOP;
		}
		gotoxy(88 + vitri,19);
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 3))
		{
			lop.Idkhoa[vitri] = char(key);
			lop.Idkhoa[vitri] = toupper(lop.Idkhoa[vitri]);
			cout << lop.Idkhoa[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoxy(88 + vitri, 19);
			cout << " ";
			gotoxy(88 + vitri, 19);
		}
		if (key == ENTER && vitri != 0)
		{
			lop.Idkhoa[vitri] = '\0';
			TextColor(128);
			gotoxy(107, 27 ); cout << "             ";
			gotoxy(107, 28 ); cout << "    SUA LOP   ";
			gotoxy(107, 29 ); cout << "             ";
			gotoxy(107,27);
			cout << char(218) <<setw(13) << setfill(char(196))<<char(196) << char(191);
			gotoxy(107,28);
			cout << char(179);
			gotoxy(121,28);
			cout << char(179);
			gotoxy(107,29);
			cout << char(192) << setw(14) << setfill(char(196)) << char(217);
			gotoxy(114,28);
			goto SUALOP;
		}
		if (key == UP)
		{
			lop.Idkhoa[vitri] = '\0';
			vitri = strlen(lop.Namelop);
			gotoxy(88 + vitri, 16);
			goto NAMELOP;
		}
		if (key == DOWN && vitri != 0)
		{
			lop.Idkhoa[vitri] = '\0';
			TextColor(128);
			gotoxy(107, 27 ); cout << "             ";
			gotoxy(107, 28 ); cout << "    SUA LOP   ";
			gotoxy(107, 29 ); cout << "             ";
			gotoxy(107,27);
			cout << char(218) <<setw(13) << setfill(char(196))<<char(196) << char(191);
			gotoxy(107,28);
			cout << char(179);
			gotoxy(121,28);
			cout << char(179);
			gotoxy(107,29);
			cout << char(192) << setw(14) << setfill(char(196)) << char(217);
			gotoxy(114,28);
			goto SUALOP;
		}
		
	}
SUALOP:
	Nocursortype();
	while(1)
	{
		key = GetKey();
		if(key == UP){
			
			TextColor(48);
			gotoxy(79, 27 ); cout << "             ";
			gotoxy(79, 28 ); cout << "      HUY     ";
			gotoxy(79, 29 ); cout << "             ";
			gotoxy(79,27);
			cout << char(218) <<setw(13) << setfill(char(196))<<char(196) << char(191);
			gotoxy(79,28);
			cout << char(179);
			gotoxy(93,28);
			cout << char(179);
			gotoxy(79,29);
			cout << char(192) << setw(14) << setfill(char(196)) << char(217);
			TextColor(48);
			gotoxy(107, 27 ); cout << "             ";
			gotoxy(107, 28 ); cout << "    SUA LOP   ";
			gotoxy(107, 29 ); cout << "             ";
			gotoxy(107,27);
			cout << char(218) <<setw(13) << setfill(char(196))<<char(196) << char(191);
			gotoxy(107,28);
			cout << char(179);
			gotoxy(121,28);
			cout << char(179);
			gotoxy(107,29);
			cout << char(192) << setw(14) << setfill(char(196)) << char(217);
			vitri = strlen(lop.Idkhoa);
			gotoxy(88 + vitri, 19);
			goto IDKHOA;
		}
		if((key == LEFT) || (key == RIGHT))
		{
			TextColor(128);
			gotoxy(79, 27 ); cout << "             ";
			gotoxy(79, 28 ); cout << "      HUY     ";
			gotoxy(79, 29 ); cout << "             ";
			gotoxy(79,27);
			cout << char(218) <<setw(13) << setfill(char(196))<<char(196) << char(191);
			gotoxy(79,28);
			cout << char(179);
			gotoxy(93,28);
			cout << char(179);
			gotoxy(79,29);
			cout << char(192) << setw(14) << setfill(char(196)) << char(217);
			TextColor(48);
			gotoxy(107, 27 ); cout << "             ";
			gotoxy(107, 28 ); cout << "    SUA LOP   ";
			gotoxy(107, 29 ); cout << "             ";
			gotoxy(107,27);
			cout << char(218) <<setw(13) << setfill(char(196))<<char(196) << char(191);
			gotoxy(107,28);
			cout << char(179);
			gotoxy(121,28);
			cout << char(179);
			gotoxy(107,29);
			cout << char(192) << setw(14) << setfill(char(196)) << char(217);
			gotoxy(87,28);
			goto HUY;
		}
		if(key == ENTER)
		{
			TextColor(48);
			lop.Idkhoa[vitri] = '\0';
			check_trung = CHECKKHOA(DSKHOA, lop.Idkhoa);
			if (check_trung != 1) {
				gotoxy(66, 32);
				cout << "Ma Khoa Khong Ton Tai!      ";
				Beep(1000,600);
				gotoxy(66, 32);
				cout << "                            ";
				continue;
			}
			else {
			gotoxy(66,32);
			p->data = lop;
			GhiChu("Lop Hoc Da Duoc Cap Nhat!      ", 66, 32, 1000);
			cout << "\a";
			GhiFileLop(DSLOP);
			return;
			}
			
		}
	}
HUY:
	Nocursortype();
	while(1)
	{
		key = GetKey();
		if(key == UP){
			TextColor(48);
			gotoxy(79, 27 ); cout << "             ";
			gotoxy(79, 28 ); cout << "      HUY     ";
			gotoxy(79, 29 ); cout << "             ";
			gotoxy(79,27);
			cout << char(218) <<setw(13) << setfill(char(196))<<char(196) << char(191);
			gotoxy(79,28);
			cout << char(179);
			gotoxy(93,28);
			cout << char(179);
			gotoxy(79,29);
			cout << char(192) << setw(14) << setfill(char(196)) << char(217);
			TextColor(48);
			gotoxy(107, 27 ); cout << "             ";
			gotoxy(107, 28 ); cout << "    SUA LOP   ";
			gotoxy(107, 29 ); cout << "             ";
			gotoxy(107,27);
			cout << char(218) <<setw(13) << setfill(char(196))<<char(196) << char(191);
			gotoxy(107,28);
			cout << char(179);
			gotoxy(121,28);
			cout << char(179);
			gotoxy(107,29);
			cout << char(192) << setw(14) << setfill(char(196)) << char(217);
			vitri = strlen(lop.Idkhoa);
			gotoxy(88 + vitri, 19);
			goto IDKHOA;
		}
		if((key == LEFT) || (key == RIGHT))
		{
			TextColor(48);
			gotoxy(79, 27 ); cout << "             ";
			gotoxy(79, 28 ); cout << "      HUY     ";
			gotoxy(79, 29 ); cout << "             ";
			gotoxy(79,27);
			cout << char(218) <<setw(13) << setfill(char(196))<<char(196) << char(191);
			gotoxy(79,28);
			cout << char(179);
			gotoxy(93,28);
			cout << char(179);
			gotoxy(79,29);
			cout << char(192) << setw(14) << setfill(char(196)) << char(217);
			TextColor(128);
			gotoxy(107, 27 ); cout << "             ";
			gotoxy(107, 28 ); cout << "    SUA LOP   ";
			gotoxy(107, 29 ); cout << "             ";
			gotoxy(107,27);
			cout << char(218) <<setw(13) << setfill(char(196))<<char(196) << char(191);
			gotoxy(107,28);
			cout << char(179);
			gotoxy(121,28);
			cout << char(179);
			gotoxy(107,29);
			cout << char(192) << setw(14) << setfill(char(196)) << char(217);
			gotoxy(114,28);
			goto SUALOP;
		}
		if(key == ENTER)
		{
			return;
		}
	}
}
//--xoa lop hoc
void PhanTuTheMang(PTRLOP &p, PTRLOP &q) {
	if (q->left != NULL)
	{
		PhanTuTheMang(p, q->left);
	}
	else {
		p->data = q->data;			//cap nhat du lieu vô cùng trái sang con tro can xóa
		p = q;						//cap nhat dia chi vô cùng trái sang con tro can xóa
		q = q->right;				//ben phai cua vo cung trai dôn lên
	}
}
void DeleteNode_Lop(PTRLOP &DSLOP, char c[]) {
	if (DSLOP == NULL) { return; }
	//Truong hop node goc > hoac < char c
	if (strcmp(DSLOP->data.Idlop, c) >0)
	{
		DeleteNode_Lop(DSLOP->left, c);
	}
	else if (strcmp(DSLOP->data.Idlop, c) <0)
	{
		DeleteNode_Lop(DSLOP->right, c);
	}
	//Truong Hop node goc == char c
	else {
		PTRLOP p = DSLOP;		//Cho con tro tai vi tri muon xoa vao 1 con tro tam. De lat xoa
		if (DSLOP->left == NULL && DSLOP->right == NULL)	//Truong hop 2 nhanh con NULL
		{
			delete DSLOP; DSLOP = NULL; return;
		}
		if (DSLOP->left == NULL && DSLOP->right != NULL)	//Truong hop co nhanh con ben phai
		{
			DSLOP = DSLOP->right;
		}
		else if (DSLOP->right == NULL && DSLOP->left != NULL) //Truong hop co nhanh con ben trai
		{
			DSLOP = DSLOP->left;
		}
		//Truong hop ca 2 nhanh con deu != NULL
		else {
			PhanTuTheMang(p, DSLOP->right);
			delete p;
		}
	}
}

void XoaLopHoc(PTRLOP &DSLOP)
{
	int key, vitri = 0, x = 110, y = 15, check_trung;
	PTRLOP p;
	LopHoc lop;	lop.Idlop[0] = NULL; lop.Idkhoahoc[0] = NULL;
	Khung_XoaLop();gotoxy(x, y);
	 
RESET:	
	while (1)
	{
		
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z') || (key == '-')) && (vitri < 11))
		{
			lop.Idlop[vitri] = char(key);
			lop.Idlop[vitri] = toupper(lop.Idlop[vitri]);
			cout << lop.Idlop[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoxy(110 + vitri, y);
			cout << " ";
			gotoxy(110 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			
			lop.Idlop[vitri] = '\0';	//Ngat chuoi~
			check_trung = KTIDLOP(DSLOP, lop.Idlop); //KT trung`. 1: trung, co ton tai 0: ko trung
			if (check_trung != 0)
			{
				bool check = KTSV_LOP(lop.Idlop);
				p = Search_IDLop(DSLOP, lop.Idlop);
				strcpy(lop.Idlop, p->data.Idlop);
				strcpy(lop.Idkhoahoc, p->data.Idkhoahoc);
				if(strcmp(lop.Idkhoahoc, "") == 0 && check == false) //lop chua dk khoa hoc va chua co SV
				{
					system("cls");
					p = Search_IDLop(DSLOP, lop.Idlop);
					Khung_Xoa();
					gotoxy(90,9);
					cout << "THONG TIN LOP CAN XOA";
					strcpy(lop.Idlop, p->data.Idlop);
					strcpy(lop.Namelop, p->data.Namelop);
					strcpy(lop.Idkhoa, p->data.Idkhoa);
					gotoxy(88, 13); cout << lop.Idlop;
					gotoxy(88, 16); cout << lop.Namelop;
					gotoxy(88, 19); cout << lop.Idkhoa;
					TextColor(128);
					gotoxy(107, 27 ); cout << "             ";
					gotoxy(107, 28 ); cout << "    XOA LOP   ";
					gotoxy(107, 29 ); cout << "             ";
					gotoxy(107,27);
					cout << char(218) <<setw(13) << setfill(char(196))<<char(196) << char(191);
					gotoxy(107,28);
					cout << char(179);
					gotoxy(121,28);
					cout << char(179);
					gotoxy(107,29);
					cout << char(192) << setw(14) << setfill(char(196)) << char(217);
					gotoxy(114,28);
					goto XOALOP;
					break;
					
				}
				else { //Lop da dk khoa hoc
					GhiChu("Lop Hoc Da Co Khoa Hoc/Sinh vien!", 76, 19, 1000);Beep(1000, 500);
					gotoxy(110 + vitri, y);
				}
			}
			else {
					GhiChu("Ma Lop Hoc Khong Ton Tai!        ", 76, 19, 500);Beep(1000, 500);	gotoxy(110 + vitri, y);
			}
		}
		if (key == ESC || key == F2) { return; }
	}
XOALOP:
	Nocursortype();
	while(1)
	{
		key = GetKey();
		if((key == LEFT) || (key == RIGHT))
		{
			TextColor(128);
			gotoxy(79, 27 ); cout << "             ";
			gotoxy(79, 28 ); cout << "      HUY     ";
			gotoxy(79, 29 ); cout << "             ";
			gotoxy(79,27);
			cout << char(218) <<setw(13) << setfill(char(196))<<char(196) << char(191);
			gotoxy(79,28);
			cout << char(179);
			gotoxy(93,28);
			cout << char(179);
			gotoxy(79,29);
			cout << char(192) << setw(14) << setfill(char(196)) << char(217);
			TextColor(48);
			gotoxy(107, 27 ); cout << "             ";
			gotoxy(107, 28 ); cout << "    XOA LOP   ";
			gotoxy(107, 29 ); cout << "             ";
			gotoxy(107,27);
			cout << char(218) <<setw(13) << setfill(char(196))<<char(196) << char(191);
			gotoxy(107,28);
			cout << char(179);
			gotoxy(121,28);
			cout << char(179);
			gotoxy(107,29);
			cout << char(192) << setw(14) << setfill(char(196)) << char(217);
			gotoxy(87,28);
			goto HUY;
		}
		if(key == ENTER)
		{
			TextColor(48);
			DeleteNode_Lop(DSLOP, lop.Idlop);
			cout << "\a";
			GhiChu("Xoa Thanh Cong Lop Hoc!           ", 66, 32, 1500);
			gotoxy(66,32);
			cout <<"                                  ";
			GhiFileLop(DSLOP);
			return;
			
		}
	}
HUY:
	Nocursortype();
	while(1)
	{
		key = GetKey();
		if((key == LEFT) || (key == RIGHT))
		{
			TextColor(48);
			gotoxy(79, 27 ); cout << "             ";
			gotoxy(79, 28 ); cout << "      HUY     ";
			gotoxy(79, 29 ); cout << "             ";
			gotoxy(79,27);
			cout << char(218) <<setw(13) << setfill(char(196))<<char(196) << char(191);
			gotoxy(79,28);
			cout << char(179);
			gotoxy(93,28);
			cout << char(179);
			gotoxy(79,29);
			cout << char(192) << setw(14) << setfill(char(196)) << char(217);
			TextColor(128);
			gotoxy(107, 27 ); cout << "             ";
			gotoxy(107, 28 ); cout << "    XOA LOP   ";
			gotoxy(107, 29 ); cout << "             ";
			gotoxy(107,27);
			cout << char(218) <<setw(13) << setfill(char(196))<<char(196) << char(191);
			gotoxy(107,28);
			cout << char(179);
			gotoxy(121,28);
			cout << char(179);
			gotoxy(107,29);
			cout << char(192) << setw(14) << setfill(char(196)) << char(217);
			gotoxy(114,28);
			goto XOALOP;
		}
		if(key == ENTER)
		{
			return;
		}
	}
}

//--xem danh sach lop
void XemLopHoc(PTRLOP &DSLOP, PTRKHOA &DSKHOA, bool phanquyen) { // PHAN QUYEN: -true: admin -false: sinh vien
	int key;
	int  trang = 0, tongtrang = 0;
	int soluonglop, dem = 0, demdong = 0;
	while (1)
	{
		soluonglop = DemLopHoc(DSLOP);
		if (soluonglop == 0)
		{
			GhiChu("Chua co du lieu Lop Hoc", 35, 27, 500);
		}
		else {
			if (soluonglop < 15)
			{
				tongtrang = 1;
				trang = 0;
			}
			else {
				tongtrang = ((soluonglop - 1) / 15 + 1);
			}
		}
		LopHoc *LOP = new LopHoc[soluonglop + 1];
		MangTam_Lop(DSLOP, LOP, dem); //Do Cay Nhi Phan ra Mang?
		Sort_MangLop(LOP, soluonglop);
		dem = 0; demdong = 0;
		TextColor(14);	XoaMhlop();
		Khung_XemLop();
		if(phanquyen == false)
		{
			gotoxy(50,27);
			cout <<"ESC: EXIT || UP - DOWN - LEFT - RIGHT : NEXT PAGE                                  ";
		}
		for (int i = trang * 15; i < 15 + trang * 15 && i < soluonglop; i++)
		{
			
			gotoxy(49, 11 + demdong); cout << i+1;
			gotoxy(54, 11 + demdong); cout << LOP[i].Idlop;
			gotoxy(75, 11 + demdong); cout << LOP[i].Namelop;
			gotoxy(116, 11 + demdong); cout << LOP[i].Idkhoa;
			gotoxy(135, 11 + demdong); cout << LOP[i].Idkhoahoc;
			demdong++;
		}
		HienThiTrang(trang + 1, tongtrang, 140, 27);
		TextColor(164);
		gotoxy(47,5);
		cout << "                                           DANH SACH LOP                                                     ";
		Nocursortype();
		gotoxy(81, 29);
		key = GetKey();
		if ((key == RIGHT || key == DOWN) && trang < tongtrang - 1) { trang++; }
		if ((key == LEFT || key == UP) && trang > 0) { trang--; }
		if((key == F1 || key == F2 || key == F3) && phanquyen == false)
		{
			Beep(1000,700);
			gotoxy(46,29);
			cout << "SINH VIEN KHONG DUOC QUYEN CHINH SUA";
			Sleep(1000);
			gotoxy(46,29);
			cout << "                                    ";
		}
		if (key == F1 && phanquyen == true)
		{
			XoaMhlop();
			Yescursortype();
			ThemLopHoc(DSLOP, DSKHOA);
		}
		if (key == F2 && phanquyen == true)
		{
			XoaMhlop();
			Yescursortype();
			SuaLopHoc(DSLOP, DSKHOA);
		}
		if (key == F3 && phanquyen == true){
			XoaMhlop();
			Yescursortype();
			XoaLopHoc(DSLOP);
		}
		if (key == ESC) {return;}
		
		
	}
}
void BangDKKH(PTRLOP &DSLOP, PTRKHOAHOC &DSKHOAHOC, char tam[])
{
	int key, vitri = 0, x = 88 , y = 22, check_trung;
	PTRLOP p;
	LopHoc lop;	lop.Idlop[0] = NULL;	lop.Namelop[0] = NULL;	lop.Idkhoa[0] = NULL;	lop.Idkhoahoc[0] = NULL;
	
THONGTIN:
	Khung_DKKHOAHOC(); gotoxy(x,y);
	p = Search_IDLop(DSLOP, tam);
	strcpy(lop.Idlop, p->data.Idlop);
	strcpy(lop.Namelop, p->data.Namelop);
	strcpy(lop.Idkhoa, p->data.Idkhoa);
	gotoxy(67,9); cout << "DANG KY KHOA HOC CHO LOP " << tam;
	gotoxy(88, 13); cout << lop.Idlop;
	gotoxy(88, 16); cout << lop.Namelop;
	gotoxy(88, 19); cout << lop.Idkhoa;
	gotoxy(88,22);
	goto NHAPKHOAHOC;
NHAPKHOAHOC:
	while(1)
	{
		
		Yescursortype();
		key = GetKey();
		if(key == F1){
			goto DSKHOAHOC;
		}
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z') ) && (vitri < 11))
		{
			lop.Idkhoahoc[vitri] = char(key);
			lop.Idkhoahoc[vitri] = toupper(lop.Idkhoahoc[vitri]);
			cout << lop.Idkhoahoc[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoxy(88 + vitri, y);
			cout << " ";
			gotoxy(88 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			lop.Idkhoahoc[vitri] = '\0';
			TextColor(48);
			gotoxy(79, 27 ); cout << "             ";
			gotoxy(79, 28 ); cout << "      HUY     ";
			gotoxy(79, 29 ); cout << "             ";
			gotoxy(79,27);
			cout << char(218) <<setw(13) << setfill(char(196))<<char(196) << char(191);
			gotoxy(79,28);
			cout << char(179);
			gotoxy(93,28);
			cout << char(179);
			gotoxy(79,29);
			cout << char(192) << setw(14) << setfill(char(196)) << char(217);
			TextColor(128);
			gotoxy(107, 27 ); cout << "             ";
			gotoxy(107, 28 ); cout << "    DANG KY   ";
			gotoxy(107, 29 ); cout << "             ";
			gotoxy(107,27);
			cout << char(218) <<setw(13) << setfill(char(196))<<char(196) << char(191);
			gotoxy(107,28);
			cout << char(179);
			gotoxy(121,28);
			cout << char(179);
			gotoxy(107,29);
			cout << char(192) << setw(14) << setfill(char(196)) << char(217);
			gotoxy(114,28);
			goto DANGKY;
			
		}
		
	}

DANGKY:
	Nocursortype();
	while(1)
	{
		key = GetKey();
		if(key == UP){
			
			TextColor(48);
			gotoxy(79, 27 ); cout << "             ";
			gotoxy(79, 28 ); cout << "      HUY     ";
			gotoxy(79, 29 ); cout << "             ";
			gotoxy(79,27);
			cout << char(218) <<setw(13) << setfill(char(196))<<char(196) << char(191);
			gotoxy(79,28);
			cout << char(179);
			gotoxy(93,28);
			cout << char(179);
			gotoxy(79,29);
			cout << char(192) << setw(14) << setfill(char(196)) << char(217);
			TextColor(48);
			gotoxy(107, 27 ); cout << "             ";
			gotoxy(107, 28 ); cout << "    DANG KY   ";
			gotoxy(107, 29 ); cout << "             ";
			gotoxy(107,27);
			cout << char(218) <<setw(13) << setfill(char(196))<<char(196) << char(191);
			gotoxy(107,28);
			cout << char(179);
			gotoxy(121,28);
			cout << char(179);
			gotoxy(107,29);
			cout << char(192) << setw(14) << setfill(char(196)) << char(217);
			vitri = strlen(lop.Idkhoahoc);
			gotoxy(88 + vitri, 22);
			goto NHAPKHOAHOC;
		}
		if((key == LEFT) || (key == RIGHT))
		{
			TextColor(128);
			gotoxy(79, 27 ); cout << "             ";
			gotoxy(79, 28 ); cout << "      HUY     ";
			gotoxy(79, 29 ); cout << "             ";
			gotoxy(79,27);
			cout << char(218) <<setw(13) << setfill(char(196))<<char(196) << char(191);
			gotoxy(79,28);
			cout << char(179);
			gotoxy(93,28);
			cout << char(179);
			gotoxy(79,29);
			cout << char(192) << setw(14) << setfill(char(196)) << char(217);
			TextColor(48);
			gotoxy(107, 27 ); cout << "             ";
			gotoxy(107, 28 ); cout << "    DANG KY   ";
			gotoxy(107, 29 ); cout << "             ";
			gotoxy(107,27);
			cout << char(218) <<setw(13) << setfill(char(196))<<char(196) << char(191);
			gotoxy(107,28);
			cout << char(179);
			gotoxy(121,28);
			cout << char(179);
			gotoxy(107,29);
			cout << char(192) << setw(14) << setfill(char(196)) << char(217);
			gotoxy(87,28);
			goto HUY;
		}
		if(key == ENTER)
		{
			lop.Idkhoahoc[vitri] = '\0';	//Ngat chuoi~
			check_trung = KTIDKHOAHOC(DSKHOAHOC, lop.Idkhoahoc); //KT trung`. 1: trung, co ton tai 0: ko trung
			if (check_trung == 1)
			{
				gotoxy(81,24);
				p->data = lop;
				TextColor(48);
				GhiChu("Dang Ky Khoa Hoc Thanh Cong! ", 87, 24, 1300);
				GhiFileLop(DSLOP);
				return;
				
			}
			else {
				TextColor(48);
				GhiChu("Ma Khoa Hoc Khong Ton Tai!   ", 87, 24, 700);
				gotoxy(87,24);	
				cout<< "                          ";
				gotoxy(107, 27 ); cout << "             ";
				gotoxy(107, 28 ); cout << "    DANG KY   ";
				gotoxy(107, 29 ); cout << "             ";
				gotoxy(107,27);
				cout << char(218) <<setw(13) << setfill(char(196))<<char(196) << char(191);
				gotoxy(107,28);
				cout << char(179);
				gotoxy(121,28);
				cout << char(179);
				gotoxy(107,29);
				cout << char(192) << setw(14) << setfill(char(196)) << char(217);
				gotoxy(88 + vitri, y);goto NHAPKHOAHOC;
			}
		}
		if(key == F1){
			goto DSKHOAHOC;
		}
	}
HUY:
	Nocursortype();
	while(1)
	{
		key = GetKey();
		if(key == UP){
			TextColor(48);
			gotoxy(79, 27 ); cout << "             ";
			gotoxy(79, 28 ); cout << "      HUY     ";
			gotoxy(79, 29 ); cout << "             ";
			gotoxy(79,27);
			cout << char(218) <<setw(13) << setfill(char(196))<<char(196) << char(191);
			gotoxy(79,28);
			cout << char(179);
			gotoxy(93,28);
			cout << char(179);
			gotoxy(79,29);
			cout << char(192) << setw(14) << setfill(char(196)) << char(217);
			TextColor(48);
			gotoxy(107, 27 ); cout << "             ";
			gotoxy(107, 28 ); cout << "    DANG KY   ";
			gotoxy(107, 29 ); cout << "             ";
			gotoxy(107,27);
			cout << char(218) <<setw(13) << setfill(char(196))<<char(196) << char(191);
			gotoxy(107,28);
			cout << char(179);
			gotoxy(121,28);
			cout << char(179);
			gotoxy(107,29);
			cout << char(192) << setw(14) << setfill(char(196)) << char(217);
			vitri = strlen(lop.Idkhoahoc);
			gotoxy(88 + vitri, 22);
			goto NHAPKHOAHOC;
		}
		if((key == LEFT) || (key == RIGHT))
		{
			TextColor(48);
			gotoxy(79, 27 ); cout << "             ";
			gotoxy(79, 28 ); cout << "      HUY     ";
			gotoxy(79, 29 ); cout << "             ";
			gotoxy(79,27);
			cout << char(218) <<setw(13) << setfill(char(196))<<char(196) << char(191);
			gotoxy(79,28);
			cout << char(179);
			gotoxy(93,28);
			cout << char(179);
			gotoxy(79,29);
			cout << char(192) << setw(14) << setfill(char(196)) << char(217);
			TextColor(128);
			gotoxy(107, 27 ); cout << "             ";
			gotoxy(107, 28 ); cout << "    DANG KY   ";
			gotoxy(107, 29 ); cout << "             ";
			gotoxy(107,27);
			cout << char(218) <<setw(13) << setfill(char(196))<<char(196) << char(191);
			gotoxy(107,28);
			cout << char(179);
			gotoxy(121,28);
			cout << char(179);
			gotoxy(107,29);
			cout << char(192) << setw(14) << setfill(char(196)) << char(217);
			gotoxy(114,28);
			goto DANGKY;
		}
		if(key == ENTER)
		{
			return;
		}
		if(key == F1){
			goto DSKHOAHOC;
		}
	}
DSKHOAHOC:
	int  trang = 0, tongtrang = 0;
	int soluongkhoahoc, dem = 0, demdong = 0;
	while (1)
	{
		soluongkhoahoc = DemKhoaHoc(DSKHOAHOC);
		if (soluongkhoahoc == 0)
		{
			GhiChu("Chua co du lieu khoa Hoc", 35, 27, 500);
		}
		else {
			if (soluongkhoahoc < 15)
			{
				tongtrang = 1;
				trang = 0;
			}
			else {
				tongtrang = ((soluongkhoahoc - 1) / 15 + 1);
			}
		}
		KhoaHoc *KH = new KhoaHoc[soluongkhoahoc + 1];
		MangTam_KhoaHoc(DSKHOAHOC, KH, dem);
		Sort_MangKhoaHoc(KH, dem);
		dem = 0; demdong = 0;
		TextColor(14);	XoaMhlop();
		Khung_XemKhoaHocDK();
		for (int i = trang * 15; i < 15 + trang * 15 && i < soluongkhoahoc; i++)
		{
			
			gotoXY(49, 11 + demdong); cout << i+1;
			gotoXY(54, 11 + demdong); cout << KH[i].khoahocID;
			gotoXY(75, 11 + demdong); cout << KH[i].Namekhoahoc;
			gotoXY(116, 11 + demdong); cout << KH[i].thoihan << " THANG";
			demdong++;
		}
		HienThiTrang(trang + 1, tongtrang, 116, 27);
		TextColor(164);
		gotoxy(47,5);
		cout << "                               DANH SACH KHOA HOC                                    ";
		Nocursortype();
		gotoXY(81, 26);
		key = GetKey();
		if ((key == RIGHT || key == DOWN) && trang < tongtrang - 1) { trang++; }
		if ((key == LEFT || key == UP) && trang > 0) { trang--; }
		if (key == ESC) {
		XoaMhlop();
		vitri = 0;
		goto THONGTIN;
		}
		
	}
}
void DangKyKhoaHoc(PTRLOP &DSLOP, PTRKHOAHOC &DSKHOAHOC, PTRKHOA &DSKHOA)
{
	int key, vitri = 0, x = 114, y = 15, check_trung;
	PTRLOP p;
	char tam[11]; //de luu ma lop nhap vao
	LopHoc lop;	lop.Idlop[0] = NULL;	lop.Namelop[0] = NULL;	lop.Idkhoa[0] = NULL;	lop.Idkhoahoc[0] = NULL;
	//dau tien phai tim cai vi tri cua ma lop 
NHAPIDLOP:
	Khung_DK();gotoxy(x, y);
	while (1)
	{
		Yescursortype();
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z') || (key == '-')) && (vitri < 11))
		{
			lop.Idlop[vitri] = char(key);
			lop.Idlop[vitri] = toupper(lop.Idlop[vitri]);
			cout << lop.Idlop[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoxy(114 + vitri, y);
			cout << " ";
			gotoxy(114 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			
			lop.Idlop[vitri] = '\0';	//Ngat chuoi~
			strcpy(tam, lop.Idlop);
			check_trung = KTIDLOP(DSLOP, lop.Idlop); //KT trung`. 1: trung, co ton tai 0: ko trung
			if (check_trung == 1)
			{
				bool check = KTSV_LOP(lop.Idlop);
				p = Search_IDLop(DSLOP, lop.Idlop);
				strcpy(lop.Idkhoahoc, p->data.Idkhoahoc);
				if(strcmp(lop.Idkhoahoc,"") == 0 && check == true){
					BangDKKH(DSLOP, DSKHOAHOC, tam);
					return;
				}
				else{
					GhiChu("Lop Da Co Khoa Hoc/ Chua Co Sinh Vien!", 83, 17, 1200);	gotoxy(114 + vitri, y);	
				}
			}
			else {
					GhiChu("Ma Lop Hoc Khong Ton Tai!             ", 83, 17, 1200);	gotoxy(114 + vitri, y);
			}
		}
		if (key == F1){
			goto DSLOP;
		}		
		if (key == ESC) { return; }
	}
DSLOP:
	int  trang = 0, tongtrang = 0;
	int soluonglop, dem = 0, demdong = 0;
	while (1)
	{
		soluonglop = DemLopHoc(DSLOP);
		if (soluonglop == 0)
		{
			GhiChu("Chua co du lieu Lop Hoc", 35, 27, 500);
		}
		else {
			if (soluonglop < 15)
			{
				tongtrang = 1;
				trang = 0;
			}
			else {
				tongtrang = ((soluonglop - 1) / 15 + 1);
			}
		}
		LopHoc *LOP = new LopHoc[soluonglop + 1];
		MangTam_Lop(DSLOP, LOP, dem); //Do Cay Nhi Phan ra Mang?
		Sort_MangLop(LOP, dem);
		dem = 0; demdong = 0;
		TextColor(14);	XoaMhlop();
		Khung_XemLopDK();
		for (int i = trang * 15; i < 15 + trang * 15 && i < soluonglop; i++)
		{
			
			gotoxy(49, 11 + demdong); cout << i+1;
			gotoxy(54, 11 + demdong); cout << LOP[i].Idlop;
			gotoxy(75, 11 + demdong); cout << LOP[i].Namelop;
			gotoxy(116, 11 + demdong); cout << LOP[i].Idkhoa;
			gotoxy(135, 11 + demdong); cout << LOP[i].Idkhoahoc;
			demdong++;
		}
		HienThiTrang(trang + 1, tongtrang, 140, 27);
		TextColor(164);
		gotoxy(47,5);
		cout << "                                           DANH SACH LOP                                                     ";
		Nocursortype();
		gotoxy(81, 26);
		key = GetKey();
		if ((key == RIGHT || key == DOWN) && trang < tongtrang - 1) { trang++; }
		if ((key == LEFT || key == UP) && trang > 0) { trang--; }
		
		if (key == ESC) {
		XoaMhlop();
		vitri = 0;
		goto NHAPIDLOP;
		}
				
		
	}
}
void DSLopTheoKhoa(PTRLOP &DSLOP, char tam[])
{
	int key;
	int  STT=0,trang = 0, tongtrang = 0;
	int soluonglop, dem = 0, demdong = 0;
	while (1)
	{
		soluonglop = DemLopHoc(DSLOP);
		LopHoc *LOP = new LopHoc[soluonglop + 1];
		MangTam_Lop(DSLOP, LOP, dem); //Do Cay Nhi Phan ra Mang?
		Sort_MangLop(LOP, soluonglop);
		dem = 0; demdong = 0;
		TextColor(14);	XoaMhlop();
		Khung_XemLopTheoKhoa();
		for (int i = 0; i < soluonglop; i++)
		{
			if(strcmp(LOP[i].Idkhoa,tam) == 0){
				
				gotoxy(49, 11 + demdong); cout << LOP[i].Idlop;
				gotoxy(75, 11 + demdong); cout << LOP[i].Namelop;
				gotoxy(116, 11 + demdong); cout << LOP[i].Idkhoa;
				gotoxy(135, 11 + demdong); cout << LOP[i].Idkhoahoc;
				demdong++;
				
			}
			
		}
		HienThiTrang(trang+1, tongtrang+1, 140, 39);
		TextColor(164);
		gotoxy(47,5);
		cout << "                                          DANH SACH LOP THEO KHOA                                            ";
		Nocursortype();
		gotoxy(81, 26);
		key = GetKey();
		if ((key == RIGHT || key == DOWN) && trang < tongtrang - 1) { trang++; }
		if ((key == LEFT || key == UP) && trang > 0) { trang--; }
		if (key == ESC) {return;}
		
		
	}
}
void XemLopTheoIDKhoa(PTRLOP &DSLOP, PTRKHOA &DSKHOA)
{
	int key, vitri = 0, x = 110, y = 15, check_trung;
	PTRLOP p;
	char tam[3]; //de luu ma khoa nhap vao
	Khoa k; k.Idkhoa[0] = NULL;
	Khung_XLTK();gotoxy(x, y);
	//dau tien phai tim cai vi tri cua ma khoa da
TIMIDKHOA:	
	while (1)
	{
		
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z') || (key == '-')) && (vitri < 11))
		{
			k.Idkhoa[vitri] = char(key);
			k.Idkhoa[vitri] = toupper(k.Idkhoa[vitri]);
			cout << k.Idkhoa[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoxy(110 + vitri, y);
			cout << " ";
			gotoxy(110 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			
			k.Idkhoa[vitri] = '\0';	//Ngat chuoi~
			strcpy(tam, k.Idkhoa);
			check_trung = CHECKKHOA(DSKHOA, k.Idkhoa); //KT trung`. 1: trung, co ton tai 0: ko trung
			if (check_trung == 1)
			{
				DSLopTheoKhoa(DSLOP, tam);				
			}
			else {
				GhiChu("Ma Khoa Khong Ton Tai/Khong Co Lop Thuoc Khoa", 81, 17, 500);	gotoxy(110 + vitri, y);
				}
		}
		if (key == ESC || key == F2) { return; }
		}
}

//--xem danh sach lop
void XemKhoa(PTRKHOA &DSKHOA, PTRLOP &DSLOP) { 
	int key;
	int  trang = 0, tongtrang = 0;
	int soluongkhoa, dem = 0, demdong = 0;
	while (1)
	{
		soluongkhoa = DemKhoa(DSKHOA);
		if (soluongkhoa == 0)
		{
			GhiChu("Chua co du lieu Khoa", 35, 27, 500);
		}
		else {
			if (soluongkhoa < 15)
			{
				tongtrang = 1;
				trang = 0;
			}
			else {
				tongtrang = ((soluongkhoa - 1) / 15 + 1);
			}
		}
		Khoa *KHOA = new Khoa[soluongkhoa + 1];
		MangTam_Khoa(DSKHOA, KHOA, dem); //Do Cay Nhi Phan ra Mang?
		Sort_MangKhoa(KHOA, soluongkhoa);
		dem = 0; demdong = 0;
		TextColor(14);	XoaMhlop();
		Khung_XemKhoa();
		for (int i = trang * 15; i < 15 + trang * 15 && i < soluongkhoa; i++)
		{
			
			gotoxy(79, 11 + demdong); cout << i+1;
			gotoxy(84, 11 + demdong); cout << KHOA[i].Idkhoa;
			gotoxy(105, 11 + demdong); cout << KHOA[i].NameKhoa;
			demdong++;
		}
		HienThiTrang(trang + 1, tongtrang, 130, 27);
		TextColor(164);
		gotoxy(77,5);
		cout << "                           DANH SACH KHOA                            ";
		Nocursortype();
		gotoxy(81, 26);
		key = GetKey();
		if ((key == RIGHT || key == DOWN) && trang < tongtrang - 1) { trang++; }
		if ((key == LEFT )|| key == UP && trang > 0) { trang--; } 
		if(key == F1)
		{
			XoaMhlop();
			Yescursortype();
			XemLopTheoIDKhoa(DSLOP, DSKHOA);
		}
		if (key == ESC) {return;}
	}
}

void MenuKT(PTRLOP &DSLOP, PTRKHOAHOC &DSKHOAHOC, PTRKHOA &DSKHOA, bool phanquyen)
{
	
	
	while (1)
	{
		
		Nocursortype();
		system("cls");
		system("color 71");
		for (int i = 0; i < 4 ; i++)
		{
			if (i == 0) { TextColor(180); }
			else { TextColor(240); }
			gotoxy(5, 4 + i * 4); cout << "                              ";
			gotoxy(5, 5 + i * 4); cout << MENULOP[i];
			gotoxy(5, 6 + i * 4); cout << "                              ";
		}
		
		gotoxy(24, 7);
		int chon = MenuChaLop(phanquyen);
		switch (chon)
		{
			case 1:
			{
				XemKhoa(DSKHOA, DSLOP);
				break;
			}
			case 2:
			{
				XemLopHoc(DSLOP, DSKHOA, phanquyen);
				break;	
			}
			case 3:
			{
				
				if(phanquyen == true){
					system("cls");
					DangKyKhoaHoc(DSLOP, DSKHOAHOC, DSKHOA);
					break;
				}
				else{
					Beep(1000,700);
					GhiChu("SINH VIEN KHONG DUOC PHEP CHINH SUA",2,44,1500);
					break;	
				}
			}
			case 4:
			{
				return; break;
			}
			
		}
	}
}

int sizeKhoa(PTRKHOA DSKHOA) {
	if (DSKHOA != NULL)
	{
		return (sizeKhoa(DSKHOA->left) + sizeKhoa(DSKHOA->right) + 1);
	}
	else return 0;
}



