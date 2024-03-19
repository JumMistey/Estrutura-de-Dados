#include <stdio.h>
#include <stdlib.h>


int args(argc[1], argv[2]);

int main (int argc, char* argv[]){ 

   do {

       printf("\n%s %s\n", argv[1], argv[2]);

   }while(strcmp (args(argc[1], argv[2])) <= 0);

   //double media
   
   //(argv[1] + argv[2])/2 = media;

   //printf("Media: %d", media);

    int numeros[n],a,b,c,maior=0,menor=0,medio=0;



printf("Digite numeros:\n");
scanf("%d %d %d",&numeros[n]);


for(a=0;a<3;a++){
    if(numeros[a]>numeros[a+1]){
        numeros[a]=maior;
    }


}
for(b=0;b<3;b++){
    if(numeros[b]<numeros[b+1]){
        numeros[b]=menor;
    }
}
for(c=0;c<3;c++){
    if(numeros[c]<maior && numeros[c]>menor){
        numeros[c]=medio;
    }
}

printf("%d %d %d",menor,medio,maior);

    exit(0);
}