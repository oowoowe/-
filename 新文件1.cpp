#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
	int 
	day=1,//��� 
	safe=100,//�w���A�L�C�N�X�{�Ǫ� 
	san=100,//San�� 
	time_m=0,
	time_h=7,//�C��ɶ� 
	fuel=0,//�U�Ʀs�f�A�L�C�N��light 
	clean=100,//���A�L�C�N��safe
	light=100, //�O���A�L�C�N��safe 
	left_key=0,//���𤤳����_�� 
	machine=1;//�����Ǿ��񪬪p 
void time(){
	if (time_m>=60){
		time_m=time_m-60;
		time_h=time_h+1;
		fuel=fuel-5;
		clean=clean-5;
	}
	if(time_h>=24){
		time_h=time_h-24;
		day=day+1;
	}
}
void col(int x){
	BOOL SetConsoleTextAttribute(HANDLE hConsoleOutput,WORD wAttributes);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),x);
}
void clean_page(){
	for(int i=51;i!=0;i--)
		cout<<endl;
}
void gotoxy(int x, int y) {
    COORD pos = {x,y};
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOut, pos);
}
int newgame(){
	int ch,O=1;col(15);
	gotoxy(10,5);cout<< "�p�p�p�p�p�p�p�p";
	gotoxy(10,6);cout<< "�p�p�p�p    �p�p ";
	gotoxy(10,7);cout<< "�p�p�p�p    �p�p    �p�p�p�p�p�p�p�p      �p�p�p�p�p�p      �p�p�p�p�p�p      �p�p�p�p�p�p�p�p    �p�p�p�p�p�p�p�p";
	gotoxy(10,8);cout<< "�p�p�p�p�p�p�p�p    �p�p�p�p    �p�p�p�p        �p�p�p�p  �p�p�p�p    �p�p  �p�p�p�p    �p�p�p�p  �p�p�p�p    �p�p�p�p";
	gotoxy(10,9);cout<< "�p�p�p�p    �p�p  �p�p�p�p�p�p�p�p�p�p�p�p    �p�p�p�p�p�p�p�p  �p�p�p�p        �p�p�p�p    �p�p�p�p  �p�p�p�p    �p�p�p�p";
	gotoxy(10,10);cout<<"�p�p�p�p    �p�p  �p�p�p�p          �p�p�p�p  �p�p�p�p  �p�p�p�p    �p�p  �p�p�p�p    �p�p�p�p  �p�p�p�p    �p�p�p�p  ";
	gotoxy(10,11);cout<<"�p�p�p�p�p�p�p�p      �p�p�p�p�p�p�p�p      �p�p�p�p�p�p�p�p    �p�p�p�p�p�p      �p�p�p�p�p�p�p�p    �p�p�p�p    �p�p�p�p";
	gotoxy(15,13);cout<<"�p�p�p�p    �p�p�p�p  ";
	gotoxy(15,14);cout<<"�p�p�p�p    �p�p�p�p  ";
	gotoxy(15,15);cout<<"�p�p�p�p  �p�p�p�p      �p�p�p�p�p�p�p�p      �p�p�p�p�p�p�p�p      �p�p�p�p�p�p�p�p      �p�p�p�p�p�p�p�p    �p�p�p�p  �p�p�p�p�p�p";
	gotoxy(15,16);cout<<"�p�p�p�p�p�p        �p�p�p�p    �p�p�p�p  �p�p�p�p    �p�p�p�p  �p�p�p�p    �p�p�p�p  �p�p�p�p    �p�p�p�p  �p�p�p�p�p�p�p�p    ";
	gotoxy(15,17);cout<<"�p�p�p�p  �p�p�p�p    �p�p�p�p�p�p�p�p�p�p�p�p  �p�p�p�p�p�p�p�p�p�p�p�p  �p�p�p�p    �p�p�p�p  �p�p�p�p    �p�p�p�p  �p�p�p�p";
	gotoxy(15,18);cout<<"�p�p�p�p    �p�p�p�p  �p�p�p�p          �p�p�p�p          �p�p�p�p�p�p�p�p�p�p    �p�p�p�p�p�p�p�p�p�p    �p�p�p�p";
	gotoxy(15,19);cout<<"�p�p�p�p    �p�p�p�p    �p�p�p�p�p�p�p�p�p�p    �p�p�p�p�p�p�p�p�p�p  �p�p�p�p          �p�p�p�p          �p�p�p�p";
	gotoxy(57,20);cout<<"�p�p�p�p          �p�p�p�p";
	gotoxy(57,21);cout<<"�p�p�p�p          �p�p�p�p";
    gotoxy(50,26);cout<<"(1)�s�C��";	
	gotoxy(50,27);cout<<"(2)�����C��";
	while (1){
        if (_kbhit()){
            ch = _getch();
            if (ch == 49){
            	return 1;
            	break;
			}	
            if (ch == 50){
            	break;
			}
        }
	}
}
void manual(){//���A�� 
	clean_page();
	gotoxy(0,0);
	col(14);
	cout<<"�O���U"<<endl<<endl<<endl;
	col(15);
	cout<<"���A:"<<endl
	<<"----------"<<endl
	<<"���:��"<<day<<"��"<<endl;
	cout<<"�ɶ�:";
	if(time_h<10)cout<<"0";
	cout<<time_h<<":";
	if(time_m<10)cout<<"0";
	cout<<time_m<<endl;
	cout<<"�w��:";
	if (safe>=80)      {col(10);cout<<"�A�{�b�ܦw��  ";} 
	else if(safe>=60)  {col(3);cout<<"�Ȯɤ��|�����D";} 
	else if (safe>=40) {col(9);cout<<"�¼v�{�L����  ";} 
	else if (safe>=20) {col(5);cout<<"���ߧY�N���{  ";} 
	else               {col(12);cout<<"���̨ӤF!!!   ";} 
	col(15);cout<<endl;
	cout<<"�믫:";
	if (san>=80)      {col(10);cout<<"�A��O�R�K";} 
	else if(san>=60)  {col(3);cout<<"�A�Q���M��";} 
	else if (san>=40) {col(9);cout<<"�A���I�֤F";} 
	else if (san>=20) {col(5);cout<<" �A�P��h��";} 
	else               {col(12);cout<<"�A�D�`���h��";} 
	col(15);cout<<endl;
	cout<<"�O��:";
	if (light>=80)      {col(10);cout<<"���~�U�V";} 
	else if(light>=60)  {col(3);cout<<"���O����";} 
	else if (light>=40) {col(9);cout<<"�O���n��";} 
	else if (light>=20) {col(5);cout<<"��������";} 
	else               {col(12);cout<<"�@������";} 
	col(15);cout<<endl;
	cout<<"�U��:";
	if (fuel>=80)      {col(10);cout<<"�U�ƥR��";} 
	else if(fuel>=60)  {col(3);cout<<"��������";} 
	else if (fuel>=40) {col(9);cout<<"�U�ƥb��";} 
	else if (fuel>=20) {col(5);cout<<"�Y�N����";} 
	else               {col(12);cout<<"�U�ƥ��L";} 
	col(15);cout<<endl;
	cout<<"���:";
	if (clean>=80)      {col(10);cout<<"�Q�����b";} 
	else if(clean>=60)  {col(3);cout<<"���I���";} 
	else if (clean>=40) {col(9);cout<<"�ٺ���";} 
	else if (clean>=20) {col(5);cout<<"���I����";} 
	else               {col(12);cout<<"�D�`����";} 
	col(15);cout<<endl;
	cout<<endl<<endl<<endl<<endl;
	col(3);cout<<"(1)���W��U";col(15);
	gotoxy(30,1);cout<< "�w��A�s���u��H�A�b���U�Ӫ�1�Ӥ�A�A�N�t�d�O����B�A�O�𪺤����O�ө�����Ʊ�A";
	gotoxy(30,2);cout<< "���O�A�o�����~�]�|�l�ިӬY�ǪF�誺�`���A���L��ߡA�u�n�A��u�U�C�W�w�A�ڭ̥i�H�O�ҡA";
	gotoxy(30,3);cout<< "�b�i�w�������ӡA�A�A���N�O�w�����C";
	gotoxy(30,5);cout<< "(1) �����O������ģ�O�A�̭��n���u�@�A���G�����~�I��A�O�U�Ʒ������_�����ӡA�A�����O��";
	gotoxy(30,6);cout<< "    �U�ƪ������A�U�ƪ��x�s����b�k�ƶ𪺩����A�b�D����Ǧ��ӻ֪��A�}�ҴN��ɥR�U�ơC"; 
	col(14);
	gotoxy(30,7);cout<< "    *�O��A�O�𥲶��{ģ!!!���Ƥ@�M�A�O�𥲶��{ģ!!!*"; 
	col(15);
	gotoxy(30,9);cout<< "(2) �����ƶ𪺤W�h�A���۳̼s�諸�����A�p�G�A�b�ߤW�ݨ�{�ۺ��O��������q�������ɰ_"; 
	gotoxy(30,10);cout<<"    �A�Хߨ�ԤU�����ƶ𪺹q�h�A�ëݦb�����ƶ𪺤W�h�A���ܮ�����^�������C";
	col(13);
	gotoxy(30,11);cout<<"    *���̪��D�A�b�ݵ�*"; 
	col(15);
	gotoxy(30,13);cout<<"(3) �D�𤤳����@�ӹϮѫǡA�̭������y�i�H�N�\\Ū�A���O�аO��A�̥k��ĤG�h���d�̥u��17"; 
	gotoxy(30,14);cout<<"    ���ѡA�p�G�A�ݨ�F��18���ѡA�åB���O�¦�ʭ����A�Хߨ����}�ϮѫǡA�æܤֵ��ݤ@�p��"; 
	gotoxy(30,15);cout<<"    �A�i�J�A���p�G�L�O�Q��b��l�W�A�B�U���ٹԵۥզ⪺��y�A�Хߨ�\\Ū���A���H����a�C"; 
	col(10);
	gotoxy(30,16);cout<<"    *���ѡA�O�ڭ̰ߤ@���Z���A���n��*"; 
	col(15);
	gotoxy(30,18);cout<<"(4) ����W�X�{�j���ɡA�л��T���áA�O�@�L������A���ê��}���b�D���Ṋ̀��C"; 
	col(11);
	gotoxy(30,19);cout<<"    *�B�W�����A�ä������A�w��*"; 
	col(15);
	gotoxy(30,21);cout<<"(5) �k���ƶ𪺤W�h�O�����ǡA�O������V�P�o�ƪ��B�鳣�O�̾a�۳o�̪����c�B�檺�A�p�G"; 
	gotoxy(30,22);cout<<"    ����O�𪺹h���L�k���`�B�@�A���u���ӳo���ˬd�C";
	col(9);
	gotoxy(30,23);cout<<"    *�������۾����A�U�����p�w����B�@*"; 
	col(15);
	while (1){
        if (_kbhit()){
            if (_getch()== 49){
           		break;
			}
		}
	}
}
int story1(){//�C���}�l 
	gotoxy(0,2);
	cout<<"�A���b�O��e�A��V���ߩ�������q����ӡA���F�M�f�A�A��ܤF�o���u�@�C"<<endl;
	cout<<"��ӻP��y�ƶ�{�{�ۥ��~�A��M�A�O�𪺤j���}�F�A�@��ѤH�q�����X�ñ�V�A�C"<<endl;
	cout<<"�u�A�n�A�A�N�O�s��";col(12);cout<<"�u��H";col(15);cout<<"��a�C�v�ѤH���C"<<endl; 
	cout<<"�u�A�ݭn�����ơA���g�b";col(14);cout<<"�O���U";col(15);cout<<"���F�C�v"<<endl;
	cout<<"�u��";col(12);cout<<"�D�`��ĳ";col(15);cout<<"�A�ݧ�����A�}�l�u�@�A�O���ڨS�����A�C�v"<<endl;
	cout<<"*�A��o�F�O���U�A���Ui��H�}�ҥ�*"<<endl<<endl<<endl<<endl;
	col(3);cout<<"(1)�n��"<<endl; col(15);
	while (1){
        if (_kbhit()){
        	int ch=_getch();
            if (ch== 49){
            	return 2;
					break;
				}
			else if (ch== 105){
					manual();
					return 1;
					break;
				}
			}	
    }
}
int story2(){//���𳻼h  �D���� 
	gotoxy(0,0);
	cout<<"���𳻼h  �D����"; 
	gotoxy(0,2);
	cout<<"�A�{�b�b���𳻼h���D���ǡA�o�̤Q���U���A���j���D�O����F�j�������Ŷ��A"<<endl;
	cout<<"���������c�s����W�A�w�C���a�ʥD�O����A���{�b�ݰ_��";
	if (light>=80)      {col(10);cout<<"���~�U�V";} 
	else if(light>=60)  {col(3);cout<<"���O����";} 
	else if (light>=40) {col(9);cout<<"�O���n��";} 
	else if (light>=20) {col(5);cout<<"��������";} 
	else               {col(12);cout<<"�@������";} 
	col(15);
	cout<<"�C"<<endl<<endl<<"���@�ӻ֪��b�D�O���k��A�ж��������P�k���U���@�����A�t���@�D�ӱ�q�V�U�h�C"<<endl<<endl<<endl;
	
	col(3);
	cout<<"(1)�ԤU�֪�"<<endl<<"(2)�i�J���䪺��"<<endl<<"(3)�i�J�k�䪺��"<<endl<<"(4)�i�J�V�U���ӱ�"<<endl<<"(5)�ϥ�����";
	col(15); 
	while (1){
        if (_kbhit()){
        	int ch=_getch();
            if (ch== 49){
            	return 3;
				break;
				}
			else if (ch== 105){
					manual();
					return 2;
					break;
				}
			else if (ch== 50){
				return 4;
				break;
				}
			else if (ch== 51){
				return 5;
				break;
				}
			else if (ch== 52){
				return 6;
				break;
				}
			else if (ch== 53){
				return 17;
				break;
				}
			}	
    }
}
int story3(){//���𳻼h  �D����  �֪� 
	gotoxy(0,0);
	cout<<"���𳻼h  �D����  �֪�"; 
	gotoxy(0,2);
	cout<<"�{�b�O�𪺿U�ƪ��A:";
	if (fuel>=80)      {col(10);cout<<"�U�ƥR��";} 
	else if(fuel>=60)  {col(3);cout<<"��������";} 
	else if (fuel>=40) {col(9);cout<<"�U�ƥb��";} 
	else if (fuel>=20) {col(5);cout<<"�Y�N����";} 
	else               {col(12);cout<<"�U�ƥ��L";} 
	cout<<endl<<endl;
	if(fuel==100)cout<<"�U�Ƥw�g�񺡡A���ݭn�A�K�[�F";
	cout<<endl<<endl;	
	col(3);cout<<"(1)�K�[�U��(20:00)          (2)����K�[�U��";col(15);
	while (1){
        if (_kbhit()){
        	int ch=_getch();
            if (ch== 49){
            	fuel=fuel+20;
            	time_m=time_m+20;
            	time();
            	if(fuel>100)fuel=100;
				return 3;
				}
			else if (ch== 105){
					manual();
					return 3;
					break;
				}
			else if (ch== 50){
				return 2;
				break;
				}
			}	
    }
}
int story4(){//���𳻼h  �[��� 
	gotoxy(0,0);
	cout<<"���𳻼h  �[���";
	gotoxy(0,2);
	cout<<"�A�{�b�b���𳻼h���[��ǡA�o�̦��@���[��A�[��e���@��滷��A"<<endl; 
	cout<<"�ж����k�䦳�@�����A�t���@�ӱ�q�V�ӤU�C"<<endl<<endl<<endl;
	col(3);cout<<"(1)�i�J�k�䪺��"<<endl<<"(2)�i�J�V�U���ӱ�"<<endl<<"(3)�ϥα滷��(00:15)";col(15);
while (1){
        if (_kbhit()){
        	int ch=_getch();
            if (ch== 49){
            	return 2;
				break;
				}
			else if (ch== 105){
					manual();
					return 4;
					break;
				}
			else if (ch== 50){
				return 8;
				break;
				}
			else if (ch== 51){
				time_m=time_m+15;
				time();
				return 7;
				break;
				}
			}	
    	}
}
int story5(){//�k�𳻼h  ������ 
	gotoxy(0,0);
	cout<<"�k�𳻼h  ������";
	gotoxy(0,2);
	cout<<"�A�{�b�b�𳻼h�������ǡA�����P�޽u�󦹥��|�A��������L�������ʵ۵L�ƾ����@�ΡA"<<endl; 
	cout<<"�̫�Ѥ@�ڶǰʶb�s���쥪�����𤤡A���ɦ⪺�޽u�h�q�U��}�l�A����b�𭱻P�Ѫ�O����"<<endl;
	cout<<"��s���쥪�����𤤡C"<<endl;
	cout<<"�ж������䦳�@�����A�t���@�ӱ�q�V�ӤU�C"<<endl<<endl<<endl;
	col(3);cout<<"(1)�i�J���䪺��"<<endl<<"(2)�i�J�V�U���ӱ�"<<endl<<"(3)�ˬd����(00:30)";col(15);
while (1){
        if (_kbhit()){
        	int ch=_getch();
            if (ch== 49){
            	return 2;
				break;
				}
			else if (ch== 105){
					manual();
					return 5;
					break;
				}
			else if (ch== 50){
				return 10;
				break;
				}
			else if (ch== 51){
				time_m=time_m+30;
				time();
				return 9;
				break;
				}
			}	
    	}
}
int story6(){//���𤤼h  �Ϯѫ� 
	gotoxy(0,0);
	cout<<"���𤤼h  �Ϯѫ�";
	gotoxy(0,2);
	cout<<"�A�{�b�b���𤤼h���ϮѫǡA�|�ӮѬ[��¶�ۧA�A�������@�ӴȤl�A�Pı�i�H�b�W��"<<endl;
	cout<<"�ݮѡA�Ȥl�e��O�@�Ӯ�l�A�W����F�X�����C"<<endl;
	cout<<"�ж��̦���Ӥ��O�q�V�W�U���ӱ�C"<<endl<<endl<<endl;
	col(3);cout<<"(1)�i�J�V�W���ӱ�"<<endl<<"(2)�i�J�V�U���ӱ�"<<endl<<"(3)�j�M�Ѭ[(00:30)"<<endl<<"(4)���b�Ȥl�W";col(15);
while (1){
        if (_kbhit()){
        	int ch=_getch();
            if (ch== 49){
            	return 2;
				break;
				}
			else if (ch== 105){
				manual();
				return 5;
				break;
				}
			else if (ch== 50){
				return 11;
				break;
				}
			else if (ch== 51){
				time_m=time_m+30;
				time();
				return 12;
				break;
				}
			else if (ch== 52){
				return 13;
				break;
				}
			}	
    	}
}
int story7(){//���𳻼h  �[���  �滷�� 
	gotoxy(0,0);
	cout<<"���𳻼h  �[���  �滷��";
	gotoxy(0,2);
	cout<<"�A���_�滷��A";
	if(time_h>=9||time_h<=4) cout<<"�@�����ª����v�X�{�b�A�����������A"<<endl;
	else cout<<"�@�����Ū����v�X�{�b�A�����������A"<<endl;
	int r=rand()%4+1;
	if(r==2){
		cout<<"�@���C���q���B�p�L�A�E�_������ިӤ@�s���b�A�@�����M�������C";col(3);cout<<"�믫++";col(15);san=san+2;
	}
	if(r==3){
		cout<<"�����W�@�p���`�A����������G�ۡA�ީ]�����C";
	}
	if(r==4){
		cout<<"�޲����¼v�q���U�_�X�A����ʤF����180�ת����y�A�ݤF�ݧA�A"<<endl<<
		"�X������A���S���s�p�^�F�����C";col(12);cout<<"�믫--";col(15);san=san-2;
	}
	col(3);cout<<endl<<endl<<endl<<"(1)�~��ϥα滷��(00:15)"<<endl<<"(2)����ϥα滷��";col(15);
	while (1){
        if (_kbhit()){
        	int ch=_getch();
            if (ch== 49){
            	time_m=time_m+15;
            	time();
            	return 7;
				break;
				}
			else if (ch== 105){
					manual();
					return 7;
					break;
				}
			else if (ch== 50){
				return 4;
				break;
				}
			}	
    	}
}
int story8(){//���𤤼h   
	if(left_key==0) {
		gotoxy(0,0);
		cout<<"���𤤼h  �����ж�";
		gotoxy(0,2);
		col(12);cout<<"���𤤼h�ж������Q��W�F�A�L�קA�p��ϤO�������}�C"<<endl;col(15);
		cout<<"�γ\\�A�A��b���̧�쥴�}�o�������_�ͤ]�����w�C";
	}
	if(left_key==1) {
		gotoxy(0,0);
		cout<<"���𤤼h  �����ж�";
		gotoxy(0,2);
		cout<<"���𤤼h�ж������Q��W�F�A���L�A�ϥΤ�W���_�ͥ��}�����𤤼h�ж������A"<<endl; 
		cout<<"�M�J��î���O�@���ﺡ�������x�ëǡA�]�\\�̭��|���@�ǷN�䪺�F��C";
		gotoxy(0,8);col(3);cout<<"(3)�i�J�x�ë�";col(15);
	} 
	if(left_key==2) {
		gotoxy(0,0);
		cout<<"���𤤼h  �x�ë�";
		gotoxy(0,2);
		cout<<"�e�誺�O�@���ﺡ�������x�ëǡA�Ƚc�P��c�ﺡ�F����q�D�A�����������A"<<endl;
		cout<<"�L�ɪ��i��P...�ǹСA�A�i�H�յۦb�̭���@�Ǧ��N�䪺�F��C";
		gotoxy(0,8);col(3);cout<<"(3)�i�J�x�ë�";col(15);
	} 
	gotoxy(0,6);col(3);cout<<"(1)�i�J�V�W���ӱ�"<<endl<<"(2)�i�J�V�U���ӱ�";col(15);
	
while (1){
        if (_kbhit()){
        	int ch=_getch();
            if (ch== 49){
            	return 4;
				break;
				}
			else if (ch== 105){
					manual();
					return 8;
					break;
				}
			else if (ch== 50){
				return 14;
				break;
				}
			else if (ch== 51&&left_key==1||ch== 51&&left_key==2){
				return 15;
				break;
				}
			}	
    	}
}
int story9(){//�k�𳻼h  ������  �ˬd���� 
	gotoxy(0,0);
	cout<<"�k�𳻼h  ������  �ˬd����";
	gotoxy(0,2);
	cout<<"�A�a��F���񵲺c�A�J�Ӧa�[��F�������p�A���{�b���p";
	if(machine==1){col(10);cout<<"���`";}
	else {col(12);cout<<"�G��";}
	cout<<endl<<endl<<endl;col(3);cout<<"(1)���խ״_"<<endl<<"(2)���}";
while (1){
        if (_kbhit()){
        	int ch=_getch();
            if (ch== 49){
            	return 16;
				break;
				}
			else if (ch== 105){
					manual();
					return 8;
					break;
				}
			else if (ch== 50){
					manual();
					return 5;
					break;
				}
			}	
    	}	
	 
}
int story10(){//�k�𤤼h
}
int story11(){//���𩳼h  �׫� 
}
int story12(){//���𤤼h  �Ϯѫ�  �j���Ѭ[ 
}
int story13(){//���𤤼h  �Ϯѫ�  ���b�Ȥl�W 
}
int story14(){//���𩳼h 
	
}
int story15(){//���𤤼h  ���� 
}
int story16(){//�k�𳻼h  ������  �ˬd����  ����״_���� 
}
int story17(){//���𳻼h  �D����  ���� 
}

void gameing(){
	int story=1;
	while(1){
		clean_page();
		     if(story==1){story=story1();}
		else if(story==2){story=story2();}
		else if(story==3){story=story3();}
		else if(story==4){story=story4();}
		else if(story==5){story=story5();}
		else if(story==6){story=story6();}
		else if(story==7){story=story7();}
		else if(story==8){story=story8();}
		else if(story==9){story=story9();}
		else if(story==10){story=story10();}
		else if(story==11){story=story11();}
		else if(story==12){story=story12();}
		else if(story==13){story=story13();}
		else if(story==14){story=story14();}
	}
}
int main(){
	srand( time(NULL) );
	int main;
	main=newgame();
	if (main==1) {
	gameing();
	}
	return 0;
}
