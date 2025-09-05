
void CONFIGURATION(void)
{
  cls();
  printf(0,0,"---CONFIGURATIONS---");
  printf(1,0,"(1) SAMPLING RATE");
  printf(2,0,"(2) SAMPLING TIME");
  printf(3,0,"(3) FACTORY RESTORE");
  
    if((digitalRead(middleKey)==1)&&(Menu_index==1))
    {
     SAMPLING_RATE();
    }
    if((digitalRead(middleKey)==1)&&(Menu_index==2))
    {
     SAMPLING_TIME();
    }
    if((digitalRead(middleKey)==1)&&(Menu_index==3))
    {
     cls();
     FACTORY_RESTORE();
    }
 


     if((digitalRead(leftKey)==1)){
      if(Menu_index>0){
        Menu_index -= 1;
      }
       
    }
    if((digitalRead(leftKey)==1)){
      if(Menu_index<4){
        Menu_index += 1;
      }
    }

    if(Menu_index==1){
        printf(0,15,"<-");
        printf(1,15,"  ");
        printf(2,15,"  ");
        printf(3,15,"  ");
    }else if(Menu_index==2){
        printf(0,15,"  ");
        printf(1,15,"<-");
        printf(2,15,"  ");
        printf(3,15,"  ");
    }else if(Menu_index==3){
        printf(0,15,"  ");
        printf(1,15,"  ");
        printf(2,15,"<-");
        printf(3,15,"  ");
    }else if(Menu_index==4){
        printf(0,15,"  ");
        printf(1,15,"  ");
        printf(2,15,"  ");
        printf(3,15,"<-");
    }
}