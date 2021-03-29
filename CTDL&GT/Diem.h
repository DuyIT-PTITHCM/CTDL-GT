#include"giaodien.h"

void ShowTableSV(){
	cout << setw(20) << left << "Ma SV" << setw(20) << left << "Ten" << setw(20) << left << "Lop"<< setw(20) << left << "SDT"<< setw(20) << left << "CMND" <<"\n";
}

void ShowSV(SinhVien sv){
	cout << setw(20) << left << sv.maSinhVien << setw(20) << left << sv.tenSinhVien << setw(20) << left << sv.lopSinhVien << setw(20) << left << sv.soDienThoai << setw(20) << left << sv.cmnd << "\n";
}

void DuyetNLRSV(TREE p){
	if (p!=NULL)
	{
		ShowSV(p->sv);
		DuyetNLRSV(p->pLeft);
		DuyetNLRSV(p->pRight);
	}
}

void KhoiTaoCayDiem(PtrDiem &TreeDiem){
	TreeDiem = NULL;
}

void ShowTableDiem(){
	cout << setw(20) << left << "Ma SV" << setw(20) << left << "Ma Mon Hoc" << setw(20) << left << "Chuyen Can"<< setw(20) << left << "Giua Ky";
	cout << setw(20) << left << "Cuoi Ky" << setw(20) << left << "TBM" <<"\n";
}

void ShowDiem(DiemSV d){
	float TBM = 0;
	TBM = (float)(d.ChuyenCan*10 + d.GiuaKy*20 + d.CuoiKy*70)/100;
	cout << setw(20) << left << d.maSinhVien << setw(20) << left << d.monhocID << setw(20) << left << d.ChuyenCan << setw(20) << left << d.GiuaKy;
	cout << setw(20) << left << d.CuoiKy << setw(20) << left << TBM << "\n";
}

void DuyetNLRDiem(PtrDiem p){
	if (p!=NULL)
	{
		ShowDiem(p->Diem);
		DuyetNLRDiem(p->Left);
		DuyetNLRDiem(p->Right);
	}
}

int CountDiem(PtrDiem t) {
	if (t != NULL)
	{
		return (CountDiem(t->Left) + CountDiem(t->Right) + 1);
	}
	else return 0;
}

//void AddTreeDiem(PtrDiem &TreeDiem, DiemSV diem){	
//	if(TreeDiem!=NULL)
//	{
//		if (strcmp(TreeDiem->Diem.maSinhVien, diem.maSinhVien) < 0)
//			AddTreeDiem(TreeDiem->Left, diem);
//		else
//			AddTreeDiem(TreeDiem->Right, diem);
//	}
//	else
//	{
//		TreeDiem = new NodeDiem;
//		TreeDiem->Diem = diem;
//		TreeDiem->Left = NULL;
//		TreeDiem->Right = NULL;
//	}
//}

void SuaDiem(PtrDiem &p, DiemSV diem){
	if (p!=NULL)
	{
		if(strcmp(p->Diem.maSinhVien, diem.maSinhVien) == 0 && strcmp(p->Diem.monhocID, diem.monhocID) == 0){
			p->Diem = diem;
			return;
		}
		SuaDiem(p->Left, diem);
		SuaDiem(p->Right, diem);
	}
}

void SuaDanhSachDiem(PtrDiem &p, DiemSV DSDiem[], int demDiem){
	for(int i = 0; i < demDiem; i++){
		SuaDiem(p, DSDiem[i]);
	}
}

void ghi1(PtrDiem p, ofstream &m){
	if(p!=NULL){
		m<<p->Diem.maSinhVien; m<<",";
		m<<p->Diem.tenSinhVien; m<<",";
		m<<p->Diem.monhocID; m<<",";
		m<<p->Diem.ChuyenCan; m<<",";
		m<<p->Diem.GiuaKy; m<<",";
		m<<p->Diem.CuoiKy; m<<",";
		m<<p->Diem.TBM; m<<endl;
		ghi1(p->Left,m);
		ghi1(p->Right,m);
	} 
}

void GhiFileDiem(PtrDiem &tree, DiemSV DSSV[], int n, char *mamon, char *malop){
	DiemSV diem;
	strcpy(diem.monhocID, mamon);
	for(int i = 0; i < n; i++){
		strcpy(diem.maSinhVien, DSSV[i].maSinhVien);
		strcpy(diem.tenSinhVien, DSSV[i].tenSinhVien);
		diem.ChuyenCan = DSSV[i].ChuyenCan;
		diem.GiuaKy = DSSV[i].GiuaKy;
		diem.CuoiKy = DSSV[i].CuoiKy;
		diem.TBM = DSSV[i].TBM;
		AddTreeDiem(tree, diem);
	}
	string a(mamon);
	string b(malop);
	string tenFile = a + b + ".txt";
	ofstream g(tenFile.c_str(), ios::out);
	ghi1(tree,g);	
	g.close();
}

void DocFileDiem(PtrDiem &tree, char *mamon, char *malop){
	string a(mamon);
	string b(malop);
	string tenFile = a + b + ".txt";
	ifstream d(tenFile.c_str(), ios::in);  
	if (d.fail())
	{
		std::cout << "Failed to open this file!" << std::endl;
		return;
	}
	
	while(!d.eof()){
		DiemSV diem;
		string maSV, tenSV, maMon, chuyenCan, giuaKy, cuoiKy, tbm;
		getline(d,maSV,',');
		if(maSV == "") break;
		
		getline(d,tenSV,',');
		getline(d,maMon,',');	
		getline(d,chuyenCan,',');
		getline(d,giuaKy,',');
		getline(d,cuoiKy,',');
		getline(d,tbm,'\n');
		
		strcpy(diem.maSinhVien, maSV.c_str());
		strcpy(diem.tenSinhVien, tenSV.c_str());
		strcpy(diem.monhocID, maMon.c_str());
		diem.ChuyenCan = atof(chuyenCan.c_str()); 
		diem.GiuaKy = atof(giuaKy.c_str()); 
		diem.CuoiKy = atof(cuoiKy.c_str()); 
		diem.TBM = atof(tbm.c_str()); 
		
		AddTreeDiem(tree, diem);
	}
	d.close();
}

void GhiFileTreeDiem(PtrDiem tree){
	string tenFile = "DiemSinhVien.txt";
	ofstream g(tenFile.c_str(), ios::out);
	ghi1(tree,g);	
	g.close();
}

//void DocFileTreeDiem(PtrDiem &tree){
//	string tenFile = "DiemSinhVien.txt";
//	ifstream d(tenFile.c_str(), ios::in);  
//	if (d.fail())
//	{
//		std::cout << "Failed to open this file!" << std::endl;
//		return;
//	}
//	
//	while(!d.eof()){
//		DiemSV diem;
//		string maSV, tenSV, maMon, chuyenCan, giuaKy, cuoiKy, tbm;
//		getline(d,maSV,',');
//		if(maSV == "") break;
//		
//		getline(d,tenSV,',');
//		getline(d,maMon,',');	
//		getline(d,chuyenCan,',');
//		getline(d,giuaKy,',');
//		getline(d,cuoiKy,',');
//		getline(d,tbm,'\n');
//		
//		strcpy(diem.maSinhVien, maSV.c_str());
//		strcpy(diem.tenSinhVien, tenSV.c_str());
//		strcpy(diem.monhocID, maMon.c_str());
//		diem.ChuyenCan = atof(chuyenCan.c_str()); 
//		diem.GiuaKy = atof(giuaKy.c_str()); 
//		diem.CuoiKy = atof(cuoiKy.c_str()); 
//		diem.TBM = atof(tbm.c_str()); 
//		
//		AddTreeDiem(tree, diem);
//	}
//	d.close();
//}

