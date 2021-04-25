#ifndef nhap_xuat_file
#define nhap_xuat_file
#include<iostream>
#include<fstream>
#include<conio.h>
#include<stdio.h>
#include "Xu_ly.h"
#define file_may_bay "may_bay.txt"
#define file_chuyen_bay "chuyen_bay.txt"
#define file_hanh_khach "hanh_khach.txt"
#define file_danh_sach_ve "danh_sach_ve.txt"



void Save_file_may_bay(ds_may_bay &dsmb,char *filename) {
 FILE * f;
 if ((f=fopen(filename,"wb"))==NULL)
 {  
 cout<<"Khong the ket noi voi file!"<<endl;
 return;
 }
 for (int i=0; i < dsmb.n; i++){
 	
   fwrite (dsmb.data[i], sizeof(may_bay),1,f);
 }
 	fclose(f);
// cout<<"Ghi thanh cong!"<<endl;
}
void Open_file_may_bay(ds_may_bay &dsmb, char *filename) {
 FILE * f;
  may_bay mb;
 if ((f=fopen(filename,"rb"))==NULL)
 {  
 	cout<<"Khong the ket noi voi file!"<<endl;
 	return;
 }
 dsmb.n=0;
 while  (fread (&mb, sizeof (may_bay), 1, f)!=0) {
 	dsmb.data[dsmb.n]=new may_bay;
 	*dsmb.data[dsmb.n]=mb;
 	dsmb.n ++;
 }
// cout<<"Mo file thanh cong!"<<endl;
 
}



void Save_file_chuyen_bay(PTR_chuyenbay &phead_cb,char *filename1, char *filename2){

 FILE * f1;
 FILE *f2;
 if ((f1=fopen(filename1,"wb"))==NULL)
 {  	cout<<"Duong dan luu file bi loi!"<<endl;
 		 return ;
 }
 if((f2=fopen(filename2,"wb"))==NULL){
 	cout<<"Duong dan file bi loi!"<<endl;
 	return;
 }
 
 PTR_chuyenbay ptr=phead_cb;
 while(ptr!=NULL){
 	fwrite(&(ptr->data), sizeof(chuyen_bay), 1, f1);
	
	
		for(int i=0;i<ptr->data.danh_sach_ve.n;i++){
 		fwrite(ptr->data.danh_sach_ve.so_ghe[i],sizeof(ve),1,f2);
	}
 	ptr=ptr->pnext;
 }
 
 fclose(f1);
 fclose(f2);
// cout<<"Da luu vao file thanh cong!"<<endl;

}
void Open_file_chuyen_bay(PTR_chuyenbay &phead_cb , char *filename1,char *filename2){
 FILE * f1;
 FILE *f2; 
 chuyen_bay cb;
 ve ticket;
 if ((f1=fopen(filename1,"rb"))==NULL)
 {  cout<<"Duong dan file bi loi"<<endl;
 	return ;
 }
 if ((f2=fopen(filename2,"rb"))==NULL)
 {  cout<<"Duong dan file bi loi"<<endl;
 	return ;
 }
 
 //xoa du lieu khi doc file!
 while(phead_cb!=NULL){
			node_cb*ptemp=phead_cb;
			phead_cb=phead_cb->pnext;
			
			delete ptemp;
			ptemp=NULL;
		}

//bat dau doc file.
 while(fread (&cb, sizeof (chuyen_bay), 1, f1)!=0) {
 	
 	ve temp_ve;
 	


	 	initialize_ve(cb.danh_sach_ve,cb.danh_sach_ve.limit,cb.danh_sach_ve.n);
 	
 		for(int i=0;i<cb.danh_sach_ve.n;i++){
 			fread ((cb.danh_sach_ve.so_ghe[i]), sizeof (ve), 1, f2);
	 	}
 	
 	
 	if(check_depart_time(cb.depart_time)==false){
 		free_memory(cb.danh_sach_ve);
	 }
 	
 	node_cb *temp_node=new node_cb;
 	temp_node->data=cb;
 	temp_node->pnext=NULL;
 	
 	
 	if(phead_cb==NULL){
		phead_cb=temp_node;
	}
	else{
		temp_node->pnext=phead_dscb;
		phead_dscb=temp_node;
	}
 }
 fclose(f1);
 fclose(f2);
// cout<<"Doc du lieu thanh cong!"<<endl;
}


//==========================HANH KHACH ============================

//save file theo hinh thuc NLR
 void output_hanh_khach(NODE_hanhkhach root_hk,FILE *f){
	if(root_hk!=NULL){
	fwrite (&root_hk->data, sizeof (hanh_khach), 1, f);
 	output_hanh_khach(root_hk->left,f);
 	output_hanh_khach(root_hk->right,f);
 	}
}
void Save_file_hanh_khach(NODE_hanhkhach &root_hk,char *filename){

	FILE *f;
 if ((f=fopen(filename,"wb"))==NULL)
 {  	cout<<"Duong dan luu file bi loi!"<<endl;
 		 return ;
 }
//ROOT_hanhkhach temp_root=root_hk;
output_hanh_khach(root_hk,f);
fclose(f);
//cout<<"Ghi file thanh cong!"<<endl;
 
}

void Open_file_hanh_khach(NODE_hanhkhach &root_hk , char *filename){
	
	FILE * f; 
	hanh_khach hk;
	node_hk *p;// ~PTR_hanhkhach
	
	
 if ((f=fopen(filename,"rb"))==NULL)
 {  cout<<"Duong dan file bi loi"<<endl;
 	return;
 }
 
 
while(fread (&hk, sizeof (hanh_khach), 1, f)!=0){

	
	insert_node_hk(root_hk,hk);
	
} 
fclose(f);
}
#endif









