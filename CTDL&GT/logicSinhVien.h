#include"qll.h"
#include"dinhDangVaoRa.h"

// tao doi tuong sinh vien 
struct SinhVien{
	char maSinhVien[200];
	char tenSinhVien[200];
	char lopSinhVien[200];
	char soDienThoai[200];
	char cmnd[200];
	
};
//end tao doi tuong sinh vien 

// tao doi tuong node sinh vien thanh phan cua cay nhi phan
struct nodeSinhVien{
	SinhVien sv;
	nodeSinhVien *pLeft;
	nodeSinhVien *pRight;
};
// end doi tuong node sinh vien thanh phan cua cay nhi phan
typedef struct nodeSinhVien SinhVienItem;
typedef SinhVienItem *TREE;
TREE root1 = NULL;

// ham xoa thong bao ben giao dien
void xoaTB(){
		
	for(int i = 20; i<31;i++){
		gotoxy(2,i);
		cout<<"                                      ";
		
	}
}
//end ham xoa thong bao 

//ham search sinh vien tham so la tree va ma so sinh vien tra ve sinh vien 
SinhVienItem* searchSinhVien(TREE t,char maSinhVien[] )
{
	// neu tree khong co cai gi thi chung ta tra ve la null --> ko co sv thoa
	if (t == NULL)
	{
		return NULL;
	}
	// nguoc lai
	else
	{
		// MSSV nho hon thi tiep tuc tim ve ben trai
		if (strcmp(maSinhVien,t->sv.maSinhVien)<0)
		{
			searchSinhVien(t->pLeft, maSinhVien);
		}
		// nguoc lai lon hon thi tiep tuc tim ve ben phai
		else if (strcmp(maSinhVien,t->sv.maSinhVien)>0)
		{
			searchSinhVien(t->pRight, maSinhVien);
		}
		// nguoc lai bang thi da thim thay roi nha
		else
		{
			return t; 
		}
	}

}
//end ham search 

// tao cay rong 
 void initEmpty(TREE &t){
 	t = NULL;
 }
// end cua tao cay rong 

//tao sinh vien voi tat ca tham so lien quan den sinh vien va tra ve dia chi sinh vien 
SinhVien createSinhVien(char maSinhVien[],char tenSinhVien[],char lopSinhVien[],char soDienThoai[],char cmnd[]){
	SinhVien sv ;
		strcpy(sv.maSinhVien,maSinhVien);
		strcpy(sv.tenSinhVien,tenSinhVien);
		strcpy(sv.lopSinhVien,lopSinhVien);
		strcpy(sv.soDienThoai,soDienThoai);
		strcpy(sv.cmnd,cmnd);
		return sv;
	
}
// end cua ham create sinh vien tra ve sinh vien

// toArr dua du lieu doc duoc thi file den mang chung duy nhat la mang sinhvien 
void ToArr(char fileName[],SinhVien sinhVien[],int &count){
	//tao bien sinh vien de doc cai file nhi phan len
	SinhVien sv;
	const char *ten=fileName;
	fstream fh(ten,ios::in|ios::binary );
	//y tuong xin so code o duoi tranh truong hop mo file hk co gi ma doc len gay loi
	if(fh.read(reinterpret_cast<char *>(&sv), sizeof(sv))){
		fh.close();
		fstream fk(ten,ios::in|ios::binary);
		while(fk.read(reinterpret_cast<char *>(&sv), sizeof(sv))){
			strcpy(sinhVien[count].maSinhVien,sv.maSinhVien);
			strcpy(sinhVien[count].tenSinhVien,sv.tenSinhVien);
			strcpy(sinhVien[count].lopSinhVien,sv.lopSinhVien);
			strcpy(sinhVien[count].soDienThoai,sv.soDienThoai);
			strcpy(sinhVien[count].cmnd,sv.cmnd);
			count++;
		}
		fk.close();
	}
			
	
}
//end cua ham toArr

//demSV theo file phuc vu cho viec dem tat ca sinh vien 
void demSV(char fileName[],int &dem){
	SinhVien sv;	
	const char *ten=fileName;
	fstream fh(ten,ios::in|ios::binary );
	if(fh.read(reinterpret_cast<char *>(&sv), sizeof(sv))){
		fh.close();
		fstream fk(ten,ios::in|ios::binary);
		while(fk.read(reinterpret_cast<char *>(&sv), sizeof(sv))){
			dem++;	
		}
		fk.close();
		}

}
//end dem sinh vien 

