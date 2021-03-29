#include "dohoa.h"
struct KhoaHoc {
	char khoahocID[10]; 
	char Namekhoahoc[31]; 
	char thoihan[7];
};
struct dskhoahoc {
	KhoaHoc data;
	dskhoahoc *left;
	dskhoahoc *right;
};
struct ChiTietKhoaHoc{
	char khoahocID[10];
	char monhocID[10];
	
};
typedef dskhoahoc *PTRKHOAHOC;
bool EmptyDSKHOAHOC(PTRKHOAHOC DSKHOAHOC) { 
	if (DSKHOAHOC == NULL) return true;
	return false;
}
void InsertNode_KhoaHoc(PTRKHOAHOC &DSKHOAHOC, KhoaHoc kh) {
	if (EmptyDSKHOAHOC(DSKHOAHOC)) {
		PTRKHOAHOC p = new dskhoahoc;
		p->data = kh;
		p->left = p->right = NULL;
		DSKHOAHOC = p;
		return;
	}
	else {
		if (0 < (strcmp(DSKHOAHOC->data.khoahocID,kh.khoahocID))) {
			InsertNode_KhoaHoc(DSKHOAHOC->left, kh);
		}
		else {
			InsertNode_KhoaHoc(DSKHOAHOC->right, kh);
		}
	}
}
struct MonHoc {
	char monhocID[10]; 
	char Namemonhoc[31]; 
	
};
struct dsmonhoc {
	MonHoc data;
	dsmonhoc *left;
	dsmonhoc *right;
};
typedef dsmonhoc *PTRMONHOC;
bool EmptyDSMONHOC(PTRMONHOC DSMONHOC) { 
	if (DSMONHOC == NULL) return true;
	return false;
}
void InsertNode_MonHoc(PTRMONHOC &DSMONHOC, MonHoc mh) {
	if (EmptyDSMONHOC(DSMONHOC)) {
		PTRMONHOC p = new dsmonhoc;
		p->data = mh;
		p->left = p->right = NULL;
		DSMONHOC = p;
		return;
	}
	else {
		if (0 < (strcmp(DSMONHOC->data.monhocID,mh.monhocID))) {
			InsertNode_MonHoc(DSMONHOC->left, mh);
		}
		else {
			InsertNode_MonHoc(DSMONHOC->right, mh);
		}
	}
}
void GhiChu(char c[], int x, int y, int sleep)
{

	gotoxy(x, y);
	cout << c;
	Sleep(sleep);
	
}

void DocFileKhoaHoc(PTRKHOAHOC &DSKHOAHOC) {
	ifstream infile;
	string data;
	infile.open("DSKHOAHOC.txt", ios::in);
	if (!infile) {return; } //Khong tim thay file
	while (infile.good())
	{
		KhoaHoc kh;
		getline(infile, data);
		if (data.size() == 0) { break; } //Da co file nhung chua co du lieu
		strcpy(kh.khoahocID, data.c_str());
		getline(infile, data);		strcpy(kh.Namekhoahoc, data.c_str());
		getline(infile, data);		strcpy(kh.thoihan, data.c_str());
		InsertNode_KhoaHoc(DSKHOAHOC, kh);
	}
	infile.close();
}
void DocFileMonHoc(PTRMONHOC &DSMONHOC) {
	ifstream infile;
	string data;
	infile.open("DSMONHOC.txt", ios::in);
	if (!infile) {  return; } //Khong tim thay file
	while (infile.good())
	{
		MonHoc mh;
		getline(infile, data);
		if (data.size() == 0) { break; } //Da co file nhung chua co du lieu
		strcpy(mh.monhocID, data.c_str());
		getline(infile, data);		strcpy(mh.Namemonhoc, data.c_str());
		InsertNode_MonHoc(DSMONHOC, mh);
	}
	infile.close();
}
void GhiFile_LNR_KH(ofstream &file, PTRKHOAHOC DSKHOAHOC)
{
	if (DSKHOAHOC != NULL)
	{
		GhiFile_LNR_KH(file, DSKHOAHOC->left);
		file << DSKHOAHOC->data.khoahocID << endl
			<< DSKHOAHOC->data.Namekhoahoc << endl
			<< DSKHOAHOC->data.thoihan << endl;
		GhiFile_LNR_KH(file, DSKHOAHOC->right);
	}
}
//Luu file
void GhiFileKhoaHoc(PTRKHOAHOC DSKHOAHOC) {
	ofstream outfile;
	outfile.open("DSKHOAHOC.txt", ios::out);
	GhiFile_LNR_KH(outfile, DSKHOAHOC);
	outfile.close();
}
void GhiFile_LNR_MH(ofstream &file, PTRMONHOC DSMONHOC)
{
	if (DSMONHOC != NULL)
	{
		GhiFile_LNR_MH(file, DSMONHOC->left);
		file << DSMONHOC->data.monhocID << endl
			<< DSMONHOC->data.Namemonhoc << endl;
		GhiFile_LNR_MH(file, DSMONHOC->right);
	}
}
//Luu file
void GhiFileMonHoc(PTRMONHOC DSMONHOC) {
	ofstream outfile;
	outfile.open("DSMONHOC.txt", ios::out);
	GhiFile_LNR_MH(outfile, DSMONHOC);
	outfile.close();
}
int KTIDKHOAHOC(PTRKHOAHOC DSKHOAHOC, char kh[]) {
	if (DSKHOAHOC == NULL)
	{
		return 0;
	}
	else {
		if (strcmp(DSKHOAHOC->data.khoahocID, kh) == 0)
		{
			return 1;
		}
		else if (strcmp(DSKHOAHOC->data.khoahocID, kh) >0)
		{
			KTIDKHOAHOC(DSKHOAHOC->left, kh);
		}
		else {
			KTIDKHOAHOC(DSKHOAHOC->right, kh);
		}
	}
}
int KTIDMONHOC(PTRMONHOC DSMONHOC, char mh[]) {
	if (DSMONHOC == NULL)
	{
		return 0;
	}
	else {
		if (strcmp(DSMONHOC->data.monhocID, mh) == 0)
		{
			return 1;
		}
		else if (strcmp(DSMONHOC->data.monhocID, mh) >0)
		{
			KTIDMONHOC(DSMONHOC->left, mh);
		}
		else {
			KTIDMONHOC(DSMONHOC->right, mh);
		}
	}
}
PTRKHOAHOC Search_IDKhoaHoc(PTRKHOAHOC &DSKHOAHOC, char kh[]) {
	if (EmptyDSKHOAHOC(DSKHOAHOC)) { return NULL; }
	else {
		if (0 == strcmp(DSKHOAHOC->data.khoahocID, kh)) {
			return DSKHOAHOC;
		}
		else if (0< strcmp(DSKHOAHOC->data.khoahocID, kh)) {
			Search_IDKhoaHoc(DSKHOAHOC->left, kh);
		}
		else {
			Search_IDKhoaHoc(DSKHOAHOC->right, kh);
		}
	}
}
PTRMONHOC Search_IDMonHoc(PTRMONHOC &DSMONHOC, char mh[]) {
	if (EmptyDSMONHOC(DSMONHOC)) { return NULL; }
	else {
		if (0 == strcmp(DSMONHOC->data.monhocID, mh)) {
			return DSMONHOC;
		}
		else if (0< strcmp(DSMONHOC->data.monhocID, mh)) {
			Search_IDMonHoc(DSMONHOC->left, mh);
		}
		else {
			Search_IDMonHoc(DSMONHOC->right, mh);
		}
	}
}
int DemKhoaHoc(PTRKHOAHOC DSKHOAHOC) {
	if (DSKHOAHOC != NULL)
	{
		return (DemKhoaHoc(DSKHOAHOC->left) + DemKhoaHoc(DSKHOAHOC->right) + 1);
	}
	else return 0;
}
int DemMonHoc(PTRMONHOC DSMONHOC) {
	if (DSMONHOC != NULL)
	{
		return (DemMonHoc(DSMONHOC->left) + DemMonHoc(DSMONHOC->right) + 1);
	}
	else return 0;
}

