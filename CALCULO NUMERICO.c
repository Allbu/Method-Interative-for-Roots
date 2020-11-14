#include <stdio.h>
#include <math.h>
#include <locale.h>
double fun(double x){
	return (x*x*x)-(11*x*x)+(4*x)+60;
}

double deri_fun(double x){
	return (3*x*x)-3;
}

double (*f) (double)=&fun;
double (*p) (double)=&deri_fun;



void bis(double x,double y,int ite){
	setlocale(LC_ALL, "Portuguese");
	double s;
	int i;
	if((*f)(x) * (*f)(y) >0){
		printf("Chute inicial não é correspondente");
		return;	
	}else{
		for(i=0;i<ite;i++){
			printf("x[%i]: %.6f\n\n",i,x);
			printf("y[%i]: %.6f\n\n",i,y);
			s=(x+y)/2;
			printf("%.6f\n\n",s);
			printf("Iteração [%i]: %.6f\n\n",i+1,(*f)(s));
			if((*f)(x)*(*f)(s)>0){x=s;}
			if((*f)(y)*(*f)(s)>0){y=s;}
		}
		printf("-------- Resultado final: %.6f ---------",s);
	}
}

void pos_falsa(double x, double y, int ite){
	setlocale(LC_ALL, "Portuguese");
	int i;
	double s,v,t,g;
	if((*f)(x) * (*f)(y) >0){
	printf("Chute inicial não é correspondente");
	return;	
	}else{
		for(i=0;i<ite;i++){
		printf("x[%i]: %.6f\n\n",i,x);
		printf("y[%i]: %.6f\n\n",i,y);
		v=(*f)(y)-(*f)(x);
		t=x*(*f)(y);
		g=y*(*f)(x);
		s=(t-g)/v;
		printf("%.6f\n\n",s);
		printf("Iteração [%i]: %.6f\n\n",i+1,(*f)(s));
		if((*f)(x)*(*f)(s)>0){x=s;}
		if((*f)(y)*(*f)(s)>0){y=s;}
		}
	printf("-------- Resultado final: %.6f ---------",s);		
	}
}


void sec(double x, double y, int ite){
	setlocale(LC_ALL, "Portuguese");
	int i;
	double s,v,t,g;
	for(i=0;i<ite;i++){
	v=(*f)(y)-(*f)(x);
	t=x*(*f)(y);
	g=y*(*f)(x);
	s=(t-g)/v;
	printf("Iteração [%i]: %.6f\n\n",i+1,(*f)(s));
	printf("Valor da raiz:%.6f\n\n",s);
	if(i%2==0){x=s;}
	if(i%2!=0){y=s;}
	}	
	printf("-------- Resultado final: %.6f ---------",s);	
} 

void newton(double x, int ite){
	setlocale(LC_ALL, "Portuguese");
	int i;
	double s;
	for(i=0;i<ite;i++){
		printf("Valor da função na raiz[%i]: %.6f\n\n",i,(*f)(x));
		s=(*f)(x)/(*p)(x);
		x=x-s;
		printf("Iteração [%i]: %.6f\n\n",i+1,x);
	}
	printf("Valor da função final...: %.6f\n\n",(*f)(x));
	printf("-------- Resultado final: %.6f ---------",x);
}




int main(){
	double x,y;
	pos_falsa(7,12,3);
	//newton(-2,3);
	
}