//dem so luong tat ca sinh vien 
int demAllFile(){
	
	int count =0,cc=0;
	PTRLOP DSLOP = NULL;
	DocFileLop(DSLOP);
	int dem =DemLopHoc(DSLOP);
	LopHoc *lop = new LopHoc[100];
	MangTam_Lop(DSLOP,lop,cc);
	for(int i =0 ; i < dem; i++){
		char fileName[200];
		strcpy(fileName,lop[i].Idlop);
		demSV(fileName,count);
		
		
	}
	return count ;
	
}
//end dem sinh vien

//them vao cay
void InsertNode_SV(TREE &t, SinhVien sv) {
	// neu tim duoc mot vi tri rong hoac cay ban dau la rong thi tao doi tuong coppy vung du lieu them vao 
	if (t==NULL) {
		TREE p = new SinhVienItem;
		strcpy(p->sv.maSinhVien,sv.maSinhVien);
		strcpy(p->sv.tenSinhVien,sv.tenSinhVien);
		strcpy(p->sv.lopSinhVien,sv.lopSinhVien);
		strcpy(p->sv.soDienThoai,sv.soDienThoai);
		strcpy(p->sv.cmnd,sv.cmnd);
		p->pLeft =NULL;
		p->pRight = NULL;
		t = p;
	}
	
	else {
		// di ve ben trai 
		if ( 0> strcmp( sv.maSinhVien, t->sv.maSinhVien)) {
			InsertNode_SV(t->pLeft, sv);
		}
		// di ve ben phai
		else 	if (0 < strcmp(sv.maSinhVien, t->sv.maSinhVien)){
			InsertNode_SV(t->pRight, sv);
		}
	}
}
//end them vao cay 

// dem sinh vien ton tai tren tree bang thuat toan duyet cay LRN
int countSV(TREE t) {
	//node la dem len 1 hong phai la thi tiep tuc de quy 
	if (t != NULL)
	{
		return (countSV(t->pLeft) + countSV(t->pRight) + 1);
	}
	else return 0;
}
//end cua ham dem sinh vien tren cay 

//doc tat ca cac file va them vao TREE tra ve la cai cay nhi phan tim kiem
//y tuong lay ve list lop dung list lop doc len mang duy nhat roi them no vao cay thoi
void docAllFile(TREE &t){
	int sizeTree = demAllFile();
	
	SinhVien listSinhVien[sizeTree];
	char fileName[200];
	PTRLOP DSLOP = NULL;
	DocFileLop(DSLOP);
	int dem =DemLopHoc(DSLOP);
	int cc=0,count = 0;
	LopHoc lop[dem];
	MangTam_Lop(DSLOP,lop,cc);
	
	for(int i =0 ; i < dem; i++){
		strcpy(fileName,lop[i].Idlop);
		ToArr(fileName,listSinhVien,count);
	}
	//them vao cay thoi nao
	for(int i = 0 ; i < demAllFile();i++){
	InsertNode_SV(t,(listSinhVien[i]));	
	}
	
}
//end cua ham doc tat ca cac file

//mang tam tat ca sinh vien de lam gi u luu vao file day haha
void listTampAllSV(TREE tree, SinhVien listSinhVien[], int &dem) {
	//phep duyet LNR
	// di ma den het left thay la lay no lay node goc lay right neu right ko la la tiep tuc de quy roi de quy haha 
	if (tree != NULL)
	{
		listTampAllSV(tree->pLeft, listSinhVien, dem);
		listSinhVien[dem++] = tree->sv;
		listTampAllSV(tree->pRight, listSinhVien, dem);
	}
}
//end cua ham list tam all sinh vien 

//dem so sinh vien cua lop phuc vu cho viec  show theo lop day ahihi 
int demSVTrongLop(SinhVien listSinhVien[],char fileName[],int sizeTree){
	int dem = 0;
	for(int i = 0 ; i < sizeTree; i++){
		if(strcmp(fileName,listSinhVien[i].lopSinhVien)==0){
			dem++;
		}
	}
	return dem;
}
//end dem sinh vien co trong 1 lop 

//mang tamp  sinh vien theo lop nha ihihi
void listTampCLass(SinhVien listSinhVienLop[],SinhVien listSinhVien[],char fileName[],int sizeTree){
	int dem=0;
	for(int i = 0 ; i < sizeTree; i++){
		if(strcmp(fileName,listSinhVien[i].lopSinhVien)==0){
			listSinhVienLop[dem] = listSinhVien[i];
			dem++;
		}
	}
}
//end mang tam sinh vien theo lop 

