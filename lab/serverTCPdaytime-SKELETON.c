/* ------------------------------------------------------------------------
TCP Daytime Lab:   the Server

When running, use
   ss -lt  | grep srvPort
to check the socket status of listening TCP sockets

------------------------------------------------------------------------ */

#include "myNetLib.h"

#include <time.h>

void    TCPdaytimed( int fd );

#define QLEN        32
#define MAXSTRLEN   256

int	    masterSkt ;      // Listening socket
int	    connectedSkt ;   // Connected socket

//------------------------------------------------------------
//  Hanld SIGINT  or SIGTERM 
//------------------------------------------------------------
void goodbye(int sig) 
{
    /* Mission Accomplished */
    printf( "\n### The TCP daytime Server (pid = %d) have been " , getpid() );  
    switch( sig )
    {
        case SIGTERM:
            printf("nicely asked to TERMINATE by SIGTERM ( %d ).\n" , sig );
            break ;

        case SIGINT:   // Ctrl-C
            printf("INTERRUPTED by SIGINT ( %d )\n" , sig );
            break ;
            
        default:
            printf("unexpectedly SIGNALed by ( %d )\n" , sig );

    }


    // Close any possibly open sockets

    printf( "\nGoodbye\n\n" );  

    exit(0) ;     
}

/*------------------------------------------------------------------------
 * main - Iterative TCP server for DAYTIME service
 *------------------------------------------------------------------------
 */

int main(int argc, char *argv[])
{
    struct  sockaddr_in cliSock ;       // the from address of a client	
    unsigned short      srvPort = 13 ;  // Default server port 
    unsigned int        alen;           // The from-address length
    
	switch ( argc ) 
	{

        // MISSING CODE

      default:
        err_quit("usage: command [port]\n");
    }

	masterSkt = socketTCP( /* MISSING CODE */ ) ;

    // Prepare to handle signals
    
    // Start lissining at masterSkt 
    
    
	while ( 1 ) 
	{
		alen  = sizeof( cliSock );
		connectedSkt = Accept(  /* MISSING CODE */ );

		TCPdaytimed( connectedSkt );

		Close( connectedSkt );   // a utility function to serve this client
        
	} // serve the next client
}

/*------------------------------------------------------------------------
 * TCPdaytimed - do TCP DAYTIME protocol
 *------------------------------------------------------------------------
 */

#define MAX_BUF_SZ  200

void TCPdaytimed( int sd )
{
    char   *pts ;       /* pointer to time string   */
    time_t  now ;       /* current time             */
	char    ipStr[20] ;

    struct  sockaddr_in  clientSocket ;

    //  Who is calling?
    int alen = sizeof( clientSocket ) ;
    
    // MISSING CODE
    
    printf("\nServing client at %s : %hu\n" , /* Client's IP addr */ , /* Client's port*/  ) ;

	time( &now ) ;
	pts = ctime( &now );    /* WARNING! ctime() is NOT thread-safe */

    unsigned char buff[ MAX_BUF_SZ ] ;
    snprintf( buff , MAX_BUF_SZ , "CustomBuilt DT server: %s" , pts );

	writen( sd, buff, strlen( buff ) ) ;
}
