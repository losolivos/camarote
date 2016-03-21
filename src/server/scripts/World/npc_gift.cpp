#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "Player.h"
#include "Guild.h"
#include "SpellMgr.h"
#include "Pet.h"
#include "Spell.h"

class npc_gift : public CreatureScript
{
public:
    npc_gift()
        : CreatureScript("npc_gift") {}

    bool OnGossipHello(Player* player, Creature* creature)
    {

        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Get gift!", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Nothing here", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
        player->SEND_GOSSIP_MENU(907, creature->GetGUID());

        return true;
    }
    std::list<uint64> OnlyFirstGift;
    bool _access;

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action)
    {
        player->PlayerTalkClass->ClearMenus();
        _access = true;

        switch (action)
        {
        case GOSSIP_ACTION_INFO_DEF + 1:
            for (std::list<uint64>::iterator itr = OnlyFirstGift.begin(); itr != OnlyFirstGift.end(); ++itr)
            {
                if (player->GetGUID() == *itr) { player->SendChatMessage("you already got gift!"); _access = false; break; }
            }
            if (_access) { player->AddItem(82453, 1); OnlyFirstGift.push_back(player->GetGUID()); }
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:
            player->CLOSE_GOSSIP_MENU();
            break;
        }
        return true;
    }
};

class npc_jade_serpent_riding_skill : public CreatureScript
{
public:
    npc_jade_serpent_riding_skill()
        : CreatureScript("npc_jade_serpent_riding_skill") {}

    bool OnGossipHello(Player* player, Creature* creature)
    {

        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Get serpent riding skill!", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "What is is?", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Nothing there", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
        player->SEND_GOSSIP_MENU(907, creature->GetGUID());

        return true;
    }
    bool _access;

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action)
    {
        player->PlayerTalkClass->ClearMenus();
        _access = true;

        switch (action)
        {
        case GOSSIP_ACTION_INFO_DEF + 1:
            if (player->GetReputationRank(1271) != REP_EXALTED) { player->SendChatMessage("You do not have reputation"); _access = false; }
            if (_access)
                player->learnSpell(130487, false);
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:
            player->SendChatMessage("Here you can learn the skills of flight on cloud snakes. To do this, you need to have a reputation: Exalted");
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:
            player->CLOSE_GOSSIP_MENU();
            break;
        }
        return true;
    }
};

class npc_new_players_gift : public CreatureScript
{
public:
    npc_new_players_gift()
        : CreatureScript("npc_new_players_gift") {}

    bool OnGossipHello(Player* player, Creature* creature)
    {

        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Get gift!", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Nothing here", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
        player->SEND_GOSSIP_MENU(907, creature->GetGUID());

        return true;
    }
    std::list<uint64> OnlyFirstGift;
    bool _access;

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action)
    {
        player->PlayerTalkClass->ClearMenus();
        _access = true;

        switch (action)
        {
        case GOSSIP_ACTION_INFO_DEF + 1:
            for (std::list<uint64>::iterator itr = OnlyFirstGift.begin(); itr != OnlyFirstGift.end(); ++itr)
            {
                if (player->GetGUID() == *itr) { player->SendChatMessage("you already got gift!"); _access = false; break; }
            }
            if (_access) 
            { 
                switch (player->getClass())
                {
                case CLASS_WARRIOR:
                    player->AddItem(94577, 1);
                    player->AddItem(86778, 1);
                    player->AddItem(86799, 1);
                    break;
                case CLASS_PALADIN:
                    player->AddItem(94577, 1);
                    player->AddItem(86778, 1);
                    player->AddItem(87544, 1);
                    player->AddItem(86764, 1);
                    player->AddItem(86799, 1);
                    break;
                case CLASS_DEATH_KNIGHT:
                    player->AddItem(86799, 1);   
                    break;
                case CLASS_PRIEST:
                case CLASS_WARLOCK:
                case CLASS_MAGE:
                    player->AddItem(82859, 1);
                    break;
                case CLASS_MONK:
                case CLASS_DRUID:
                        player->AddItem(86777, 1);
                        player->AddItem(86762, 2);
                        player->AddItem(82859,1);
                    break;
                case CLASS_ROGUE:
                    player->AddItem(87547, 2);
                    break;
                case CLASS_HUNTER:
                    player->AddItem(87546, 1);
                    break;
                case CLASS_SHAMAN:
                        player->AddItem(87544, 1);
                        player->AddItem(86764, 1);
                        player->AddItem(86762, 2);
                    break;
                default:
                    break;
                }

                player->AddItem(72582, 1);
                OnlyFirstGift.push_back(player->GetGUID()); 
            }
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:
            player->CLOSE_GOSSIP_MENU();
            break;
        }
        return true;
    }
};

class npc_morpher : public CreatureScript
{
public:
    npc_morpher()
        : CreatureScript("npc_morpher") {}

    bool OnGossipHello(Player* player, Creature* creature)
    {

        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Morph to Sylvanas!", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Morph to Tyrande!", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Morph to Garrosh!", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Morph to Jaina!", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Morph to Varian!", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 5);
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Morph to Thrall!", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 6);
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Morph to Mograin!", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 7);
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Morph to Demon Hunter!", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 8);
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Morph to Valeera!", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 9);
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Nothing there", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 10);
        player->SEND_GOSSIP_MENU(907, creature->GetGUID());

        return true;
    }
    std::list<uint64> OnlyFirstGift;
    bool _access;

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action)
    {
        player->PlayerTalkClass->ClearMenus();

        switch (action)
        {
        case GOSSIP_ACTION_INFO_DEF + 1:
            if (player)
                player->SetDisplayId(28213); // Sylvanas
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:
            if (player)
                player->SetDisplayId(39620); // Tyrande
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:
            if (player)
                player->SetDisplayId(32904); // Garrosh
            break;
        case GOSSIP_ACTION_INFO_DEF + 4:
            if (player)
                player->SetDisplayId(30863); // Jaina
            break;
        case GOSSIP_ACTION_INFO_DEF + 5:
            if (player)
                player->SetDisplayId(28127); // Varian
            break;
        case GOSSIP_ACTION_INFO_DEF + 6:
            if (player)
                player->SetDisplayId(38689); // Thrall
            break;
        case GOSSIP_ACTION_INFO_DEF + 7:
            if (player)
                player->SetDisplayId(30869); // Darion
            break;
        case GOSSIP_ACTION_INFO_DEF + 8:
            if (player)
                player->SetDisplayId(20124); //Demon Hunter
            break;
        case GOSSIP_ACTION_INFO_DEF + 9:
            if (player)
                player->SetDisplayId(26365); //Valeera
            break;
        case GOSSIP_ACTION_INFO_DEF + 10:
            player->CLOSE_GOSSIP_MENU();
            break;
        }
        return true;
    }
};

class test_npc_for : public CreatureScript
{
public:
    test_npc_for() : CreatureScript("test_npc_for") { }

    struct test_npc_forAI : public ScriptedAI
    {
        test_npc_forAI(Creature* creature) : ScriptedAI(creature) {}

        void UpdateAI(const uint32 diff)
        {
            events.Update(diff);

            me->CastSpell(me, 135052, true);
        }

        void DamageTaken(Unit* /*attacker*/, uint32& damage) 
        {
            damage = 0;
        }

    };
};

void AddSC_npc_gift()
{
    new npc_gift();
    new npc_jade_serpent_riding_skill();
    new npc_new_players_gift();
    new npc_morpher();
    new test_npc_for();
}