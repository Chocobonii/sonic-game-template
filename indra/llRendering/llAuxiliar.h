#include "../llManagement/llLoaderFunc.h"

void LL_Gemini_stand(){
    usleep(33);
    glutPostRedisplay();
}

void LL_Gemini_start(){
 glClearColor(0.0,0.0,0.0,0.0);
 glEnable(GL_DEPTH_TEST);
 glEnable(GL_TEXTURE_2D);
 glEnable(GL_BLEND);
 glMatrixMode(GL_PROJECTION);
 glAlphaFunc(GL_GREATER, 0.8);
 glEnable(GL_ALPHA_TEST);
 glLoadIdentity();
 glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
 gluPerspective(60, 0.01,0.01,7000);
 //ImGui_ImplOpenGL2_Init();
 // MODEL LOADING GOES HERE
 // -------------------------------------------------------------------------------------------------------------------------------------------
 LL_Load_Models();
 LL_Load_Textures();
 // -------------------------------------------------------------------------------------------------------------------------------------------
 player->player_y = 1+LL_World->LL_Chunk_Get_Height((int)player->player_x, (int)player->player_z);
}
// ------------------------------------------------------------------------------------------------
void Timer (int value){          // 
    if(player->_id_am < 7){      // 
        player->_id_am ++;       // THIS IS THE ANIMATOR FUNCTION
    }else{                       // IT MOVES THE ID FOR THE ANIMATION
        player->_id_am = 0;      // INDEX TO CAUSE THE MOVEMENT
    }                            // 
    if(air > 0.5){_air_anim = true;}
    if(air < 0.0){_air_anim = false;} 
    if(_air_anim==false){air+=0.01;}else{air-=0.01;}
    // ---------------------------------------------
    if(LL_Is_Jump && player->player_y < (LL_Height_stamp+LL_Jump_Height)){
        player->player_y += LL_Speed_y;
    }

    if(player->player_y >= (LL_Height_stamp+LL_Jump_Height)){
        LL_Is_Jump = false;
    }
    
    if(!LL_Is_Jump && player->player_y >= (1+LL_World->LL_Chunk_Get_Height((int)player->player_x, (int)player->player_z))){
        player->player_y -= LL_Gravity;
    }

    if(player->player_y < (1+LL_World->LL_Chunk_Get_Height((int)player->player_x, (int)player->player_z))){
        LL_On_Floor = true;
        LL_Is_Jump = false;
        //LL_Jump = false;
        player->player_y = 1+LL_World->LL_Chunk_Get_Height((int)player->player_x, (int)player->player_z);
    }

    // ---------------------------------------------
    glutTimerFunc(30, Timer, 0); // 
}
// ------------------------------------------------------------------------------------------------