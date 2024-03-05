#include <graphics.h>
#include <curl/curl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <math.h>

txt_function(const char *ptr, size_t size, size_t nmemb, void *stream){
    
    FILE * fi;
    fi = fopen("buf.txt","w+");
    if(fi == NULL)
    {
        printf("ERROR!!");
        return(-1);
    }
    fputs(ptr,fi);
    fclose(fi);
}

struct koordinat
{
    int x;
    int y;
};

int main(){
	setlocale(LC_ALL,"Turkish");
	CURL *curl;
	curl = curl_easy_init();
	
	if (curl){
		CURLcode code;
		curl_easy_setopt(curl,CURLOPT_URL, "http://abilgisayar.kocaeli.edu.tr/prolab1/prolab1.txt");
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, txt_function);
		code = curl_easy_perform(curl);
		curl_easy_cleanup(curl);
	
	}
	
	char plain[2000];
	
	FILE * fi;
    fi = fopen("buf.txt","r+");
    if(fi == NULL)
    {
        printf("ERROR!!");
        return(-1);
    }
    fread(plain,2000,1,fi);
    
    fclose(fi);

    int a=-1;
	char satirlar[10][200];
	char delim[2] = "B";
	char delim2[2] = "(";
	char delim3[3] = ")(";
    char * token;
    token = strtok(plain,delim);
    while (token != NULL){
    	
    	
    	for(int i=0;token[i]!='\0';i++){
    		if(token[i]=='F')
    		token[i]='\0';
		}
    	strcpy(satirlar[a],token);
    	
    	token = strtok(NULL,delim);
    	a++;
    	
	}
int x;
printf("Birim sondaj maliyetini TL cinsinden giriniz: ");
scanf("%d",&x);
int b;
printf("Çizdirmek istediðiniz satýr index numarasýný giriniz: ");
scanf("%d",&b);
struct koordinat koseler[30];
for(int i=0;i<30;i++){
	koseler[i].x = koseler[i].y = 0;
	}
int c=0;
token = strtok(satirlar[b],delim2);

while( token != NULL )
    {

        sscanf(token,"%d,%d",&koseler[c].x,&koseler[c].y);

            token = strtok(NULL, delim3);
            c++;

    }
c=0;   

while(koseler[c].x != 0 && koseler[c].y != 0){
	c++;

}
int bufarray[c*2];
int d,e;
a=0;
for(int i=0;i<c;i++){
	
	bufarray[a]=koseler[i].x*10;
	a++;
	bufarray[a]=koseler[i].y*10;
	a++;
	
}
for(int i=1;i<c;i++){
	if(koseler[i].x==koseler[0].x && koseler[i].y==koseler[0].y){
		
		d=i+1;
		break;
	}
}
int array1[d*2];


a=0;
for(int i=0;i<d;i++){
	
	array1[a]=koseler[i].x*10;
	a++;
	array1[a]=koseler[i].y*10;
	a++;
	
}
int toplam=0;
double alan=0;
for(int i=0;i<((d*2)-2);i+=2){

    toplam = toplam + ((array1[((i+2) % ((d*2)-2)  )] - array1[((i+(d*2)-4) % ((d*2)-2))])*(array1[i+1]));
}
alan = alan + fabs(toplam /2);
initwindow(800,600);
settextstyle(8,0,3);
outtextxy(50,550,"Devam etmek icin herhangi bir tusa basiniz");
setfillstyle(SOLID_FILL,3);
  fillpoly(d, array1);
  printf("Toplam kaynak rezerv maliyeti: %.2f TL\n",((alan/10)*x));
  getch(); 
 
for(int i=d+1;i<c;i++){
	
		if(koseler[i].x==koseler[d].x && koseler[i].y==koseler[d].y){
		e=i+1;
		break;
	}
}
int f= e-d;
int array2[f*2];
a=0;
for(int i=d;i<e;i++){
	
	array2[a]=koseler[i].x*10;
	a++;
	array2[a]=koseler[i].y*10;
	a++;
	
}
toplam =0;
for(int i=0;i<((f*2)-2);i+=2){

    toplam = toplam + ((array2[((i+2) % ((f*2)-2)  )] - array2[((i+(f*2)-4) % ((f*2)-2))])*(array2[i+1]));
}
alan = alan + fabs(toplam /2);

setfillstyle(SOLID_FILL,5);
  fillpoly(f,array2);
  printf("Toplam kaynak rezerv maliyeti: %.2f TL\n",((alan/10)*x));
  getch();
  
  for(int i=e+1;i<c;i++){
	
		if(koseler[i].x==koseler[e].x && koseler[i].y==koseler[e].y){
		f=i+1;
		break;
	}
}
int g= f-e;
int array3[g*2];
a=0;
for(int i=e;i<f;i++){
	
	array3[a]=koseler[i].x*10;
	a++;
	array3[a]=koseler[i].y*10;
	a++;
	
}
toplam =0;
for(int i=0;i<((g*2)-2);i+=2){

    toplam = toplam + ((array3[((i+2) % ((g*2)-2)  )] - array3[((i+(g*2)-4) % ((g*2)-2))])*(array3[i+1]));
}
alan = alan + fabs(toplam /2);

setfillstyle(SOLID_FILL,12);
  fillpoly(g,array2);

printf("Toplam kaynak rezerv maliyeti: %.2f TL\n",((alan/10)*x));
a=0;

getch();
closegraph();
return 0;
}
