// #include <iostream>

// #include "Ambassador.hpp"
// #include "Duke.hpp"
// #include "Assassin.hpp"
// #include "Contessa.hpp"
// #include "Captain.hpp"
// #include "Game.hpp"


// int main(){

//     using namespace coup;
//     std::cout<<"Choose the number of players (2 to 6)";

//     size_t playerNum;
//     std::cin>>playerNum;
    
//     //create players
//     Player *p1, *p2, *p3, *p4, *p5, *p6;
//     std::vector<Player*> players {p1, p2, p3, p4, p5, p6};
//     Game g;
//     size_t pick;
//     for(size_t i = 1; i <= playerNum; ++i){

//         std::cout<<"choose class for player #"<<i<<std::endl;
//         std::cout<<"1 for Ambassador, 2 for assassin, 3 for Captatin, 4 for Duke and 5 for Contessa"<<std::endl;
//         std::cin>>pick;

//         switch (pick)
//         {
//         case 1:
//             players.at(i) = new Ambassador{g, "Player " + std::to_string(i)};
//             break;
//         case 2:
//             players.at(i) = new Assassin{g, "Player " + std::to_string(i)};
//             break;
//         case 3:
//             players.at(i) = new Captain{g, "Player " + std::to_string(i)};
//             break;
//         case 4:
//             players.at(i) = new Duke{g, "Player " + std::to_string(i)};
//             break;
//         case 5:
//             players.at(i) = new Contessa{g, "Player " + std::to_string(i)};
//             break;
        
//         default:
//             std::cout<<"Invalid choice, try again"<<std::endl;
//             --i;
//             break;
//         }
//     }

//     //start game
//     size_t turn = 1;
//     int action;
//     std::cout<<"Game started, action menu:\n"
//     "check balance: 0\n"
//     "income: 1\n"
//     "foregin aid: 2\n"
//     "coup 3\n"
//     "Block (contessa and captain only): 4\n"
//     "Tax (Duke only) : 5\n"
//     "Transfer (ambassador only): 6\n "
//     "Steal (Captain only): 7\n "
//     <<std::endl; 

//     while(g.get_count() >1){
//         if(turn ==0){
//             turn++;
//         }
//         std::cout<<"Player "<<turn<<" turn's, choose action "<<std::endl;
//         std::cin>>action;

//         switch (action)
//         {

//         case 0:
//             std::cout<<"coins "<<players.at(turn)->coins()<<std::endl;;
//             break;
//         case 1:
//             players.at(turn)->income();
//             turn = (turn+1) % (playerNum +1);
//             break;
//         case 2:
//             players.at(turn)->foreign_aid();
//             turn = (turn+1) % (playerNum +1);
//             break;
//         case 3:
//         try{
//             std::cout<<"Choose player to coup against"<<std::endl;
//             std::cin>>pick;
//             if(pick == turn){
//                 std::cout<<"Cant coup against yourself"<<std::endl;
//                 continue;
//                 }
//             players.at(turn)->coup(*players.at(pick));
//             turn = (turn+1) % (playerNum +1);
//             std::cout<<"Couped player "<<pick<<" succesfully"<<std::endl;
//             break;
//         }
//         catch( const std::exception & ex ) {
//             std::cerr << ex.what() << std::endl;
//         }
//         case 4:
//             players.at(turn)->foreign_aid();
//             turn = (turn+1) % (playerNum +1);
//             break;
//         case 5:
//             if(players.at(turn)->role() != "Duke"){
//                 std::cout<<"Youre not a Duke"<<std::endl;
//                 break;
//             }
//             dynamic_cast<Duke*> (players.at(turn))->tax();
//             turn = (turn+1) % (playerNum +1);
//             break;      
//         case 6:
            
//             if(players.at(turn)->role() != "Ambassador"){
//                 std::cout<<"Youre not a Ambassador"<<std::endl;
//                 break;
//             }
//             size_t pick2;
//             std::cout<<"choose target and recepient exmp: 3 5"<<std::endl;
//             std::cin>>pick>>pick2;
//             dynamic_cast<Ambassador*> (players.at(turn))->transfer(*players.at(pick), *players.at(pick2));
//             turn = (turn+1) % (playerNum +1);
//             break;     
//         case 7:
            
//             if(players.at(turn)->role() != "Captain"){
//                 std::cout<<"Youre not a Captain"<<std::endl;
//                 break;
//             }
//             std::cout<<"choose target:"<<std::endl;
//             std::cin>>pick;
//             dynamic_cast<Captain*> (players.at(turn))->steal(*players.at(pick));
//             turn = (turn+1) % (playerNum +1);
//             break;
//         default:
//             break;
//         }

        

//     }
//     std::cout<<"The winner is: "<<g.winner()<<std::endl;        
//     return 0;
// }