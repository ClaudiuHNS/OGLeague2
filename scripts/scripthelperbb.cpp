#include "scripthelperbb.h"


void ScriptHelperBB::RegisterGlobals(sol::global_table state)
{
    state["TTYPE_Invalid"] = -1;
    state["TTYPE_Self"] = 0;
    state["TTYPE_Target"] = 1;
    state["TTYPE_Area"] = 2;
    state["TTYPE_Cone"] = 3;
    state["TTYPE_SelfAOE"] = 4;
    state["TTYPE_TargetOrLocation"] = 5;
    state["TTYPE_Location"] = 6;
    state["TTYPE_Direction"] = 7;
    state["TEAM_UNKNOWN"] = 0;
    state["TEAM_ORDER"] = 100;
    state["TEAM_CHAOS"] = 200;
    state["TEAM_NEUTRAL"] = 300;
    state["TEAM_OWNER"] = 401;
    state["TEAM_CASTER"] = 402;
    state["TEAM_TARGET"] = 403;
    state["SPAWN_LOCATION"] = 1;
    state["SpellSlots"] = 0;
    state["InventorySlots"] = 1;
    state["ExtraSlots"] = 2;
    state["SPELLBOOK_CHAMPION"] = 0;
    state["SPELLBOOK_SUMMONER"] = 1;
    state["BUFF_REPLACE_EXISTING"] = 0;
    state["BUFF_RENEW_EXISTING"] = 1;
    state["BUFF_STACKS_AND_RENEWS"] = 2;
    state["BUFF_STACKS_AND_OVERLAPS"] = 3;
    state["ChannelingStopCondition_NotCancelled"] = 0;
    state["ChannelingStopCondition_Success"] = 1;
    state["ChannelingStopCondition_Cancel"] = 2;
    state["ChannelingStopSource_NotCancelled"] = 0;
    state["ChannelingStopSource_TimeCompleted"] = 1;
    state["ChannelingStopSource_Animation"] = 2;
    state["ChannelingStopSource_LostTarget"] = 3;
    state["ChannelingStopSource_StunnedOrSilencedOrTaunted"] = 4;
    state["ChannelingStopSource_ChannelingCondition"] = 5;
    state["ChannelingStopSource_Die"] = 6;
    state["ChannelingStopSource_HeroReincarnate"] = 7;
    state["ChannelingStopSource_Move"] = 8;
    state["ChannelingStopSource_Attack"] = 9;
    state["ChannelingStopSource_Casting"] = 10;
    state["ChannelingStopSource_Unknown"] = 11;
    state["FURTHEST_WITHIN_RANGE"] = 0;
    state["FIRST_COLLISION_HIT"] = 1;
    state["GET_NEAREST_IN_RANGE"] = 2;
    state["GET_NEAREST_IN_RANGE_INCLUDE_UNITS"] = 3;
    state["CANCEL_ORDER"] = 0;
    state["POSTPONE_CURRENT_ORDER"] = 1;
    state["PAR_MANA"] = 0;
    state["PAR_ENERGY"] = 1;
    state["PAR_SOULS"] = 2;
    state["PAR_SHIELD"] = 3;

    state["BBSetCameraPosition"] = &ScriptHelperBB::BBSetCameraPosition;
    state["BBIsPathable"] = &ScriptHelperBB::BBIsPathable;
    state["BBTeleportToKeyLocation"] = &ScriptHelperBB::BBTeleportToKeyLocation;
    state["BBTeleportToPosition"] = &ScriptHelperBB::BBTeleportToPosition;
    state["BBGetNearestPassablePosition"] = &ScriptHelperBB::BBGetNearestPassablePosition;
    state["BBForEachUnitInTargetAreaAddBuff"] = &ScriptHelperBB::BBForEachUnitInTargetAreaAddBuff;
    state["BBForEachUnitInTargetArea"] = &ScriptHelperBB::BBForEachUnitInTargetArea;
    state["BBForEachUnitInTargetAreaRandom"] = &ScriptHelperBB::BBForEachUnitInTargetAreaRandom;
    state["BBForNClosestUnitsInTargetArea"] = &ScriptHelperBB::BBForNClosestUnitsInTargetArea;
    state["BBForEachChampion"] = &ScriptHelperBB::BBForEachChampion;
    state["BBForEachUnitInTargetRectangle"] = &ScriptHelperBB::BBForEachUnitInTargetRectangle;
    state["BBGetRandomPointInAreaUnit"] = &ScriptHelperBB::BBGetRandomPointInAreaUnit;
    state["BBGetRandomPointInAreaPosition"] = &ScriptHelperBB::BBGetRandomPointInAreaPosition;
    state["BBGetUnitPosition"] = &ScriptHelperBB::BBGetUnitPosition;
    state["BBGetSkinID"] = &ScriptHelperBB::BBGetSkinID;
    state["BBGetPointByUnitFacingOffset"] = &ScriptHelperBB::BBGetPointByUnitFacingOffset;
    state["BBGetMissilePosFromID"] = &ScriptHelperBB::BBGetMissilePosFromID;
    state["BBModifyPosition"] = &ScriptHelperBB::BBModifyPosition;
    state["BBIncFlatPARPoolMod"] = &ScriptHelperBB::BBIncFlatPARPoolMod;
    state["BBIncFlatPARRegenMod"] = &ScriptHelperBB::BBIncFlatPARRegenMod;
    state["BBIncPercentPARPoolMod"] = &ScriptHelperBB::BBIncPercentPARPoolMod;
    state["BBIncPercentPARRegenMod"] = &ScriptHelperBB::BBIncPercentPARRegenMod;
    state["BBIncPermanentFlatPARPoolMod"] = &ScriptHelperBB::BBIncPermanentFlatPARPoolMod;
    state["BBIncPermanentFlatPARRegenMod"] = &ScriptHelperBB::BBIncPermanentFlatPARRegenMod;
    state["BBIncPermanentPercentPARPoolMod"] = &ScriptHelperBB::BBIncPermanentPercentPARPoolMod;
    state["BBIncPermanentPercentPARRegenMod"] = &ScriptHelperBB::BBIncPermanentPercentPARRegenMod;
    state["BBGetFlatPARPoolMod"] = &ScriptHelperBB::BBGetFlatPARPoolMod;
    state["BBGetFlatPARRegenMod"] = &ScriptHelperBB::BBGetFlatPARRegenMod;
    state["BBGetPercentPARPoolMod"] = &ScriptHelperBB::BBGetPercentPARPoolMod;
    state["BBGetPercentPARRegenMod"] = &ScriptHelperBB::BBGetPercentPARRegenMod;
    state["BBApplyDamage"] = &ScriptHelperBB::BBApplyDamage;
    state["BBApplyStun"] = &ScriptHelperBB::BBApplyStun;
    state["BBApplyPacified"] = &ScriptHelperBB::BBApplyPacified;
    state["BBApplyNet"] = &ScriptHelperBB::BBApplyNet;
    state["BBApplyDisarm"] = &ScriptHelperBB::BBApplyDisarm;
    state["BBApplySuppression"] = &ScriptHelperBB::BBApplySuppression;
    state["BBApplySilence"] = &ScriptHelperBB::BBApplySilence;
    state["BBApplyRoot"] = &ScriptHelperBB::BBApplyRoot;
    state["BBApplyTaunt"] = &ScriptHelperBB::BBApplyTaunt;
    state["BBApplyCharm"] = &ScriptHelperBB::BBApplyCharm;
    state["BBApplyFear"] = &ScriptHelperBB::BBApplyFear;
    state["BBApplySleep"] = &ScriptHelperBB::BBApplySleep;
    state["BBApplyNearSight"] = &ScriptHelperBB::BBApplyNearSight;
    state["BBApplyNoRender"] = &ScriptHelperBB::BBApplyNoRender;
    state["BBApplyForceRenderParticles"] = &ScriptHelperBB::BBApplyForceRenderParticles;
    state["BBApplyStealth"] = &ScriptHelperBB::BBApplyStealth;
    state["BBApplyRevealSpecificUnit"] = &ScriptHelperBB::BBApplyRevealSpecificUnit;
    state["BBApplySuppressCallForHelp"] = &ScriptHelperBB::BBApplySuppressCallForHelp;
    state["BBApplyCallForHelpSuppresser"] = &ScriptHelperBB::BBApplyCallForHelpSuppresser;
    state["BBApplyIgnoreCallForHelp"] = &ScriptHelperBB::BBApplyIgnoreCallForHelp;
    state["BBIncPAR"] = &ScriptHelperBB::BBIncPAR;
    state["BBIncGold"] = &ScriptHelperBB::BBIncGold;
    state["BBLuaGetGold"] = &ScriptHelperBB::BBLuaGetGold;
    state["BBIncHealth"] = &ScriptHelperBB::BBIncHealth;
    state["BBDrawDefaultHitEffects"] = &ScriptHelperBB::BBDrawDefaultHitEffects;
    state["BBGetCastSpellTargetPos"] = &ScriptHelperBB::BBGetCastSpellTargetPos;
    state["BBAdjustCastInfoCenterAOE"] = &ScriptHelperBB::BBAdjustCastInfoCenterAOE;
    state["BBSpawnPet"] = &ScriptHelperBB::BBSpawnPet;
    state["BBSpawnMinion"] = &ScriptHelperBB::BBSpawnMinion;
    state["BBCloneUnit"] = &ScriptHelperBB::BBCloneUnit;
    state["BBCloneUnitPet"] = &ScriptHelperBB::BBCloneUnitPet;
    state["BBIncExp"] = &ScriptHelperBB::BBIncExp;
    state["BBForEachPetInTarget"] = &ScriptHelperBB::BBForEachPetInTarget;
    state["BBSetDodgePiercing"] = &ScriptHelperBB::BBSetDodgePiercing;
    state["BBSetStateDisableAmbientGold"] = &ScriptHelperBB::BBSetStateDisableAmbientGold;
    state["BBSetStunned"] = &ScriptHelperBB::BBSetStunned;
    state["BBSetPacified"] = &ScriptHelperBB::BBSetPacified;
    state["BBSetNetted"] = &ScriptHelperBB::BBSetNetted;
    state["BBSetDisarmed"] = &ScriptHelperBB::BBSetDisarmed;
    state["BBSetRooted"] = &ScriptHelperBB::BBSetRooted;
    state["BBSetSuppressCallForHelp"] = &ScriptHelperBB::BBSetSuppressCallForHelp;
    state["BBSetCallForHelpSuppresser"] = &ScriptHelperBB::BBSetCallForHelpSuppresser;
    state["BBRedirectGold"] = &ScriptHelperBB::BBRedirectGold;
    state["BBSetTargetingType"] = &ScriptHelperBB::BBSetTargetingType;
    state["BBSetSpell"] = &ScriptHelperBB::BBSetSpell;
    state["BBSetBuffCasterUnit"] = &ScriptHelperBB::BBSetBuffCasterUnit;
    state["BBSetTriggerUnit"] = &ScriptHelperBB::BBSetTriggerUnit;
    state["BBSetUnit"] = &ScriptHelperBB::BBSetUnit;
    state["BBInvalidateUnit"] = &ScriptHelperBB::BBInvalidateUnit;
    state["BBForceDead"] = &ScriptHelperBB::BBForceDead;
    state["BBSetIgnoreCallForHelp"] = &ScriptHelperBB::BBSetIgnoreCallForHelp;
    state["BBSpellBuffAdd"] = &ScriptHelperBB::BBSpellBuffAdd;
    state["BBTimeChannelTickExecute"] = &ScriptHelperBB::BBTimeChannelTickExecute;
    state["BBBreak"] = &ScriptHelperBB::BBBreak;
    state["BBSpellBuffRemoveType"] = &ScriptHelperBB::BBSpellBuffRemoveType;
    state["BBSpellBuffRemove"] = &ScriptHelperBB::BBSpellBuffRemove;
    state["BBSpellBuffRemoveCurrent"] = &ScriptHelperBB::BBSpellBuffRemoveCurrent;
    state["BBSpellBuffClear"] = &ScriptHelperBB::BBSpellBuffClear;
    state["BBGetBuffRemainingDuration"] = &ScriptHelperBB::BBGetBuffRemainingDuration;
    state["BBSpellEffectCreate"] = &ScriptHelperBB::BBSpellEffectCreate;
    state["BBSpellEffectRemove"] = &ScriptHelperBB::BBSpellEffectRemove;
    state["BBStopChanneling"] = &ScriptHelperBB::BBStopChanneling;
    state["BBStopMove"] = &ScriptHelperBB::BBStopMove;
    state["BBMove"] = &ScriptHelperBB::BBMove;
    state["BBMoveAway"] = &ScriptHelperBB::BBMoveAway;
    state["BBDestroyMissile"] = &ScriptHelperBB::BBDestroyMissile;
    state["BBDestroyMissileForTarget"] = &ScriptHelperBB::BBDestroyMissileForTarget;
    state["BBSpellCast"] = &ScriptHelperBB::BBSpellCast;
    state["BBCancelAutoAttack"] = &ScriptHelperBB::BBCancelAutoAttack;
    state["BBOverrideAutoAttack"] = &ScriptHelperBB::BBOverrideAutoAttack;
    state["BBRemoveOverrideAutoAttack"] = &ScriptHelperBB::BBRemoveOverrideAutoAttack;
    state["BBSetAutoAttackTargetingFlags"] = &ScriptHelperBB::BBSetAutoAttackTargetingFlags;
    state["BBSetPetReturnRadius"] = &ScriptHelperBB::BBSetPetReturnRadius;
    state["BBCreateItem"] = &ScriptHelperBB::BBCreateItem;
    state["BBSealSpellSlot"] = &ScriptHelperBB::BBSealSpellSlot;
    state["BBSetBuffToolTipVar"] = &ScriptHelperBB::BBSetBuffToolTipVar;
    state["BBSetSpellToolTipVar"] = &ScriptHelperBB::BBSetSpellToolTipVar;
    state["BBLinkVisibility"] = &ScriptHelperBB::BBLinkVisibility;
    state["BBIsInBrush"] = &ScriptHelperBB::BBIsInBrush;
    state["BBGetHeightDifference"] = &ScriptHelperBB::BBGetHeightDifference;
    state["BBRemoveLinkVisibility"] = &ScriptHelperBB::BBRemoveLinkVisibility;
    state["BBSetNearSight"] = &ScriptHelperBB::BBSetNearSight;
    state["BBGetNearSight"] = &ScriptHelperBB::BBGetNearSight;
    state["BBGetPetOwner"] = &ScriptHelperBB::BBGetPetOwner;
    state["BBStartTrackingCollisions"] = &ScriptHelperBB::BBStartTrackingCollisions;
    state["BBStopMoveBlock"] = &ScriptHelperBB::BBStopMoveBlock;
    state["BBStopCurrentOverrideAnimation"] = &ScriptHelperBB::BBStopCurrentOverrideAnimation;
    state["BBPreloadCharacter"] = &ScriptHelperBB::BBPreloadCharacter;
    state["BBPreloadParticle"] = &ScriptHelperBB::BBPreloadParticle;
    state["BBPreloadSpell"] = &ScriptHelperBB::BBPreloadSpell;
    state["BBDispellPositiveBuffs"] = &ScriptHelperBB::BBDispellPositiveBuffs;
    state["BBDispellNegativeBuffs"] = &ScriptHelperBB::BBDispellNegativeBuffs;
    state["BBRemovePerceptionBubble"] = &ScriptHelperBB::BBRemovePerceptionBubble;
    state["BBAddUnitPerceptionBubble"] = &ScriptHelperBB::BBAddUnitPerceptionBubble;
    state["BBAddPosPerceptionBubble"] = &ScriptHelperBB::BBAddPosPerceptionBubble;
    state["BBPlayAnimation"] = &ScriptHelperBB::BBPlayAnimation;
    state["BBUnlockAnimation"] = &ScriptHelperBB::BBUnlockAnimation;
    state["BBGetNumberOfHeroesOnTeam"] = &ScriptHelperBB::BBGetNumberOfHeroesOnTeam;
    state["BBCanSeeTarget"] = &ScriptHelperBB::BBCanSeeTarget;
    state["BBPushCharacterData"] = &ScriptHelperBB::BBPushCharacterData;
    state["BBSetSlotSpellCooldownTimeVer2"] = &ScriptHelperBB::BBSetSlotSpellCooldownTimeVer2;
    state["BBPopCharacterData"] = &ScriptHelperBB::BBPopCharacterData;
    state["BBPopAllCharacterData"] = &ScriptHelperBB::BBPopAllCharacterData;
    state["BBPushCharacterFade"] = &ScriptHelperBB::BBPushCharacterFade;
    state["BBPopCharacterFade"] = &ScriptHelperBB::BBPopCharacterFade;
    state["BBForEachPointAroundCircle"] = &ScriptHelperBB::BBForEachPointAroundCircle;
    state["BBSetCharacterDebugRadius"] = &ScriptHelperBB::BBSetCharacterDebugRadius;
    state["BBForEachPointOnLine"] = &ScriptHelperBB::BBForEachPointOnLine;
    state["BBFaceDirection"] = &ScriptHelperBB::BBFaceDirection;
    state["BBGetGameTime"] = &ScriptHelperBB::BBGetGameTime;
    state["BBGetChampionBySkinName"] = &ScriptHelperBB::BBGetChampionBySkinName;
    state["BBPauseAnimation"] = &ScriptHelperBB::BBPauseAnimation;
    state["BBEnableWallOfGrassTracking"] = &ScriptHelperBB::BBEnableWallOfGrassTracking;
    state["BBShowHealthBar"] = &ScriptHelperBB::BBShowHealthBar;
    state["BBClearOverrideAnimation"] = &ScriptHelperBB::BBClearOverrideAnimation;
    state["BBOverrideAnimation"] = &ScriptHelperBB::BBOverrideAnimation;
    state["BBIncSpellLevel"] = &ScriptHelperBB::BBIncSpellLevel;
    state["BBSetPARCostInc"] = &ScriptHelperBB::BBSetPARCostInc;
    state["BBGetPARCostInc"] = &ScriptHelperBB::BBGetPARCostInc;
    state["BBSetPARMultiplicativeCostInc"] = &ScriptHelperBB::BBSetPARMultiplicativeCostInc;
    state["BBGetPARMultiplicativeCostInc"] = &ScriptHelperBB::BBGetPARMultiplicativeCostInc;
    state["BBSetInCastTable"] = &ScriptHelperBB::BBSetInCastTable;
    state["BBOverrideCastRange"] = &ScriptHelperBB::BBOverrideCastRange;
    state["BBGetCastRange"] = &ScriptHelperBB::BBGetCastRange;
    state["BBAddDebugCircle"] = &ScriptHelperBB::BBAddDebugCircle;
    state["BBRemoveDebugCircle"] = &ScriptHelperBB::BBRemoveDebugCircle;
    state["BBModifyDebugCircleRadius"] = &ScriptHelperBB::BBModifyDebugCircleRadius;
    state["BBModifyDebugCircleColor"] = &ScriptHelperBB::BBModifyDebugCircleColor;
    state["BBApplyAssistMarker"] = &ScriptHelperBB::BBApplyAssistMarker;
    state["BBSkipNextAutoAttack"] = &ScriptHelperBB::BBSkipNextAutoAttack;
    state["BBIncMaxHealth"] = &ScriptHelperBB::BBIncMaxHealth;
    state["BBGetIsZombie"] = &ScriptHelperBB::BBGetIsZombie;
    state["GetCFParam"] = &ScriptHelperBB::GetCFParam;
}