void GhiFileDanhSachDiem(DiemSV DSSV[], int demDiemSV, char *mamon, char *malop){
	string a(mamon);
	string b(malop);
	string tenFile = a + b + ".txt";
	ofstream ghi(tenFile.c_str(), ios::out);
	
	for(int i = 0; i < demDiemSV; i++){
		ghi<<DSSV[i].maSinhVien; ghi<<",";
		ghi<<DSSV[i].tenSinhVien; ghi<<",";
		ghi<<DSSV[i].monhocID; ghi<<",";
		ghi<<DSSV[i].ChuyenCan; ghi<<",";
		ghi<<DSSV[i].GiuaKy; ghi<<",";
		ghi<<DSSV[i].CuoiKy; ghi<<",";
		ghi<<DSSV[i].TBM; ghi<<endl;
	}
	ghi.close();
}
//tra ve diem sinh vien theo ma mon va theo lop
int DocFileDanhSachDiem(DiemSV DSSV[], char *mamon, char *malop){
	string a(mamon);
	string b(malop);
	string tenFile = a + b + ".txt";
	ifstream d(tenFile.c_str(), ios::in);  
	if (d.fail())
	{
	//	std::cout << "Failed to open this file!" << std::endl;
		return 0;
	}
	int i = 0;
	while(!d.eof()){
		DiemSV diem;
		string maSV, tenSV, maMon, chuyenCan, giuaKy, cuoiKy, tbm;
		getline(d,maSV,',');
		if(maSV == "") break;
		
		getline(d,tenSV,',');
		getline(d,maMon,',');	
		getline(d,chuyenCan,',');
		getline(d,giuaKy,',');
		getline(d,cuoiKy,',');
		getline(d,tbm,'\n');
		
		strcpy(diem.maSinhVien, maSV.c_str());
		strcpy(diem.tenSinhVien, tenSV.c_str());
		strcpy(diem.monhocID, maMon.c_str());
		diem.ChuyenCan = atof(chuyenCan.c_str()); 
		diem.GiuaKy = atof(giuaKy.c_str()); 
		diem.CuoiKy = atof(cuoiKy.c_str()); 
		diem.TBM = atof(tbm.c_str()); 
		
		DSSV[i] = diem;
		i++;
	}
	d.close();
	return i;
}

bool CheckDiemDeXoa(char *mamon, char *malop){
	string a(malop);
	string b(mamon);
	string tenFile = a + b + ".txt";
	ifstream d(tenFile.c_str(), ios::in);
	if (d.fail())
	{
		std::cout << "Failed to open this file!" << std::endl;
		return false;
	}
	int i = 0;
	while(!d.eof()){
		string maSV, tenSV, maMon, chuyenCan, giuaKy, cuoiKy, tbm;
		getline(d,maSV,',');
		if(maSV != "") return true;
	}
	d.close();
	return false;
}

void ShowKhungDiemSV(DiemSV *SV, int bd, int kt, string lop, string mon){
	system("cls");
	int RIGHTX = 160; 
	int RIGHTY = LEFTY + (kt - bd + 2) * 2;// Phai chia het cho 3
	
	int kcSTT = 4;
	int khoangCachCot = (RIGHTX-kcSTT)/6;
	
	gotoxy((RIGHTX-LEFTX)/2 - 21, LEFTY-4); ;cout<< "DANH SACH DIEM CUA SINH VIEN THEO MON + LOP";
	gotoxy((RIGHTX-LEFTX)/4 - 4, LEFTY-2); ;cout<< "LOP: " << lop;
	gotoxy((RIGHTX-LEFTX)*2/4 - 4, LEFTY-2); ;cout<< "MON HOC: " << mon;
	
	//BoderTop 0-160
	gotoxy(LEFTX,LEFTY); cout << char(218) << setw(RIGHTX-LEFTX) << setfill(char(196)) << char(191);
	
	//BoderLeft
	for(int i = LEFTY+1; i < RIGHTY; i++){
		gotoxy(LEFTX, i); cout<<char(179);
	}
	
	//BoderBottom	
	gotoxy(LEFTX,RIGHTY); cout << char(192) << setw(RIGHTX-LEFTX) << setfill(char(196)) << char(217);
	
	//BoderRight
	for(int i = LEFTY+1; i < RIGHTY; i++){
		gotoxy(RIGHTX, i); cout<<char(179);
	}
	
	//Cot Ngang tieu de
	gotoxy(LEFTX+1, LEFTY+2); cout << setw(RIGHTX-LEFTX-1) << setfill(char(196)) << char(196);
	
	// n dong
	int n = kt - bd + 1;
	for(int i = bd; i <= kt; i++){
		int ndongy = LEFTY + 2 + (i-bd)*2;
		if(ndongy > RIGHTY){
			break;
		}
		gotoxy(LEFTX + 1, ndongy + 1); cout << i; // Show STT
		gotoxy(LEFTX+1, ndongy); cout << setw(RIGHTX-LEFTX-1) << setfill(char(196)) << char(196);
		
		gotoxy(kcSTT + 0*khoangCachCot + 1, ndongy + 1); cout << SV[i-1].maSinhVien; // Show thong tin
		gotoxy(kcSTT + 1*khoangCachCot + 1, ndongy + 1); cout << SV[i-1].tenSinhVien;
		gotoxy(kcSTT + 2*khoangCachCot + 1, ndongy + 1); cout << SV[i-1].ChuyenCan;
		gotoxy(kcSTT + 3*khoangCachCot + 1, ndongy + 1); cout << SV[i-1].GiuaKy;
		gotoxy(kcSTT + 4*khoangCachCot + 1, ndongy + 1); cout << SV[i-1].CuoiKy;
		gotoxy(kcSTT + 5*khoangCachCot + 1, ndongy + 1); cout << SV[i-1].TBM;
	}
	
	//STT
	gotoxy(LEFTX+1, LEFTY+1); cout << "STT";
	for(int j = LEFTY+1; j < RIGHTY; j++)
	{
		gotoxy(LEFTX+kcSTT, j); cout << char(179);
	}
	
	
	gotoxy(kcSTT + 0*khoangCachCot + 1, LEFTY+1); cout << "MA SV";
	gotoxy(kcSTT + 1*khoangCachCot + 1, LEFTY+1); cout << "TEN";
	gotoxy(kcSTT + 2*khoangCachCot + 1, LEFTY+1); cout << "CHUYEN CAN";
	gotoxy(kcSTT + 3*khoangCachCot + 1, LEFTY+1); cout << "GIUA KY";
	gotoxy(kcSTT + 4*khoangCachCot + 1, LEFTY+1); cout << "CUOI KY";
	gotoxy(kcSTT + 5*khoangCachCot + 1, LEFTY+1); cout << "TBM";
	// 6 cot doc
	for(int i =0; i < 5; i++){
		for(int j = LEFTY+1; j < RIGHTY; j++)
		{
			gotoxy(kcSTT + i*khoangCachCot+khoangCachCot, j); cout << char(179);
		}
	}
	gotoxy(LEFTX, RIGHTY+2); cout<< setw(26)<<" ENTER: Nhap Diem " << setw(34) <<" UP, DOWN: Chon Sinh Vien " << setw(29) <<" DELETE: Xoa Diem "
		<< setw(35)<<" LEFT, RIGHT: Chuyen trang " << setw(20)<<" ESC: Thoat ";	
}

