Arduino_Code__Second_Robot2022
Arduino Code in C for the secondary robot in Eurobot 2022 Age of Bots This code includes 7 Servos Control, 2 Air-pumps Control, one 600rpm motor control and one pump relay. these are the cases :

  case 'S':statuette.upFor(10);break;
  case 's':statuette.downFor(10);break;
  
  case 'B':batraR.up();break;
  case 'b':batraR.down();break;

  case 'Z':batraL.up();break;
  case 'z':batraL.down();break;

  case 'C':catchR.up();break;
  case 'c':catchR.down();break;

  case 'D':catchL.up();break;
  case 'd':catchL.down();break;

  case 'F':flip.up();break;
  case 'f':flip.down();break;

  case 'T':fouille.up();break;
  case 't':fouille.down();break;

  case 'P': digitalWrite(pompe_stat,HIGH);break;
  case 'p': digitalWrite(pompe_stat,LOW);break;

  case 'V' : digitalWrite(ectrovanne,HIGH);break;
  case 'v' : digitalWrite(ectrovanne,LOW);break; 
  
  case 'Q' : digitalWrite(pompe_catch,HIGH);break; 
  case 'q' : digitalWrite(pompe_catch,LOW);break; 
  
  case 'm' :     analogWrite(motor_f,100);    
                 analogWrite(motor_b,0); 
                 delay(100);
                 analogWrite(motor_f,0);    
                 analogWrite(motor_b,0); break;
                  
  case 'M' :analogWrite(motor_f,0);
                 analogWrite(motor_b,100);
                 delay(100);
                 analogWrite(motor_f,0);    
                 analogWrite(motor_b,0);break;
///////////////////////////// Sequences /////////////////////////////

   case 'h' : sequence_batratte();break;
   case 'H' : sequence_batratte_1();break;
   case 'e' : sequence_batratte_2();break;
   case 'a' : sequence_stat_up();break;
   case 'A' : sequence_stat_down();break;
   case 'y' : catch_down(10);break;
   case 'Y' : catch_up(10);break;
   case 'n' : sequence_catch_down();break;
   case 'j' : sequence_catch_hex();break;
   case 'J' : sequence_catch_hex_down();break;
   case 'i' : initialisation();break;
   case 'g' : sequence_carre();break;
