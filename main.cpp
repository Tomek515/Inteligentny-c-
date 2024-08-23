#include <iostream>
int menuglowne;

std::string numer;

 
   void menu(){
    std::cout << "1.Połączenia" << std::endl;
 std::cout << "2.Kontakty" << std::endl;
 std::cout << "3.SMS" << std::endl;
 
   }
  


 void run(){
    
    menu();
    std::cin >> menuglowne;

     switch(menuglowne){
    case 1: // wybieranie numeru
    system( "cls" );
    std::cout << "wprowadz numer, wciśnij dwa aby wrócić do menu" << std::endl;  
    //std::string numer;

    std::cin>> numer;
    if (numer.length()==9)//wprowadzenie poprawnego numeru 
    {
      std::cout << "Dzwonienie" << numer << std::endl; 
      std::cout << "Wciśnij Enter zeby przerwać" << std::endl; 
      getchar();
      getchar();
      run();
    }
    else if(numer=="2"){// opuszczenie menu wybierania numeru
      run();
    }
    else {  //wprowadzenie niepoprawnegu numeru, ponowne wybieranie lub powrót do menu
                    std::cout << "Numer musi składać się z 9 cyfr" << std::endl; 
                    std::cout << "wprowadz numer, wciśnij dwa aby wrócić do menu" << std::endl;  
                    
                    std::cin>> numer;
                    if (numer.length()==9)
                    {
                      std::cout << "Dzwonienie" << numer << std::endl; 
                      std::cout << "Wciśnij Enter zeby przerwać" << std::endl; 
                      getchar();
                      getchar();
                      run();
                    }
                      else if(numer=="2"){
                      run();
                      }
                    else {
                    std::cout << "Numer musi składać się z 9 cyfr" << std::endl; 
                    std::cout << "wprowadz numer, wciśnij dwa aby wrócić do menu" << std::endl;  
      
      
  
    }
     
    }
    

    break;

    case 2: // wybieranie sms
    system( "cls" );
    std::cout << "wprowadz numer" << std::endl;  
    break;

    case 3: // ksiażka telefoniczna 
    system( "cls" );
    std::cout << "wprowadz numer" << std::endl;  
    break;
   }
 }
int main (){
    
run();

 return 0;
 } 
   

 