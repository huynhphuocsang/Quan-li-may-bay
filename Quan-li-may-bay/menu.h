#ifndef menu
#define menu
#include "io.h"

//************************************************MENU********************************************************//
//Ham nhan chuc nang nguoi dung muon 
void Chon_chucnang(){
	//==================DOC DU LIEU===========================
		Open_file_may_bay(dsmb,file_may_bay);
		Open_file_hanh_khach(root_hk,file_hanh_khach);
		Open_file_chuyen_bay(phead_dscb,file_chuyen_bay,file_danh_sach_ve);
		//thiet lap trang thai chuyen bay
		update_statement(phead_dscb);
		resizeConsole(150,45);
		ShowConsoleCursor(false);
		Giaodien_main();
	while(1){
	    
		char temp_macb[15] = "";
		char temp_cmnd[10] = "";
		PTR_chuyenbay check=NULL;
		ve_thanhcongcu();
		int i =0;int x=4,ktra;
		while(!kbhit()){
			Logo(7,10);
			Sleep(200);
		}
		i=Nhanphim();
		if (i!=27){
			Xoa_khunhap(); 
		while(1){
			int j;
			switch (x){
		    	case 4:{
		    		string danhsach_chucnang[3]={"             THEM            ","             XOA             ","          HIEU CHINH         "};
		    		string s="     QUAN LY MAY BAY         ";
		    		Ve_congcu(x,s);
        			In_chucnang(x,3,danhsach_chucnang);
        			int y=3;
        			ve_hcnrong(x,y,31,3);
        			Chuyenmau(x+1,y+1,3,0,danhsach_chucnang[y-3]);
        			ve_gioithieu(138,20);
        			gioi_thieu(1);
        			while(1){
        				j=Nhanphim();
        				if(j==80){
        					switch(y){
        					case 3:{
        						gioi_thieu(2);
								Chuyenmau(x+1,y+1,11,0,danhsach_chucnang[0]);
        						y+=3;
        						Chuyenmau(x+1,y+1,3,0,danhsach_chucnang[1]);
        						break;
								} 
							case 6:{
								gioi_thieu(3);
        						Chuyenmau(x+1,y+1,11,0,danhsach_chucnang[1]);
        						y+=3;
        						Chuyenmau(x+1,y+1,3,0,danhsach_chucnang[2]);
        						break;
								} 
							case 9:{
								gioi_thieu(1);
        						Chuyenmau(x+1,y+1,11,0,danhsach_chucnang[2]);
        						y=3;
        						Chuyenmau(x+1,y+1,3,0,danhsach_chucnang[0]);
        						break;
								} 
							}
						}
						if(j==72){
							switch(y){
        					case 3:{
        						gioi_thieu(3);
        						Chuyenmau(x+1,y+1,11,0,danhsach_chucnang[0]);
        						y=9;
        						Chuyenmau(x+1,y+1,3,0,danhsach_chucnang[2]);
        						break;
								} 
							case 6:{
								gioi_thieu(1);
        						Chuyenmau(x+1,y+1,11,0,danhsach_chucnang[1]);
        						y-=3;
        						Chuyenmau(x+1,y+1,3,0,danhsach_chucnang[0]);
        						break;
								} 
							case 9:{
								gioi_thieu(2);
        						Chuyenmau(x+1,y+1,11,0,danhsach_chucnang[2]);
        						y-=3;
        						Chuyenmau(x+1,y+1,3,0,danhsach_chucnang[1]);
        						break;
								} 
							}
						}
						if (j==13){
        					Xoa_chucnang(x,11,s);
        					xoa_gt(1);
        					//Lenh khi chon bang phim ENTER
        					SetBGColor(15);
        					if (y==3){
        						int n=0;
								ve_hcnrong(42+20,12,23,3); 
								gotoxy(63,13);
								SetBGColor(11);
								cout<<"So luong may bay :   ";
								ShowConsoleCursor(true);
								while(true){
									do{
										ktra =0;
										Nhan_so(n,81,13,2,ktra);
									}while( n == 0);
										if (n+dsmb.n > 300){
											int result = MessageBox(NULL,"So luong may bay khong duoc qua 300\n Ban co muon nhap lai","THONG BAO",MB_ICONWARNING|MB_OKCANCEL);
											while(kbhit()) getch();
											if (result == IDCANCEL){
												Xoa_khunhap();
												break;
											}
										}else break;
								}
								
								SetBGColor(15);
								for (int t=1;t<=n;t++)
									add_new_MB(dsmb,n);	 
								
							} 
        					if (y==6) delete_may_bay(dsmb);
        					if (y==9) edit_maybay(dsmb);
        					break;
						}
						if (j==27){
							Xoa_chucnang(x,11,s);
							xoa_gt(1);
							break;
						} // dung khi nhan Esc
						if (j==75) {
							Xoa_chucnang(x,11,s);
							x=114; 
							break;
						}
						if (j==77) {
							Xoa_chucnang(x,11,s);
							x=40; 
							break;
						}
					}					
					break;
				}
				case 40:{
		    		string danhsach_chucnang[5]={"      LAP CHUYEN BAY MOI     ","     HIEU CHINH NGAY GIO     ","        CUA CHUYEN BAY       ","        HUY CHUYEN BAY       ","     IN DS CAC CHUYEN BAY    "};
		    		string s="     QUAN LY CHUYEN BAY      ";                                                                                    
		    		Ve_congcu(x,s);
        			In_chucnang(x,5,danhsach_chucnang);
        			int y=3;
        			ve_hcnrong(x,y,31,3);
        			Chuyenmau(x+1,y+1,3,0,danhsach_chucnang[y-3]);
        			gioi_thieu(4);
        			while(1){
        				j=Nhanphim();
        				if(j==80){
        					switch(y){
        					case 3:{
        						gioi_thieu(5);
        						Chuyenmau(x+1,y+1,11,0,danhsach_chucnang[0]);
        						y+=3;
        						Chuyenmau(x+1,y+1,3,0,danhsach_chucnang[1]);
        						Chuyenmau(x+1,y+2,3,0,danhsach_chucnang[2]);
        						break;
								} 
							case 6:{
								gioi_thieu(6);
        						Chuyenmau(x+1,y+1,11,0,danhsach_chucnang[1]);
        						Chuyenmau(x+1,y+2,11,0,danhsach_chucnang[2]);
        						y=10;
        						Chuyenmau(x+1,y+1,3,0,danhsach_chucnang[3]);
        						break;
								} 
							case 10:{
								gioi_thieu(41);
        						Chuyenmau(x+1,y+1,11,0,danhsach_chucnang[3]);
        						y=13;
        						Chuyenmau(x+1,y+1,3,0,danhsach_chucnang[4]);
        						break;
								} 
							case 13:{
								gioi_thieu(4);
        						Chuyenmau(x+1,y+1,11,0,danhsach_chucnang[4]);
        						y=3;
        						Chuyenmau(x+1,y+1,3,0,danhsach_chucnang[0]);
        						break;
								}
							}
						}
						if(j==72){
							switch(y){
        					case 3:{
        						gioi_thieu(41);
        						Chuyenmau(x+1,y+1,11,0,danhsach_chucnang[0]);
        						y=13;
        						Chuyenmau(x+1,y+1,3,0,danhsach_chucnang[4]);
        						break;
								} 
							case 6:{
								gioi_thieu(4);
        						Chuyenmau(x+1,y+1,11,0,danhsach_chucnang[1]);
        						Chuyenmau(x+1,y+2,11,0,danhsach_chucnang[2]);
        						y-=3;
        						Chuyenmau(x+1,y+1,3,0,danhsach_chucnang[0]);
        						break;
								} 
							case 10:{
								gioi_thieu(5);
        						Chuyenmau(x+1,y+1,11,0,danhsach_chucnang[3]);
        						y=6;
        						Chuyenmau(x+1,y+1,3,0,danhsach_chucnang[1]);
        						Chuyenmau(x+1,y+2,3,0,danhsach_chucnang[2]);
        						break;
								}
							case 13:{
        						gioi_thieu(6);
        						Chuyenmau(x+1,y+1,11,0,danhsach_chucnang[4]);
        						y=10;
        						Chuyenmau(x+1,y+1,3,0,danhsach_chucnang[3]);
        						break;
								} 
							}
						}
						if (j==13){
        					Xoa_chucnang(x,17,s);
        					xoa_gt(1);
        					//Lenh khi chon bang phim ENTER
        					SetBGColor(15);
        					if (y==3) add_new_ch_bay(phead_dscb);
        					if (y==6) edit_chuyen_bay(phead_dscb);
        					if (y==10) del_chuyen_bay(phead_dscb,dsmb);
        					if (y==13) traverse_chuyen_bay(phead_dscb);
        					break;
						}
						if (j==27) {
							Xoa_chucnang(x,17,s);
							xoa_gt(1);
							break;
						}
						if (j==75) {
							Xoa_chucnang(x,17,s);
							x=4; 
							break;
						}
						if (j==77) {
							Xoa_chucnang(x,17,s);
							x=78; 
							break;
						}
					}					
					break;
				}
				case 78:{
		    		string danhsach_chucnang[2]={"           DAT VE            ","           HUY VE            "};
        			string s="        DAT / HUY VE         ";
		    		Ve_congcu(x,s);
        			In_chucnang(x,2,danhsach_chucnang);
        			int y=3;
        			ve_hcnrong(x,y,31,3);
        			Chuyenmau(x+1,y+1,3,0,danhsach_chucnang[y-3]);
        			gioi_thieu(7);
        			while(1){
        				j=Nhanphim();
        				if(j==80 || j==72){
        					switch(y){
        					case 3:{
        						gioi_thieu(8);
        						Chuyenmau(x+1,y+1,11,0,danhsach_chucnang[0]);
        						y+=3;
        						Chuyenmau(x+1,y+1,3,0,danhsach_chucnang[1]);
        						break;
								} 
							case 6:{
								gioi_thieu(7);
        						Chuyenmau(x+1,y+1,11,0,danhsach_chucnang[1]);
        						y-=3;
        						Chuyenmau(x+1,y+1,3,0,danhsach_chucnang[0]);
        						break;
								} 
							}
						}
						if (j==13){
        					Xoa_chucnang(x,8,s);
        					xoa_gt(1);
        					//Lenh khi chon bang phim ENTER
        					gotoxy(20,20);
        					SetBGColor(15);
        					SetColor(0);
        					if (y==3) {
        						fflush(stdin);
        						update_statement(phead_dscb);
								do{
									memset(temp_macb,'\0',sizeof(temp_macb));
									Xoa_khunhap();
									ve_hcnrong(42,15,65,3); 
									gotoxy(44,16);
									SetBGColor(11);
									cout<<"Nhap vao Ma chuyen bay :                                     ";
									ShowConsoleCursor(true);
									fflush(stdin);
									do{
										ktra =3;
										Nhan_chu2(temp_macb,69,16,15,ktra);
									}while(strlen(temp_macb)==0);
										strupr(temp_macb);
									SetBGColor(15);
									ShowConsoleCursor(false);
									check=search_node(phead_dscb,temp_macb);
									
									if(check!=NULL && check->data.trang_thai==1){
										order_ve(phead_dscb,check,check->data.danh_sach_ve);
		
										break;
									}
									else if (check == NULL){
										int result = MessageBox(NULL,"Ma chuyen bay khong ton tai\n Ban co muon nhap lai","THONG BAO",MB_ICONWARNING|MB_OKCANCEL);
										while(kbhit()) getch();
										if (result == IDCANCEL){
											Xoa_khunhap();
											break;
										} 
									}
									else if(check->data.trang_thai==3){
										int result = MessageBox(NULL,"Chuyen bay nay da thuc hien!\n Ban co muon nhap lai","THONG BAO",MB_ICONWARNING|MB_OKCANCEL);
										while(kbhit()) getch();
										if (result == IDCANCEL){
											Xoa_khunhap();
											break;
										}
									}
									else if(check->data.trang_thai==0){
										int result = MessageBox(NULL,"Chuyen bay nay da bi huy!\n Ban co muon nhap lai","THONG BAO",MB_ICONWARNING|MB_OKCANCEL);
										while(kbhit()) getch();
										if (result == IDCANCEL){
											Xoa_khunhap();
											break;
										}
									}
									else if(check->data.trang_thai==2){
										int result = MessageBox(NULL,"Chuyen bay nay da het ve!\n Ban co muon nhap lai","THONG BAO",MB_ICONWARNING|MB_OKCANCEL);
										while(kbhit()) getch();
										if (result == IDCANCEL){
											Xoa_khunhap();
											break;
										}
									}
								}while(true);
							}	
        					if (y==6){
        						fflush(stdin);
        						do{
        							Xoa_khunhap();
        							memset(temp_macb,'\0',sizeof(temp_macb));
									ve_hcnrong(42,15,65,3); 
									gotoxy(44,16);
									SetBGColor(11);
									cout<<"Nhap vao Ma chuyen bay :                                     ";
									ShowConsoleCursor(true);
									fflush(stdin);
									do{
										ktra =4;
										Nhan_chu2(temp_macb,69,16,15,ktra);
									}while(strlen(temp_macb)==0);
										strupr(temp_macb);
									SetBGColor(15);
									ShowConsoleCursor(false);
									check=search_node(phead_dscb,temp_macb);
									if (check!=NULL && check->data.trang_thai == 0){
										int result = MessageBox(NULL,"Chuyen bay da bi huy\n Ban co muon nhap lai","THONG BAO",MB_ICONWARNING|MB_OKCANCEL);
										while(kbhit()) getch();
										if (result == IDCANCEL){
											Xoa_khunhap();
											break;
										}
									}
									if (check!=NULL && check->data.trang_thai == 3){
										int result = MessageBox(NULL,"Chuyen bay da hoan tat khong duoc huy ve\n Ban co muon nhap lai","THONG BAO",MB_ICONHAND|MB_OKCANCEL);
										while(kbhit()) getch();
										if (result == IDCANCEL){
											Xoa_khunhap();
											break;
										}
									}
									if (check != NULL && check->data.trang_thai != 3 && check->data.trang_thai != 0 && check->data.danh_sach_ve.n == 0 ){
										int result = MessageBox(NULL,"Danh sach hanh khach trong \n Ban co muon nhap lai","THONG BAO",MB_ICONWARNING|MB_OKCANCEL);
										while(kbhit()) getch();
										if (result == IDCANCEL){
											Xoa_khunhap();
											break;
										}
									}
									else if(check!=NULL && check->data.trang_thai != 3 && check->data.trang_thai != 0){
										Xoa_khunhap();
										remove_ve(check->data.danh_sach_ve);
										break;
									}
									if (check == NULL){
										int result = MessageBox(NULL,"Ma chuyen bay khong ton tai\n Ban co muon nhap lai","THONG BAO",MB_ICONWARNING|MB_OKCANCEL);
										while(kbhit()) getch();
										if (result == IDCANCEL){
											Xoa_khunhap();
											break;
										} 
									}
								}while(true);
							} 
        					break;
						}
						if (j==27){
							Xoa_chucnang(x,8,s);
							xoa_gt(1);
							break;
						} 
						if (j==75) {
							Xoa_chucnang(x,8,s);
							x=40; 
							break;
						}
						if (j==77) {
							Xoa_chucnang(x,8,s);
							x=114; 
							break;
						}
					}					
					break;
				}
				case 114:{
		    		string danhsach_chucnang[8]={"  IN DS HK CUA 1 CHUYEN BAY  ","    IN DS CAC CHUYEN BAY     ","         KHOI HANH           ","  IN DS CAC VE CON TRONG CUA ","          CHUYEN BAY         ","  THONG KE SO LUOT THUC HIEN ","       CUA CAC MAY BAY       ","   IN DS TAT CA HANH KHACH   "};
        			string s="      THONG KE DU LIEU       ";					 		
		    		Ve_congcu(x,s);
        			In_chucnang(x,8,danhsach_chucnang);
        			int y=3;
        			ve_hcnrong(x,y,31,3);
        			Chuyenmau(x+1,y+1,3,0,danhsach_chucnang[y-3]);
        			gioi_thieu(9);
        			while(1){
        				j=Nhanphim();
        				if(j==80){
        					switch(y){
        					case 3:{
        						gioi_thieu(10);
        						Chuyenmau(x+1,y+1,11,0,danhsach_chucnang[0]);
        						y+=3;
        						Chuyenmau(x+1,y+1,3,0,danhsach_chucnang[1]);
        						Chuyenmau(x+1,y+2,3,0,danhsach_chucnang[2]);
        						break;
								} 
							case 6:{
								gioi_thieu(11);
        						Chuyenmau(x+1,y+1,11,0,danhsach_chucnang[1]);
        						Chuyenmau(x+1,y+2,11,0,danhsach_chucnang[2]);
        						y+=4;
        						Chuyenmau(x+1,y+1,3,0,danhsach_chucnang[3]);
        						Chuyenmau(x+1,y+2,3,0,danhsach_chucnang[4]);
        						break;
								} 
							case 10:{
								gioi_thieu(12);
        						Chuyenmau(x+1,y+1,11,0,danhsach_chucnang[3]);
        						Chuyenmau(x+1,y+2,11,0,danhsach_chucnang[4]);
        						y+=4;
        						Chuyenmau(x+1,y+1,3,0,danhsach_chucnang[5]);
        						Chuyenmau(x+1,y+2,3,0,danhsach_chucnang[6]);
        						break;
								} 
							case 14:{
								gioi_thieu(91);
								Chuyenmau(x+1,y+1,11,0,danhsach_chucnang[5]);
        						Chuyenmau(x+1,y+2,11,0,danhsach_chucnang[6]);
								y=18;
        						Chuyenmau(x+1,y+1,3,0,danhsach_chucnang[7]);
								break;
							}
							case 18:{
								gioi_thieu(9);
								Chuyenmau(x+1,y+1,11,0,danhsach_chucnang[7]);
								y=3;
        						Chuyenmau(x+1,y+1,3,0,danhsach_chucnang[0]);
								break;
							}
							}
						}
						if(j==72){
							switch(y){
        					case 3:{
        						gioi_thieu(91);
        						Chuyenmau(x+1,y+1,11,0,danhsach_chucnang[0]);
        						y=18;
        						Chuyenmau(x+1,y+1,3,0,danhsach_chucnang[7]);
        						break;
								} 
							case 6:{
								gioi_thieu(9);
        						Chuyenmau(x+1,y+1,11,0,danhsach_chucnang[1]);
        						Chuyenmau(x+1,y+2,11,0,danhsach_chucnang[2]);
        						y-=3;
        						Chuyenmau(x+1,y+1,3,0,danhsach_chucnang[0]);
        						break;
								} 
							case 10:{
								gioi_thieu(10);
        						Chuyenmau(x+1,y+1,11,0,danhsach_chucnang[3]);
        						Chuyenmau(x+1,y+2,11,0,danhsach_chucnang[4]);
        						y-=4;
        						Chuyenmau(x+1,y+1,3,0,danhsach_chucnang[1]);
        						Chuyenmau(x+1,y+2,3,0,danhsach_chucnang[2]);
        						break;
								} 
							case 14:{
								gioi_thieu(11);
								Chuyenmau(x+1,y+1,11,0,danhsach_chucnang[5]);
        						Chuyenmau(x+1,y+2,11,0,danhsach_chucnang[6]);
        						y-=4;
        						Chuyenmau(x+1,y+1,3,0,danhsach_chucnang[3]);
        						Chuyenmau(x+1,y+2,3,0,danhsach_chucnang[4]);
								break;
							}
							case 18:{
								gioi_thieu(12);
        						Chuyenmau(x+1,y+1,11,0,danhsach_chucnang[7]);
        						y=14;
        						Chuyenmau(x+1,y+1,3,0,danhsach_chucnang[5]);
        						Chuyenmau(x+1,y+2,3,0,danhsach_chucnang[6]);
								break;
							}
							}
						}
						if (j==13){
        					Xoa_chucnang(x,21,s);
        					xoa_gt(1);
        					//Lenh khi chon bang phim ENTER
        					gotoxy(20,20);
        					SetBGColor(15);
        					SetColor(0);
        					if (y==3){
        						fflush(stdin);
        						do{
									ve_hcnrong(42,15,65,3); 
									gotoxy(44,16);
									SetBGColor(11);
									cout<<"Nhap vao Ma chuyen bay :                                     ";
									ShowConsoleCursor(true);
									fflush(stdin);
									do{
										ktra =2;
										Nhan_chu2(temp_macb,69,16,15,ktra);
									}while(strlen(temp_macb)==0);
										strupr(temp_macb);
									SetBGColor(15);
									ShowConsoleCursor(false);
									check=search_node(phead_dscb,temp_macb);
									if(check!=NULL){
										Xoa_khunhap();
										print_by_macb(check->data);
									}
									else{
										int result = MessageBox(NULL,"Ma chuyen bay khong ton tai\n Ban co muon nhap lai","THONG BAO",MB_ICONWARNING|MB_OKCANCEL);
										while(kbhit()) getch();
										if (result == IDCANCEL){
											Xoa_khunhap();
											break;
										} 
									}
								}while(check==NULL);
							
						    }
        					if (y==6) print_follow_day_place(phead_dscb);
        					if (y==10){
        					 	fflush(stdin);
								do{
									ve_hcnrong(42,15,65,3); 
									gotoxy(44,16);
									SetBGColor(11);
									cout<<"Nhap vao Ma chuyen bay :                                     ";
									ShowConsoleCursor(true);
									fflush(stdin);
									do{
										ktra =2;
										Nhan_chu2(temp_macb,69,16,15,ktra);
									}while(strlen(temp_macb)==0);
										strupr(temp_macb);
									SetBGColor(15);
									ShowConsoleCursor(false);
									check=search_node(phead_dscb,temp_macb);
									if(check!=NULL){
										Xoa_khunhap();
										print_empty_ve(check->data.danh_sach_ve,temp_macb);
									}
									else{
										int result = MessageBox(NULL,"Ma chuyen bay khong ton tai\n Ban co muon nhap lai","THONG BAO",MB_ICONWARNING|MB_OKCANCEL);
										while(kbhit()) getch();
										if (result == IDCANCEL){
											Xoa_khunhap();
											break;
										} 
									}
								}while(check==NULL);
							}
        					if (y==14) print_so_luot_thuc_hien(dsmb);
        					if (y==18) In_tatca_hk();
        					break;
						}
						if (j==27) {
							Xoa_chucnang(x,21,s);
							xoa_gt(1);
							break;
						}
						if (j==75) {
							Xoa_chucnang(x,21,s);
							x=78; 
							break;
						}
						if (j==77) {
							Xoa_chucnang(x,21,s);
							x=4; 
							break;
						}
					}					
					break;
				}
			}
		if (j==27 ||j==13) {
			Save_file_may_bay(dsmb,file_may_bay);
			Save_file_chuyen_bay(phead_dscb,file_chuyen_bay,file_danh_sach_ve);
			Save_file_hanh_khach(root_hk,file_hanh_khach);
			break;	
		}	
		}  
    	}	
	if (i==27) break;			
	}
}

#endif
