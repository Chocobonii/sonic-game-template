// ***********************************************
// *  THESE ARE THE CAMERA MOVEMENT AND CONTROLS *
// ***********************************************
// ---------------------------------------------------------------
class LL_Camera {
    public:
        float _xfrom = 0, _yfrom = 0, _zfrom = 0;
        int   _Zoom = 10;
        float _AngleH = 0;      // --------------------
        float _AngleV = 25;     // THIS IS THE CAMERA
        LL_Camera();            // AND IT'S ANGLES
        void LL_Calculate_Cam(float _xto, float _yto, float _zto);
        void LL_Draw_Camera(float _xto, float _yto, float _zto);
        // -----------------------------------------------------
};
// ----------------------------------------------------------------
LL_Camera::LL_Camera(){} // THIS IS THE CAMERA CONSTRUCTOR
// ----------------------------------------------------------------
void LL_Camera::LL_Calculate_Cam(float _xto, float _yto, float _zto){
    _xfrom = _xto+cos(((_AngleH+90)*3.14159)/180)*_Zoom;
    _yfrom = _yto+tan(((_AngleV)*3.14159)/180) * 10;
    _zfrom = _zto-sin(((_AngleH+90)*3.14159)/180)*_Zoom;
}
// ----------------------------------------------------------------
void LL_Camera::LL_Draw_Camera(float _xto, float _yto, float _zto){
    gluLookAt(_xfrom, _yfrom, _zfrom, _xto, _yto+1, _zto,0,1,0);
    // ---------- THIS HAS A FEW AMBIENT MOVEMENTS ----------------
    if(_yfrom < LL_Ocean_Lvl){        // THIS PART OF THE CAMERA 
        LL_Is_Underwater = true;      // IS NOT RELEVANT
        LL_Env_Set_Fog_Wat(1,25,0.8);//
    }else{                            // IT IS JUST THE CAMERA EFFECTS
        LL_Is_Underwater = false;     // FOR WATER
        LL_Env_Set_Fog_Amb(5,100,0.05);
    }
    // ------------------------------------------------------------
}
// ----------------------------------------------------------------
LL_Camera *LL_Cam = new LL_Camera();