void ShowLopDiem(LopHoc *lopArr, int bd, int kt){
	system("cls");
	int RIGHTX = 160; 
	int RIGHTY = LEFTY + (kt - bd + 2) * 2;// Phai chia het cho 3
	
	int kcSTT = 4;
	int khoangCachCot = (RIGHTX-kcSTT)/4;
	
	gotoxy((RIGHTX-LEFTX)/2 - 10, LEFTY-4); ;cout<< "DANH SACH LOP";
	
	//BoderTop 0-160
	gotoxy(LEFTX,LEFTY); cout << char(218) << setw(RIGHTX-LEFTX) << setfill(char(196)) << char(191);
	
	//BoderLeft
	for(int i = LEFTY+1; i < RIGHTY; i++){
		gotoxy(LEFTX, i); cout<<char(179);
	}
	
	//BoderBottom	
	gotoxy(LEFTX,RIGHTY); cout << char(192) << setw(RIGHTX-LEFTX) << setfill(char(196)) << char(217);
	
	//BoderRight
	for(int i = LEFTY+1; i < RIGHTY; i++){
		gotoxy(RIGHTX, i); cout<<char(179);
	}
	
	//Cot Ngang tieu de
	gotoxy(LEFTX+1, LEFTY+2); cout << setw(RIGHTX-LEFTX-1) << setfill(char(196)) << char(196);
	
	// n dong
	int n = kt - bd + 1;
	for(int i = bd; i <= kt; i++){
		int ndongy = LEFTY + 2 + (i-bd)*2;
		if(ndongy > RIGHTY){
			break;
		}
		gotoxy(LEFTX + 1, ndongy + 1); cout << i; // Show STT
		gotoxy(LEFTX+1, ndongy); cout << setw(RIGHTX-LEFTX-1) << setfill(char(196)) << char(196);
		
		gotoxy(kcSTT + 0*khoangCachCot + 1, ndongy + 1); cout << lopArr[i-1].Idlop; // Show thong tin
		gotoxy(kcSTT + 1*khoangCachCot + 1, ndongy + 1); cout << lopArr[i-1].Namelop;
		gotoxy(kcSTT + 2*khoangCachCot + 1, ndongy + 1); cout << lopArr[i-1].Idkhoa;
		gotoxy(kcSTT + 3*khoangCachCot + 1, ndongy + 1); cout << lopArr[i-1].Idkhoahoc;
	}
	
	//STT
	gotoxy(LEFTX+1, LEFTY+1); cout << "STT";
	for(int j = LEFTY+1; j < RIGHTY; j++)
	{
		gotoxy(LEFTX+kcSTT, j); cout << char(179);
	}
	
	
	gotoxy(kcSTT + 0*khoangCachCot + 1, LEFTY+1); cout << "MA LOP";
	gotoxy(kcSTT + 1*khoangCachCot + 1, LEFTY+1); cout << "TEN LOP";
	gotoxy(kcSTT + 2*khoangCachCot + 1, LEFTY+1); cout << "MA KHOA";
	gotoxy(kcSTT + 3*khoangCachCot + 1, LEFTY+1); cout << "MA KHOA HOC";
	// 4 cot doc
	for(int i =0; i < 3; i++){
		for(int j = LEFTY+1; j < RIGHTY; j++)
		{
			gotoxy(kcSTT + i*khoangCachCot+khoangCachCot, j); cout << char(179);
		}
	}
	gotoxy(LEFTX, RIGHTY+2); cout<< setw(44)<<" ENTER: Xem danh sach mon cua lop " << setw(30) <<" UP, DOWN: Chon Lop "
		<< setw(35)<<" LEFT, RIGHT: Chuyen trang " << setw(20)<<" ESC: Thoat ";	
}

void ShowMonCuaLop(MonHoc *monHocArr, int demMH, int bd, int kt, LopHoc lop){
	system("cls");
	int RIGHTX = 160; 
	int RIGHTY = LEFTY + (kt - bd + 2) * 2;// Phai chia het cho 3
	
	int kcSTT = 4;
	int khoangCachCot = (RIGHTX-kcSTT)/2;
	
	gotoxy((RIGHTX-LEFTX)/2 - 10, LEFTY-4); ;cout<< "DANH SACH MON HOC CUA LOP";
	gotoxy((RIGHTX-LEFTX)/2 - 10, LEFTY-2); ;cout<< "MA LOP: " << lop.Idlop << "          TEN LOP: " << lop.Namelop;
	
	//BoderTop 0-160
	gotoxy(LEFTX,LEFTY); cout << char(218) << setw(RIGHTX-LEFTX) << setfill(char(196)) << char(191);
	
	//BoderLeft
	for(int i = LEFTY+1; i < RIGHTY; i++){
		gotoxy(LEFTX, i); cout<<char(179);
	}
	
	//BoderBottom	
	gotoxy(LEFTX,RIGHTY); cout << char(192) << setw(RIGHTX-LEFTX) << setfill(char(196)) << char(217);
	
	//BoderRight
	for(int i = LEFTY+1; i < RIGHTY; i++){
		gotoxy(RIGHTX, i); cout<<char(179);
	}
	
	//Cot Ngang tieu de
	gotoxy(LEFTX+1, LEFTY+2); cout << setw(RIGHTX-LEFTX-1) << setfill(char(196)) << char(196);
	
	// n dong
	int n = kt - bd + 1;
	for(int i = bd; i <= kt; i++){
		int ndongy = LEFTY + 2 + (i-bd)*2;
		if(ndongy > RIGHTY){
			break;
		}
		gotoxy(LEFTX + 1, ndongy + 1); cout << i; // Show STT
		gotoxy(LEFTX+1, ndongy); cout << setw(RIGHTX-LEFTX-1) << setfill(char(196)) << char(196);
		
		gotoxy(kcSTT + 0*khoangCachCot + 1, ndongy + 1); cout << monHocArr[i-1].monhocID; // Show thong tin
		gotoxy(kcSTT + 1*khoangCachCot + 1, ndongy + 1); cout << monHocArr[i-1].Namemonhoc;
	}
	
	//STT
	gotoxy(LEFTX+1, LEFTY+1); cout << "STT";
	for(int j = LEFTY+1; j < RIGHTY; j++)
	{
		gotoxy(LEFTX+kcSTT, j); cout << char(179);
	}
	
	
	gotoxy(kcSTT + 0*khoangCachCot + 1, LEFTY+1); cout << "MA MON";
	gotoxy(kcSTT + 1*khoangCachCot + 1, LEFTY+1); cout << "TEN MON";
	// 2 cot doc
	for(int i =0; i < 1; i++){
		for(int j = LEFTY+1; j < RIGHTY; j++)
		{
			gotoxy(kcSTT + i*khoangCachCot+khoangCachCot, j); cout << char(179);
		}
	}
	gotoxy(LEFTX, RIGHTY+2); cout<< setw(44)<<" ENTER: Xem danh sach Diem " << setw(30) <<" UP, DOWN: Chon Mon "
		<< setw(35)<<" LEFT, RIGHT: Chuyen trang " << setw(20)<<" ESC: Thoat ";	
	if(demMH == 0){
		gotoxy((RIGHTX-LEFTX)/2 - 10, LEFTY-1); cout<< "Lop Chua Dang Ky Mon Nao!";
	}
}

