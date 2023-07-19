// ****************************************************************
// * THIS PART WILL BE THE FUNCTION WHICH WILL RENDER OUR OBJECTS *
// ****************************************************************
//------------------------------------------------------------------
void ll_Obj_Draw_Model( double vert_map[9][9000], double uv_map[6][9000],int vert_num, GLuint Texture){
  glPushMatrix();                                                 //  
   glBindTexture(GL_TEXTURE_2D, Texture);                         //  THIS FUNCTION WILL DRAW THE OBJECTS
   glColor3f(1.0,1.0,1.0);                                        //  
   glBegin(GL_TRIANGLES);                                         //  --------------------------------------------
    for(int i = 0; i < vert_num; i++){                            //  IT MAKES A LOOP ALONG ALL THE VERTEX
     glTexCoord2f(uv_map[0][i], uv_map[1][i]);                    //  
     glVertex3f(vert_map[0][i], vert_map[1][i], vert_map[2][i]);  //  AND WILL START TO DRAW
                                                                  //  
     glTexCoord2f(uv_map[2][i], uv_map[3][i]);                    //  FOR EACH ONE OF THE VERTEX
     glVertex3f(vert_map[3][i], vert_map[4][i], vert_map[5][i]);  //  IT WILL CREATE A TRIANGLE
                                                                  //  WITH IT'S RESPECTIVE UV MAPPING
     glTexCoord2f(uv_map[4][i], uv_map[5][i]);                    //  AND THAT WILL CREATE
     glVertex3f(vert_map[6][i], vert_map[7][i], vert_map[8][i]);  //  THE OBJECT DRAWN
    }                                                             //  ON THE OPENGL WINDOW
   glEnd();                                                       //  -----------------------------------------------
  glPopMatrix();                                                  //  
}
//----------------------------------------------------------------