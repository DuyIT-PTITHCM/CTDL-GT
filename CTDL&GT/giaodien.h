#include"logicSinhVien.h"
#include"diemqq.h"
//xoa man hinh show cn
void xoaManHinhShowCN(){
	gotoxy(40,3);
	SetBGColor(14);
	for(int i = 3;i<43;i++){
		
		gotoxy(41,i);
		cout<<"                                                                                                                                            ";
	}
}
//end xoa man hinh show chuc nang 

//khung xoa 
void xoa(TREE &tree,char maSinhVienXoa[]){
	//lam gi lam ve cai khung cai da
		gotoxy(90,6);
		SetBGColor(7);
		cout << char(218) << setw(50) << setfill(char(196)) << char(191);
		
		for(int i = 7; i < 13; i++){
		gotoxy(90,i);
		cout << char(179);
		gotoxy(140,i);
		cout << char(179);
		gotoxy(91,i);
		cout<<"                                                 ";
		
	}
	
	gotoxy(90,13);
	cout << char(192) << setw(50) << setfill(char(196)) << char(217);
	
	gotoxy(98,7);
	cout<<"BAN CO CHAC CHAN MUON XOA KHONG";
	//hight light thang co  len
	gotoxy(100,8);
	SetBGColor(9);
	cout << char(218) << setw(10) << setfill(char(196)) << char(191);
	gotoxy(100,9);
	cout << char(179)<<"   CO     ";
	gotoxy(110,9);
	cout << char(179);
	gotoxy(100,10);
	cout << char(192) << setw(10) << setfill(char(196)) << char(217);
	//-------------------------------------------
	gotoxy(115,8);
	SetBGColor(7);
	cout << char(218) << setw(10) << setfill(char(196)) << char(191);
	gotoxy(115,9);
	cout << char(179)<<"  KHONG    ";
	gotoxy(125,9);
	cout << char(179);
	gotoxy(115,10);
	cout << char(192) << setw(10) << setfill(char(196)) << char(217);
	char  chon = getch();
	int tamp = 110;
	
	while(chon){
		if(chon == 75 || chon == 77){
			if(chon == 75 && tamp >110){
				tamp -= 5;
			}else if(chon== 77 && tamp <115){
				tamp+=5;
			}
			//-dua tat ca ve mac dinh--------
			gotoxy(100,8);
			SetBGColor(7);
			cout << char(218) << setw(10) << setfill(char(196)) << char(191);
			gotoxy(100,9);
			cout << char(179)<<"   CO    ";
			gotoxy(110,9);
			cout << char(179);
			gotoxy(100,10);
			cout << char(192) << setw(10) << setfill(char(196)) << char(217);
			//------------------------
			gotoxy(115,8);
			SetBGColor(7);
			cout << char(218) << setw(10) << setfill(char(196)) << char(191);
			gotoxy(115,9);
			cout << char(179)<<"  KHONG   ";
			gotoxy(125,9);
			cout << char(179);
			gotoxy(115,10);
			cout << char(192) << setw(10) << setfill(char(196)) << char(217);
			// end dua ve mac dinh
			//--hight light cai nguoi dung tuong tac len
			if(tamp==110){
			gotoxy(100,8);
			SetBGColor(9);
			cout << char(218) << setw(10) << setfill(char(196)) << char(191);
			gotoxy(100,9);
			cout << char(179)<<"   CO    ";
			gotoxy(110,9);
			cout << char(179);
			gotoxy(100,10);
			cout << char(192) << setw(10) << setfill(char(196)) << char(217);
		}else if(tamp ==115){
			gotoxy(115,8);
			SetBGColor(9);
			cout << char(218) << setw(10) << setfill(char(196)) << char(191);
			gotoxy(115,9);
			cout << char(179)<<"  KHONG   ";
			gotoxy(125,9);
			cout << char(179);
			gotoxy(115,10);
			cout << char(192) << setw(10) << setfill(char(196)) << char(217);
		}
		}
		//bat su kien cho enter	
		else if(chon==13){
			if(tamp==110){
				//kiem tra  xem da nhap diem cho sinh vien nay chua
				bool check = CheckDiemXoaSinhVien(maSinhVienXoa);
				if(!check){
					xoaNodeFromTree(maSinhVienXoa,tree);
					gotoxy(2,20);
					cout<<"Xoa Thanh Cong Roi Nha ";
					xoaManHinhShowCN();
				}else{
					xoaTB();
					gotoxy(2,20);
					cout<<"Sinh Vien Da Nhap Diem Khong Duoc Xoa";
					xoaManHinhShowCN();
				}
					
					break;
				
				
				
			}else{
				//break va xoa man hinh chuc nang
				xoaManHinhShowCN();
				break;
			}
		}
		chon = getch();
		
	}
	
}
//khung sua 
void sua(SinhVienItem * svItem){
	char ma_nha[200];
	strcpy(ma_nha,svItem->sv.maSinhVien);
	// kiemm tra xem co diem chua co roi thi khong cho xoa ok
	bool check = CheckDiemXoaSinhVien(ma_nha);
	if(!check){
		xoaManHinhShowCN();
	Yescursortype();
	// ve cai khung cai da tinh sau
	gotoxy(60,6);
	SetBGColor(7);
	cout << char(218) << setw(100) << setfill(char(196)) << char(191);
	
	for(int i = 7; i < 40; i++){
		gotoxy(60,i);
		cout << char(179);
		gotoxy(160,i);
		cout << char(179);
		gotoxy(61,i);
		cout<<"                                                                                                   ";
		
	}
	gotoxy(60,40);
	cout << char(192) << setw(100) << setfill(char(196)) << char(217);
//	xong cai khung da ne 
	gotoxy(61,8);
	cout <<setw(100) << setfill(char(196))<<char(196) ;
	gotoxy(61,7);
	cout <<"                               CAP NHAT THONG TIN SINH VIEN  " ;
	//-------------------------------------------------
	gotoxy(80,11);
	cout<<"MA SINH VIEN";
	gotoxy(100,10);
	cout << char(218) << setw(40) << setfill(char(196)) << char(191);
	gotoxy(100,11);
	cout << char(179)<<"       "<<svItem->sv.maSinhVien;
	gotoxy(140,11);
	cout << char(179);
	gotoxy(100,12);
	cout << char(192) << setw(40) << setfill(char(196)) << char(217);
	//---------------------------------------------------
	//-------------------------------------------------
	gotoxy(80,14);
	cout<<"TEN SINH VIEN";
	gotoxy(100,13);
	cout << char(218) << setw(40) << setfill(char(196)) << char(191);
	gotoxy(100,14);
	cout << char(179);
	gotoxy(140,14);
	cout << char(179);
	gotoxy(100,15);
	cout << char(192) << setw(40) << setfill(char(196)) << char(217);
	//---------------------------------------------------
	//-------------------------------------------------
	gotoxy(80,17);
	cout<<"LOP SINH VIEN";
	gotoxy(100,16);
	cout << char(218) << setw(40) << setfill(char(196)) << char(191);
	gotoxy(100,17);
	cout << char(179);
	gotoxy(140,17);
	cout << char(179);
	gotoxy(100,18);
	cout << char(192) << setw(40) << setfill(char(196)) << char(217);
	//---------------------------------------------------
	gotoxy(80,20);
	cout<<"SO DIEN THOAI ";
	gotoxy(100,19);
	cout << char(218) << setw(40) << setfill(char(196)) << char(191);
	gotoxy(100,20);
	cout << char(179);
	gotoxy(140,20);
	cout << char(179);
	gotoxy(100,21);
	cout << char(192) << setw(40) << setfill(char(196)) << char(217);
	//---------------------------------------------------
	gotoxy(80,23);
	cout<<"SO CMND ";
	gotoxy(100,22);
	cout << char(218) << setw(40) << setfill(char(196)) << char(191);
	gotoxy(100,23);
	cout << char(179);
	gotoxy(140,23);
	cout << char(179);
	gotoxy(100,24);
	cout << char(192) << setw(40) << setfill(char(196)) << char(217);
	//---------------------------------------------------
	gotoxy(101,28);
	cout<<"             CAP NHAT             ";
	gotoxy(100,27);
	cout << char(218) << setw(40) << setfill(char(196)) << char(191);
	gotoxy(100,28);
	cout << char(179);
	gotoxy(140,28);
	cout << char(179);
	gotoxy(100,29);
	cout << char(192) << setw(40) << setfill(char(196)) << char(217);
	//---------------------------------------------------
	//------------------------------nhap vao nao---------------------------------------
	char ten[200],lop[200],sdt[200],cmnd[200];
	gotoxy(110,14);
	
	strcpy(ten , dinhDangNhapTen(30));
	gotoxy(110,17);
	strcpy(lop, dinhDangNhapLop('U',11));
	gotoxy(110,20);
	strcpy(sdt, dinhDangSo(10));
	gotoxy(110,23);
	strcpy(cmnd, dinhDangSo(9));
	//---------------------------------------------------hight light cai cap nhat len nha ------------------------------//
	gotoxy(101,28);
	SetBGColor(99);
	cout<<"                CAP NHAT               ";
	gotoxy(100,27);
	cout << char(218) << setw(40) << setfill(char(196)) << char(191);
	gotoxy(100,28);
	cout << char(179);
	gotoxy(140,28);
	cout << char(179);
	gotoxy(100,29);
	cout << char(192) << setw(40) << setfill(char(196)) << char(217);
	//---------------------------------------------------
		
	char qq= getch();
	if(qq=13){

			PTRLOP DSLOP = NULL;
			DocFileLop(DSLOP);
			int dem =DemLopHoc(DSLOP),flag =0;
			int cc=0;
			LopHoc *lopYou = new LopHoc[100];
			MangTam_Lop(DSLOP,lopYou,cc);
			char lopTamp[200];
			for(int i =0 ; i < dem; i++){
			strcpy(lopTamp,lopYou[i].Idlop);
			//chi can kiem tra cai lop co ton tai khong thoi	
			if(strcmp(lop,lopTamp)==0){
				flag = 1;
				break;
			}
		}
		
		xoaTB();
		gotoxy(2,20);
		cout<<"nhan enter de cap nhap bat ki de thoat";
		if(flag == 0){
			//call ham thong bao
				xoaTB();
				gotoxy(2,20);
				cout<<"lop sinh vien k0 ton tai nha";
				xoaManHinhShowCN();
		}else{
			char cc= getch();
			
			if(cc==13){
				strcpy(svItem->sv.tenSinhVien,ten);
				strcpy(svItem->sv.lopSinhVien,lop);
				strcpy(svItem->sv.soDienThoai,sdt);
				strcpy(svItem->sv.cmnd,cmnd);
				
				xoaTB();
				gotoxy(2,20);
				cout<<"cap nhat thanh cong ";
				xoaManHinhShowCN();	
			}else{
				gotoxy(2,20);
				cout<<"ban chua cap nhap nha ";
				xoaManHinhShowCN();
			}
			
		}
		
}
				}else{
					xoaTB();
					gotoxy(2,20);
					cout<<"Sinh Vien Da Nhap Diem Khong Duoc Sua";
					xoaManHinhShowCN();
				}

//	}else{
//		gotoxy(2,20);
//		cout<<"ban chua cap nhap nha ";
//		xoaManHinhShowCN();
//	}
	
	Nocursortype();
	
}

