#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#define INF 9999999

typedef int bool;
enum { false, true };
typedef struct st_ciudades st_ciudades;
typedef struct st_carreteras st_carreteras;
typedef struct ciunke ciunke;
int carreteras=400,ciudades=50,into=0;
float distanciax=0;
 struct st_ciudades {
   int coordenada_x;
   int coordenada_y;
   char* nombre_ciudad;
   int visitado;
   float heuristica;
   float recorrido;
} ciu[350];

struct ciunke{
char * nombre;
float funcion;

}ciutre[50000];

   struct st_carreteras{
   char* nombre_carretera;
   char* ciudad_origen;
   char* ciudad_destino;
   char* carretera_origen;
   int distancia_origen;
   char* carretera_destino;
   int distancia_destino;
   float distancia;
}carr[500];

float c_distancia(st_ciudades ciud1[],st_ciudades pete, st_ciudades pepe){
int i,j;
float calc;
for (i=0;i<350;i++){

        if (ciud1[i].nombre_ciudad==pete.nombre_ciudad){
    for (j=0;j<350;j++)
     if (ciud1[j].nombre_ciudad==pepe.nombre_ciudad)
        calc  = sqrt(pow(ciud1[i].coordenada_x-ciud1[j].coordenada_x,2)+pow(ciud1[i].coordenada_y-ciud1[j].coordenada_y,2));
                //distancia euclidiana, usar -lmath
                return calc;
        }
    }
    return INF;
}

void marcar (st_ciudades ciud2[], char *pata){
int i=0;
for (i=0;i<350;i++){
if (strcmp(pata,ciud2[i].nombre_ciudad)==0)
    ciud2[i].visitado=1;

}

}


//pete(carr,ciu[0].nombre_ciudad,ciu);
int pete(st_carreteras ciud1[], char *potix,st_ciudades  ciud2[] ,int *y){
        int j;
for (j=0;j<350;j++){
if (strcmp(ciud2[j].nombre_ciudad,potix)==0&&ciud2[j].visitado==1)
    return 0;
}
        marcar( ciud2,potix);
        (*y)++;
        for (j=0;j<500;j++){
        if (strcmp(potix,ciud1[j].ciudad_destino)==0){
            pete(ciud1,ciud1[j].ciudad_origen,ciud2,y);

            }
        }

return 1;
}

//función heurística en el parámetro recibe el listado de ciudades y una ciudad destino.
// Luego almacena distancia euclidiana de todas las ciudades que sí existen
void c_heuristic(st_ciudades ciudades[],st_ciudades ciuxi){
    int i;
    for(i=0;i<350;i++)
            if(strlen(ciudades[i].nombre_ciudad)>0){
                ciudades[i].heuristica = c_distancia(ciudades, ciudades[i], ciuxi);
      //          printf("%i\n", i);
//                printf("La hermosa heuristica que nos ensegno la tia Pini es: para %s = %f \n",ciudades[i].nombre_ciudad,ciudades[i].heuristica);
        }
}

void bubbleSort(ciunke arr[], int n) {

      bool swapped = true;

      int j = 0;

      ciunke tmp;

      while (swapped) {

            swapped = false;

            j++;
int i;
            for ( i = 0; i < n - j; i++) {

                  if (arr[i].funcion > arr[i + 1].funcion) {

                        tmp = arr[i];

                        arr[i] = arr[i + 1];

                        arr[i + 1] = tmp;

                        swapped = true;

                  }

            }

      }

}

