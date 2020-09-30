void initText()
{

  glClearColor(1.0, 1.0, 1.0, 1.0);
  glShadeModel(GL_FLAT);
  glEnable(GL_DEPTH_TEST);

  // Read the images
  GLbyte image[256][256][3];
  readRAWImage("brick.raw", image);

  // Get "names" for the textures
    glGenTextures(1,&textureName);

    glBindTexture(GL_TEXTURE_2D, textureName);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
   glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    // Create the texture object
    glTexImage2D(GL_TEXTURE_2D, 0, 3, 256, 256, 0, GL_RGB, GL_UNSIGNED_BYTE,
                 image);

  // Enable textures
  glEnable(GL_TEXTURE_2D);
}
glBindTexture(GL_TEXTURE_2D, textureName);
   glTexCoord2f(0,0);