void khungSuaXoa(SinhVien sinhVien,TREE &tree){
	SinhVienItem * svEdit = searchSinhVien(tree,sinhVien.maSinhVien);
	// tao cai khung de show chi tiet thang cu sinh vien do ra moi duoc ne 
		gotoxy(50,16);
		SetBGColor(111);
		cout << char(218) << setw(120) << setfill(char(196)) << char(191);
		
		for(int i = 17; i < 23; i++){
			gotoxy(50,i);
			cout << char(179);
			gotoxy(170,i);
			cout << char(179);
			gotoxy(51,i);
			cout<<"                                                                                                                       ";
			
		}
		gotoxy(50,23);
		cout << char(192) << setw(120) << setfill(char(196)) << char(217);
		//end cai khung cai da lam gia lam tiep
		
		gotoxy(51,18);
		cout <<  setw(118) << setfill(char(196)) <<char(196);
			gotoxy(51,17);
			cout<<"    MA SO SINH VIEN      ";
			gotoxy(78,17);
			cout << char(179);
			cout<<"    TEN SINH VIEN      ";
			gotoxy(100,17);
			cout << char(179);
			cout<<"      LOP SINH VIEN      ";
			gotoxy(122,17);
			cout << char(179);
			cout<<"    SDT SINH VIEN      ";
			gotoxy(144,17);
			cout << char(179);
			cout<<"   SO CMND SINH VIEN     ";		
		//----------------------------------
			gotoxy(51,20);
			cout<<"     "<<svEdit->sv.maSinhVien;
			gotoxy(78,20);
			cout << char(179);
			cout<<"    "<<svEdit->sv.tenSinhVien;
			gotoxy(100,20);
			cout << char(179);
			cout<<"     "<<svEdit->sv.lopSinhVien;
			gotoxy(122,20);
			cout << char(179);
			cout<<"     "<<svEdit->sv.soDienThoai;
			gotoxy(144,20);
			cout << char(179);
			cout<<"     "<<svEdit->sv.cmnd;
			//---------------------------------------------------
		gotoxy(81,35);
		cout<<"        SUA        ";
		// tao cai o sua cho dep ti 
		gotoxy(80,34);
		cout << char(218) << setw(20) << setfill(char(196)) << char(191);
		gotoxy(80,35);
		cout << char(179);
		gotoxy(100,35);
		cout << char(179);
		gotoxy(80,36);
		cout << char(192) << setw(20) << setfill(char(196)) << char(217);
		//---------------------------------------------------
		gotoxy(120,35);
		cout<<"       XOA          ";
		//tao cai o xoa cho no dep ti
		gotoxy(120,34);
		cout << char(218) << setw(20) << setfill(char(196)) << char(191);
		gotoxy(120,35);
		cout << char(179);
		gotoxy(140,35);
		cout << char(179);
		gotoxy(120,36);
		cout << char(192) << setw(20) << setfill(char(196)) << char(217);
		//---------------------------------------------------
		// so (100,9) la search 
		//(80,35) la sua
		//(120,35) xoa
		// goi ham sua voi dia chi nhap la x = 100 , y = 9 va nhan ve la thong tin cua sinh vien
		
		//hight light thang sua len cai da
		gotoxy(81,35);
		SetBGColor(99);
		cout<<"       SUA          ";
		gotoxy(80,34);
		cout << char(218) << setw(20) << setfill(char(196)) << char(191);
		gotoxy(80,35);
		cout << char(179);
		gotoxy(100,35);
		cout << char(179);
		gotoxy(80,36);
		cout << char(192) << setw(20) << setfill(char(196)) << char(217);
//		end hight light nha 
		char chon = getch();
		int k = 90;
		Nocursortype();
		while(chon){
			if(chon==75 || chon ==77){
				if(chon == 75 && k>90){
					k-=40;
				}
				else if(chon ==77 && k <130){
					k+=40;
				}
//--------------------------------------------------- dua hai thang do ve mac dinh---------------------------------------//
				gotoxy(81,35);
				SetBGColor(7);
				cout<<"       SUA          ";
				gotoxy(80,34);
				cout << char(218) << setw(20) << setfill(char(196)) << char(191);
				gotoxy(80,35);
				cout << char(179);
				gotoxy(100,35);
				cout << char(179);
				gotoxy(80,36);
				cout << char(192) << setw(20) << setfill(char(196)) << char(217);
				//---------------------------------------------------
				gotoxy(120,35);
				SetBGColor(7);
				cout<<"       XOA          ";
				gotoxy(120,34);
				cout << char(218) << setw(20) << setfill(char(196)) << char(191);
				gotoxy(120,35);
				cout << char(179);
				gotoxy(140,35);
				cout << char(179);
				gotoxy(120,36);
				cout << char(192) << setw(20) << setfill(char(196)) << char(217);
				//---------------------------------------------------
//--------------------hight light cai duoc tuong tac boi ng dung len --------------------------------//
				if(k==130){
					gotoxy(120,35);
					SetBGColor(99);
					cout<<"       XOA          ";
					gotoxy(120,34);
					cout << char(218) << setw(20) << setfill(char(196)) << char(191);
					gotoxy(120,35);
					cout << char(179);
					gotoxy(140,35);
					cout << char(179);
					gotoxy(120,36);
					cout << char(192) << setw(20) << setfill(char(196)) << char(217);
				}else{
						gotoxy(81,35);
						SetBGColor(99);
						cout<<"       SUA          ";
						gotoxy(80,34);
						cout << char(218) << setw(20) << setfill(char(196)) << char(191);
						gotoxy(80,35);
						cout << char(179);
						gotoxy(100,35);
						cout << char(179);
						gotoxy(80,36);
						cout << char(192) << setw(20) << setfill(char(196)) << char(217);
				}
			}
			// bat su kien enter
			else if(chon==13){
					if(k==90){
					xoaManHinhShowCN();
					sua(svEdit);
				}else if(k==130){
					xoaManHinhShowCN();
					char c[200];
					strcpy(c,svEdit->sv.maSinhVien);
					xoa(tree,c);
				}
				break;
			}else if(chon==27){
				xoaManHinhShowCN();
				break;
			}
			chon = getch();
			
		}
		
		
	
	
	// lay dc du lieu va show neu khong lay dc hien ben bang thong bao
	// co leh if o day bay gio thi chi show thu giao dien 


	
}
//xoa man hinh phan trang 
void xoaPhanTrang(){
	for(int i = 7 ; i <27; i++){
				SetBGColor(15);
				gotoxy(51,i);
				cout<<"                        ";
				gotoxy(78,i);
				cout << char(179);
				cout<<"                        ";
				gotoxy(100,i);
				cout << char(179);
				cout<<"                        ";
				gotoxy(122,i);
				cout << char(179);
				cout<<"                        ";
				gotoxy(144,i);
				cout << char(179);
					cout<<"                        ";
			
				
}
}
// render du lieu theo page yeu cau
void pageContent(SinhVien listLop[],int sizeLop,int ofset){
	// truoc tien xoa du lieu cu con tren trang di cai da ne
	for(int k = 7 ; k<20+7;k++){
		gotoxy(51,k);
		SetBGColor(11);
		cout<<"                                                                                                                       ";
	}
	// xoa xong roi ne
	// render ra thoi ne
	int j= 7;
	// lap thoai mai ne ahihi
	for(int i = ofset *20 ; i <sizeLop; i++){
				gotoxy(51,j);
				cout<<"     "<<listLop[i].maSinhVien;
				gotoxy(78,j);
				cout << char(179);
				cout<<"     "<<listLop[i].tenSinhVien;
				gotoxy(100,j);
				cout << char(179);
				cout<<"     "<<listLop[i].lopSinhVien;
				gotoxy(122,j);
				cout << char(179);
				cout<<"     "<<listLop[i].soDienThoai;
				gotoxy(144,j);
				cout << char(179);
				cout<<"     "<<listLop[i].cmnd;
				j++;
				// chan cai lap m lai ne cay khong ahihi
				if(ofset*20+19==i){
					break;
				}
	}
//	end render 	
}
//end page content hay con goi la sinh vien cua lop hien thi 

