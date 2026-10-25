#include <stdio.h>
#include <stdlib.h>
#include <time.h>
float train_model[][2]={
   {0,0},
   {1,2},
   {2,4},
   {3,6},
   {4,8},
   {5,10}
};
#define traincount (sizeof(train_model)/sizeof(train_model[0]))
float cost(float w,float b){
        float result=0.0f;
        for(size_t i =0;i < traincount;++i){
        float x=train_model[i][0];
	float y=w*x+b;
	float d=y-train_model[i][1];
	result+=d *d;
	}
	result /= traincount;
	return result;
}
float rand_float(void){
return (float) rand()/(float)RAND_MAX;

}



int main(){
srand(time(0));
float w=rand_float()*10.0f;
float b =rand_float()*5.0f;
float eps=1e-3;
float rate=1e-3;
printf("before train irr: %f\n",cost(w,b));

for(size_t i =0;i< 400;++i){
	float c = cost(w,b);
float dw=(cost(w+eps,b)-c)/eps;
float db=(cost(w,b+eps)-c)/eps;
w-=rate*dw;
b-=rate*db;
printf("cost = %f, w = %f, b = %f \n",cost(w,b),w,b);


}
printf("w = %f, b = %f\n",w,b); 
return 0;
}
