
#include"thongke.h"

void MENUCHINH(){

	//Khung_Loading();
	bool phanquyen = Login(); // TK: admin  || PASS: 20062020
	Khung_MenuMain();
	while (1)
	{
		
		Nocursortype();
		system("cls");
		system("color 72");
		for (int i = 0; i < 7 ; i++)
		{
			if (i == 0) { TextColor(52); }
			else { TextColor(240); }
			gotoXY(6, 4 + i * 4); cout << "                              ";
			gotoXY(6, 5 + i * 4); cout << MENUMAIN[i];
			gotoXY(6, 6 + i * 4); cout << "                              ";
		}
		gotoXY(24, 7);
		int chon = Menukey();
		switch (chon)
		{
			case 1:
			{
				
				PTRKHOAHOC DSKHOAHOC = NULL;
				PTRMONHOC DSMONHOC = NULL;
				DocFileKhoaHoc(DSKHOAHOC);
				DocFileMonHoc(DSMONHOC);
				MenuKhoaHoc(DSKHOAHOC, DSMONHOC, phanquyen);
				break;
			}
			case 2:
			{
			system("cls");
				system("color F0");
				TREE tree;
				initEmpty(tree);
				docAllFile(tree);
				huongDan();
				khungMain(tree,phanquyen);
				
				break;	
			}
			case 3:
			{
				PTRLOP DSLOP = NULL;
				PTRKHOA DSKHOA = NULL;
				PTRKHOAHOC DSKHOAHOC = NULL;
				DocFileLop(DSLOP);
				DocFileKhoa(DSKHOA);
				DocFileKhoaHoc(DSKHOAHOC);
				MenuKT(DSLOP, DSKHOAHOC, DSKHOA, phanquyen);
				break;
			}
			case 4:
			{
				Yescursortype();
				system("color 6");
				hide_scrollbar();
				Yescursortype();
				SetColor(255);
				PtrDiem TreeDiem;
				TreeDiem = NULL;
				DocFileTreeDiem(TreeDiem);
				int chon;
				do{
					chon = ShowMenuTienDo();
					if(chon == 0){
						if(phanquyen == true)
						{
							ThaoTacShowLop(TreeDiem);
						}
						else{
							GhiChu("BAN KHONG CO QUYEN THUC THI CHUC NANG NAY!", 60, 14, 2000);
								
						}
					}
					else if(chon == 1){
						ThaoTacShowDiemCua1SV(TreeDiem);
					}
				}
				while(chon!=2);
				break;
				
			}
			case 5:
			{
				system("cls");
				system("color F0");
				thongKeKQSV();
				break;	
			}
			case 6:
			{
				if(phanquyen == true){
					cout << "\a";
					GhiChu("BAN DA DANG XUAT, XEM VOI TU CACH SINH VIEN", 2, 44, 2000);
					phanquyen = false;
					break;
				}
				else{
					system("cls");
					phanquyen = Login();
				}
				break;
			}
			
			case 7:
			{
				system("cls");
				cout << "\a";
			//	Khung_Thoat();
				exit(0); break;
			}
			
		}
	}

} 
int main()
{
	fullscreen();
	remove_scrollbar();
	MENUCHINH();
	system("pause");
	return 0;
}