//nhan vao ten lop va doc len cay
void showSVLop(char tenLop[],TREE &tree){
	// lam gi lam tao cai khung cai da nha ahihi
	gotoxy(50,4);
	SetBGColor(111);
	cout << char(218) << setw(120) << setfill(char(196)) << char(191);
	
	for(int i = 5; i < 35; i++){
		gotoxy(50,i);
		cout << char(179);
		gotoxy(170,i);
		cout << char(179);
		gotoxy(51,i);
		cout<<"                                                                                                                       ";
		
	}
	
	gotoxy(50,35);
	cout << char(192) << setw(120) << setfill(char(196)) << char(217);
	//end cai khung roi ne 
	
	gotoxy(51,6);
	cout <<  setw(118) << setfill(char(196)) <<char(196);
		gotoxy(51,5);
		cout<<"    MA SO SINH VIEN      ";
		gotoxy(78,5);
		cout << char(179);
		cout<<"    TEN SINH VIEN      ";
		gotoxy(100,5);
		cout << char(179);
		cout<<"      LOP SINH VIEN      ";
		gotoxy(122,5);
		cout << char(179);
		cout<<"    SDT SINH VIEN      ";
		gotoxy(144,5);
		cout << char(179);
		cout<<"   SO CMND SINH VIEN     ";		
	//---------------------------------- bat dau tu  7
	int dem = 0,sizeTree = countSV(tree),tamp = 7,index = 0,tamp1 =0,sizeLop;
	SinhVien listSinhVien[sizeTree];
	listTampAllSV(tree,listSinhVien,dem);
	sizeLop = demSVTrongLop(listSinhVien,tenLop,sizeTree);
	SinhVien listLop[sizeLop];
	listTampCLass(listLop,listSinhVien,tenLop,sizeTree);
	int page = sizeLop/20,indexPage = 0;
		pageContent(listLop,sizeLop,0);
		
		

//------------------->>Phan Trang O day nha <<---------------------------------------//		
		for(int i = 0; i< page+1; i ++){
			if(i == indexPage){
				//tao cai khung hinh vuong cho dep nhe
				gotoxy(100+5*i+i,36);
				SetBGColor(9);
				cout << char(218) << setw(5) << setfill(char(196)) << char(191);
				
				gotoxy(100+5*i+i,37);
				cout << char(179)<<" "<<i+1<<"  ";
				gotoxy(100+5*i+5+i,37);
				cout <<char(179);
				
				gotoxy(100+5*i+i,38);
				cout << char(192) << setw(5) << setfill(char(196)) << char(217);
//				end cai khung ne
			}else{
					//tao cai khung hinh vuong cho dep nhe
				gotoxy(100+5*i+i,36);
				SetBGColor(15);
				cout << char(218) << setw(5) << setfill(char(196)) << char(191);
				
				gotoxy(100+5*i+i,37);
				cout << char(179)<<" "<<i+1<<"  ";
				gotoxy(100+5*i+5+i,37);
				cout << char(179);
				
				gotoxy(100+5*i+i,38);
				cout << char(192) << setw(5) << setfill(char(196)) << char(217);
				//				end cai khung ne
			}
			
		}
	gotoxy(2,20);
	SetBGColor(10);
	cout<<"      Di chuyen <- -> de qua trang    ";
	
	
	gotoxy(79,7);
	SetBGColor(9);
	cout<<"-->";
	char chon = getch();
	
	while(chon){
		if(chon ==72 || chon ==80){
			
			gotoxy(2,21);
			SetBGColor(9);
			cout<<"     ENTER de SUA hoac XOA SV nha     ";
			if(chon == 72 && index>indexPage*20){
				index=index-1;
				tamp1-=1;
			}else if(chon==80 && index<indexPage*20+19&& index<sizeLop-1){
				index=index+ 1;
				tamp1+=1;
			}
		}else if(chon ==13){
			
			SinhVien svChon = listLop[index];
			xoaTB();
			xoaManHinhShowCN();
			khungSuaXoa(svChon,tree);
			break;
			
		}else if((chon == 75 || chon == 77 ) && 10>0){
			
			if(chon == 75&& indexPage>0){
				indexPage -=1;
			
			}else if(chon ==77 && indexPage <page){
				indexPage +=1;
			}
			for(int i = 0; i< page+1; i ++){
				if(i == indexPage){
					//tao cai khung cai da hight light no len nha
				gotoxy(100+5*i+i,36);
				SetBGColor(9);
				cout << char(218) << setw(5) << setfill(char(196)) << char(191);
				
				gotoxy(100+5*i+i,37);
				cout << char(179)<<" "<<i+1<<"  ";
				gotoxy(100+5*i+5+i,37);
				cout <<char(179);
				
				gotoxy(100+5*i+i,38);
				cout << char(192) << setw(5) << setfill(char(196)) << char(217);
				// xong cai khung
			}else{
				// dua tat ca ve default
				gotoxy(100+5*i+i,36);
				SetBGColor(15);
				
				cout << char(218) << setw(5) << setfill(char(196)) << char(191);
				gotoxy(100+5*i+i,37);
				cout << char(179)<<" "<<i+1<<"  ";
				gotoxy(100+5*i+5+i,37);
				cout << char(179);
				
				gotoxy(100+5*i+i,38);
				cout << char(192) << setw(5) << setfill(char(196)) << char(217);
//				dua xong roi nha 
			}
			xoaPhanTrang();
			pageContent(listLop,sizeLop,indexPage);
			
			
		}
			
		
			
		}else if(chon==27){
			xoaManHinhShowCN();
			break;
		}
		index = indexPage*20+tamp1;
		// nhan len cong lai bu hon so thanh vien thi dua no len dau tien
		if(index>=sizeLop){
			index = indexPage*20;
			tamp1 = 0;
		};
		
		for(int kk= 0 ; kk<20;kk++){
			gotoxy(79,kk+7);
			SetBGColor(11);
			cout<<"   ";
		}
		gotoxy(79,tamp1+7);
		SetBGColor(9);
		cout<<"-->";
		chon = getch();
	}
	
	
}