void KhungNhapDiem(DiemSV *SV, int thuTuSV){
	system("cls");
	int RIGHTX = 160; 
	int RIGHTY = LEFTY + 12 ;// Phai chia het cho 3
	
	
	gotoxy((RIGHTX-LEFTX)/2 - 21, LEFTY-4); ;cout<< "NHAP DIEM CHO SINH VIEN";
	gotoxy((RIGHTX-LEFTX)/4 - 4, LEFTY-2); ;cout<< "MA SV: " << SV[thuTuSV].maSinhVien;
	gotoxy((RIGHTX-LEFTX)*2/4 - 4, LEFTY-2); ;cout<< "TEN: "<< SV[thuTuSV].tenSinhVien;
	gotoxy((RIGHTX-LEFTX)*3/4 - 4, LEFTY-2); ;cout<< "MON HOC: "<< SV[thuTuSV].monhocID;
	
	//BoderTop 0-160
	gotoxy(LEFTX + (RIGHTX-LEFTX)*1/4 ,LEFTY); cout << char(218) << setw((RIGHTX-LEFTX)*2/4) << setfill(char(196)) << char(191);
	
	//BoderLeft
	for(int i = LEFTY+1; i < RIGHTY; i++){
		gotoxy(LEFTX + (RIGHTX-LEFTX)*1/4, i); cout<<char(179);
	}
	
	//BoderBottom	
	gotoxy(LEFTX + (RIGHTX-LEFTX)*1/4,RIGHTY); cout << char(192) << setw((RIGHTX-LEFTX)*2/4) << setfill(char(196)) << char(217);
	
	//BoderRight
	for(int i = LEFTY+1; i < RIGHTY; i++){
		gotoxy((RIGHTX-LEFTX)*3/4, i); cout<<char(179);
	}
	
	gotoxy(LEFTX + (RIGHTX-LEFTX)*1/4 + 1, LEFTY + 1); cout<< " MA SV: ";
	gotoxy(LEFTX + (RIGHTX-LEFTX)*1/4 + 1, LEFTY + 3); cout<< " TEN: ";
	gotoxy(LEFTX + (RIGHTX-LEFTX)*1/4 + 1, LEFTY + 5); cout<< " CHUYEN CAN: ";
	gotoxy(LEFTX + (RIGHTX-LEFTX)*1/4 + 1, LEFTY + 7); cout<< " GIUA KY: ";
	gotoxy(LEFTX + (RIGHTX-LEFTX)*1/4 + 1, LEFTY + 9); cout<< " CUOI KY: ";
	gotoxy(LEFTX + (RIGHTX-LEFTX)*1/4 + 1, LEFTY + 11); cout<< " TBM: ";
	
	gotoxy(LEFTX + (RIGHTX-LEFTX)*2/5 + 5, LEFTY + 1); cout<< SV[thuTuSV].maSinhVien;
	gotoxy(LEFTX + (RIGHTX-LEFTX)*2/5 + 5, LEFTY + 3); cout<< SV[thuTuSV].tenSinhVien;
	gotoxy(LEFTX + (RIGHTX-LEFTX)*2/5 + 5, LEFTY + 5); cout<< SV[thuTuSV].ChuyenCan;
	gotoxy(LEFTX + (RIGHTX-LEFTX)*2/5 + 5, LEFTY + 7); cout<< SV[thuTuSV].GiuaKy;
	gotoxy(LEFTX + (RIGHTX-LEFTX)*2/5 + 5, LEFTY + 9); cout<< SV[thuTuSV].CuoiKy;
	gotoxy(LEFTX + (RIGHTX-LEFTX)*2/5 + 5, LEFTY + 11); cout<< SV[thuTuSV].TBM;
	
	for(int i = 1; i < 6; i ++){
		gotoxy(LEFTX + (RIGHTX-LEFTX)*1/4 + 1, LEFTY + i*2); cout << setw((RIGHTX-LEFTX)*2/4 - 1) << setfill(char(196)) << char(196);
	}
	for(int i = LEFTY+1; i < RIGHTY; i++){
		gotoxy((RIGHTX-LEFTX)*2/5, i); cout<<char(179);
	}
	
	gotoxy((RIGHTX-LEFTX)*1/5, RIGHTY+2); cout<< setw(26)<<" ENTER: Xac Nhan " << setw(34) <<" UP, DOWN: Chon Diem De Nhap " 
		<< setw(35)<<" LEFT, RIGHT: Nhap Diem "	<< setw(20)<<" ESC: Thoat ";
}

void XuatDiem(char *diem, int n){
	for(int i = 0; i <= n; i++){
		cout << diem[i];
	}
}

SinhVien searchTenSinhVien(TREE t, char maSinhVien[]){
	if (t!=NULL)
	{
		if (strcmp(maSinhVien,t->sv.maSinhVien)==0)
		{
			return t->sv;
		}
		searchTenSinhVien(t->pLeft, maSinhVien);
		searchTenSinhVien(t->pRight, maSinhVien);
	}
}

int demsv=0;
void DuyetNLRSVA(PtrDiem treeDiem, DiemSV *DSSV){
	if (treeDiem!=NULL)
	{
		strcpy(DSSV[demsv].maSinhVien, treeDiem->Diem.maSinhVien);
		strcpy(DSSV[demsv].tenSinhVien, treeDiem->Diem.tenSinhVien);
		DSSV[demsv].ChuyenCan = treeDiem->Diem.ChuyenCan;
		DSSV[demsv].GiuaKy = treeDiem->Diem.GiuaKy;
		DSSV[demsv].CuoiKy = treeDiem->Diem.CuoiKy;
		if(DSSV[demsv].ChuyenCan != 0 && DSSV[demsv].GiuaKy != 0 && DSSV[demsv].CuoiKy != 0){
			DSSV[demsv].TBM = (float)(10*DSSV[demsv].ChuyenCan + 20*DSSV[demsv].GiuaKy + 70*DSSV[demsv].CuoiKy)/100;
		}
		else DSSV[demsv].TBM = 0;
		demsv++;
		DuyetNLRSVA(treeDiem->Left, DSSV);
		DuyetNLRSVA(treeDiem->Right, DSSV);
	}
}

void ConvertSVToDiemSV(PtrDiem &TreeDiem, SinhVien ListSV[], int demSV, DiemSV *DSSV, string monHoc){
	for (int i = 0; i < demSV; i++)
	{
		strcpy(DSSV[i].maSinhVien, ListSV[i].maSinhVien);
		strcpy(DSSV[i].tenSinhVien, ListSV[i].tenSinhVien);
		DSSV[i].ChuyenCan = 0;
		DSSV[i].GiuaKy = 0;
		DSSV[i].CuoiKy = 0;
		DSSV[i].TBM = 0;		
		strcpy(DSSV[i].monhocID, monHoc.c_str());
		AddTreeDiem(TreeDiem, DSSV[i]);
	}
}

