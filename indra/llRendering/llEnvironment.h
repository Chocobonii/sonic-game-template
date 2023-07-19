#include "../llPrimitives/llSky.h"
// -----------------------------------------------------
void LL_Gemini_water(){
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D,LL_WATER_TEXTURES);
    glBegin(GL_QUADS);
        glTexCoord2d(0.0,0.0);
        glVertex3f( -1000, LL_Ocean_Lvl + air,  -1000 );
        glTexCoord2d(0.0,1000);
        glVertex3f( -1000, LL_Ocean_Lvl + air,   1000 );
        glTexCoord2d(1000,1000);
        glVertex3f(  1000, LL_Ocean_Lvl + air,   1000 );
        glTexCoord2d(1000,0.0);
        glVertex3f(  1000, LL_Ocean_Lvl + air,  -1000 );
    glEnd();
    glPopMatrix();
}
// ----------------------------------------------------
void LL_Gemini_environment(){
    glClearColor(0.5,0.5,0.7,1.0);
    glPushMatrix();
        if(LL_Is_Underwater){glEnable(GL_FOG);}
        glTranslatef(player->player_x,player->player_y,player->player_z);
        glDisable(GL_CULL_FACE);
        LL_World_Skybox(LL_SKY_NX,LL_SKY_NY,LL_SKY_NZ, LL_SKY_PX,LL_SKY_PY,LL_SKY_PZ);
        glEnable(GL_CULL_FACE);
        glDisable(GL_FOG);
    glPopMatrix();
    // *********************************************************
    glPushMatrix();
        //glEnable(GL_FOG);
        glAlphaFunc(GL_GREATER, 0.3);
        glTranslatef(player->player_x,0,player->player_z);
        LL_Gemini_water();
        glAlphaFunc(GL_GREATER, 0.8);
        //glDisable(GL_FOG);
    glPopMatrix();
}
// ----------------------------------------------------