bool recorrer2(st_carreteras carre[],st_ciudades cius[], ciunke cius2[],st_ciudades pepe,st_ciudades lino,float recorrido, char * khe){
int j,e;
//getchar();

c_heuristic(cius,lino);


if (pepe.nombre_ciudad!=lino.nombre_ciudad)

    marcar(cius,pepe.nombre_ciudad);
//pepe.visitado=1;
if (pepe.nombre_ciudad==lino.nombre_ciudad){
    //printf("Exito %s : %f  desde: %s\n", pepe.nombre_ciudad, pepe.recorrido, khe);
    distanciax= pepe.recorrido+distanciax;
   // return pepe.recorrido;
return true;
}
// printf("Actual %s : %f desde: %s\n\n", pepe.nombre_ciudad, pepe.recorrido, khe);

float aux=0, min=INF;
  for (j=0;j<500;j++){
        if (carre[j].ciudad_origen==pepe.nombre_ciudad){
              for(e=0;e<350;e++){
              if(cius[e].nombre_ciudad==carre[j].ciudad_destino){
              //  printf("la suma entre la heuristica y la distancia es: %s   %f\n", carre[j].ciudad_destino, cius[e].heuristica+carre[j].distancia);

                //cius[e].recorrido
                float nene=recorrido+carre[j].distancia;

                //cius[e].recorrido=nene;
                if(cius[e].recorrido>0&&cius[e].recorrido<nene)nene=cius[e].recorrido;
                cius[e].recorrido=nene;



                aux=cius[e].heuristica+cius[e].recorrido;


                cius2[into].nombre=cius[e].nombre_ciudad;
                cius2[into].funcion=  cius[e].heuristica+carre[j].distancia+cius[e].recorrido;// //+cius[e].recorrido;//  //
                into++;


                if(aux<min) min=aux;
                }

              }
              }
            }


            bubbleSort(cius2,into);
int a;
/*
printf("%i\n",into);
for (a=0;a<into;a++)
printf("%s : funcion :%f\n",ciutre[a].nombre,ciutre[a].funcion);
for (a=0;a<350;a++)
    if (strlen(cius[a].nombre_ciudad)>0)
printf("%s : recorrido :%f\n",cius[a].nombre_ciudad,cius[a].recorrido);

*/
int ki=0;

            for (e=0;e<=into;e++){
              //  for (j=0;j<500;j++){
              int k;

            for(k=0;k<350;k++){
                if(strlen(cius[k].nombre_ciudad)>0)
                if(cius[k].nombre_ciudad==cius2[e].nombre){
            //    printf("El minimo es: %s   : %f  \n",carr[j].ciudad_destino, min);
                if(cius[k].visitado!=1)
            if( recorrer2(carre,cius,cius2,cius[k],lino,cius[k].recorrido,pepe.nombre_ciudad))ki++;
           //    recorrer2(carre,cius,cius2,cius[k],lino,cius[k].recorrido,pepe.nombre_ciudad);
                //cius[k].visitado=1;
                //pepe.visitado=1;

               // return true;
                }
               //


            }


            //}

cius2[e].nombre="";
cius2[e].funcion= INF;

            }

           // for(a=0;a<350;a++)
             //   ciu[a].visitado=0;



 if (ki>0)return true;
          else  return false;

}




void crear (st_ciudades cunco[], st_carreteras yolo[]){
int i,j;
float aux, menor;
menor = INF;

for (i=0;i<350;i++){
    if (strlen(cunco[i].nombre_ciudad)>0&&cunco[i].visitado!=1){
        printf("%i %s Necesita ser visitada.\n", i, cunco[i].nombre_ciudad);
        for(j=0;j<350;j++){
                if(i!=j && cunco[j].visitado==1) {
            aux = c_distancia(cunco,cunco[j],cunco[i]);
            //printf("%f", aux);
            if(aux<menor) menor = aux;
                        }
                    }
                    printf("%f es la mínima distancia.\n",menor);

                    for(j=0;j<350;j++)
                        if (c_distancia(cunco,cunco[j],cunco[i])==menor){
                        printf ("Ciudad desde la cual se debe hacer una carretera: %s \n", cunco[j].nombre_ciudad);
                        yolo[carreteras].ciudad_origen=cunco[j].nombre_ciudad;
                        yolo[carreteras].ciudad_destino=cunco[i].nombre_ciudad;
                        yolo[carreteras].distancia=menor;
                        yolo[carreteras].nombre_carretera="CarreteraFea";
                        carreteras++;
                        yolo[carreteras].ciudad_origen=cunco[i].nombre_ciudad;
                        yolo[carreteras].ciudad_destino=cunco[j].nombre_ciudad;
                        yolo[carreteras].distancia=menor;
                        yolo[carreteras].nombre_carretera="CarreteraFea";
                        carreteras++;
                        j=350,i=350;
                        }
                }
            }



    }