void hide_scrollbar(){
	
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(handle, &info);
    COORD new_size = 
    {
        info.srWindow.Right - info.srWindow.Left +1,
        info.srWindow.Bottom - info.srWindow.Top + 1
    };
    SetConsoleScreenBufferSize(handle, new_size);
}

void XemMa(){
	char a = getch();
	while(a!=27){
		a = getch();
		cout<< (int)a;
	}
}

void LayDanhSachDiem(LopHoc lop, DiemSV DSDiemSV[], int &demDiemSV){
//	PtrDiem treeDiem;
//	KhoiTaoCayDiem(treeDiem);
//	DocFileDiem(treeDiem, "NT284175", "D15CQCN01");
//	
//	int n = CountDiem(treeDiem);
//	DiemSV DSSV[n];
//	DuyetNLRSVA(treeDiem, DSSV);
	
		
}


//void CheckDiemSinhVien(PtrDiem TreeDiem, string maSV, int &dem){
//	if(TreeDiem == NULL) return;
//	else
//	{
//		if(strcmp(TreeDiem->Diem.maSinhVien, maSV.c_str()) == 0){
//			dem++;
//			return;
//		}	
//		CheckDiemSinhVien(TreeDiem->Left, maSV, dem);
//		CheckDiemSinhVien(TreeDiem->Right, maSV, dem);
//	}
//}
//
//bool CheckDiemXoaSinhVien(string maSV){
//	PtrDiem TreeDiem;
//	TreeDiem = NULL;
//	DocFileTreeDiem(TreeDiem);
//	int abc = 0;
//	CheckDiemSinhVien(TreeDiem, maSV, abc);
//	if(abc == 0) return false;
//	else return true;
//}

void HamNhapDiem(LopHoc lop, MonHoc monHoc, PtrDiem &TreeDiem){	
	//Lay DS all Sinh Vien
	TREE tree;
	initEmpty(tree);
	docAllFile(tree);
	int demSVAll = countSV(tree);
	int ccSV = 0;
	SinhVien DSSVAll[demSVAll];
	listTampAllSV(tree,DSSVAll,ccSV);
	
	//Lay Danh Sach Sinh Vien Cua Lop
	int demDiemSV = demSVTrongLop(DSSVAll, lop.Idlop, demSVAll);
	DiemSV DSDiemSV[demDiemSV];
	int checkDiem = DocFileDanhSachDiem(DSDiemSV, lop.Idlop, monHoc.monhocID);
	if(checkDiem == 0){
		SinhVien DSSVLop[demDiemSV];
		listTampCLass(DSSVLop, DSSVAll, lop.Idlop, demSVAll);
		ConvertSVToDiemSV(TreeDiem, DSSVLop, demDiemSV, DSDiemSV, monHoc.monhocID);
	}
	
	char qq = '0';
	int trangDiem = 0, sttDiemTruyen, trangDiemHienTai = 0, chonDiemNhap = 0, selectedIndexDiem = 0;
	while(qq!=27){		
		if(qq == '0' || trangDiemHienTai != trangDiem){
			trangDiemHienTai = trangDiem;
			if((demDiemSV - trangDiem * 16) > 16) sttDiemTruyen = 16;
			else sttDiemTruyen = demDiemSV - trangDiem * 16;
			ShowKhungDiemSV(DSDiemSV, trangDiem * 16 + 1, trangDiem * 16 + sttDiemTruyen, lop.Namelop, monHoc.Namemonhoc);
			selectedIndexDiem = 0;
			gotoxy(LEFTX + 5, LEFTY + 3 + (selectedIndexDiem * 2));
		}
		
		qq= getch();
		
		if(demDiemSV > 16 && qq == 75 && trangDiem > 0){
			trangDiem -= 1;
		}
		else if(demDiemSV > 16 && qq == 77){
			if((demDiemSV - (trangDiem * 16)) > 16) trangDiem += 1;
		}
		else if(qq == 72){
			if(selectedIndexDiem > 0) selectedIndexDiem -= 1;
			gotoxy(LEFTX + 5, LEFTY + 3 + (selectedIndexDiem * 2));
		}
		else if(qq == 80){
			if(selectedIndexDiem < sttDiemTruyen-1) selectedIndexDiem += 1;
			gotoxy(LEFTX + 5, LEFTY + 3 + (selectedIndexDiem * 2));
		}
		else if(qq == 13){
			KhungNhapDiem(DSDiemSV, selectedIndexDiem + trangDiemHienTai * 16);
			float diemNhapFloat, diemCC, diemGK, diemCK;
			diemCC = DSDiemSV[selectedIndexDiem + trangDiemHienTai * 16].ChuyenCan;
			diemGK = DSDiemSV[selectedIndexDiem + trangDiemHienTai * 16].GiuaKy;
			diemCK = DSDiemSV[selectedIndexDiem + trangDiemHienTai * 16].CuoiKy;
			char arrDiemNhap[3];
			bool isChange = false;
			while(qq != 27){
				gotoxy((160-LEFTX)*1/5, LEFTY + 12 +5); cout<< "                                                                                        ";
				gotoxy((160-LEFTX)*1/5, LEFTY + 12 +5); cout<< "Nhan UP/DOWN de chon diem hoac nhan LEFT/RIGHT de nhap diem!";
				gotoxy((160-LEFTX)*1/5, LEFTY + 12 +6); cout<< "Nhan ENTER de luu toan bo diem vua nhap!";
				diemNhapFloat = 0; 	
				gotoxy(LEFTX + (160-LEFTX)*2/5 + 5, LEFTY + 5 + chonDiemNhap * 2);			
				qq = getch();
				if(qq == 72){
					if(chonDiemNhap > 0) chonDiemNhap--;
				}
				else if(qq == 80){
					if(chonDiemNhap < 2) chonDiemNhap++;
				}
				else if(qq == 75 || qq == 77){
					gotoxy((160-LEFTX)*1/5, LEFTY + 12 +6); cout<< "                                        ";
					gotoxy((160-LEFTX)*1/5, LEFTY + 12 +5); cout<< "Nhap diem la so, co the co 1 chu so thap phan. Sau khi nhap xong nhan ENTER de luu diem!";
					gotoxy(LEFTX + (160-LEFTX)*2/5 + 5, LEFTY + 5 + chonDiemNhap * 2);
					cout <<"               ";
					gotoxy(LEFTX + (160-LEFTX)*2/5 + 5, LEFTY + 5 + chonDiemNhap * 2);
					char kyTuNhap = 0;
					bool kytuThapPhan = false;
					int dem = -1;
					diemNhapFloat = 0;
					isChange = false;
					while(kyTuNhap != 13){
						kyTuNhap = getch();
						if(kyTuNhap == 13){
 							for(int i = 0; i <= dem; i++){
								if(arrDiemNhap[i] == 46){
									if(i != 1) {
										gotoxy((160-LEFTX)*1/5, LEFTY + 12 + 7); cout<<"Diem khong hop le! Nhan BACKSPACE de xoa va nhap lai!";
										kyTuNhap = 0;
										diemNhapFloat = 0;
										break;
									}
									else continue;
								}
								else if(arrDiemNhap[i-1] == 46){
									diemNhapFloat = (float)(diemNhapFloat * 10 + arrDiemNhap[i]-48)/10;
								}
								else {
									diemNhapFloat = diemNhapFloat * 10 + arrDiemNhap[i]-48;
								}
							}
							if(diemNhapFloat > 10){
								gotoxy((160-LEFTX)*1/5, LEFTY + 12 + 7); cout<<"Diem khong hop le! Nhan BACKSPACE de xoa va nhap lai!";
								diemNhapFloat = 0;
								kyTuNhap = 0;
							}
							else {
								if(chonDiemNhap == 0) diemCC = diemNhapFloat;
								if(chonDiemNhap == 1) diemGK = diemNhapFloat;
								if(chonDiemNhap == 2) diemCK = diemNhapFloat;
								isChange = true;
							}
						}
						else if(kyTuNhap == 46 && !kytuThapPhan && dem < 2){
							dem++;
							kytuThapPhan = true;
							arrDiemNhap[dem] = kyTuNhap;
							gotoxy(LEFTX + (160-LEFTX)*2/5 + 5, LEFTY + 5 + chonDiemNhap * 2);
							XuatDiem(arrDiemNhap, dem);
						}
						else if(kyTuNhap == 8 && dem >= 0){
							cout<< diemNhapFloat;
							if(arrDiemNhap[dem] == 46) kytuThapPhan = false;
							dem--;
							gotoxy(LEFTX + (160-LEFTX)*2/5 + 5, LEFTY + 5 + chonDiemNhap * 2);
							cout <<"               ";
							gotoxy(LEFTX + (160-LEFTX)*2/5 + 5, LEFTY + 5 + chonDiemNhap * 2);
							if(dem >= 0)XuatDiem(arrDiemNhap, dem);
						}
						else if(kyTuNhap >= 48 && kyTuNhap <= 57 && dem < 2){
							dem++;
							gotoxy(LEFTX + (160-LEFTX)*2/5 + 5, LEFTY + 5 + chonDiemNhap * 2);
							arrDiemNhap[dem] = kyTuNhap;
							XuatDiem(arrDiemNhap, dem);
						}
					}
				}
				else if(qq == 13){
					int diemDangChon = selectedIndexDiem + trangDiemHienTai * 16;
					DSDiemSV[diemDangChon].ChuyenCan = diemCC;
					DSDiemSV[diemDangChon].GiuaKy = diemGK;
					DSDiemSV[diemDangChon].CuoiKy = diemCK;
					if(DSDiemSV[diemDangChon].ChuyenCan != 0 && DSDiemSV[diemDangChon].GiuaKy != 0 && DSDiemSV[diemDangChon].CuoiKy != 0){
						DSDiemSV[diemDangChon].TBM = (float)(10*DSDiemSV[diemDangChon].ChuyenCan + 20*DSDiemSV[diemDangChon].GiuaKy + 70*DSDiemSV[diemDangChon].CuoiKy)/100;
					}
					gotoxy(LEFTX + 30, LEFTY -1); cout << "Da cap nhat Diem thanh cong! Nhan ESC de quay ve danh sach Diem!";
					GhiFileDanhSachDiem(DSDiemSV, demDiemSV, lop.Idlop, monHoc.monhocID);
					SuaDanhSachDiem(TreeDiem, DSDiemSV, demDiemSV);
					GhiFileTreeDiem(TreeDiem);
				}
			}
			qq = '0';
		}
		else if(qq == 83){
			gotoxy(LEFTX + 30, LEFTY -1); cout << "Ban co chac chan muon xoa Diem cua Sinh Vien nay khong? ENTER: Yes | ESC: No";
			qq = 0;
			while(qq != 27){
				qq = getch();
				if(qq == 13){
					DSDiemSV[selectedIndexDiem].ChuyenCan = 0;
					DSDiemSV[selectedIndexDiem].GiuaKy = 0;
					DSDiemSV[selectedIndexDiem].CuoiKy = 0;
					DSDiemSV[selectedIndexDiem].TBM = 0;
					gotoxy(LEFTX + 30, LEFTY -1); cout << "Da xoa Diem thanh cong!";
					GhiFileDanhSachDiem(DSDiemSV, demDiemSV, lop.Idlop, monHoc.monhocID);
					SuaDanhSachDiem(TreeDiem, DSDiemSV, demDiemSV);
					GhiFileTreeDiem(TreeDiem);
					break; 
				}			
			}
			qq = '0';
			gotoxy(LEFTX + 30, LEFTY -1); cout << "                                                                           ";
		}
	}
}