// ghi vao bang huong dan
void huongDan(){
	gotoxy(3,32);
	cout<<"   Dung Phim Mui Ten Tren Ban phim";
	gotoxy(4,33);
	cout<<"  De dieu kien len xuong trai phai ";
	gotoxy(4,34);
	cout<<"  ENTER de chon";
	gotoxy(4,35);
	cout<<"  ESC de thoat";
	gotoxy(4,36);
	cout<<"  !!! Chu y xem bang thong bao nha";
	
}
void khungCN(int k){
	//-------------------
	
	gotoxy(5,3);
	if(k==3){
		SetBGColor(11);
	}else{
		SetBGColor(15);
	}
	cout << char(218) <<setw(30) << setfill(char(196))<<char(196) << char(191);
	gotoxy(5,4);
	cout << char(179);
	gotoxy(36,4);
	cout << char(179);
	gotoxy(5,5);
	cout << char(192) << setw(31) << setfill(char(196)) << char(217);
	gotoxy(6,4);
	if(k==3){
		SetBGColor(9);
	}else{
		SetBGColor(15);
	}
	
	cout<<"         THEM SINH VIEN       ";
	//-----------------------
	
	gotoxy(5,6);
	if(k==6){
		SetBGColor(11);
	}else{
		SetBGColor(15);
	}
	cout << char(218) <<setw(30) << setfill(char(196))<<char(196) << char(191);
	gotoxy(5,7);
	cout << char(179);
	gotoxy(36,7);
	cout << char(179);
	gotoxy(5,8);
	cout << char(192) << setw(31) << setfill(char(196)) << char(217);
	gotoxy(6,7);
	if(k==6){
		SetBGColor(9);
	}else{
		SetBGColor(15);
	}
	cout<<"   TIM SINH VIEN THEO MSSV    ";
		//-----------------------
	
	gotoxy(5,9);
	if(k==9){
		SetBGColor(11);
	}else{
		SetBGColor(15);
	}
	cout << char(218) <<setw(30) << setfill(char(196))<<char(196) << char(191);
	gotoxy(5,10);
	cout << char(179);
	gotoxy(36,10);
	cout << char(179);
	gotoxy(5,11);
	cout << char(192) << setw(31) << setfill(char(196)) << char(217);
	gotoxy(6,10);
	if(k==9){
		SetBGColor(9);
	}else{
		SetBGColor(15);
	}
	cout<<"   XEM SINH VIEN THEO LOP     ";
		//-----------------------
	
	gotoxy(5,12);
	if(k==12){
		SetBGColor(11);
	}else{
		SetBGColor(15);
	}
	cout << char(218) <<setw(30) << setfill(char(196))<<char(196) << char(191);
	gotoxy(5,13);
	cout << char(179);
	gotoxy(36,13);
	cout << char(179);
	gotoxy(5,14);
	cout << char(192) << setw(31) << setfill(char(196)) << char(217);
	gotoxy(6,13);
	if(k==12){
		SetBGColor(9);
	}else{
		SetBGColor(15);
	}
	cout<<"   XEM SINH VIEN THEO KHOA    ";
		//-----------------------
	
	gotoxy(5,15);
	if(k==15){
		SetBGColor(11);
	}else{
		SetBGColor(15);
	}
	cout << char(218) <<setw(30) << setfill(char(196))<<char(196) << char(191);
	gotoxy(5,16);
	cout << char(179);
	gotoxy(36,16);
	cout << char(179);
	gotoxy(5,17);
	cout << char(192) << setw(31) << setfill(char(196)) << char(217);
	gotoxy(6,16);
	if(k==15){
		SetBGColor(9);
	}else{
		SetBGColor(15);
	}
	cout<<"       DI VE TRANG CHU        ";
	
	
}

//show ma lop de them


