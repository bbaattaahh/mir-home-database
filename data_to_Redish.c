#include <stdio.h>
#include <stdlib.h>
#include <hiredis/hiredis.h>
#include <stdarg.h> 
#include <string.h>

// Arra alkalmas hogy a megfelelő formátumban előkészített fájlokat feltültse a redis adatbázisba// mir név 0 Absztrakt_szövege 0
int main(int argc, char **argv){
   redisContext *redis;
   redisReply *replay;
   int i;
   int j;
//   long long int k;
   char c[200],junk[2];
   char *e;
   redisContext *d;
  
   e=calloc(10000, sizeof(char));
   e[0]='\0';

    FILE *fp;                                     /* fájl mutató (file pointer/handle) */ 
        fp=fopen("to_the_database.txt", "r");                /* megnyitás */
		if (fp==NULL) {
			printf("Nem sikerült megnyitni!");

        	 		}
		else {
		        	
		      redis  = redisConnect("127.0.0.1", 6379);
		      if(redis->err){
			  printf("Error in connection: %s\n", redis->errstr);
			  return(0);
			}
		       
		      do{ 
		       printf("Sikerült megnyitni!\n");
		        fscanf(fp,"%s", c); 
		       printf("c-n túl");	
			fscanf(fp,"%s",junk);
                   
			
			fscanf(fp,"%s",e);
                     if (!feof(fp)) {
			do{
			 replay = redisCommand(redis, "SADD %s %s", c,e);
                         printf("%s\n", e);
			 freeReplyObject(replay);
			 e[0]='\0';
			 fscanf(fp,"%s",e);
			}while (strcmp(e,"0")!=0);
		     }
			
		      }while (!feof(fp));
		//	replay = redisCommand(redis, "Smembers %s %s", c, e);
			
		//	for(i = 0; i < replay->elements; i++){
		//	  printf("%s", replay->element[i]->str);
		//	         }
			         
		//	printf("%s", str);         
			 //freeReplyObject(replay);
			
			/*
       
		       do{	
         	            c[strlen(c)-1] = '\0'; 
         	           
	       		    replay = redisCommand(redis, "EXISTS %s", c);
	                    j=("%lld", replay->integer);
		       	    
			    
			    if (j!=0) {
			  	  replay=redisCommand(redis, "incr %s", c);

			    }	  
			    else {
				replay = redisCommand(redis, "set %s %lld", c,1); 
				for(i = 0; i < replay->elements; i++){
				  printf("%s", replay->element[i]->str);
			         }
			      }
			
			if(replay == NULL){
			printf("Error during the command: %s\n", redis->errstr);
			return(0);
				}


		
			
			
			
			

			freeReplyObject(replay);

			 			
			
			
			printf("%s", c);
		        fgets(c, 200,fp );        //Ez szedi ki a fölösleges sort!
			c[strlen(c)-1] = '\0';
			printf("\n");             //Csak a küllem miadt!
		
		  
		}while 	(fgets(c, 200,fp )!=NULL);

                     /*   *cc="2sor"; 
		        replay = redisCommand(redis, "mget %s", cc ),         
                        k=printf("%lld\n", replay->integer);
			*/
	
		  
		} 
		redisFree(redis); 
		fclose(fp);                                                              /* bezárás */
                

        // return (0);   
            
            
            

   /* Connecting to database*/ 
   /* redis  = redisConnect("127.0.0.1", 6379);
    if(redis->err){
      printf("Error in connection: %s\n", redis->errstr);
      return(0);
   }

   
   /* Send a command*/
 /*   replay = redisCommand(redis, "set %s 0", c);

   if(replay == NULL){
      printf("Error during the command: %s\n", redis->errstr);
      return(0);
   }

   for(i = 0; i < replay->elements; i++){
      printf("%s\n", replay->element[i]->str);
   }
   freeReplyObject(replay);

   /* Free resources*/
/*   redisFree(redis); */ 
 free(e);
   return(0);
}