bool TimKhoaHocTheoLop(LopHoc lop, KhoaHoc khoaHocArr[], int demKH, KhoaHoc &kh){
	for(int i = 0; i < demKH; i++){
		if(strcmp(khoaHocArr[i].khoahocID,lop.Idkhoahoc) == 0){
			kh = khoaHocArr[i];
			return true;
		}
	}
	return false;
}

void TimMonHocThuocKhoaHoc(char khoaHocId[], ChiTietKhoaHoc ctkhArr[], int demCTKH, MonHoc monHocArr[], int demMH, MonHoc monHoc[]){
	int dem = 0;
	//int soLuong = demMHinKH(khoaHocId,ctkhArr,demCTKH);
	for(int i = 0; i < demCTKH; i++){
		if(strcmp(ctkhArr[i].khoahocID, khoaHocId) == 0){
			for(int k = 0; k < demMH; k++){
				if(strcmp(ctkhArr[i].monhocID, monHocArr[k].monhocID) == 0){					
					monHoc[dem] = monHocArr[k];
					dem++;
					break;
				}				
			}
		}
	}
}

void ThaoTacShowMonCuaLop(LopHoc lop, PtrDiem &TreeDiem){
	//Lay Danh Sach Mon Hoc
	PTRMONHOC DSMH = NULL;
	DocFileMonHoc(DSMH);
	int demMHFull = DemMonHoc(DSMH);
	int ccMH=0;	
	MonHoc monHocArrFull[demMHFull];
	MangTam_MonHoc(DSMH,monHocArrFull,ccMH);
	
	//Lay Danh Sach Chi Tiet Khoa Hoc
	int ccCTKH = 0;
	int demCTKH = 0;
	demMHAddKhoa(demCTKH);
	ChiTietKhoaHoc ctkhArr[demCTKH];
	ToArrK(ctkhArr, ccCTKH);
	
	//Lay Danh Sach Mon Hoc Cua Lop
	
	int demMH = demMHinKH(lop.Idkhoahoc,ctkhArr,demCTKH);
	MonHoc monHocArr[demMH];
	TimMonHocThuocKhoaHoc(lop.Idkhoahoc, ctkhArr, demCTKH, monHocArrFull, demMHFull, monHocArr);
	
	string lopHoc = lop.Namelop;
	char qq = '0';
	int trangMHHienTai = 0, trangMH = 0, selectedIndexMH = 0, sttMHTruyen;
	while(qq!=27){
		if(qq =='0' || trangMHHienTai != trangMH){			
			trangMHHienTai = trangMH;
			if((demMH - trangMH * 16) > 16) sttMHTruyen = 16;
			else sttMHTruyen = demMH - trangMH * 16;
			ShowMonCuaLop(monHocArr, demMH, trangMH*16 + 1, trangMH * 16 + sttMHTruyen, lop);
			selectedIndexMH = 0;
			gotoxy(LEFTX + 5, LEFTY + 3 + (selectedIndexMH * 2));
		}
		
		qq = getch();
		if(demMH > 16 && qq == 75 && trangMH > 0){
			trangMH -= 1;
		}
		else if(demMH > 16 && qq == 77){
			if((demMH - (trangMH * 16)) > 16) trangMH += 1;
		}
		else if(qq == 72){
			if(selectedIndexMH > 0) selectedIndexMH -= 1;
			gotoxy(LEFTX + 5, LEFTY + 3 + (selectedIndexMH * 2));
		}
		else if(qq == 80){
			if(selectedIndexMH < sttMHTruyen-1) selectedIndexMH += 1;
			gotoxy(LEFTX + 5, LEFTY + 3 + (selectedIndexMH * 2));
		}
		else if (qq == 13){
			if(demMH > 0){
				HamNhapDiem(lop, monHocArr[selectedIndexMH + (trangMH * 16)], TreeDiem);	
			}
			ShowMonCuaLop(monHocArr, demMH, trangMH*16 + 1, trangMH * 16 + sttMHTruyen, lop);
		}
	}
}