//khung them 
void khungThem(TREE &tree,bool phanQuyen, int &xx,char nameLopFile[]){
	if(phanQuyen){
	char mssv[200], ten[200],lop[200],sdt[200],cmnd[200];
	
	gotoxy(80,6);
	SetBGColor(7);
	cout << char(218) << setw(100) << setfill(char(196)) << char(191);
	
	for(int i = 7; i < 40; i++){
		gotoxy(80,i);
		cout << char(179);
		gotoxy(180,i);
		cout << char(179);
		gotoxy(81,i);
		cout<<"                                                                                                   ";
		
	}
	gotoxy(125,17);
	strcpy(lop , nameLopFile);
	cout<<nameLopFile;
	
	
	gotoxy(80,40);
	cout << char(192) << setw(100) << setfill(char(196)) << char(217);
	
	gotoxy(81,8);
	cout <<setw(100) << setfill(char(196))<<char(196) ;
	gotoxy(81,7);
	cout <<"                                  NHAP THONG TIN SINH VIEN                                         " ;
	//-------------------------------------------------
	gotoxy(100,11);
	cout<<"MA SINH VIEN";
	//tao cai khung nhap ma 
	gotoxy(120,10);
	cout << char(218) << setw(40) << setfill(char(196)) << char(191);
	gotoxy(120,11);
	cout << char(179);
	gotoxy(160,11);
	cout << char(179);
	gotoxy(120,12);
	cout << char(192) << setw(40) << setfill(char(196)) << char(217);
	//---------------------------------------------------
	//-------------------------------------------------
	gotoxy(100,14);
	cout<<"TEN SINH VIEN";
	//tao cai khung nhap
	gotoxy(120,13);
	cout << char(218) << setw(40) << setfill(char(196)) << char(191);
	gotoxy(120,14);
	cout << char(179);
	gotoxy(160,14);
	cout << char(179);
	gotoxy(120,15);
	cout << char(192) << setw(40) << setfill(char(196)) << char(217);
	//---------------------------------------------------
	//-------------------------------------------------
	gotoxy(100,17);
	cout<<"LOP SINH VIEN";
	//tao cai khung nhap
	gotoxy(120,16);
	cout << char(218) << setw(40) << setfill(char(196)) << char(191);
	gotoxy(120,17);
	cout << char(179);
	gotoxy(160,17);
	cout << char(179);
	gotoxy(120,18);
	cout << char(192) << setw(40) << setfill(char(196)) << char(217);
	//---------------------------------------------------
	gotoxy(100,20);
	cout<<"SO DIEN THOAI ";
	//tao cai khung nhap
	gotoxy(120,19);
	cout << char(218) << setw(40) << setfill(char(196)) << char(191);
	gotoxy(120,20);
	cout << char(179);
	gotoxy(160,20);
	cout << char(179);
	gotoxy(120,21);
	cout << char(192) << setw(40) << setfill(char(196)) << char(217);
	//---------------------------------------------------
	gotoxy(100,23);
	cout<<"SO CMND ";
	//tao cai khung nhap
	gotoxy(120,22);
	cout << char(218) << setw(40) << setfill(char(196)) << char(191);
	gotoxy(120,23);
	cout << char(179);
	gotoxy(160,23);
	cout << char(179);
	gotoxy(120,24);
	cout << char(192) << setw(40) << setfill(char(196)) << char(217);
	//---------------------------------------------------
	// dau tien la hight light no len luon
	gotoxy(121,28);
	SetBGColor(8);
	cout<<"             THEM SINH VIEN            ";
	//tao cai khung nhan tham
	gotoxy(120,27);
	cout << char(218) << setw(40) << setfill(char(196)) << char(191);
	gotoxy(120,28);
	cout << char(179);
	gotoxy(160,28);
	cout << char(179);
	gotoxy(120,29);
	cout << char(192) << setw(40) << setfill(char(196)) << char(217);
	//---------------------------------------------------
	gotoxy(100,35);
	SetBGColor(7);
	cout<<"       TRO VE       ";
	//tao cai khung tro ve
	gotoxy(100,34);
	cout << char(218) << setw(20) << setfill(char(196)) << char(191);
	gotoxy(100,35);
	cout << char(179);
	gotoxy(120,35);
	cout << char(179);
	gotoxy(100,36);
	cout << char(192) << setw(20) << setfill(char(196)) << char(217);
	//---------------------------------------------------
	gotoxy(140,35);
	cout<<"     TRANG CHU      ";
	//tao cai khung nhan di ve trang chu
	gotoxy(140,34);
	cout << char(218) << setw(20) << setfill(char(196)) << char(191);
	gotoxy(140,35);
	cout << char(179);
	gotoxy(160,35);
	cout << char(179);
	gotoxy(140,36);
	cout << char(192) << setw(20) << setfill(char(196)) << char(217);
	//---------------------------------------------------
	//y = 11 + 3 len de nhap  x thi 105  them 28 tro ve 35
	
	
	Yescursortype();
	gotoxy(125,11);
	strcpy(mssv , dinhDangMSSV('U',10));
	gotoxy(125,14);
	strcpy(ten , dinhDangNhapTen(30));
	gotoxy(125,20);
	strcpy(sdt , dinhDangSo(10));
	gotoxy(125,23);
	strcpy(cmnd , dinhDangSo(9));
	int dem = 1;
	gotoxy(141,29);
	char chon = getch();
	
	while(chon){
		if(chon ==72 || chon ==80){
			if(chon==72 && dem>1){
				dem-=1;
			}else if(chon ==80 && dem<3){
				dem+=1;
			}
			//---------------------------------------------------
			// dua tat ca ve default voi bachground la mau so 7
				gotoxy(121,28);
				SetBGColor(7);
				cout<<"             THEM SINH VIEN            ";
				gotoxy(120,27);
				cout << char(218) << setw(40) << setfill(char(196)) << char(191);
				gotoxy(120,28);
				cout << char(179);
				gotoxy(160,28);
				cout << char(179);
				gotoxy(120,29);
				cout << char(192) << setw(40) << setfill(char(196)) << char(217);
				//---------------------------------------------------
				gotoxy(100,35);
				SetBGColor(7);
				cout<<"       TRO VE       ";
				gotoxy(100,34);
				cout << char(218) << setw(20) << setfill(char(196)) << char(191);
				gotoxy(100,35);
				cout << char(179);
				gotoxy(120,35);
				cout << char(179);
				gotoxy(100,36);
				cout << char(192) << setw(20) << setfill(char(196)) << char(217);
				//---------------------------------------------------
				gotoxy(140,35);
				SetBGColor(7);
				cout<<"     TRANG CHU      ";
				gotoxy(140,34);
				cout << char(218) << setw(20) << setfill(char(196)) << char(191);
				gotoxy(140,35);
				cout << char(179);
				gotoxy(160,35);
				cout << char(179);
				gotoxy(140,36);
				cout << char(192) << setw(20) << setfill(char(196)) << char(217);
				//---------------------------------------------------
				// nguoc lai thi hight light no len mau so 8
				if(dem==1){
					gotoxy(121,28);
					SetBGColor(8);
					cout<<"             THEM SINH VIEN            ";
					gotoxy(120,27);
					cout << char(218) << setw(40) << setfill(char(196)) << char(191);
					gotoxy(120,28);
					cout << char(179);
					gotoxy(160,28);
					cout << char(179);
					gotoxy(120,29);
					cout << char(192) << setw(40) << setfill(char(196)) << char(217);
				}else if(dem==2){
					gotoxy(100,35);
					SetBGColor(8);
					cout<<"       TRO VE       ";
					gotoxy(100,34);
					cout << char(218) << setw(20) << setfill(char(196)) << char(191);
					gotoxy(100,35);
					cout << char(179);
					gotoxy(120,35);
					cout << char(179);
					gotoxy(100,36);
					cout << char(192) << setw(20) << setfill(char(196)) << char(217);
					//---------------------------------------------------
				}else if(dem==3){
						//---------------------------------------------------
					gotoxy(140,35);
					SetBGColor(8);
					cout<<"     TRANG CHU      ";
					gotoxy(140,34);
					cout << char(218) << setw(20) << setfill(char(196)) << char(191);
					gotoxy(140,35);
					cout << char(179);
					gotoxy(160,35);
					cout << char(179);
					gotoxy(140,36);
					cout << char(192) << setw(20) << setfill(char(196)) << char(217);
					//---------------------------------------------------
				}
			}
			// xu ly su kien cho phim enter
		else if(chon == 13){
			if(dem == 1){
				cn1ThemSinhVien(mssv,ten,lop,sdt,cmnd,tree);
				xoaManHinhShowCN();
				break;
			}
			else if(dem==2){
				xoaManHinhShowCN();
				break;
			}
			// xu ly cho cai di ve trang chu
			else if(dem==3){
				xoaManHinhShowCN();
				xx=1;
				break;
			}
		}
			chon = getch();

		}
	}else{
		xoaTB();
		gotoxy(2,20);
		cout<<"Ban khong co quyen xem chuc nang nay";
	}
	
		
//			
}
				
