//JUEGO2
#include <fstream>
#include <iostream>
#include <windows.h> // Para usar Sleep() y limpiar pantalla en Windows
#include <cstring> // Para manejo de cadenas (strcpy, strcmp)
#include <conio.h> // Funciones de consola
#include <cctype> // Para funciones de caracteres
#include <ctime> // Para generar números aleatorios con srand()
using namespace std;
const int def=50,delay=700;
const char lin[]="----------------";
const char mensajes[def][def]={"Error","Hasta luego","opcion no valida","ingreso exitoso","se realizo exitosamente","no se encontro"};
const char archivos[def][def]={"jugadores.txt","administradores.txt","ranking1.txt","ranking2.txt","ranking3.txt","datos_gen_juego1.txt","datos_juego2.txt","datos_juego3.txt","datos_gen.txt"};

void cls(){ system("cls"); }
bool conf(){ /// CONFIRMAR
    char c;cin>>c;
    cin.ignore();
    return (c=='y'||c=='Y'); }

void mos_mensaje(int cod){ ///MENSAJES
    cls(); cout<<lin<<"  "<<mensajes[cod]<<" "<<lin<<" ";
    Sleep(delay); cls(); }

int sum(){ ///?
    static int count=-1; count++;
    return count;
    }
///ESTRUCTURAS
struct jugador{
  char nom[def];
  int puntajes[3];
  int pos_jueg;
  int tot_punt=0;
  int pos_rank_inter;
  int pos_txt=-1;
};
struct adm{ char nom[def];char contr[def]; };

struct rankin{