void ThaoTacShowLop(PtrDiem &TreeDiem){
	TextColor(255);
	SetBGColor(1);
	//Lay Danh Sach Lop
	PTRLOP DSLOP = NULL;
	DocFileLop(DSLOP);
	int demL = DemLopHoc(DSLOP);
	int ccL=0;
	LopHoc lopArr[demL];
	MangTam_Lop(DSLOP,lopArr,ccL);
	
	//Lay DS all Sinh Vien
	TREE tree;
	initEmpty(tree);
	docAllFile(tree);
	int demSVAll = countSV(tree);
	int ccSV = 0;
	SinhVien DSSVAll[demSVAll];
	listTampAllSV(tree,DSSVAll,ccSV);
	
	char qq = '0';
	int trangLopHienTai = 0, trangLop = 0, selectedIndexLop = 0, sttLopTruyen;
	int trangMHHienTai = 0, trangMH = 0, selectedIndexMH = 0, sttMHTruyen;
	while(qq!=27){
		if(qq =='0' || trangLopHienTai != trangLop){			
			trangLopHienTai = trangLop;
			if((demL - trangLop * 16) > 16) sttLopTruyen = 16;
			else sttLopTruyen = demL - trangLop * 16;
			ShowLopDiem(lopArr, trangLop*16 + 1, trangLop * 16 + sttLopTruyen);
			selectedIndexLop = 0;
			gotoxy(LEFTX + 5, LEFTY + 3 + (selectedIndexLop * 2));
		}
		
		qq = getch();
		if(demL > 16 && qq == 75 && trangLop > 0){
			trangLop -= 1;
		}
		else if(demL > 16 && qq == 77){
			if((demL - (trangLop * 16)) > 16) trangLop += 1;
		}
		else if(qq == 72){
			if(selectedIndexLop > 0) selectedIndexLop -= 1;
			gotoxy(LEFTX + 5, LEFTY + 3 + (selectedIndexLop * 2));
		}
		else if(qq == 80){
			if(selectedIndexLop < sttLopTruyen-1) selectedIndexLop += 1;
			gotoxy(LEFTX + 5, LEFTY + 3 + (selectedIndexLop * 2));
		}
		else if (qq == 13){
			int checkLop = demSVTrongLop(DSSVAll, lopArr[selectedIndexLop + (trangLop * 16)].Idlop, demSVAll);
			if(checkLop > 0){
				ThaoTacShowMonCuaLop(lopArr[selectedIndexLop + (trangLop * 16)], TreeDiem);			
				ShowLopDiem(lopArr, trangLop*16 + 1, trangLop * 16 + sttLopTruyen);		
			}			
		}
	}
}

void DemDSDiemSinhVien(PtrDiem TreeDiem, string maSV,int &demDiem){
	if (TreeDiem!=NULL)
	{
		if(strcmp(TreeDiem->Diem.maSinhVien, maSV.c_str()) == 0){
			demDiem++;
		}		
		DemDSDiemSinhVien(TreeDiem->Left,maSV,demDiem);
		DemDSDiemSinhVien(TreeDiem->Right,maSV,demDiem);
	}
}

void DSDiemSinhVien(PtrDiem TreeDiem, string maSV, DiemSV DSDiem[], int demDiem){
	if (TreeDiem!=NULL)
	{
		if(strcmp(TreeDiem->Diem.maSinhVien, maSV.c_str()) == 0){
			DSDiem[demDiem] = TreeDiem->Diem;
			demDiem++;
		}		
		DSDiemSinhVien(TreeDiem->Left,maSV, DSDiem,demDiem);
		DSDiemSinhVien(TreeDiem->Right,maSV, DSDiem,demDiem);
	}
}

string TimTenMonHoc_Phu(PTRMONHOC TreeMH, string idMon){
	if(TreeMH == NULL) return "Loi";
	else {
		if(strcmp(TreeMH->data.monhocID, idMon.c_str())==0){
			return TreeMH->data.Namemonhoc;
		}
		TimTenMonHoc_Phu(TreeMH->left, idMon);
		TimTenMonHoc_Phu(TreeMH->right, idMon);
	}	
}

string TimTenMonHoc(string idMon){
	PTRMONHOC DSMH = NULL;
	DocFileMonHoc(DSMH);
	int demMHFull = DemMonHoc(DSMH);
	int ccMH=0;	
	MonHoc monHocArrFull[demMHFull];
	MangTam_MonHoc(DSMH,monHocArrFull,ccMH);
	for(int i = 0; i < demMHFull; i++){
		if(strcmp(monHocArrFull[i].monhocID, idMon.c_str()) == 0){
			return monHocArrFull[i].Namemonhoc;
		}
	}
}