// show lop va them sinh vien vao		
void showLopThem(TREE &tree,bool phanQuyen,int &xx){
	if(phanQuyen){
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
			cout<<"     ENTER de them sinh vien vao lop ";
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
			strcpy(nameFileTampClass,lop[index].Idlop);
			//goi den khung them va do du lieu a lop ra do 
			khungThem(tree,phanQuyen,xx,nameFileTampClass);
			break;
			
		}else if(chon==27){
			xoaManHinhShowCN();
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
	}else{
		xoaTB();
		gotoxy(2,20);
		cout<<"Ban ko co quyen thuc thi chuc nang nay";
	}

}
//end show lop va them sinh vien vao 


//khung search 
void khungTimSV(TREE t){
	gotoxy(90,6);
	SetBGColor(7);
	cout << char(218) << setw(50) << setfill(char(196)) << char(191);
	
	for(int i = 7; i < 13; i++){
		gotoxy(90,i);
		cout << char(179);
		gotoxy(140,i);
		cout << char(179);
		gotoxy(91,i);
		cout<<"                                                 ";
		
	}
	gotoxy(90,13);
	cout << char(192) << setw(50) << setfill(char(196)) << char(217);
	
	gotoxy(105,7);
	cout<<"NHAP VAO MSSV CAN TIM";
	//tao cai hop cho nguoi dung nhap nha
	gotoxy(100,8);
	cout << char(218) << setw(30) << setfill(char(196)) << char(191);
	
	gotoxy(100,9);
	cout << char(179);
	gotoxy(130,9);
	cout << char(179);
	
	gotoxy(100,10);
	cout << char(192) << setw(30) << setfill(char(196)) << char(217);
//	xong cai hop 
	// goi ham truyen vi tri vao cho no search cho no
	gotoxy(105,9);
	Yescursortype();
	char maSV[200] ;
	 strcpy(maSV,dinhDangMSSV('U',10));
	SinhVienItem *  svTim = searchSinhVien(t,maSV);
	
	//searchSinhVien(105,9);
	
	// lay dc du lieu va show neu khong lay dc hien ben bang thong bao
	// co leh if o day bay gio thi chi show thu giao dien 
	if(!svTim){
		gotoxy(10,21);
		SetBGColor(9);
		cout<<"khong ton tai sinh vien nay";
		xoaManHinhShowCN();
	}else{
	// ve cai khung cai da lam gi lam
	gotoxy(50,16);
	SetBGColor(111);
	cout << char(218) << setw(120) << setfill(char(196)) << char(191);
	
	for(int i = 17; i < 23; i++){
		gotoxy(50,i);
		cout << char(179);
		gotoxy(170,i);
		cout << char(179);
		gotoxy(51,i);
		cout<<"                                                                                                                       ";
		
	}
	
	gotoxy(50,23);
	cout << char(192) << setw(120) << setfill(char(196)) << char(217);
	//xong cai khung
	gotoxy(51,18);
	cout <<  setw(118) << setfill(char(196)) <<char(196);
		gotoxy(51,17);
		cout<<"    MA SO SINH VIEN      ";
		gotoxy(78,17);
		cout << char(179);
		cout<<"    TEN SINH VIEN      ";
		gotoxy(100,17);
		cout << char(179);
		cout<<"      LOP SINH VIEN      ";
		gotoxy(122,17);
		cout << char(179);
		cout<<"    SDT SINH VIEN      ";
		gotoxy(144,17);
		cout << char(179);
		cout<<"   SO CMND SINH VIEN     ";		
	//----------------------------------
		gotoxy(51,20);
		cout<<"     "<<svTim->sv.maSinhVien;
		gotoxy(78,20);
		cout << char(179);
		cout<<"  "<<svTim->sv.tenSinhVien;
		gotoxy(100,20);
		cout << char(179);
		cout<<"     "<<svTim->sv.lopSinhVien;
		gotoxy(122,20);
		cout << char(179);
		cout<<"     "<<svTim->sv.soDienThoai;
		gotoxy(144,20);
		cout << char(179);
		cout<<"     "<<svTim->sv.cmnd;
	
	}
	
	gotoxy(2,22);
	cout<<"Bam ESC DE QUAY LAI CHUC NANG";
	char exit = getch();
	if(exit){
		xoaTB();
		xoaManHinhShowCN();
	}
}
//end khung search

//-----------------------show llop de xem sua va xoa ok
void showLop(TREE &tree,bool phanQuyen, int &check){
	if(phanQuyen){
		//lam gi lam tao cai khung cho no cai da
	gotoxy(80,4);
	SetBGColor(111);
	cout << char(218) << setw(80) << setfill(char(196)) << char(191);
	
	for(int i = 5; i < 41; i++){
		gotoxy(80,i);
		cout << char(179);
		gotoxy(160,i);
		cout << char(179);
		gotoxy(81,i);
		cout<<"                                                                               ";
		
	}
	gotoxy(80,40);
	cout << char(192) << setw(80) << setfill(char(196)) << char(217);
//	end ci khung nha 
	gotoxy(81,6);
	cout <<  setw(79) << setfill(char(196)) <<char(196);
	// lam cai gach ngang dai dai duoi cai title cai da
		gotoxy(81,5);
		cout<<"          MA LOP     ";
		gotoxy(120,5);
		cout << char(179);
		cout<<"          TEN LOP      ";
			
	//---------------------------------- bat dau tu  7
	PTRLOP DSLOP = NULL;
	DocFileLop(DSLOP);
	int dem =DemLopHoc(DSLOP);
	int cc=0;
	LopHoc *lop = new LopHoc[100];
	MangTam_Lop(DSLOP,lop,cc);
	// render du lieu lop ra thoi nha 
	for(int i = 0 ; i <dem; i++){
		
		gotoxy(81,7+i);
		SetBGColor(11);
		cout<<"         "<<lop[i].Idlop<<"         ";
		gotoxy(120,7+i);
		SetBGColor(15);
		cout << char(179);
		cout<<"         "<<lop[i].Namelop;
	
	}
//	end render du lieu lop ne 
		int index = 0;
	
		//cho thang dau hight light len 
		gotoxy(81,7);
		SetBGColor(9);
		cout<<"                             ";
		gotoxy(81,7);
		cout<<"          "<<lop[0].Idlop;
//		end hight light 
		char chon = getch();
	
	while(chon){
		if(chon ==72 || chon ==80){
//			xoaTB();
			gotoxy(2,20);
			SetBGColor(9);
			cout<<"     ENTER de xem danh sach SV nha    ";
			if(chon == 72 && index>0){
				index=index-1;
			}else if(chon==80 && index<dem-1){
				index=index+ 1;
			}
		}else if(chon ==13){
			xoaTB();
			char nameFileTampClass[200] ;
			// lay duoc cai lop ma nguoi dung muon xem 
			strcpy(nameFileTampClass,lop[index].Idlop);
			int qq = countSV(tree),ccc= 0;
			SinhVien list[qq];
			listTampAllSV(tree,list,ccc);
			//kiem tra xem trong lop do co sinh vien khong
			int kk = demSVTrongLop(list,lop[index].Idlop,qq);
			if(kk<=0){
				gotoxy(2,20);
				cout<<"lop hoc chua co sinh vien nao";
			
			}else{
				
				xoaManHinhShowCN();
				showSVLop(nameFileTampClass,tree);
				break;
				
				
			}
			
			
		}else if(chon==27){
			xoaManHinhShowCN();
			check  = 1;
			break;
		}
		
			//---------------------day la xu ly mau cho dep------------------//
			for(int i =7 ; i < dem+7; i ++){
					if(i==index+7){
						gotoxy(81,i);
						SetBGColor(9);
						cout<<"                             ";
						gotoxy(81,i);
						cout<<"         "<<lop[i-7].Idlop;
					}else{
						gotoxy(81,i);
						SetBGColor(11);
						cout<<"                             ";
						gotoxy(81,i);
						cout<<"         "<<lop[i-7].Idlop;
					}
					
				}
		
		gotoxy(83,index+7);
		chon = getch();
	}
	}else{
		xoaTB();
		gotoxy(2,20);
		cout<<"Ban ko co quyen thuc thi chuc nang nay";
		check = 1;
	}

}
//end show lop nha 

