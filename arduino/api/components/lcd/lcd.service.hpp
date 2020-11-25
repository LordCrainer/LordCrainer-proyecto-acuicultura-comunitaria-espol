#include "lcd.model.hpp"
//Variables para menu y submenu
int menuCont = 1; 
int submenuCont=1;
int submenu1Cont=1;
//Definicion tipo de dato variables banderas
boolean flagArriba, flagAbajo, flagOk, flagCancelar;   

void setup_lcd()
{
  lcd.begin(20, 4);
  pinMode(BOT_ARRIBA,INPUT_PULLUP);
  pinMode(BOT_ABAJO,INPUT_PULLUP);
  pinMode(BOT_OK,INPUT_PULLUP);
  pinMode(BOT_CANCELAR,INPUT_PULLUP);

}

void flechaArriba(){
  lcd.createChar(1, CARACTER_ARRIBA);
  lcd.setCursor(10,1);
  lcd.write((byte)1);
  }

void flechaAbajo(){
  lcd.createChar(2, CARACTER_ABAJO);
  lcd.setCursor(10,3);
  lcd.write((byte)2);
  }
//Funcion para regresar al menu principal, permite salir del bucle al presionar cancelMenuar
void cancelMenu(){    
  if(!digitalRead(BOT_CANCELAR)){ flagCancelar= 0x01;}
  if(digitalRead(BOT_CANCELAR) && flagCancelar){flagCancelar=0x00;flagOk=0x00;lcd.clear();submenuCont=1;submenuCont=1;}
}


void piscId(){
   if(!digitalRead(BOT_ARRIBA)) flagArriba = 0x01;          //Bandera para boton abajo
   if(!digitalRead(BOT_ABAJO)) flagAbajo = 0x01;          //Bandera para boton abajo
   if(digitalRead(BOT_ARRIBA) && flagArriba)                //Boton abajo y bandera
   {  
    flagArriba = 0x00;                                 //Limpia flag
      lcd.clear();                                     //Limpia display
     submenuCont--;      
      if(submenuCont < 1) submenuCont = 5;//Decrementa menu
                          //Si submenu<1 entonces submenu=3
   } 
   if(digitalRead(BOT_ABAJO) && flagAbajo)                //Boton abajo y bandera
   {  
    flagAbajo = 0x00;                                 //Limpia flag
      lcd.clear();                                     //Limpia display
      submenuCont++;      
      if(submenuCont > 5) submenuCont = 1;//Decrementa menu
                          //Si menuCont<1 entonces menuCont=3
   }
    switch(submenuCont)                  //Controla los casos del submenu piscId
    {
            
       case  1:                                      
            lcd.setCursor(1,0);
            lcd.print("Seleccione piscina:");
            lcd.setCursor(7,2);
            lcd.print("ID 1");
            flechaAbajo(); //Caracter Direccional
            //act1();Para lectura sd
            cancelMenu();//Permite regresar al menu principal
             break; 
        case 2:
            lcd.setCursor(1,0);
            lcd.print("Seleccione piscina:");
            flechaArriba(); //Caracter Direccional
            lcd.setCursor(7,2);
            lcd.print("ID 2");
            //act2();Para lectura sd
            flechaAbajo(); //Caracter Direccional
            cancelMenu(); //Permite regresar al menu principal
            break;
        case 3:
            lcd.setCursor(1,0);
            lcd.print("Seleccione piscina:");
            flechaArriba(); //Caracter Direccional
            lcd.setCursor(7,2);
            lcd.print("ID 3");
            flechaAbajo(); //Caracter Direccional
            //act3();Para lectura sd
            cancelMenu(); //Permite regresar al menu principal
            break;
        case 4:
            lcd.setCursor(1,0);
            lcd.print("Seleccione piscina:");
            flechaArriba(); //Caracter Direccional
            lcd.setCursor(7,2);
            lcd.print("ID 4");
            flechaAbajo(); //Caracter Direccional
            //act4();Para lectura sd
            cancelMenu(); //Permite regresar al menu principal
            break;
     case 5:
           lcd.setCursor(1,0);
           lcd.print("Seleccione piscina:");
           flechaArriba(); //Caracter Direccional
           lcd.setCursor(7,2);
           lcd.print("ID 5");
           //act5();Para lectura sd
           cancelMenu(); //Permite regresar al menu principal
           break;
  }
}



