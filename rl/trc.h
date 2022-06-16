extern I trcfd;
void trc1();

#ifdef TRC
#define ED                "\x1b[H\x1b[2J" //!< (e)rase (d)isplay command
#define trcrst() (dprintf(trcfd,"%s",ED))
#define trc(arg...) (dprintf(trcfd,arg))
#else
#define trcrst() (0)
#define trc(arg...) (0)
#endif