  char nom_r[def][def],temporal[def];
  int puntajes_r[def],tam=0,cod_jueg,pos_txt[def];

void cargar_rank(int cod){
    ifstream a(archivos[cod]);
    if(a.is_open()){ a>>tam;
    for(int i=0;i<tam;i++){
        a>>pos_txt[i]>>nom_r[i]>>puntajes_r[i]; }}

    void guardar_rank(int cod){
    ofstream a(archivos[cod]);
    if(a.is_open()){ a<<tam<<" ";
    for(int i=0;i<tam;i++){
    a<<pos_txt[i]<<" "<<nom_r[i]<<" "<<puntajes_r[i]<<" "; }}

    void insert_rankin(jugador j,int punt){
    strcpy(nom_r[tam],j.nom);
     puntajes_r[tam]=punt;
     pos_txt[tam]=j.pos_txt; tam++; }
    void buscar(jugador &jug){
    for(int i=0;i<tam;i++){
    if(pos_txt[i]==jug.pos_txt){
        jug.pos_jueg=i; return;}
        jug.pos_jueg=-1; }

  void ordenar(int val,jugador &jug){
      int pos=jug.pos_jueg;
      if(pos<0){ return;
       puntajes_r[pos]=val; }
};

bool buscarJugador_admin(int cod,char nom_obj[def],adm &admin,jugador &jug){
  ifstream archivo(archivos[cod]); int cant=0,aux_num; char aux[def],nom[def];
  if (archivo.is_open()){ archivo>>cant;
    for(int i=0;i<cant;i++){
      archivo>>aux>>nom;
      if(strcmp(nom,nom_obj)==0){
        if(cod==0){ strcpy(jug.nom,nom); for(int j=0;j<3;j++) archivo>>jug.puntajes[j]; jug.pos_txt=i;}
        else if(cod==1){ archivo>>admin.contr; strcpy(admin.nom,nom);}
        archivo.close(); return true;
      }
      if(cod==0){ for(int j=0;j<3;j++) archivo>>aux_num; } else archivo>>aux;
    }
  }
  if(cod==0) jug.pos_txt=cant+sum(); return false;
}

void cargar_jugador(jugador &jug){
    cout<<"Ingresar nombre:"; cin>>jug.nom; cin.ignore();
    adm tmp;
    if(buscarJugador_admin(0,jug.nom,tmp,jug)){
        for(int i=0;i<3;i++) jug.tot_punt+=jug.puntajes[i];
        mos_mensaje(3);
    } else for(int j=0;j<3;j++) jug.puntajes[j]=0;
}

// ===================== FUNCIONES MATEMÁTICAS RECURSIVAS ===================
int multiplicarRec(int a,int b){
    if(b==0){
    return 0;}
    if(b>0){
    return a+multiplicarRec(a,b-1);}
    return -multiplicarRec(a,-b);}

int dividirRec(int a,int b){ if(b==0) return 0; if(a<b) return 0; return 1+dividirRec(a-b,b);}
int factorial(int a){ if(a==0||a==1) return 1; return a*factorial(a-1);}
int exponencial(int a,int b){ if(b==0) return 1; return a*exponencial(a,b-1);}
int DecimalaBinario(int n){ if(n==0) return 0; return DecimalaBinario(n/2)*10+(n%2);}

// ===================== DEMOSTRACIONES PASO A PASO =========================
void explicarMultiplicacionColumna(int a,int b){
  cout<<"=== MULTIPLICACIÓN EN COLUMNA ===\nOperación: "<<a<<" x "<<b<<"\n";
  int factor=1, multiplicador=b, resultadoFinal=0, paso=1;
  while (multiplicador>0){
    int digito = multiplicador % 10;
    int parcial = digito * a;
    cout<<"Paso "<<paso++<<": "<<a<<" x "<<digito<<" = "<<parcial;
    if(factor>1) cout<<" (desplazado "<<factor<<" posiciones)";
    cout<<"\n";
    resultadoFinal += parcial * factor;
    multiplicador /= 10;
    factor *= 10;
  }
  cout<<"Resultado final: "<<resultadoFinal<<"\n";
}

void explicarDivisionVisual(int a,int b){
  cout<<"=== DIVISIÓN MEDIANTE RESTAS SUCESIVAS ===\n";
  cout<<"Operación: "<<a<<" ÷ "<<b<<"\n";
  if(b==0){ cout<<"Error: división por cero.\n"; return; }
  int resto=a,cociente=0,iter=1;
  while(resto>=b){
    resto -= b; cociente++;
    cout<<"Iter "<<iter++<<": resto = "<<resto<<"\n";
  }
  cout<<"Cociente: "<<cociente<<" | Resto: "<<resto<<"\n";
}

void explicarFactorialVisual(int a){
  cout<<"=== FACTORIAL ===\n"<<a<<"! = ";
  int prod=1;
  for(int i=a;i>0;i--){ cout<<i; prod*=i; if(i>1) cout<<" x "; }
  cout<<" = "<<prod<<"\n";
}

void explicarExponencialVisual(int a,int b){
  cout<<"=== EXPONENCIAL ===\n"<<a<<"^"<<b<<" = ";
  int acum=1;
  for(int i=0;i<b;i++){ acum*=a; cout<<a; if(i<b-1) cout<<" x "; }
  cout<<" = "<<acum<<"\n";
}

void explicarDecimalABinario(int a){
  cout<<"=== DECIMAL A BINARIO ===\n";
  if(a==0){ cout<<"0 en binario es 0\n"; return; }
  int original=a, pasos[64], cnt=0;
  while(a>0){ pasos[cnt++]=a%2; cout<<a<<" /2, residuo "<<a%2<<"\n"; a/=2; }
  cout<<"Binario: "; for(int i=cnt-1;i>=0;i--) cout<<pasos[i]; cout<<"\n";
}

// ===================== GENERADORES POR NIVEL =============================
int generarNumeroPorNivel(int n){ switch(n){ case 1:return rand()%10+1; case 2:return rand()%90+10; case 3:return rand()%900+100;} return 1; }
int generarNumeroPorNivelFactorial(int n){ switch(n){ case 1:return rand()%5+1; case 2:return rand()%6+5; case 3:return rand()%3+10;} return 1;}
int generarNumeroPorNivelExponencial(int n){ switch(n){ case 1:return rand()%3+1; case 2:return rand()%4+3; case 3:return rand()%4+6;} return 1;}

// ===================== TURNO DEL JUGADOR ===============================
void turnoJugador(jugador jugadores[def],rankin &rank_inter,rankin &rank_jueg,bool grupo,int lis[4][def],int nivel){
  int opcion,a,b,respuesta,resultado;
  int valorfactorial,factor,exponente;
  a=generarNumeroPorNivel(nivel); b=generarNumeroPorNivel(nivel);
  valorfactorial=generarNumeroPorNivelFactorial(nivel);
  factor=generarNumeroPorNivelExponencial(nivel);
  exponente=generarNumeroPorNivelExponencial(nivel);

  cout<<"Turno de "<<jugadores[lis[0][0]].nom<<" (Puntaje: "<<jugadores[lis[0][0]].puntajes[1]<<")\n";
  cout<<"1. Multiplicación 2. División 3. Factorial 4. Exponencial 5. Decimal a binario\nElige una opción: "; cin>>opcion;

  if(opcion==1){ cout<<"¿Cuánto es "<<a<<" x "<<b<<"? "; cin>>respuesta; resultado=multiplicarRec(a,b); }
  else if(opcion==2){ cout<<"¿Cuánto es "<<a<<" ÷ "<<b<<"? "; cin>>respuesta; resultado=dividirRec(a,b); }
  else if(opcion==3){ cout<<"¿Cuánto es "<<valorfactorial<<"! ? "; cin>>respuesta; resultado=factorial(valorfactorial); }
  else if(opcion==4){ cout<<"¿Cuánto es "<<factor<<"^"<<exponente<<"? "; cin>>respuesta; resultado=exponencial(factor,exponente); }
  else if(opcion==5){ cout<<"¿Cuánto es "<<a<<" en binario? "; cin>>respuesta; resultado=DecimalaBinario(a); }
  else { cout<<"Opción no válida.\n"; return; }

  // ================== PUNTAJE Y RANKING =========================
  if(respuesta==resultado){
      cout<<"¡Correcto!\n";
      jugadores[lis[0][0]].puntajes[1]+=15*nivel;
  }else{
      cout<<"Incorrecto. La respuesta era "<<resultado<<".\n";
      jugadores[lis[0][0]].puntajes[1]-=5;
  }

  if(jugadores[lis[0][0]].pos_jueg==-1){
      rank_jueg.insert_rankin(jugadores[lis[0][0]], jugadores[lis[0][0]].puntajes[1]);
      jugadores[lis[0][0]].pos_jueg = rank_jueg.tam-1;
  }

  rank_jueg.ordenar(jugadores[lis[0][0]].puntajes[1], jugadores[lis[0][0]]);

  if(rank_inter.tam>1)
      rank_inter.ordenar(jugadores[lis[0][0]].tot_punt, jugadores[lis[0][0]]);

  // ================== DEMOSTRACIÓN OPCIONAL =====================
  cout<<"¿Quieres ver la demostración paso a paso? (y/n): "; if(conf()){
    switch(opcion){
      case 1: explicarMultiplicacionColumna(a,b); break;
      case 2: explicarDivisionVisual(a,b); break;
      case 3: explicarFactorialVisual(valorfactorial); break;
      case 4: explicarExponencialVisual(factor,exponente); break;
      case 5: explicarDecimalABinario(a); break;
      default: break;
    }
  }
}

// ================== JUEGO 2 - MENU ============================
void jue_mat(jugador jugadores[def],rankin &rank_inter,int tam){
  int elec, nivel, lis[4][def], pos;
  rankin rank_jueg; rank_jueg.cod_jueg=1; rank_jueg.cargar_rank(3);

  if(tam>1){
    do{
      cout<<"Jugadores:\n";
      for(int i=0;i<tam;i++) cout<<i+1<<".- "<<jugadores[i].nom<<"\n";
      cout<<"-1 salir\nElige jugador: "; cin>>pos;
      if(pos==-1) break;
      lis[0][0]=pos-1;

      do{
        cout<<"1.Fácil 2.Medio 3.Difícil -1.volverNivel: "; cin>>elec;
        if(elec==-1) break;
        turnoJugador(jugadores,rank_inter,rank_jueg,false,lis,elec);
      }while(elec!=-1);

    }while(true);
  }else{
    lis[0][0]=0;
    do{
      cout<<"1.Fácil 2.Medio 3.Difícil -1.salir Elige nivel: "; cin>>elec;
      if(elec==-1) break;
      turnoJugador(jugadores,rank_inter,rank_jueg,false,lis,elec);
    }while(elec!=-1);
  }

  rank_jueg.guardar_rank(3);
}

// ================== MAIN ============================
int main(){
    srand(time(NULL));
    jugador jugadores[def];
    rankin rank_inter; rank_inter.cod_jueg=-1;
    int can;

    cout << "¿Cuántos jugadores jugarán? "; cin >> can; cin.ignore();
    for(int i = 0; i < can; i++){
        cout << "Jugador " << i+1 << ":\n";
        cargar_jugador(jugadores[i]);
    }

    jue_mat(jugadores, rank_inter, can);
    mos_mensaje(1);
    return 0;
}