void configTiempo(){
   
   if(!digitalRead(BOT_ARRIBA)) flagArriba = 0x01;      //Bandera para boton abajo
   if(!digitalRead(BOT_ABAJO)) flagAbajo = 0x01;        //Bandera para boton abajo
   if(digitalRead(BOT_ARRIBA) && flagArriba)              //Boton abajo y bandera
   {  
    flagArriba = 0x00;                                 //Limpia flag
      lcd.clear();                                     //Limpia display
     submenu1Cont--;      
    if(submenu1Cont < 1) submenu1Cont = 4;//Decrementa menu
                        //Si menuCont<1 entonces submenu=4
   } 
   if(digitalRead(BOT_ABAJO) && flagAbajo)               //Boton abajo y bandera
   {  
    flagAbajo = 0x00;                                   //Limpia flag
      lcd.clear();                                     //Limpia display
      submenu1Cont++;      
      if(submenu1Cont > 4) submenu1Cont = 1;//Decrementa submenu
                          //Si submenu<1 entonces submenu=3
   } 
    switch(submenu1Cont)                               //submenu para configurar tiempo de inicio
    {
            
       case  1:                                       //Caso 1
            lcd.setCursor(1,0);
            lcd.print("Seleccione tiempo:");
            lcd.setCursor(4,2);
            lcd.print("30 segundos");
            //act1();Para lectura sd
            flechaAbajo();
            cancelMenu();     //Para regresar al menu principal
             break; 
        case 2:
            lcd.setCursor(1,0);
            lcd.print("Seleccione tiempo:");
            flechaArriba();
            lcd.setCursor(4,2);
            lcd.print("60 segundos");
            //act2();Para lectura sd
            flechaAbajo();
            cancelMenu(); //Para regresar al menu principal
            break;
        case 3:
            lcd.setCursor(1,0);
            lcd.print("Seleccione tiempo:");
            flechaArriba();
            lcd.setCursor(4,2);
            lcd.print("90 segundos");
            //act3();Para lectura sd
            flechaAbajo();
            cancelMenu(); //Para regresar al menu principal
            break;
        case 4:
            lcd.setCursor(1,0);
            lcd.print("Seleccione tiempo:");
            flechaArriba();
            lcd.setCursor(4,2);
            lcd.print("120 segundos");
            //act4();Para lectura sd
            cancelMenu(); //Para regresar al menu principal
            break;
  }
  
  }

void controlBoton()     //Permite el control del menu mediante botones                                  
{
   if(!digitalRead(BOT_ARRIBA)) flagArriba = 0x01;          //Bandera para boton abajo
   if(!digitalRead(BOT_ABAJO)) flagAbajo = 0x01;          //Bandera para boton abajo
   if(digitalRead(BOT_ARRIBA) && flagArriba)                //Boton abajo y bandera
   {  
    flagArriba = 0x00;                                 //Encera la bandera
      lcd.clear();                                     //Limpia display
      menuCont--;      
      if(menuCont < 1) menuCont = 2;//Decrementa menu
                          //Si menu<1 entonces menu=2
   } 
   if(digitalRead(BOT_ABAJO) && flagAbajo)                //Boton abajo y bandera
   {  
    flagAbajo = 0x00;                                 //Limpia flag
      lcd.clear();                                     //Limpia display
      menuCont++;      
      if(menuCont > 2) menuCont = 1;//Decrementa menu
                          //Si menu>2 entonces menu=1 para ir al inicio
   } 
}

void menuPrin()                                         //Mostra o menu atual
{
    switch(menuCont)                                        //Menu
    {
       case 1:                          
      lcd.setCursor(4,0);
      lcd.print("||||MENU|||");
      lcd.setCursor(0,1);
      lcd.print(">Seleccionar piscina");
      lcd.setCursor(1,2);
      lcd.print("Configurar tiempo");      
      if(!digitalRead(BOT_OK)) flagOk= 0x01;  //Configuracion de bandera para el bucle funcione
      if(digitalRead(BOT_OK) && flagOk){      //Para ingresar al bucle cuando se presiona ok
      lcd.clear();
      if(!digitalRead(BOT_CANCELAR)) {flagCancelar= 0x01;}
      while(flagOk){  //Bucle para mantenerse en submenu configTiempo
        piscId();     //Funcion de piscina ID   
      }}
                                                        
      break;                                    
       
       case 2:
      lcd.setCursor(4,0);
      lcd.print("||||MENU|||");
      lcd.setCursor(1,1);
      lcd.print("Seleccionar piscina");
      lcd.setCursor(0,2);
      lcd.print(">Configurar tiempo");
      if(!digitalRead(BOT_OK)) flagOk= 0x01; //Configuracion de bandera para el bucle funcione
      if(digitalRead(BOT_OK) && flagOk){     //Para ingresar al bucle cuando se presiona ok
      lcd.clear();
      while(flagOk){      //Bucle para mantenerse en submenu configTiempo
        configTiempo();   //Funcion configTiempo de arranque
      }}                             
      break;                                   
    }
}