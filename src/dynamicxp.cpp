/*
Credits
Script reworked by Micrah/Milestorme and Poszer (Poszer is the Best)
Module Created by Micrah/Milestorme
Original Script from AshmaneCore https://github.com/conan513 Single Player Project 
*/
#include "Configuration/Config.h"
#include "ScriptMgr.h"
#include "Player.h"
#include "Chat.h"


class spp_dynamic_xp_rate : public PlayerScript
{
    public:
        spp_dynamic_xp_rate() : PlayerScript("spp_dynamic_xp_rate") { };

        void OnLogin(Player* player) override
       {
            if (sConfigMgr->GetOption<bool>("Dynamic.XP.Rate.Announce", true))
               {
               ChatHandler(player->GetSession()).SendSysMessage("This server is running the |cff4CFF00Level Dynamic XP |rmodule.");
               }
       }
        void OnGiveXP(Player* player, uint32& amount, Unit* /*victim*/) override
       {

        if (player->getClass() != CLASS_DEATH_KNIGHT && sConfigMgr->GetOption<bool>("Dynamic.XP.Rate", true))
        
	   {
           if (player->getLevel() <= 9)
            amount *= sConfigMgr->GetOption<int32>("Dynamic.XP.Rate.1-9", 1);

           else if (player->getLevel() <= 19)
            amount *= sConfigMgr->GetOption<int32>("Dynamic.XP.Rate.10-19", 2);

           else if (player->getLevel() <= 29)
            amount *= sConfigMgr->GetOption<int32>("Dynamic.XP.Rate.20-29", 3);

           else if (player->getLevel() <= 39)
            amount *= sConfigMgr->GetOption<int32>("Dynamic.XP.Rate.30-39", 4);

           else if (player->getLevel() <= 49)
            amount *= sConfigMgr->GetOption<int32>("Dynamic.XP.Rate.40-49", 5);

           else if (player->getLevel() <= 57)
            amount *= sConfigMgr->GetOption<int32>("Dynamic.XP.Rate.50-57", 6);

           else if (player->getLevel() <= 67)
            amount *= sConfigMgr->GetOption<int32>("Dynamic.XP.Rate.60-67", 7);

           else if (player->getLevel() <= 79)
            amount *= sConfigMgr->GetOption<int32>("Dynamic.XP.Rate.70-79", 8);

        }

     }
    
};

void AddSC_dynamic_xp_rate()
{
    new spp_dynamic_xp_rate();
}