void MangTam_KhoaHoc(PTRKHOAHOC DSKHOAHOC, KhoaHoc kh[], int &dem) {
	
	if (DSKHOAHOC != NULL)
	{
		MangTam_KhoaHoc(DSKHOAHOC->left, kh, dem);
		kh[dem++] = DSKHOAHOC->data;
		MangTam_KhoaHoc(DSKHOAHOC->right, kh, dem);
	}
}
void Sort_MangKhoaHoc(KhoaHoc a[], int n) { 
	KhoaHoc min;
	int vitrimin;
	int i, j;
	for (i = 0; i < n - 1; i++) {
		min = a[i];
		vitrimin = i;
		for (j = i + 1; j < n; j++) {
			if (strcmp(min.Namekhoahoc, a[j].Namekhoahoc) >0)
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
void MangTam_MonHoc(PTRMONHOC DSMONHOC, MonHoc mh[], int &dem) {
	
	if (DSMONHOC != NULL)
	{
		MangTam_MonHoc(DSMONHOC->left, mh, dem);
		mh[dem++] = DSMONHOC->data;
		MangTam_MonHoc(DSMONHOC->right, mh, dem);
	}
}
void Sort_MangMonHoc(MonHoc a[], int n) {
	MonHoc min;
	int vitrimin;
	int i, j;
	for (i = 0; i < n - 1; i++) {
		min = a[i];
		vitrimin = i;
		for (j = i + 1; j < n; j++) {
			if (strcmp(min.Namemonhoc, a[j].Namemonhoc) >0)
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

//lay ve list du lieu
void ToArrK(ChiTietKhoaHoc ctkh[],int &count){
	ChiTietKhoaHoc ct;
	
	fstream fh("CHI_TIET.IO",ios::in|ios::binary );
	if(fh.read(reinterpret_cast<char *>(&ct), sizeof(ct))){
		fh.close();
		fstream fk("CHI_TIET.IO",ios::in|ios::binary);
		while(fk.read(reinterpret_cast<char *>(&ct), sizeof(ct))){
			strcpy(ctkh[count].khoahocID,ct.khoahocID);
			strcpy(ctkh[count].monhocID,ct.monhocID);
			count++;
		}
		fk.close();
	}
			
	
}//
void demMHAddKhoa(int &dem){
	ChiTietKhoaHoc ct;	

	fstream fh("CHI_TIET.IO",ios::in|ios::binary );
	if(fh.read(reinterpret_cast<char *>(&ct), sizeof(ct))){
		fh.close();
		fstream fk("CHI_TIET.IO",ios::in|ios::binary);
		while(fk.read(reinterpret_cast<char *>(&ct), sizeof(ct))){
			dem++;	
		}
		fk.close();
		}

}
// ghi file chi tiet nha
bool ghiFileChiTiet(ChiTietKhoaHoc ct){
	
	fstream fh("CHI_TIET.IO",ios::app | ios::binary );

	if(!fh){
		return false;
	}
	else{
		fh.write(reinterpret_cast<char *>(&ct), sizeof(ct));
}
	fh.close();

		return true;

}
int check_ctkh(char kh[]){
	
	ChiTietKhoaHoc ctkh[100]; int count;
	ToArrK(ctkh, count);
	for(int i=0;i<count;i++)
	{
		if(strcmp(kh,ctkh[i].khoahocID) == 0)
		{
			return 1;
		}
	}
	return 0;
}
int check_ctmh(char mh[]){
	
	ChiTietKhoaHoc ctkh[100]; int count;
	ToArrK(ctkh, count);
	for(int i=0;i<count;i++)
	{
		if(strcmp(mh,ctkh[i].monhocID) == 0)
		{
			return 1;
		}
	}
	return 0;
}
void ThemKhoaHoc(PTRKHOAHOC &DSKHOAHOC)
{
	
	int key, vitri = 0, x = 72, y = 14, check_trung;
	KhoaHoc kh;	kh.khoahocID[0] = NULL; kh.Namekhoahoc[0] = NULL;	kh.thoihan[0] = NULL;
	gotoXY(x, y);Khung_ThemKhoaHoc();
	gotoxy(97,9);
	cout << "THEM KHOA HOC MOI";
IDKHOAHOC:
	while (1)
	{
		gotoXY(66, 19);
		cout << "Ki tu: (A-Z) & (0-9). Toi da: 10";
		gotoXY(72 + vitri, y);
		key = GetKey();
		if (((key >= 'A' && key <= 'Z')  || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z') || (key == '-')) && (vitri < 11))
		{
			kh.khoahocID[vitri] = char(key);
			kh.khoahocID[vitri] = toupper(kh.khoahocID[vitri]);
			cout << kh.khoahocID[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(72 + vitri, y);
			cout << " ";
			gotoXY(72 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			kh.khoahocID[vitri] = '\0';
			check_trung = KTIDKHOAHOC(DSKHOAHOC, kh.khoahocID);
			if (check_trung == 1) {
				gotoXY(66, 16);
				cout << "Trung Ma Khoa Hoc. Nhap Lai!";
				Sleep(500);
				continue;
			}
			vitri = strlen(kh.Namekhoahoc);
			gotoXY(90 + vitri, y);
			goto NAMEKHOAHOC;
		}
		if (key == RIGHT)
		{
			kh.khoahocID[vitri] = '\0';
			check_trung = KTIDKHOAHOC(DSKHOAHOC, kh.khoahocID);
			if (check_trung == 1) {
				gotoXY(66, 16);
				cout << "Trung Ma Khoa Hoc. Nhap Lai!";
				Sleep(500); continue;
			}
			vitri = strlen(kh.Namekhoahoc);
			gotoXY(90 + vitri, y);
			goto NAMEKHOAHOC;
		}
		if (key == ESC || key == F1) { return; }
	}
NAMEKHOAHOC:
	while (1)
	{
		gotoXY(66,19);
		   cout << "Ki tu: (A-Z) & (0-9). Toi da: 30";
		  
		if (kh.khoahocID[0] == '\0')
		{
			GhiChu("Ban Chua Nhap Ma Khoa Hoc!", 66, 16, 700);
			gotoXY(72, y);
			goto IDKHOAHOC;
		}
		gotoxy(90+vitri, y);
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 30))
		{
			kh.Namekhoahoc[vitri] = char(key);
			kh.Namekhoahoc[vitri] = toupper(kh.Namekhoahoc[vitri]);
			cout << kh.Namekhoahoc[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(90 + vitri, y);
			cout << " ";
			gotoXY(90 + vitri, y);
		}
		if (key == SPACE && kh.Namekhoahoc[vitri - 1] != ' ' && vitri > 0 && vitri < 30) // ko cho 2 khoang trang && vitri = 0
		{
			gotoXY(90 + vitri, y);
			cout << " ";
			kh.Namekhoahoc[vitri] = ' ';
			vitri++;
		}
		if (key == ENTER && vitri != 0)
		{
			if (kh.Namekhoahoc[vitri - 1] == ' ') { vitri--; } //Kiem tra ki tu cuoi cung la khoang trang thi xoa khoang trang
			kh.Namekhoahoc[vitri] = '\0';
			vitri = strlen(kh.thoihan);
			gotoXY(127 + vitri, y);
			goto THOIHAN;
		}
		if (key == LEFT)
		{
			kh.Namekhoahoc[vitri] = '\0';
			vitri = strlen(kh.khoahocID);
			gotoXY(72 + vitri, y);
			goto IDKHOAHOC;
		}
		if (key == RIGHT)
		{
			if (kh.Namekhoahoc[vitri - 1] == ' ') { vitri--; } //Kiem tra ki tu cuoi cung la khoang trang thi xoa khoang trang
			kh.Namekhoahoc[vitri] = '\0';
			vitri = strlen(kh.thoihan);
			gotoXY(127 + vitri, y);
			goto THOIHAN;
		}
		if (key == ESC || key == F1) { return; }
	}
THOIHAN:
	while (1)
	{
		gotoXY(66, 19);
		cout << "Ki tu:(0-9). Toi da: 2          ";
		// Ghi chú
		if (kh.Namekhoahoc[0] == '\0')
		{
			GhiChu("Ban Chua Nhap Ten Khoa Hoc!", 66, 16, 700);
			gotoXY(90 , y);
			goto NAMEKHOAHOC;
		}
		gotoxy(127 + vitri,y);
		key = GetKey();
		if (((key <= '9' && key >= '0')) && (vitri < 2))
		{
			kh.thoihan[vitri] = char(key);
			kh.thoihan[vitri] = toupper(kh.thoihan[vitri]);
			cout << kh.thoihan[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(127 + vitri, y);
			cout << " ";
			gotoXY(127 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			kh.thoihan[vitri] = '\0';
			InsertNode_KhoaHoc(DSKHOAHOC, kh);
			gotoxy(66,16);
			cout << "                            ";
			gotoxy(66,9);
			GhiChu("Them Thanh Cong", 66, 9, 1000);
			GhiFileKhoaHoc(DSKHOAHOC);
			return;
		}
		
		if (key == LEFT)
		{
			kh.thoihan[vitri] = '\0';
			vitri = strlen(kh.Namekhoahoc);
			gotoXY(90 + vitri, y);
			goto NAMEKHOAHOC;
		}
		if (key == ESC || key == F1) { return; }
	}
}

void SuaKhoaHoc(PTRKHOAHOC &DSKHOAHOC)
{
	int key, vitri = 0, x = 110, y = 15, check_trung;
	PTRKHOAHOC p;
	ChiTietKhoaHoc ctkh[100]; int count;
	KhoaHoc kh;	kh.khoahocID[0] = NULL; kh.Namekhoahoc[0] = NULL;	kh.thoihan[0] = NULL;
	Khung_SuaKhoaHoc();gotoXY(x, y);
	
TIMIDKHOAHOC:	
	while (1)
	{
		
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z') || (key == '-')) && (vitri < 11))
		{
			kh.khoahocID[vitri] = char(key);
			kh.khoahocID[vitri] = toupper(kh.khoahocID[vitri]);
			cout << kh.khoahocID[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(110 + vitri, y);
			cout << " ";
			gotoXY(110 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			
			kh.khoahocID[vitri] = '\0';
			ToArrK(ctkh,count);
			check_trung = KTIDKHOAHOC(DSKHOAHOC, kh.khoahocID); 
			if (check_trung == 1)
			{
				for(int i = 0; i< count; i++)
				{
					if(strcmp(kh.khoahocID, ctkh[i].khoahocID) == 0)
					{
						GhiChu("Khoa Hoc Da Dang Ky Mon!", 81, 19, 500);	gotoXY(110 + vitri, y); goto TIMIDKHOAHOC ;break;
					}
					
				}
				system("cls");
				vitri = 0;
				p = Search_IDKhoaHoc(DSKHOAHOC, kh.khoahocID);
				Khung_ThemKhoaHoc();
				gotoxy(94,9);
				cout << "THONG TIN KHOA HOC CAN SUA";
				x = 72, y = 14;
				gotoXY(x, y);
				strcpy(kh.khoahocID, p->data.khoahocID);
				strcpy(kh.Namekhoahoc, p->data.Namekhoahoc);
				strcpy(kh.thoihan, p->data.thoihan);
				gotoXY(72, y); cout << kh.khoahocID;
				gotoXY(90, y); cout << kh.Namekhoahoc;
				gotoXY(127, y); cout << kh.thoihan;
				vitri = strlen(kh.khoahocID);
				goto IDKHOAHOC;
				break;
			}
			else {
				GhiChu("Ma Khoa Hoc Khong Ton Tai!", 81, 19, 500);	gotoXY(110 + vitri, y);
			}
		}
		if (key == ESC || key == F2) { return; }
	}
IDKHOAHOC:
	while (1)
	{
		gotoXY(66, 19);
		cout << "Ki tu: (A-Z) & (0-9). Toi da: 10";
		gotoXY(72 + vitri, y);
		key = GetKey();
		if (((key >= 'A' && key <= 'Z')  || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z') || (key == '-')) && (vitri < 11))
		{
			kh.khoahocID[vitri] = char(key);
			kh.khoahocID[vitri] = toupper(kh.khoahocID[vitri]);
			cout << kh.khoahocID[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(72 + vitri, y);
			cout << " ";
			gotoXY(72 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			kh.khoahocID[vitri] = '\0';
			check_trung = KTIDKHOAHOC(DSKHOAHOC, kh.khoahocID);
			if (check_trung == 1) {
				gotoXY(66, 16);
				cout << "Trung Ma Khoa Hoc. Nhap Lai!";
				Sleep(500);
				continue;
			}
			vitri = strlen(kh.Namekhoahoc);
			gotoXY(90 + vitri, y);
			goto NAMEKHOAHOC;
		}
		if (key == RIGHT)
		{
			kh.khoahocID[vitri] = '\0';
			check_trung = KTIDKHOAHOC(DSKHOAHOC, kh.khoahocID);
			if (check_trung == 1) {
				gotoXY(66, 16);
				cout << "Trung Ma Khoa Hoc. Nhap Lai!";
				Sleep(500); continue;
			}
			vitri = strlen(kh.Namekhoahoc);
			gotoXY(90 + vitri, y);
			goto NAMEKHOAHOC;
		}
		if (key == ESC || key == F1) { return; }
	}
NAMEKHOAHOC:
	while (1)
	{
		gotoXY(66,19);
		   cout << "Ki tu: (A-Z) & (0-9). Toi da: 30";
		  
		if (kh.khoahocID[0] == '\0')
		{
			GhiChu("Ban Chua Nhap Ma Khoa Hoc!", 66, 16, 700);
			gotoXY(72, y);
			goto IDKHOAHOC;
		}
		gotoxy(90+vitri, y);
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 30))
		{
			kh.Namekhoahoc[vitri] = char(key);
			kh.Namekhoahoc[vitri] = toupper(kh.Namekhoahoc[vitri]);
			cout << kh.Namekhoahoc[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(90 + vitri, y);
			cout << " ";
			gotoXY(90 + vitri, y);
		}
		if (key == SPACE && kh.Namekhoahoc[vitri - 1] != ' ' && vitri > 0 && vitri < 30) // ko cho 2 khoang trang && vitri = 0
		{
			gotoXY(90 + vitri, y);
			cout << " ";
			kh.Namekhoahoc[vitri] = ' ';
			vitri++;
		}
		if (key == ENTER && vitri != 0)
		{
			if (kh.Namekhoahoc[vitri - 1] == ' ') { vitri--; } //Kiem tra ki tu cuoi cung la khoang trang thi xoa khoang trang
			kh.Namekhoahoc[vitri] = '\0';
			vitri = strlen(kh.thoihan);
			gotoXY(127 + vitri, y);
			goto THOIHAN;
		}
		if (key == LEFT)
		{
			kh.Namekhoahoc[vitri] = '\0';
			vitri = strlen(kh.khoahocID);
			gotoXY(72 + vitri, y);
			goto IDKHOAHOC;
		}
		if (key == RIGHT)
		{
			if (kh.Namekhoahoc[vitri - 1] == ' ') { vitri--; } //Kiem tra ki tu cuoi cung la khoang trang thi xoa khoang trang
			kh.Namekhoahoc[vitri] = '\0';
			vitri = strlen(kh.thoihan);
			gotoXY(127 + vitri, y);
			goto THOIHAN;
		}
		if (key == ESC || key == F1) { return; }
	}
THOIHAN:
	while (1)
	{
		gotoXY(66, 19);
		cout << "Ki tu:(0-9). Toi da: 2          ";
		// Ghi chú
		if (kh.Namekhoahoc[0] == '\0')
		{
			GhiChu("Ban Chua Nhap Ten Khoa Hoc!", 66, 16, 700);
			gotoXY(90 , y);
			goto NAMEKHOAHOC;
		}
		gotoxy(127 + vitri,y);
		key = GetKey();
		if (((key <= '9' && key >= '0')) && (vitri < 2))
		{
			kh.thoihan[vitri] = char(key);
			kh.thoihan[vitri] = toupper(kh.thoihan[vitri]);
			cout << kh.thoihan[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(127 + vitri, y);
			cout << " ";
			gotoXY(127 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			kh.thoihan[vitri] = '\0';
			gotoxy(66,9);
			p->data = kh;
			GhiChu("Khoa Hoc Da Duoc Cap Nhat!", 66, 9, 1000);
			GhiFileKhoaHoc(DSKHOAHOC);
			return;
		}
		
		if (key == LEFT)
		{
			kh.thoihan[vitri] = '\0';
			vitri = strlen(kh.Namekhoahoc);
			gotoXY(90 + vitri, y);
			goto NAMEKHOAHOC;
		}
		if (key == ESC || key == F1) { return; }
	}
}
void PhanTuTheMang(PTRKHOAHOC &p, PTRKHOAHOC &q) {
	if (q->left != NULL)
	{
		PhanTuTheMang(p, q->left);
	}
	else {
		p->data = q->data;			
		p = q;						
		q = q->right;				
	}
}
void DeleteNode_KhoaHoc(PTRKHOAHOC &DSKHOAHOC, char c[]) {
	if (DSKHOAHOC == NULL) { return; }
	
	if (strcmp(DSKHOAHOC->data.khoahocID, c) >0)
	{
		DeleteNode_KhoaHoc(DSKHOAHOC->left, c);
	}
	else if (strcmp(DSKHOAHOC->data.khoahocID, c) <0)
	{
		DeleteNode_KhoaHoc(DSKHOAHOC->right, c);
	}
	
	else {
		PTRKHOAHOC p = DSKHOAHOC;		
		if (DSKHOAHOC->left == NULL && DSKHOAHOC->right == NULL)	
		{
			delete DSKHOAHOC; DSKHOAHOC = NULL; return;
		}
		if (DSKHOAHOC->left == NULL && DSKHOAHOC->right != NULL)
		{
			DSKHOAHOC = DSKHOAHOC->right;
		}
		else if (DSKHOAHOC->right == NULL && DSKHOAHOC->left != NULL) 
		{
			DSKHOAHOC = DSKHOAHOC->left;
		}
	
		else {
			PhanTuTheMang(p, DSKHOAHOC->right);
			delete p;
		}
	}
}

void XoaKhoaHoc(PTRKHOAHOC &DSKHOAHOC)
{
	int key, vitri = 0, x = 110, y = 15, check_trung, check_kh;
	PTRKHOAHOC p;
	KhoaHoc kh; kh.khoahocID[0] = NULL;
	Khung_XoaKhoaHoc();gotoXY(x, y);
	 
RESET:	
	while (1)
	{
		
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z') || (key == '-')) && (vitri < 11))
		{
			kh.khoahocID[vitri] = char(key);
			kh.khoahocID[vitri] = toupper(kh.khoahocID[vitri]);
			cout << kh.khoahocID[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(110 + vitri, y);
			cout << " ";
			gotoXY(110 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			
			kh.khoahocID[vitri] = '\0';	//Ngat chuoi~
			check_trung = KTIDKHOAHOC(DSKHOAHOC, kh.khoahocID); //KT trung`. 1: trung, co ton tai 0: ko trung
			check_kh = check_ctkh(kh.khoahocID);
			if (check_trung != 0)
			{
				if(check_kh != 1)
				{
					DeleteNode_KhoaHoc(DSKHOAHOC, kh.khoahocID);
					GhiChu("Xoa Thanh Cong Khoa Hoc!                       ", 81, 17, 1500);
					gotoxy(81,17);
					cout <<"                                               ";
					GhiFileKhoaHoc(DSKHOAHOC);
					return;
				}
				else{
					GhiChu("Khoa Hoc Da Duoc Them Mon Hoc!                 ", 81, 17, 500);	gotoXY(110 + vitri, y);
				}
							
			}
			else {
					GhiChu("Ma Khoa Hoc Khong Ton Tai!                     ", 81, 17, 500);	gotoXY(110 + vitri, y);
			}
		}
		if (key == ESC || key == F2) { return; }
	}
}

void XemKhoaHoc(PTRKHOAHOC &DSKHOAHOC, bool phanquyen) { // PHAN QUYEN: -true: admin -false: sinh vien
	int key;
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
		TextColor(14);	system("cls");
		Khung_XemKhoaHoc();
		for (int i = trang * 15; i < 15 + trang * 15 && i < soluongkhoahoc; i++)
		{
			
			gotoXY(49, 8 + demdong); cout << i+1;
			gotoXY(54, 8 + demdong); cout << KH[i].khoahocID;
			gotoXY(75, 8 + demdong); cout << KH[i].Namekhoahoc;
			gotoXY(116, 8 + demdong); cout << KH[i].thoihan << " THANG";
			demdong++;
		}
		HienThiTrang(trang + 1, tongtrang, 118, 26);
		TextColor(164);
		gotoxy(47,2);
		cout << "                               DANH SACH KHOA HOC                                    ";
		Nocursortype();
		gotoXY(81, 26);
		key = GetKey();
		if ((key == RIGHT || key == DOWN) && trang < tongtrang - 1) { trang++; }
		if ((key == LEFT || key == UP) && trang > 0) { trang--; }
		if((key == F1 || key == F2 || key == F3) && phanquyen == false)
		{
			gotoxy(46,26);
			cout << "SINH VIEN KHONG DUOC QUYEN CHINH SUA";
			Sleep(1000);
			gotoxy(46,26);
			cout << "                                    ";
		}
		if (key == F1 && phanquyen == true)
		{
			system("cls");
			Yescursortype();
			ThemKhoaHoc(DSKHOAHOC);
		}
		if (key == F2 && phanquyen == true)
		{
			system("cls");
			Yescursortype();
			SuaKhoaHoc(DSKHOAHOC);
		}
		if (key == F3 && phanquyen == true){
			system("cls");
			Yescursortype();
			XoaKhoaHoc(DSKHOAHOC);
		}
		if (key == ESC) {return;}
		
		
	}
}
void ThemMonHoc(PTRMONHOC &DSMONHOC)
{
	
	int key, vitri = 0, x = 82, y = 14, check_trung;
	MonHoc mh; mh.monhocID[0] = NULL; mh.Namemonhoc[0] = NULL;
	gotoXY(x, y);Khung_ThemMonHoc();
	gotoxy(97,9);
	cout << "THEM MON HOC MOI";
IDMONHOC:
	while (1)
	{
		gotoXY(66, 19);
		cout << "Ki tu: (A-Z) & (0-9). Toi da: 10";
		gotoXY(82 + vitri, y);
		key = GetKey();
		if (((key >= 'A' && key <= 'Z')  || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z') || (key == '-')) && (vitri < 11))
		{
			mh.monhocID[vitri] = char(key);
			mh.monhocID[vitri] = toupper(mh.monhocID[vitri]);
			cout << mh.monhocID[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(82 + vitri, y);
			cout << " ";
			gotoXY(82 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			mh.monhocID[vitri] = '\0';
			check_trung = KTIDMONHOC(DSMONHOC, mh.monhocID);
			if (check_trung == 1) {
				gotoXY(66, 16);
				cout << "Trung Ma Mon Hoc. Nhap Lai!";
				Sleep(500);
				continue;
			}
			vitri = strlen(mh.Namemonhoc);
			gotoXY(100 + vitri, y);
			goto NAMEMONHOC;
		}
		if (key == RIGHT)
		{
			mh.monhocID[vitri] = '\0';
			check_trung = KTIDMONHOC(DSMONHOC, mh.monhocID);
			if (check_trung == 1) {
				gotoXY(66, 16);
				cout << "Trung Ma Mon Hoc. Nhap Lai!";
				Sleep(500); continue;
			}
			vitri = strlen(mh.Namemonhoc);
			gotoXY(100 + vitri, y);
			goto NAMEMONHOC;
		}
		if (key == ESC || key == F1) { return; }
	}
NAMEMONHOC:
	while (1)
	{
		gotoXY(66,19);
		   cout << "Ki tu: (A-Z) & (0-9). Toi da: 30";
		  
		if (mh.monhocID[0] == '\0')
		{
			GhiChu("Ban Chua Nhap Ma Mon Hoc!", 66, 16, 700);
			gotoXY(82, y);
			goto IDMONHOC;
		}
		gotoxy(100+vitri, y);
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 30))
		{
			mh.Namemonhoc[vitri] = char(key);
			mh.Namemonhoc[vitri] = toupper(mh.Namemonhoc[vitri]);
			cout << mh.Namemonhoc[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(100 + vitri, y);
			cout << " ";
			gotoXY(100 + vitri, y);
		}
		if (key == SPACE && mh.Namemonhoc[vitri - 1] != ' ' && vitri > 0 && vitri < 30) // ko cho 2 khoang trang && vitri = 0
		{
			gotoXY(100 + vitri, y);
			cout << " ";
			mh.Namemonhoc[vitri] = ' ';
			vitri++;
		}
		if (key == ENTER && vitri != 0)
		{
			if (mh.Namemonhoc[vitri - 1] == ' ') { vitri--; } //Kiem tra ki tu cuoi cung la khoang trang thi xoa khoang trang
			mh.Namemonhoc[vitri] = '\0';
			InsertNode_MonHoc(DSMONHOC, mh);
			gotoxy(66,16);
			cout << "                            ";
			gotoxy(66,9);
			GhiChu("Them Thanh Cong", 66, 9, 1000);
			GhiFileMonHoc(DSMONHOC);
			return;
		}
		if (key == LEFT)
		{
			mh.Namemonhoc[vitri] = '\0';
			vitri = strlen(mh.monhocID);
			gotoXY(82 + vitri, y);
			goto IDMONHOC;
		}
		
		if (key == ESC || key == F1) { return; }
	}

}

void SuaMonHoc(PTRMONHOC &DSMONHOC)
{
	int key, vitri = 0, x = 110, y = 15, check_trung;
	PTRMONHOC p;
	ChiTietKhoaHoc ctkh[100]; int count;
	MonHoc mh; mh.monhocID[0] = NULL; mh.Namemonhoc[0] = NULL;
	Khung_SuaMonHoc();gotoXY(x, y);

TIMIDMONHOC:	
	while (1)
	{
		
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z') || (key == '-')) && (vitri < 11))
		{
			mh.monhocID[vitri] = char(key);
			mh.monhocID[vitri] = toupper(mh.monhocID[vitri]);
			cout << mh.monhocID[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(110 + vitri, y);
			cout << " ";
			gotoXY(110 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			
			mh.monhocID[vitri] = '\0';
			
			check_trung = KTIDMONHOC(DSMONHOC, mh.monhocID);
			ToArrK(ctkh, count);
			if (check_trung == 1)
			{
				for(int i = 0; i< count; i++)
				{
					if(strcmp(mh.monhocID, ctkh[i].monhocID) == 0)
					{
						GhiChu("Mon Hoc Da Dang Ky!", 81, 19, 500);	gotoXY(110 + vitri, y); goto TIMIDMONHOC ;break;
					}
					
				}
				system("cls");
				vitri = 0;
				p = Search_IDMonHoc(DSMONHOC, mh.monhocID);
				Khung_ThemMonHoc();
				gotoxy(94,9);
				cout << "THONG TIN MON HOC CAN SUA";
				x = 82, y = 14;
				gotoXY(x, y);
				strcpy(mh.monhocID, p->data.monhocID);
				strcpy(mh.Namemonhoc, p->data.Namemonhoc);
				gotoXY(82, y); cout << mh.monhocID;
				gotoXY(100, y); cout << mh.Namemonhoc;
				vitri = strlen(mh.monhocID);
				goto IDMONHOC;
				break;
			}
			else {
				GhiChu("Ma Mon Hoc Khong Ton Tai!", 81, 19, 500);	gotoXY(110 + vitri, y);
			}
		}
		if (key == ESC || key == F2) { return; }
	}
IDMONHOC:
	while (1)
	{
		gotoXY(66, 19);
		cout << "Ki tu: (A-Z) & (0-9). Toi da: 10";
		gotoXY(82 + vitri, y);
		key = GetKey();
		if (((key >= 'A' && key <= 'Z')  || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z') || (key == '-')) && (vitri < 11))
		{
			mh.monhocID[vitri] = char(key);
			mh.monhocID[vitri] = toupper(mh.monhocID[vitri]);
			cout << mh.monhocID[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(82 + vitri, y);
			cout << " ";
			gotoXY(82 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			mh.monhocID[vitri] = '\0';
			check_trung = KTIDMONHOC(DSMONHOC, mh.monhocID);
			if (check_trung == 1) {
				gotoXY(66, 16);
				cout << "Trung Ma Mon Hoc. Nhap Lai!";
				Sleep(500);
				continue;
			}
			vitri = strlen(mh.Namemonhoc);
			gotoXY(100 + vitri, y);
			goto NAMEMONHOC;
		}
		if (key == RIGHT)
		{
			mh.monhocID[vitri] = '\0';
			check_trung = KTIDMONHOC(DSMONHOC, mh.monhocID);
			if (check_trung == 1) {
				gotoXY(66, 16);
				cout << "Trung Ma Mon Hoc. Nhap Lai!";
				Sleep(500); continue;
			}
			vitri = strlen(mh.Namemonhoc);
			gotoXY(100 + vitri, y);
			goto NAMEMONHOC;
		}
		if (key == ESC || key == F1) { return; }
	}
NAMEMONHOC:
	while (1)
	{
		gotoXY(66,19);
		   cout << "Ki tu: (A-Z) & (0-9). Toi da: 30";
		  
		if (mh.monhocID[0] == '\0')
		{
			GhiChu("Ban Chua Nhap Ma Mon Hoc!", 66, 16, 700);
			gotoXY(82, y);
			goto IDMONHOC;
		}
		gotoxy(100+vitri, y);
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 30))
		{
			mh.Namemonhoc[vitri] = char(key);
			mh.Namemonhoc[vitri] = toupper(mh.Namemonhoc[vitri]);
			cout << mh.Namemonhoc[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(100 + vitri, y);
			cout << " ";
			gotoXY(100 + vitri, y);
		}
		if (key == SPACE && mh.Namemonhoc[vitri - 1] != ' ' && vitri > 0 && vitri < 30) // ko cho 2 khoang trang && vitri = 0
		{
			gotoXY(100 + vitri, y);
			cout << " ";
			mh.Namemonhoc[vitri] = ' ';
			vitri++;
		}
		if (key == ENTER && vitri != 0)
		{
			if (mh.Namemonhoc[vitri - 1] == ' ') { vitri--; } //Kiem tra ki tu cuoi cung la khoang trang thi xoa khoang trang
			mh.Namemonhoc[vitri] = '\0';
			gotoxy(66,9);
			p->data = mh;
			GhiChu("Mon Hoc Da Duoc Cap Nhat!", 66, 9, 1000);
			GhiFileMonHoc(DSMONHOC);
			return;
		}
		if (key == LEFT)
		{
			mh.Namemonhoc[vitri] = '\0';
			vitri = strlen(mh.monhocID);
			gotoXY(82 + vitri, y);
			goto IDMONHOC;
		}
		
		if (key == ESC || key == F1) { return; }
	}

}
void PhanTuTheMangMH(PTRMONHOC &p, PTRMONHOC &q) {
	if (q->left != NULL)
	{
		PhanTuTheMangMH(p, q->left);
	}
	else {
		p->data = q->data;			
		p = q;						
		q = q->right;				
	}
}
void DeleteNode_MonHoc(PTRMONHOC &DSMONHOC, char c[]) {
	if (DSMONHOC == NULL) { return; }
	
	if (strcmp(DSMONHOC->data.monhocID, c) >0)
	{
		DeleteNode_MonHoc(DSMONHOC->left, c);
	}
	else if (strcmp(DSMONHOC->data.monhocID, c) <0)
	{
		DeleteNode_MonHoc(DSMONHOC->right, c);
	}
	
	else {
		PTRMONHOC p = DSMONHOC;		
		if (DSMONHOC->left == NULL && DSMONHOC->right == NULL)	
		{
			delete DSMONHOC; DSMONHOC = NULL; return;
		}
		if (DSMONHOC->left == NULL && DSMONHOC->right != NULL)
		{
			DSMONHOC = DSMONHOC->right;
		}
		else if (DSMONHOC->right == NULL && DSMONHOC->left != NULL) 
		{
			DSMONHOC = DSMONHOC->left;
		}
	
		else {
			PhanTuTheMangMH(p, DSMONHOC->right);
			delete p;
		}
	}
}

void XoaMonHoc(PTRMONHOC &DSMONHOC)
{
	int key, vitri = 0, x = 110, y = 15, check_trung, check_mh;
	PTRMONHOC p;
	ChiTietKhoaHoc ctkh[100]; int count;
	MonHoc mh; mh.monhocID[0] = NULL;
	Khung_XoaMonHoc();gotoXY(x, y);
	
RESET:	
	while (1)
	{
		
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z') || (key == '-')) && (vitri < 11))
		{
			mh.monhocID[vitri] = char(key);
			mh.monhocID[vitri] = toupper(mh.monhocID[vitri]);
			cout << mh.monhocID[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(110 + vitri, y);
			cout << " ";
			gotoXY(110 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			
			mh.monhocID[vitri] = '\0';	//Ngat chuoi~
			check_trung = KTIDMONHOC(DSMONHOC, mh.monhocID); //KT trung`. 1: trung, co ton tai 0: ko trung
			check_mh = check_ctmh(mh.monhocID);
			if (check_trung != 0)
			{
				if(check_mh != 1)
				{
					DeleteNode_MonHoc(DSMONHOC, mh.monhocID);
					GhiChu("Xoa Thanh Cong Mon Hoc!                       ", 81, 17, 1500);
					gotoxy(81,17);
					cout <<"                                              ";
					GhiFileMonHoc(DSMONHOC);
					return;
				}
				else {
					GhiChu("Mon Hoc Da Them Vao Khoa Hoc!                 ", 81, 17, 500);	gotoXY(110 + vitri, y);
				}
												
				
			}
				
			else {
					GhiChu("Ma Mon Hoc Khong Ton Tai!                     ", 81, 17, 500);	gotoXY(110 + vitri, y);
			}
		}
		if (key == ESC || key == F2) { return; }
	}
}
//--xem danh sach lop
void XemMonHoc(PTRMONHOC &DSMONHOC, bool phanquyen) { // PHAN QUYEN: -true: admin -false: sinh vien
	int key;
	int  trang = 0, tongtrang = 0;
	int soluongmonhoc, dem = 0, demdong = 0;
	while (1)
	{
		soluongmonhoc = DemMonHoc(DSMONHOC);
		if (soluongmonhoc == 0)
		{
			GhiChu("Chua co du lieu khoa Hoc", 35, 27, 500);
		}
		else {
			if (soluongmonhoc < 15)
			{
				tongtrang = 1;
				trang = 0;
			}
			else {
				tongtrang = ((soluongmonhoc - 1) / 15 + 1);
			}
		}
		MonHoc *MH = new MonHoc[soluongmonhoc + 1];
		MangTam_MonHoc(DSMONHOC, MH, dem);
		Sort_MangMonHoc(MH, dem);
		dem = 0; demdong = 0;
		TextColor(14);	system("cls");
		Khung_XemMonHoc();
		for (int i = trang * 15; i < 15 + trang * 15 && i < soluongmonhoc; i++)
		{
			
			gotoXY(49, 8 + demdong); cout << i+1;
			gotoXY(54, 8 + demdong); cout << MH[i].monhocID;
			gotoXY(75, 8 + demdong); cout << MH[i].Namemonhoc;
			demdong++;
		}
		HienThiTrang(trang + 1, tongtrang, 118, 26);
		TextColor(164);
		gotoxy(47,2);
		cout << "                               DANH SACH MON HOC                                     ";
		Nocursortype();
		gotoXY(81, 26);
		key = GetKey();
		if ((key == RIGHT || key == DOWN) && trang < tongtrang - 1) { trang++; }
		if ((key == LEFT || key == UP) && trang > 0) { trang--; }
		if((key == F1 || key == F2 || key == F3) && phanquyen == false)
		{
			gotoxy(46,26);
			cout << "SINH VIEN KHONG DUOC QUYEN CHINH SUA";
			Sleep(1000);
			gotoxy(46,26);
			cout << "                                    ";
		}
		if (key == F1 && phanquyen == true)
		{
			system("cls");
			Yescursortype();
			ThemMonHoc(DSMONHOC);
		}
		if (key == F2 && phanquyen == true)
		{
			system("cls");
			Yescursortype();
			SuaMonHoc(DSMONHOC);
		}
		if (key == F3 && phanquyen == true){
			system("cls");
			Yescursortype();
			XoaMonHoc(DSMONHOC);
		}
		if (key == ESC) {return;}
		
		
	}
}
char MENU[5][40] = {
	"  1.XEM DANH SACH KHOA HOC    ",
	"  2.XEM DANH SACH MON         ",
	"  3.THEM MON CHO KHOA HOC     ",
	"  4.XEM MON THEO KHOA HOC     ",
	"  5.QUAY LAI TRANG CHU        "};
void ToMauMenu(int color, int vitri)
{
	TextColor(color);
	gotoXY(5, 4 + vitri * 4); cout << "                              ";
	gotoXY(5, 5 + vitri * 4); cout << MENU[vitri];
	gotoXY(5, 6 + vitri * 4); cout << "                              ";
}
int MenuCha()
{
	
	int vitri = 0;
	while (1)
	{
		
		Khung_ChucnangKhoaHoc();
		gotoxy(3,1);
		cout << "    CHUC NANG QUAN LY KHOA HOC     ";
		char key = GetKey();
		if (key == ENTER )
		{
			return vitri+1;
		}
		switch (key)
		{
		case DOWN:
		{
			if (vitri == 4)
			{
				ToMauMenu(240, vitri);
				vitri = 0;
				ToMauMenu(180, vitri);
			}
			else
			{
				ToMauMenu(240, vitri);
				vitri++;
				ToMauMenu(180, vitri);
			}
		}break;
		case UP:
		{
			if (vitri == 0)
			{
				ToMauMenu(240, vitri);
				vitri = (4);
				ToMauMenu(180, vitri);
			}
			else
			{
				ToMauMenu(240, vitri);
				vitri--;
				ToMauMenu(180, vitri);
			}
		}break;
		}
	}
}
/// code cho phan them khoa hoc mon hôc da xong
// bay gio code phan them mon vao khoa hoc

void xoaManHinhShowCN1(){
	gotoxy(40,3);
	SetBGColor(14);
	for(int i = 3;i<43;i++){
		
		gotoxy(41,i);
		cout<<"                                                                                                                                            ";
	}
}

//
//chuc nang cho cong viec la them mon hoc vao khoa hoc
void addMonHocToKhoa(char maKH[],  char maMH[]){
	//lay ve list cac du lieu da co
	int dem = 0,count=0,flag = 0;
	demMHAddKhoa(dem);
	
	if(dem==0){
				ChiTietKhoaHoc newKhMH;
				strcpy(newKhMH.khoahocID,maKH);
				strcpy(newKhMH.monhocID,maMH);
				//call den ham ghi file
				ghiFileChiTiet(newKhMH);
				TextColor(224);
				SetBGColor(100);
				gotoxy(80,41);
				cout<<"ADD THANH CONG ";
				Sleep(1000);
				gotoxy(80,41);
				cout<<"               ";
				getch();
	}else{
		ChiTietKhoaHoc ctkh[dem];
		ToArrK(ctkh,count);
		//kiem tra xem co bij trung mon khong
		for(int i= 0 ; i <dem; i ++){
			if(strcmp(maKH,ctkh[i].khoahocID)==0 && strcmp(maMH,ctkh[i].monhocID)==0 ){
				//thong bao trung
				TextColor(224);
				SetBGColor(100);
				gotoxy(80,41);
				cout<<"DA BI TRUNG MON HOC";
				Sleep(1000);
				gotoxy(80,41);
				cout<<"                   ";
				flag = 1;
				Sleep(2);
				getch();
			}
		}
			if(flag == 0){

				//tao ra doi tuong chi tiet va add no vao file
				ChiTietKhoaHoc newKhMH;
				strcpy(newKhMH.khoahocID,maKH);
				strcpy(newKhMH.monhocID,maMH);
				//call den ham ghi file
				bool a = ghiFileChiTiet(newKhMH);
				if(a == true){
					TextColor(224);
					gotoxy(80,41);
					cout<<"ADD THANH CONG ";
					Sleep(1000);
					cout<<"               ";
					getch();
			}
		}
	}
	
	
	//kiem tra trung 
	//them
}

//khung mon 

void showMon(bool phanQuyen,char maKH[]){
	if(phanQuyen){
			gotoxy(80,4);
	SetBGColor(111);
	cout << char(218) << setw(50) << setfill(char(196)) << char(191);
	for(int i = 5; i < 41; i++){
		gotoxy(80,i);
		cout << char(179);
		gotoxy(130,i);
		cout << char(179);
		gotoxy(81,i);
		cout<<"                                                 ";
		
	}
	gotoxy(80,40);
	cout << char(192) << setw(50) << setfill(char(196)) << char(217);
	gotoxy(81,6);
	cout <<  setw(49) << setfill(char(196)) <<char(196);
		gotoxy(83,5);
		cout<<"          TEN MON HOC     ";
			
	//---------------------------------- bat dau tu  7
	PTRMONHOC DSMH = NULL;
	DocFileMonHoc(DSMH);
	int dem =DemMonHoc(DSMH);
	int cc=0;
	
	MonHoc *mh = new MonHoc[100];
	MangTam_MonHoc(DSMH,mh,cc);
	for(int i = 0 ; i <dem; i++){
		gotoxy(81,7+i);
		SetBGColor(11);
		cout<<"                                        ";
		gotoxy(81,7+i);
		cout<<"        "<<mh[i].Namemonhoc;
	}
	int index = 0;
	//
		//
		gotoxy(81,7);
		SetBGColor(9);
		cout<<"                                        ";
		gotoxy(81,7);
		cout<<"        "<<mh[0].Namemonhoc;
		
	//
	
	Yescursortype();
	gotoxy(83,index+7);
	char chon = getch();
	Yescursortype();
	
	while(chon){
		if(chon ==72 || chon ==80){
			TextColor(224);
			SetBGColor(100);
			gotoxy(80,41);
			cout<<"ENTER DE THEM MON HOC VAO KHOA HOC   ";
			if(chon == 72 && index>0){
				index=index-1;
			}else if(chon==80 && index<dem-1){
				index=index+ 1;
			}
				//---------------------day la xu ly mau cho dep------------------//
			for(int i =7 ; i < dem+7; i ++){
					if(i==index+7){
						gotoxy(81,i);
						SetBGColor(9);
						cout<<"                                        ";
						gotoxy(81,i);
						cout<<"        "<<mh[i-7].Namemonhoc;
					}else{
						gotoxy(81,i);
						SetBGColor(11);
						cout<<"                                         ";
						gotoxy(81,i);
						cout<<"        "<<mh[i-7].Namemonhoc;
					}
				
		}
			
		}else if(chon ==13){
			//xoaTB();
			xoaManHinhShowCN1();
			char mhName[200] ;
			strcpy(mhName,mh[index].monhocID);
			addMonHocToKhoa(maKH,mhName);
			break;
			
		}else if(chon==27){
			xoaManHinhShowCN1();
			break;
		}
		
		gotoxy(83,index+7);
		chon = getch();
	}
	}else{
		gotoxy(2,44);
		cout<<"BAN KHONG CO QUYEN THUC THI CHUC NANG NAY";
	
		getch();
	}

}
//

//end khung mon
//khung them
void showLopThem(bool phanQuyen){
	if(phanQuyen){
			gotoxy(45,4);
	SetBGColor(111);
	cout << char(218) << setw(35) << setfill(char(196)) << char(191);
	for(int i = 5; i < 41; i++){
		gotoxy(45,i);
		cout << char(179);
		gotoxy(80,i);
		cout << char(179);
		gotoxy(46,i);
		cout<<"                                  ";
		
	}
	gotoxy(45,40);
	cout << char(192) << setw(35) << setfill(char(196)) << char(217);
	gotoxy(46,6);
	cout <<  setw(34) << setfill(char(196)) <<char(196);
		gotoxy(46,5);
		cout<<"          TEN KHOA HOC     ";
			
	//---------------------------------- bat dau tu  7
	PTRKHOAHOC DSKH = NULL;
	DocFileKhoaHoc(DSKH);
	int dem =DemKhoaHoc(DSKH);
	int cc=0;
	
	KhoaHoc *kh = new KhoaHoc[dem];
	MangTam_KhoaHoc(DSKH,kh,cc);
	for(int i = 0 ; i <dem; i++){
		gotoxy(46,7+i);
		SetBGColor(11);
		cout<<"                                  ";
		gotoxy(46,7+i);
		cout<<kh[i].Namekhoahoc;
	}
	int index = 0;
	//
		gotoxy(46,7);
		SetBGColor(9);
		cout<<"                                 ";
		gotoxy(46,7);
		cout<<kh[0].Namekhoahoc;
	//
	Yescursortype();
	gotoxy(48,index+7);
	char chon = getch();
	Yescursortype();
	
	while(chon){
		if(chon ==72 || chon ==80){
//			xoaTB();
			TextColor(224);
			gotoxy(45,41);
			cout<<"ENTER DE THEM MON HOC VAO KHOA HOC   ";
			if(chon == 72 && index>0){
				index=index-1;
			}else if(chon==80 && index<dem-1){
				index=index+ 1;
			}
				//---------------------day la xu ly mau cho dep------------------//
			for(int i =7 ; i < dem+7; i ++){
					if(i==index+7){
						gotoxy(46,i);
						SetBGColor(9);
						cout<<"                                ";
						gotoxy(46,i);
						cout<<kh[i-7].Namekhoahoc;
					}else{
						gotoxy(46,i);
						SetBGColor(11);
						cout<<"                                 ";
						gotoxy(46,i);
						cout<<kh[i-7].Namekhoahoc;
					}
				
		}
		
		}else if(chon ==13){
			//xoaTB();
			xoaManHinhShowCN1();
			char khName[200] ;
			strcpy(khName,kh[index].khoahocID);
			showMon(true,khName);
			break;
			
		}else if(chon==27){
			xoaManHinhShowCN1();
			break;
		}
//			
		gotoxy(48,index+7);
		chon = getch();
	}
	}else{
		//xoaTB();
		TextColor(224);
		gotoxy(2,44);
		cout<<"BAN KHONG CO QUYEN THUC THI CHUC NANG NAY";
		Sleep(1000);
		gotoxy(2,44);
		cout<<"                                         ";
		getch();
		
	}

}
//
//end khung them
//dem xem khoa hoc do co mon nao khong
int demMHinKH(char maKH[],ChiTietKhoaHoc ctkh[],int sizeCT){
	int dem = 0;
	for(int i = 0 ; i< sizeCT; i++){
		if(strcmp(maKH,ctkh[i].khoahocID)==0){
			dem ++;
		}
	}
	return dem;
}

//end chuc nang dem nha
void showMonTheoKhoaNha(bool phanQuyen,char maKH[]){
	if(phanQuyen){
			gotoxy(80,4);
	SetBGColor(111);
	cout << char(218) << setw(50) << setfill(char(196)) << char(191);
	for(int i = 5; i < 41; i++){
		gotoxy(80,i);
		cout << char(179);
		gotoxy(130,i);
		cout << char(179);
		gotoxy(81,i);
		cout<<"                                                 ";
		
	}
	gotoxy(80,40);
	cout << char(192) << setw(50) << setfill(char(196)) << char(217);
	gotoxy(81,6);
	cout <<  setw(49) << setfill(char(196)) <<char(196);
		gotoxy(81,5);
		cout<<"          TEN MON HOC     ";
			
	//---------------------------------- bat dau tu  7
	PTRMONHOC DSMH = NULL;
	DocFileMonHoc(DSMH);
	int dem =DemMonHoc(DSMH);
	int cc=0,nhay = 0,count = 0;
	
	MonHoc *mh = new MonHoc[100];
	MangTam_MonHoc(DSMH,mh,cc);
	int sizen = 0;
	demMHAddKhoa(sizen);
	ChiTietKhoaHoc ctkh[sizen];
	ToArrK(ctkh,count);
	int soLuong = demMHinKH(maKH,ctkh,sizen);
	if(soLuong==0){
		gotoxy(80,41);
		cout<<"KHOA HOC CHUA CO MON HOC";
		Sleep(2000);
		return;
	}else{
			for(int i = 0 ; i <sizen; i++){
				if(strcmp(ctkh[i].khoahocID,maKH)==0){
					for(int j= 0 ; j< dem ; j++){
						if(strcmp(ctkh[i].monhocID,mh[j].monhocID)==0){
							gotoxy(81,7+nhay);
							cout<<mh[j].Namemonhoc;
							nhay++;
							
//							gotoxy(2,21);
//		cout<<"co cl "<<mh[j].Namemonhoc;
//		Sleep(2);
//		getch();
						}
					}
				}
		
	}
	getch();
	}
	}else{
		gotoxy(2,44);
		cout<<"BAN KHONG CO QUYEN THUC THI CHUC NANG NAY";
		Sleep(1000);
		gotoxy(2,44);
		cout<<"                                         ";
		getch();
	}

}
//

//end khung mon
// show mon hoc theo khoa hoc 

void showMonTheoKhoa(bool phanQuyen){
	if(phanQuyen){
	gotoxy(45,4);
	SetBGColor(111);
	cout << char(218) << setw(35) << setfill(char(196)) << char(191);
	for(int i = 5; i < 41; i++){
		gotoxy(45,i);
		cout << char(179);
		gotoxy(80,i);
		cout << char(179);
		gotoxy(46,i);
		cout<<"                                  ";
		
	}
	gotoxy(45,40);
	cout << char(192) << setw(35) << setfill(char(196)) << char(217);
	gotoxy(46,6);
	cout <<  setw(34) << setfill(char(196)) <<char(196);
		gotoxy(46,5);
		cout<<"          TEN KHOA HOC     ";
			
	//---------------------------------- bat dau tu  7
	PTRKHOAHOC DSKH = NULL;
	DocFileKhoaHoc(DSKH);
	int dem =DemKhoaHoc(DSKH);
	int cc=0;
	
	KhoaHoc *kh = new KhoaHoc[100];
	MangTam_KhoaHoc(DSKH,kh,cc);
	for(int i = 0 ; i <dem; i++){
		gotoxy(46,7+i);
		SetBGColor(11);
		cout<<"                                  ";
		gotoxy(46,7+i);
		cout<<kh[i].Namekhoahoc;
	}
	int index = 0;
	//
		gotoxy(46,7);
		SetBGColor(9);
		cout<<"                                 ";
		gotoxy(46,7);
		cout<<kh[0].Namekhoahoc;
	//
	
	Yescursortype();
	gotoxy(48,index+7);
	char chon = getch();
	Yescursortype();
	
	while(chon){
		if(chon ==72 || chon ==80){
			TextColor(224);
			gotoxy(45,41);
			SetBGColor(100);
			cout<<"ENTER DE XEM MON HOC CUA KHOA HOC   ";
			if(chon == 72 && index>0){
				index=index-1;
			}else if(chon==80 && index<dem-1){
				index=index+ 1;
			}
			
					//---------------------day la xu ly mau cho dep------------------//
			for(int i =7 ; i < dem+7; i ++){
					if(i==index+7){
						gotoxy(46,i);
						SetBGColor(9);
						cout<<"                                ";
						gotoxy(46,i);
						cout<<kh[i-7].Namekhoahoc;
					}else{
						gotoxy(46,i);
						SetBGColor(11);
						cout<<"                                 ";
						gotoxy(46,i);
						cout<<kh[i-7].Namekhoahoc;
					}
				
		}
		}else if(chon ==13){
			//xoaTB();
			xoaManHinhShowCN1();
			char khName[200] ;
			strcpy(khName,kh[index].khoahocID);
			showMonTheoKhoaNha(1,khName);
			break;
			
		}else if(chon==27){
			xoaManHinhShowCN1();
			break;
		}
		
		gotoxy(48,index+7);
		chon = getch();
	}
	}else{
		gotoxy(2,44);
		cout<<"BAN KHONG CO QUYEN THUC THI CHUC NANG NAY";
		Sleep(1000);
		gotoxy(2,44);
		cout<<"                                         ";
		getch();
	}

}
//
//end khung them
void MenuKhoaHoc(PTRKHOAHOC &DSKHOAHOC, PTRMONHOC &DSMONHOC, bool phanquyen)
{
	
	Khung_ChucnangKhoaHoc();
	while (1)
	{
		
		Nocursortype();
		system("cls");
		system("color 71");
		for (int i = 0; i < 5 ; i++)
		{
			if (i == 0) { TextColor(180); }
			else { TextColor(240); }
			gotoXY(5, 4 + i * 4); cout << "                              ";
			gotoXY(5, 5 + i * 4); cout << MENU[i];
			gotoXY(5, 6 + i * 4); cout << "                              ";
		}
		gotoXY(24, 7);
		int chon = MenuCha();
		switch (chon)
		{
			case 1:
			{
				XemKhoaHoc(DSKHOAHOC, phanquyen);
				break;
			}
			case 2:
			{
				XemMonHoc(DSMONHOC, phanquyen);
				break;	
			}
			case 3:
			{
				showLopThem(phanquyen);
				break;
			}
			case 4:
			{
				showMonTheoKhoa(phanquyen);
				 break;
			}
			case 5:
			{
				return; break;
			}
			
		}
	}
}

