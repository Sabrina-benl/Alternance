#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include <MLV/MLV_all.h>
#include "lutin.h"
#include "ligne.h"


void menu(int L, int H){ 
    
    int xs, ys;
    int longueur,hauteur,x,y=0;
    /* MLV_Font* font_ = MLV_load_font("ARCADE_I.TTF" , 50 );*/
    MLV_Font* font = MLV_load_font( "police3.ttf" , (0.10*L) );
    MLV_Font* font1 = MLV_load_font( "police2.ttf" , (0.06*L) );
    MLV_Font* font2 = MLV_load_font( "police1.ttf" ,((5.9/100)*H) );
    MLV_change_window_size(L,H);	
    MLV_clear_window(MLV_COLOR_DARKRED);
    y=0;
    MLV_get_size_of_text_with_font("PLANNING",&longueur,&hauteur,font);
    MLV_draw_line(L/2,0,L/2,500,MLV_COLOR_BLACK);
    MLV_draw_adapted_text_box_with_font((L/2)-((longueur+23*2)/2),y ,"PLANNING", font,23, MLV_COLOR_DARKRED, MLV_COLOR_WHITE, MLV_COLOR_DARKRED, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER );
  
    MLV_get_size_of_text_with_font("SANTA",&longueur,&hauteur,font);
    MLV_draw_adapted_text_box_with_font((L/2)-((longueur+23*2)/2),y +hauteur+23 ,"SANTA", font,23, MLV_COLOR_DARKRED, MLV_COLOR_WHITE, MLV_COLOR_DARKRED, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER );
    y=y +hauteur+23;
   
    MLV_get_size_of_text_with_font("Planning lignes",&longueur,&hauteur,font1);
    MLV_draw_adapted_text_box_with_font((L/2)-((longueur+23*2)/2),y +hauteur+23*2 ,"Planning lignes", font1,23, MLV_COLOR_DARKRED, MLV_COLOR_WHITE, MLV_COLOR_DARKRED, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER );
    y=y +hauteur+23;
    int bouton_centre_y=y;
    MLV_get_size_of_text_with_font("Planning lutins",&longueur,&hauteur,font1);
    MLV_draw_adapted_text_box_with_font((L/2)-((longueur+23*2)/2),y +hauteur+23*2 ,"Planning lutins", font1,23, MLV_COLOR_DARKRED, MLV_COLOR_WHITE, MLV_COLOR_DARKRED, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER );
    y=y +hauteur+23;
    MLV_get_size_of_text_with_font("Generer nouveau planning",&longueur,&hauteur,font1);
    MLV_draw_adapted_text_box_with_font((L/2)-((longueur+23*2)/2),y +hauteur+23*2 ,"Generer nouveau planning", font1,23, MLV_COLOR_DARKRED, MLV_COLOR_WHITE, MLV_COLOR_DARKRED, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER );
    y=y +hauteur+23;
    MLV_get_size_of_text_with_font("Quitter",&longueur,&hauteur,font1);
    MLV_draw_adapted_text_box_with_font((L/2)-((longueur+23*2)/2),y +hauteur+23*2 ,"Quitter", font1,23, MLV_COLOR_DARKRED, MLV_COLOR_WHITE, MLV_COLOR_DARKRED, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER );
  
    MLV_draw_circle( ((3.1/100)*L), ((4.1/100)*H), ((3.1/100)*L), MLV_COLOR_RED );
    MLV_draw_text_with_font(((0.9/100)*L),((1/100)*H), "7", font2, MLV_COLOR_RED);


    MLV_actualise_window();
   
    while(1){
        MLV_get_size_of_text_with_font("Planning lignes",&longueur,&hauteur,font1);
        /*planning global*/
       
        if( MLV_get_mouse_button_state( MLV_BUTTON_LEFT ) == MLV_PRESSED ){
            MLV_get_mouse_position(&xs,&ys);
            MLV_actualise_window();

            
            if(xs> ((3.1/100)*L) -((3.1/100)*L) && xs<((3.1/100)*L) +((3.1/100)*L) && ys>((4.1/100)*L) -((3.1/100)*L)&& ys < ((4.1/100)*L) +((3.1/100)*L) ){
                if(L == 800){
                    L=1600;
                    H=1200;
                }
                else{
                    L=800;
                    H=600;
                }
                menu(L,H);
                return;
            }
            
            if(xs> (L/2)-((longueur+23*2)/2) && xs<(L/2)+((longueur+23*2)/2) && ys>bouton_centre_y && ys<bouton_centre_y+hauteur){
                MLV_clear_window(MLV_COLOR_BLACK);
                  afficher_planning_ligne(L,H);
                MLV_actualise_window();
            }
            
            /*planning lutin*/
            y=bouton_centre_y +hauteur+23;
            MLV_get_size_of_text_with_font("Planning lutins",&longueur,&hauteur,font1);
            if(xs>(L/2)-((longueur+23*2)/2) && xs<(L/2)+((longueur+23*2)/2) && ys>y && ys<y+hauteur){
                MLV_clear_window(MLV_COLOR_BLACK);
                /*planning_lutin(L,H);*/
                afficher_planning(L,H);
                MLV_actualise_window();
            }
            y=y +hauteur+23;
            /*ajouter/supprimer un lutin */
            MLV_get_size_of_text_with_font("Generer nouveau planning",&longueur,&hauteur,font1);
            if(xs>(L/2)-((longueur+23*2)/2) && xs<(L/2)+((longueur+23*2)/2) && ys>y && ys<y+hauteur){
                MLV_clear_window(MLV_COLOR_BLACK);
                /* planning_lutin();*/
                MLV_actualise_window();
            }
       
            y=y +hauteur+23;
            /*QUITTER*/
            
            MLV_get_size_of_text_with_font("Quitter",&longueur,&hauteur,font1);
            MLV_draw_rectangle((L/2)-((longueur+23*2)/2),y+23,longueur+23*2,hauteur+23*2,MLV_COLOR_WHITE);
            if(xs>(L/2)-((longueur+23*2)/2) && xs<(L/2)+((longueur+23*2)/2) && ys>y+23 && ys<y+hauteur+23*2){
                MLV_free_window();
                exit(EXIT_SUCCESS);
            }
        }
    }

}

int main(){
  
  MLV_create_window("planning","planning", 1600, 1200 );
  MLV_clear_window(MLV_COLOR_BLACK);
 


  menu(1600,1200);
    
    
  MLV_actualise_window();
  MLV_wait_seconds( 110 );
  MLV_free_window();
  exit(0);
}

  
