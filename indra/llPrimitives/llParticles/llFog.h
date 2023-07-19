// ========================================================================
// =  THE FUNCTION THAT GENERATES THE FOG AND GIVES THE PROPERTIES TO IT  =
// ========================================================================
// ----------------------------------------------------------------------------------
void LL_Env_Set_Fog_Amb(float strt , float end ,float dens){  // fog function to hide that the world is being generated
 GLuint filter;                                      // just a variable
 glClearColor(0.5,0.5,0.7,1.0);                      // set the background color
 float FogColor[4] = {0.5,0.5,0.7,1.0};              //
 glFogi(GL_FOG_MODE , GL_LINEAR);                    // enable the fog mode on linear
 glFogfv(GL_FOG_COLOR , FogColor);                   // set the fog color
 glFogf(GL_FOG_DENSITY , dens );                     // set the fog density
 glHint(GL_FOG_HINT , GL_DONT_CARE);                 // start a hint
 glFogf(GL_FOG_START , strt );                       // set where fog starts 
 glFogf(GL_FOG_END , end);                           // set where fog ends
}
// -----------------------------------------------------------------------------------
void LL_Env_Set_Fog_Wat(float strt , float end ,float dens){  // fog function to hide that the world is being generated
 GLuint filter;                                      // just a variable
 float FogColor[4] = {0.1,0.2,0.3,0.0};              //
 glClearColor(0.1,0.2,0.3,0.0);                      // set the background color
 glFogi(GL_FOG_MODE , GL_LINEAR);                    // enable the fog mode on linear
 glFogfv(GL_FOG_COLOR , FogColor);                   // set the fog color
 glFogf(GL_FOG_DENSITY , dens );                     // set the fog density
 glHint(GL_FOG_HINT , GL_DONT_CARE);                 // start a hint
 glFogf(GL_FOG_START , strt );                       // set where fog starts 
 glFogf(GL_FOG_END , end);                           // set where fog ends
}
// ------------------------------------------------------------------------------------