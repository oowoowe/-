#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
	int 
	day=1,//日期 
	safe=100,//安全，過低將出現怪物 
	san=100,//San值 
	time_m=0,
	time_h=7,//每日時間 
	fuel=0,//燃料存貨，過低將扣light 
	clean=100,//整潔，過低將扣safe
	light=100, //燈火，過低將扣safe 
	left_key=0,//左塔中部的鑰匙 
	machine=1;//機關室機械狀況 
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
	gotoxy(10,5);cout<< "▉▉▉▉▉▉▉▉";
	gotoxy(10,6);cout<< "▉▉▉▉    ▉▉ ";
	gotoxy(10,7);cout<< "▉▉▉▉    ▉▉    ▉▉▉▉▉▉▉▉      ▉▉▉▉▉▉      ▉▉▉▉▉▉      ▉▉▉▉▉▉▉▉    ▉▉▉▉▉▉▉▉";
	gotoxy(10,8);cout<< "▉▉▉▉▉▉▉▉    ▉▉▉▉    ▉▉▉▉        ▉▉▉▉  ▉▉▉▉    ▉▉  ▉▉▉▉    ▉▉▉▉  ▉▉▉▉    ▉▉▉▉";
	gotoxy(10,9);cout<< "▉▉▉▉    ▉▉  ▉▉▉▉▉▉▉▉▉▉▉▉    ▉▉▉▉▉▉▉▉  ▉▉▉▉        ▉▉▉▉    ▉▉▉▉  ▉▉▉▉    ▉▉▉▉";
	gotoxy(10,10);cout<<"▉▉▉▉    ▉▉  ▉▉▉▉          ▉▉▉▉  ▉▉▉▉  ▉▉▉▉    ▉▉  ▉▉▉▉    ▉▉▉▉  ▉▉▉▉    ▉▉▉▉  ";
	gotoxy(10,11);cout<<"▉▉▉▉▉▉▉▉      ▉▉▉▉▉▉▉▉      ▉▉▉▉▉▉▉▉    ▉▉▉▉▉▉      ▉▉▉▉▉▉▉▉    ▉▉▉▉    ▉▉▉▉";
	gotoxy(15,13);cout<<"▉▉▉▉    ▉▉▉▉  ";
	gotoxy(15,14);cout<<"▉▉▉▉    ▉▉▉▉  ";
	gotoxy(15,15);cout<<"▉▉▉▉  ▉▉▉▉      ▉▉▉▉▉▉▉▉      ▉▉▉▉▉▉▉▉      ▉▉▉▉▉▉▉▉      ▉▉▉▉▉▉▉▉    ▉▉▉▉  ▉▉▉▉▉▉";
	gotoxy(15,16);cout<<"▉▉▉▉▉▉        ▉▉▉▉    ▉▉▉▉  ▉▉▉▉    ▉▉▉▉  ▉▉▉▉    ▉▉▉▉  ▉▉▉▉    ▉▉▉▉  ▉▉▉▉▉▉▉▉    ";
	gotoxy(15,17);cout<<"▉▉▉▉  ▉▉▉▉    ▉▉▉▉▉▉▉▉▉▉▉▉  ▉▉▉▉▉▉▉▉▉▉▉▉  ▉▉▉▉    ▉▉▉▉  ▉▉▉▉    ▉▉▉▉  ▉▉▉▉";
	gotoxy(15,18);cout<<"▉▉▉▉    ▉▉▉▉  ▉▉▉▉          ▉▉▉▉          ▉▉▉▉▉▉▉▉▉▉    ▉▉▉▉▉▉▉▉▉▉    ▉▉▉▉";
	gotoxy(15,19);cout<<"▉▉▉▉    ▉▉▉▉    ▉▉▉▉▉▉▉▉▉▉    ▉▉▉▉▉▉▉▉▉▉  ▉▉▉▉          ▉▉▉▉          ▉▉▉▉";
	gotoxy(57,20);cout<<"▉▉▉▉          ▉▉▉▉";
	gotoxy(57,21);cout<<"▉▉▉▉          ▉▉▉▉";
    gotoxy(50,26);cout<<"(1)新遊戲";	
	gotoxy(50,27);cout<<"(2)結束遊戲";
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
void manual(){//狀態欄 
	clean_page();
	gotoxy(0,0);
	col(14);
	cout<<"燈塔手冊"<<endl<<endl<<endl;
	col(15);
	cout<<"狀態:"<<endl
	<<"----------"<<endl
	<<"日期:第"<<day<<"天"<<endl;
	cout<<"時間:";
	if(time_h<10)cout<<"0";
	cout<<time_h<<":";
	if(time_m<10)cout<<"0";
	cout<<time_m<<endl;
	cout<<"安全:";
	if (safe>=80)      {col(10);cout<<"你現在很安全  ";} 
	else if(safe>=60)  {col(3);cout<<"暫時不會有問題";} 
	else if (safe>=40) {col(9);cout<<"黑影閃過窗邊  ";} 
	else if (safe>=20) {col(5);cout<<"恐懼即將降臨  ";} 
	else               {col(12);cout<<"它們來了!!!   ";} 
	col(15);cout<<endl;
	cout<<"精神:";
	if (san>=80)      {col(10);cout<<"你精力充沛";} 
	else if(san>=60)  {col(3);cout<<"你十分清醒";} 
	else if (san>=40) {col(9);cout<<"你有點累了";} 
	else if (san>=20) {col(5);cout<<" 你感到疲憊";} 
	else               {col(12);cout<<"你非常的疲累";} 
	col(15);cout<<endl;
	cout<<"燈火:";
	if (light>=80)      {col(10);cout<<"光芒萬丈";} 
	else if(light>=60)  {col(3);cout<<"明燈依舊";} 
	else if (light>=40) {col(9);cout<<"燈火搖曳";} 
	else if (light>=20) {col(5);cout<<"忽明忽滅";} 
	else               {col(12);cout<<"一片漆黑";} 
	col(15);cout<<endl;
	cout<<"燃料:";
	if (fuel>=80)      {col(10);cout<<"燃料充足";} 
	else if(fuel>=60)  {col(3);cout<<"略有消耗";} 
	else if (fuel>=40) {col(9);cout<<"燃料半滿";} 
	else if (fuel>=20) {col(5);cout<<"即將見底";} 
	else               {col(12);cout<<"燃料全無";} 
	col(15);cout<<endl;
	cout<<"整潔:";
	if (clean>=80)      {col(10);cout<<"十分乾淨";} 
	else if(clean>=60)  {col(3);cout<<"有點整潔";} 
	else if (clean>=40) {col(9);cout<<"還算整潔";} 
	else if (clean>=20) {col(5);cout<<"有點雜亂";} 
	else               {col(12);cout<<"非常雜亂";} 
	col(15);cout<<endl;
	cout<<endl<<endl<<endl<<endl;
	col(3);cout<<"(1)關上手冊";col(15);
	gotoxy(30,1);cout<< "歡迎，新的守塔人，在接下來的1個月，你將負責燈塔的營運，燈塔的火光是來往船隻的希望，";
	gotoxy(30,2);cout<< "但是，這份光芒也會吸引來某些東西的注視，不過放心，只要你遵守下列規定，我們可以保證，";
	gotoxy(30,3);cout<< "在可預見的未來，你，都將是安全的。";
	gotoxy(30,5);cout<< "(1) 維持燈火的照耀是你最重要的工作，明亮的光芒背後，是燃料源源不斷的消耗，你必須保證";
	gotoxy(30,6);cout<< "    燃料的供應，燃料的儲存罐位在右副塔的底部，在主控制室有個閥門，開啟就能補充燃料。"; 
	col(14);
	gotoxy(30,7);cout<< "    *記住，燈塔必須閃耀!!!重複一遍，燈塔必須閃耀!!!*"; 
	col(15);
	gotoxy(30,9);cout<< "(2) 左側副塔的上層，有著最廣闊的視野，如果你在晚上看到閃著綠色燈號的桅杆從海平面升起"; 
	gotoxy(30,10);cout<<"    ，請立刻拉下左側副塔的電閘，並待在左側副塔的上層，直至桅杆落回海平面。";
	col(13);
	gotoxy(30,11);cout<<"    *它們知道你在看著*"; 
	col(15);
	gotoxy(30,13);cout<<"(3) 主塔中部有一個圖書室，裡面的書籍可隨意閱\讀，但是請記住，最右邊第二層書櫃裡只有17"; 
	gotoxy(30,14);cout<<"    本書，如果你看到了第18本書，並且它是黑色封面的，請立刻離開圖書室，並至少等待一小時"; 
	gotoxy(30,15);cout<<"    再進入，但如果他是被放在桌子上，且下面還墊著白色的手巾，請立刻閱\讀它，並隨身攜帶。"; 
	col(10);
	gotoxy(30,16);cout<<"    *知識，是我們唯一的武器，拿好它*"; 
	col(15);
	gotoxy(30,18);cout<<"(4) 當海上出現大霧時，請鳴響霧笛，保護過往的船隻，霧笛的開關在主控室裡面。"; 
	col(11);
	gotoxy(30,19);cout<<"    *遮上雙眼，並不能讓你安全*"; 
	col(15);
	gotoxy(30,21);cout<<"(5) 右側副塔的上層是機關室，燈光的方向與油料的運輸都是依靠著這裡的機構運行的，如果"; 
	gotoxy(30,22);cout<<"    控制燈塔的閘門無法正常運作，請優先來這裡檢查。";
	col(9);
	gotoxy(30,23);cout<<"    *齒輪接著齒輪，萬物都如預期般運作*"; 
	col(15);
	while (1){
        if (_kbhit()){
            if (_getch()== 49){
           		break;
			}
		}
	}
}
int story1(){//遊戲開始 
	gotoxy(0,2);
	cout<<"你站在燈塔前，望向矗立於海中高聳的塔樓，為了餬口，你選擇了這份工作。"<<endl;
	cout<<"塔樓與兩座副塔閃爍著光芒，突然，燈塔的大門開了，一位老人從中走出並望向你。"<<endl;
	cout<<"「你好，你就是新的";col(12);cout<<"守塔人";col(15);cout<<"對吧。」老人說。"<<endl; 
	cout<<"「你需要做的事，都寫在";col(14);cout<<"燈塔手冊";col(15);cout<<"中了。」"<<endl;
	cout<<"「我";col(12);cout<<"非常建議";col(15);cout<<"你看完它後再開始工作，別說我沒提醒你。」"<<endl;
	cout<<"*你獲得了燈塔手冊，按下i鍵以開啟它*"<<endl<<endl<<endl<<endl;
	col(3);cout<<"(1)好的"<<endl; col(15);
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
int story2(){//中塔頂層  主控室 
	gotoxy(0,0);
	cout<<"中塔頂層  主控室"; 
	gotoxy(0,2);
	cout<<"你現在在中塔頂層的主控室，這裡十分狹窄，巨大的主燈佔住了大部分的空間，"<<endl;
	cout<<"複雜的機構連接其上，緩慢的帶動主燈旋轉，它現在看起來";
	if (light>=80)      {col(10);cout<<"光芒萬丈";} 
	else if(light>=60)  {col(3);cout<<"明燈依舊";} 
	else if (light>=40) {col(9);cout<<"燈火搖曳";} 
	else if (light>=20) {col(5);cout<<"忽明忽滅";} 
	else               {col(12);cout<<"一片漆黑";} 
	col(15);
	cout<<"。"<<endl<<endl<<"有一個閥門在主燈的右邊，房間的左側與右側各有一扇門，另有一道樓梯通向下層。"<<endl<<endl<<endl;
	
	col(3);
	cout<<"(1)拉下閥門"<<endl<<"(2)進入左邊的門"<<endl<<"(3)進入右邊的門"<<endl<<"(4)進入向下的樓梯"<<endl<<"(5)使用霧笛";
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
int story3(){//中塔頂層  主控室  閥門 
	gotoxy(0,0);
	cout<<"中塔頂層  主控室  閥門"; 
	gotoxy(0,2);
	cout<<"現在燈塔的燃料狀態:";
	if (fuel>=80)      {col(10);cout<<"燃料充足";} 
	else if(fuel>=60)  {col(3);cout<<"略有消耗";} 
	else if (fuel>=40) {col(9);cout<<"燃料半滿";} 
	else if (fuel>=20) {col(5);cout<<"即將見底";} 
	else               {col(12);cout<<"燃料全無";} 
	cout<<endl<<endl;
	if(fuel==100)cout<<"燃料已經填滿，不需要再添加了";
	cout<<endl<<endl;	
	col(3);cout<<"(1)添加燃料(20:00)          (2)停止添加燃料";col(15);
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
int story4(){//左塔頂層  觀察室 
	gotoxy(0,0);
	cout<<"左塔頂層  觀察室";
	gotoxy(0,2);
	cout<<"你現在在左塔頂層的觀察室，這裡有一面觀察窗，觀察窗前有一支望遠鏡，"<<endl; 
	cout<<"房間的右邊有一扇門，另有一樓梯通向樓下。"<<endl<<endl<<endl;
	col(3);cout<<"(1)進入右邊的門"<<endl<<"(2)進入向下的樓梯"<<endl<<"(3)使用望遠鏡(00:15)";col(15);
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
int story5(){//右塔頂層  機關室 
	gotoxy(0,0);
	cout<<"右塔頂層  機關室";
	gotoxy(0,2);
	cout<<"你現在在塔頂層的機關室，齒輪與管線於此交疊，巨型的圓盤齒輪推動著無數機關作用，"<<endl; 
	cout<<"最後由一根傳動軸連接到左側的牆中，黃銅色的管線則從下方開始，穿梭在牆面與天花板之中"<<endl;
	cout<<"亦連接到左側的牆中。"<<endl;
	cout<<"房間的左邊有一扇門，另有一樓梯通向樓下。"<<endl<<endl<<endl;
	col(3);cout<<"(1)進入左邊的門"<<endl<<"(2)進入向下的樓梯"<<endl<<"(3)檢查機械(00:30)";col(15);
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
int story6(){//中塔中層  圖書室 
	gotoxy(0,0);
	cout<<"中塔中層  圖書室";
	gotoxy(0,2);
	cout<<"你現在在中塔中層的圖書室，四個書架圍繞著你，中央有一個椅子，感覺可以在上面"<<endl;
	cout<<"看書，椅子前方是一個桌子，上面放了幾隻筆。"<<endl;
	cout<<"房間裡有兩個分別通向上下的樓梯。"<<endl<<endl<<endl;
	col(3);cout<<"(1)進入向上的樓梯"<<endl<<"(2)進入向下的樓梯"<<endl<<"(3)搜尋書架(00:30)"<<endl<<"(4)坐在椅子上";col(15);
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
int story7(){//左塔頂層  觀察室  望遠鏡 
	gotoxy(0,0);
	cout<<"左塔頂層  觀察室  望遠鏡";
	gotoxy(0,2);
	cout<<"你拿起望遠鏡，";
	if(time_h>=9||time_h<=4) cout<<"一片漆黑的海洋出現在你的視野之中，"<<endl;
	else cout<<"一片蔚藍的海洋出現在你的視野之中，"<<endl;
	int r=rand()%4+1;
	if(r==2){
		cout<<"一艘遊輪從遠處駛過，激起的水花引來一群海豚，一片祥和的光景。";col(3);cout<<"精神++";col(15);san=san+2;
	}
	if(r==3){
		cout<<"水面上一如往常，海浪輕拍著礁石，晝夜不歇。";
	}
	if(r==4){
		cout<<"詭異的黑影從水下冒出，它轉動了它那180度的眼球，看了看你，"<<endl<<
		"幾秒鐘後，它又重新鑽回了海里。";col(12);cout<<"精神--";col(15);san=san-2;
	}
	col(3);cout<<endl<<endl<<endl<<"(1)繼續使用望遠鏡(00:15)"<<endl<<"(2)停止使用望遠鏡";col(15);
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
int story8(){//左塔中層   
	if(left_key==0) {
		gotoxy(0,0);
		cout<<"左塔中層  未知房間";
		gotoxy(0,2);
		col(12);cout<<"左塔中層房間的門被鎖上了，無論你如何使力都打不開。"<<endl;col(15);
		cout<<"或許\，你能在哪裡找到打開這扇門的鑰匙也說不定。";
	}
	if(left_key==1) {
		gotoxy(0,0);
		cout<<"左塔中層  未知房間";
		gotoxy(0,2);
		cout<<"左塔中層房間的門被鎖上了，不過你使用手上的鑰匙打開的左塔中層房間的門，"<<endl; 
		cout<<"映入眼簾的是一間堆滿雜物的儲藏室，也許\裡面會有一些意思的東西。";
		gotoxy(0,8);col(3);cout<<"(3)進入儲藏室";col(15);
	} 
	if(left_key==2) {
		gotoxy(0,0);
		cout<<"左塔中層  儲藏室";
		gotoxy(0,2);
		cout<<"前方的是一間堆滿雜物的儲藏室，紙箱與木箱堆滿了整條通道，未知的探索，"<<endl;
		cout<<"無盡的可能與...灰塵，你可以試著在裡面找一些有意思的東西。";
		gotoxy(0,8);col(3);cout<<"(3)進入儲藏室";col(15);
	} 
	gotoxy(0,6);col(3);cout<<"(1)進入向上的樓梯"<<endl<<"(2)進入向下的樓梯";col(15);
	
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
int story9(){//右塔頂層  機關室  檢查機械 
	gotoxy(0,0);
	cout<<"右塔頂層  機關室  檢查機械";
	gotoxy(0,2);
	cout<<"你靠近了機械結構，仔細地觀察了它的狀況，它現在狀況";
	if(machine==1){col(10);cout<<"正常";}
	else {col(12);cout<<"故障";}
	cout<<endl<<endl<<endl;col(3);cout<<"(1)嘗試修復"<<endl<<"(2)離開";
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
int story10(){//右塔中層
}
int story11(){//中塔底層  臥室 
}
int story12(){//中塔中層  圖書室  搜索書架 
}
int story13(){//中塔中層  圖書室  坐在椅子上 
}
int story14(){//左塔底層 
	
}
int story15(){//中塔中層  內部 
}
int story16(){//右塔頂層  機關室  檢查機械  機械修復互動 
}
int story17(){//中塔頂層  主控室  霧笛 
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