// tao tat ca cac cai file lop rong 
//y tuong la mo file len ung moi ma lop trong list lop mo no len roi dong no vao thi no tao thoi ahihi
void createAllFileClassEmpty(){
	char fileName[200];
	PTRLOP DSLOP = NULL;
	DocFileLop(DSLOP);
	int dem =DemLopHoc(DSLOP);
	int cc=0,count = 0;
	LopHoc lop[dem];
	MangTam_Lop(DSLOP,lop,cc);
	
	for(int i =0 ; i < dem; i++){
		strcpy(fileName,lop[i].Idlop);
		const char *ten=fileName;
		fstream fh(ten,ios::out | ios::binary );
		fh.close();
		
	}
}
//end tao tat ca cac file lop rong 

//ghi sinh vien vao file va day la ghi noi tiep phuc vu cho ham ghi lai nao
bool ghiFile(char fileName[],SinhVien sv){
	
	const char *ten=fileName;
	fstream fh(ten,ios::app | ios::binary );

	if(!fh){
		return false;
	}
	else{
		fh.write(reinterpret_cast<char *>(&sv), sizeof(sv));
}
	fh.close();

		return true;


}
// end ghi file sinh vien vao lop

//them sinh vien
void cn1ThemSinhVien(char maSinhVien[],char tenSinhVien[],char lopSinhVien[],char soDienThoai[],char cmnd[],TREE &tree){
	//tao arr lop tam chua tat ca cac lop
	PTRLOP DSLOP = NULL;
	DocFileLop(DSLOP);
	int dem =DemLopHoc(DSLOP),flag =0;
	int cc=0;
	LopHoc *lop = new LopHoc[100];
	MangTam_Lop(DSLOP,lop,cc);
	//lopTamp luu lai ten lop ung voi ten file day ahihi
	char lopTamp[200];
	//kiem tra xem lop nay da ton tai hay chua tho a ma
	for(int i =0 ; i < dem; i++){
		strcpy(lopTamp,lop[i].Idlop);	
		if(strcmp(lopSinhVien,lopTamp)==0){
			flag = 1;
			break;
		}
	}
//	end cua kie tra nha 
//	neu la da ton tai thi them thoi nao 
	if(flag == 1){
		SinhVienItem *sv= searchSinhVien(tree,maSinhVien);
		if(sv!=NULL){
			xoaTB();
			gotoxy(2,20);
			cout<<"ma sinh vien da ton tai roi nha";
			
		}else if(sv==NULL){
			SinhVien svAdd;
			svAdd = createSinhVien(maSinhVien,tenSinhVien,lopSinhVien,soDienThoai,cmnd);
			//insert sinh vien nay vao cay	
			InsertNode_SV(tree,svAdd);
				xoaTB();
				gotoxy(2,20);
				cout<<"Them Thanh cong ";
		}
		
	}else if(flag == 0){
		//call ham thong bao
			xoaTB();
			gotoxy(2,20);
			cout<<"lop sinh vien k0 ton tai nha";
	}
}
// end chuc nang the sinh vien 

// day la ham ghi lai tat ca sinh vien tren caay vao file cua chung ta do ahihi
//ghi noi tiep noi sinh vien vao file y tuong lay duyet tat ca sinh vien va luu tung sinh vien vao ung voi lop cua no
void ghiLaiNao(TREE tree){
	createAllFileClassEmpty();
	int dem = 0,sizeTree = countSV(tree); 
	SinhVien listSinhVien [sizeTree];
	listTampAllSV(tree,listSinhVien,dem);
	char fileName [200];
	// ung voi tung sinh vien ta luu noi tiep vao lop tuong ung thoi nha
	for(int i = 0 ; i < sizeTree; i++){
		strcpy(fileName,listSinhVien[i].lopSinhVien);
		ghiFile(fileName,listSinhVien[i]);
	}
}
//end cua ghi lai nao 

