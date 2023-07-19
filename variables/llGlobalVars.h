// ------------------------------------
int BON_SCREEN_W = 640; // THIS IS THE SCREEN RESOLUTION
int BON_SCREEN_H = 480; // FOR THE DRAWING WINDOW (NOT RELEVANT AT ALL)
// ---------------------------------------------------
bool up=false,down=false,left=false,right=false; // KEYBOARD INPUT
// ---------------------------------------------------
int LL_Mouse_oldx = 0;  //  
int LL_Mouse_oldy = 0;  // THIS ALLOWS MOUSE DRAGGING DETECTION
int LL_Mouse_sensitv=2; // AND PROVIDES SENSITIVITY
bool _Clicked = false;  // 
// ------ PERLIN MANAGER VARIABLES -------------
int numX = 512,
    numY = 512,
    numOctaves = 8;
double persistence = 0.5;

#define maxPrimeIndex 10
int primeIndex = 0;
// ---------------------------------------------
int primes[maxPrimeIndex][3] = {
  { 995615039, 600173719, 701464987 },
  { 831731269, 162318869, 136250887 },
  { 174329291, 946737083, 245679977 },
  { 362489573, 795918041, 350777237 },
  { 457025711, 880830799, 909678923 }, 
  { 787070341, 177340217, 593320781 },
  { 405493717, 291031019, 391950901 },
  { 458904767, 676625681, 424452397 },
  { 531736441, 939683957, 810651871 },
  { 997169939, 842027887, 423882827 }
};
float height_map1;
int world_freq = 100;
/*
================================
* GLOBAL CONSTANTS FOR PHYSICS *
================================
*/
#define PHY_PI 3.14159
float dt = 0.02;   // delta time - time step
float rho = 0.5;  // density of the air
// ---------------------------------------------
int LL_Loc_x = 0,LL_Loc_y = 0;       // HUGE LOCATION FOR THE CHUNK SYSTEM
int LL_Old_x = 8,LL_Old_y = 8;       // BIG SCALE OF THE PLAYER LOCATION
// ---------------------------------------------
// -    THESE ARE THE TEXTURES LOADED INGAME   - 
// ---------------------------------------------
GLuint LL_FLOOR_TEMPLATE;
GLuint LL_GRASS_TEXTURES;
GLuint LL_WATER_TEXTURES;
GLuint LL_SKY_PX;
GLuint LL_SKY_NX;
GLuint LL_SKY_PY;
GLuint LL_SKY_NY;
GLuint LL_SKY_PZ;
GLuint LL_SKY_NZ;
// ---------------------------------------------
float air = 0.0;
bool _air_anim = false;
// ---------------------------------------------
float LL_Ocean_Lvl = 38;
bool  LL_Is_Underwater = false;
// ----- Y CONSTANTS FOR Vertical PHYSICS ------
float LL_Gravity = 1.0;
bool  LL_On_Floor= true;
bool  LL_Is_Jump = false;
float LL_Speed_y = 0.981;
bool  LL_Jump    = false;
float LL_Height_stamp = 0;
int LL_Jump_Height = 8;