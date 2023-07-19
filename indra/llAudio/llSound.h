#ifdef CL_AUDIO
int LL_Audio_Manager() {
    LL_Sterm->LL_Termios_Log("Loading sound resources");
    sf::Sound LL_Snd_Jump; sf::SoundBuffer LL_Buff_Jump;

    if(!LL_Buff_Jump.loadFromFile("Res/Sound/jump_snd.wav")){ return -1; }else{ LL_Snd_Jump.setBuffer(LL_Buff_Jump); }
    
    while(1)
    {
        //LL_Sterm->LL_Termios_Log("Sound loop is working...");
        if(LL_Is_Jump){LL_Snd_Jump.play();}
        usleep(33);
    }
}
#endif