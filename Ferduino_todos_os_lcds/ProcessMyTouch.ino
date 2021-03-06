//-------------------------------------------Touch screen----------------------------
void processMyTouch()
{
  myTouch.read();
  x=myTouch.getX();
  y=myTouch.getY();
  if ((x>=iniC[0]* fator_escala_x) && (x<=iniC[2]* fator_escala_x) && (y>=iniC[1]* fator_escala_y) && (y<=iniC[3]) && (dispScreen!=0) && (LEDtestTick == false))  // volta ao inicio
  {
    waitForIt(iniC[0], iniC[1], iniC[2], iniC[3]);
    if(dispScreen == 5)
    {
     ReadFromEEPROM();
    }
    periodo_selecionado = false;
    dispScreen=0;
    clearScreen();
    mainScreen(true);   
  } 
  else
  {
    switch (dispScreen) 
    {
    case 0:                       //Tela de inico
      dispScreen=30;
      clearScreen();
      solicitar_senha();
      break;
    case 1:     //------------------------------------Tela de menu-------------------------------------------------
      if ((x >= tanD[0] * fator_escala_x) && (x<=tanD[2]* fator_escala_x))               //first column
      {
        if ((y >= tanD[1] * fator_escala_y) && (y<=tanD[3] * fator_escala_y))             //press clock
        {
          waitForIt(tanD[0], tanD[1], tanD[2], tanD[3]);
          dispScreen=2;
          clearScreen();
          setClock();
        }

        if ((y>=tesT[1]* fator_escala_y) && (y<=tesT[3] * fator_escala_y))              // Menu configurar leds
        {
          waitForIt(tesT[0], tesT[1], tesT[2], tesT[3]);
          dispScreen=40;
          clearScreen();
          config_leds();
        }  
        if ((y>=temC[1]* fator_escala_y) && (y<=temC[3] * fator_escala_y))               //controle de parametros
        {
          waitForIt(temC[0], temC[1], temC[2], temC[3]);
          dispScreen=14;
          clearScreen();
          parametroScreen();
        }
        if ((y>=graF[1]* fator_escala_y) && (y<=graF[3] * fator_escala_y))           // seleciona a funcao grafico
        {
          waitForIt(graF[0], graF[1], graF[2], graF[3]);
          dispScreen=9;
          clearScreen();
          graficoScreen();
        } 
      }
      if ((x>=ledW[0]* fator_escala_x) && (x<=ledW[2]* fator_escala_x))                 //second column
      {
        if  ((y>=ledW[1]* fator_escala_y) && (y<=ledW[3] * fator_escala_y))           //Timers
        {
          waitForIt(ledW[0], ledW[1], ledW[2], ledW[3]);
          dispScreen=38;
          clearScreen();
          TimerScreen();
        } 
        if  ((y>=tpaA[1]* fator_escala_y) && (y<=tpaA[3] * fator_escala_y))           // seleciona a funcao "TPA automatica"
        {
          waitForIt(tpaA[0], tpaA[1], tpaA[2], tpaA[3]);
          dispScreen=7;
          clearScreen();
          tpaScreen(true);
        }      
        if  ((y>=dosA[1]* fator_escala_y) && (y<=dosA[3] * fator_escala_y))           // seleciona a funcao "Bomba dosadora"
        {
          waitForIt(dosA[0], dosA[1], dosA[2], dosA[3]);
          dispScreen=8;
          clearScreen();
          menu_dosadoras();
        } 
        if ((y>=wavM[1]* fator_escala_y) && (y<=wavM[3] * fator_escala_y))           // seleciona a funcao "wavemaker"
        {
          waitForIt(wavM[0], wavM[1], wavM[2], wavM[3]);
          dispScreen=10;
          clearScreen();
          waveScreen(true);
        } 
      }
      if ((y>=menU[1]* fator_escala_y) && (y<=menU[3]) && (x>=menU[0]* fator_escala_x) && (x<=menU[2]* fator_escala_x))
      {
        waitForIt(menU[0], menU[1], menU[2], menU[3]); // Vai para o menu 2
        dispScreen=37;
        clearScreen();
        menuScreen_2();
      }
      break;

    case 2:    // -------------------------------------Tela configuracao data e hora---------------------

      if ((y>=houU[1]* fator_escala_y) && (y<=houU[3] * fator_escala_y)) // Buttons: Time UP
      {
        if((x>=houU[0]* fator_escala_x) && (x<=houU[2]* fator_escala_x))
        {
          waitForIt(houU[0], houU[1], houU[2], houU[3]);

          t_temp.hour = (t_temp.hour+1) %24;
          if (t_temp.hour<10)
          {
            myGLCD.printNumI(0, 70, 48);
            myGLCD.printNumI(t_temp.hour, 86, 48);
          }
          else
          {
            myGLCD.printNumI(t_temp.hour, 70, 48);
          }
          if (ct==false)
          {
            ct=true;
            myGLCD.setColor(255, 0, 0);
            myGLCD.setFont(SmallFont);
            myGLCD.print(tabela_textos[163], 10, 200); // tabela_textos[163]
            myGLCD.setColor(255, 255, 255);
            myGLCD.setFont(BigFont);
          }      
        }
        else if ((x>=minU[0]* fator_escala_x) && (x<=minU[2]* fator_escala_x))
        {
          waitForIt(minU[0], minU[1], minU[2], minU[3]);
          t_temp.min = (t_temp.min +1) %60;
          if (t_temp.min<10)
          {
            myGLCD.printNumI(0, 160, 48);
            myGLCD.printNumI(t_temp.min, 176, 48);
          }
          else
          {
            myGLCD.printNumI(t_temp.min, 160, 48);
          }   
          if (ct==false)
          {
            ct=true;
            myGLCD.setColor(255, 0, 0);
            myGLCD.setFont(SmallFont);
            myGLCD.print(tabela_textos[163], 10, 200);
            myGLCD.setColor(255, 255, 255);
            myGLCD.setFont(BigFont);
          }
        }
        else if ((x>=segC[0]* fator_escala_x) && (x<=segC[2]* fator_escala_x))
        {
          waitForIt(segC[0], segC[1], segC[2], segC[3]);
          t_temp.sec = (t_temp.sec +1) %60;
          if (t_temp.sec==60)
            t_temp.sec=0;
          if (t_temp.sec<10)
          {
            myGLCD.printNumI(0, 250, 48);
            myGLCD.printNumI(t_temp.sec, 266, 48);
          }
          else
          {
            myGLCD.printNumI(t_temp.sec, 250, 48);
          } 
          if (ct==false)
          {
            ct=true;
            myGLCD.setColor(255, 0, 0);
            myGLCD.setFont(SmallFont);
            myGLCD.print(tabela_textos[163], 10, 200);
            myGLCD.setColor(255, 255, 255);
            myGLCD.setFont(BigFont);
          }      
        }
      }
      else if ((y>=houD[1]* fator_escala_y) && (y<=houD[3] * fator_escala_y)) // Buttons: Time DOWN
      {
        if ((x>=houD[0]* fator_escala_x) && (x<=houD[2]* fator_escala_x))
        {
          waitForIt(houD[0], houD[1], houD[2], houD[3]);
          t_temp.hour =(t_temp.hour + 23)% 24;
          if (t_temp.hour<10)
          {
            myGLCD.printNumI(0, 70, 48);
            myGLCD.printNumI(t_temp.hour, 86, 48);
          }
          else
          {
            myGLCD.printNumI(t_temp.hour, 70, 48);
          }            
          if (ct==false)
          {
            ct=true;
            myGLCD.setColor(255, 0, 0);
            myGLCD.setFont(SmallFont);
            myGLCD.print(tabela_textos[163], 10, 200);
            myGLCD.setColor(255, 255, 255);
            myGLCD.setFont(BigFont);
          }
        }
        else if ((x>=minD[0]* fator_escala_x) && (x<=minD[2]* fator_escala_x))
        {
          waitForIt(minD[0], minD[1], minD[2], minD[3]);
          t_temp.min =(t_temp.min +59) %60;
          if (t_temp.min<10)
          {
            myGLCD.printNumI(0, 160, 48);
            myGLCD.printNumI(t_temp.min, 176, 48);
          }
          else
          {
            myGLCD.printNumI(t_temp.min, 160, 48);
          } 
          if (ct==false)
          {
            ct=true;
            myGLCD.setColor(255, 0, 0);
            myGLCD.setFont(SmallFont);
            myGLCD.print(tabela_textos[163], 10, 200);
            myGLCD.setColor(255, 255, 255);
            myGLCD.setFont(BigFont);
          }
        }
        else if ((x>=segB[0]* fator_escala_x) && (x<=segB[2]* fator_escala_x))
        {
          waitForIt(segB[0], segB[1], segB[2], segB[3]); 
          t_temp.sec = (t_temp.sec +59) %60;
          if (t_temp.sec<10)
          {
            myGLCD.printNumI(0, 250, 48);
            myGLCD.printNumI(t_temp.sec, 266, 48);
          }
          else
          {
            myGLCD.printNumI(t_temp.sec, 250, 48);
          }
          if (ct==false)
          {
            ct=true;
            myGLCD.setColor(255, 0, 0);
            myGLCD.setFont(SmallFont);
            myGLCD.print(tabela_textos[163], 10, 200);
            myGLCD.setColor(255, 255, 255);
            myGLCD.setFont(BigFont);
          }
        }
      }

      if ((y>=dayU[1]* fator_escala_y) && (y<=dayU[3] * fator_escala_y)) // Buttons: Date UP
      {
        if ((x>=dayU[0]* fator_escala_x) && (x<=dayU[2]* fator_escala_x))
        {
          waitForIt(dayU[0], dayU[1], dayU[2], dayU[3]);
          t_temp.date+=1;
          t_temp.date=validateDate(t_temp.date, t_temp.mon, t_temp.year);
          if (t_temp.date<10)
          {
            myGLCD.printNumI(0, 70, 132);
            myGLCD.printNumI(t_temp.date, 86, 132);
          }
          else
          {
            myGLCD.printNumI(t_temp.date, 70, 132);
          }
          if (ct==false)
          {
            ct=true;
            myGLCD.setColor(255, 0, 0);
            myGLCD.setFont(SmallFont);
            myGLCD.print(tabela_textos[163], 10, 200);
            myGLCD.setColor(255, 255, 255);
            myGLCD.setFont(BigFont);
          }
        }
        else if ((x>=monU[0]* fator_escala_x) && (x<=monU[2]* fator_escala_x))
        {
          waitForIt(monU[0], monU[1], monU[2], monU[3]);
          t_temp.mon =(t_temp.mon + 1) %13;
          if (t_temp.mon ==0)
          {
            t_temp.mon = 1;
          }
          if (t_temp.mon<10)
          {
            myGLCD.printNumI(0, 160, 132);
            myGLCD.printNumI(t_temp.mon, 176, 132);
          }
          else
          {
            myGLCD.printNumI(t_temp.mon, 160, 132);
          }

          t_temp.date=validateDateForMonth(t_temp.date, t_temp.mon, t_temp.year);
          if (ct==false)
          {
            ct=true;
            myGLCD.setColor(255, 0, 0);
            myGLCD.setFont(SmallFont);
            myGLCD.print(tabela_textos[163], 10, 200);
            myGLCD.setColor(255, 255, 255);
            myGLCD.setFont(BigFont);
          }
        }
        else if ((x>=yeaU[0]* fator_escala_x) && (x<=yeaU[2]* fator_escala_x))   
        {
          waitForIt(yeaU[0], yeaU[1], yeaU[2], yeaU[3]);
          t_temp.year+=1;
          if (t_temp.year==2100)
            t_temp.year=2000;
          myGLCD.printNumI(t_temp.year, 230, 132);

          t_temp.date=validateDateForMonth(t_temp.date, t_temp.mon, t_temp.year);
          if (ct==false)
          {
            ct=true;
            myGLCD.setColor(255, 0, 0);
            myGLCD.setFont(SmallFont);
            myGLCD.print(tabela_textos[163], 10, 200);
            myGLCD.setColor(255, 255, 255);
            myGLCD.setFont(BigFont);
          }
        }
        t_temp.dow=calcDOW(t_temp.date, t_temp.mon, t_temp.year);
      }
      else if ((y>=dayD[1]* fator_escala_y) && (y<=dayD[3] * fator_escala_y))  // Buttons: Date DOWN
      {
        if ((x>=dayD[0]* fator_escala_x) && (x<=dayD[2]* fator_escala_x))
        {
          waitForIt(dayD[0], dayD[1], dayD[2], dayD[3]);
          t_temp.date-=1;
          t_temp.date=validateDate(t_temp.date, t_temp.mon, t_temp.year);
          if (t_temp.date<10)
          {
            myGLCD.printNumI(0, 70, 132);
            myGLCD.printNumI(t_temp.date, 86, 132);
          }
          else
          {
            myGLCD.printNumI(t_temp.date, 70, 132);
          }
          if (ct==false)
          {
            ct=true;
            myGLCD.setColor(255, 0, 0);
            myGLCD.setFont(SmallFont);
            myGLCD.print(tabela_textos[163], 10, 200);
            myGLCD.setColor(255, 255, 255);
            myGLCD.setFont(BigFont);
          }
        }
        else if ((x>=monD[0]* fator_escala_x) && (x<=monD[2]* fator_escala_x))   
        {
          waitForIt(monD[0], monD[1], monD[2], monD[3]);
          t_temp.mon =(t_temp.mon +12) %13;
          if (t_temp.mon ==0)
          {
            t_temp.mon = 12;
          }
          if (t_temp.mon<10)
          {
            myGLCD.printNumI(0, 160, 132);
            myGLCD.printNumI(t_temp.mon, 176, 132);
          }
          else
          {
            myGLCD.printNumI(t_temp.mon, 160, 132);
          }
          t_temp.date=validateDateForMonth(t_temp.date, t_temp.mon, t_temp.year);
          if (ct==false)
          {
            ct=true;
            myGLCD.setColor(255, 0, 0);
            myGLCD.setFont(SmallFont);
            myGLCD.print(tabela_textos[163], 10, 200);
            myGLCD.setColor(255, 255, 255);
            myGLCD.setFont(BigFont);
          }
        }

        else if ((x>=yeaD[0]* fator_escala_x) && (x<=yeaD[2]* fator_escala_x))
        {
          waitForIt(yeaD[0], yeaD[1], yeaD[2], yeaD[3]);
          t_temp.year = (t_temp.year +2099) %2100;

          myGLCD.printNumI(t_temp.year, 230, 132);
          t_temp.date=validateDateForMonth(t_temp.date, t_temp.mon, t_temp.year);
          if (ct==false)
          {
            ct=true;
            myGLCD.setColor(255, 0, 0);
            myGLCD.setFont(SmallFont);
            myGLCD.print(tabela_textos[163], 10, 200);
            myGLCD.setColor(255, 255, 255);
            myGLCD.setFont(BigFont);
          }          
        }
        t_temp.dow=calcDOW(t_temp.date, t_temp.mon, t_temp.year);
      }
      if ((y>=prOK[1]* fator_escala_y) && (y<=prOK[3]) && (x>=prOK[0]* fator_escala_x) && (x<=prOK[2]* fator_escala_x))
      {
        waitForIt(prOK[0], prOK[1], prOK[2], prOK[3]); //funcao salvar
        rtc.halt(true);
        rtc.setTime(t_temp.hour, t_temp.min, t_temp.sec); 
        rtc.setDate(t_temp.date, t_temp.mon, t_temp.year);
        rtc.setDOW(t_temp.dow);
        rtc.halt(false);
        dispScreen=0;
        clearScreen();
        mainScreen(true);
      }
      if ((y>=iniC[1]* fator_escala_y) && (y<=iniC[3]) && (x>=iniC[0]* fator_escala_x) && (x<=iniC[2]* fator_escala_x))
      {
        waitForIt(iniC[0], iniC[1], iniC[2], iniC[3]); //volta ao inicio
        dispScreen=0;
        clearScreen();
        mainScreen(true);
      }
      if ((y>=menU[1]* fator_escala_y) && (y<=menU[3]) && (x>=menU[0]* fator_escala_x) && (x<=menU[2]* fator_escala_x))
      {
        waitForIt(menU[0], menU[1], menU[2], menU[3]); //volta ao menu
        dispScreen=1;
        clearScreen();
        menuScreen();
      }     
      break;
    case 3:                    // -------------------Tela testar led------------------------------------------
      if ((x>=stsT[0]* fator_escala_x) && (x<=stsT[2]* fator_escala_x) && (y>=stsT[1]* fator_escala_y) && (y<=stsT[3] * fator_escala_y))     //press start/stop test
      {
        waitForIt(stsT[0], stsT[1], stsT[2], stsT[3]); 

        if (LEDtestTick == true) 
        {
          LEDtestTick = false;
          testScreen(true);
        }
        else {
          LEDtestTick = true; 
          myGLCD.setColor(0, 0, 0);
          myGLCD.fillRect (319, 1, 399, 239);   //Limpar botões iniciar e menu.       
          testScreen(); 
        }
      } 
      else
      {
        if ((x>=tenM[0]* fator_escala_x) && (x<=tenM[2]* fator_escala_x) && (y>=tenM[1]* fator_escala_y) && (y<=tenM[3] * fator_escala_y))      //press -10s
        {
          waitForIt(tenM[0], tenM[1], tenM[2], tenM[3]);
          min_cnt -= 10;
          if (min_cnt<0) {
            min_cnt= 0; 
          }

        }
        if ((x>=tenP[0]* fator_escala_x) && (x<=tenP[2]* fator_escala_x) && (y>=tenP[1]* fator_escala_y) && (y<=tenP[2]* fator_escala_x))    //press +10s
        {
          waitForIt(tenP[0], tenP[1], tenP[2], tenP[3]);
          min_cnt += 10;
          if (min_cnt>1440) {
            min_cnt = 1440; 
          }
        }
        if ((x>=menU[0]* fator_escala_x) && (x<=menU[2]* fator_escala_x) && (y>=menU[1]* fator_escala_y) && (y<=menU[3]) && (LEDtestTick == false))           // volta ao menu
        {
          waitForIt(menU[0], menU[1], menU[2], menU[3]);
          dispScreen=1;
          clearScreen();
          menuScreen(); 
        }
        if ((x>=volT[0]* fator_escala_x) && (x<=volT[2]* fator_escala_x) && (y>=volT[1]* fator_escala_y) && (y<=volT[3])&& (LEDtestTick == false))           // volta a tela configurar leds
        {
          waitForIt(volT[0], volT[1], volT[2], volT[3]);
          dispScreen=40;
          clearScreen();
          config_leds(); 
        }

      }    
      break;
    case 4:             //---------------------------------------Tela controle de temperatura----------------------------------
      if ((x>=prOK[0]* fator_escala_x) && (x<=prOK[2]* fator_escala_x) && (y>=prOK[1]* fator_escala_y) && (y<=prOK[3] * fator_escala_y))       //Funcao salvar
      {
        waitForIt(prOK[0], prOK[1], prOK[2], prOK[3]);
        setTempC = temp2beS;
        offTempC = temp2beO;
        alarmTempC = temp2beA;
        dispScreen=0;
        SaveTempToEEPROM();
        clearScreen();
        mainScreen(true);
      } 
      else
      {
        if ((x>=temM[0]* fator_escala_x) && (x<=temM[2]* fator_escala_x))                         // Primeira coluna
        {
          if ((y>=temM[1]* fator_escala_y) && (y<=temM[3] * fator_escala_y))                      //press temp minus
          {
            waitForIt(temM[0], temM[1], temM[2], temM[3]);
            temp2beS -= 0.1;
            if (temp2beS<10) {
              temp2beS = 10; 
            }
            tempScreen();
          }
          if ((y>=offM[1]* fator_escala_y) && (y<=offM[3] * fator_escala_y))                       //press offset minus
          {
            waitForIt(offM[0], offM[1], offM[2], offM[3]);
            temp2beO -= 0.1;
            if (temp2beO <= 0.1) {
              temp2beO = 0.0; 
            }
            tempScreen();
          }          
          if ((y>=almM[1]* fator_escala_y) && (y<=almM[3] * fator_escala_y))                        //press alarm minus
          {
            waitForIt(almM[0], almM[1], almM[2], almM[3]);
            temp2beA -= 0.1;
            if (temp2beA < 0.1) {
              temp2beA = 0.0;  
            }
            tempScreen();
          }
        }
        if ((x>=temP[0]* fator_escala_x) && (x<=temP[2]* fator_escala_x))                             //Segunda coluna
        {
          if ((y>=temP[1]* fator_escala_y) && (y<=temP[3] * fator_escala_y))                      //press temp plus
          {
            waitForIt(temP[0], temP[1], temP[2], temP[3]);
            temp2beS += 0.1;
            if (temp2beS >= 40) {
              temp2beS = 40; 
            }
            tempScreen();
          }
          if ((y>=offP[1]* fator_escala_y) && (y<=offP[3] * fator_escala_y))                           //press offset plus
          {
            waitForIt(offP[0], offP[1], offP[2], offP[3]);
            temp2beO += 0.1;
            if (temp2beO >= 10) {
              temp2beO = 9.9; 
            }
            tempScreen();
          }
          if ((y>=almP[1]* fator_escala_y) && (y<=almP[3] * fator_escala_y))                           //press alarm plus
          {
            waitForIt(almP[0], almP[1], almP[2], almP[3]);
            temp2beA += 0.1;
            if (temp2beA >= 10) {
              temp2beA = 9.9;  
            }
            tempScreen();
          }
        }
        if ((x>=menU[0]* fator_escala_x) && (x<=menU[2]* fator_escala_x) && (y>=menU[1]* fator_escala_y) && (y<=menU[3] * fator_escala_y))           // volta ao menu
        {
          waitForIt(menU[0], menU[1], menU[2], menU[3]);
          dispScreen=14;
          clearScreen();
          parametroScreen();
        } 

      }
      break;
    case 5:         // --------------------------------Tela alterar valores led------------------------------------------------------------
      if ((x>=menU[0]* fator_escala_x) && (x<=menU[2]* fator_escala_x) && (y>=menU[1]* fator_escala_y) && (y<=menU[3] * fator_escala_y))           // volta ao menu
      {
        waitForIt(menU[0], menU[1], menU[2], menU[3]);
        dispScreen=1;
        clearScreen();
        menuScreen();
        ReadFromEEPROM();
      }
      if ((x>=volT[0]* fator_escala_x) && (x<=volT[2]* fator_escala_x) && (y>=volT[1]* fator_escala_y) && (y<=volT[3] * fator_escala_y))           // volta a tela configurar leds
      {
        waitForIt(volT[0], volT[1], volT[2], volT[3]);
        dispScreen=40;
        clearScreen();
        config_leds();
        ReadFromEEPROM();
      } 
      if ((x>=leWB[0]* fator_escala_x) && (x<=leWB[2]* fator_escala_x) && (y>=leWB[1]* fator_escala_y) && (y<=leWB[3] * fator_escala_y))       // Alterna entre a tabela do azuis e brancos
      {
        waitForIt(leWB[0], leWB[1], leWB[2], leWB[3]);
        if (WorB == true)
        {
          WorB = false;
        }
        else
        {
          WorB = true;
        }
        clearScreen();
        ledSetScreen();
      } 
      else if ((x>=leST[0]* fator_escala_x) && (x<=leST[2]* fator_escala_x) && (y>=leST[1]* fator_escala_y) && (y<=leST[3] * fator_escala_y))       // Alterar valores dos leds
      {
        waitForIt(leST[0], leST[1], leST[2], leST[3]);
        dispScreen=6;
        clearScreen();
        ledChangeScreen(true);
      }
      else if ((x>=savE[0]* fator_escala_x) && (x<=savE[2]* fator_escala_x) && (y>=savE[1]* fator_escala_y) && (y<=savE[3] * fator_escala_y))      // Salva os valores na EEPROM
      {
        waitForIt(savE[0], savE[1], savE[2], savE[3]);
        SaveLEDToEEPROM();
        dispScreen=0;
        clearScreen();
        mainScreen(true);
      }
      break;
    case 6:             //---------------------------------- Tela alterar potencia dos leds ---------------------
      if ((x>=salV[0]* fator_escala_x) && (x<=salV[2]* fator_escala_x) && (y>=salV[1]* fator_escala_y) && (y<=salV[3] * fator_escala_y))       // Salvar tabela temporária
      {
        waitForIt(salV[0], salV[1], salV[2], salV[3]);
        dispScreen=5;
        if (WorB == true) 
        {
          for (int i; i<96; i++) 
          {
            wled[i]=tled[i]; 
          }
        } 
        else 
        {
          for (int i; i<96; i++) 
          {
            bled[i]=tled[i]; 
          }
        }
        clearScreen();
        ledSetScreen();
        periodo_selecionado = false;
      }
      else if ((y>=15 * fator_escala_y) && (y<=40 * fator_escala_y))                                    // Seleção de período
      {
        if ((x>=4 * fator_escala_x) && (x<=316 * fator_escala_x))
        {
          periodo_selecionado = true;
          ledChangeScreen();
          int oldLCT = LedChangTime;
          LedChangTime = map(x, 3 * fator_escala_x, 320 * fator_escala_x, 0, 12);                

          if (oldLCT != LedChangTime)                        // Realçar período tocado
          {
            myGLCD.setColor(0, 0, 0);
            myGLCD.fillRect((oldLCT*26)+5, 21, (oldLCT*26)+29, 45);
            setFont(SMALL, 0, 255, 255, 0, 0, 0);
            myGLCD.printNumI((oldLCT*2), (oldLCT*26)+10, 22);
            myGLCD.printNumI(((oldLCT*2)+2), (oldLCT*26)+10, 33);
            myGLCD.setColor(255, 0, 0);
            myGLCD.fillRect((LedChangTime*26)+5, 21, (LedChangTime*26)+29, 45);
            setFont(SMALL, 255, 255, 255, 255, 0, 0);
            myGLCD.printNumI((LedChangTime*2), (LedChangTime*26)+10, 22);
            myGLCD.printNumI(((LedChangTime*2)+2), (LedChangTime*26)+10, 33);

            for (int i=0; i<8; i++)                          // Imprime valores do período.
            {
              int k=(LedChangTime*8)+i;
              setFont(SMALL, 255, 255, 255, 0, 0, 0);
              myGLCD.print("   ", (i*38)+12, 105);
              myGLCD.printNumI( tled[k], (i*38)+12, 105);
            }
          }
        }
      } 
      else if ((y>=70 * fator_escala_y) && (y<=95 * fator_escala_y) && (periodo_selecionado == true))       // Botão +
      {
        for (int i=0; i<8; i++) {                
          if ((x>=(i*38* fator_escala_x)+10) && (x<=(i*38* fator_escala_x)+35)) {
            int k= (LedChangTime*8)+i;
            tled[k]++;
            if (tled[k]>255) {
              tled[k]=255; 
            }
            myGLCD.printNumI( tled[k], (i*38)+12, 105);
          }
        }
      }
      else if ((y>=125 * fator_escala_y) && (y<=150 * fator_escala_y)  && (periodo_selecionado == true))     // Botão -
      {
        for (int i=0; i<8; i++) {                
          if ((x>=(i*38* fator_escala_x)+10) && (x<=(i*38 * fator_escala_x)+35)) {
            int k= (LedChangTime*8)+i;
            tled[k]--;
            if (tled[k]<0) {
              tled[k]=0; 
            }
            myGLCD.print("  ", (i*38)+20, 105);
            myGLCD.printNumI( tled[k], (i*38)+12, 105);
          }
        }  
      }
      if ((x>=menU[0]* fator_escala_x) && (x<=menU[2]* fator_escala_x) && (y>=menU[1]* fator_escala_y) && (y<=menU[3] * fator_escala_y))           // Volta ao menu
      {
        waitForIt(menU[0], menU[1], menU[2], menU[3]);
        dispScreen=1;
        clearScreen();
        menuScreen();
        periodo_selecionado = false; 
      }
      if ((x>=volT[0]* fator_escala_x) && (x<=volT[2]* fator_escala_x) && (y>=volT[1]* fator_escala_y) && (y<=volT[3] * fator_escala_y))           // Volta a tela configurar leds
      {
        waitForIt(volT[0], volT[1], volT[2], volT[3]);
        dispScreen=5;
        clearScreen();
        ledSetScreen();
        periodo_selecionado = false; 
      }
      break;
    case 7: //--------------------------------------------- configurar tpa autom.-----------------------------------
      if ((y >= houU[1]* fator_escala_y) && (y <= houU[3] * fator_escala_y)) // Buttons: Time UP
      {
        if ((x >= houU[0]* fator_escala_x) && (x <= houU[2]* fator_escala_x)) {
          waitForIt(houU[0], houU[1], houU[2], houU[3]);
          temp2hora = (temp2hora + 1) % 24;
          tpaScreen();
        } 
        if ((x >= minUT[0]* fator_escala_x) && (x <= minUT[2]* fator_escala_x)) {
          waitForIt(minUT[0], minUT[1], minUT[2], minUT[3]);
          temp2minuto = (temp2minuto + 1) % 60;
          tpaScreen();
        } 
        if ((x >= durC[0]* fator_escala_x) && (x <= durC[2]* fator_escala_x)) {
          waitForIt(durC[0], durC[1], durC[2], durC[3]); 
          temp2duracaomaximatpa = (temp2duracaomaximatpa + 1) % 60;
          tpaScreen();
        }
      } 
      if ((y >= houD[1]* fator_escala_y) && (y <= houD[3] * fator_escala_y)) // Buttons: Time DOWN
      {
        if ((x >= houD[0]* fator_escala_x) && (x <= houD[2]* fator_escala_x)) {
          waitForIt(houD[0], houD[1], houD[2], houD[3]);
          temp2hora = (temp2hora + 23) % 24;
          tpaScreen();
        } 
        if ((x >= minDT[0]* fator_escala_x) && (x <= minDT[2]* fator_escala_x)) {
          waitForIt(minDT[0], minDT[1], minDT[2], minDT[3]);
          temp2minuto = (temp2minuto + 59) % 60;
          tpaScreen();
        } 
        if ((x >= durB[0]* fator_escala_x) && (x <= durB[2]* fator_escala_x)) {
          waitForIt(durB[0], durB[1], durB[2], durB[3]);
          temp2duracaomaximatpa = (temp2duracaomaximatpa + 59) % 60;
          tpaScreen();          
        }
      }
      if ((y >= prOK[1]* fator_escala_y) && (y <= prOK[3]) && (x >= prOK[0]* fator_escala_x) && (x <= prOK[2]* fator_escala_x)) {
        waitForIt(prOK[0], prOK[1], prOK[2], prOK[3]); //funcao salvar
        hora = temp2hora;
        minuto = temp2minuto;
        duracaomaximatpa = temp2duracaomaximatpa;
        segunda = temp2segunda;
        terca = temp2terca;
        quarta = temp2quarta;
        quinta = temp2quinta;
        sexta = temp2sexta;
        sabado = temp2sabado;
        domingo =temp2domingo;
        SalvartpaEEPROM();
        dispScreen = 0;
        clearScreen();
        mainScreen(true);
      }
      if ((y >= menU[1]* fator_escala_y) && (y <= menU[3]) && (x >= menU[0]* fator_escala_x) && (x <= menU[2]* fator_escala_x)) {
        waitForIt(menU[0], menU[1], menU[2], menU[3]); //volta ao menu
        dispScreen = 1;
        clearScreen();
        menuScreen();
      }
      if ((x >= segU[0]* fator_escala_x) && (x <= segU[2]* fator_escala_x) && (y >= segU[1]* fator_escala_y) && (y <= segU[3] * fator_escala_y)) {
        if (temp2segunda == 1) {
          temp2segunda = 0;
          tpaScreen();
        } 
        else {
          temp2segunda = 1;
          tpaScreen();
        }
      }
      if ((x >= terC[0]* fator_escala_x) && (x <= terC[2]* fator_escala_x) && (y >= terC[1]* fator_escala_y) && (y <= terC[3] * fator_escala_y)) {
        if (temp2terca == 2) {
          temp2terca = 0;
          tpaScreen();
        } 
        else {
          temp2terca = 2;
          tpaScreen();
        }
      }
      if ((x >= quaR[0]* fator_escala_x) && (x <= quaR[2]* fator_escala_x) && (y >= quaR[1]* fator_escala_y) && (y <= quaR[3] * fator_escala_y)) {

        if (temp2quarta == 3) {
          temp2quarta = 0;
          tpaScreen();
        } 
        else {
          temp2quarta = 3;
          tpaScreen();
        }
      }
      if ((x >= quiN[0]* fator_escala_x) && (x <= quiN[2]* fator_escala_x) && (y >= quiN[1]* fator_escala_y) && (y <= quiN[3] * fator_escala_y)) {

        if (temp2quinta == 4) {
          temp2quinta = 0;
          tpaScreen();
        } 
        else {
          temp2quinta = 4;
          tpaScreen();
        }
      }
      if ((x >= sexT[0]* fator_escala_x) && (x <= sexT[2]* fator_escala_x) && (y >= sexT[1]* fator_escala_y) && (y <= sexT[3] * fator_escala_y)) {
        if (temp2sexta == 5) {
          temp2sexta = 0;
          tpaScreen();
        } 
        else {
          temp2sexta = 5;
          tpaScreen();
        }
      }
      if ((x >= sabA[0]* fator_escala_x) && (x <= sabA[2]* fator_escala_x) && (y >= sabA[1]* fator_escala_y) && (y <= sabA[3] * fator_escala_y)) {
        if (temp2sabado == 6) {
          temp2sabado = 0;
          tpaScreen();
        } 
        else {
          temp2sabado = 6;
          tpaScreen();
        }
      }
      if ((x >= domI[0]* fator_escala_x) && (x <= domI[2]* fator_escala_x) && (y >= domI[1]* fator_escala_y) && (y <= domI[3] * fator_escala_y)) {
        if (temp2domingo == 7) {
          temp2domingo = 0;
          tpaScreen();
        } 
        else {
          temp2domingo = 7;
          tpaScreen();
        }
      }
      if ((x >= proX[0]* fator_escala_x) && (x <= proX[2]* fator_escala_x) && (y >= proX[1]* fator_escala_y) && (y <= proX[3] * fator_escala_y)) 
      {
        if (falha_tpa == true)
        {
          falha_tpa = false;
          tpa_em_andamento = false;
          tpaScreen();
        }
        else
        {
          falha_tpa = true;
          tpaScreen();
        }
      }

      break;
    case 8: //--------------------------------------------- Escolher dosadora -----------------------------------

      if ((x>=manU[0]* fator_escala_x) && (x<=manU[2]* fator_escala_x) && (y>=manU[1]* fator_escala_y) && (y<=manU[3] * fator_escala_y))
      {
        waitForIt(manU[0], manU[1], manU[2], manU[3]);
        modo_manual = true;
        modo_automatico = false;
        modo_personalizado = false;
        modo_calibrar = false;
        dispScreen = 21;
        clearScreen();
        selecionar_dosadora();
        setFont(SMALL, 255, 255, 255, 0, 0, 0);
        myGLCD.print(tabela_textos[164], 15, 220); // "MODO MANUAL SELECIONADO"
      }
      if ((x>=autO[0]* fator_escala_x) && (x<=autO[2]* fator_escala_x) && (y>=autO[1]* fator_escala_y) && (y<=autO[3] * fator_escala_y))
      {
        waitForIt(autO[0], autO[1], autO[2], autO[3]);
        modo_manual = false;
        modo_automatico = true;
        modo_personalizado = false;
        modo_calibrar = false;
        dispScreen = 21;
        clearScreen();
        selecionar_dosadora();
        setFont(SMALL, 255, 255, 255, 0, 0, 0);
        myGLCD.print(tabela_textos[165], 15, 220);      
      } 
      if ((x>=perS[0]* fator_escala_x) && (x<=perS[2]* fator_escala_x) && (y>=perS[1]* fator_escala_y) && (y<=perS[3] * fator_escala_y))
      {
        waitForIt(perS[0], perS[1], perS[2], perS[3]);
        modo_manual = false;
        modo_automatico = false;
        modo_personalizado = true;
        modo_calibrar = false;
        dispScreen = 21;
        clearScreen();
        selecionar_dosadora();
        setFont(SMALL, 255, 255, 255, 0, 0, 0);
        myGLCD.print(tabela_textos[171], 15, 220);      
      }
      if ((x>=caliB[0]* fator_escala_x) && (x<=caliB[2]* fator_escala_x) && (y>=caliB[1]* fator_escala_y) && (y<=caliB[3] * fator_escala_y))
      {
        waitForIt(caliB[0], caliB[1], caliB[2], caliB[3]);
        modo_manual = false;
        modo_automatico = false;
        modo_personalizado = false;
        modo_calibrar = true;
        dispScreen=21;
        clearScreen();
        selecionar_dosadora();
        setFont(SMALL, 255, 255, 255, 0, 0, 0);
        myGLCD.print(tabela_textos[172], 15, 220);      
      }    
      if ((x>=menU[0]* fator_escala_x) && (x<=menU[2]* fator_escala_x) && (y>=menU[1]* fator_escala_y) && (y<=menU[3] * fator_escala_y))           /// volta ao menu
      {
        waitForIt(menU[0], menU[1], menU[2], menU[3]);
        dispScreen=1;
        clearScreen();
        menuScreen();
        modo_manual = false;
        modo_automatico = false;
        modo_personalizado = false;
        modo_calibrar = false; 
      }          
      if ((x>=reV[0]* fator_escala_x) && (x<=reV[2]* fator_escala_x) && (y>=reV[1]* fator_escala_y) && (y<=reV[3] * fator_escala_y))           /// volta ao menu
      {
        waitForIt(reV[0], reV[1], reV[2], reV[3]);
        dispScreen=32;
        clearScreen();
        rever_configuracao_dosadoras();
      }
      if ((x>=atiV[0]* fator_escala_x) && (x<=atiV[2]* fator_escala_x) && (y>=atiV[1]* fator_escala_y) && (y<=atiV[3] * fator_escala_y))
      {
        waitForIt(atiV[0], atiV[1], atiV[2], atiV[3]);
        dispScreen = 35;
        clearScreen();
        desativar_dosadoras(true);
      }
      break;    

    case 9: //  -----------------------------------------Tela escolher graficos-----------------------------------------
      if ((x>=orP[0]* fator_escala_x) && (x<=orP[2]* fator_escala_x) && (y>=orP[1]* fator_escala_y) && (y<=orP[3] * fator_escala_y))           
      {
        waitForIt(orP[0], orP[1], orP[2], orP[3]);
        dispScreen=12;
        clearScreen();
        orpScreen(); 
      } 
      if ((x>=phR[0]* fator_escala_x) && (x<=phR[2]* fator_escala_x) && (y>=phR[1]* fator_escala_y) && (y<=phR[3] * fator_escala_y))           
      {
        waitForIt(phR[0], phR[1], phR[2], phR[3]);
        dispScreen=13;
        clearScreen();
        PHRScreen(); 
      } 
      if ((x>=tempG[0]* fator_escala_x) && (x<=tempG[2]* fator_escala_x) && (y>=tempG[1]* fator_escala_y) && (y<=tempG[3] * fator_escala_y))           
      {
        waitForIt(tempG[0], tempG[1], tempG[2], tempG[3]);
        dispScreen=13;
        clearScreen();
        tempgScreen(); 
      }
      if ((x>=phA[0]* fator_escala_x) && (x<=phA[2]* fator_escala_x) && (y>=phA[1]* fator_escala_y) && (y<=phA[3] * fator_escala_y))           
      {
        waitForIt(phA[0], phA[1], phA[2], phA[3]);
        dispScreen=17;
        clearScreen();
        PHAScreen(); 
      } 
      if ((x>=denS[0]* fator_escala_x) && (x<=denS[2]* fator_escala_x) && (y>=denS[1]* fator_escala_y) && (y<=denS[3] * fator_escala_y))           
      {
        waitForIt(denS[0], denS[1], denS[2], denS[3]);
        dispScreen=19;
        clearScreen();
        densidadeScreen(); 
      }       

      if ((x>=menU[0]* fator_escala_x) && (x<=menU[2]* fator_escala_x) && (y>=menU[1]* fator_escala_y) && (y<=menU[3] * fator_escala_y))           /// volta ao menu
      {
        waitForIt(menU[0], menU[1], menU[2], menU[3]);
        dispScreen=1;
        clearScreen();
        menuScreen(); 
      }          
      break;

    case 10: //--------------------------------- Tela wavemaker ----------------------------
      if ((x>=menU[0]* fator_escala_x) && (x<=menU[2]* fator_escala_x) && (y>=menU[1]* fator_escala_y) && (y<=menU[3] * fator_escala_y))           // volta ao menu
      {
        waitForIt(menU[0], menU[1], menU[2], menU[3]);
        dispScreen = 1;
        clearScreen();
        menuScreen(); 
      }
      break;

    case 11:  //----------------------------- Tela grafico de temperatura ------------------------------
      if ((x>=menU[0]* fator_escala_x) && (x<=menU[2]* fator_escala_x) && (y>=menU[1]* fator_escala_y) && (y<=menU[3] * fator_escala_y))           /// volta ao menu
      {
        waitForIt(menU[0], menU[1], menU[2], menU[3]);
        dispScreen=1;
        clearScreen();
        menuScreen(); 
      }
      if ((x>=volT[0]* fator_escala_x) && (x<=volT[2]* fator_escala_x) && (y>=volT[1]* fator_escala_y) && (y<=volT[3] * fator_escala_y))           // volta a tela de graficos
      {
        waitForIt(volT[0], volT[1], volT[2], volT[3]);
        dispScreen=9;
        clearScreen();
        graficoScreen(); 
      }           
      break;

    case 12:  //--------------------------- Tela grafico de orp---------------------------------------
      if ((x>=menU[0]* fator_escala_x) && (x<=menU[2]* fator_escala_x) && (y>=menU[1]* fator_escala_y) && (y<=menU[3] * fator_escala_y))           /// volta ao menu
      {
        waitForIt(menU[0], menU[1], menU[2], menU[3]);
        dispScreen=1;
        clearScreen();
        menuScreen(); 
      }
      if ((x>=volT[0]* fator_escala_x) && (x<=volT[2]* fator_escala_x) && (y>=volT[1]* fator_escala_y) && (y<=volT[3] * fator_escala_y))           // volta a tela de graficos
      {
        waitForIt(volT[0], volT[1], volT[2], volT[3]);
        dispScreen=9;
        clearScreen();
        graficoScreen(); 
      }  
      break;           

    case 13:   //-----------------Tela grafico de ph do aquario----------------------------------
      if ((x>=menU[0]* fator_escala_x) && (x<=menU[2]* fator_escala_x) && (y>=menU[1]* fator_escala_y) && (y<=menU[3] * fator_escala_y))           // volta ao menu
      {
        waitForIt(menU[0], menU[1], menU[2], menU[3]);
        dispScreen=1;
        clearScreen();
        menuScreen(); 
      }
      if ((x>=volT[0]* fator_escala_x) && (x<=volT[2]* fator_escala_x) && (y>=volT[1]* fator_escala_y) && (y<=volT[3] * fator_escala_y))         // volta a tela de graficos
      {
        waitForIt(volT[0], volT[1], volT[2], volT[3]);
        dispScreen=9;
        clearScreen();
        graficoScreen(); 
      } 
      break; 

    case 14:  //--------------------------------Tela escolher parametro para configurar-----------------------------------
      if ((x>=orP[0]* fator_escala_x) && (x<=orP[2]* fator_escala_x) && (y>=orP[1]* fator_escala_y) && (y<=orP[3] * fator_escala_y))           
      {
        waitForIt(orP[0], orP[1], orP[2], orP[3]);
        dispScreen=16;
        clearScreen();
        config_orp_Screen(true); 
      } 
      if ((x>=phR[0]* fator_escala_x) && (x<=phR[2]* fator_escala_x) && (y>=phR[1]* fator_escala_y) && (y<=phR[3] * fator_escala_y))           
      {
        waitForIt(phR[0], phR[1], phR[2], phR[3]);
        dispScreen=15;
        clearScreen();
        config_phR_Screen(true); 
      }
      if ((x>=phA[0]* fator_escala_x) && (x<=phA[2]* fator_escala_x) && (y>=phA[1]* fator_escala_y) && (y<=phA[3] * fator_escala_y))           
      {
        waitForIt(phA[0], phA[1], phA[2], phA[3]);
        dispScreen=18;
        clearScreen();
        config_phA_Screen(true); 
      } 
      if ((x>=tempG[0]* fator_escala_x) && (x<=tempG[2]* fator_escala_x) && (y>=tempG[1]* fator_escala_y) && (y<=tempG[3] * fator_escala_y))           
      {
        waitForIt(tempG[0], tempG[1], tempG[2], tempG[3]);
        dispScreen=4;
        clearScreen();
        tempScreen(true); 
      }
      if ((x>=caliB[0]* fator_escala_x) && (x<=caliB[2]* fator_escala_x) && (y>=caliB[1]* fator_escala_y) && (y<=caliB[3] * fator_escala_y))           
      {
        waitForIt(caliB[0], caliB[1], caliB[2], caliB[3]);
        dispScreen=0;
        clearScreen();
        mainScreen(true); 
      }
      if ((x>=denS[0]* fator_escala_x) && (x<=denS[2]* fator_escala_x) && (y>=denS[1]* fator_escala_y) && (y<=denS[3] * fator_escala_y))           
      {
        waitForIt(denS[0], denS[1], denS[2], denS[3]);
        dispScreen=20;
        clearScreen();
        config_dens_Screen(true); 
      }  
      if ((x>=menU[0]* fator_escala_x) && (x<=menU[2]* fator_escala_x) && (y>=menU[1]* fator_escala_y) && (y<=menU[3] * fator_escala_y))           /// volta ao menu
      {
        waitForIt(menU[0], menU[1], menU[2], menU[3]);
        dispScreen=1;
        clearScreen();
        menuScreen(); 
      }          
      break;
    case 15:             //---------------------------------------Tela controle de PH do reator--------
      if ((x>=prOK[0]* fator_escala_x) && (x<=prOK[2]* fator_escala_x) && (y>=prOK[1]* fator_escala_y) && (y<=prOK[3] * fator_escala_y))       //Funcao salvar
      {
        waitForIt(prOK[0], prOK[1], prOK[2], prOK[3]);
        setPHR = PHR2beS;
        offPHR = PHR2beO;
        alarmPHR = PHR2beA;
        dispScreen=0;
        SavePHRToEEPROM();
        clearScreen();
        mainScreen(true);
      } 
      else
      {
        if ((x>=temM[0]* fator_escala_x) && (x<=temM[2]* fator_escala_x))                         // Primeira coluna
        {
          if ((y>=temM[1]* fator_escala_y) && (y<=temM[3] * fator_escala_y))                      //press ph minus
          {
            waitForIt(temM[0], temM[1], temM[2], temM[3]);
            PHR2beS -= 0.1;
            config_phR_Screen();
          }
          if ((y>=offM[1]* fator_escala_y) && (y<=offM[3] * fator_escala_y))                       //press offset minus
          {
            waitForIt(offM[0], offM[1], offM[2], offM[3]);
            PHR2beO -= 0.1;
            if (PHR2beO <= 0.1) {
              PHR2beO = 0.0; 
            }
            config_phR_Screen();
          }          
          if ((y>=almM[1]* fator_escala_y) && (y<=almM[3] * fator_escala_y))                        //press alarm minus
          {
            waitForIt(almM[0], almM[1], almM[2], almM[3]);
            PHR2beA -= 0.1;
            if (PHR2beA < 0.1) {
              PHR2beA = 0.0;  
            }
            config_phR_Screen();
          }
        }
        if ((x>=temP[0]* fator_escala_x) && (x<=temP[2]* fator_escala_x))                             //Segunda coluna
        {
          if ((y>=temP[1]* fator_escala_y) && (y<=temP[3] * fator_escala_y))                      //press ph plus
          {
            waitForIt(temP[0], temP[1], temP[2], temP[3]);
            PHR2beS += 0.1;
            if (PHR2beS > 9.9)
            {
              PHR2beS = 9.9;
            }
            config_phR_Screen();            
          }
          if ((y>=offP[1]* fator_escala_y) && (y<=offP[3] * fator_escala_y))                           //press offset plus
          {
            waitForIt(offP[0], offP[1], offP[2], offP[3]);
            PHR2beO += 0.1;
            if (PHR2beO > 9.9)
            {
              PHR2beO = 9.9;
            }
            config_phR_Screen();

          }
          if ((y>=almP[1]* fator_escala_y) && (y<=almP[3] * fator_escala_y))                           //press alarm plus
          {
            waitForIt(almP[0], almP[1], almP[2], almP[3]);
            PHR2beA += 0.1;
            if (PHR2beA > 9.9)
            {
              PHR2beA = 9.9;
            }
            config_phR_Screen();
          }
        }
        if ((x>=menU[0]* fator_escala_x) && (x<=menU[2]* fator_escala_x) && (y>=menU[1]* fator_escala_y) && (y<=menU[3] * fator_escala_y))           // volta ao menu
        {
          waitForIt(menU[0], menU[1], menU[2], menU[3]);
          dispScreen=14;
          clearScreen();
          parametroScreen(); 
        } 

      }
      break;
    case 16:             //---------------------------------------Tela controle de ORP---------------------------------
      if ((x>=prOK[0]* fator_escala_x) && (x<=prOK[2]* fator_escala_x) && (y>=prOK[1]* fator_escala_y) && (y<=prOK[3] * fator_escala_y))       //Funcao salvar
      {
        waitForIt(prOK[0], prOK[1], prOK[2], prOK[3]);
        setORP = ORP2beS;
        offORP = ORP2beO;
        alarmORP = ORP2beA;
        dispScreen=0;
        SaveORPToEEPROM();
        clearScreen();
        mainScreen(true);
      } 
      else
      {
        if ((x>=temM[0]* fator_escala_x) && (x<=temM[2]* fator_escala_x))                         // Primeira coluna
        {
          if ((y>=temM[1]* fator_escala_y) && (y<=temM[3] * fator_escala_y))                      //press orp minus
          {
            waitForIt(temM[0], temM[1], temM[2], temM[3]);
            ORP2beS -= 10;
            if (ORP2beS < 100)
            {
              ORP2beS =100;
            }
            config_orp_Screen();
          }
          if ((y>=offM[1]* fator_escala_y) && (y<=offM[3] * fator_escala_y))                       //press offset minus
          {
            waitForIt(offM[0], offM[1], offM[2], offM[3]);
            ORP2beO -= 10;
            if (ORP2beO < 10)
            {
              ORP2beO = 10;
            }
            config_orp_Screen();
          }          
          if ((y>=almM[1]* fator_escala_y) && (y<=almM[3] * fator_escala_y))                        //press alarm minus
          {
            waitForIt(almM[0], almM[1], almM[2], almM[3]);
            ORP2beA -= 10;
            if (ORP2beA < 10)
            {
              ORP2beA = 10;
            }
            config_orp_Screen();
          }
        }
        if ((x>=temP[0]* fator_escala_x) && (x<=temP[2]* fator_escala_x))                             //Segunda coluna
        {
          if ((y>=temP[1]* fator_escala_y) && (y<=temP[3] * fator_escala_y))                      //press orp plus
          {
            waitForIt(temP[0], temP[1], temP[2], temP[3]);
            ORP2beS += 10;
            if (ORP2beS >999)
            {
              ORP2beS = 990;
            }
            config_orp_Screen();
          }
          if ((y>=offP[1]* fator_escala_y) && (y<=offP[3] * fator_escala_y))                           //press offset plus
          {
            waitForIt(offP[0], offP[1], offP[2], offP[3]);
            ORP2beO += 10;
            if (ORP2beO >999)
            {
              ORP2beO = 990;
            }
            config_orp_Screen();
          }
          if ((y>=almP[1]* fator_escala_y) && (y<=almP[3] * fator_escala_y))                           //press alarm plus
          {
            waitForIt(almP[0], almP[1], almP[2], almP[3]);
            ORP2beA += 10;
            if (ORP2beA >999)
            {
              ORP2beA = 990;
            }
            config_orp_Screen();
          }
        }
        if ((x>=menU[0]* fator_escala_x) && (x<=menU[2]* fator_escala_x) && (y>=menU[1]* fator_escala_y) && (y<=menU[3] * fator_escala_y))           // volta ao menu
        {
          waitForIt(menU[0], menU[1], menU[2], menU[3]);
          dispScreen=14;
          clearScreen();
          parametroScreen();
        } 

      }
      break;
    case 17:   //---------------------Tela grafico de ph do reator de calcio-------------------------------------
      if ((x>=menU[0]* fator_escala_x) && (x<=menU[2]* fator_escala_x) && (y>=menU[1]* fator_escala_y) && (y<=menU[3] * fator_escala_y))           /// volta ao menu
      {
        waitForIt(menU[0], menU[1], menU[2], menU[3]);
        dispScreen=1;
        clearScreen();
        menuScreen(); 
      }
      if ((x>=volT[0]* fator_escala_x) && (x<=volT[2]* fator_escala_x) && (y>=volT[1]* fator_escala_y) && (y<=volT[3] * fator_escala_y))           // volta a tela de graficos
      {
        waitForIt(volT[0], volT[1], volT[2], volT[3]);
        dispScreen=9;
        clearScreen();
        graficoScreen(); 
      }  
      break; 

    case 18: //--------------------------Tela configuracao de ph do aquario-----------------------------------
      if ((x>=prOK[0]* fator_escala_x) && (x<=prOK[2]* fator_escala_x) && (y>=prOK[1]* fator_escala_y) && (y<=prOK[3] * fator_escala_y))       //Funcao salvar
      {
        waitForIt(prOK[0], prOK[1], prOK[2], prOK[3]);
        setPHA = PHA2beS;
        offPHA = PHA2beO;
        alarmPHA = PHA2beA;
        dispScreen=0;
        SavePHAToEEPROM();
        clearScreen();
        mainScreen(true);
      } 
      else
      {
        if ((x>=temM[0]* fator_escala_x) && (x<=temM[2]* fator_escala_x))                         // Primeira coluna
        {
          if ((y>=temM[1]* fator_escala_y) && (y<=temM[3] * fator_escala_y))                      //press ph minus
          {
            waitForIt(temM[0], temM[1], temM[2], temM[3]);
            PHA2beS -= 0.1;
            config_phA_Screen();
            if (PHA2beS <0.1)
            {
              PHA2beS = 0.0;
            }
          }
          if ((y>=offM[1]* fator_escala_y) && (y<=offM[3] * fator_escala_y))                       //press offset minus
          {
            waitForIt(offM[0], offM[1], offM[2], offM[3]);
            PHA2beO -= 0.1;
            if (PHA2beO < 0.1) {
              PHA2beO = 0.0; 
            }
            config_phA_Screen();
          }          
          if ((y>=almM[1]* fator_escala_y) && (y<=almM[3] * fator_escala_y))                        //press alarm minus
          {
            waitForIt(almM[0], almM[1], almM[2], almM[3]);
            PHA2beA -= 0.1;
            if (PHA2beA < 0.1) {
              PHA2beA = 0.0;  
            }
            config_phA_Screen();
          }
        }
        if ((x>=temP[0]* fator_escala_x) && (x<=temP[2]* fator_escala_x))                             //Segunda coluna
        {
          if ((y>=temP[1]* fator_escala_y) && (y<=temP[3] * fator_escala_y))                      //press temp plus
          {
            waitForIt(temP[0], temP[1], temP[2], temP[3]);
            PHA2beS += 0.1;
            if (PHA2beS > 9.9)
            {
              PHA2beS = 9.9;
            }            
            config_phA_Screen();
          }
          if ((y>=offP[1]* fator_escala_y) && (y<=offP[3] * fator_escala_y))                           //press offset plus
          {
            waitForIt(offP[0], offP[1], offP[2], offP[3]);
            PHA2beO += 0.1;
            if (PHA2beO > 9.9)
            {
              PHA2beO = 9.9;
            }
            config_phA_Screen();
          }
          if ((y>=almP[1]* fator_escala_y) && (y<=almP[3] * fator_escala_y))                           //press alarm plus
          {
            waitForIt(almP[0], almP[1], almP[2], almP[3]);
            PHA2beA += 0.1;
            if (PHA2beA > 9.9)
            {
              PHA2beA = 9.9;
            }
            config_phA_Screen();
          }
        }
        if ((x>=menU[0]* fator_escala_x) && (x<=menU[2]* fator_escala_x) && (y>=menU[1]* fator_escala_y) && (y<=menU[3] * fator_escala_y))           // volta ao menu
        {
          waitForIt(menU[0], menU[1], menU[2], menU[3]);
          dispScreen=14;
          clearScreen();
          parametroScreen(); 
        } 

      }
      break;

    case 19://----------------------Tela grafico de densidade----------------------------------
      if ((x>=menU[0]* fator_escala_x) && (x<=menU[2]* fator_escala_x) && (y>=menU[1]* fator_escala_y) && (y<=menU[3] * fator_escala_y))           /// volta ao menu
      {
        waitForIt(menU[0], menU[1], menU[2], menU[3]);
        dispScreen=1;
        clearScreen();
        menuScreen(); 
      }
      if ((x>=volT[0]* fator_escala_x) && (x<=volT[2]* fator_escala_x) && (y>=volT[1]* fator_escala_y) && (y<=volT[3] * fator_escala_y))           // volta a tela de graficos
      {
        waitForIt(volT[0], volT[1], volT[2], volT[3]);
        dispScreen=9;
        clearScreen();
        graficoScreen(); 
      }  
      break;

    case 20: //--------------------------Tela configuração densidade  -----------------------------------------------------
      if ((x>=prOK[0]* fator_escala_x) && (x<=prOK[2]* fator_escala_x) && (y>=prOK[1]* fator_escala_y) && (y<=prOK[3] * fator_escala_y))       //Funcao salvar
      {
        waitForIt(prOK[0], prOK[1], prOK[2], prOK[3]);
        setDEN = DEN2beS;
        offDEN = DEN2beO;
        alarmDEN = DEN2beA;
        dispScreen=0;
        SaveDENToEEPROM();
        clearScreen();
        mainScreen(true);
      } 
      else
      {
        if ((x>=temM[0]* fator_escala_x) && (x<=temM[2]* fator_escala_x))                         // Primeira coluna
        {
          if ((y>=temM[1]* fator_escala_y) && (y<=temM[3] * fator_escala_y))                      //press densidade minus
          {
            waitForIt(temM[0], temM[1], temM[2], temM[3]);
            DEN2beS -= 1;
            if (DEN2beS < 1000)
            {
              DEN2beS = 1000;
            }
            config_dens_Screen();
          }
          if ((y>=offM[1]* fator_escala_y) && (y<=offM[3] * fator_escala_y))                       //press offset minus
          {
            waitForIt(offM[0], offM[1], offM[2], offM[3]);
            DEN2beO -= 1;
            if (DEN2beO < 1)
            {
              DEN2beO = 0;
            }
            config_dens_Screen();
          }          
          if ((y>=almM[1]* fator_escala_y) && (y<=almM[3] * fator_escala_y))                        //press alarm minus
          {
            waitForIt(almM[0], almM[1], almM[2], almM[3]);
            DEN2beA -= 1;
            if (DEN2beA < 1)
            {
              DEN2beA =0;
            }
            config_dens_Screen();
          }
        }
        if ((x>=temP[0]* fator_escala_x) && (x<=temP[2]* fator_escala_x))                             //Segunda coluna
        {
          if ((y>=temP[1]* fator_escala_y) && (y<=temP[3] * fator_escala_y))                      //press densidade plus
          {
            waitForIt(temP[0], temP[1], temP[2], temP[3]);
            DEN2beS += 1;
            if (DEN2beS > 9999)
            {
              DEN2beS = 9999;
            }
            config_dens_Screen();
          }
          if ((y>=offP[1]* fator_escala_y) && (y<=offP[3] * fator_escala_y))                           //press offset plus
          {
            waitForIt(offP[0], offP[1], offP[2], offP[3]);
            DEN2beO += 1;
            if (DEN2beO > 9999)
            {
              DEN2beO = 9999;
            }
            config_dens_Screen();
          }
          if ((y>=almP[1]* fator_escala_y) && (y<=almP[3] * fator_escala_y))                           //press alarm plus
          {
            waitForIt(almP[0], almP[1], almP[2], almP[3]);
            DEN2beA += 1;
            if (DEN2beA > 9999)
            {
              DEN2beA = 9999;
            }
            config_dens_Screen();
          }
        }
        if ((x>=menU[0]* fator_escala_x) && (x<=menU[2]* fator_escala_x) && (y>=menU[1]* fator_escala_y) && (y<=menU[3] * fator_escala_y))           // volta ao menu
        {
          waitForIt(menU[0], menU[1], menU[2], menU[3]);
          dispScreen=14;
          clearScreen();
          parametroScreen(); 
        } 
      }
      break;
    case 21: // ------------------------------------------------ Escolher dosadora -----------------------------------

      if ((x>=dosa1[0]* fator_escala_x) && (x<=dosa1[2]* fator_escala_x) && (y>=dosa1[1]* fator_escala_y) && (y<=dosa1[3] * fator_escala_y))         
      {
        waitForIt(dosa1[0], dosa1[1], dosa1[2], dosa1[3]);
        if (modo_manual == true)
        {
          dosadora_1_selecionada = true;
          dosadora_2_selecionada = false;
          dosadora_3_selecionada = false;
          dispScreen = 27;
          clearScreen();
          config_dosagem_manual(true);
        }
        if (modo_automatico == true)
        {
          dosadora_1_selecionada = true;
          dosadora_2_selecionada = false;
          dosadora_3_selecionada = false;
          dispScreen = 28;
          clearScreen();
          config_dosagem_automatica(true);
        }          
        if (modo_personalizado == true)
        {
          dosadora_1_selecionada = true;
          dosadora_2_selecionada = false;
          dosadora_3_selecionada = false;
          dispScreen = 29;
          clearScreen();
          config_dosagem_personalizada(true);
        }

        if (modo_calibrar == true)
        {
          dosadora_1_selecionada = true;
          dosadora_2_selecionada = false;
          dosadora_3_selecionada = false;
          dispScreen = 26;
          clearScreen();
          calibrar_dosadoras(true);
        }      
      }
      if ((x>=dosa2[0]* fator_escala_x) && (x<=dosa2[2]* fator_escala_x) && (y>=dosa2[1]* fator_escala_y) && (y<=dosa2[3] * fator_escala_y))         
      {
        waitForIt(dosa2[0], dosa2[1], dosa2[2], dosa2[3]);
        if (modo_manual == true)
        {
          dosadora_2_selecionada = true;
          dosadora_1_selecionada = false;
          dosadora_3_selecionada = false;
          dispScreen = 27;
          clearScreen();
          config_dosagem_manual(true);
        }
        if (modo_automatico == true)
        {
          dosadora_2_selecionada = true;
          dosadora_1_selecionada = false;
          dosadora_3_selecionada = false;
          dispScreen = 28;
          clearScreen();
          config_dosagem_automatica(true);
        }          
        if (modo_personalizado == true)
        {
          dosadora_2_selecionada = true;
          dosadora_1_selecionada = false;
          dosadora_3_selecionada = false;
          dispScreen = 29;
          clearScreen();
          config_dosagem_personalizada(true);
        }

        if (modo_calibrar == true)
        {
          dosadora_2_selecionada = true;
          dosadora_1_selecionada = false;
          dosadora_3_selecionada = false;
          dispScreen = 26;
          clearScreen();
          calibrar_dosadoras(true);
        } 
      }
      if ((x>=dosa3[0]* fator_escala_x) && (x<=dosa3[2]* fator_escala_x) && (y>=dosa3[1]* fator_escala_y) && (y<=dosa3[3] * fator_escala_y))         
      {
        waitForIt(dosa3[0], dosa3[1], dosa3[2], dosa3[3]);
        if (modo_manual == true)
        {
          dosadora_3_selecionada = true;
          dosadora_1_selecionada = false;
          dosadora_2_selecionada = false;
          dispScreen = 27;
          clearScreen();
          config_dosagem_manual(true);
        }
        if (modo_automatico == true)
        {
          dosadora_3_selecionada = true;
          dosadora_1_selecionada = false;
          dosadora_2_selecionada = false;
          dispScreen = 28;
          clearScreen();
          config_dosagem_automatica(true);
        }          
        if (modo_personalizado == true)
        {
          dosadora_3_selecionada = true;
          dosadora_1_selecionada = false;
          dosadora_2_selecionada = false;
          dispScreen = 29;
          clearScreen();
          config_dosagem_personalizada(true);
        }

        if (modo_calibrar == true)
        {
          dosadora_3_selecionada = true;
          dosadora_1_selecionada = false;
          dosadora_2_selecionada = false;
          dispScreen = 26;
          clearScreen();
          calibrar_dosadoras(true);
        }  
      }        
      if ((x>=menU[0]* fator_escala_x) && (x<=menU[2]* fator_escala_x) && (y>=menU[1]* fator_escala_y) && (y<=menU[3] * fator_escala_y))           // volta ao menu
      {
        waitForIt(menU[0], menU[1], menU[2], menU[3]);
        dispScreen = 1;
        clearScreen();
        menuScreen(); 
      }
      if ((x>=volT[0]* fator_escala_x) && (x<=volT[2]* fator_escala_x) && (y>=volT[1]* fator_escala_y) && (y<=volT[3] * fator_escala_y))           // volta a tela de escolha da dosadora
      {
        waitForIt(volT[0], volT[1], volT[2], volT[3]);
        dispScreen = 8;
        clearScreen();
        menu_dosadoras();
      }
      break;

    case 26: //------------------------------------ calibrar dosadoras -------------------------------------------
      if ((x>=almP[0]* fator_escala_x) && (x<=almP[2]* fator_escala_x) && (y>=almP[1]* fator_escala_y) && (y<=almP[3]) && (dosadora_1_selecionada == true))            //fator calibracao mais.
      {
        waitForIt(almP[0], almP[1], almP[2], almP[3]);
        fator_calib_dosadora_1_temp2 += 0.1;
        if (fator_calib_dosadora_1_temp2 > 99.9)
        {
          fator_calib_dosadora_1_temp2 = 0.0;
        }
        calibrar_dosadoras();
      }
      if ((x>=almM[0]* fator_escala_x) && (x<=almM[2]* fator_escala_x) && (y>=almM[1]* fator_escala_y) && (y<=almM[3]) && (dosadora_1_selecionada == true))            //fator calibracao menos.
      {
        waitForIt(almM[0], almM[1], almM[2], almM[3]);
        fator_calib_dosadora_1_temp2 -= 0.1;
        if (fator_calib_dosadora_1_temp2 < 0.1)
        {
          fator_calib_dosadora_1_temp2 = 99.9;
        }
        calibrar_dosadoras();
      }
      if ((x>=almP[0]* fator_escala_x) && (x<=almP[2]* fator_escala_x) && (y>=almP[1]* fator_escala_y) && (y<=almP[3]) && (dosadora_2_selecionada == true))            //fator calibracao mais.
      {
        waitForIt(almP[0], almP[1], almP[2], almP[3]);
        fator_calib_dosadora_2_temp2 += 0.1;
        if (fator_calib_dosadora_2_temp2 > 99.9)
        {
          fator_calib_dosadora_2_temp2 = 0.0;
        }
        calibrar_dosadoras();
      }
      if ((x>=almM[0]* fator_escala_x) && (x<=almM[2]* fator_escala_x) && (y>=almM[1]* fator_escala_y) && (y<=almM[3]) && (dosadora_2_selecionada == true))            //fator calibracao menos.
      {
        waitForIt(almM[0], almM[1], almM[2], almM[3]);
        fator_calib_dosadora_2_temp2 -= 0.1;
        if (fator_calib_dosadora_2_temp2 < 0.1)
        {
          fator_calib_dosadora_2_temp2 = 99.9;
        }
        calibrar_dosadoras();
      }          
      if ((x>=almP[0]* fator_escala_x) && (x<=almP[2]* fator_escala_x) && (y>=almP[1]* fator_escala_y) && (y<=almP[3]) && (dosadora_3_selecionada == true))            //fator calibracao mais.
      {
        waitForIt(almP[0], almP[1], almP[2], almP[3]);
        fator_calib_dosadora_3_temp2 += 0.1;
        if (fator_calib_dosadora_3_temp2 > 99.9)
        {
          fator_calib_dosadora_3_temp2 = 0.0;
        }
        calibrar_dosadoras();
      }
      if ((x>=almM[0]* fator_escala_x) && (x<=almM[2]* fator_escala_x) && (y>=almM[1]* fator_escala_y) && (y<=almM[3]) && (dosadora_3_selecionada == true))            //fator calibracao menos.
      {
        waitForIt(almM[0], almM[1], almM[2], almM[3]);
        fator_calib_dosadora_3_temp2 -= 0.1;
        if (fator_calib_dosadora_3_temp2 < 0.1)
        {
          fator_calib_dosadora_3_temp2 = 99.9;
        }
        calibrar_dosadoras();
      }    
      if ((x>=salV[0]* fator_escala_x) && (x<=salV[2]* fator_escala_x) && (y>=salV[1]* fator_escala_y) && (y<=salV[3] * fator_escala_y))
      {
        waitForIt(salV[0], salV[1], salV[2], salV[3]); // Função salvar
        if(dosadora_1_selecionada == true)
        {
          fator_calib_dosadora_1 = fator_calib_dosadora_1_temp2;
          Salvar_dosadora_EEPROM();
          dispScreen = 21;
          clearScreen();
          selecionar_dosadora();
          setFont(SMALL, 255, 255, 255, 0, 0, 0);
          myGLCD.print(tabela_textos[172], 15, 220);
          modo_manual = false;
          modo_automatico = false;
          modo_personalizado = false;
          modo_calibrar = true;
          dosadora_1_selecionada = false;
          dosadora_2_selecionada = false;
          dosadora_3_selecionada = false;
        }        
        if(dosadora_2_selecionada == true)
        {
          fator_calib_dosadora_2 = fator_calib_dosadora_2_temp2;
          Salvar_dosadora_EEPROM();
          dispScreen = 21;
          clearScreen();
          selecionar_dosadora();
          setFont(SMALL, 255, 255, 255, 0, 0, 0);
          myGLCD.print(tabela_textos[172], 15, 220);
          modo_manual = false;
          modo_automatico = false;
          modo_personalizado = false;
          modo_calibrar = true;
          dosadora_1_selecionada = false;
          dosadora_2_selecionada = false;
          dosadora_3_selecionada = false;
        }
        if(dosadora_3_selecionada == true)
        {
          fator_calib_dosadora_3 = fator_calib_dosadora_3_temp2;
          Salvar_dosadora_EEPROM();
          dispScreen = 21;
          clearScreen();
          selecionar_dosadora();
          setFont(SMALL, 255, 255, 255, 0, 0, 0);
          myGLCD.print(tabela_textos[172], 15, 220);
          modo_manual = false;
          modo_automatico = false;
          modo_personalizado = false;
          modo_calibrar = true;
          dosadora_1_selecionada = false;
          dosadora_2_selecionada = false;
          dosadora_3_selecionada = false;
        }
      }      
      if ((x>=volT[0]* fator_escala_x) && (x<=volT[2]* fator_escala_x) && (y>=volT[1]* fator_escala_y) && (y<=volT[3] * fator_escala_y))           // Volta a tela altera configuracao das dosadoras
      {
        waitForIt(volT[0], volT[1], volT[2], volT[3]);
        dispScreen = 21;
        clearScreen();
        selecionar_dosadora();
        setFont(SMALL, 255, 255, 255, 0, 0, 0);
        myGLCD.print(tabela_textos[172], 15, 220);
        modo_manual = false;
        modo_automatico = false;
        modo_personalizado = false;
        modo_calibrar = true;
        dosadora_1_selecionada = false;
        dosadora_2_selecionada = false;
        dosadora_3_selecionada = false; 
      }
      if ((x>=iniciaR[0]* fator_escala_x) && (x<=iniciaR[2]* fator_escala_x) && (y>=iniciaR[1]* fator_escala_y) && (y<=iniciaR[3] * fator_escala_y))
      {
        waitForIt(iniciaR[0], iniciaR[1], iniciaR[2], iniciaR[3]);
        if((modo_calibrar == true) && (dosadora_1_selecionada == true))
        {
          printButton_verde(tabela_textos[17], iniciaR[0], iniciaR[1], iniciaR[2], iniciaR[3]);
          delay(10000);
          digitalWrite(dosadora1, HIGH);
          delay(60000);
          digitalWrite(dosadora1, LOW);
          printButton(tabela_textos[17], iniciaR[0], iniciaR[1], iniciaR[2], iniciaR[3]);
        }
        if((modo_calibrar == true) && (dosadora_2_selecionada == true))
        {
          printButton_verde(tabela_textos[17], iniciaR[0], iniciaR[1], iniciaR[2], iniciaR[3]);
          delay(10000);
          digitalWrite(dosadora2, HIGH);
          delay(60000);
          digitalWrite(dosadora2, LOW);
          printButton(tabela_textos[17], iniciaR[0], iniciaR[1], iniciaR[2], iniciaR[3]);
        }
        if((modo_calibrar == true) && (dosadora_3_selecionada == true))
        {
          printButton_verde(tabela_textos[17], iniciaR[0], iniciaR[1], iniciaR[2], iniciaR[3]);
          delay(10000);
          digitalWrite(dosadora3, HIGH);
          delay(60000);
          digitalWrite(dosadora3, LOW);
          printButton(tabela_textos[17], iniciaR[0], iniciaR[1], iniciaR[2], iniciaR[3]);
        }
      }      
      break;
    case 27:   // ----------------------------------------- Config dosagem manual --------------------------------------
      if ((x>=almP[0]* fator_escala_x) && (x<=almP[2]* fator_escala_x) && (y>=almP[1]* fator_escala_y) && (y<=almP[3]) && (dosadora_1_selecionada == true))            //dose manual mais.
      {
        waitForIt(almP[0], almP[1], almP[2], almP[3]);
        dose_dosadora_1_manual += 0.5;
        if (dose_dosadora_1_manual > 99.5)
        {
          dose_dosadora_1_manual = 0.0;
        }
        config_dosagem_manual();
      }
      if ((x>=almM[0]* fator_escala_x) && (x<=almM[2]* fator_escala_x) && (y>=almM[1]* fator_escala_y) && (y<=almM[3]) && (dosadora_1_selecionada == true))            //dose manual menos.
      {
        waitForIt(almM[0], almM[1], almM[2], almM[3]);
        dose_dosadora_1_manual -= 0.5;
        if (dose_dosadora_1_manual < 0.5)
        {
          dose_dosadora_1_manual = 99.5;
        }
        config_dosagem_manual();
      }
      if ((x>=almP[0]* fator_escala_x) && (x<=almP[2]* fator_escala_x) && (y>=almP[1]* fator_escala_y) && (y<=almP[3]) && (dosadora_2_selecionada == true))            //dose manual mais.
      {
        waitForIt(almP[0], almP[1], almP[2], almP[3]);
        dose_dosadora_2_manual += 0.5;
        if (dose_dosadora_2_manual > 99.5)
        {
          dose_dosadora_2_manual = 0.0;
        }
        config_dosagem_manual();
      }
      if ((x>=almM[0]* fator_escala_x) && (x<=almM[2]* fator_escala_x) && (y>=almM[1]* fator_escala_y) && (y<=almM[3]) && (dosadora_2_selecionada == true))            //dose manual menos.
      {
        waitForIt(almM[0], almM[1], almM[2], almM[3]);
        dose_dosadora_2_manual -= 0.5;
        if (dose_dosadora_2_manual < 0.5)
        {
          dose_dosadora_2_manual = 99.5;
        }
        config_dosagem_manual();
      }          
      if ((x>=almP[0]* fator_escala_x) && (x<=almP[2]* fator_escala_x) && (y>=almP[1]* fator_escala_y) && (y<=almP[3]) && (dosadora_3_selecionada == true))            //dose manual mais.
      {
        waitForIt(almP[0], almP[1], almP[2], almP[3]);
        dose_dosadora_3_manual += 0.5;
        if (dose_dosadora_3_manual > 99.5)
        {
          dose_dosadora_3_manual = 0.5;
        }
        config_dosagem_manual();
      }
      if ((x>=almM[0]* fator_escala_x) && (x<=almM[2]* fator_escala_x) && (y>=almM[1]* fator_escala_y) && (y<=almM[3]) && (dosadora_3_selecionada == true))            //dose manual menos.
      {
        waitForIt(almM[0], almM[1], almM[2], almM[3]);
        dose_dosadora_3_manual -= 0.5;
        if (dose_dosadora_3_manual < 0.5)
        {
          dose_dosadora_3_manual = 99.5;
        }
        config_dosagem_manual();
      }    

      if ((x>=volT[0]* fator_escala_x) && (x<=volT[2]* fator_escala_x) && (y>=volT[1]* fator_escala_y) && (y<=volT[3] * fator_escala_y))           // Volta a tela altera configuracao das dosadoras
      {
        waitForIt(volT[0], volT[1], volT[2], volT[3]);
        dispScreen = 21;
        clearScreen();
        selecionar_dosadora();
        setFont(SMALL, 255, 255, 255, 0, 0, 0);
        myGLCD.print(tabela_textos[164], 15, 220);
        modo_manual = true;
        modo_automatico = false;
        modo_personalizado = false;
        modo_calibrar = false;
        dosadora_1_selecionada = false;
        dosadora_2_selecionada = false;
        dosadora_3_selecionada = false; 
      }
      if ((x>=iniciaR[0]* fator_escala_x) && (x<=iniciaR[2]* fator_escala_x) && (y>=iniciaR[1]* fator_escala_y) && (y<=iniciaR[3] * fator_escala_y))
      {
        waitForIt(iniciaR[0], iniciaR[1], iniciaR[2], iniciaR[3]);
        if((modo_manual == true) && (dosadora_1_selecionada == true))
        {
          if(fator_calib_dosadora_1 > 10)
          {
            printButton_verde(tabela_textos[17], iniciaR[0], iniciaR[1], iniciaR[2], iniciaR[3]);  
            tempo_dosagem_1 = map ((dose_dosadora_1_manual*2), 0, fator_calib_dosadora_1, 0, 60000);
            tempo_dosagem_1 /= 2;                 
            delay(10000);
            digitalWrite(dosadora1, HIGH);
            delay(tempo_dosagem_1);
            digitalWrite(dosadora1, LOW);
            printButton(tabela_textos[17], iniciaR[0], iniciaR[1], iniciaR[2], iniciaR[3]);
          }
        }
        if((modo_manual == true) && (dosadora_2_selecionada == true))
        {
          if(fator_calib_dosadora_2 > 10)
          {
            printButton_verde(tabela_textos[17], iniciaR[0], iniciaR[1], iniciaR[2], iniciaR[3]);
            tempo_dosagem_1 = map ((dose_dosadora_2_manual*2), 0, fator_calib_dosadora_2, 0, 60000);
            tempo_dosagem_1 /= 2;
            delay(10000);
            digitalWrite(dosadora2, HIGH);
            delay(tempo_dosagem_1);
            digitalWrite(dosadora2, LOW);
            printButton(tabela_textos[17], iniciaR[0], iniciaR[1], iniciaR[2], iniciaR[3]);
          }
        }
        if((modo_manual == true) && (dosadora_3_selecionada == true))
        {
          if(fator_calib_dosadora_3 > 10)
          {
            printButton_verde(tabela_textos[17], iniciaR[0], iniciaR[1], iniciaR[2], iniciaR[3]);
            tempo_dosagem_1 = map ((dose_dosadora_3_manual*2), 0, fator_calib_dosadora_3, 0, 60000);
            tempo_dosagem_1 /= 2;
            delay(10000);
            digitalWrite(dosadora3, HIGH);
            delay(tempo_dosagem_1);
            digitalWrite(dosadora3, LOW);
            printButton(tabela_textos[17], iniciaR[0], iniciaR[1], iniciaR[2], iniciaR[3]);
          }
        }
      }      
      break;
    case 28:   // ----------------------------------------- Config dosagem automatica --------------------------------------

      if ((x>=volT[0]* fator_escala_x) && (x<=volT[2]* fator_escala_x) && (y>=volT[1]* fator_escala_y) && (y<=volT[3] * fator_escala_y))           // // Volta a tela altera configuracao das dosadoras
      {
        waitForIt(volT[0], volT[1], volT[2], volT[3]);
        dispScreen = 21;
        clearScreen();
        selecionar_dosadora();
        setFont(SMALL, 255, 255, 255, 0, 0, 0);
        myGLCD.print(tabela_textos[165], 15, 220); // tabela_textos[165] = "MODO AUTOMATICO SELECIONADO"
        modo_manual = false;
        modo_automatico = true;
        modo_personalizado = false;
        modo_calibrar = false;
        dosadora_1_selecionada = false;
        dosadora_2_selecionada = false;
        dosadora_3_selecionada = false; 
      }
      if(dosadora_1_selecionada == true)
      {
        if ((y >= houU[1]* fator_escala_y) && (y <= houU[3] * fator_escala_y)) // Buttons: Time UP
        {
          if ((x >= houU[0]* fator_escala_x) && (x <= houU[2]* fator_escala_x)) {
            waitForIt(houU[0], houU[1], houU[2], houU[3]);
            hora_inicial_dosagem_automatica_1_temp2 = (hora_inicial_dosagem_automatica_1_temp2 + 1) % 24;
            config_dosagem_automatica();
          } 
          if ((x >= minUT[0]* fator_escala_x) && (x <= minUT[2]* fator_escala_x)) {
            waitForIt(minUT[0], minUT[1], minUT[2], minUT[3]);
            minuto_inicial_dosagem_automatica_1_temp2 = (minuto_inicial_dosagem_automatica_1_temp2 + 1) % 60;
            config_dosagem_automatica();
          } 


          if ((x >= houU[0] + deslocamento_botao_x) && (x <= houU[2] + deslocamento_botao_x)) {
            waitForIt(houU[0] + deslocamento_botao_x, houU[1], houU[2] + deslocamento_botao_x, houU[3]);
            hora_final_dosagem_automatica_1_temp2 = (hora_final_dosagem_automatica_1_temp2 + 1) % 24;
            config_dosagem_automatica();
          } 
          if ((x >= minUT[0] + deslocamento_botao_x) && (x <= minUT[2] + deslocamento_botao_x)) {
            waitForIt(minUT[0] + deslocamento_botao_x, minUT[1], minUT[2] + deslocamento_botao_x, minUT[3]);
            minuto_final_dosagem_automatica_1_temp2 = (minuto_final_dosagem_automatica_1_temp2 + 1) % 60;
            config_dosagem_automatica();
          }

        } 
        if ((y >= houD[1]* fator_escala_y) && (y <= houD[3] * fator_escala_y)) // Buttons: Time DOWN
        {
          if ((x >= houD[0]* fator_escala_x) && (x <= houD[2]* fator_escala_x)) {
            waitForIt(houD[0], houD[1], houD[2], houD[3]);
            hora_inicial_dosagem_automatica_1_temp2 = (hora_inicial_dosagem_automatica_1_temp2 + 23) % 24;
            config_dosagem_automatica();
          } 
          if ((x >= minDT[0]* fator_escala_x) && (x <= minDT[2]* fator_escala_x)) {
            waitForIt(minDT[0], minDT[1], minDT[2], minDT[3]);
            minuto_inicial_dosagem_automatica_1_temp2 = (minuto_inicial_dosagem_automatica_1_temp2 + 59) % 60;
            config_dosagem_automatica();
          } 

          if ((x >= houD[0] + deslocamento_botao_x) && (x <= houD[2] + deslocamento_botao_x)) {
            waitForIt(houD[0] + deslocamento_botao_x, houD[1], houD[2] + deslocamento_botao_x, houD[3]);
            hora_final_dosagem_automatica_1_temp2 = (hora_final_dosagem_automatica_1_temp2 + 23) % 24;
            config_dosagem_automatica();
          } 
          if ((x >= minDT[0] + deslocamento_botao_x) && (x <= minDT[2] + deslocamento_botao_x)) {
            waitForIt(minDT[0] + deslocamento_botao_x, minDT[1], minDT[2] + deslocamento_botao_x, minDT[3]);
            minuto_final_dosagem_automatica_1_temp2 = (minuto_final_dosagem_automatica_1_temp2 + 59) % 60;
            config_dosagem_automatica();
          }
        }
        if ((x >= minUT[0]* fator_escala_x) && (x <= minUT[2]* fator_escala_x) && (y >= minUT[1]+ deslocamento_botao_y) && (y <= minUT[3] + deslocamento_botao_y)) // Dose diaria mais
        {
          waitForIt(minUT[0], minUT[1] + deslocamento_botao_y, minUT[2], minUT[3] + deslocamento_botao_y);
          dose_dosadora_1_automatica_temp2 += 0.5;
          if(dose_dosadora_1_automatica_temp2 > 999.5)
          {
            dose_dosadora_1_automatica_temp2 = 0.5;
          }
          if(dose_dosadora_1_automatica_temp2 <= 9.5)
          {
            myGLCD.setColor(0, 0, 0);                      
            myGLCD.fillRect(100, 45 + deslocamento_botao_y, 185, 67 + deslocamento_botao_y);
          }           

          config_dosagem_automatica();
        }
        if ((x >= minDT[0]* fator_escala_x) && (x <= minDT[2]* fator_escala_x) && (y >= minDT[1] + deslocamento_botao_y) && (y <= minDT[3] + deslocamento_botao_y)) // Dose diaria menos
        {
          waitForIt(minDT[0], minDT[1] + deslocamento_botao_y, minDT[2], minDT[3] + deslocamento_botao_y);
          dose_dosadora_1_automatica_temp2 -= 0.5;
          if(dose_dosadora_1_automatica_temp2 <0.5)
          {
            dose_dosadora_1_automatica_temp2 = 999.5;
          }
          if(dose_dosadora_1_automatica_temp2 <= 9.5)
          {
            myGLCD.setColor(0, 0, 0);                      
            myGLCD.fillRect(100, 45 + deslocamento_botao_y, 185, 67 + deslocamento_botao_y);
          }
          config_dosagem_automatica();
        }
        if ((x >= durC[0]* fator_escala_x) && (x <= durC[2]* fator_escala_x) && (y >= durC[1] + deslocamento_botao_y) && (y <= durC[3] + deslocamento_botao_y)) 
        {
          waitForIt(durC[0], durC[1] + deslocamento_botao_y, durC[2], durC[3] + deslocamento_botao_y); 
          quantidade_dose_dosadora_1_automatica_temp2 += 1;
          if(quantidade_dose_dosadora_1_automatica_temp2 > 24)
          {
            quantidade_dose_dosadora_1_automatica_temp2 = 1;
          }
          config_dosagem_automatica();
        }

        if ((x >= durB[0]* fator_escala_x) && (x <= durB[2]* fator_escala_x) && (y >= durB[1] + deslocamento_botao_y) && (y <= durB[3] + deslocamento_botao_y)) 
        {
          waitForIt(durB[0], durB[1] + deslocamento_botao_y, durB[2], durB[3] + deslocamento_botao_y);
          quantidade_dose_dosadora_1_automatica_temp2 -= 1;
          if(quantidade_dose_dosadora_1_automatica_temp2 < 1)
          {
            quantidade_dose_dosadora_1_automatica_temp2 = 24;
          }
          config_dosagem_automatica();        
        }
        if ((x >= domI[0]* fator_escala_x) && (x<= domI[2]* fator_escala_x) && (y >= domI [1]* fator_escala_y) && (y <= domI[3] * fator_escala_y)) // Ativar ou desativar modo automatico
        {
          waitForIt(domI[0], domI[1], domI[2], domI[3]);
          if(modo_automatico_on_1_temp2 == 0)
          {
            modo_automatico_on_1_temp2 = 1;
            modo_personalizado_on_1_temp2 = 0;
            config_dosagem_automatica();
          }
          else
          {
            modo_automatico_on_1_temp2 = 0;
            modo_personalizado_on_1_temp2 = 1;
            config_dosagem_automatica();
          }
        }
        if ((y >= salV[1]* fator_escala_y) && (y <= salV[3]) && (x >= salV[0]* fator_escala_x) && (x <= salV[2]* fator_escala_x)) 
        {
          waitForIt(salV[0], salV[1], salV[2], salV[3]); //funcao salvar
          dose_dosadora_1_automatica = dose_dosadora_1_automatica_temp2;
          quantidade_dose_dosadora_1_automatica = quantidade_dose_dosadora_1_automatica_temp2;
          modo_automatico_on_1 = modo_automatico_on_1_temp2;
          modo_personalizado_on_1 = modo_personalizado_on_1_temp2;
          hora_inicial_dosagem_automatica_1 = hora_inicial_dosagem_automatica_1_temp2;
          minuto_inicial_dosagem_automatica_1 = minuto_inicial_dosagem_automatica_1_temp2;
          hora_final_dosagem_automatica_1 = hora_final_dosagem_automatica_1_temp2;
          minuto_final_dosagem_automatica_1 = minuto_final_dosagem_automatica_1_temp2;

          if((hora_final_dosagem_automatica_1_temp2 == hora_inicial_dosagem_automatica_1) && (minuto_final_dosagem_automatica_1_temp2 < (minuto_inicial_dosagem_automatica_1+10)))
          {
            setFont(SMALL, 255, 0, 0, 0, 0, 0);
            myGLCD.print(tabela_textos[166], 225, 198); // tabela_textos[166]
            myGLCD.print(tabela_textos[167], 225, 218);

          }
          if(hora_final_dosagem_automatica_1_temp2 < hora_inicial_dosagem_automatica_1)
          {
            setFont(SMALL, 255, 0, 0, 0, 0, 0);
            myGLCD.print(tabela_textos[168], 225, 198);
            myGLCD.print(tabela_textos[169], 225, 218);
          }
          if((hora_final_dosagem_automatica_1_temp2 == hora_inicial_dosagem_automatica_1) && (minuto_final_dosagem_automatica_1_temp2 >= (minuto_inicial_dosagem_automatica_1+10)))
          {
            dispScreen = 21;
            clearScreen();
            selecionar_dosadora();
            setFont(SMALL, 255, 255, 255, 0, 0, 0);
            myGLCD.print(tabela_textos[165], 15, 220); // tabela_textos[165] = "MODO AUTOMATICO SELECIONADO"
            modo_manual = false;
            modo_automatico = true;
            modo_personalizado = false;
            modo_calibrar = false;
            dosadora_1_selecionada = false;
            dosadora_2_selecionada = false;
            dosadora_3_selecionada = false; 
            digitalWrite (4, LOW); 
            file.open(&root, "HDA1.TXT", O_WRITE);
            file.remove();       
            file.open(&root, "HDA1.TXT", O_CREAT | O_APPEND | O_WRITE);

            minuto01 = (((hora_final_dosagem_automatica_1 * 60) + (minuto_final_dosagem_automatica_1)) - ((hora_inicial_dosagem_automatica_1 * 60) + (minuto_inicial_dosagem_automatica_1))); 
            minuto01 /= 1 + quantidade_dose_dosadora_1_automatica;

            for(int i = 1; i <= quantidade_dose_dosadora_1_automatica; i++)
            { 
              contador += 1;  
              if(contador == 1)
              {
                minuto11 = (hora_inicial_dosagem_automatica_1 * 60) + minuto_inicial_dosagem_automatica_1 + minuto01;
              }
              if(contador > 1)
              {
                minuto11 += minuto01; 
              }
              if(minuto11 < 10)
              {
                file.print("000");  
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(( minuto11 > 10) && (minuto11 < 100))
              {
                file.print("00");
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(( minuto11 >= 100) && (minuto11 < 1000))
              {
                file.print("0");
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(minuto11 >= 1000)
              {
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }              
            }
            file.close();  
            contador = 0;
            digitalWrite (4, HIGH);
            Salvar_dosadora_EEPROM(); 
          }    

          if(hora_final_dosagem_automatica_1_temp2 > hora_inicial_dosagem_automatica_1)
          {
            dispScreen = 21;
            clearScreen();
            selecionar_dosadora();
            setFont(SMALL, 255, 255, 255, 0, 0, 0);
            myGLCD.print(tabela_textos[165], 15, 220); // tabela_textos[165] = "MODO AUTOMATICO SELECIONADO"
            modo_manual = false;
            modo_automatico = true;
            modo_personalizado = false;
            modo_calibrar = false;
            dosadora_1_selecionada = false;
            dosadora_2_selecionada = false;
            dosadora_3_selecionada = false; 
            digitalWrite (4, LOW); 
            file.open(&root, "HDA1.TXT", O_WRITE);
            file.remove();       
            file.open(&root, "HDA1.TXT", O_CREAT | O_APPEND | O_WRITE);

            minuto01 = (((hora_final_dosagem_automatica_1 * 60) + (minuto_final_dosagem_automatica_1)) - ((hora_inicial_dosagem_automatica_1 * 60) + (minuto_inicial_dosagem_automatica_1))); 
            minuto01 /= 1 + quantidade_dose_dosadora_1_automatica;

            for(int i = 1; i <= quantidade_dose_dosadora_1_automatica; i++)
            { 
              contador += 1;  
              if(contador == 1)
              {
                minuto11 = (hora_inicial_dosagem_automatica_1 * 60) + minuto_inicial_dosagem_automatica_1 + minuto01;
              }
              if(contador > 1)
              {
                minuto11 += minuto01; 
              }
              if(minuto11 < 10)
              {
                file.print("000");  
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(( minuto11 > 10) && (minuto11 < 100))
              {
                file.print("00");
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(( minuto11 >= 100) && (minuto11 < 1000))
              {
                file.print("0");
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(minuto11 >= 1000)
              {
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
            }
            file.close();  
            contador = 0;
            digitalWrite (4, HIGH);
            Salvar_dosadora_EEPROM();
          }         
        }
      }
      if(dosadora_2_selecionada == true)
      {
        if ((y >= houU[1]* fator_escala_y) && (y <= houU[3] * fator_escala_y)) // Buttons: Time UP
        {
          if ((x >= houU[0]* fator_escala_x) && (x <= houU[2]* fator_escala_x)) {
            waitForIt(houU[0], houU[1], houU[2], houU[3]);
            hora_inicial_dosagem_automatica_2_temp2 = (hora_inicial_dosagem_automatica_2_temp2 + 1) % 24;
            config_dosagem_automatica();
          } 
          if ((x >= minUT[0]* fator_escala_x) && (x <= minUT[2]* fator_escala_x)) {
            waitForIt(minUT[0], minUT[1], minUT[2], minUT[3]);
            minuto_inicial_dosagem_automatica_2_temp2 = (minuto_inicial_dosagem_automatica_2_temp2 + 1) % 60;
            config_dosagem_automatica();
          } 


          if ((x >= houU[0] + deslocamento_botao_x) && (x <= houU[2] + deslocamento_botao_x)) {
            waitForIt(houU[0] + deslocamento_botao_x, houU[1], houU[2] + deslocamento_botao_x, houU[3]);
            hora_final_dosagem_automatica_2_temp2 = (hora_final_dosagem_automatica_2_temp2 + 1) % 24;
            config_dosagem_automatica();
          } 
          if ((x >= minUT[0] + deslocamento_botao_x) && (x <= minUT[2] + deslocamento_botao_x)) {
            waitForIt(minUT[0] + deslocamento_botao_x, minUT[1], minUT[2] + deslocamento_botao_x, minUT[3]);
            minuto_final_dosagem_automatica_2_temp2 = (minuto_final_dosagem_automatica_2_temp2 + 1) % 60;
            config_dosagem_automatica();
          }

        } 
        if ((y >= houD[1]* fator_escala_y) && (y <= houD[3] * fator_escala_y)) // Buttons: Time DOWN
        {
          if ((x >= houD[0]* fator_escala_x) && (x <= houD[2]* fator_escala_x)) {
            waitForIt(houD[0], houD[1], houD[2], houD[3]);
            hora_inicial_dosagem_automatica_2_temp2 = (hora_inicial_dosagem_automatica_2_temp2 + 23) % 24;
            config_dosagem_automatica();
          } 
          if ((x >= minDT[0]* fator_escala_x) && (x <= minDT[2]* fator_escala_x)) {
            waitForIt(minDT[0], minDT[1], minDT[2], minDT[3]);
            minuto_inicial_dosagem_automatica_2_temp2 = (minuto_inicial_dosagem_automatica_2_temp2 + 59) % 60;
            config_dosagem_automatica();
          } 

          if ((x >= houD[0] + deslocamento_botao_x) && (x <= houD[2] + deslocamento_botao_x)) {
            waitForIt(houD[0] + deslocamento_botao_x, houD[1], houD[2] + deslocamento_botao_x, houD[3]);
            hora_final_dosagem_automatica_2_temp2 = (hora_final_dosagem_automatica_2_temp2 + 23) % 24;
            config_dosagem_automatica();
          } 
          if ((x >= minDT[0] + deslocamento_botao_x) && (x <= minDT[2] + deslocamento_botao_x)) {
            waitForIt(minDT[0] + deslocamento_botao_x, minDT[1], minDT[2] + deslocamento_botao_x, minDT[3]);
            minuto_final_dosagem_automatica_2_temp2 = (minuto_final_dosagem_automatica_2_temp2 + 59) % 60;
            config_dosagem_automatica();
          }
        }
        if ((x >= minUT[0]* fator_escala_x) && (x <= minUT[2]* fator_escala_x) && (y >= minUT[1]+ deslocamento_botao_y) && (y <= minUT[3] + deslocamento_botao_y)) // Dose diaria mais
        {
          waitForIt(minUT[0], minUT[1] + deslocamento_botao_y, minUT[2], minUT[3] + deslocamento_botao_y);
          dose_dosadora_2_automatica_temp2 += 0.5;
          if(dose_dosadora_2_automatica_temp2 > 999.5)
          {
            dose_dosadora_2_automatica_temp2 = 0.5;
          }
          if(dose_dosadora_2_automatica_temp2 <= 9.5)
          {
            myGLCD.setColor(0, 0, 0);                      
            myGLCD.fillRect(100, 45 + deslocamento_botao_y, 185, 67 + deslocamento_botao_y);
          }           

          config_dosagem_automatica();
        }
        if ((x >= minDT[0]* fator_escala_x) && (x <= minDT[2]* fator_escala_x) && (y >= minDT[1] + deslocamento_botao_y) && (y <= minDT[3] + deslocamento_botao_y)) // Dose diaria menos
        {
          waitForIt(minDT[0], minDT[1] + deslocamento_botao_y, minDT[2], minDT[3] + deslocamento_botao_y);
          dose_dosadora_2_automatica_temp2 -= 0.5;
          if(dose_dosadora_2_automatica_temp2 <0.5)
          {
            dose_dosadora_2_automatica_temp2 = 999.5;
          }
          if(dose_dosadora_2_automatica_temp2 <= 9.5)
          {
            myGLCD.setColor(0, 0, 0);                      
            myGLCD.fillRect(100, 45 + deslocamento_botao_y, 185, 67 + deslocamento_botao_y);
          }
          config_dosagem_automatica();
        }
        if ((x >= durC[0]* fator_escala_x) && (x <= durC[2]* fator_escala_x) && (y >= durC[1] + deslocamento_botao_y) && (y <= durC[3] + deslocamento_botao_y)) 
        {
          waitForIt(durC[0], durC[1] + deslocamento_botao_y, durC[2], durC[3] + deslocamento_botao_y); 
          quantidade_dose_dosadora_2_automatica_temp2 += 1;
          if(quantidade_dose_dosadora_2_automatica_temp2 > 24)
          {
            quantidade_dose_dosadora_2_automatica_temp2 = 1;
          }
          config_dosagem_automatica();
        }

        if ((x >= durB[0]* fator_escala_x) && (x <= durB[2]* fator_escala_x) && (y >= durB[1] + deslocamento_botao_y) && (y <= durB[3] + deslocamento_botao_y)) 
        {
          waitForIt(durB[0], durB[1] + deslocamento_botao_y, durB[2], durB[3] + deslocamento_botao_y);
          quantidade_dose_dosadora_2_automatica_temp2 -= 1;
          if(quantidade_dose_dosadora_2_automatica_temp2 < 1)
          {
            quantidade_dose_dosadora_2_automatica_temp2 = 24;
          }
          config_dosagem_automatica();        
        }
        if ((x >= domI[0]* fator_escala_x) && (x<= domI[2]* fator_escala_x) && (y >= domI [1]* fator_escala_y) && (y <= domI[3] * fator_escala_y)) // Ativar ou desativar modo automatico
        {
          waitForIt(domI[0], domI[1], domI[2], domI[3]);
          if(modo_automatico_on_2_temp2 == 0)
          {
            modo_automatico_on_2_temp2 = 1;
            modo_personalizado_on_2_temp2 = 0;
            config_dosagem_automatica();
          }
          else
          {
            modo_automatico_on_2_temp2 = 0;
            modo_personalizado_on_2_temp2 = 1;
            config_dosagem_automatica();
          }
        }
        if ((y >= salV[1]* fator_escala_y) && (y <= salV[3]) && (x >= salV[0]* fator_escala_x) && (x <= salV[2]* fator_escala_x)) 
        {
          waitForIt(salV[0], salV[1], salV[2], salV[3]); //funcao salvar
          dose_dosadora_2_automatica = dose_dosadora_2_automatica_temp2;
          quantidade_dose_dosadora_2_automatica = quantidade_dose_dosadora_2_automatica_temp2;
          modo_automatico_on_2 = modo_automatico_on_2_temp2;
          modo_personalizado_on_2 = modo_personalizado_on_2_temp2;
          hora_inicial_dosagem_automatica_2 = hora_inicial_dosagem_automatica_2_temp2;
          minuto_inicial_dosagem_automatica_2 = minuto_inicial_dosagem_automatica_2_temp2;
          hora_final_dosagem_automatica_2 = hora_final_dosagem_automatica_2_temp2;
          minuto_final_dosagem_automatica_2 = minuto_final_dosagem_automatica_2_temp2;

          if((hora_final_dosagem_automatica_2_temp2 == hora_inicial_dosagem_automatica_2) && (minuto_final_dosagem_automatica_2_temp2 < (minuto_inicial_dosagem_automatica_2+10)))
          {
            setFont(SMALL, 255, 0, 0, 0, 0, 0);
            myGLCD.print(tabela_textos[166], 225, 198);
            myGLCD.print(tabela_textos[167], 225, 218);

          }
          if(hora_final_dosagem_automatica_2_temp2 < hora_inicial_dosagem_automatica_2)
          {
            setFont(SMALL, 255, 0, 0, 0, 0, 0);
            myGLCD.print(tabela_textos[168], 225, 198);
            myGLCD.print(tabela_textos[169], 225, 218);
          }
          if((hora_final_dosagem_automatica_2_temp2 == hora_inicial_dosagem_automatica_2) && (minuto_final_dosagem_automatica_2_temp2 >= (minuto_inicial_dosagem_automatica_2+10)))
          {
            dispScreen = 21;
            clearScreen();
            selecionar_dosadora();
            setFont(SMALL, 255, 255, 255, 0, 0, 0);
            myGLCD.print(tabela_textos[165], 15, 220); // tabela_textos[165] = "MODO AUTOMATICO SELECIONADO"
            modo_manual = false;
            modo_automatico = true;
            modo_personalizado = false;
            modo_calibrar = false;
            dosadora_1_selecionada = false;
            dosadora_2_selecionada = false;
            dosadora_3_selecionada = false; 
            digitalWrite (4, LOW); 
            file.open(&root, "HDA2.TXT", O_WRITE);
            file.remove();       
            file.open(&root, "HDA2.TXT", O_CREAT | O_APPEND | O_WRITE);

            minuto01 = (((hora_final_dosagem_automatica_2 * 60) + (minuto_final_dosagem_automatica_2)) - ((hora_inicial_dosagem_automatica_2 * 60) + (minuto_inicial_dosagem_automatica_2))); 
            minuto01 /= 1 + quantidade_dose_dosadora_2_automatica;

            for(int i = 1; i <= quantidade_dose_dosadora_2_automatica; i++)
            { 
              contador += 1;  
              if(contador == 1)
              {
                minuto11 = (hora_inicial_dosagem_automatica_2 * 60) + minuto_inicial_dosagem_automatica_2 + minuto01;
              }
              if(contador > 1)
              {
                minuto11 += minuto01; 
              }
              if(minuto11 < 10)
              {
                file.print("000");  
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(( minuto11 > 10) && (minuto11 < 100))
              {
                file.print("00");
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(( minuto11 >= 100) && (minuto11 < 1000))
              {
                file.print("0");
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(minuto11 >= 1000)
              {
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
            }
            file.close();  
            contador = 0;
            digitalWrite (4, HIGH);
            Salvar_dosadora_EEPROM(); 
          }    

          if(hora_final_dosagem_automatica_2_temp2 > hora_inicial_dosagem_automatica_2)
          {
            dispScreen = 21;
            clearScreen();
            selecionar_dosadora();
            setFont(SMALL, 255, 255, 255, 0, 0, 0);
            myGLCD.print(tabela_textos[165], 15, 220); // tabela_textos[165] = "MODO AUTOMATICO SELECIONADO"
            modo_manual = false;
            modo_automatico = true;
            modo_personalizado = false;
            modo_calibrar = false;
            dosadora_1_selecionada = false;
            dosadora_2_selecionada = false;
            dosadora_3_selecionada = false; 
            digitalWrite (4, LOW); 
            file.open(&root, "HDA2.TXT", O_WRITE);
            file.remove();       
            file.open(&root, "HDA2.TXT", O_CREAT | O_APPEND | O_WRITE);

            minuto01 = (((hora_final_dosagem_automatica_2 * 60) + (minuto_final_dosagem_automatica_2)) - ((hora_inicial_dosagem_automatica_2 * 60) + (minuto_inicial_dosagem_automatica_2))); 
            minuto01 /= 1 + quantidade_dose_dosadora_2_automatica;

            for(int i = 1; i <= quantidade_dose_dosadora_2_automatica; i++)
            { 
              contador += 1;  
              if(contador == 1)
              {
                minuto11 = (hora_inicial_dosagem_automatica_2 * 60) + minuto_inicial_dosagem_automatica_2 + minuto01;
              }
              if(contador > 1)
              {
                minuto11 += minuto01; 
              }
              if(minuto11 < 10)
              {
                file.print("000");  
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(( minuto11 > 10) && (minuto11 < 100))
              {
                file.print("00");
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(( minuto11 >= 100) && (minuto11 < 1000))
              {
                file.print("0");
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(minuto11 >= 1000)
              {
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
            }
            file.close();  
            contador = 0;
            digitalWrite (4, HIGH);
            Salvar_dosadora_EEPROM();
          }         
        }
      }
      if(dosadora_3_selecionada == true)
      {
        if ((y >= houU[1]* fator_escala_y) && (y <= houU[3] * fator_escala_y)) // Buttons: Time UP
        {
          if ((x >= houU[0]* fator_escala_x) && (x <= houU[2]* fator_escala_x)) {
            waitForIt(houU[0], houU[1], houU[2], houU[3]);
            hora_inicial_dosagem_automatica_3_temp2 = (hora_inicial_dosagem_automatica_3_temp2 + 1) % 24;
            config_dosagem_automatica();
          } 
          if ((x >= minUT[0]* fator_escala_x) && (x <= minUT[2]* fator_escala_x)) {
            waitForIt(minUT[0], minUT[1], minUT[2], minUT[3]);
            minuto_inicial_dosagem_automatica_3_temp2 = (minuto_inicial_dosagem_automatica_3_temp2 + 1) % 60;
            config_dosagem_automatica();
          } 


          if ((x >= houU[0] + deslocamento_botao_x) && (x <= houU[2] + deslocamento_botao_x)) {
            waitForIt(houU[0] + deslocamento_botao_x, houU[1], houU[2] + deslocamento_botao_x, houU[3]);
            hora_final_dosagem_automatica_3_temp2 = (hora_final_dosagem_automatica_3_temp2 + 1) % 24;
            config_dosagem_automatica();
          } 
          if ((x >= minUT[0] + deslocamento_botao_x) && (x <= minUT[2] + deslocamento_botao_x)) {
            waitForIt(minUT[0] + deslocamento_botao_x, minUT[1], minUT[2] + deslocamento_botao_x, minUT[3]);
            minuto_final_dosagem_automatica_3_temp2 = (minuto_final_dosagem_automatica_3_temp2 + 1) % 60;
            config_dosagem_automatica();
          }

        } 
        if ((y >= houD[1]* fator_escala_y) && (y <= houD[3] * fator_escala_y)) // Buttons: Time DOWN
        {
          if ((x >= houD[0]* fator_escala_x) && (x <= houD[2]* fator_escala_x)) {
            waitForIt(houD[0], houD[1], houD[2], houD[3]);
            hora_inicial_dosagem_automatica_3_temp2 = (hora_inicial_dosagem_automatica_3_temp2 + 23) % 24;
            config_dosagem_automatica();
          } 
          if ((x >= minDT[0]* fator_escala_x) && (x <= minDT[2]* fator_escala_x)) {
            waitForIt(minDT[0], minDT[1], minDT[2], minDT[3]);
            minuto_inicial_dosagem_automatica_3_temp2 = (minuto_inicial_dosagem_automatica_3_temp2 + 59) % 60;
            config_dosagem_automatica();
          } 

          if ((x >= houD[0] + deslocamento_botao_x) && (x <= houD[2] + deslocamento_botao_x)) {
            waitForIt(houD[0] + deslocamento_botao_x, houD[1], houD[2] + deslocamento_botao_x, houD[3]);
            hora_final_dosagem_automatica_3_temp2 = (hora_final_dosagem_automatica_3_temp2 + 23) % 24;
            config_dosagem_automatica();
          } 
          if ((x >= minDT[0] + deslocamento_botao_x) && (x <= minDT[2] + deslocamento_botao_x)) {
            waitForIt(minDT[0] + deslocamento_botao_x, minDT[1], minDT[2] + deslocamento_botao_x, minDT[3]);
            minuto_final_dosagem_automatica_3_temp2 = (minuto_final_dosagem_automatica_3_temp2 + 59) % 60;
            config_dosagem_automatica();
          }
        }
        if ((x >= minUT[0]* fator_escala_x) && (x <= minUT[2]* fator_escala_x) && (y >= minUT[1]+ deslocamento_botao_y) && (y <= minUT[3] + deslocamento_botao_y)) // Dose diaria mais
        {
          waitForIt(minUT[0], minUT[1] + deslocamento_botao_y, minUT[2], minUT[3] + deslocamento_botao_y);
          dose_dosadora_3_automatica_temp2 += 0.5;
          if(dose_dosadora_3_automatica_temp2 > 999.5)
          {
            dose_dosadora_3_automatica_temp2 = 0.5;
          }
          if(dose_dosadora_3_automatica_temp2 <= 9.5)
          {
            myGLCD.setColor(0, 0, 0);                      
            myGLCD.fillRect(100, 45 + deslocamento_botao_y, 185, 67 + deslocamento_botao_y);
          }           

          config_dosagem_automatica();
        }
        if ((x >= minDT[0]* fator_escala_x) && (x <= minDT[2]* fator_escala_x) && (y >= minDT[1] + deslocamento_botao_y) && (y <= minDT[3] + deslocamento_botao_y)) // Dose diaria menos
        {
          waitForIt(minDT[0], minDT[1] + deslocamento_botao_y, minDT[2], minDT[3] + deslocamento_botao_y);
          dose_dosadora_3_automatica_temp2 -= 0.5;
          if(dose_dosadora_3_automatica_temp2 <0.5)
          {
            dose_dosadora_3_automatica_temp2 = 999.5;
          }
          if(dose_dosadora_3_automatica_temp2 <= 9.5)
          {
            myGLCD.setColor(0, 0, 0);                      
            myGLCD.fillRect(100, 45 + deslocamento_botao_y, 185, 67 + deslocamento_botao_y);
          }
          config_dosagem_automatica();
        }
        if ((x >= durC[0]* fator_escala_x) && (x <= durC[2]* fator_escala_x) && (y >= durC[1] + deslocamento_botao_y) && (y <= durC[3] + deslocamento_botao_y)) 
        {
          waitForIt(durC[0], durC[1] + deslocamento_botao_y, durC[2], durC[3] + deslocamento_botao_y); 
          quantidade_dose_dosadora_3_automatica_temp2 += 1;
          if(quantidade_dose_dosadora_3_automatica_temp2 > 24)
          {
            quantidade_dose_dosadora_3_automatica_temp2 = 1;
          }
          config_dosagem_automatica();
        }

        if ((x >= durB[0]* fator_escala_x) && (x <= durB[2]* fator_escala_x) && (y >= durB[1] + deslocamento_botao_y) && (y <= durB[3] + deslocamento_botao_y)) 
        {
          waitForIt(durB[0], durB[1] + deslocamento_botao_y, durB[2], durB[3] + deslocamento_botao_y);
          quantidade_dose_dosadora_3_automatica_temp2 -= 1;
          if(quantidade_dose_dosadora_3_automatica_temp2 < 1)
          {
            quantidade_dose_dosadora_3_automatica_temp2 = 24;
          }
          config_dosagem_automatica();        
        }
        if ((x >= domI[0]* fator_escala_x) && (x<= domI[2]* fator_escala_x) && (y >= domI [1]* fator_escala_y) && (y <= domI[3] * fator_escala_y)) // Ativar ou desativar modo automatico
        {
          waitForIt(domI[0], domI[1], domI[2], domI[3]);
          if(modo_automatico_on_3_temp2 == 0)
          {
            modo_automatico_on_3_temp2 = 1;
            modo_personalizado_on_3_temp2 = 0;
            config_dosagem_automatica();
          }
          else
          {
            modo_automatico_on_3_temp2 = 0;
            modo_personalizado_on_3_temp2 = 1;
            config_dosagem_automatica();
          }
        }
        if ((y >= salV[1]* fator_escala_y) && (y <= salV[3]) && (x >= salV[0]* fator_escala_x) && (x <= salV[2]* fator_escala_x)) 
        {
          waitForIt(salV[0], salV[1], salV[2], salV[3]); //funcao salvar
          dose_dosadora_3_automatica = dose_dosadora_3_automatica_temp2;
          quantidade_dose_dosadora_3_automatica = quantidade_dose_dosadora_3_automatica_temp2;
          modo_automatico_on_3 = modo_automatico_on_3_temp2;
          modo_personalizado_on_3 = modo_personalizado_on_3_temp2;
          hora_inicial_dosagem_automatica_3 = hora_inicial_dosagem_automatica_3_temp2;
          minuto_inicial_dosagem_automatica_3 = minuto_inicial_dosagem_automatica_3_temp2;
          hora_final_dosagem_automatica_3 = hora_final_dosagem_automatica_3_temp2;
          minuto_final_dosagem_automatica_3 = minuto_final_dosagem_automatica_3_temp2;

          if((hora_final_dosagem_automatica_3_temp2 == hora_inicial_dosagem_automatica_3) && (minuto_final_dosagem_automatica_3_temp2 < (minuto_inicial_dosagem_automatica_3+10)))
          {
            setFont(SMALL, 255, 0, 0, 0, 0, 0);
            myGLCD.print(tabela_textos[166], 225, 198);
            myGLCD.print(tabela_textos[167], 225, 218);

          }
          if(hora_final_dosagem_automatica_3_temp2 < hora_inicial_dosagem_automatica_3)
          {
            setFont(SMALL, 255, 0, 0, 0, 0, 0);
            myGLCD.print(tabela_textos[168], 225, 198);
            myGLCD.print(tabela_textos[169], 225, 218);
          }
          if((hora_final_dosagem_automatica_3_temp2 == hora_inicial_dosagem_automatica_3) && (minuto_final_dosagem_automatica_3_temp2 >= (minuto_inicial_dosagem_automatica_3+10)))
          {
            dispScreen = 21;
            clearScreen();
            selecionar_dosadora();
            setFont(SMALL, 255, 255, 255, 0, 0, 0);
            myGLCD.print(tabela_textos[165], 15, 220); // tabela_textos[165] = "MODO AUTOMATICO SELECIONADO"
            modo_manual = false;
            modo_automatico = true;
            modo_personalizado = false;
            modo_calibrar = false;
            dosadora_1_selecionada = false;
            dosadora_2_selecionada = false;
            dosadora_3_selecionada = false; 
            digitalWrite (4, LOW); 
            file.open(&root, "HDA3.TXT", O_WRITE);
            file.remove();       
            file.open(&root, "HDA3.TXT", O_CREAT | O_APPEND | O_WRITE);

            minuto01 = (((hora_final_dosagem_automatica_3 * 60) + (minuto_final_dosagem_automatica_3)) - ((hora_inicial_dosagem_automatica_3 * 60) + (minuto_inicial_dosagem_automatica_3))); 
            minuto01 /= 1 + quantidade_dose_dosadora_3_automatica;

            for(int i = 1; i <= quantidade_dose_dosadora_3_automatica; i++)
            { 
              contador += 1;  
              if(contador == 1)
              {
                minuto11 = (hora_inicial_dosagem_automatica_3 * 60) + minuto_inicial_dosagem_automatica_3 + minuto01;
              }
              if(contador > 1)
              {
                minuto11 += minuto01; 
              }
              if(minuto11 < 10)
              {
                file.print("000");  
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(( minuto11 > 10) && (minuto11 < 100))
              {
                file.print("00");
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(( minuto11 >= 100) && (minuto11 < 1000))
              {
                file.print("0");
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(minuto11 >= 1000)
              {
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
            }
            file.close();  
            contador = 0;
            digitalWrite (4, HIGH);
            Salvar_dosadora_EEPROM(); 
          }    

          if(hora_final_dosagem_automatica_3_temp2 > hora_inicial_dosagem_automatica_3)
          {
            dispScreen = 21;
            clearScreen();
            selecionar_dosadora();
            setFont(SMALL, 255, 255, 255, 0, 0, 0);
            myGLCD.print(tabela_textos[165], 15, 220); // tabela_textos[165] = "MODO AUTOMATICO SELECIONADO"
            modo_manual = false;
            modo_automatico = true;
            modo_personalizado = false;
            modo_calibrar = false;
            dosadora_1_selecionada = false;
            dosadora_2_selecionada = false;
            dosadora_3_selecionada = false; 
            digitalWrite (4, LOW); 
            file.open(&root, "HDA3.TXT", O_WRITE);
            file.remove();       
            file.open(&root, "HDA3.TXT", O_CREAT | O_APPEND | O_WRITE);

            minuto01 = (((hora_final_dosagem_automatica_3 * 60) + (minuto_final_dosagem_automatica_3)) - ((hora_inicial_dosagem_automatica_3 * 60) + (minuto_inicial_dosagem_automatica_3))); 
            minuto01 /= 1 + quantidade_dose_dosadora_3_automatica;

            for(int i = 1; i <= quantidade_dose_dosadora_3_automatica; i++)
            { 
              contador += 1;  
              if(contador == 1)
              {
                minuto11 = (hora_inicial_dosagem_automatica_3 * 60) + minuto_inicial_dosagem_automatica_3 + minuto01;
              }
              if(contador > 1)
              {
                minuto11 += minuto01; 
              }
              if(minuto11 < 10)
              {
                file.print("000");  
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(( minuto11 > 10) && (minuto11 < 100))
              {
                file.print("00");
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(( minuto11 >= 100) && (minuto11 < 1000))
              {
                file.print("0");
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(minuto11 >= 1000)
              {
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
            }
            file.close();  
            contador = 0;
            digitalWrite (4, HIGH);
            Salvar_dosadora_EEPROM();
          }         
        }
      }
      break;

    case 29:   // ----------------------------------------- Config dosagem personalizada --------------------------------------
      if ((x>=menU[0]* fator_escala_x) && (x<=menU[2]* fator_escala_x) && (y>=menU[1]* fator_escala_y) && (y<=menU[3] * fator_escala_y))           // volta ao menu
      {
        waitForIt(menU[0], menU[1], menU[2], menU[3]);
        dispScreen = 1;
        clearScreen();
        menuScreen(); 
      }
      if ((x>=volT[0]* fator_escala_x) && (x<=volT[2]* fator_escala_x) && (y>=volT[1]* fator_escala_y) && (y<=volT[3] * fator_escala_y))           // Volta a tela altera configuracao das dosadoras
      {
        waitForIt(volT[0], volT[1], volT[2], volT[3]);
        dispScreen = 21;
        clearScreen();
        selecionar_dosadora();
        setFont(SMALL, 255, 255, 255, 0, 0, 0);
        myGLCD.print(tabela_textos[171], 15, 220);
        modo_manual = false;
        modo_automatico = false;
        modo_personalizado = true;
        modo_calibrar = false;
        dosadora_1_selecionada = false;
        dosadora_2_selecionada = false;
        dosadora_3_selecionada = false; 
      }
      if ((y >= proX[1]* fator_escala_y) && (y <= proX[3]) && (x >= proX[0]* fator_escala_x) && (x <= proX[2]* fator_escala_x)) {
        waitForIt(proX[0], proX[1], proX[2], proX[3]); //Próximo menu.
        dispScreen = 31;
        clearScreen();
        config_dosagem_personalizada_2(true);
      }
      if(dosadora_1_selecionada == true)
      {
        if ((y >= houU[1]* fator_escala_y) && (y <= houU[3] * fator_escala_y)) // Buttons: Time UP
        {
          if ((x >= houU[0]* fator_escala_x) && (x <= houU[2]* fator_escala_x)) {
            waitForIt(houU[0], houU[1], houU[2], houU[3]);
            temp2hora_inicial_dosagem_personalizada_1 = (temp2hora_inicial_dosagem_personalizada_1 + 1) % 24;
            config_dosagem_personalizada();
          } 
          if ((x >= minUT[0]* fator_escala_x) && (x <= minUT[2]* fator_escala_x)) {
            waitForIt(minUT[0], minUT[1], minUT[2], minUT[3]);
            temp2minuto_inicial_dosagem_personalizada_1 = (temp2minuto_inicial_dosagem_personalizada_1 + 1) % 60;
            config_dosagem_personalizada();
          } 


          if ((x >= houU[0] + deslocamento_botao_x) && (x <= houU[2] + deslocamento_botao_x)) {
            waitForIt(houU[0] + deslocamento_botao_x, houU[1], houU[2] + deslocamento_botao_x, houU[3]);
            temp2hora_final_dosagem_personalizada_1 = (temp2hora_final_dosagem_personalizada_1 + 1) % 24;
            config_dosagem_personalizada();
          } 
          if ((x >= minUT[0] + deslocamento_botao_x) && (x <= minUT[2] + deslocamento_botao_x)) {
            waitForIt(minUT[0] + deslocamento_botao_x, minUT[1], minUT[2] + deslocamento_botao_x, minUT[3]);
            temp2minuto_final_dosagem_personalizada_1 = (temp2minuto_final_dosagem_personalizada_1 + 1) % 60;
            config_dosagem_personalizada();
          }

        } 
        if ((y >= houD[1]* fator_escala_y) && (y <= houD[3] * fator_escala_y)) // Buttons: Time DOWN
        {
          if ((x >= houD[0]* fator_escala_x) && (x <= houD[2]* fator_escala_x)) {
            waitForIt(houD[0], houD[1], houD[2], houD[3]);
            temp2hora_inicial_dosagem_personalizada_1 = (temp2hora_inicial_dosagem_personalizada_1 + 23) % 24;
            config_dosagem_personalizada();
          } 
          if ((x >= minDT[0]* fator_escala_x) && (x <= minDT[2]* fator_escala_x)) {
            waitForIt(minDT[0], minDT[1], minDT[2], minDT[3]);
            temp2minuto_inicial_dosagem_personalizada_1 = (temp2minuto_inicial_dosagem_personalizada_1 + 59) % 60;
            config_dosagem_personalizada();
          } 

          if ((x >= houD[0] + deslocamento_botao_x) && (x <= houD[2] + deslocamento_botao_x)) {
            waitForIt(houD[0] + deslocamento_botao_x, houD[1], houD[2] + deslocamento_botao_x, houD[3]);
            temp2hora_final_dosagem_personalizada_1 = (temp2hora_final_dosagem_personalizada_1 + 23) % 24;
            config_dosagem_personalizada();
          } 
          if ((x >= minDT[0] + deslocamento_botao_x) && (x <= minDT[2] + deslocamento_botao_x)) {
            waitForIt(minDT[0] + deslocamento_botao_x, minDT[1], minDT[2] + deslocamento_botao_x, minDT[3]);
            temp2minuto_final_dosagem_personalizada_1 = (temp2minuto_final_dosagem_personalizada_1 + 59) % 60;
            config_dosagem_personalizada();
          }
        }

        if ((x >= segU[0]* fator_escala_x) && (x <= segU[2]* fator_escala_x) && (y >= segU[1]* fator_escala_y) && (y <= segU[3] * fator_escala_y)) {
          if (temp2segunda_dosagem_personalizada_1 == 1) {
            temp2segunda_dosagem_personalizada_1 = 0;
            config_dosagem_personalizada();
          } 
          else {
            temp2segunda_dosagem_personalizada_1 = 1;
            config_dosagem_personalizada();
          }
        }
        if ((x >= terC[0]* fator_escala_x) && (x <= terC[2]* fator_escala_x) && (y >= terC[1]* fator_escala_y) && (y <= terC[3] * fator_escala_y)) {
          if (temp2terca_dosagem_personalizada_1 == 2) {
            temp2terca_dosagem_personalizada_1 = 0;
            config_dosagem_personalizada();
          } 
          else {
            temp2terca_dosagem_personalizada_1 = 2;
            config_dosagem_personalizada();
          }
        }
        if ((x >= quaR[0]* fator_escala_x) && (x <= quaR[2]* fator_escala_x) && (y >= quaR[1]* fator_escala_y) && (y <= quaR[3] * fator_escala_y)) {

          if (temp2quarta_dosagem_personalizada_1 == 3) {
            temp2quarta_dosagem_personalizada_1 = 0;
            config_dosagem_personalizada();
          } 
          else {
            temp2quarta_dosagem_personalizada_1 = 3;
            config_dosagem_personalizada();
          }
        }
        if ((x >= quiN[0]* fator_escala_x) && (x <= quiN[2]* fator_escala_x) && (y >= quiN[1]* fator_escala_y) && (y <= quiN[3] * fator_escala_y)) {

          if (temp2quinta_dosagem_personalizada_1 == 4) {
            temp2quinta_dosagem_personalizada_1 = 0;
            config_dosagem_personalizada();
          } 
          else {
            temp2quinta_dosagem_personalizada_1 = 4;
            config_dosagem_personalizada();
          }
        }
        if ((x >= sexT[0]* fator_escala_x) && (x <= sexT[2]* fator_escala_x) && (y >= sexT[1]* fator_escala_y) && (y <= sexT[3] * fator_escala_y)) {
          if (temp2sexta_dosagem_personalizada_1 == 5) {
            temp2sexta_dosagem_personalizada_1 = 0;
            config_dosagem_personalizada();
          } 
          else {
            temp2sexta_dosagem_personalizada_1 = 5;
            config_dosagem_personalizada();
          }
        }
        if ((x >= sabA[0]* fator_escala_x) && (x <= sabA[2]* fator_escala_x) && (y >= sabA[1]* fator_escala_y) && (y <= sabA[3] * fator_escala_y)) {
          if (temp2sabado_dosagem_personalizada_1 == 6) {
            temp2sabado_dosagem_personalizada_1 = 0;
            config_dosagem_personalizada();
          } 
          else {
            temp2sabado_dosagem_personalizada_1 = 6;
            config_dosagem_personalizada();
          }
        }
        if ((x >= domI[0]* fator_escala_x) && (x <= domI[2]* fator_escala_x) && (y >= domI[1]* fator_escala_y) && (y <= domI[3] * fator_escala_y)) {
          if (temp2domingo_dosagem_personalizada_1 == 7) {
            temp2domingo_dosagem_personalizada_1 = 0;
            config_dosagem_personalizada();
          } 
          else {
            temp2domingo_dosagem_personalizada_1 = 7;
            config_dosagem_personalizada();
          }
        }
      }
      if(dosadora_2_selecionada == true)
      {
        if ((y >= houU[1]* fator_escala_y) && (y <= houU[3] * fator_escala_y)) // Buttons: Time UP
        {
          if ((x >= houU[0]* fator_escala_x) && (x <= houU[2]* fator_escala_x)) {
            waitForIt(houU[0], houU[1], houU[2], houU[3]);
            temp2hora_inicial_dosagem_personalizada_2 = (temp2hora_inicial_dosagem_personalizada_2 + 1) % 24;
            config_dosagem_personalizada();
          } 
          if ((x >= minUT[0]* fator_escala_x) && (x <= minUT[2]* fator_escala_x)) {
            waitForIt(minUT[0], minUT[1], minUT[2], minUT[3]);
            temp2minuto_inicial_dosagem_personalizada_2 = (temp2minuto_inicial_dosagem_personalizada_2 + 1) % 60;
            config_dosagem_personalizada();
          } 


          if ((x >= houU[0] + deslocamento_botao_x) && (x <= houU[2] + deslocamento_botao_x)) {
            waitForIt(houU[0] + deslocamento_botao_x, houU[1], houU[2] + deslocamento_botao_x, houU[3]);
            temp2hora_final_dosagem_personalizada_2 = (temp2hora_final_dosagem_personalizada_2 + 1) % 24;
            config_dosagem_personalizada();
          } 
          if ((x >= minUT[0] + deslocamento_botao_x) && (x <= minUT[2] + deslocamento_botao_x)) {
            waitForIt(minUT[0] + deslocamento_botao_x, minUT[1], minUT[2] + deslocamento_botao_x, minUT[3]);
            temp2minuto_final_dosagem_personalizada_2 = (temp2minuto_final_dosagem_personalizada_2 + 1) % 60;
            config_dosagem_personalizada();
          }

        } 
        if ((y >= houD[1]* fator_escala_y) && (y <= houD[3] * fator_escala_y)) // Buttons: Time DOWN
        {
          if ((x >= houD[0]* fator_escala_x) && (x <= houD[2]* fator_escala_x)) {
            waitForIt(houD[0], houD[1], houD[2], houD[3]);
            temp2hora_inicial_dosagem_personalizada_2 = (temp2hora_inicial_dosagem_personalizada_2 + 23) % 24;
            config_dosagem_personalizada();
          } 
          if ((x >= minDT[0]* fator_escala_x) && (x <= minDT[2]* fator_escala_x)) {
            waitForIt(minDT[0], minDT[1], minDT[2], minDT[3]);
            temp2minuto_inicial_dosagem_personalizada_2 = (temp2minuto_inicial_dosagem_personalizada_2 + 59) % 60;
            config_dosagem_personalizada();
          } 

          if ((x >= houD[0] + deslocamento_botao_x) && (x <= houD[2] + deslocamento_botao_x)) {
            waitForIt(houD[0] + deslocamento_botao_x, houD[1], houD[2] + deslocamento_botao_x, houD[3]);
            temp2hora_final_dosagem_personalizada_2 = (temp2hora_final_dosagem_personalizada_2 + 23) % 24;
            config_dosagem_personalizada();
          } 
          if ((x >= minDT[0] + deslocamento_botao_x) && (x <= minDT[2] + deslocamento_botao_x)) {
            waitForIt(minDT[0] + deslocamento_botao_x, minDT[1], minDT[2] + deslocamento_botao_x, minDT[3]);
            temp2minuto_final_dosagem_personalizada_2 = (temp2minuto_final_dosagem_personalizada_2 + 59) % 60;
            config_dosagem_personalizada();
          }
        }

        if ((x >= segU[0]* fator_escala_x) && (x <= segU[2]* fator_escala_x) && (y >= segU[1]* fator_escala_y) && (y <= segU[3] * fator_escala_y)) {
          if (temp2segunda_dosagem_personalizada_2 == 1) {
            temp2segunda_dosagem_personalizada_2 = 0;
            config_dosagem_personalizada();
          } 
          else {
            temp2segunda_dosagem_personalizada_2 = 1;
            config_dosagem_personalizada();
          }
        }
        if ((x >= terC[0]* fator_escala_x) && (x <= terC[2]* fator_escala_x) && (y >= terC[1]* fator_escala_y) && (y <= terC[3] * fator_escala_y)) {
          if (temp2terca_dosagem_personalizada_2 == 2) {
            temp2terca_dosagem_personalizada_2 = 0;
            config_dosagem_personalizada();
          } 
          else {
            temp2terca_dosagem_personalizada_2 = 2;
            config_dosagem_personalizada();
          }
        }
        if ((x >= quaR[0]* fator_escala_x) && (x <= quaR[2]* fator_escala_x) && (y >= quaR[1]* fator_escala_y) && (y <= quaR[3] * fator_escala_y)) {

          if (temp2quarta_dosagem_personalizada_2 == 3) {
            temp2quarta_dosagem_personalizada_2 = 0;
            config_dosagem_personalizada();
          } 
          else {
            temp2quarta_dosagem_personalizada_2 = 3;
            config_dosagem_personalizada();
          }
        }
        if ((x >= quiN[0]* fator_escala_x) && (x <= quiN[2]* fator_escala_x) && (y >= quiN[1]* fator_escala_y) && (y <= quiN[3] * fator_escala_y)) {

          if (temp2quinta_dosagem_personalizada_2 == 4) {
            temp2quinta_dosagem_personalizada_2 = 0;
            config_dosagem_personalizada();
          } 
          else {
            temp2quinta_dosagem_personalizada_2 = 4;
            config_dosagem_personalizada();
          }
        }
        if ((x >= sexT[0]* fator_escala_x) && (x <= sexT[2]* fator_escala_x) && (y >= sexT[1]* fator_escala_y) && (y <= sexT[3] * fator_escala_y)) {
          if (temp2sexta_dosagem_personalizada_2 == 5) {
            temp2sexta_dosagem_personalizada_2 = 0;
            config_dosagem_personalizada();
          } 
          else {
            temp2sexta_dosagem_personalizada_2 = 5;
            config_dosagem_personalizada();
          }
        }
        if ((x >= sabA[0]* fator_escala_x) && (x <= sabA[2]* fator_escala_x) && (y >= sabA[1]* fator_escala_y) && (y <= sabA[3] * fator_escala_y)) {
          if (temp2sabado_dosagem_personalizada_2 == 6) {
            temp2sabado_dosagem_personalizada_2 = 0;
            config_dosagem_personalizada();
          } 
          else {
            temp2sabado_dosagem_personalizada_2 = 6;
            config_dosagem_personalizada();
          }
        }
        if ((x >= domI[0]* fator_escala_x) && (x <= domI[2]* fator_escala_x) && (y >= domI[1]* fator_escala_y) && (y <= domI[3] * fator_escala_y)) {
          if (temp2domingo_dosagem_personalizada_2 == 7) {
            temp2domingo_dosagem_personalizada_2 = 0;
            config_dosagem_personalizada();
          } 
          else {
            temp2domingo_dosagem_personalizada_2 = 7;
            config_dosagem_personalizada();
          }
        }
      }
      if(dosadora_3_selecionada == true)
      {
        if ((y >= houU[1]* fator_escala_y) && (y <= houU[3] * fator_escala_y)) // Buttons: Time UP
        {
          if ((x >= houU[0]* fator_escala_x) && (x <= houU[2]* fator_escala_x)) {
            waitForIt(houU[0], houU[1], houU[2], houU[3]);
            temp2hora_inicial_dosagem_personalizada_3 = (temp2hora_inicial_dosagem_personalizada_3 + 1) % 24;
            config_dosagem_personalizada();
          } 
          if ((x >= minUT[0]* fator_escala_x) && (x <= minUT[2]* fator_escala_x)) {
            waitForIt(minUT[0], minUT[1], minUT[2], minUT[3]);
            temp2minuto_inicial_dosagem_personalizada_3 = (temp2minuto_inicial_dosagem_personalizada_3 + 1) % 60;
            config_dosagem_personalizada();
          } 


          if ((x >= houU[0] + deslocamento_botao_x) && (x <= houU[2] + deslocamento_botao_x)) {
            waitForIt(houU[0] + deslocamento_botao_x, houU[1], houU[2] + deslocamento_botao_x, houU[3]);
            temp2hora_final_dosagem_personalizada_3 = (temp2hora_final_dosagem_personalizada_3 + 1) % 24;
            config_dosagem_personalizada();
          } 
          if ((x >= minUT[0] + deslocamento_botao_x) && (x <= minUT[2] + deslocamento_botao_x)) {
            waitForIt(minUT[0] + deslocamento_botao_x, minUT[1], minUT[2] + deslocamento_botao_x, minUT[3]);
            temp2minuto_final_dosagem_personalizada_3 = (temp2minuto_final_dosagem_personalizada_3 + 1) % 60;
            config_dosagem_personalizada();
          }

        } 
        if ((y >= houD[1]* fator_escala_y) && (y <= houD[3] * fator_escala_y)) // Buttons: Time DOWN
        {
          if ((x >= houD[0]* fator_escala_x) && (x <= houD[2]* fator_escala_x)) {
            waitForIt(houD[0], houD[1], houD[2], houD[3]);
            temp2hora_inicial_dosagem_personalizada_3 = (temp2hora_inicial_dosagem_personalizada_3 + 23) % 24;
            config_dosagem_personalizada();
          } 
          if ((x >= minDT[0]* fator_escala_x) && (x <= minDT[2]* fator_escala_x)) {
            waitForIt(minDT[0], minDT[1], minDT[2], minDT[3]);
            temp2minuto_inicial_dosagem_personalizada_3 = (temp2minuto_inicial_dosagem_personalizada_3 + 59) % 60;
            config_dosagem_personalizada();
          } 

          if ((x >= houD[0] + deslocamento_botao_x) && (x <= houD[2] + deslocamento_botao_x)) {
            waitForIt(houD[0] + deslocamento_botao_x, houD[1], houD[2] + deslocamento_botao_x, houD[3]);
            temp2hora_final_dosagem_personalizada_3 = (temp2hora_final_dosagem_personalizada_3 + 23) % 24;
            config_dosagem_personalizada();
          } 
          if ((x >= minDT[0] + deslocamento_botao_x) && (x <= minDT[2] + deslocamento_botao_x)) {
            waitForIt(minDT[0] + deslocamento_botao_x, minDT[1], minDT[2] + deslocamento_botao_x, minDT[3]);
            temp2minuto_final_dosagem_personalizada_3 = (temp2minuto_final_dosagem_personalizada_3 + 59) % 60;
            config_dosagem_personalizada();
          }
        }

        if ((x >= segU[0]* fator_escala_x) && (x <= segU[2]* fator_escala_x) && (y >= segU[1]* fator_escala_y) && (y <= segU[3] * fator_escala_y)) {
          if (temp2segunda_dosagem_personalizada_3 == 1) {
            temp2segunda_dosagem_personalizada_3 = 0;
            config_dosagem_personalizada();
          } 
          else {
            temp2segunda_dosagem_personalizada_3 = 1;
            config_dosagem_personalizada();
          }
        }
        if ((x >= terC[0]* fator_escala_x) && (x <= terC[2]* fator_escala_x) && (y >= terC[1]* fator_escala_y) && (y <= terC[3] * fator_escala_y)) {
          if (temp2terca_dosagem_personalizada_3 == 2) {
            temp2terca_dosagem_personalizada_3 = 0;
            config_dosagem_personalizada();
          } 
          else {
            temp2terca_dosagem_personalizada_3 = 2;
            config_dosagem_personalizada();
          }
        }
        if ((x >= quaR[0]* fator_escala_x) && (x <= quaR[2]* fator_escala_x) && (y >= quaR[1]* fator_escala_y) && (y <= quaR[3] * fator_escala_y)) {

          if (temp2quarta_dosagem_personalizada_3 == 3) {
            temp2quarta_dosagem_personalizada_3 = 0;
            config_dosagem_personalizada();
          } 
          else {
            temp2quarta_dosagem_personalizada_3 = 3;
            config_dosagem_personalizada();
          }
        }
        if ((x >= quiN[0]* fator_escala_x) && (x <= quiN[2]* fator_escala_x) && (y >= quiN[1]* fator_escala_y) && (y <= quiN[3] * fator_escala_y)) {

          if (temp2quinta_dosagem_personalizada_3 == 4) {
            temp2quinta_dosagem_personalizada_3 = 0;
            config_dosagem_personalizada();
          } 
          else {
            temp2quinta_dosagem_personalizada_3 = 4;
            config_dosagem_personalizada();
          }
        }
        if ((x >= sexT[0]* fator_escala_x) && (x <= sexT[2]* fator_escala_x) && (y >= sexT[1]* fator_escala_y) && (y <= sexT[3] * fator_escala_y)) {
          if (temp2sexta_dosagem_personalizada_3 == 5) {
            temp2sexta_dosagem_personalizada_3 = 0;
            config_dosagem_personalizada();
          } 
          else {
            temp2sexta_dosagem_personalizada_3 = 5;
            config_dosagem_personalizada();
          }
        }
        if ((x >= sabA[0]* fator_escala_x) && (x <= sabA[2]* fator_escala_x) && (y >= sabA[1]* fator_escala_y) && (y <= sabA[3] * fator_escala_y)) {
          if (temp2sabado_dosagem_personalizada_3 == 6) {
            temp2sabado_dosagem_personalizada_3 = 0;
            config_dosagem_personalizada();
          } 
          else {
            temp2sabado_dosagem_personalizada_3 = 6;
            config_dosagem_personalizada();
          }
        }
        if ((x >= domI[0]* fator_escala_x) && (x <= domI[2]* fator_escala_x) && (y >= domI[1]* fator_escala_y) && (y <= domI[3] * fator_escala_y)) {
          if (temp2domingo_dosagem_personalizada_3 == 7) {
            temp2domingo_dosagem_personalizada_3 = 0;
            config_dosagem_personalizada();
          } 
          else {
            temp2domingo_dosagem_personalizada_3 = 7;
            config_dosagem_personalizada();
          }
        }
      }
      break;

    case 30:  // ----------------------------------------- Digitar a senha --------------------------------------------

      if ((x>=boT1[0]* fator_escala_x) && (x<=boT1[2]* fator_escala_x) && (y>=boT1[1]* fator_escala_y) && (y<=boT1[3] * fator_escala_y))  // Botao: 1
      {
        waitForIt(boT1[0], boT1[1], boT1[2] ,boT1[3]);
        updateStr('1');
      }

      if ((x>=boT2[0]* fator_escala_x) && (x<=boT2[2]* fator_escala_x) && (y>=boT2[1]* fator_escala_y) && (y<=boT2[3] * fator_escala_y))  // Botao: 2
      {
        waitForIt(boT2[0], boT2[1], boT2[2], boT2[3]);
        updateStr('2');
      }
      if ((x>=boT3[0]* fator_escala_x) && (x<=boT3[2]* fator_escala_x) && (y>=boT3[1]* fator_escala_y) && (y<=boT3[3] * fator_escala_y))  // Botao: 3
      {
        waitForIt(boT3[0], boT3[1], boT3[2], boT3[3]);
        updateStr('3');
      }
      if ((x>=boT4[0]* fator_escala_x) && (x<=boT4[2]* fator_escala_x) && (y>=boT4[1]* fator_escala_y) && (y<=boT4[3] * fator_escala_y))  // Botao: 4
      {
        waitForIt(boT4[0], boT4[1], boT4[2], boT4[3]);
        updateStr('4');
      }
      if ((x>=boT5[0]* fator_escala_x) && (x<=boT5[2]* fator_escala_x) && (y>=boT5[1]* fator_escala_y) && (y<=boT5[3] * fator_escala_y))  // Botao: 5
      {
        waitForIt(boT5[0], boT5[1], boT5[2], boT5[3]);
        updateStr('5');
      }

      if ((x>=boT6[0]* fator_escala_x) && (x<=boT6[2]* fator_escala_x) && (y>=boT6[1]* fator_escala_y) && (y<=boT6[3] * fator_escala_y))  // Botao: 6
      {
        waitForIt(boT6[0], boT6[1], boT6[2], boT6[3]);
        updateStr('6');
      }
      if ((x>=boT7[0]* fator_escala_x) && (x<=boT7[2]* fator_escala_x) && (y>=boT7[1]* fator_escala_y) && (y<=boT7[3] * fator_escala_y))  // Botao: 7
      {
        waitForIt(boT7[0], boT7[1], boT7[2], boT7[3]);
        updateStr('7');
      }
      if ((x>=boT8[0]* fator_escala_x) && (x<=boT8[2]* fator_escala_x) && (y>=boT8[1]* fator_escala_y) && (y<=boT8[3] * fator_escala_y))  // Botao: 8
      {
        waitForIt(boT8[0], boT8[1], boT8[2], boT8[3]);
        updateStr('8');
      }
      if ((x>=boT9[0]* fator_escala_x) && (x<=boT9[2]* fator_escala_x) && (y>=boT9[1]* fator_escala_y) && (y<=boT9[3] * fator_escala_y))  // Botao: 9
      {
        waitForIt(boT9[0], boT9[1], boT9[2], boT9[3]);
        updateStr('9');
      }
      if ((x>=boT0[0]* fator_escala_x) && (x<=boT0[2]* fator_escala_x) && (y>=boT0[1]* fator_escala_y) && (y<=boT0[3] * fator_escala_y))  // Botao: 0
      {
        waitForIt(boT0[0], boT0[1], boT0[2], boT0[3]);
        updateStr('0');
      }

      if ((x>=boTL[0]* fator_escala_x) && (x<=boTL[2]* fator_escala_x) && (y>=boTL[1]* fator_escala_y) && (y<=boTL[3] * fator_escala_y))  // Botao: limpar
      {
        waitForIt(boTL[0], boTL[1], boTL[2], boTL[3]);
        for (int i=0; i < 7;i++) stCurrent[i] = '\0';
        stCurrentLen=0;
        myGLCD.setColor(0, 0, 0);
        myGLCD.fillRect (110, 210, 300, 225); //Limpar senha impressa ***************
      }
      if ((x>=boTE[0]* fator_escala_x) && (x<=boTE[2]* fator_escala_x) && (y>=boTE[1]* fator_escala_y) && (y<=boTE[3] * fator_escala_y))  // Botao: entrar
      {
        waitForIt(boTE[0], boTE[1], boTE[2], boTE[3]);
        if ((stCurrent[0] == senha [0]) && (stCurrent[1] == senha [1]) && (stCurrent[2] == senha [2]) && (stCurrent[3] == senha [3]) && (stCurrent[4] == senha [4]) && (stCurrent[5] == senha [5]) && stCurrentLen <=6)
        {
          stCurrentLen=0;
          myGLCD.setFont(BigFont);
          myGLCD.setColor(0, 255, 0);
          myGLCD.setBackColor(0, 0, 0);
          myGLCD.print(tabela_textos[173], 51, 192); // tabela_textos[173] = "SENHA CORRETA"
          delay(500);
          dispScreen=1;
          clearScreen();
          menuScreen();
          memcpy(stCurrent, limpar_senha, sizeof(limpar_senha));
        }

        else if(stCurrentLen <=6)
        {
          myGLCD.setFont(BigFont);
          myGLCD.setColor(255, 0, 0);
          myGLCD.setBackColor(0, 0, 0);
          myGLCD.print(tabela_textos[174], 35, 192); // tabela_textos[173] = "SENHA INCORRETA!"
          delay(500);
          myGLCD.setColor(0, 0, 0);
          myGLCD.fillRect (35, 192, 300, 207);
          delay(500);            
          myGLCD.setColor(255, 0, 0);
          myGLCD.print(tabela_textos[174], 35, 192);
          delay(500);
          myGLCD.setColor(0, 0, 0);
          myGLCD.fillRect (35, 192, 300, 207);
          delay(500);
          myGLCD.setColor(255, 0, 0);
          myGLCD.print(tabela_textos[174], 35, 192);
          delay(500);
          myGLCD.setColor(0, 0, 0);
          myGLCD.fillRect (35, 192, 300, 207);
          myGLCD.fillRect (110, 210, 300, 225); //Limpar senha impressa ***************
          stCurrentLen=0;
          memcpy(stCurrent, limpar_senha, sizeof(limpar_senha));
        }
        else if(stCurrentLen > 6)
        {
          myGLCD.setFont(BigFont);
          myGLCD.setColor(255, 0, 0);
          myGLCD.setBackColor(0, 0, 0);
          myGLCD.print(tabela_textos[174], 35, 192);
          delay(500);
          myGLCD.setColor(0, 0, 0);
          myGLCD.fillRect (35, 192, 300, 207);
          delay(500);
          myGLCD.setColor(255, 0, 0);          
          myGLCD.print(tabela_textos[175], 35, 192); // "MAXIMO 6 DIGITOS!"
          delay(1000);
          myGLCD.setColor(0, 0, 0);
          myGLCD.fillRect (35, 192, 300, 207);
          delay(500);
          myGLCD.setColor(255, 0, 0);
          myGLCD.print(tabela_textos[174], 35, 192);
          delay(500);
          myGLCD.setColor(0, 0, 0);
          myGLCD.fillRect (35, 192, 300, 207);
          delay(500);
          myGLCD.setColor(255, 0, 0);          
          myGLCD.print(tabela_textos[175], 35, 192);
          delay(1000);
          myGLCD.setColor(0, 0, 0);
          myGLCD.fillRect (35, 192, 300, 207);
          myGLCD.fillRect (110, 210, 300, 225); //Limpar senha impressa ***************
          stCurrentLen=0;
          memcpy(stCurrent, limpar_senha, sizeof(limpar_senha));
        }
      }
      break;
    case 31:// ----------------------------------------- Dosagem personalizada --------------------------------------------
      if ((x>=menU[0]* fator_escala_x) && (x<=menU[2]* fator_escala_x) && (y>=menU[1]* fator_escala_y) && (y<=menU[3] * fator_escala_y))           // volta ao menu
      {
        waitForIt(menU[0], menU[1], menU[2], menU[3]);
        dispScreen = 1;
        clearScreen();
        menuScreen(); 
      }
      if ((y >= anT[1]* fator_escala_y) && (y <= anT[3]) && (x >= anT[0]* fator_escala_x) && (x <= anT[2]* fator_escala_x)) // Volta ao menu dosagem personalizada
      {
        waitForIt(anT[0], anT[1], anT[2], anT[3]);
        dispScreen = 29;
        clearScreen();
        config_dosagem_personalizada(true);
      }
      if(dosadora_1_selecionada == true)
      {
        if ((x >= minUT[0]* fator_escala_x) && (x <= minUT[2]* fator_escala_x) && (y >= minUT[1]* fator_escala_y) && (y <= minUT[3] * fator_escala_y)) // Dose diaria mais
        {
          waitForIt(minUT[0], minUT[1], minUT[2], minUT[3]);
          dose_dosadora_1_personalizada_temp2 += 0.5;
          if(dose_dosadora_1_personalizada_temp2 > 999.5)
          {
            dose_dosadora_1_personalizada_temp2 = 0.5;
          }
          if(dose_dosadora_1_personalizada_temp2 <= 9.5)
          {
            myGLCD.setColor(0, 0, 0);                      
            myGLCD.fillRect(100, 45, 185, 67);
          }           

          config_dosagem_personalizada_2();
        }
        if ((x >= minDT[0]* fator_escala_x) && (x <= minDT[2]* fator_escala_x) && (y >= minDT[1]* fator_escala_y) && (y <= minDT[3] * fator_escala_y)) // Dose diaria menos
        {
          waitForIt(minDT[0], minDT[1], minDT[2], minDT[3]);
          dose_dosadora_1_personalizada_temp2 -= 0.5;
          if(dose_dosadora_1_personalizada_temp2 <0.5)
          {
            dose_dosadora_1_personalizada_temp2 = 999.5;
          }
          if(dose_dosadora_1_personalizada_temp2 <= 9.5)
          {
            myGLCD.setColor(0, 0, 0);                      
            myGLCD.fillRect(100, 45, 185, 67);
          }
          config_dosagem_personalizada_2();
        }
        if ((x >= durC[0]* fator_escala_x) && (x <= durC[2]* fator_escala_x) && (y >= durC[1]* fator_escala_y) && (y <= durC[3] * fator_escala_y)) 
        {
          waitForIt(durC[0], durC[1], durC[2], durC[3]); 
          quantidade_dose_dosadora_1_personalizada_temp2 += 1;
          if(quantidade_dose_dosadora_1_personalizada_temp2 > 24)
          {
            quantidade_dose_dosadora_1_personalizada_temp2 = 1;
          }
          config_dosagem_personalizada_2();
        }

        if ((x >= durB[0]* fator_escala_x) && (x <= durB[2]* fator_escala_x) && (y >= durB[1]* fator_escala_y) && (y <= durB[3] * fator_escala_y)) 
        {
          waitForIt(durB[0], durB[1], durB[2], durB[3]);
          quantidade_dose_dosadora_1_personalizada_temp2 -= 1;
          if(quantidade_dose_dosadora_1_personalizada_temp2 < 1)
          {
            quantidade_dose_dosadora_1_personalizada_temp2 = 24;
          }
          config_dosagem_personalizada_2();        
        }
        if ((x >= sexT[0]* fator_escala_x) && (x<= sexT[2]* fator_escala_x) && (y >= sexT [1]* fator_escala_y) && (y <= sexT[3] * fator_escala_y)) // Ativar ou desativar modo personalizado
        {
          waitForIt(sexT[0], sexT[1], sexT[2], sexT[3]);
          if(modo_personalizado_on_1_temp2 == 0)
          {
            modo_personalizado_on_1_temp2 = 1;
            modo_automatico_on_1_temp2 = 0;
            config_dosagem_personalizada_2();
          }
          else
          {
            modo_personalizado_on_1_temp2 = 0;
            modo_automatico_on_1_temp2 = 1;
            config_dosagem_personalizada_2();
          }
        }
        if ((y >= prOK[1]* fator_escala_y) && (y <= prOK[3]) && (x >= prOK[0]* fator_escala_x) && (x <= prOK[2]* fator_escala_x)) 
        {
          waitForIt(prOK[0], prOK[1], prOK[2], prOK[3]); //funcao salvar
          dose_dosadora_1_personalizada = dose_dosadora_1_personalizada_temp2;
          quantidade_dose_dosadora_1_personalizada = quantidade_dose_dosadora_1_personalizada_temp2;
          modo_personalizado_on_1 = modo_personalizado_on_1_temp2;
          modo_automatico_on_1 = modo_automatico_on_1_temp2;
          hora_inicial_dosagem_personalizada_1 = temp2hora_inicial_dosagem_personalizada_1;
          minuto_inicial_dosagem_personalizada_1 = temp2minuto_inicial_dosagem_personalizada_1;
          hora_final_dosagem_personalizada_1 = temp2hora_final_dosagem_personalizada_1;
          minuto_final_dosagem_personalizada_1 = temp2minuto_final_dosagem_personalizada_1;
          segunda_dosagem_personalizada_1 = temp2segunda_dosagem_personalizada_1;
          terca_dosagem_personalizada_1 = temp2terca_dosagem_personalizada_1;
          quarta_dosagem_personalizada_1 = temp2quarta_dosagem_personalizada_1;
          quinta_dosagem_personalizada_1 = temp2quinta_dosagem_personalizada_1;
          sexta_dosagem_personalizada_1 = temp2sexta_dosagem_personalizada_1;
          sabado_dosagem_personalizada_1 = temp2sabado_dosagem_personalizada_1;
          domingo_dosagem_personalizada_1 = temp2domingo_dosagem_personalizada_1;

          if((hora_final_dosagem_personalizada_1 == hora_inicial_dosagem_personalizada_1) && (minuto_final_dosagem_personalizada_1 < (minuto_inicial_dosagem_personalizada_1+10)))
          {
            setFont(SMALL, 255, 0, 0, 0, 0, 0);
            myGLCD.print(tabela_textos[176], 20, 110); // "O INTERVALO ENTRE A INICIAL E A FINAL"
            myGLCD.print(tabela_textos[177], 35, 130);

          }
          if(hora_final_dosagem_personalizada_1 < hora_inicial_dosagem_personalizada_1)
          {
            setFont(SMALL, 255, 0, 0, 0, 0, 0);
            myGLCD.print(tabela_textos[178], 50, 110);
            myGLCD.print(tabela_textos[179], 100, 130);
          }

          if((temp2hora_final_dosagem_personalizada_1 == hora_inicial_dosagem_personalizada_1) && (temp2minuto_final_dosagem_personalizada_1 >= (minuto_inicial_dosagem_personalizada_1+10)))
          {
            dispScreen =21;
            clearScreen();
            selecionar_dosadora();
            setFont(SMALL, 255, 255, 255, 0, 0, 0);
            myGLCD.print(tabela_textos[171], 15, 220); // tabela_textos[171] = "MODO PERSONALIZADO SELECIONADO"
            modo_manual = false;
            modo_automatico = false;
            modo_personalizado = true;
            modo_calibrar = false;
            dosadora_1_selecionada = false;
            dosadora_2_selecionada = false;
            dosadora_3_selecionada = false; 
            digitalWrite (4, LOW); 
            file.open(&root, "HDP1.TXT", O_WRITE);
            file.remove();       
            file.open(&root, "HDP1.TXT", O_CREAT | O_APPEND | O_WRITE);

            if((minuto_inicial_dosagem_personalizada_1 == minuto_inicial_dosagem_personalizada_2) || (minuto_inicial_dosagem_personalizada_1 == minuto_inicial_dosagem_personalizada_3))
            {
              minuto_inicial_dosagem_personalizada_1 += 10;
            }
            minuto01 = (((hora_final_dosagem_personalizada_1 * 60) + (minuto_final_dosagem_personalizada_1)) - ((hora_inicial_dosagem_personalizada_1 * 60) + (minuto_inicial_dosagem_personalizada_1))); 
            minuto01 /= 1 + quantidade_dose_dosadora_1_personalizada;

            for(int i = 1; i <= quantidade_dose_dosadora_1_personalizada; i++)
            { 
              contador += 1;  
              if(contador == 1)
              {
                minuto11 = (hora_inicial_dosagem_personalizada_1 * 60) + minuto_inicial_dosagem_personalizada_1 + minuto01;
              }
              if(contador > 1)
              {
                minuto11 += minuto01; 
              }
              if(minuto11 < 10)
              {
                file.print("000");  
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(( minuto11 > 10) && (minuto11 < 100))
              {
                file.print("00");
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(( minuto11 >= 100) && (minuto11 < 1000))
              {
                file.print("0");
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(minuto11 >= 1000)
              {
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
            }
            file.close();  
            contador = 0;
            digitalWrite (4, HIGH);
            Salvar_dosadora_EEPROM(); 
          }    

          if(temp2hora_final_dosagem_personalizada_1 > hora_inicial_dosagem_personalizada_1)
          {
            dispScreen =21;
            clearScreen();
            selecionar_dosadora();
            setFont(SMALL, 255, 255, 255, 0, 0, 0);
            myGLCD.print(tabela_textos[171], 15, 220); // tabela_textos[171] = "MODO PERSONALIZADO SELECIONADO"
            modo_manual = false;
            modo_automatico = false;
            modo_personalizado = true;
            modo_calibrar = false;
            dosadora_1_selecionada = false;
            dosadora_2_selecionada = false;
            dosadora_3_selecionada = false; 
            digitalWrite (4, LOW); 
            file.open(&root, "HDP1.TXT", O_WRITE);
            file.remove();       
            file.open(&root, "HDP1.TXT", O_CREAT | O_APPEND | O_WRITE);

            if((minuto_inicial_dosagem_personalizada_1 == minuto_inicial_dosagem_personalizada_2) || (minuto_inicial_dosagem_personalizada_1 == minuto_inicial_dosagem_personalizada_3))
            {
              minuto_inicial_dosagem_personalizada_1 += 10;
            }
            if(minuto_inicial_dosagem_personalizada_1 >= 60)
            {
              minuto_inicial_dosagem_personalizada_1 -= 60;
              hora_inicial_dosagem_personalizada_1 += 1;
            }
            minuto01 = (((hora_final_dosagem_personalizada_1 * 60) + (minuto_final_dosagem_personalizada_1)) - ((hora_inicial_dosagem_personalizada_1 * 60) + (minuto_inicial_dosagem_personalizada_1))); 
            minuto01 /= 1 + quantidade_dose_dosadora_1_personalizada;

            for(int i = 1; i <= quantidade_dose_dosadora_1_personalizada; i++)
            { 
              contador += 1;  
              if(contador == 1)
              {
                minuto11 = (hora_inicial_dosagem_personalizada_1 * 60) + minuto_inicial_dosagem_personalizada_1 + minuto01;
              }
              if(contador > 1)
              {
                minuto11 += minuto01; 
              }
              if(minuto11 < 10)
              {
                file.print("000");  
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(( minuto11 > 10) && (minuto11 < 100))
              {
                file.print("00");
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(( minuto11 >= 100) && (minuto11 < 1000))
              {
                file.print("0");
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(minuto11 >= 1000)
              {
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
            }
            file.close();  
            contador = 0;
            digitalWrite (4, HIGH);
            Salvar_dosadora_EEPROM();
          }         
        } 
      }      
      if(dosadora_2_selecionada == true)
      {
        if ((x >= minUT[0]* fator_escala_x) && (x <= minUT[2]* fator_escala_x) && (y >= minUT[1]* fator_escala_y) && (y <= minUT[3] * fator_escala_y)) // Dose diaria mais
        {
          waitForIt(minUT[0], minUT[1], minUT[2], minUT[3]);
          dose_dosadora_2_personalizada_temp2 += 0.5;
          if(dose_dosadora_2_personalizada_temp2 > 999.5)
          {
            dose_dosadora_2_personalizada_temp2 = 0.5;
          }
          if(dose_dosadora_2_personalizada_temp2 <= 9.5)
          {
            myGLCD.setColor(0, 0, 0);                      
            myGLCD.fillRect(100, 45, 185, 67);
          }
          config_dosagem_personalizada_2();
        }
        if ((x >= minDT[0]* fator_escala_x) && (x <= minDT[2]* fator_escala_x) && (y >= minDT[1]* fator_escala_y) && (y <= minDT[3] * fator_escala_y)) // Dose diaria menos
        {
          waitForIt(minDT[0], minDT[1], minDT[2], minDT[3]);
          dose_dosadora_2_personalizada_temp2 -= 0.5;
          if(dose_dosadora_2_personalizada_temp2 <0.5)
          {
            dose_dosadora_2_personalizada_temp2 = 999.5;
          }
          if(dose_dosadora_2_personalizada_temp2 <= 9.5)
          {
            myGLCD.setColor(0, 0, 0);                      
            myGLCD.fillRect(100, 45, 185, 67);
          }
          config_dosagem_personalizada_2();
        }
        if ((x >= durC[0]* fator_escala_x) && (x <= durC[2]* fator_escala_x) && (y >= durC[1]* fator_escala_y) && (y <= durC[3] * fator_escala_y)) 
        {
          waitForIt(durC[0], durC[1], durC[2], durC[3]); 
          quantidade_dose_dosadora_2_personalizada_temp2 += 1;
          if(quantidade_dose_dosadora_2_personalizada_temp2 > 24)
          {
            quantidade_dose_dosadora_2_personalizada_temp2 = 1;
          }
          config_dosagem_personalizada_2();
        }

        if ((x >= durB[0]* fator_escala_x) && (x <= durB[2]* fator_escala_x) && (y >= durB[1]* fator_escala_y) && (y <= durB[3] * fator_escala_y)) 
        {
          waitForIt(durB[0], durB[1], durB[2], durB[3]);
          quantidade_dose_dosadora_2_personalizada_temp2 -= 1;
          if(quantidade_dose_dosadora_2_personalizada_temp2 < 1)
          {
            quantidade_dose_dosadora_2_personalizada_temp2 = 24;
          }
          config_dosagem_personalizada_2();        
        }
        if ((x >= sexT[0]* fator_escala_x) && (x<= sexT[2]* fator_escala_x) && (y >= sexT [1]* fator_escala_y) && (y <= sexT[3] * fator_escala_y))
        {
          waitForIt(sexT[0], sexT[1], sexT[2], sexT[3]);
          if(modo_personalizado_on_2_temp2 == 0)
          {
            modo_personalizado_on_2_temp2 = 1;
            modo_automatico_on_2_temp2 = 0;
            config_dosagem_personalizada_2();
          }
          else
          {
            modo_personalizado_on_2_temp2 = 0;
            modo_automatico_on_2_temp2 = 1;
            config_dosagem_personalizada_2();
          }
        }
        if ((y >= prOK[1]* fator_escala_y) && (y <= prOK[3]) && (x >= prOK[0]* fator_escala_x) && (x <= prOK[2]* fator_escala_x)) 
        {
          waitForIt(prOK[0], prOK[1], prOK[2], prOK[3]); //funcao salvar
          dose_dosadora_2_personalizada = dose_dosadora_2_personalizada_temp2;
          quantidade_dose_dosadora_2_personalizada = quantidade_dose_dosadora_2_personalizada_temp2;
          modo_personalizado_on_2 = modo_personalizado_on_2_temp2;
          modo_automatico_on_2 = modo_automatico_on_2_temp2;
          hora_inicial_dosagem_personalizada_2 = temp2hora_inicial_dosagem_personalizada_2;
          minuto_inicial_dosagem_personalizada_2 = temp2minuto_inicial_dosagem_personalizada_2;
          hora_final_dosagem_personalizada_2 = temp2hora_final_dosagem_personalizada_2;
          minuto_final_dosagem_personalizada_2 = temp2minuto_final_dosagem_personalizada_2;
          segunda_dosagem_personalizada_2 = temp2segunda_dosagem_personalizada_2;
          terca_dosagem_personalizada_2 = temp2terca_dosagem_personalizada_2;
          quarta_dosagem_personalizada_2 = temp2quarta_dosagem_personalizada_2;
          quinta_dosagem_personalizada_2 = temp2quinta_dosagem_personalizada_2;
          sexta_dosagem_personalizada_2 = temp2sexta_dosagem_personalizada_2;
          sabado_dosagem_personalizada_2 = temp2sabado_dosagem_personalizada_2;
          domingo_dosagem_personalizada_2 = temp2domingo_dosagem_personalizada_2;

          if((hora_final_dosagem_personalizada_2 == hora_inicial_dosagem_personalizada_2) && (minuto_final_dosagem_personalizada_2 < (minuto_inicial_dosagem_personalizada_2+10)))
          {
            setFont(SMALL, 255, 0, 0, 0, 0, 0);
            myGLCD.print(tabela_textos[176], 20, 110);
            myGLCD.print(tabela_textos[177], 35, 130);
          }
          if(hora_final_dosagem_personalizada_2 < hora_inicial_dosagem_personalizada_2)
          {
            setFont(SMALL, 255, 0, 0, 0, 0, 0);
            myGLCD.print(tabela_textos[178], 50, 110); // "A HORA FINAL NAO PODE SER MENOR"
            myGLCD.print(tabela_textos[179], 100, 130); // tabela_textos[179] = "QUE A INICIAL!"
          }

          if((temp2hora_final_dosagem_personalizada_2 == hora_inicial_dosagem_personalizada_2) && (temp2minuto_final_dosagem_personalizada_2 >= (minuto_inicial_dosagem_personalizada_2+10)))
          {
            dispScreen =21;
            clearScreen();
            selecionar_dosadora();
            setFont(SMALL, 255, 255, 255, 0, 0, 0);
            myGLCD.print(tabela_textos[171], 15, 220); // tabela_textos[171] = "MODO PERSONALIZADO SELECIONADO"
            modo_manual = false;
            modo_automatico = false;
            modo_personalizado = true;
            modo_calibrar = false;
            dosadora_1_selecionada = false;
            dosadora_2_selecionada = false;
            dosadora_3_selecionada = false; 
            digitalWrite (4, LOW); 
            file.open(&root, "HDP2.TXT", O_WRITE);
            file.remove();       
            file.open(&root, "HDP2.TXT", O_CREAT | O_APPEND | O_WRITE);

            minuto01 = (((hora_final_dosagem_personalizada_2 * 60) + (minuto_final_dosagem_personalizada_2)) - ((hora_inicial_dosagem_personalizada_2 * 60) + (minuto_inicial_dosagem_personalizada_2))); 
            minuto01 /= 1 + quantidade_dose_dosadora_2_personalizada;

            for(int i = 1; i <= quantidade_dose_dosadora_2_personalizada; i++)
            { 
              contador += 1;  
              if(contador == 1)
              {
                minuto11 = (hora_inicial_dosagem_personalizada_2 * 60) + minuto_inicial_dosagem_personalizada_2 + minuto01;
              }
              if(contador > 1)
              {
                minuto11 += minuto01; 
              }
              if(minuto11 < 10)
              {
                file.print("000");  
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(( minuto11 > 10) && (minuto11 < 100))
              {
                file.print("00");
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(( minuto11 >= 100) && (minuto11 < 1000))
              {
                file.print("0");
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(minuto11 >= 1000)
              {
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
            }
            file.close();  
            contador = 0;
            digitalWrite (4, HIGH);
            Salvar_dosadora_EEPROM(); 
          }    

          if(temp2hora_final_dosagem_personalizada_2 > hora_inicial_dosagem_personalizada_2)
          {
            dispScreen =21;
            clearScreen();
            selecionar_dosadora();
            setFont(SMALL, 255, 255, 255, 0, 0, 0);
            myGLCD.print(tabela_textos[171], 15, 220); // tabela_textos[171] = "MODO PERSONALIZADO SELECIONADO"
            modo_manual = false;
            modo_automatico = false;
            modo_personalizado = true;
            modo_calibrar = false;
            dosadora_1_selecionada = false;
            dosadora_2_selecionada = false;
            dosadora_3_selecionada = false; 
            digitalWrite (4, LOW); 
            file.open(&root, "HDP2.TXT", O_WRITE);
            file.remove();       
            file.open(&root, "HDP2.TXT", O_CREAT | O_APPEND | O_WRITE);

            minuto01 = (((hora_final_dosagem_personalizada_2 * 60) + (minuto_final_dosagem_personalizada_2)) - ((hora_inicial_dosagem_personalizada_2 * 60) + (minuto_inicial_dosagem_personalizada_2))); 
            minuto01 /= 1 + quantidade_dose_dosadora_2_personalizada;

            for(int i = 1; i <= quantidade_dose_dosadora_2_personalizada; i++)
            { 
              contador += 1;  
              if(contador == 1)
              {
                minuto11 = (hora_inicial_dosagem_personalizada_2 * 60) + minuto_inicial_dosagem_personalizada_2 + minuto01;
              }
              if(contador > 1)
              {
                minuto11 += minuto01; 
              }
              if(minuto11 < 10)
              {
                file.print("000");  
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(( minuto11 > 10) && (minuto11 < 100))
              {
                file.print("00");
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(( minuto11 >= 100) && (minuto11 < 1000))
              {
                file.print("0");
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(minuto11 >= 1000)
              {
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
            }
            file.close();  
            contador = 0;
            digitalWrite (4, HIGH);
            Salvar_dosadora_EEPROM();
          }         
        }      
      }
      if(dosadora_3_selecionada == true)
      {
        if ((x >= minUT[0]* fator_escala_x) && (x <= minUT[2]* fator_escala_x) && (y >= minUT[1]* fator_escala_y) && (y <= minUT[3] * fator_escala_y)) // Dose diaria mais
        {
          waitForIt(minUT[0], minUT[1], minUT[2], minUT[3]);
          dose_dosadora_3_personalizada_temp2 += 0.5;
          if(dose_dosadora_3_personalizada_temp2 > 999.5)
          {
            dose_dosadora_3_personalizada_temp2 = 0.5;
          }
          if(dose_dosadora_3_personalizada_temp2 <= 9.5)
          {
            myGLCD.setColor(0, 0, 0);                      
            myGLCD.fillRect(100, 45, 185, 67);
          }
          config_dosagem_personalizada_2();
        }
        if ((x >= minDT[0]* fator_escala_x) && (x <= minDT[2]* fator_escala_x) && (y >= minDT[1]* fator_escala_y) && (y <= minDT[3] * fator_escala_y)) // Dose diaria menos
        {
          waitForIt(minDT[0], minDT[1], minDT[2], minDT[3]);
          dose_dosadora_3_personalizada_temp2 -= 0.5;
          if(dose_dosadora_3_personalizada_temp2 <0.5)
          {
            dose_dosadora_3_personalizada_temp2 = 999.5;
          }
          if(dose_dosadora_3_personalizada_temp2 <= 9.5)
          {
            myGLCD.setColor(0, 0, 0);                      
            myGLCD.fillRect(100, 45, 185, 67);
          }
          config_dosagem_personalizada_2();
        }
        if ((x >= durC[0]* fator_escala_x) && (x <= durC[2]* fator_escala_x) && (y >= durC[1]* fator_escala_y) && (y <= durC[3] * fator_escala_y)) 
        {
          waitForIt(durC[0], durC[1], durC[2], durC[3]); 
          quantidade_dose_dosadora_3_personalizada_temp2 += 1;
          if(quantidade_dose_dosadora_3_personalizada_temp2 > 24)
          {
            quantidade_dose_dosadora_3_personalizada_temp2 = 1;
          }
          config_dosagem_personalizada_2();
        }

        if ((x >= durB[0]* fator_escala_x) && (x <= durB[2]* fator_escala_x) && (y >= durB[1]* fator_escala_y) && (y <= durB[3] * fator_escala_y)) 
        {
          waitForIt(durB[0], durB[1], durB[2], durB[3]);
          quantidade_dose_dosadora_3_personalizada_temp2 -= 1;
          if(quantidade_dose_dosadora_3_personalizada_temp2 < 1)
          {
            quantidade_dose_dosadora_3_personalizada_temp2 = 24;
          }
          config_dosagem_personalizada_2();        
        }
        if ((x >= sexT[0]* fator_escala_x) && (x<= sexT[2]* fator_escala_x) && (y >= sexT [1]* fator_escala_y) && (y <= sexT[3] * fator_escala_y))
        {
          waitForIt(sexT[0], sexT[1], sexT[2], sexT[3]);
          if(modo_personalizado_on_3_temp2 == 0)
          {
            modo_personalizado_on_3_temp2 = 1;
            modo_automatico_on_3_temp2 = 0;
            config_dosagem_personalizada_2();
          }
          else
          {
            modo_personalizado_on_3_temp2 = 0;
            modo_automatico_on_3_temp2 = 1;
            config_dosagem_personalizada_2();
          }
        }
        if ((y >= prOK[1]* fator_escala_y) && (y <= prOK[3]) && (x >= prOK[0]* fator_escala_x) && (x <= prOK[2]* fator_escala_x)) 
        {
          waitForIt(prOK[0], prOK[1], prOK[2], prOK[3]); //funcao salvar
          dose_dosadora_3_personalizada = dose_dosadora_3_personalizada_temp2;
          quantidade_dose_dosadora_3_personalizada = quantidade_dose_dosadora_3_personalizada_temp2;
          modo_personalizado_on_3 = modo_personalizado_on_3_temp2;
          modo_automatico_on_3 = modo_automatico_on_3_temp2;
          hora_inicial_dosagem_personalizada_3 = temp2hora_inicial_dosagem_personalizada_3;
          minuto_inicial_dosagem_personalizada_3 = temp2minuto_inicial_dosagem_personalizada_3;
          hora_final_dosagem_personalizada_3 = temp2hora_final_dosagem_personalizada_3;
          minuto_final_dosagem_personalizada_3 = temp2minuto_final_dosagem_personalizada_3;
          segunda_dosagem_personalizada_3 = temp2segunda_dosagem_personalizada_3;
          terca_dosagem_personalizada_3 = temp2terca_dosagem_personalizada_3;
          quarta_dosagem_personalizada_3 = temp2quarta_dosagem_personalizada_3;
          quinta_dosagem_personalizada_3 = temp2quinta_dosagem_personalizada_3;
          sexta_dosagem_personalizada_3 = temp2sexta_dosagem_personalizada_3;
          sabado_dosagem_personalizada_3 = temp2sabado_dosagem_personalizada_3;
          domingo_dosagem_personalizada_3 = temp2domingo_dosagem_personalizada_3;
          if((hora_final_dosagem_personalizada_3 == hora_inicial_dosagem_personalizada_3) && (minuto_final_dosagem_personalizada_3 < (minuto_inicial_dosagem_personalizada_3+10)))
          {
            setFont(SMALL, 255, 0, 0, 0, 0, 0);
            myGLCD.print(tabela_textos[176], 20, 110);
            myGLCD.print(tabela_textos[177], 35, 130); // tabela_textos[177] = "DEVE SER DE NO MINIMO 10 MINUTOS!"
          }
          if(hora_final_dosagem_personalizada_3 < hora_inicial_dosagem_personalizada_3)
          {
            setFont(SMALL, 255, 0, 0, 0, 0, 0);
            myGLCD.print(tabela_textos[178], 50, 110); // tabela_textos[178] = "A HORA FINAL NAO PODE SER MENOR"
            myGLCD.print(tabela_textos[179], 100, 130); // tabela_textos[179] = "QUE A INICIAL!" 
          }

          if((temp2hora_final_dosagem_personalizada_3 == hora_inicial_dosagem_personalizada_3) && (temp2minuto_final_dosagem_personalizada_3 >= (minuto_inicial_dosagem_personalizada_3+10)))
          {
            dispScreen =21;
            clearScreen();
            selecionar_dosadora();
            setFont(SMALL, 255, 255, 255, 0, 0, 0);
            myGLCD.print(tabela_textos[171], 15, 220); // tabela_textos[171] = "MODO PERSONALIZADO SELECIONADO"
            modo_manual = false;
            modo_automatico = false;
            modo_personalizado = true;
            modo_calibrar = false;
            dosadora_1_selecionada = false;
            dosadora_2_selecionada = false;
            dosadora_3_selecionada = false; 
            digitalWrite (4, LOW); 
            file.open(&root, "HDP3.TXT", O_WRITE);
            file.remove();       
            file.open(&root, "HDP3.TXT", O_CREAT | O_APPEND | O_WRITE);

            minuto01 = (((hora_final_dosagem_personalizada_3 * 60) + (minuto_final_dosagem_personalizada_3)) - ((hora_inicial_dosagem_personalizada_3 * 60) + (minuto_inicial_dosagem_personalizada_3))); 
            minuto01 /= 1 + quantidade_dose_dosadora_3_personalizada;

            for(int i = 1; i <= quantidade_dose_dosadora_3_personalizada; i++)
            { 
              contador += 1;  
              if(contador == 1)
              {
                minuto11 = (hora_inicial_dosagem_personalizada_3 * 60) + minuto_inicial_dosagem_personalizada_3 + minuto01;
              }
              if(contador > 1)
              {
                minuto11 += minuto01; 
              }
              if(minuto11 < 10)
              {
                file.print("000");  
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(( minuto11 > 10) && (minuto11 < 100))
              {
                file.print("00");
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(( minuto11 >= 100) && (minuto11 < 1000))
              {
                file.print("0");
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(minuto11 >= 1000)
              {
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
            }
            file.close();  
            contador = 0;
            digitalWrite (4, HIGH);
            Salvar_dosadora_EEPROM(); 
          }    

          if(temp2hora_final_dosagem_personalizada_3 > hora_inicial_dosagem_personalizada_3)
          {
            dispScreen =21;
            clearScreen();
            selecionar_dosadora();
            setFont(SMALL, 255, 255, 255, 0, 0, 0);
            myGLCD.print(tabela_textos[171], 15, 220); // tabela_textos[171] = "MODO PERSONALIZADO SELECIONADO"
            modo_manual = false;
            modo_automatico = false;
            modo_personalizado = true;
            modo_calibrar = false;
            dosadora_1_selecionada = false;
            dosadora_2_selecionada = false;
            dosadora_3_selecionada = false; 
            digitalWrite (4, LOW); 
            file.open(&root, "HDP3.TXT", O_WRITE);
            file.remove();       
            file.open(&root, "HDP3.TXT", O_CREAT | O_APPEND | O_WRITE);

            minuto01 = (((hora_final_dosagem_personalizada_3 * 60) + (minuto_final_dosagem_personalizada_3)) - ((hora_inicial_dosagem_personalizada_3 * 60) + (minuto_inicial_dosagem_personalizada_3))); 
            minuto01 /= 1 + quantidade_dose_dosadora_3_personalizada;

            for(int i = 1; i <= quantidade_dose_dosadora_3_personalizada; i++)
            { 
              contador += 1;  
              if(contador == 1)
              {
                minuto11 = (hora_inicial_dosagem_personalizada_3 * 60) + minuto_inicial_dosagem_personalizada_3 + minuto01;
              }
              if(contador > 1)
              {
                minuto11 += minuto01; 
              }
              if(minuto11 < 10)
              {
                file.print("000");  
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(( minuto11 > 10) && (minuto11 < 100))
              {
                file.print("00");
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(( minuto11 >= 100) && (minuto11 < 1000))
              {
                file.print("0");
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(minuto11 >= 1000)
              {
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
            }
            file.close();  
            contador = 0;
            digitalWrite (4, HIGH);
            Salvar_dosadora_EEPROM();
          }         
        }
      }      
      break;
    case 32: // -------------------------------- Rever configuração das dosadoras ------------------------------------------
      if ((x>=menU[0]* fator_escala_x) && (x<=menU[2]* fator_escala_x) && (y>=menU[1]* fator_escala_y) && (y<=menU[3] * fator_escala_y))           // volta ao menu
      {
        waitForIt(menU[0], menU[1], menU[2], menU[3]);
        dispScreen = 1;
        clearScreen();
        menuScreen(); 
      }
      if ((x>=volT[0]* fator_escala_x) && (x<=volT[2]* fator_escala_x) && (y>=volT[1]* fator_escala_y) && (y<=volT[3] * fator_escala_y))           // volta ao menu das dosadoras
      {
        waitForIt(volT[0], volT[1], volT[2], volT[3]);
        dispScreen=8;
        clearScreen();
        menu_dosadoras();
      }
      if ((x>=manU[0]* fator_escala_x) && (x<=manU[2]* fator_escala_x) && (y>=manU[1]* fator_escala_y) && (y<=manU[3] * fator_escala_y))           // Rever configuração dosagem automatica
      {
        waitForIt(manU[0], manU[1], manU[2], manU[3]);
        dispScreen = 33;
        clearScreen();
        rever_dosagem_automatica();
      }
      if ((x>=autO[0]* fator_escala_x) && (x<=autO[2]* fator_escala_x) && (y>=autO[1]* fator_escala_y) && (y<=autO[3] * fator_escala_y))           // Rever configuração dosagem personalizada
      {
        waitForIt(autO[0], autO[1], autO[2], autO[3]);
        dispScreen = 34;
        clearScreen();
        rever_dosagem_personalizada();
      }  
      break;     
    case 33:// -------------------------------- Rever configuração das dosadoras modo automático ------------------------------------------
      if ((x>=menU[0]* fator_escala_x) && (x<=menU[2]* fator_escala_x) && (y>=menU[1]* fator_escala_y) && (y<=menU[3] * fator_escala_y))           // volta ao menu
      {
        waitForIt(menU[0], menU[1], menU[2], menU[3]);
        dispScreen = 1;
        clearScreen();
        menuScreen(); 
      }
      if ((x>=volT[0]* fator_escala_x) && (x<=volT[2]* fator_escala_x) && (y>=volT[1]* fator_escala_y) && (y<=volT[3] * fator_escala_y))           // volta ao menu de revisão das dosadoras
      {
        waitForIt(volT[0], volT[1], volT[2], volT[3]);
        dispScreen=32;
        clearScreen();
        rever_configuracao_dosadoras();
      }
      break;
    case 34:// -------------------------------- Rever configuração das dosadoras personalizado ------------------------------------------
      if ((x>=menU[0]* fator_escala_x) && (x<=menU[2]* fator_escala_x) && (y>=menU[1]* fator_escala_y) && (y<=menU[3] * fator_escala_y))           // volta ao menu
      {
        waitForIt(menU[0], menU[1], menU[2], menU[3]);
        dispScreen = 1;
        clearScreen();
        menuScreen();    
      }
      if ((x>=volT[0]* fator_escala_x) && (x<=volT[2]* fator_escala_x) && (y>=volT[1]* fator_escala_y) && (y<=volT[3] * fator_escala_y))           // volta ao menu de revisão das dosadoras
      {
        waitForIt(volT[0], volT[1], volT[2], volT[3]);
        dispScreen=32;
        clearScreen();
        rever_configuracao_dosadoras();
      }
      break;
    case 35:// -------------------------------------- Desativar dosadoras ------------------------------------------
      if ((x>=menU[0]* fator_escala_x) && (x<=menU[2]* fator_escala_x) && (y>=menU[1]* fator_escala_y) && (y<=menU[3] * fator_escala_y))           // volta ao menu
      {
        waitForIt(menU[0], menU[1], menU[2], menU[3]);
        dispScreen = 1;
        clearScreen();
        menuScreen();    
      }
      if ((x>=volT[0]* fator_escala_x) && (x<=volT[2]* fator_escala_x) && (y>=volT[1]* fator_escala_y) && (y<=volT[3] * fator_escala_y))           // volta ao menu de revisão das dosadoras
      {
        waitForIt(volT[0], volT[1], volT[2], volT[3]);
        dispScreen = 8;
        clearScreen();
        menu_dosadoras();
      }
      if ((x >= 100) && (x <= 220) && (y >= 45) && (y <= 85))           //Ativar/desatiavr dosadora 1
      {
        waitForIt(100, 45, 220, 85);

        if(ativar_desativar_1 == 1)
        {
          ativar_desativar_1 = 0;
          desativar_dosadoras();
        }
        else
        {
          desativar_dosadoras(true);
        }          
      }
      if ((x >= 100) && (x <= 220) && (y >= 115) && (y <= 155))           //Ativar/desatiavr dosadora 2
      {
        waitForIt(100, 115, 220, 155);

        if(ativar_desativar_2 == 1)
        {
          ativar_desativar_2 = 0;
          desativar_dosadoras();
        }
        else
        {
          desativar_dosadoras(true);
        }          
      }
      if ((x >= 100) && (x <= 220) && (y >= 185) && (y <= 225))           //Ativar/desatiavr dosadora 3
      {
        waitForIt(100, 185, 220, 225);

        if(ativar_desativar_3 == 1)
        {
          ativar_desativar_3 = 0;
          desativar_dosadoras();
        }
        else
        {
          desativar_dosadoras(true);
        }          
      }
      if ((x>=salV[0]* fator_escala_x) && (x<=salV[2]* fator_escala_x) && (y>=salV[1]* fator_escala_y) && (y<=salV[3] * fator_escala_y))           //Salvar alterações
      {
        waitForIt(salV[0], salV[1], salV[2], salV[3]);
        if(ativar_desativar_1 == 0)
        {
          modo_personalizado_on_1 = 0;
          modo_automatico_on_1 = 0;
        }
        if(ativar_desativar_2 == 0)
        {
          modo_personalizado_on_2 = 0;
          modo_automatico_on_2 = 0;
        }
        if(ativar_desativar_3 == 0)
        {
          modo_personalizado_on_3 = 0;
          modo_automatico_on_3 = 0;
        }
        Salvar_dosadora_EEPROM(); 
        dispScreen = 0;
        clearScreen();
        mainScreen(true);       
      }
      break;
    case 36: // -------------------------------- Luz noturna --------------------------------------------
      if ((x>=volT[0]* fator_escala_x) && (x<=volT[2]* fator_escala_x) && (y>=volT[1]* fator_escala_y) && (y<=volT[3] * fator_escala_y))           // volta a tela configurar leds
      {
        waitForIt(volT[0], volT[1], volT[2], volT[3]);
        dispScreen=40;
        clearScreen();
        config_leds(); 
      }
      if ((x>=salV[0]* fator_escala_x) && (x<=salV[2]* fator_escala_x) && (y>=salV[1]* fator_escala_y) && (y<=salV[3] * fator_escala_y))       //Funcao salvar
      {
        waitForIt(salV[0], salV[1], salV[2], salV[3]);
        MaxI = tMaxI;
        MinI = tMinI;
        dispScreen=0;
        Salvar_luz_noturna_EEPROM();
        clearScreen();
        mainScreen(true);
      } 
      if ((x>=temM[0]* fator_escala_x) && (x<=temM[2]* fator_escala_x))                         // Primeira coluna
      {
        if ((y>=temM[1]* fator_escala_y) && (y<=temM[3] * fator_escala_y))                      //press densidade minus
        {
          waitForIt(temM[0], temM[1], temM[2], temM[3]);
          tMaxI -= 1;
          if (tMaxI < 0)
          {
            tMaxI = 255;
          }
          myGLCD.setColor(0, 0, 0);
          myGLCD.fillRect (128, 40, 180, 56);//Limpar texto
          luz_noturna();
        }

        if ((y>=almM[1]* fator_escala_y) && (y<=almM[3] * fator_escala_y))                        //press alarm minus
        {
          waitForIt(almM[0], almM[1], almM[2], almM[3]);
          tMinI -= 1;
          if (tMinI < 0)
          {
            tMinI = 255;
          }
          myGLCD.setColor(0, 0, 0);
          myGLCD.fillRect (128, 140, 180, 156);//Limpar texto
          luz_noturna();
        }
      }
      if ((x>=temP[0]* fator_escala_x) && (x<=temP[2]* fator_escala_x))                             //Segunda coluna
      {
        if ((y>=temP[1]* fator_escala_y) && (y<=temP[3] * fator_escala_y))                      //press densidade plus
        {
          waitForIt(temP[0], temP[1], temP[2], temP[3]);
          tMaxI += 1;
          if (tMaxI > 255)
          {
            tMaxI = 1;
          }
          myGLCD.setColor(0, 0, 0);
          myGLCD.fillRect (128, 40, 180, 56); //Limpar texto
          luz_noturna();
        }

        if ((y>=almP[1]* fator_escala_y) && (y<=almP[3] * fator_escala_y))                           //press alarm plus
        {
          waitForIt(almP[0], almP[1], almP[2], almP[3]);
          tMinI += 1;
          if (tMinI > 255)
          {
            tMinI = 1;
          }
          myGLCD.setColor(0, 0, 0);
          myGLCD.fillRect (128, 140, 180, 156);//Limpar texto
          luz_noturna();
        }
      }
      if ((x>=menU[0]* fator_escala_x) && (x<=menU[2]* fator_escala_x) && (y>=menU[1]* fator_escala_y) && (y<=menU[3] * fator_escala_y))           // volta ao menu 1
      {
        waitForIt(menU[0], menU[1], menU[2], menU[3]);
        dispScreen=1;
        clearScreen();
        menuScreen();
      } 
      break;
    case 37: // -------------------------------- Menu 2 -------------------------------------------------------------- 
      if ((x>=menU[0]* fator_escala_x) && (x<=menU[2]* fator_escala_x) && (y>=menU[1]* fator_escala_y) && (y<=menU[3] * fator_escala_y))           // Volta ao menu 1
      {
        waitForIt(menU[0], menU[1], menU[2], menU[3]);
        dispScreen=1;
        clearScreen();
        menuScreen();
      }
      break;
    case 38: // -------------------------------- Timers -------------------------------------------------------------- 
      if ((x>=menU[0]* fator_escala_x) && (x<=menU[2]* fator_escala_x) && (y>=menU[1]* fator_escala_y) && (y<=menU[3] * fator_escala_y))           // Volta ao menu 1
      {
        waitForIt(menU[0], menU[1], menU[2], menU[3]);
        dispScreen=1;
        clearScreen();
        menuScreen();
      }
      if ((x >= 7) && (x <= 56) && (y >= 22) && (y <= 238))           // Timer 1 
      {
        waitForIt(7, 22, 56, 238);
        temporizador_1 = true;
        temporizador_2 = false;
        temporizador_3 = false;
        temporizador_4 = false;
        temporizador_5 = false;
        dispScreen=39;
        clearScreen();
        config_timer(true);
      }
      if ((x >= 71) && (x <= 120) && (y >= 22) && (y <= 238))           // Timer 2 
      {
        waitForIt(71, 22, 120, 238);
        temporizador_1 = false;
        temporizador_2 = true;
        temporizador_3 = false;
        temporizador_4 = false;
        temporizador_5 = false;
        dispScreen=39;
        clearScreen();
        config_timer(true);
      }
      if ((x >= 135) && (x <= 184) && (y >= 22) && (y <= 238))           // Timer 3 
      {
        waitForIt(135, 22, 184, 238);
        temporizador_1 = false;
        temporizador_2 = false;
        temporizador_3 = true;
        temporizador_4 = false;
        temporizador_5 = false;
        dispScreen=39;
        clearScreen();
        config_timer(true);
      }
      if ((x >= 199) && (x <= 248) && (y >= 22) && (y <= 238))           // Timer 4 
      {
        waitForIt(199, 22, 248, 238);
        temporizador_1 = false;
        temporizador_2 = false;
        temporizador_3 = false;
        temporizador_4 = true;
        temporizador_5 = false;
        dispScreen=39;
        clearScreen();
        config_timer(true);
      } 
      if ((x >= 263) && (x <= 312) && (y >= 22) && (y <= 238))           // Timer 5 
      {
        waitForIt(263, 22, 312, 238);
        temporizador_1 = false;
        temporizador_2 = false;
        temporizador_3 = false;
        temporizador_4 = false;
        temporizador_5 = true;
        dispScreen=39;
        clearScreen();
        config_timer(true);
      }       
      break;
    case 39:// -------------------------------- Configurar timers ------------------------------------------------------ 
      if ((x>=menU[0]* fator_escala_x) && (x<=menU[2]* fator_escala_x) && (y>=menU[1]* fator_escala_y) && (y<=menU[3] * fator_escala_y))           // Volta ao menu 2
      {
        waitForIt(menU[0], menU[1], menU[2], menU[3]);   
        dispScreen=1;
        clearScreen();
        menuScreen();
      }
      if ((x>=volT[0]* fator_escala_x) && (x<=volT[2]* fator_escala_x) && (y>=volT[1]* fator_escala_y) && (y<=volT[3] * fator_escala_y))           // Selecionar timer
      {
        waitForIt(volT[0], volT[1], volT[2], volT[3]);
        dispScreen=38;
        clearScreen();
        TimerScreen(); 
      } 
      if(temporizador_1 == true)
      {
        if ((x>=salV[0]* fator_escala_x) && (x<=salV[2]* fator_escala_x) && (y>=salV[1]* fator_escala_y) && (y<=salV[3] * fator_escala_y))
        {
          waitForIt(salV[0], salV[1], salV[2], salV[3]); // Função salvar
          if((on1_hora_temp2 == off1_hora_temp2) && (on1_minuto_temp2 >= off1_minuto_temp2))
          {
            setFont(SMALL, 255, 0, 0, 0, 0, 0);
            myGLCD.print(tabela_textos[170], 20, 205);
            myGLCD.print(tabela_textos[169], 20, 222);
          }

          if(off1_hora_temp2 < on1_hora_temp2)
          {
            setFont(SMALL, 255, 0, 0, 0, 0, 0);
            myGLCD.print(tabela_textos[170], 20, 205);
            myGLCD.print(tabela_textos[169], 20, 222);
          }

          if((on1_hora_temp2 == off1_hora_temp2) && (off1_minuto_temp2 > on1_minuto_temp2))
          {
            on1_minuto = on1_minuto_temp2;
            on1_hora = on1_hora_temp2;
            off1_minuto = off1_minuto_temp2;
            off1_hora = off1_hora_temp2;
            temporizador_1_ativado = temporizador_1_ativado_temp2;
            dispScreen=38;
            clearScreen();
            TimerScreen();
            salvar_timers_EEPROM();
          }
          if(on1_hora_temp2 < off1_hora_temp2)
          {
            on1_minuto = on1_minuto_temp2;
            on1_hora = on1_hora_temp2;
            off1_minuto = off1_minuto_temp2;
            off1_hora = off1_hora_temp2;
            temporizador_1_ativado = temporizador_1_ativado_temp2;
            dispScreen=38;
            clearScreen();
            TimerScreen();    
            salvar_timers_EEPROM();
          }
        }
        if ((x >= 21) && (x <= 65) && (y >= 45) && (y <= 88))           // Hora ligar mais 
        {
          waitForIt(21, 45, 65, 88);
          on1_hora_temp2 += 1;
          if(on1_hora_temp2 > 23)
          {
            on1_hora_temp2 = 0;
          }
          config_timer();
        } 
        if ((x >= 21) && (x <= 65) && (y >= 135) && (y <= 178))           // Hora ligar menos
        {
          waitForIt(21, 45, 65, 88);
          on1_hora_temp2 -= 1;
          if(on1_hora_temp2 < 0)
          {
            on1_hora_temp2 = 23;
          }
          config_timer();
        } 

        if ((x >= 89) && (x <= 133) && (y >= 45) && (y <= 88))           // Minuto ligar mais 
        {
          waitForIt(89, 45, 133, 88);
          on1_minuto_temp2 += 1;
          if(on1_minuto_temp2 > 59)
          {
            on1_minuto_temp2 = 0;
          }
          config_timer();
        } 
        if ((x >= 89) && (x <= 133) && (y >= 135) && (y <= 178))           // Minuto ligar menos
        {
          waitForIt(89, 135, 133, 178);
          on1_minuto_temp2 -= 1;
          if(on1_minuto_temp2 < 0)
          {
            on1_minuto_temp2 = 59;
          }
          config_timer();
        }
        if ((x >= 187) && (x <= 231) && (y >= 45) && (y <= 88))           // Hora desligar mais 
        {
          waitForIt(187, 45, 231, 88);
          off1_hora_temp2 += 1;
          if(off1_hora_temp2 > 23)
          {
            off1_hora_temp2 = 0;
          }
          config_timer();
        } 
        if ((x >= 187) && (x <= 231) && (y >= 135) && (y <= 178))           // Hora desligar menos
        {
          waitForIt(187, 135, 231, 178);
          off1_hora_temp2 -= 1;
          if(off1_hora_temp2 < 0)
          {
            off1_hora_temp2 = 23;
          }
          config_timer();
        } 

        if ((x >= 255) && (x <= 299) && (y >= 45) && (y <= 88))           // Minuto desligar mais 
        {
          waitForIt(255, 45, 299, 88);
          off1_minuto_temp2 += 1;
          if(off1_minuto_temp2 > 59)
          {
            off1_minuto_temp2 = 0;
          }
          config_timer();
        } 
        if ((x >= 255) && (x <= 299) && (y >= 135) && (y <= 178))           // Minuto desligar menos
        {
          waitForIt(255, 135, 299, 178);
          off1_minuto_temp2 -= 1;
          if(off1_minuto_temp2 < 0)
          {
            off1_minuto_temp2 = 59;
          }
          config_timer();
        }
        if ((x>=domI[0]-20) && (x<=domI[2]+20) && (y>=domI[1]* fator_escala_y) && (y<=domI[3] * fator_escala_y))           // Ativar / desativar timer
        {
          waitForIt(domI[0]-20, domI[1], domI[2]+20, domI[3]);
          if(temporizador_1_ativado_temp2 == 0)
          {
            temporizador_1_ativado_temp2 = 1;
          }
          else
          {
            temporizador_1_ativado_temp2 = 0;
          }
          config_timer();
        }  
      }
      if(temporizador_2 == true)
      {
        if ((x>=salV[0]* fator_escala_x) && (x<=salV[2]* fator_escala_x) && (y>=salV[1]* fator_escala_y) && (y<=salV[3] * fator_escala_y))
        {
          waitForIt(salV[0], salV[1], salV[2], salV[3]); // Função salvar

          if((on2_hora_temp2 == off2_hora_temp2) && (on2_minuto_temp2 >= off2_minuto_temp2))
          {
            setFont(SMALL, 255, 0, 0, 0, 0, 0);
            myGLCD.print(tabela_textos[170], 20, 205);
            myGLCD.print(tabela_textos[169], 20, 222);
          }

          if(off2_hora_temp2 < on2_hora_temp2)
          {
            setFont(SMALL, 255, 0, 0, 0, 0, 0);
            myGLCD.print(tabela_textos[170], 20, 205);
            myGLCD.print(tabela_textos[169], 20, 222);
          }

          if((on2_hora_temp2 == off2_hora_temp2) && (off2_minuto_temp2 > on2_minuto_temp2))
          {
            on2_minuto = on2_minuto_temp2;
            on2_hora = on2_hora_temp2;
            off2_minuto = off2_minuto_temp2;
            off2_hora = off2_hora_temp2;
            temporizador_2_ativado = temporizador_2_ativado_temp2;
            dispScreen=38;
            clearScreen();
            TimerScreen();
            salvar_timers_EEPROM();
          }
          if(on2_hora_temp2 < off2_hora_temp2)
          {
            on2_minuto = on2_minuto_temp2;
            on2_hora = on2_hora_temp2;
            off2_minuto = off2_minuto_temp2;
            off2_hora = off2_hora_temp2;
            temporizador_2_ativado = temporizador_2_ativado_temp2;
            dispScreen=38;
            clearScreen();
            TimerScreen();
            salvar_timers_EEPROM();
          }
        }

        if ((x >= 21) && (x <= 65) && (y >= 45) && (y <= 88))           // Hora ligar mais 
        {
          waitForIt(21, 45, 65, 88);
          on2_hora_temp2 += 1;
          if(on2_hora_temp2 > 23)
          {
            on2_hora_temp2 = 0;
          }
          config_timer();
        } 
        if ((x >= 21) && (x <= 65) && (y >= 135) && (y <= 178))           // Hora ligar menos
        {
          waitForIt(21, 45, 65, 88);
          on2_hora_temp2 -= 1;
          if(on2_hora_temp2 < 0)
          {
            on2_hora_temp2 = 23;
          }
          config_timer();
        } 

        if ((x >= 89) && (x <= 133) && (y >= 45) && (y <= 88))           // Minuto ligar mais 
        {
          waitForIt(89, 45, 133, 88);
          on2_minuto_temp2 += 1;
          if(on2_minuto_temp2 > 59)
          {
            on2_minuto_temp2 = 0;
          }
          config_timer();
        } 
        if ((x >= 89) && (x <= 133) && (y >= 135) && (y <= 178))           // Minuto ligar menos
        {
          waitForIt(89, 135, 133, 178);
          on2_minuto_temp2 -= 1;
          if(on2_minuto_temp2 < 0)
          {
            on2_minuto_temp2 = 59;
          }
          config_timer();
        }
        if ((x >= 187) && (x <= 231) && (y >= 45) && (y <= 88))           // Hora desligar mais 
        {
          waitForIt(187, 45, 231, 88);
          off2_hora_temp2 += 1;
          if(off2_hora_temp2 > 23)
          {
            off2_hora_temp2 = 0;
          }
          config_timer();
        } 
        if ((x >= 187) && (x <= 231) && (y >= 135) && (y <= 178))           // Hora desligar menos
        {
          waitForIt(187, 135, 231, 178);
          off2_hora_temp2 -= 1;
          if(off2_hora_temp2 < 0)
          {
            off2_hora_temp2 = 23;
          }
          config_timer();
        } 

        if ((x >= 255) && (x <= 299) && (y >= 45) && (y <= 88))           // Minuto desligar mais 
        {
          waitForIt(255, 45, 299, 88);
          off2_minuto_temp2 += 1;
          if(off2_minuto_temp2 > 59)
          {
            off2_minuto_temp2 = 0;
          }
          config_timer();
        } 
        if ((x >= 255) && (x <= 299) && (y >= 135) && (y <= 178))           // Minuto desligar menos
        {
          waitForIt(255, 135, 299, 178);
          off2_minuto_temp2 -= 1;
          if(off2_minuto_temp2 < 0)
          {
            off2_minuto_temp2 = 59;
          }
          config_timer();
        }
        if ((x>=domI[0]-20) && (x<=domI[2]+20) && (y>=domI[1]* fator_escala_y) && (y<=domI[3] * fator_escala_y))           // Ativar / desativar timer
        {
          waitForIt(domI[0]-20, domI[1], domI[2]+20, domI[3]);
          if(temporizador_2_ativado_temp2 == 0)
          {
            temporizador_2_ativado_temp2 = 1;
          }
          else
          {
            temporizador_2_ativado_temp2 = 0;
          }
          config_timer();
        }  
      }   
      if(temporizador_3 == true)
      {
        if ((x>=salV[0]* fator_escala_x) && (x<=salV[2]* fator_escala_x) && (y>=salV[1]* fator_escala_y) && (y<=salV[3] * fator_escala_y))
        {
          waitForIt(salV[0], salV[1], salV[2], salV[3]); // Função salvar          

          if((on3_hora_temp2 == off3_hora_temp2) && (on3_minuto_temp2 >= off3_minuto_temp2))
          {
            setFont(SMALL, 255, 0, 0, 0, 0, 0);
            myGLCD.print(tabela_textos[170], 20, 205);
            myGLCD.print(tabela_textos[169], 20, 222);
          }

          if(off3_hora_temp2 < on3_hora_temp2)
          {
            setFont(SMALL, 255, 0, 0, 0, 0, 0);
            myGLCD.print(tabela_textos[170], 20, 205);
            myGLCD.print(tabela_textos[169], 20, 222);
          }

          if((on3_hora_temp2 == off3_hora_temp2) && (off3_minuto_temp2 > on3_minuto_temp2))
          {
            on3_minuto = on3_minuto_temp2;
            on3_hora = on3_hora_temp2;
            off3_minuto = off3_minuto_temp2;
            off3_hora = off3_hora_temp2;
            temporizador_3_ativado = temporizador_3_ativado_temp2;
            dispScreen=38;
            clearScreen();
            TimerScreen();
            salvar_timers_EEPROM();
          }
          if(on3_hora_temp2 < off3_hora_temp2)
          {
            on3_minuto = on3_minuto_temp2;
            on3_hora = on3_hora_temp2;
            off3_minuto = off3_minuto_temp2;
            off3_hora = off3_hora_temp2;
            temporizador_3_ativado = temporizador_3_ativado_temp2;
            dispScreen=38;
            clearScreen();
            TimerScreen();
            salvar_timers_EEPROM();
          }
        }

        if ((x >= 21) && (x <= 65) && (y >= 45) && (y <= 88))           // Hora ligar mais 
        {
          waitForIt(21, 45, 65, 88);
          on3_hora_temp2 += 1;
          if(on3_hora_temp2 > 23)
          {
            on3_hora_temp2 = 0;
          }
          config_timer();
        } 
        if ((x >= 21) && (x <= 65) && (y >= 135) && (y <= 178))           // Hora ligar menos
        {
          waitForIt(21, 45, 65, 88);
          on3_hora_temp2 -= 1;
          if(on3_hora_temp2 < 0)
          {
            on3_hora_temp2 = 23;
          }
          config_timer();
        } 

        if ((x >= 89) && (x <= 133) && (y >= 45) && (y <= 88))           // Minuto ligar mais 
        {
          waitForIt(89, 45, 133, 88);
          on3_minuto_temp2 += 1;
          if(on3_minuto_temp2 > 59)
          {
            on3_minuto_temp2 = 0;
          }
          config_timer();
        } 
        if ((x >= 89) && (x <= 133) && (y >= 135) && (y <= 178))           // Minuto ligar menos
        {
          waitForIt(89, 135, 133, 178);
          on3_minuto_temp2 -= 1;
          if(on3_minuto_temp2 < 0)
          {
            on3_minuto_temp2 = 59;
          }
          config_timer();
        }
        if ((x >= 187) && (x <= 231) && (y >= 45) && (y <= 88))           // Hora desligar mais 
        {
          waitForIt(187, 45, 231, 88);
          off3_hora_temp2 += 1;
          if(off3_hora_temp2 > 23)
          {
            off3_hora_temp2 = 0;
          }
          config_timer();
        } 
        if ((x >= 187) && (x <= 231) && (y >= 135) && (y <= 178))           // Hora desligar menos
        {
          waitForIt(187, 135, 231, 178);
          off3_hora_temp2 -= 1;
          if(off3_hora_temp2 < 0)
          {
            off3_hora_temp2 = 23;
          }
          config_timer();
        } 

        if ((x >= 255) && (x <= 299) && (y >= 45) && (y <= 88))           // Minuto desligar mais 
        {
          waitForIt(255, 45, 299, 88);
          off3_minuto_temp2 += 1;
          if(off3_minuto_temp2 > 59)
          {
            off3_minuto_temp2 = 0;
          }
          config_timer();
        } 
        if ((x >= 255) && (x <= 299) && (y >= 135) && (y <= 178))           // Minuto desligar menos
        {
          waitForIt(255, 135, 299, 178);
          off3_minuto_temp2 -= 1;
          if(off3_minuto_temp2 < 0)
          {
            off3_minuto_temp2 = 59;
          }
          config_timer();
        }
        if ((x>=domI[0]-20) && (x<=domI[2]+20) && (y>=domI[1]* fator_escala_y) && (y<=domI[3] * fator_escala_y))           // Ativar / desativar timer
        {
          waitForIt(domI[0]-20, domI[1], domI[2]+20, domI[3]);
          if(temporizador_3_ativado_temp2 == 0)
          {
            temporizador_3_ativado_temp2 = 1;
          }
          else
          {
            temporizador_3_ativado_temp2 = 0;
          }
          config_timer(); 
        }  
      }
      if(temporizador_4 == true)
      {
        if ((x>=salV[0]* fator_escala_x) && (x<=salV[2]* fator_escala_x) && (y>=salV[1]* fator_escala_y) && (y<=salV[3] * fator_escala_y))
        {
          waitForIt(salV[0], salV[1], salV[2], salV[3]); // Função salvar

          if((on4_hora_temp2 == off4_hora_temp2) && (on4_minuto_temp2 >= off4_minuto_temp2))
          {
            setFont(SMALL, 255, 0, 0, 0, 0, 0);
            myGLCD.print(tabela_textos[170], 20, 205);
            myGLCD.print(tabela_textos[169], 20, 222);
          }

          if(off4_hora_temp2 < on4_hora_temp2)
          {
            setFont(SMALL, 255, 0, 0, 0, 0, 0);
            myGLCD.print(tabela_textos[170], 20, 205);
            myGLCD.print(tabela_textos[169], 20, 222);
          }

          if((on4_hora_temp2 == off4_hora_temp2) && (off4_minuto_temp2 > on4_minuto_temp2))
          {
            on4_minuto = on4_minuto_temp2;
            on4_hora = on4_hora_temp2;
            off4_minuto = off4_minuto_temp2;
            off4_hora = off4_hora_temp2;
            temporizador_4_ativado = temporizador_4_ativado_temp2;
            dispScreen=38;
            clearScreen();
            TimerScreen();
            salvar_timers_EEPROM();
          }
          if(on4_hora_temp2 < off4_hora_temp2)
          {
            on4_minuto = on4_minuto_temp2;
            on4_hora = on4_hora_temp2;
            off4_minuto = off4_minuto_temp2;
            off4_hora = off4_hora_temp2;
            temporizador_4_ativado = temporizador_4_ativado_temp2;
            dispScreen=38;
            clearScreen();
            TimerScreen();
            salvar_timers_EEPROM();
          }
        }
        if ((x >= 21) && (x <= 65) && (y >= 45) && (y <= 88))           // Hora ligar mais 
        {
          waitForIt(21, 45, 65, 88);
          on4_hora_temp2 += 1;
          if(on4_hora_temp2 > 23)
          {
            on4_hora_temp2 = 0;
          }
          config_timer();
        } 
        if ((x >= 21) && (x <= 65) && (y >= 135) && (y <= 178))           // Hora ligar menos
        {
          waitForIt(21, 45, 65, 88);
          on4_hora_temp2 -= 1;
          if(on4_hora_temp2 < 0)
          {
            on4_hora_temp2 = 23;
          }
          config_timer();
        } 

        if ((x >= 89) && (x <= 133) && (y >= 45) && (y <= 88))           // Minuto ligar mais 
        {
          waitForIt(89, 45, 133, 88);
          on4_minuto_temp2 += 1;
          if(on4_minuto_temp2 > 59)
          {
            on4_minuto_temp2 = 0;
          }
          config_timer();
        } 
        if ((x >= 89) && (x <= 133) && (y >= 135) && (y <= 178))           // Minuto ligar menos
        {
          waitForIt(89, 135, 133, 178);
          on4_minuto_temp2 -= 1;
          if(on4_minuto_temp2 < 0)
          {
            on4_minuto_temp2 = 59;
          }
          config_timer();
        }
        if ((x >= 187) && (x <= 231) && (y >= 45) && (y <= 88))           // Hora desligar mais 
        {
          waitForIt(187, 45, 231, 88);
          off4_hora_temp2 += 1;
          if(off4_hora_temp2 > 23)
          {
            off4_hora_temp2 = 0;
          }
          config_timer();
        } 
        if ((x >= 187) && (x <= 231) && (y >= 135) && (y <= 178))           // Hora desligar menos
        {
          waitForIt(187, 135, 231, 178);
          off4_hora_temp2 -= 1;
          if(off4_hora_temp2 < 0)
          {
            off4_hora_temp2 = 23;
          }
          config_timer();
        } 

        if ((x >= 255) && (x <= 299) && (y >= 45) && (y <= 88))           // Minuto desligar mais 
        {
          waitForIt(255, 45, 299, 88);
          off4_minuto_temp2 += 1;
          if(off4_minuto_temp2 > 59)
          {
            off4_minuto_temp2 = 0;
          }
          config_timer();
        } 
        if ((x >= 255) && (x <= 299) && (y >= 135) && (y <= 178))           // Minuto desligar menos
        {
          waitForIt(255, 135, 299, 178);
          off4_minuto_temp2 -= 1;
          if(off4_minuto_temp2 < 0)
          {
            off4_minuto_temp2 = 59;
          }
          config_timer();
        }
        if ((x>=domI[0]-20) && (x<=domI[2]+20) && (y>=domI[1]* fator_escala_y) && (y<=domI[3] * fator_escala_y))           // Ativar / desativar timer
        {
          waitForIt(domI[0]-20, domI[1], domI[2]+20, domI[3]);
          if(temporizador_4_ativado_temp2 == 0)
          {
            temporizador_4_ativado_temp2 = 1;
          }
          else
          {
            temporizador_4_ativado_temp2 = 0;
          }
          config_timer(); 
        }  
      }
      if(temporizador_5 == true)
      {
        if ((x>=salV[0]* fator_escala_x) && (x<=salV[2]* fator_escala_x) && (y>=salV[1]* fator_escala_y) && (y<=salV[3] * fator_escala_y))
        {        
          waitForIt(salV[0], salV[1], salV[2], salV[3]); // Função salvar

          if((on5_hora_temp2 == off5_hora_temp2) && (on5_minuto_temp2 >= off5_minuto_temp2))
          {
            setFont(SMALL, 255, 0, 0, 0, 0, 0);
            myGLCD.print(tabela_textos[170], 20, 205);
            myGLCD.print(tabela_textos[169], 20, 222);
          }

          if(off5_hora_temp2 < on5_hora_temp2)
          {
            setFont(SMALL, 255, 0, 0, 0, 0, 0);
            myGLCD.print(tabela_textos[170], 20, 205);
            myGLCD.print(tabela_textos[169], 20, 222);
          }

          if((on5_hora_temp2 == off5_hora_temp2) && (off5_minuto_temp2 > on5_minuto_temp2))
          {
            on5_minuto = on5_minuto_temp2;
            on5_hora = on5_hora_temp2;
            off5_minuto = off5_minuto_temp2;
            off5_hora = off5_hora_temp2;
            temporizador_5_ativado = temporizador_5_ativado_temp2;
            dispScreen=38;
            clearScreen();
            TimerScreen();
            salvar_timers_EEPROM();
          }
          if(on5_hora_temp2 < off5_hora_temp2)
          {
            on5_minuto = on5_minuto_temp2;
            on5_hora = on5_hora_temp2;
            off5_minuto = off5_minuto_temp2;
            off5_hora = off5_hora_temp2;
            temporizador_5_ativado = temporizador_5_ativado_temp2;
            dispScreen=38;
            clearScreen();
            TimerScreen();
            salvar_timers_EEPROM();
          }
        }
        if ((x >= 21) && (x <= 65) && (y >= 45) && (y <= 88))           // Hora ligar mais 
        {
          waitForIt(21, 45, 65, 88);
          on5_hora_temp2 += 1;
          if(on5_hora_temp2 > 23)
          {
            on5_hora_temp2 = 0;
          }
          config_timer();
        } 
        if ((x >= 21) && (x <= 65) && (y >= 135) && (y <= 178))           // Hora ligar menos
        {
          waitForIt(21, 45, 65, 88);
          on5_hora_temp2 -= 1;
          if(on5_hora_temp2 < 0)
          {
            on5_hora_temp2 = 23;
          }
          config_timer();
        } 

        if ((x >= 89) && (x <= 133) && (y >= 45) && (y <= 88))           // Minuto ligar mais 
        {
          waitForIt(89, 45, 133, 88);
          on5_minuto_temp2 += 1;
          if(on5_minuto_temp2 > 59)
          {
            on5_minuto_temp2 = 0;
          }
          config_timer();
        } 
        if ((x >= 89) && (x <= 133) && (y >= 135) && (y <= 178))           // Minuto ligar menos
        {
          waitForIt(89, 135, 133, 178);
          on5_minuto_temp2 -= 1;
          if(on5_minuto_temp2 < 0)
          {
            on5_minuto_temp2 = 59;
          }
          config_timer();
        }
        if ((x >= 187) && (x <= 231) && (y >= 45) && (y <= 88))           // Hora desligar mais 
        {
          waitForIt(187, 45, 231, 88);
          off5_hora_temp2 += 1;
          if(off5_hora_temp2 > 23)
          {
            off5_hora_temp2 = 0;
          }
          config_timer();
        } 
        if ((x >= 187) && (x <= 231) && (y >= 135) && (y <= 178))           // Hora desligar menos
        {
          waitForIt(187, 135, 231, 178);
          off5_hora_temp2 -= 1;
          if(off5_hora_temp2 < 0)
          {
            off5_hora_temp2 = 23;
          }
          config_timer();
        } 

        if ((x >= 255) && (x <= 299) && (y >= 45) && (y <= 88))           // Minuto desligar mais 
        {
          waitForIt(255, 45, 299, 88);
          off5_minuto_temp2 += 1;
          if(off5_minuto_temp2 > 59)
          {
            off5_minuto_temp2 = 0;
          }
          config_timer();
        } 
        if ((x >= 255) && (x <= 299) && (y >= 135) && (y <= 178))           // Minuto desligar menos
        {
          waitForIt(255, 135, 299, 178);
          off5_minuto_temp2 -= 1;
          if(off5_minuto_temp2 < 0)
          {
            off5_minuto_temp2 = 59;
          }
          config_timer();
        }
        if ((x>=domI[0]-20) && (x<=domI[2]+20) && (y>=domI[1]* fator_escala_y) && (y<=domI[3] * fator_escala_y))           // Ativar / desativar timer
        {
          waitForIt(domI[0]-20, domI[1], domI[2]+20, domI[3]);
          if(temporizador_5_ativado_temp2 == 0)
          {
            temporizador_5_ativado_temp2 = 1;
          }
          else
          {
            temporizador_5_ativado_temp2 = 0;
          }
          config_timer(); 
        }  
      }
      break;
    case 40://---------------------------------------- Configurar leds ----------------------------
      if ((x>=menU[0]* fator_escala_x) && (x<=menU[2]* fator_escala_x) && (y>=menU[1]* fator_escala_y) && (y<=menU[3] * fator_escala_y))           // Volta ao menu 1
      {
        waitForIt(menU[0], menU[1], menU[2], menU[3]);   
        dispScreen=1;
        clearScreen();
        menuScreen();
      }
      if ((x>=tanD[0]* fator_escala_x) && (x<=tanD[2]* fator_escala_x) && (y>=tanD[1]* fator_escala_y) && (y<=tanD[3] * fator_escala_y))           // Testar leds
      {
        waitForIt(tanD[0], tanD[1], tanD[2], tanD[3]);   
        dispScreen=3;
        clearScreen();
        testScreen(true);
      }
      if ((x>=tesT[0]* fator_escala_x) && (x<=tesT[2]* fator_escala_x) && (y>=tesT[1]* fator_escala_y) && (y<=tesT[3] * fator_escala_y))           // Alterar valores led
      {
        waitForIt(tesT[0], tesT[1], tesT[2], tesT[3]);   
        dispScreen=5;
        WorB=WHITE;
        clearScreen();
        ledSetScreen(); 
      }
      if ((x>=temC[0]* fator_escala_x) && (x<=temC[2]* fator_escala_x) && (y>=temC[1]* fator_escala_y) && (y<=temC[3] * fator_escala_y))           // Luz Noturna
      {
        waitForIt(temC[0], temC[1], temC[2], temC[3]);   
        dispScreen=36;
        clearScreen();
        luz_noturna(true);
      }    
      break;
    }
  }
}




