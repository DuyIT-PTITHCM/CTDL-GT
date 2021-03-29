#include"Diem.h"

void showMonTheoKhoaNe(char maKH[],char nameMonNha[],int &check){
	MonHoc *monHocNha;
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

	int k =0;
	if(soLuong==0){
		xoaManHinhShowCN();
		return;
	}else{
			monHocNha = new MonHoc[soLuong];
			for(int i = 0 ; i <sizen; i++){
				if(strcmp(ctkh[i].khoahocID,maKH)==0){
					for(int j= 0 ; j< dem ; j++){
						if(strcmp(ctkh[i].monhocID,mh[j].monhocID)==0){

							if(k<soLuong){
									strcpy((monHocNha+k)->monhocID , mh[j].monhocID);
									strcpy((monHocNha+k)->Namemonhoc , mh[j].Namemonhoc);
	
									k++;
							}
						
						}
					}
				}
		
	}
	}
	
	
	if(soLuong>0){
							for(int j= 0 ; j< dem ; j++){
							gotoxy(81,7+nhay);
							SetBGColor(11);
							cout<<"                                               ";
							gotoxy(81,7+nhay);
							cout<<"          "<<(monHocNha+j)->Namemonhoc;
							nhay++;
							

					}
					
					
				
		int index = 0;
		gotoxy(81,7);
		SetBGColor(9);
		cout<<"                                               ";
		gotoxy(81,7);
		cout<<"          "<<(monHocNha+0)->Namemonhoc;
	
	char chon = getch();
	
	while(chon){
		if(chon ==72 || chon ==80){
			xoaTB();
			gotoxy(2,20);
			SetBGColor(9);
			cout<<"     ENTER de xem KQ SV theo Mon ";
			if(chon == 72 && index>0){
				index=index-1;
			}else if(chon==80 && index<soLuong-1){
				index=index+ 1;
			}
			
				//xu ly di chuen phim muoi ten
			
		}else if(chon ==13){
			xoaTB();
			xoaManHinhShowCN();
			
			// lay ten lop ung voi tai vi tri chon
			strcpy(nameMonNha,(monHocNha+index)->monhocID);
			
			break;
			
		}else if(chon==27){
			xoaManHinhShowCN();
			check = 1;
			break;
		}
		//---------------------day la xu ly mau cho dep------------------//
			for(int i =7 ; i < soLuong+7; i ++){
					if(i==index+7){
						gotoxy(81,i);
						SetBGColor(9);
						cout<<"                                               ";
						gotoxy(81,i);
						cout<<"         "<<(monHocNha+i-7)->Namemonhoc;
					}else{
						gotoxy(81,i);
						SetBGColor(11);
						cout<<"                                               ";
						gotoxy(81,i);
						cout<<"         "<<(monHocNha+i-7)->Namemonhoc;
					}
					
				}
		gotoxy(48,index+7);
		chon = getch();
	}
}
	
	

}
// show lop va them sinh vien vao		
void showLopA(char ahihi[],char lopNuaAhihi[],int &check){

	gotoxy(45,4);
	SetBGColor(111);
	cout << char(218) << setw(30) << setfill(char(196)) << char(191);
	
	for(int i = 5; i < 41; i++){
		gotoxy(45,i);
		cout << char(179);
		gotoxy(75,i);
		cout << char(179);
		gotoxy(46,i);
		cout<<"                             ";
		
	}
	
	gotoxy(45,40);
	cout << char(192) << setw(30) << setfill(char(196)) << char(217);
	//x ong cai khung hop 
	gotoxy(46,6);
	cout <<  setw(30) << setfill(char(196)) <<char(196);
		gotoxy(46,5);
		cout<<"          MA LOP     ";
			
	//---------------------------------- bat dau tu  7
	PTRLOP DSLOP = NULL;
	DocFileLop(DSLOP);
	int dem =DemLopHoc(DSLOP);
	int cc=0,nhay = 7;
	LopHoc *lop = new LopHoc[100];
	MangTam_Lop(DSLOP,lop,cc);
	// render du lieu ra thoi nao
	for(int i = 0 ; i <dem; i++){
		
		gotoxy(46,7+i);
		SetBGColor(11);
		cout<<"          "<<lop[i].Idlop<<"        ";
	}
	//end render
	int index = 0;
		gotoxy(46,nhay);
		SetBGColor(9);
		cout<<"                             ";
		gotoxy(46,nhay);
		cout<<"          "<<lop[0].Idlop;
	
	char chon = getch();
	
	while(chon){
		if(chon ==72 || chon ==80){
			xoaTB();
			gotoxy(2,20);
			SetBGColor(9);
			cout<<"     ENTER de them xem ket qua sv lop ";
			if(chon == 72 && index>0){
				index=index-1;
			}else if(chon==80 && index<dem-1){
				index=index+ 1;
			}
			
				//xu ly di chuen phim muoi ten
			
		}else if(chon ==13){
			xoaTB();
			xoaManHinhShowCN();
			char nameFileTampClass[200] ;
			// lay ten lop ung voi tai vi tri chon
			strcpy(nameFileTampClass,lop[index].Idkhoahoc);
			//goi den khung them va do du lieu a lop ra do 
//			khungThem(tree,phanQuyen,xx,nameFileTampClass);
			strcpy(ahihi,nameFileTampClass);
			strcpy(lopNuaAhihi,lop[index].Idlop);
			break;
			
		}else if(chon==27){
			xoaManHinhShowCN();
			check = 1;
			break;
		}
		//---------------------day la xu ly mau cho dep------------------//
			for(int i =7 ; i < dem+7; i ++){
					if(i==index+7){
						gotoxy(46,i);
						SetBGColor(9);
						cout<<"                             ";
						gotoxy(46,i);
						cout<<"         "<<lop[i-7].Idlop;
					}else{
						gotoxy(46,i);
						SetBGColor(11);
						cout<<"                             ";
						gotoxy(46,i);
						cout<<"         "<<lop[i-7].Idlop;
					}
					
				}
		gotoxy(48,index+7);
		chon = getch();
	}
	

}
//end show lop va them sinh vien vao 

