//
//  world.hpp
//  vesper
//
//  Created by Gaspar Rodriguez Valero on 8/12/16.
//  Copyright © 2016 Skyscrapers. All rights reserved.
//

#ifndef world_hpp
#define world_hpp

#include "NPC.hpp"
#include "gestor_eventos.hpp"

class world {
public:
    world();
    ~world();
    void anyadirBotiquin(botiquin * hijo);
    void anyadirFuente(fuente * hijo);
    void anyadirComida(comida * hijo);
    void anyadirAlarma(alarma * hijo);
    void anyadirNPC(NPC * hijo);
    void anyadirAltavoz(altavoz * hijo);
    void update();
private:
    void ConstruirBlackBoard();
    //void NPCsAvisados(NPC * npc);
    //void NPCsCercanos(vector3D  NPCactual);
    //void ObjetosCercanos(vector3D  NPCactual);
    void PosicionJugador(vector3D  NPCactual);
    void ComprobacionFuentesAlarmas();
    float CalcularDistancia(vector3D a,vector3D b);
    vector<NPC*> enemigos;
    vector<botiquin*> botiquin_mundo;
    vector<fuente*> fuente_mundo;
    vector<comida*> comida_mundo;
    vector<alarma*> alarma_mundo;
    vector<altavoz*> altavoces_mundo;
    void cargarMapa();
    BlackBoard * infoWorld;
    
};

#endif /* world_hpp */