//khung hien thi khhoa nha
void khungKhoaDetail(SinhVien *svKhoa,int size,int ofset){
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
				cout<<"  LOP SINH VIEN  ";
				gotoxy(133,5);
				cout << char(179);
				cout<<"  SDT SINH VIEN  ";
				gotoxy(153,5);
				cout << char(179);
				cout<<"  CMND SINH VIEN  ";		
			//---------------------------------- bat dau tu  7
			int j = 7;
			for(int i = ofset *20 ; i <size; i++){
					
						gotoxy(73,j);
						cout<<"  "<<(svKhoa+i)->maSinhVien;
						gotoxy(93,j);
						cout << char(179);
						cout<<" "<<(svKhoa+i)->tenSinhVien;
						gotoxy(113,j);
						cout << char(179);
						cout<<"     "<<(svKhoa+i)->lopSinhVien;
						gotoxy(133,j);
						cout << char(179);
						cout<<"   "<<(svKhoa+i)->soDienThoai;
						gotoxy(153,j);
						cout << char(179);
						cout<<"   "<<(svKhoa+i)->cmnd;
						if(ofset*20+19==i){
							break;
						}
						j++;
					
}
}

//khung xoa phan trang cua  khoa
void xoaSVKhoa(){
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
				cout<<"  LOP SINH VIEN  ";
				gotoxy(133,5);
				cout << char(179);
				cout<<"  SDT SINH VIEN  ";
				gotoxy(153,5);
				cout << char(179);
				cout<<"  CMND SINH VIEN  ";		
			//---------------------------------- bat dau tu  7
		
			for(int i = 7 ; i <20+7; i++){
					
						gotoxy(73,i);
						cout<<"                      ";
						gotoxy(93,i);
						cout << char(179);
						cout<<"                      ";
						gotoxy(113,i);
						cout << char(179);
						cout<<"                      ";
						gotoxy(133,i);
						cout << char(179);
						cout<<"                      ";
						gotoxy(153,i);
						cout << char(179);
						cout<<"                      ";
}
}
//khung show sinh vien theo khoa


//xoa icon phan trang
void xoaIconPhanTrang(int page){
	for(int i = 0; i< page+1; i ++){
				SetBGColor(14);
				gotoxy(100+5*i+i,36);
				cout << "                     ";
				gotoxy(100+5*i+i,37);
				cout <<"                      ";
				gotoxy(100+5*i+5+i,37);
				cout <<" ";
				gotoxy(100+5*i+i,38);
				cout << "                     ";
				cout << "                  ";
			}
			
}

// show list khoa di chuyen den dau show sinh vien khoa do


void showAllSVKhoa(char makhoa[],LopHoc *listLop,int sizeLop,int &dem1,TREE tree){
	int dem =0;
	SinhVien * svKhoa;
	LopHoc *listLopNew,*qq;
	//dem so lop thuoc khoa
	for(int i = 0 ; i < sizeLop;i++){
		char ma[4];
		strcpy(ma,(listLop+i)->Idkhoa);
		if(strcmp(makhoa,ma)==0){
			dem+=1;
		}
	}
	//ebd den lop thuoc khoa
	
	dem1 = dem;
	
	int gido = 0;
	// tao list lop new chua tat ca cac cai lop thuoc cai khoa do
	if(dem != 0){
		listLopNew = new LopHoc[dem1];
		for(int i = 0 ; i < sizeLop; i++){
			char ma[4];
			strcpy(ma,listLop[i].Idkhoa);
			if(strcmp(makhoa,ma)==0){
				strcpy((listLopNew+gido)->Idlop,(listLop+i)->Idlop);
				strcpy((listLopNew+gido)->Namelop,(listLop+i)->Idlop);
				strcpy((listLopNew+gido)->Idkhoa,(listLop+i)->Idlop);
				strcpy((listLopNew+gido)->Idkhoahoc,(listLop+i)->Idlop);
				gido++;
			}
		}
		
	}
	///---------------------------------------end tao list lop thuoc cai khoa do
	
	int allSinhVien = countSV(tree),count= 0,demTamp=0,nhay = 0,soLuongSV;
	SinhVien svAll[allSinhVien];
	//lay ve so luong cac sinh vien thuoc cai list lop hoi nay tao
	listTampAllSV(tree,svAll,count);
	for(int j = 0 ; j < dem1; j++){
		char ma[4];
		strcpy(ma,(listLopNew+j)->Idlop);
		for(int i  =0 ; i < allSinhVien; i ++){
			if(strcmp(ma,svAll[i].lopSinhVien)==0){
				demTamp++;
			}
		}
	}
	
	
	soLuongSV = demTamp;
	if(demTamp >0){
		//chay xong co duoc bien demTamp la so luong sinh vien thuoc khoa
		svKhoa = new SinhVien[demTamp];
		for(int j = 0 ; j < dem1; j++){
			char ma[4];
			strcpy(ma,(listLopNew+j)->Idlop);
			// lay ve cai list sinh vien thuoc cai khoa do
			for(int i  =0 ; i < allSinhVien; i ++){
				if(strcmp(ma,svAll[i].lopSinhVien)==0){
					strcpy((svKhoa+nhay)->maSinhVien,svAll[i].maSinhVien);
					strcpy((svKhoa+nhay)->tenSinhVien,svAll[i].tenSinhVien);
					strcpy((svKhoa+nhay)->lopSinhVien,svAll[i].lopSinhVien);
					strcpy((svKhoa+nhay)->soDienThoai,svAll[i].soDienThoai);
					strcpy((svKhoa+nhay)->cmnd,svAll[i].cmnd);
					nhay++;
				}
			}

		}
		//			lay xong roi ne 
		//goi khung khoa detail de show may thang sinh vien day ra page dau tien
		khungKhoaDetail(svKhoa,soLuongSV,0);
		
		int page = soLuongSV/20,indexPage = 0;
		
		
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
	
	gotoxy(83,7);
	char chon = getch();

	
	while(chon){
		if(chon==72 || chon ==80){
			xoaSVKhoa();
			break;
		}else if((chon == 75 || chon == 77 ) && 10>0){
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
			khungKhoaDetail(svKhoa,soLuongSV,indexPage);
		
		}else if(chon==27){
			xoaIconPhanTrang(5);
			xoaSVKhoa();
			xoaTB();
			break;
		}
		chon = getch();
	}
	}else{
		
		xoaIconPhanTrang(5);
		xoaTB();
		gotoxy(2,20);
		cout<<"Khoa Nay Chua Co Sinh Vien ";
		
		
	}
	
	
	// so luong sinh vien la so luong sinh vien co trong khoa
	//svKhoa chua sinh vien co trong khoa
	
	
}//-----------------------------