//duyet node left right o day 
void NLR(TREE t)
{
	if (t != NULL)
	{
		
		cout << t->sv.tenSinhVien << "  ";
		NLR(t->pLeft);
		NLR(t->pRight);
	}
}
//void NodeTheMang(TREE X, TREE Y)
//{
//	if (Y->pRight != NULL)
//	{
//		NodeTheMang(X, Y->pRight);
//	}
//	else
//	{
//		X->sv = Y->sv;
//		X = Y;
//		Y = Y->pLeft;
//	}
//}
//
//
//void DiTimNodeTheMang(TREE X, TREE Y) {
//
//	if (Y->pLeft != NULL)
//	{
//		DiTimNodeTheMang(X, Y->pLeft);
//	}
//	else //day la thang hy sinh tim met vai
//	{
//		X->sv = Y->sv; 
//		X = Y;
//		Y = Y->pRight;
//	}
//}
//
//
//void XoaNode(TREE &t, char  data[]) // data chính là giá tr? c?a cái node c?n xóa
//{
//	if (t == NULL)
//	{
//		return; 
//	}
//	else
//	{
//		if (strcmp(data,t->sv.maSinhVien)<0);
//		{
//			XoaNode(t->pLeft, data); 
//		}
//		 if (strcmp(data,t->sv.maSinhVien)>0)
//		{
//			XoaNode(t->pRight, data); 
//		}
//		else 
//		{
//			SinhVienItem *X = t;
//
//			if (t->pLeft == NULL)
//			{
//				t = t->pRight; 
//			}
//			else if (t->pRight == NULL)
//			{
//				t = t->pLeft;
//			}
//			else
//			{
//				
//				DiTimNodeTheMang(X, t->pRight);
//			
//				//DiTimNodeTheMang(X, t->pLeft);
//			}
//			delete X;
//		}
//	}
//}
//
//SinhVienItem* minValueNode(SinhVienItem* node) 
//{ 
//    SinhVienItem * current = node; 
//  
//    /* loop down to find the leftmost leaf */
//    while (current && current->pLeft != NULL) 
//        current = current->pLeft; 
//  
//    return current; 
//} 
//
//TREE deleteNode( TREE root, char key[]) 
//{ 
//    // base case 
//    if (root == NULL) return root; 
//  
//    // If the key to be deleted is smaller than the root's key, 
//    // then it lies in left subtree 
//    
//    if (strcmp(key,root->sv.maSinhVien)<0) 
//        root->pLeft = deleteNode(root->pLeft, key);  
//    else if (strcmp(key,root->sv.maSinhVien)>0)
//        root->pRight = deleteNode(root->pRight, key); 
//  
//    // if key is same as root's key, then This is the node 
//    // to be deleted 
//    else
//    { 
//        // node with only one child or no child 
//        if (root->pLeft == NULL) 
//        { 
//             SinhVienItem *temp = root->pRight; 
//            free(root); 
//            return temp; 
//        } 
//        else if (root->pRight == NULL) 
//        { 
//            SinhVienItem *temp = root->pLeft; 
//            free(root); 
//            return temp; 
//        } 
//  
//        // node with two children: Get the inorder successor (smallest 
//        // in the right subtree) 
//        SinhVienItem* temp = minValueNode(root->pRight); 
//  
//        // Copy the inorder successor's content to this node 
//        root->sv = temp->sv; 
//  
//        // Delete the inorder successor 
//        root->pRight = deleteNode(root->pRight, temp->sv.maSinhVien); 
//    } 
//    return root; 
//} 
// tim thang the mang de xoa ung voi truong hop co 2 con
void xoaNodeFromTree1 ( TREE &r,TREE &rp )
{
	// di mai cho den khi no null thi thoi
	if (r->pLeft != NULL)
		xoaNodeFromTree1 (r->pLeft,rp);
		//den day r la nut cuc trai cua cay con ben phai co nut goc la rp}
	else
	{
		//rp->key = r->key coppy Chep noi dung cua r sang rp ";
		rp->sv =r->sv; 
		// quay ve truong hop xoa node voi 1 cay con ben phai thi cho no tro den ben phai ahihi
		rp = r;
		r = rp->pRight;
	}
}
//end cua no 

//ham xoa chinh 
void xoaNodeFromTree (char x[] , TREE &p )
{
	TREE rp;//rp remove_P la cai thang tro dem cai ma minh muon cho no ra di
	// cai nay co cho vui ai xai lai thi xai 
	if( p== root1 && p->pLeft ==NULL && p->pRight==NULL)
	{
		rp=p;
		root1=NULL;
		delete rp;
		return;
	}
	// case NULL nay cung co cho vui hihi
	if (p == NULL) {
		printf ("Khong tim thay");
	}
	//day moi thuc su bat dau vao xoa
	else
	//neu nho hon thi di ve trai lon thi ve phai
		if (strcmp(x,p->sv.maSinhVien)<0) xoaNodeFromTree (x, p->pLeft);
		else if (strcmp(x,p->sv.maSinhVien)>0)
		xoaNodeFromTree (x, p->pRight);
		else // p->key = x thi xoa no di
		{
			rp = p;
			if (rp->pRight == NULL) p = rp->pLeft;
			// p là nút lá hoac la nut chi co cay con ben trai
			//la la thi null va xoa di ben phai null thi ben trai thay the va phai trai null thi phai thay the 
			else if (rp->pLeft == NULL)
				p = rp->pRight; // p là nut co cay con ben phai 
//				di tim trai nhat ben phai
			else xoaNodeFromTree1 (rp->pRight,rp);
			delete rp;
		}
}
//end ham xoa chinh 