void khungThongKe(DiemSV *DSDiemSV,int size,int ofset){
	int demYeu = 0 , demTB = 0 , demKha = 0 , demGioi = 0;
	gotoxy(72,4);
			SetBGColor(111);
			cout << char(218) << setw(104) << setfill(char(196)) << char(191);
			for(int i = 5; i < 35; i++){
				gotoxy(72,i);
				cout << char(179);
				gotoxy(176,i);
				cout << char(179);
				gotoxy(73,i);
				cout<<"                                                                                                       ";
				
			}
			gotoxy(72,35);
			cout << char(192) << setw(104) << setfill(char(196)) << char(217);
			gotoxy(73,6);
			cout <<  setw(102) << setfill(char(196)) <<char(196);
				gotoxy(73,5);
				cout<<"  MA SO SINH VIEN  ";
				gotoxy(93,5);
				cout << char(179);
				cout<<"  TEN SINH VIEN  ";
				gotoxy(113,5);
				cout << char(179);
				cout<<"  TRUNG BINH MON  ";
				gotoxy(133,5);
				cout << char(179);
				cout<<"  KET QUA   ";		
			//---------------------------------- bat dau tu  7
			int j = 7;
			for(int i = ofset *20 ; i <size; i++){
						SetBGColor(15);
						gotoxy(73,j);
						cout<<"  "<<(DSDiemSV+i)->maSinhVien;
						gotoxy(93,j);
						cout << char(179);
						cout<<" "<<(DSDiemSV+i)->tenSinhVien;
						gotoxy(113,j);
						cout << char(179);
						cout<<"     "<<(DSDiemSV+i)->TBM;
						gotoxy(133,j);
						cout << char(179);
						if((DSDiemSV+i)->TBM<4){
								
								cout<<"   YEU   ";

						}else if((DSDiemSV+i)->TBM<6){
							
							cout<<"Trung Binh";
						}else if((DSDiemSV+i)->TBM<8){
						
							cout<<"    KHA    ";
						}else{
						
							cout<<"  GIOI   ";
						}
					

						if(ofset*20+19==i){
							break;
						}
						j++;
					
}
			for(int i = 0 ; i <size; i++){
						
						if((DSDiemSV+i)->TBM<4){
								demYeu++;
						}else if((DSDiemSV+i)->TBM<6){
							demTB++;
						}else if((DSDiemSV+i)->TBM<8){
							demKha++;
						}else{
							demGioi++;
						}
	
					
}
				gotoxy(140,37);
				SetBGColor(4);
				cout<<" THONG KE KET QUA CHUNG CUA LOP  ";
				SetBGColor(11);
				gotoxy(140,38);
				cout<<"SINH VIEN YEU CHIEM TY LE  :"<<demYeu<<"/"<<size;
				gotoxy(140,39);
				cout<<"SINH VIEN TB CHIEM TY LE   :"<<demTB<<"/"<<size;
				gotoxy(140,40);
				cout<<"SINH VIEN KHA CHIEM TY LE  :"<<demKha<<"/"<<size;
				gotoxy(140,41);
				cout<<"SINH VIEN GIOI CHIEM TY LE :"<<demGioi<<"/"<<size;
}
void thongKe(char Idlop[], char monhocID[],int &check){
	
	TREE tree;
	initEmpty(tree);
	docAllFile(tree);
	int demSVAll = countSV(tree);
	int ccSV = 0;
	SinhVien DSSVAll[demSVAll];
	listTampAllSV(tree,DSSVAll,ccSV);
	
	//Lay Danh Sach Sinh Vien Cua Lop
	int demDiemSV = demSVTrongLop(DSSVAll, Idlop, demSVAll);
	DiemSV DSDiemSV[demDiemSV];
	int checkDiem = DocFileDanhSachDiem(DSDiemSV,Idlop, monhocID);
	xoaManHinhShowCN();
	if(checkDiem>0){
		int page = checkDiem/20,indexPage = 0;
	khungThongKe(DSDiemSV,checkDiem,0);
			
//------------------->>Phan Trang O day nha <<---------------------------------------//		
		for(int i = 0; i< page+1; i ++){
			if(i == indexPage){
				gotoxy(100+5*i+i,36);
				SetBGColor(9);
				cout << char(218) << setw(5) << setfill(char(196)) << char(191);
				gotoxy(100+5*i+i,37);
				cout << char(179)<<" "<<i+1<<"  ";
				gotoxy(100+5*i+5+i,37);
				cout <<char(179);
				gotoxy(100+5*i+i,38);
				cout << char(192) << setw(5) << setfill(char(196)) << char(217);
			}else{
				gotoxy(100+5*i+i,36);
				SetBGColor(15);
				cout << char(218) << setw(5) << setfill(char(196)) << char(191);
				gotoxy(100+5*i+i,37);
				cout << char(179)<<" "<<i+1<<"  ";
				gotoxy(100+5*i+5+i,37);
				cout << char(179);
				gotoxy(100+5*i+i,38);
				cout << char(192) << setw(5) << setfill(char(196)) << char(217);
			}
			
		}
	gotoxy(2,20);
	SetBGColor(10);
	cout<<"      Di chuyen <- -> de qua trang    ";
	
	gotoxy(2,21);
	SetBGColor(11);
	cout<<"ENTER DE QUAY LAI ";
	gotoxy(2,22);
	SetBGColor(4);
	cout<<"ESC DE THOAT ";
	char chon = getch();

	
	while(chon){
	 if((chon == 75 || chon == 77 ) && 10>0){
			if(chon == 75&& indexPage>0){
				indexPage -=1;
			}else if(chon ==77 && indexPage <page){
				indexPage +=1;
			}
			for(int i = 0; i< page+1; i ++){
				if(i == indexPage){
				gotoxy(100+5*i+i,36);
				SetBGColor(9);
				cout << char(218) << setw(5) << setfill(char(196)) << char(191);
				gotoxy(100+5*i+i,37);
				cout << char(179)<<" "<<i+1<<"  ";
				gotoxy(100+5*i+5+i,37);
				cout <<char(179);
				gotoxy(100+5*i+i,38);
				cout << char(192) << setw(5) << setfill(char(196)) << char(217);
			}else{
				gotoxy(100+5*i+i,36);
				SetBGColor(15);
				cout << char(218) << setw(5) << setfill(char(196)) << char(191);
				gotoxy(100+5*i+i,37);
				cout << char(179)<<" "<<i+1<<"  ";
				gotoxy(100+5*i+5+i,37);
				cout << char(179);
				gotoxy(100+5*i+i,38);
				cout << char(192) << setw(5) << setfill(char(196)) << char(217);
			}
			
			
		}//end cua vong for
		
		
			xoaSVKhoa();
			khungThongKe(DSDiemSV,checkDiem,indexPage);
		
		}else if(chon==27){
			xoaIconPhanTrang(5);
			xoaSVKhoa();
			xoaTB();
			check=1;
			break;
		}else if(chon ==13){
			xoaManHinhShowCN();
			check= 0;
			break;
		}
		chon = getch();
	}
	}else{
		gotoxy(2,20);
		cout<<"chua nhap diem hoac chua co sinh vien ";
		gotoxy(2,21);
		SetBGColor(4);
		cout<<"   An bat ki de tiep tuc";
		gotoxy(2,22);
		SetBGColor(20);
		cout<<"   An ESC de thoat";
		SetBGColor(15);
	}
	

	
}
void thongKeKQSV(){
	gotoxy(40,1);
	SetBGColor(4);
	cout<<"                                                    THONG KE KET QUA SINH VIEN THEO LOP THEO TUNG MON HOC                                     ";
	SetBGColor(15);
	PTRLOP DSLOP = NULL;
	DocFileLop(DSLOP);
	int demK =DemLopHoc(DSLOP);
	int ccK=0,count = 0;
	LopHoc lop[demK];
	MangTam_Lop(DSLOP,lop,ccK);
	
	PTRMONHOC DSMH = NULL;
	DocFileMonHoc(DSMH);
	int dem =DemMonHoc(DSMH);
	int cc=0;
	
	MonHoc *mh = new MonHoc[100];
	MangTam_MonHoc(DSMH,mh,cc);
	char fileLopChon[12],monChonNe[10],lopNuaAhihi[200];
	int check = 0;
	while(1){
		showLopA(fileLopChon,lopNuaAhihi,check);
			if(check == 1){
			break;
		}
		showMonTheoKhoaNe(fileLopChon,monChonNe,check);
			if(check == 1){
			break;
		}
		thongKe(lopNuaAhihi,monChonNe,check);
		if(check == 1){
			break;
		}
	}
	
	
}
