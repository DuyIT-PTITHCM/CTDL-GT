#include "Models.h"
#include <iostream>
#include <string> 
#include <iomanip>
#define LEFTX 0
#define LEFTY 5



void AddTreeDiem(PtrDiem &TreeDiem, DiemSV diem){	
	if(TreeDiem!=NULL)
	{
		if (strcmp(TreeDiem->Diem.maSinhVien, diem.maSinhVien) < 0)
			AddTreeDiem(TreeDiem->Left, diem);
		else
			AddTreeDiem(TreeDiem->Right, diem);
	}
	else
	{
		TreeDiem = new NodeDiem;
		TreeDiem->Diem = diem;
		TreeDiem->Left = NULL;
		TreeDiem->Right = NULL;
	}
}
void CheckDiemSinhVien(PtrDiem TreeDiem, string maSV, int &dem){
	if(TreeDiem == NULL) return;
	else
	{
		if(strcmp(TreeDiem->Diem.maSinhVien, maSV.c_str()) == 0){
			dem++;
			return;
		}	
		CheckDiemSinhVien(TreeDiem->Left, maSV, dem);
		CheckDiemSinhVien(TreeDiem->Right, maSV, dem);
	}
}


void DocFileTreeDiem(PtrDiem &tree){
	string tenFile = "DiemSinhVien.txt";
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



bool CheckDiemXoaSinhVien(string maSV){
	PtrDiem TreeDiem;
	TreeDiem = NULL;
	DocFileTreeDiem(TreeDiem);
	int abc = 0;
	CheckDiemSinhVien(TreeDiem, maSV, abc);
	if(abc == 0) return false;
	else return true;
}