//-----------------------------lay ve list lop va so luong lop luon nha
LopHoc *listLopAll(int &h){
			PTRLOP DSLOP = NULL;
			DocFileLop(DSLOP);
			 int soLuong =DemLopHoc(DSLOP),chay = 0;
			LopHoc *lop = new LopHoc[soLuong];
			//lay ve mang tam tat ca lop
			MangTam_Lop(DSLOP,lop,chay);
			h= soLuong;
	
	return lop;
}

void khungShowSinhVienKhoa(TREE tree){
	//lam gi lam ve cai khung cai da 
	gotoxy(41,4);
	SetBGColor(111);
	cout << char(218) << setw(30) << setfill(char(196)) << char(191);
	
	for(int i = 5; i < 35; i++){
		gotoxy(41,i);
		cout << char(179);
		gotoxy(71,i);
		cout << char(179);
		gotoxy(42,i);
		cout<<"                             ";
		
	}
	
	gotoxy(41,35);
	cout << char(192) << setw(30) << setfill(char(196)) << char(217);
	// e xong cai kkhung roi ne
	
	gotoxy(42,6);
	cout <<  setw(29) << setfill(char(196)) <<char(196);
		gotoxy(51,5);
		cout<<"TEN KHOA";
		//------------------------------------------
		//lay ve lsit cac khoa
		PTRKHOA treeKhoa;
		EmptyDSKHOA(treeKhoa);
		DocFileKhoa(treeKhoa);
		int takeSizeKhoa = sizeKhoa(treeKhoa),dem = 0,nhay = 7,dem1=0,sizeLop=9,demSV= 0;
		Khoa listKhoa[takeSizeKhoa];
		MangTam_Khoa(treeKhoa,listKhoa,dem1);
//		end lay cac khoa 
		int demLop ,demThuocKhoa;
		// lay ve list lop va so luong lop chung ta co 
		LopHoc *lop = listLopAll(demLop),*lopTamp;
		//render cac khoa cua chung ta ra
		for(int i =7 ; i < takeSizeKhoa+7; i ++){
			gotoxy(42,i);
			SetBGColor(11);
			cout<<"                             ";
			gotoxy(42,i);
			cout<<"     "<<listKhoa[i-7].NameKhoa;
		}
//		end render 

		gotoxy(42,nhay);
		SetBGColor(9);
		cout<<"                             ";
		gotoxy(42,nhay);
		cout<<"     "<<listKhoa[0].NameKhoa;
		char kk[200];
		strcpy(kk,listKhoa[0].Idkhoa);
		// show all sinh vien thuoc ma khoa do len
		showAllSVKhoa(kk,lop,demLop,demThuocKhoa,tree);
		char chon = getch();
		
		
		while(chon){
			if(chon == 72 || chon == 80){
				if(chon == 72 && nhay >7){
					nhay -=1;
					dem-=1;
				}else if(chon ==80 && nhay <takeSizeKhoa+7-1){
					nhay +=1;
					dem+=1;
				}
				//xu ly di chuen phim muoi ten hight light len
				for(int i =7 ; i < takeSizeKhoa+7; i ++){
					if(i==dem+7){
						gotoxy(42,i);
						SetBGColor(9);
						cout<<"                             ";
						gotoxy(42,i);
						cout<<"     "<<listKhoa[i-7].NameKhoa;
					}else{
						gotoxy(42,i);
						SetBGColor(11);
						cout<<"                             ";
						gotoxy(42,i);
						cout<<"     "<<listKhoa[i-7].NameKhoa;
					}
					
				}
				char ma[4];
				strcpy(ma,listKhoa[dem].Idkhoa);
				//------------
			 	showAllSVKhoa(ma,lop,demLop,demThuocKhoa,tree);
			}else if(chon == 27){
					xoaTB();
					xoaManHinhShowCN();
					break;
				}
					gotoxy(42,nhay);
					chon = getch();
		}
		
}

//khung chinh nha
void khungMain(TREE &tree,bool phanQuyen){
	// mo hop nha
	gotoxy(1,1);
	cout << char(218) << setw(180) << setfill(char(196)) << char(191);
	//xuat hai cai cot doc thoi ma ahihi
	for(int i = 2; i < 43; i++){
		gotoxy(1,i);
		cout << char(179);
		gotoxy(181,i);
		cout << char(179);
		gotoxy(40,i);
		cout << char(179);
	}
	// end hai cai cot doc
	gotoxy(1,43);
	cout << char(192) << setw(180) << setfill(char(196)) << char(217);
	// dong hop nha
	
	//dau gach ngang phan luong chuc nagn thong bao huong dan
	gotoxy(2,18);
	cout << setw(38) << setfill(char(196))<<char(196) ;
	gotoxy(2,30);
	cout << setw(38) << setfill(char(196))<<char(196) ;
	gotoxy(15,2);
	SetBGColor(11);
	cout<<"CHUC NANG";
	gotoxy(15,19);
	SetBGColor(11);
	cout<<"THONG BAO";
	gotoxy(15,31);
	SetBGColor(11);
	cout<<"HUONG DAN";
	//hight light thang dau tien len
	khungCN(3);
	
	// xu ly cho chon
	gotoxy(34,4);
	int x = 4,xx = 0;
	char chon= getch();
	while(chon){
		Nocursortype();
		if(chon == 72 || chon == 80 ){
			if(chon==72 && x>4){
				x= x-3;
			}else if(chon ==80 && x<15 ){
				x+=3;
			}
			gotoxy(34,x);
			// goi den khung va hight len theo ci ma ban da chon
			khungCN(x-1);
		}else if(chon == 13){
			xoaManHinhShowCN();
			switch(x){
				case 4:{
					gotoxy(41,2);
					SetBGColor(124);
					cout<<"                                                         THEM SINH VIEN                                                                     ";
					xoaTB();
					showLopThem(tree,phanQuyen,xx);
//					khungThem(tree,phanQuyen,xx);
					break;
				}
				case 7:{
					gotoxy(41,2);
					SetBGColor(124);
					cout<<"                                                     TIM SINH VIEN THEO MA                                                                  ";
					xoaTB();
					khungTimSV(tree);			
					break;
				}
				case 10:{
					gotoxy(41,2);
					SetBGColor(124);
					cout<<"                                                     XEM SUA XOA SINH VIEN THEO LOP                                                         ";
					xoaTB();
					int check= 0;
					while(1){
						showLop(tree,phanQuyen,check);
						if(check == 1){
							break;
						}
					}
					
					break;
				}
				case 13:{
					gotoxy(41,2);
					SetBGColor(124);
					cout<<"                                                         XEM SINH VIEN THEO KHOA                                                           ";
				
					xoaTB();
					khungShowSinhVienKhoa(tree);
					break;
				}
				case 16:{
					gotoxy(41,2);
					SetBGColor(124);
					cout<<"                                                             DI VE TRANG CHU                                                           ";
					xoaTB();
					ghiLaiNao(tree);
					xx=1;
					break;
				}
			}if(xx==1){
				
				break;
			}
			
		}
		
		chon= getch();
		
	}
}

