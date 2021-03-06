#include "scripthelperspells.h"

CharacterIntermediate* ScriptHelperSpells::sCharInter = nullptr;

void ScriptHelperSpells::RegisterGlobals(sol::global_table state)
{
    state["SPELL_AffectBuildings"] = 4096;
    state["SPELL_AffectEnemies"] = 1024;
    state["SPELL_AffectFriends"] = 2048;
    state["SPELL_Autocast"] = 2;
    state["SPELL_Instacast"] = 4;
    state["SPELL_NotAffectSelf"] = 0x2000;
    state["SPELL_PersistThroughDeath"] = 8;
    state["SPELL_NonDisspellable"] = 16;
    state["SPELL_AffectBuildings"] = 4096;
    state["SPELL_AffectDead"] = 0x80000;
    state["SPELL_AffectEnemies"] = 1024;
    state["SPELL_AffectFriends"] = 2048;
    state["SPELL_AffectHeroes"] = 0x10000;
    state["SPELL_AffectMinions"] = 0x8000;
    state["SPELL_AffectNeutral"] = 0x4000;
    state["SPELL_AffectNotPet"] = 0x100000;
    state["SPELL_AffectTurrets"] = 0x20000;
    state["SPELL_AlwaysSelf"] = 0x40000;
    state["SPELL_AffectBarrackOnly"] = 0x200000;
    state["SPELL_NonTargetableAlly"] = 0x800000;
    state["SPELL_NonTargetableEnemy"] = 0x1000000;
    state["SPELL_NonTargetableAll"] = 0x1800000;
    state["SPELL_TargetableToAll"] = 0x2000000;
    state["BUFF_Aura"] = 1;
    state["BUFF_CombatDehancer"] = 3;
    state["BUFF_CombatEnchancer"] = 2;
    state["BUFF_Damage"] = 11;
    state["BUFF_Fear"] = 20;
    state["BUFF_Frenzy"] = 19;
    state["BUFF_Haste"] = 13;
    state["BUFF_Heal"] = 12;
    state["BUFF_Internal"] = 0;
    state["BUFF_Invisibility"] = 5;
    state["BUFF_Invulnerability"] = 16;
    state["BUFF_Net"] = 21;
    state["BUFF_PhysicalImmunity"] = 15;
    state["BUFF_Polymorph"] = 8;
    state["BUFF_Silence"] = 6;
    state["BUFF_Sleep"] = 17;
    state["BUFF_NearSight"] = 18;
    state["BUFF_Slow"] = 9;
    state["BUFF_Snare"] = 10;
    state["BUFF_SpellImmunity"] = 14;
    state["BUFF_Suppression"] = 23;
    state["BUFF_Stun"] = 4;
    state["BUFF_Taunt"] = 7;
    state["BUFF_Pacified"] = 6;
    state["BUFF_Net"] = 6;
    state["BUFF_Disarm"] = 6;
    state["BUFF_Poison"] = 22;
    state["BUFF_Suppression"] = 23;
    state["BUFF_Blind"] = 24;
    state["UNITSCAN_Enemies"] = 1024;
    state["UNITSCAN_Friends"] = 2048;
    state["UNITSCAN_Buildings"] = 4096;
    state["UNITSCAN_Dead"] = 0x80000;
    state["EFFCREATE_KEEPALIVE"] = 1;
    state["EFFCREATE_UPDATE_ORIENTATION"] = 16;
    state["EFFCREATE_SIMULATE_WHILE_OFF_SCREEN"] = 32;
    state["AI_ORDER_NONE"] = 0;
    state["AI_HOLD"] = 1;
    state["AI_MOVETO"] = 2;
    state["AI_ATTACKTO"] = 3;
    state["AI_TEMP_CASTSPELL"] = 4;
    state["AI_PETHARDATTACK"] = 5;
    state["AI_PETHARDMOVE"] = 6;
    state["AI_PETHARDRETURN"] = 9;
    state["AI_ATTACKMOVE"] = 7;
    state["AI_TAUNT"] = 8;
    state["MAX_SPELLS_PER_CHAR"] = 4;
    state["NUM_INVENTORY_SLOTS"] = 6;
    state["MAX_SLOTS_PER_CHARACTER"] = 10;
    state["NONSPELL_DAMAGESOURCE_RAW"] = 0;
    state["NONSPELL_DAMAGESOURCE_INTERNALRAW"] = 1;
    state["NONSPELL_DAMAGESOURCE_PERIODIC"] = 2;
    state["NONSPELL_DAMAGESOURCE_REACTIVE"] = 4;
    state["NONSPELL_DAMAGESOURCE_ONDEATH"] = 5;
    state["DAMAGESOURCE_RAW"] = 0;
    state["DAMAGESOURCE_INTERNALRAW"] = 1;
    state["DAMAGESOURCE_PERIODIC"] = 2;
    state["DAMAGESOURCE_PROC"] = 3;
    state["DAMAGESOURCE_TO_REACTIVE"] = 4;
    state["DAMAGESOURCE_TO_ONDEATH"] = 5;
    state["DAMAGESOURCE_SPELL"] = 6;
    state["DAMAGESOURCE_ATTACK"] = 7;
    state["DAMAGESOURCE_DEFAULT"] = 8;
    state["DAMAGESOURCE_SPELLAOE"] = 9;
    state["DAMAGESOURCE_SPELLPERSIST"] = 10;
    state["SPAWN_HQ"] = 0;
    state["SPAWN_BARRACKS_LANE_C "] = 3;
    state["SPAWN_BARRACKS_LANE_R"] = 2;
    state["SPAWN_BARRACKS_LANE_L "] = 4;
    state["SPAWN_LOCATION"] = 1;
    state["CHANNELINGSTOPCONDITION_SUCCESS"] = 1;
    state["CHANNELINGSTOPCONDITION_CANCEL"] = 2;
    state["CHANNELINGSTOPSOURCE_NORMAL"] = 1;
    state["CHANNELINGSTOPSOURCE_ANIMATION"] = 2;
    state["CHANNELINGSTOPSOURCE_LOSTTARGET"] = 3;
    state["CHANNELINGSTOPSOURCE_STUNNEDORSILENCEDORTAUNTED"] = 4;
    state["CHANNELINGSTOPSOURCE_CHANNELINGCONDITION"] = 5;
    state["CHANNELINGSTOPSOURCE_DIE"] = 6;
    state["CHANNELINGSTOPSOURCE_HEROREINCARNATE"] = 7;
    state["CHANNELINGSTOPSOURCE_MOVE"] = 8;
    state["CHANNELINGSTOPSOURCE_ATTACK"] = 9;

    state["Say"] = &ScriptHelperSpells::Say;
    state["ApplyStun"] = &ScriptHelperSpells::ApplyStun;
    state["ApplyPacified"] = &ScriptHelperSpells::ApplyPacified;
    state["ApplyNet"] = &ScriptHelperSpells::ApplyNet;
    state["ApplyDisarm"] = &ScriptHelperSpells::ApplyDisarm;
    state["ApplyRoot"] = &ScriptHelperSpells::ApplyRoot;
    state["ApplySilence"] = &ScriptHelperSpells::ApplySilence;
    state["ApplySuppression"] = &ScriptHelperSpells::ApplySuppression;
    state["ApplySuppressCallForHelp"] = &ScriptHelperSpells::ApplySuppressCallForHelp;
    state["ApplyIgnoreCallForHelp"] = &ScriptHelperSpells::ApplyIgnoreCallForHelp;
    state["ApplyCallForHelpSuppresser"] = &ScriptHelperSpells::ApplyCallForHelpSuppresser;
    state["CancelOrder"] = &ScriptHelperSpells::CancelOrder;
    state["ChannelingStart"] = &ScriptHelperSpells::ChannelingStart;
    state["ChannelingStop"] = &ScriptHelperSpells::ChannelingStop;
    state["DrawDefaultHitEffects"] = &ScriptHelperSpells::DrawDefaultHitEffects;
    state["GetIsAttackOverride"] = &ScriptHelperSpells::GetIsAttackOverride;
    state["GetCastSpellLevelPlusOne"] = &ScriptHelperSpells::GetCastSpellLevelPlusOne;
    state["GetCastSpellTargetPos"] = &ScriptHelperSpells::GetCastSpellTargetPos;
    state["GetCastSpellTargetsHitPlusOne"] = &ScriptHelperSpells::GetCastSpellTargetsHitPlusOne;
    state["GetCastSpellLuaInfo"] = &ScriptHelperSpells::GetCastSpellLuaInfo;
    state["GetCasterID"] = &ScriptHelperSpells::GetCasterID;
    state["GetHealth"] = &ScriptHelperSpells::GetHealth;
    state["GetHealthPercent"] = &ScriptHelperSpells::GetHealthPercent;
    state["GetInvulnerable"] = &ScriptHelperSpells::GetInvulnerable;
    state["GetPhysicalImmune"] = &ScriptHelperSpells::GetPhysicalImmune;
    state["GetTargetable"] = &ScriptHelperSpells::GetTargetable;
    state["GetTargetableToTeam"] = &ScriptHelperSpells::GetTargetableToTeam;
    state["GetMagicImmune"] = &ScriptHelperSpells::GetMagicImmune;
    state["GetPAR"] = &ScriptHelperSpells::GetPAR;
    state["GetPARCost"] = &ScriptHelperSpells::GetPARCost;
    state["GetPARPercent"] = &ScriptHelperSpells::GetPARPercent;
    state["GetPARType"] = &ScriptHelperSpells::GetPARType;
    state["HasPARType"] = &ScriptHelperSpells::HasPARType;
    state["GetMaxHealth"] = &ScriptHelperSpells::GetMaxHealth;
    state["GetMaxPAR"] = &ScriptHelperSpells::GetMaxPAR;
    state["GetName"] = &ScriptHelperSpells::GetName;
    state["GetArmor"] = &ScriptHelperSpells::GetArmor;
    state["GetSpellBlock"] = &ScriptHelperSpells::GetSpellBlock;
    state["GetDodge"] = &ScriptHelperSpells::GetDodge;
    state["GetMissChance"] = &ScriptHelperSpells::GetMissChance;
    state["GetAttackSpeedMod"] = &ScriptHelperSpells::GetAttackSpeedMod;
    state["GetMovementSpeed"] = &ScriptHelperSpells::GetMovementSpeed;
    state["GetLevel"] = &ScriptHelperSpells::GetLevel;
    state["GetTotalAttackDamage"] = &ScriptHelperSpells::GetTotalAttackDamage;
    state["GetSlotSpellCooldownTime"] = &ScriptHelperSpells::GetSlotSpellCooldownTime;
    state["GetSlotSpellLevel"] = &ScriptHelperSpells::GetSlotSpellLevel;
    state["GetSlotSpellName"] = &ScriptHelperSpells::GetSlotSpellName;
    state["GetSpellName"] = &ScriptHelperSpells::GetSpellName;
    state["GetSpellSlot"] = &ScriptHelperSpells::GetSpellSlot;
    state["GetNoRender"] = &ScriptHelperSpells::GetNoRender;
    state["GetBrushVisibilityFake"] = &ScriptHelperSpells::GetBrushVisibilityFake;
    state["GetForceRenderParticles"] = &ScriptHelperSpells::GetForceRenderParticles;
    state["GetStealthed"] = &ScriptHelperSpells::GetStealthed;
    state["GetRevealSpecificUnit"] = &ScriptHelperSpells::GetRevealSpecificUnit;
    state["GetTaunted"] = &ScriptHelperSpells::GetTaunted;
    state["GetCharmed"] = &ScriptHelperSpells::GetCharmed;
    state["GetSuppressed"] = &ScriptHelperSpells::GetSuppressed;
    state["GetFeared"] = &ScriptHelperSpells::GetFeared;
    state["GetDisableAmbientGold"] = &ScriptHelperSpells::GetDisableAmbientGold;
    state["SetDisableAmbientGold"] = &ScriptHelperSpells::SetDisableAmbientGold;
    state["GetSleep"] = &ScriptHelperSpells::GetSleep;
    state["GetNearSight"] = &ScriptHelperSpells::GetNearSight;
    state["GetGhosted"] = &ScriptHelperSpells::GetGhosted;
    state["GetGhostProof"] = &ScriptHelperSpells::GetGhostProof;
    state["IncHealth"] = &ScriptHelperSpells::IncHealth;
    state["IncMana"] = &ScriptHelperSpells::IncMana;
    state["IncMoveSpeedFloorMod"] = &ScriptHelperSpells::IncMoveSpeedFloorMod;
    state["IncFlatDodgeMod"] = &ScriptHelperSpells::IncFlatDodgeMod;
    state["IncFlatMissChanceMod"] = &ScriptHelperSpells::IncFlatMissChanceMod;
    state["IncPercentArmorPenetrationMod"] = &ScriptHelperSpells::IncPercentArmorPenetrationMod;
    state["IncPercentMagicPenetrationMod"] = &ScriptHelperSpells::IncPercentMagicPenetrationMod;
    state["IncPercentMultiplicativeAttackSpeedMod"] = &ScriptHelperSpells::IncPercentMultiplicativeAttackSpeedMod;
    state["IncPercentMultiplicativeMovementSpeedMod"] = &ScriptHelperSpells::IncPercentMultiplicativeMovementSpeedMod;
    state["IssueOrder"] = &ScriptHelperSpells::IssueOrder;
    state["RaiseSpellFlag"] = &ScriptHelperSpells::RaiseSpellFlag;
    state["ReincarnateNonDeadHero"] = &ScriptHelperSpells::ReincarnateNonDeadHero;
    state["SetCanCastWhileDisabled"] = &ScriptHelperSpells::SetCanCastWhileDisabled;
    state["SetInvulnerable"] = &ScriptHelperSpells::SetInvulnerable;
    state["SetTargetable"] = &ScriptHelperSpells::SetTargetable;
    state["SetNotTargetableToTeam"] = &ScriptHelperSpells::SetNotTargetableToTeam;
    state["SetPhysicalImmune"] = &ScriptHelperSpells::SetPhysicalImmune;
    state["SetMagicImmune"] = &ScriptHelperSpells::SetMagicImmune;
    state["SetRooted"] = &ScriptHelperSpells::SetRooted;
    state["SetScaleSkinCoef"] = &ScriptHelperSpells::SetScaleSkinCoef;
    state["SetSilenced"] = &ScriptHelperSpells::SetSilenced;
    state["SetSlotSpellCooldownTime"] = &ScriptHelperSpells::SetSlotSpellCooldownTime;
    state["SetStealthed"] = &ScriptHelperSpells::SetStealthed;
    state["SetRevealSpecificUnit"] = &ScriptHelperSpells::SetRevealSpecificUnit;
    state["SetStunned"] = &ScriptHelperSpells::SetStunned;
    state["SetPacified"] = &ScriptHelperSpells::SetPacified;
    state["SetNetted"] = &ScriptHelperSpells::SetNetted;
    state["SetDisarmed"] = &ScriptHelperSpells::SetDisarmed;
    state["SetTaunted"] = &ScriptHelperSpells::SetTaunted;
    state["SetCharmed"] = &ScriptHelperSpells::SetCharmed;
    state["SetFeared"] = &ScriptHelperSpells::SetFeared;
    state["SetSleep"] = &ScriptHelperSpells::SetSleep;
    state["SetNearSight"] = &ScriptHelperSpells::SetNearSight;
    state["SetNoRender"] = &ScriptHelperSpells::SetNoRender;
    state["SetForceRenderParticles"] = &ScriptHelperSpells::SetForceRenderParticles;
    state["SetGhosted"] = &ScriptHelperSpells::SetGhosted;
    state["SetSuppressed"] = &ScriptHelperSpells::SetSuppressed;
    state["SetGhostProof"] = &ScriptHelperSpells::SetGhostProof;
    state["SetSuppressCallForHelp"] = &ScriptHelperSpells::SetSuppressCallForHelp;
    state["SetCallForHelpSuppresser"] = &ScriptHelperSpells::SetCallForHelpSuppresser;
    state["SetBrushVisibilityFake"] = &ScriptHelperSpells::SetBrushVisibilityFake;
    state["SetIgnoreCallForHelp"] = &ScriptHelperSpells::SetIgnoreCallForHelp;
    state["SpellBuffAdd"] =  &ScriptHelperSpells::SpellBuffAdd;
    state["SpellBuffAddNoRenew"] = &ScriptHelperSpells::SpellBuffAddNoRenew;
    state["SpellBuffCount"] = &ScriptHelperSpells::SpellBuffCount;
    state["SpellBuffRemove"] = &ScriptHelperSpells::SpellBuffRemove;
    state["SpellBuffRemoveCurrent"] = &ScriptHelperSpells::SpellBuffRemoveCurrent;
    state["SpellBuffRemoveType"] = &ScriptHelperSpells::SpellBuffRemoveType;
    state["HasBuffOfType"] = &ScriptHelperSpells::HasBuffOfType;
    state["SpellEffectCreate"] = &ScriptHelperSpells::SpellEffectCreate;
    state["TeleportToKeyLocation"] = &ScriptHelperSpells::TeleportToKeyLocation;
    state["TeleportToPosition"] = &ScriptHelperSpells::TeleportToPosition;
    state["GetAIState"] = &ScriptHelperSpells::GetAIState;
    state["GetCanAttack"] = &ScriptHelperSpells::GetCanAttack;
    state["GetCanCast"] = &ScriptHelperSpells::GetCanCast;
    state["IsAutoCastOn"] = &ScriptHelperSpells::IsAutoCastOn;
    state["GetCanMove"] = &ScriptHelperSpells::GetCanMove;
    state["SetCanAttack"] = &ScriptHelperSpells::SetCanAttack;
    state["SetCanCast"] = &ScriptHelperSpells::SetCanCast;
    state["SetCanMove"] = &ScriptHelperSpells::SetCanMove;
    state["IsBaseAI"] = &ScriptHelperSpells::IsBaseAI;
    state["IsHeroAI"] = &ScriptHelperSpells::IsHeroAI;
    state["IsMelee"] = &ScriptHelperSpells::IsMelee;
    state["IsRanged"] = &ScriptHelperSpells::IsRanged;
    state["IsMoving"] = &ScriptHelperSpells::IsMoving;
    state["IncFlatGoldPer10Mod"] = &ScriptHelperSpells::IncFlatGoldPer10Mod;
    state["IncPermanentFlatGoldPer10Mod"] = &ScriptHelperSpells::IncPermanentFlatGoldPer10Mod;
    state["IncBaseAttackDamage"] = &ScriptHelperSpells::IncBaseAttackDamage;
    state["IncPermanentBaseAttackDamage"] = &ScriptHelperSpells::IncPermanentBaseAttackDamage;
    state["IncFlatArmorMod"] = &ScriptHelperSpells::IncFlatArmorMod;
    state["IncPermanentFlatArmorMod"] = &ScriptHelperSpells::IncPermanentFlatArmorMod;
    state["IncFlatArmorPenetrationMod"] = &ScriptHelperSpells::IncFlatArmorPenetrationMod;
    state["IncPermanentFlatArmorPenetrationMod"] = &ScriptHelperSpells::IncPermanentFlatArmorPenetrationMod;
    state["IncFlatMagicPenetrationMod"] = &ScriptHelperSpells::IncFlatMagicPenetrationMod;
    state["IncPermanentFlatMagicPenetrationMod"] = &ScriptHelperSpells::IncPermanentFlatMagicPenetrationMod;
    state["IncFlatSpellBlockMod"] = &ScriptHelperSpells::IncFlatSpellBlockMod;
    state["IncPermanentFlatSpellBlockMod"] = &ScriptHelperSpells::IncPermanentFlatSpellBlockMod;
    state["IncFlatAttackRangeMod"] = &ScriptHelperSpells::IncFlatAttackRangeMod;
    state["IncPermanentFlatAttackRangeMod"] = &ScriptHelperSpells::IncPermanentFlatAttackRangeMod;
    state["IncFlatCastRangeMod"] = &ScriptHelperSpells::IncFlatCastRangeMod;
    state["IncPermanentFlatCastRangeMod"] = &ScriptHelperSpells::IncPermanentFlatCastRangeMod;
    state["IncFlatCooldownMod"] = &ScriptHelperSpells::IncFlatCooldownMod;
    state["IncPermanentFlatCooldownMod"] = &ScriptHelperSpells::IncPermanentFlatCooldownMod;
    state["IncFlatCritChanceMod"] = &ScriptHelperSpells::IncFlatCritChanceMod;
    state["IncPermanentFlatCritChanceMod"] = &ScriptHelperSpells::IncPermanentFlatCritChanceMod;
    state["IncFlatCritDamageMod"] = &ScriptHelperSpells::IncFlatCritDamageMod;
    state["IncPermanentFlatCritDamageMod"] = &ScriptHelperSpells::IncPermanentFlatCritDamageMod;
    state["IncFlatHPPoolMod"] = &ScriptHelperSpells::IncFlatHPPoolMod;
    state["IncPermanentFlatHPPoolMod"] = &ScriptHelperSpells::IncPermanentFlatHPPoolMod;
    state["IncFlatHPRegenMod"] = &ScriptHelperSpells::IncFlatHPRegenMod;
    state["IncPermanentFlatHPRegenMod"] = &ScriptHelperSpells::IncPermanentFlatHPRegenMod;
    state["IncFlatMagicDamageMod"] = &ScriptHelperSpells::IncFlatMagicDamageMod;
    state["IncPermanentFlatMagicDamageMod"] = &ScriptHelperSpells::IncPermanentFlatMagicDamageMod;
    state["IncFlatMagicReduction"] = &ScriptHelperSpells::IncFlatMagicReduction;
    state["IncPermanentFlatMagicReduction"] = &ScriptHelperSpells::IncPermanentFlatMagicReduction;
    state["IncFlatMovementSpeedMod"] = &ScriptHelperSpells::IncFlatMovementSpeedMod;
    state["IncPermanentFlatMovementSpeedMod"] = &ScriptHelperSpells::IncPermanentFlatMovementSpeedMod;
    state["IncFlatPhysicalDamageMod"] = &ScriptHelperSpells::IncFlatPhysicalDamageMod;
    state["IncPermanentFlatPhysicalDamageMod"] = &ScriptHelperSpells::IncPermanentFlatPhysicalDamageMod;
    state["IncFlatPhysicalReduction"] = &ScriptHelperSpells::IncFlatPhysicalReduction;
    state["IncPermanentFlatPhysicalReduction"] = &ScriptHelperSpells::IncPermanentFlatPhysicalReduction;
    state["IncFlatBubbleRadiusMod"] = &ScriptHelperSpells::IncFlatBubbleRadiusMod;
    state["IncPermanentFlatBubbleRadiusMod"] = &ScriptHelperSpells::IncPermanentFlatBubbleRadiusMod;
    state["IncPercentHardnessMod"] = &ScriptHelperSpells::IncPercentHardnessMod;
    state["IncPermanentPercentHardnessMod"] = &ScriptHelperSpells::IncPermanentPercentHardnessMod;
    state["IncPercentArmorMod"] = &ScriptHelperSpells::IncPercentArmorMod;
    state["IncPermanentPercentArmorMod"] = &ScriptHelperSpells::IncPermanentPercentArmorMod;
    state["IncPercentSpellBlockMod"] = &ScriptHelperSpells::IncPercentSpellBlockMod;
    state["IncPermanentPercentSpellBlockMod"] = &ScriptHelperSpells::IncPermanentPercentSpellBlockMod;
    state["IncPercentAttackRangeMod"] = &ScriptHelperSpells::IncPercentAttackRangeMod;
    state["IncPermanentPercentAttackRangeMod"] = &ScriptHelperSpells::IncPermanentPercentAttackRangeMod;
    state["IncPercentAttackSpeedMod"] = &ScriptHelperSpells::IncPercentAttackSpeedMod;
    state["IncPermanentPercentAttackSpeedMod"] = &ScriptHelperSpells::IncPermanentPercentAttackSpeedMod;
    state["IncPercentCastRangeMod"] = &ScriptHelperSpells::IncPercentCastRangeMod;
    state["IncPermanentPercentCastRangeMod"] = &ScriptHelperSpells::IncPermanentPercentCastRangeMod;
    state["IncPercentCooldownMod"] = &ScriptHelperSpells::IncPercentCooldownMod;
    state["IncPermanentPercentCooldownMod"] = &ScriptHelperSpells::IncPermanentPercentCooldownMod;
    state["IncPercentCritDamageMod"] = &ScriptHelperSpells::IncPercentCritDamageMod;
    state["IncPermanentPercentCritDamageMod"] = &ScriptHelperSpells::IncPermanentPercentCritDamageMod;
    state["IncPercentEXPBonus"] = &ScriptHelperSpells::IncPercentEXPBonus;
    state["IncPermanentPercentEXPBonus"] = &ScriptHelperSpells::IncPermanentPercentEXPBonus;
    state["IncPercentHPPoolMod"] = &ScriptHelperSpells::IncPercentHPPoolMod;
    state["IncPermanentPercentHPPoolMod"] = &ScriptHelperSpells::IncPermanentPercentHPPoolMod;
    state["IncPercentHPRegenMod"] = &ScriptHelperSpells::IncPercentHPRegenMod;
    state["IncPermanentPercentHPRegenMod"] = &ScriptHelperSpells::IncPermanentPercentHPRegenMod;
    state["IncPercentHealingAmountMod"] = &ScriptHelperSpells::IncPercentHealingAmountMod;
    state["IncPermanentPercentHealingAmountMod"] = &ScriptHelperSpells::IncPermanentPercentHealingAmountMod;
    state["IncPercentLifeStealMod"] = &ScriptHelperSpells::IncPercentLifeStealMod;
    state["IncPermanentPercentLifeStealMod"] = &ScriptHelperSpells::IncPermanentPercentLifeStealMod;
    state["IncPercentSpellVampMod"] = &ScriptHelperSpells::IncPercentSpellVampMod;
    state["IncPermanentPercentSpellVampMod"] = &ScriptHelperSpells::IncPermanentPercentSpellVampMod;
    state["IncPercentMagicDamageMod"] = &ScriptHelperSpells::IncPercentMagicDamageMod;
    state["IncPermanentPercentMagicDamageMod"] = &ScriptHelperSpells::IncPermanentPercentMagicDamageMod;
    state["IncPercentMagicReduction"] = &ScriptHelperSpells::IncPercentMagicReduction;
    state["IncPermanentPercentMagicReduction"] = &ScriptHelperSpells::IncPermanentPercentMagicReduction;
    state["IncPercentMovementSpeedMod"] = &ScriptHelperSpells::IncPercentMovementSpeedMod;
    state["IncPermanentPercentMovementSpeedMod"] = &ScriptHelperSpells::IncPermanentPercentMovementSpeedMod;
    state["IncPercentPhysicalDamageMod"] = &ScriptHelperSpells::IncPercentPhysicalDamageMod;
    state["IncPermanentPercentPhysicalDamageMod"] = &ScriptHelperSpells::IncPermanentPercentPhysicalDamageMod;
    state["IncPercentPhysicalReduction"] = &ScriptHelperSpells::IncPercentPhysicalReduction;
    state["IncPermanentPercentPhysicalReduction"] = &ScriptHelperSpells::IncPermanentPercentPhysicalReduction;
    state["IncPercentRespawnTimeMod"] = &ScriptHelperSpells::IncPercentRespawnTimeMod;
    state["IncPermanentPercentRespawnTimeMod"] = &ScriptHelperSpells::IncPermanentPercentRespawnTimeMod;
    state["IncPercentGoldLostOnDeathMod"] = &ScriptHelperSpells::IncPercentGoldLostOnDeathMod;
    state["IncPermanentPercentGoldLostOnDeathMod"] = &ScriptHelperSpells::IncPermanentPercentGoldLostOnDeathMod;
    state["IncPercentBubbleRadiusMod"] = &ScriptHelperSpells::IncPercentBubbleRadiusMod;
    state["IncPermanentPercentBubbleRadiusMod"] = &ScriptHelperSpells::IncPermanentPercentBubbleRadiusMod;
    state["IncAcquisitionRangeMod"] = &ScriptHelperSpells::IncAcquisitionRangeMod;
    state["IncPermanentAcquisitionRangeMod"] = &ScriptHelperSpells::IncPermanentAcquisitionRangeMod;
    state["GetFlatGoldPer10Mod"] = &ScriptHelperSpells::GetFlatGoldPer10Mod;
    state["GetBaseAttackDamage"] = &ScriptHelperSpells::GetBaseAttackDamage;
    state["GetFlatArmorMod"] = &ScriptHelperSpells::GetFlatArmorMod;
    state["GetFlatArmorPenetrationMod"] = &ScriptHelperSpells::GetFlatArmorPenetrationMod;
    state["GetFlatMagicPenetrationMod"] = &ScriptHelperSpells::GetFlatMagicPenetrationMod;
    state["GetFlatSpellBlockMod"] = &ScriptHelperSpells::GetFlatSpellBlockMod;
    state["GetFlatAttackRangeMod"] = &ScriptHelperSpells::GetFlatAttackRangeMod;
    state["GetFlatCastRangeMod"] = &ScriptHelperSpells::GetFlatCastRangeMod;
    state["GetFlatCooldownMod"] = &ScriptHelperSpells::GetFlatCooldownMod;
    state["GetFlatCritChanceMod"] = &ScriptHelperSpells::GetFlatCritChanceMod;
    state["GetFlatCritDamageMod"] = &ScriptHelperSpells::GetFlatCritDamageMod;
    state["GetFlatHPPoolMod"] = &ScriptHelperSpells::GetFlatHPPoolMod;
    state["GetFlatHPRegenMod"] = &ScriptHelperSpells::GetFlatHPRegenMod;
    state["GetFlatMagicDamageMod"] = &ScriptHelperSpells::GetFlatMagicDamageMod;
    state["GetFlatMagicReduction"] = &ScriptHelperSpells::GetFlatMagicReduction;
    state["GetFlatMovementSpeedMod"] = &ScriptHelperSpells::GetFlatMovementSpeedMod;
    state["GetFlatPhysicalDamageMod"] = &ScriptHelperSpells::GetFlatPhysicalDamageMod;
    state["GetFlatPhysicalReduction"] = &ScriptHelperSpells::GetFlatPhysicalReduction;
    state["GetFlatBubbleRadiusMod"] = &ScriptHelperSpells::GetFlatBubbleRadiusMod;
    state["GetPercentHardnessMod"] = &ScriptHelperSpells::GetPercentHardnessMod;
    state["GetPercentArmorMod"] = &ScriptHelperSpells::GetPercentArmorMod;
    state["GetPercentSpellBlockMod"] = &ScriptHelperSpells::GetPercentSpellBlockMod;
    state["GetPercentAttackRangeMod"] = &ScriptHelperSpells::GetPercentAttackRangeMod;
    state["GetPercentAttackSpeedMod"] = &ScriptHelperSpells::GetPercentAttackSpeedMod;
    state["GetPercentCastRangeMod"] = &ScriptHelperSpells::GetPercentCastRangeMod;
    state["GetPercentCooldownMod"] = &ScriptHelperSpells::GetPercentCooldownMod;
    state["GetPercentCritDamageMod"] = &ScriptHelperSpells::GetPercentCritDamageMod;
    state["GetPercentEXPBonus"] = &ScriptHelperSpells::GetPercentEXPBonus;
    state["GetPercentHPPoolMod"] = &ScriptHelperSpells::GetPercentHPPoolMod;
    state["GetPercentHPRegenMod"] = &ScriptHelperSpells::GetPercentHPRegenMod;
    state["GetPercentHealingAmountMod"] = &ScriptHelperSpells::GetPercentHealingAmountMod;
    state["GetPercentLifeStealMod"] = &ScriptHelperSpells::GetPercentLifeStealMod;
    state["GetPercentSpellVampMod"] = &ScriptHelperSpells::GetPercentSpellVampMod;
    state["GetPercentMagicDamageMod"] = &ScriptHelperSpells::GetPercentMagicDamageMod;
    state["GetPercentMagicReduction"] = &ScriptHelperSpells::GetPercentMagicReduction;
    state["GetPercentMovementSpeedMod"] = &ScriptHelperSpells::GetPercentMovementSpeedMod;
    state["GetPercentPhysicalDamageMod"] = &ScriptHelperSpells::GetPercentPhysicalDamageMod;
    state["GetPercentPhysicalReduction"] = &ScriptHelperSpells::GetPercentPhysicalReduction;
    state["GetPercentRespawnTimeMod"] = &ScriptHelperSpells::GetPercentRespawnTimeMod;
    state["GetPercentGoldLostOnDeathMod"] = &ScriptHelperSpells::GetPercentGoldLostOnDeathMod;
    state["GetPercentBubbleRadiusMod"] = &ScriptHelperSpells::GetPercentBubbleRadiusMod;
    state["GetAcquisitionRangeMod"] = &ScriptHelperSpells::GetAcquisitionRangeMod;
}