int main(int argc, char *argv[]){
int a;
for(a=0;a<350;a++){
     ciu[a].visitado=0;
     ciu[a].heuristica=INF;
    ciu[a].nombre_ciudad="";
}

for(a=0;a<500;a++){
    carr[a].nombre_carretera="";
    carr[a].ciudad_destino="";
    carr[a].ciudad_origen="";
    carr[a].distancia=INF;
}

ciu[18].coordenada_x = 0;
ciu[18].coordenada_y = 40;
ciu[18].nombre_ciudad = "Manzanalandita";

ciu[28].coordenada_x = 20;
ciu[28].coordenada_y = 80;
ciu[28].nombre_ciudad = "Isapisa";


ciu[0].coordenada_x = 0;
ciu[0].coordenada_y = 0;
ciu[0].nombre_ciudad = "Manzanalandia";

ciu[1].coordenada_x = 20;
ciu[1].coordenada_y = 30;
ciu[1].nombre_ciudad = "Naranjalandia";

ciu[2].coordenada_x = -20;
ciu[2].coordenada_y = -20;
ciu[2].nombre_ciudad = "Peralandia";

ciu[3].coordenada_x = -25;
ciu[3].coordenada_y = -30;
ciu[3].nombre_ciudad = "Kiwilandia";

ciu[4].coordenada_x = 20;
ciu[4].coordenada_y = -25;
ciu[4].nombre_ciudad = "Duraznolandia";

carr[0].nombre_carretera="RutaMP";
carr[0].ciudad_origen="Manzanalandia";
carr[0].ciudad_destino="Peralandia";
carr[0].distancia=30;

carr[1].nombre_carretera="RutaMK";
carr[1].ciudad_origen="Manzanalandia";
carr[1].ciudad_destino="Kiwilandia";
carr[1].distancia=50;

carr[2].nombre_carretera="RutaMD";
carr[2].ciudad_origen="Manzanalandia";
carr[2].ciudad_destino="Duraznolandia";
carr[2].distancia=40;

carr[3].nombre_carretera="RutaNP";
carr[3].ciudad_origen="Naranjalandia";
carr[3].ciudad_destino="Peralandia";
carr[3].distancia=50;

carr[4].nombre_carretera="RutaND";
carr[4].ciudad_origen="Naranjalandia";
carr[4].ciudad_destino="Duraznolandia";
carr[4].distancia=60;

carr[5].nombre_carretera="RutaPK";
carr[5].ciudad_origen="Peralandia";
carr[5].ciudad_destino="Kiwilandia";
carr[5].distancia=55;

carr[6].nombre_carretera="RutaDK";
carr[6].ciudad_origen="Kiwilandia";
carr[6].ciudad_destino="Duraznolandia";
carr[6].distancia=50;

carr[7].nombre_carretera="RutaPKM";
carr[7].ciudad_origen="RutaPK";
carr[7].distancia_origen=10;
carr[7].distancia_destino=5;
carr[7].ciudad_destino="RutaMK";
carr[7].distancia=25;

carr[8].nombre_carretera="RutaMPN";
carr[8].ciudad_origen="Manzanalandia";
carr[8].ciudad_destino="RutaNP";
carr[8].distancia_destino=10;
carr[8].distancia=20;

carr[9].nombre_carretera="RutaMP";
carr[9].ciudad_origen="Peralandia";
carr[9].ciudad_destino="Manzanalandia";
carr[9].distancia=30;

carr[10].nombre_carretera="RutaMK";
carr[10].ciudad_origen="Kiwilandia";
carr[10].ciudad_destino="Manzanalandia";
carr[10].distancia=50;

carr[11].nombre_carretera="RutaMD";
carr[11].ciudad_origen="Duraznolandia";
carr[11].ciudad_destino="Manzanalandia";
carr[11].distancia=40;

carr[12].nombre_carretera="RutaNP";
carr[12].ciudad_origen="Peralandia";
carr[12].ciudad_destino="Naranjalandia";
carr[12].distancia=50;

carr[13].nombre_carretera="RutaND";
carr[13].ciudad_origen="Duraznolandia";
carr[13].ciudad_destino="Naranjalandia";
carr[13].distancia=60;

carr[14].nombre_carretera="RutaPK";
carr[14].ciudad_origen="Kiwilandia";
carr[14].ciudad_destino="Peralandia";
carr[14].distancia=55;

carr[15].nombre_carretera="RutaDK";
carr[15].ciudad_origen="Duraznolandia";
carr[15].ciudad_destino="Kiwilandia";
carr[15].distancia=50;



int i;
//for(i=0;i<20;i++){
//    printf("%s \n",ciu[i].nombre_ciudad);
 //   printf("%s \n",carr[i].nombre_carretera);
//}

//pete(carr,ciu[1],ciu[3]);
int y=0;
int contar=0,t=1;
i=0;

while(t!=9){
     for(a=0;a<350;a++){
     ciu[a].visitado=0;
}
y=0;
contar=0;
pete(carr,ciu[i].nombre_ciudad,ciu,&y);
for(a=0;a<350;a++){
       if (strlen(ciu[a].nombre_ciudad)>0)contar++;

}
if(contar!=y){
    printf("No totalmente conectado\n");
    crear(ciu,carr);
}
else {printf("Correctamente conectado\n");
t=9;
}
i++;
}

for(i=0;i<350;i++){

       if (ciu[i].visitado==1){
        printf("%s : ",ciu[i].nombre_ciudad);
    printf("Visitado\n" );
            } //   printf("%s \n",carr[i].nombre_carretera);
        }
        for(i=0;i<500;i++){
        if (strlen(carr[i].nombre_carretera)>0){
            printf("%i es %s : %s , %s\n",i,carr[i].nombre_carretera,carr[i].ciudad_destino,carr[i].ciudad_origen );

        }

        }

    //   float ye = c_distancia(ciu,ciu[0],ciu[3]);
   // printf("%f",ye);

  //  c_heuristic(ciu,ciu[3]);
  int k=0;
     for(a=0;a<350;a++){
     ciu[a].visitado=0;
}

// recorrer2(carr,ciu,ciutre,ciu[3],ciu[18],0,"Inicio");


float aux,mini,suma=0;/*
for(a=0;a<350;a++){
        if (strlen(ciu[a].nombre_ciudad)>0)


}
*/
int hops=2;

ciunke rarepepe[350];
int peperare=0;
int e;
for (a=0;a<350;a++){
    if (strlen(ciu[a].nombre_ciudad)>0){
    suma=0;
        for (k=0;k<350;k++)
        ciu[k].recorrido=0;
     int lulex=0;
     while(lulex<hops){
            suma=0;
  for(k=0;k<350;k++){
        if(strlen(ciu[k].nombre_ciudad)>0){
                for(e=0;e<350;e++)ciu[e].visitado=0;
            into=0;

            recorrer2(carr,ciu,ciutre,ciu[a],ciu[k],0,"Inicio");
           // printf("Yendo a: %i",k);

         //    for(a=0;a<350;a++)ciu[a].visitado=0;
        //recorrer2(carr,ciu,ciutre,ciu[0],ciu[k],0,"Inicio");
      if (a!=k)  suma=ciu[k].recorrido+suma;
   //   if(a!=k)printf(":  %f\n",suma);
     // else puts("\n");
    }
    }
    lulex++;}
//printf("La ciudad %s tiene %f total\n",ciu[a].nombre_ciudad,suma);
rarepepe[peperare].nombre= ciu[a].nombre_ciudad;
rarepepe[peperare].funcion=suma;//hops;
peperare++;
}
}

bubbleSort(rarepepe,peperare);

printf("La mejor Ciudad para poner la planta es: %s con %f de recorrido total\n",rarepepe[0].nombre,rarepepe[0].funcion);
/*
 for (a=0;a<350;a++)
 if (strlen(ciu[a].nombre_ciudad)>0)
    printf("%s  : %f : %i\n",ciu[a].nombre_ciudad,ciu[a].recorrido,ciu[a].visitado);


for (a=0;a<into;a++)
printf("%s : funcion :%f\n",ciutre[a].nombre,ciutre[a].funcion);
*/
int te,u;

//float aux;
distanciax =0;
/*
for (u=0;u<350;u++){

        if(strlen(ciu[u].nombre_ciudad)>0){

            distanciax=0;
    for (te=0;te<350;te++){
        if (strlen(ciu[te].nombre_ciudad)>0){
        recorrer2(carr,ciu,ciutre,ciu[u],ciu[te],0,"Inicio");
       // printf

        }
            }

    aux=distanciax;
    printf("%s:  %f\n",ciu[u].nombre_ciudad,aux);
        }

}*/

}