void ShowDiemSV(DiemSV *SV, int bd, int kt){
	system("cls");
	int RIGHTX = 160; 
	int RIGHTY = LEFTY + (kt - bd + 2) * 2;// Phai chia het cho 3
	
	int kcSTT = 4;
	int khoangCachCot = (RIGHTX-kcSTT)/6;
	
	gotoxy((RIGHTX-LEFTX)/2 - 10, LEFTY-4); ; cout<< "DANH SACH DIEM CUA SINH VIEN";
	gotoxy((RIGHTX-LEFTX)/4 + 20, LEFTY-2); ; cout<< "MA SV: " << SV[bd-1].maSinhVien << "       "<<"TEN SV: " << SV[bd-1].tenSinhVien;
	
	//BoderTop 0-160
	gotoxy(LEFTX,LEFTY); cout << char(218) << setw(RIGHTX-LEFTX) << setfill(char(196)) << char(191);
	
	//BoderLeft
	for(int i = LEFTY+1; i < RIGHTY; i++){
		gotoxy(LEFTX, i); cout<<char(179);
	}
	
	//BoderBottom	
	gotoxy(LEFTX,RIGHTY); cout << char(192) << setw(RIGHTX-LEFTX) << setfill(char(196)) << char(217);
	
	//BoderRight
	for(int i = LEFTY+1; i < RIGHTY; i++){
		gotoxy(RIGHTX, i); cout<<char(179);
	}
	
	//Cot Ngang tieu de
	gotoxy(LEFTX+1, LEFTY+2); cout << setw(RIGHTX-LEFTX-1) << setfill(char(196)) << char(196);
	
	// n dong
	int n = kt - bd + 1;
	for(int i = bd; i <= kt; i++){
		int ndongy = LEFTY + 2 + (i-bd)*2;
		if(ndongy > RIGHTY){
			break;
		}
		gotoxy(LEFTX + 1, ndongy + 1); cout << i; // Show STT
		gotoxy(LEFTX+1, ndongy); cout << setw(RIGHTX-LEFTX-1) << setfill(char(196)) << char(196);
		
		gotoxy(kcSTT + 0*khoangCachCot + 1, ndongy + 1); cout << SV[i-1].monhocID; // Show thong tin
		string tenMon = TimTenMonHoc(SV[i-1].monhocID);
		gotoxy(kcSTT + 1*khoangCachCot + 1, ndongy + 1); cout << tenMon;
		gotoxy(kcSTT + 2*khoangCachCot + 1, ndongy + 1); cout << SV[i-1].ChuyenCan;
		gotoxy(kcSTT + 3*khoangCachCot + 1, ndongy + 1); cout << SV[i-1].GiuaKy;
		gotoxy(kcSTT + 4*khoangCachCot + 1, ndongy + 1); cout << SV[i-1].CuoiKy;
		gotoxy(kcSTT + 5*khoangCachCot + 1, ndongy + 1); cout << SV[i-1].TBM;
	}
	
	//STT
	gotoxy(LEFTX+1, LEFTY+1); cout << "STT";
	for(int j = LEFTY+1; j < RIGHTY; j++)
	{
		gotoxy(LEFTX+kcSTT, j); cout << char(179);
	}
	
	
	gotoxy(kcSTT + 0*khoangCachCot + 1, LEFTY+1); cout << "MA MON HOC";
	gotoxy(kcSTT + 1*khoangCachCot + 1, LEFTY+1); cout << "TEN MON HOC";
	gotoxy(kcSTT + 2*khoangCachCot + 1, LEFTY+1); cout << "CHUYEN CAN";
	gotoxy(kcSTT + 3*khoangCachCot + 1, LEFTY+1); cout << "GIUA KY";
	gotoxy(kcSTT + 4*khoangCachCot + 1, LEFTY+1); cout << "CUOI KY";
	gotoxy(kcSTT + 5*khoangCachCot + 1, LEFTY+1); cout << "TBM";
	// 6 cot doc
	for(int i =0; i < 5; i++){
		for(int j = LEFTY+1; j < RIGHTY; j++)
		{
			gotoxy(kcSTT + i*khoangCachCot+khoangCachCot, j); cout << char(179);
		}
	}
	gotoxy(LEFTX, RIGHTY+2); cout << setw(34) <<" UP, DOWN: Chon Sinh Vien " << setw(35)<<" LEFT, RIGHT: Chuyen trang " << setw(20)<<" ESC: Thoat ";	
}

void ThaoTacShowDiemCua1SV(PtrDiem TreeDiem){
	TextColor(255);
	SetBGColor(1);
	string maSV;
	gotoxy(75, 17); cout << "Nhap Ma Sinh Vien: ";
	getline(cin,maSV);
	int demDiem = 0;
	DemDSDiemSinhVien(TreeDiem, maSV,demDiem);
	DiemSV DSDiem[demDiem];
	int dem = 0;
	DSDiemSinhVien(TreeDiem, maSV, DSDiem, dem);
	if(demDiem == 0){
		gotoxy(75, 19); cout << "Sinh Vien chua co diem! Hoac sai Ma Sinh Vien!";
		getch();
		return;
	}
	char qq = '0';
	int trangDiemHienTai = 0, trangDiem = 0, selectedIndexDiem = 0, sttDiemTruyen;
	while(qq!=27){
		if(qq =='0' || trangDiemHienTai != trangDiem){			
			trangDiemHienTai = trangDiem;
			if((demDiem - trangDiem * 16) > 16) sttDiemTruyen = 16;
			else sttDiemTruyen = demDiem - trangDiem * 16;
			ShowDiemSV(DSDiem, trangDiem*16 + 1, trangDiem * 16 + sttDiemTruyen);
			selectedIndexDiem = 0;
			gotoxy(LEFTX + 5, LEFTY + 3 + (selectedIndexDiem * 2));
		}
		
		qq = getch();
		if(demDiem > 16 && qq == 75 && trangDiem > 0){
			trangDiem -= 1;
		}
		else if(demDiem > 16 && qq == 77){
			if((demDiem - (trangDiem * 16)) > 16) trangDiem += 1;
		}
		else if(qq == 72){
			if(selectedIndexDiem > 0) selectedIndexDiem -= 1;
			gotoxy(LEFTX + 5, LEFTY + 3 + (selectedIndexDiem * 2));
		}
		else if(qq == 80){
			if(selectedIndexDiem < sttDiemTruyen-1) selectedIndexDiem += 1;
			gotoxy(LEFTX + 5, LEFTY + 3 + (selectedIndexDiem * 2));
		}
	}
}

typedef char str[75];
str ThaoTac[3] = {
	"Nhap/Sua Diem Theo Lop va Mon" ,
	"Xem Diem Cua 1 Sinh Vien" ,
	"Ve trang chu"
};

int ShowMenuTienDo(){	
	TextColor(255);
	SetBGColor(1);
	system("cls");
	int LEFTXX = 60, LEFTYY = 5, RIGHTX = 110, RIGHTY = 13;
	//BoderTop 0-160
	gotoxy(LEFTXX,LEFTYY); cout << char(201) << setw(RIGHTX-LEFTXX) << setfill(char(205)) << char(187);
	gotoxy(LEFTXX,LEFTYY+2); cout << setw(RIGHTX-LEFTXX) << setfill(char(205)) << char(205);
	
	//BoderLeft
	for(int i = LEFTYY+1; i < RIGHTY; i++){
		gotoxy(LEFTXX, i); cout<<char(186);
	}
	
	//BoderBottom
	gotoxy(LEFTXX,RIGHTY); cout << char(200) << setw(RIGHTX-LEFTXX) << setfill(char(205)) << char(188);
	
	//BoderRight
	for(int i = LEFTYY+1; i < RIGHTY; i++){
		gotoxy(RIGHTX, i); cout<<char(186);
	}
	gotoxy(LEFTXX + 20, LEFTYY + 1); cout << "MENU DIEM";
	
	int tt=0, z = 0, n = 3;
	int mau[3];
	
	while(1){
		for(int i=0; i<3; i++) mau[i] = 0; 
		mau[tt] = 255;
		for(int i=0; i<n;i++)
		{
			gotoxy(LEFTXX + 5, LEFTYY + 4 + i);
			SetColor(mau[i]);
			cout<<"  "<<i+1<<". " <<ThaoTac[i]<<endl;
		}
		while(z!=72 && z!=80 && z!=13)
		{
			z = getch();		
		}
		switch(z)
		{
			case 72:{
				tt--;
				if(tt<0) tt= n-1;
				break;
			}
			case 80: {
				tt++; 
				if(tt>n-1) tt=0;
				break;
			}
			case 13: return tt;
		} z=0;
	}
	
}

